%require "2.4.1"
%error-verbose
%define parser_class_name "RPG_Net_Protocol_IRCParser"
/* %define api.pure */
/* %define namespace "" */
/* %name-prefix "IRCParse" */

%code requires {
class RPG_Net_Protocol_IRCParserDriver;
typedef void* yyscan_t;
}

// parsing context
%parse-param { RPG_Net_Protocol_IRCParserDriver& driver }
%parse-param { yyscan_t& context }
%lex-param   { RPG_Net_Protocol_IRCParserDriver& driver }
%lex-param   { yyscan_t& context }

%initial-action
{
  // Initialize the initial location.
  //@$.begin.filename = @$.end.filename = &driver.file;
};

// symbols
%union
{
  int   ival;
  char* sval;
};

%code {
#include "rpg_net_protocol_IRCparser_driver.h"
#include "rpg_net_protocol_IRCmessage.h"
#include <ace/OS_Memory.h>
#include <ace/Log_Msg.h>
}

%token <ival> SPACE       "space"
%token <sval> ORIGIN      "origin"
%token <sval> USER        "user"
%token <sval> HOST        "host"
%token <sval> CMD_STRING  "cmd_string"
%token <ival> CMD_NUMERIC "cmd_numeric"
%token <sval> PARAM       "param"
%token        END 0       "end of message"
/* %type  <sval> message prefix ext_prefix ext_prefix_2 command params */

%printer    { debug_stream() << *$$; } <sval>
/*%destructor { free $$; ACE_DEBUG((LM_DEBUG,
                                  ACE_TEXT("discarding: \"%s\"...\n"),
                                  $$)); } <sval>*/
%printer    { debug_stream() << $$; } <ival>
%destructor { ACE_DEBUG((LM_DEBUG,
                         ACE_TEXT("discarding tagless symbol...\n"))); } <>

%%
%start message;
%nonassoc ':' '!' '@';

message:      ':' "origin" ext_prefix                         { driver.myCurrentMessage->prefix.origin = $2;
                                                                ACE_DEBUG((LM_DEBUG,
                                                                           ACE_TEXT("set origin: \"%s\"...\n"),
                                                                           $2));
                                                              };
              | body                                          /* default */
              | "end of message"                              /* default */
ext_prefix:   '!' "user" ext_prefix_2                         { driver.myCurrentMessage->prefix.user = $2;
                                                                ACE_DEBUG((LM_DEBUG,
                                                                           ACE_TEXT("set user: \"%s\"...\n"),
                                                                           $2));
                                                              };
              | "space" body                                  /* default */
ext_prefix_2: | '@' "host" "space" body                       { driver.myCurrentMessage->prefix.host = $2;
                                                                ACE_DEBUG((LM_DEBUG,
                                                                           ACE_TEXT("set host: \"%s\"...\n"),
                                                                           $2));
                                                              };
              | "space" body                                  /* default */
body:         command params "end of message"                 /* default */
              | command params error "end of message"         /* default */
command:      "cmd_string"                                    { if (driver.myCurrentMessage->command.string)
                                                                  delete driver.myCurrentMessage->command.string;
                                                                ACE_NEW_NORETURN(driver.myCurrentMessage->command.string,
                                                                                 std::string($1));
                                                                ACE_ASSERT(driver.myCurrentMessage->command.string);
                                                                driver.myCurrentMessage->command.discriminator = RPG_Net_Protocol_IRCMessage::Command::STRING;
                                                                ACE_DEBUG((LM_DEBUG,
                                                                           ACE_TEXT("set command: \"%s\"...\n"),
                                                                           $1));
                                                              };
              | "cmd_numeric"                                 { driver.myCurrentMessage->command.numeric = RPG_Net_Protocol_IRC_Codes::RFC1459Numeric($1);
                                                                driver.myCurrentMessage->command.discriminator = RPG_Net_Protocol_IRCMessage::Command::NUMERIC;
                                                                ACE_DEBUG((LM_DEBUG,
                                                                           ACE_TEXT("set command (numeric): %d...\n"),
                                                                           $1));
                                                              };
params:       "space" params                                  /* default */
              | ':' "param"                                   { driver.myCurrentMessage->params.push_front(std::string($2));
                                                                ACE_DEBUG((LM_DEBUG,
                                                                           ACE_TEXT("set final param: \"%s\"...\n"),
                                                                           $2));
                                                              };
              | "param" params                                { driver.myCurrentMessage->params.push_front(std::string($1));
                                                                ACE_DEBUG((LM_DEBUG,
                                                                           ACE_TEXT("set param: \"%s\"...\n"),
                                                                           $1));
                                                              };
%%

void
yy::RPG_Net_Protocol_IRCParser::error(const location_type& location_in,
                                      const std::string& message_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParser::error"));

  driver.error(location_in, message_in);
}