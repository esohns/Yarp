%{
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <limits.h>

#include <ace/Log_Msg.h>

#include "rpg_net_protocol_IRCparser.h"
#include "rpg_net_protocol_IRCparser_driver.h"

/* Work around an incompatibility in flex (at least versions
   2.5.31 through 2.5.33): it generates code that does
   not conform to C89.  See Debian bug 333231
   <http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=333231>.  */
#undef yywrap
#define yywrap() 1

/* By default yylex returns int, we use token_type.
   Unfortunately yyterminate by default returns 0, which is
   not of token_type.  */
#define yyterminate() return token::END
%}

%option pointer full nounistd 8bit stack
/* %option c++ outfile="rpg_net_protocol_IRCscanner.cpp" */
%option warn nodefault noyywrap nounput
%option debug perf-report verbose
/* reentrant bison-bridge bison-locations */
%option prefix="IRCScanner" yylineno

COLON          ':'
SPACE          [ ]+
HOST           [a-zA-Z0-9]+
SERVERNAME     {HOST}
LETTER         [a-zA-Z]
NUMBER         [0-9]
SPECIAL        [-[]\\`^{}]
NICK           {LETTER}[{LETTER}{NUMBER}{SPECIAL}]*
EXCLAMATION    '!'
NONWHITE       [(?s:.)]{-}[ \t\0\r\n]
USER           {NONWHITE}+
AT             '@'
CHSTRING       ([(?s:.)]{-}[ \b\0\r\n,])+
MASK           [#$]{CHSTRING}
CHANNEL        [#&]{CHSTRING}
PARAM          ([(?s:.)]{-}[ \0\r\n])+
TRAILING_PARAM ([(?s:.)]{-}[\0\r\n])*
CRLF           \r\n

%s             prefix
%s             user
%s             host
%s             trailing
%s             params

%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%%
%{
  yylloc->step();
  typedef IRCParse::RPG_Net_Protocol_IRCParser::token token;
  typedef IRCParse::RPG_Net_Protocol_IRCParser::token_type token_type;
%}

<INITIAL>{COLON}           { yylloc->step();
                             BEGIN(prefix);
                             return token_type(yytext[0]); }
<prefix>{SERVERNAME}       { yylloc->step();
                             yylval->sval = yytext;
                             return token::SERVERNAME_NICK; }
<prefix>{NICK}             { yylloc->step();
                             yylval->sval = yytext;
                             return token::SERVERNAME_NICK; }
<prefix>{SPACE}            { yylloc->step();
                             BEGIN(INITIAL);
                             return token::SPACE; }
<prefix>{EXCLAMATION}      { yylloc->step();
                             BEGIN(user);
                             return token_type(yytext[0]); }
<user>{USER}               { yylloc->step();
                             BEGIN(prefix);
                             yylval->sval = yytext;
                             return token::USER; }
<prefix>{AT}               { yylloc->step();
                             BEGIN(host);
                             return token_type(yytext[0]); }
<host>{HOST}               { yylloc->step();
                             BEGIN(prefix);
                             yylval->sval = yytext;
                             return token::HOST; }
{LETTER}+                  { yylloc->step();
                             BEGIN(params);
                             yylval->sval = yytext;
                             return token::CMD_STRING; }
{NUMBER}{3}                { yylloc->step();
                             BEGIN(params);
                             yylval->ival = ::atoi(yytext);
                             return token::CMD_NUMERIC }
<params>{SPACE}            { yylloc->step();
                             return token::SPACE; }
<params>{COLON}            { yylloc->step();
                             BEGIN(trailing);
                             return token_type(yytext[0]); }
<trailing>{TRAILING_PARAM} { yylloc->step();
                             yylval->sval = yytext;
                             return token::PARAM; }
<params>{PARAM}            { yylloc->step();
                             yylval->sval = yytext;
                             return token::PARAM; }
{CRLF}                     { yylloc->step();
                             return token::END; }
(?s:.)                     driver.error(*yylloc, ACE_TEXT("invalid character"));
%%

const bool
RPG_Net_Protocol_IRCParserDriver::scan_begin(const char* data_in,
                                             const size_t& length_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::scan_begin"));

  // sanity check(s)
  ACE_ASSERT(myCurrentState == NULL);

  yy_flex_debug = myTraceScanning;

  // create a new buffer state
  myCurrentState = yy_scan_buffer(data_in, length_in + 2);
  if (myCurrentState == NULL)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ::yy_scan_buffer(%@, %d), aborting\n"),
               data_in,
               (length_in + 2)));

    return false;
  } // end IF

//   if (file == "-")
//     yyin = stdin;
//   else if (!(yyin = fopen(file.c_str (), "r")))
//   {
//     error(std::string("cannot open ") + file);
//     exit(1);
//   }
}

void
RPG_Net_Protocol_IRCParserDriver::scan_end()
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::scan_end"));

  // sanity check(s)
  ACE_ASSERT(myCurrentState);

  // clean state
  yy_delete_buffer(myCurrentState);
  myCurrentState = NULL;

//  fclose(yyin);
}
