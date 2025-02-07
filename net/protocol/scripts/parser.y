%require          "2.4.1"
%debug
%language         "c++"
%locations
/*%name-prefix      "RPG_Net_Protocol_Scanner_"*/
%define api.prefix {RPG_Net_Protocol_Scanner_}
%no-lines
%skeleton         "lalr1.cc"
/* %skeleton         "glr.c" */
%token-table
%code top {
#include "stdafx.h"
}
%defines          "rpg_net_protocol_parser.h"
%output           "rpg_net_protocol_parser.cpp"
/* %define           api.pure */
/* %define           api.push_pull */
/* %define           parse.lac full */
/* %define namespace "yy" */
%define api.namespace {yy}
/*%error-verbose*/
%define parse.error verbose
/*%define parser_class_name "RPG_Net_Protocol_Parser"*/
%define api.parser.class {RPG_Net_Protocol_Parser}

%code requires {
class RPG_Net_Protocol_IParser;
class RPG_Net_Protocol_Scanner;

typedef void* yyscan_t;
}

// calling conventions / parameter passing
%parse-param { RPG_Net_Protocol_IParser* driver }
%parse-param { yyscan_t yyscanner }
%lex-param { RPG_Net_Protocol_IParser* driver }
%lex-param { yyscan_t yyscanner }

%initial-action
{
  // Initialize the initial location
  //@$.begin.filename = @$.end.filename = &driver->file;

  // initialize the token value container
  // $$.ival = 0;
  $$.sval = NULL;
};

// symbols
%union
{
  int          ival;
  std::string* sval;
};

%code {
#include <string>

#include "ace/Basic_Types.h"
#include "ace/Log_Msg.h"

#include "rpg_common_macros.h"

#include "rpg_net_protocol_iparser.h"
#include "rpg_net_protocol_scanner.h"
}

%token <ival> LENGTH              "length"
%token <ival> TYPE                "type"
%token <sval> XML                 "xml"
%token <ival> COMMAND             "command"
%token <ival> POSITION_X          "position_x"
%token <ival> POSITION_Y          "position_y"
%token <ival> PATH_NEXT_XY        "path_next_xy"
%token <ival> PATH_NEXT_DIRECTION "path_next_direction"
%token <ival> ENTITY_ID           "entity_id"
%token <ival> PREVIOUS_X          "previous_x"
%token <ival> PREVIOUS_Y          "previous_y"
%token <ival> WINDOW              "window"
%token <ival> CURSOR              "cursor"
%token <ival> SOUND               "sound"
%token <sval> MESSAGE             "message"
%token <ival> SOURCE_X            "source_x"
%token <ival> SOURCE_Y            "source_y"
%token <ival> POSITIONS_NEXT_XY   "positions_next_xy"
%token <ival> RADIUS              "radius"
%token <ival> END_OF_COMMAND      "end_of_command"
%token <ival> END_OF_FRAME        "end_of_frame"

%type  <ival> frame
%type         commands command path path_elem positions positions_elem xml message

%printer    { debug_stream() << *$$; } <sval>
%destructor { delete $$; $$ = NULL; } <sval>
%printer    { debug_stream() << $$; } <ival>
%destructor { $$ = 0; } <ival>
/*%destructor { ACE_DEBUG((LM_DEBUG,
                         ACE_TEXT("discarding tagless symbol...\n"))); } <>*/

%%
%start frame;

frame:      "length"                                 { driver->length (static_cast<ACE_UINT32> ($1));
                                                     }
            commands "end_of_frame"                  { $$ = driver->length ();
                                                       ACE_UNUSED_ARG ($4);
                                                       YYACCEPT; };
path:       path path_elem                           /* default */
            |                                 %empty /* empty */
path_elem:  "path_next_xy" "path_next_xy" "path_next_direction" {
                                                       driver->current ().path.push_back (std::make_pair (std::make_pair (static_cast<unsigned int> ($1), static_cast<unsigned int> ($2)), static_cast<enum RPG_Map_Direction> ($3)));
                                                     };
positions:  positions positions_elem                 /* default */
            |                                 %empty /* empty */
positions_elem: "positions_next_xy" "positions_next_xy" {
                                                       driver->current ().positions.insert (std::make_pair (static_cast<unsigned int> ($1), static_cast<unsigned int> ($2)));
                                                     };
xml:        "xml"                                    { driver->current ().xml = *$1; }
            |                                 %empty /* empty */
message:    "message"                                { driver->current ().message = *$1; }
            |                                 %empty /* empty */
command:    "type"                                   { driver->current ().type = static_cast<enum RPG_Net_Protocol_MessageType> ($1);
                                                     }
            xml "command"                            { driver->current ().command = $4;
                                                     }
            "position_x" "position_y"                { driver->current ().position.first = static_cast<unsigned int> ($6);
                                                       driver->current ().position.second = static_cast<unsigned int> ($7);
                                                     }
            path "entity_id"                         { driver->current ().entity_id = static_cast<RPG_Engine_EntityID_t> ($10);
                                                     }
            "previous_x" "previous_y"                { driver->current ().previous.first = static_cast<unsigned int> ($12);
                                                       driver->current ().previous.second = static_cast<unsigned int> ($13);
                                                     }
            "window"                                 { driver->current ().window = static_cast<enum RPG_Graphics_WindowType> ($15);
                                                     }
            "cursor"                                 { driver->current ().cursor = static_cast<enum RPG_Graphics_Cursor> ($17);
                                                     }
            "sound"                                  { driver->current ().sound = static_cast<enum RPG_Sound_Event> ($19);
                                                     }
            message "source_x" "source_y"            { driver->current ().source.first = static_cast<unsigned int> ($22);
                                                       driver->current ().source.second = static_cast<unsigned int> ($23);
                                                     }
            positions "radius"                       { driver->current ().radius = $26;
                                                     }
            "end_of_command"                         { ACE_UNUSED_ARG ($28);
                                                       struct RPG_Net_Protocol_Command* current_p = &driver->current ();
                                                       driver->record (current_p);
                                                       if (driver->scannedBytes () == driver->length ())
                                                         YYACCEPT; // *NOTE*: "end_of_frame" is currently never reached
                                                     };
commands:   commands command                         /* default */
            |                                 %empty /* empty */
%%

void
yy::RPG_Net_Protocol_Parser::error (const location_type& location_in,
                                    const std::string& message_in)
{
  RPG_TRACE (ACE_TEXT ("RPG_Net_Protocol_Parser::error"));

  driver->error (location_in, message_in);
}
