/***************************************************************************
 *   Copyright (C) 2009 by Erik Sohns   *
 *   erik.sohns@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "stdafx.h"

#include "rpg_net_protocol_IRCparser_driver.h"

#include "rpg_net_protocol_defines.h"
#include "rpg_net_protocol_IRCmessage.h"
#include "rpg_net_protocol_IRCparser.h"
#include "rpg_net_protocol_IRCscanner.h"
#include "rpg_net_protocol_message.h"

#include <rpg_common_macros.h>

#include <ace/Message_Block.h>
#include <ace/Log_Msg.h>

#include <sstream>

RPG_Net_Protocol_IRCParserDriver::RPG_Net_Protocol_IRCParserDriver(const bool& traceScanning_in,
                                                                   const bool& traceParsing_in)
 : myTraceParsing(traceParsing_in),
   myCurrentNumMessages(0),
   myCurrentScannerState(NULL),
   myCurrentBufferState(NULL),
   myCurrentFragment(NULL),
   myFragmentIsResized(false),
   myParser(this,                   // driver
            &myCurrentNumMessages,  // counter
            myCurrentScannerState), // scanner
   myCurrentMessage(NULL),
   myIsInitialized(false)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::RPG_Net_Protocol_IRCParserDriver"));

  if (RPG_Net_Protocol_IRCscanner_lex_init_extra(this, &myCurrentScannerState))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to yylex_init_extra: \"%m\", continuing\n")));
  ACE_ASSERT(myCurrentScannerState);
  myParser.set(myCurrentScannerState);

  // trace ?
  RPG_Net_Protocol_IRCscanner_set_debug((traceScanning_in ? 1 : 0), myCurrentScannerState);
  myParser.set_debug_level(traceParsing_in ? 1 : 0); // binary (see bison manual)
}

RPG_Net_Protocol_IRCParserDriver::~RPG_Net_Protocol_IRCParserDriver ()
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::~RPG_Net_Protocol_IRCParserDriver"));

  // fini lex scanner
  if (RPG_Net_Protocol_IRCscanner_lex_destroy(myCurrentScannerState))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to yylex_destroy: \"%m\", continuing\n")));
}

void
RPG_Net_Protocol_IRCParserDriver::init(RPG_Net_Protocol_IRCMessage& message_in,
                                       const bool& traceScanning_in,
                                       const bool& traceParsing_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::init"));

  // sanity check(s)
  ACE_ASSERT(!myIsInitialized);

  // set parse target
  myCurrentMessage = &message_in;

  // trace ?
  RPG_Net_Protocol_IRCscanner_set_debug((traceScanning_in ? 1 : 0), myCurrentScannerState);
  myParser.set_debug_level(traceParsing_in ? 1 : 0); // binary (see bison manual)

  // OK
  myIsInitialized = true;
}

const bool
RPG_Net_Protocol_IRCParserDriver::parse(ACE_Message_Block* data_in,
                                        const bool& useYYScanBuffer_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::parse"));

  // sanity check(s)
  ACE_ASSERT(myIsInitialized);
  ACE_ASSERT(data_in);

  // start with the first fragment...
  myCurrentFragment = data_in;

  // *NOTE*: we parse ALL available message fragments
  // *TODO*: yyrestart(), yy_create_buffer/yy_switch_to_buffer, YY_INPUT...
  int result = -1;
//   do
//   { // init scan buffer
    if (!scan_begin(useYYScanBuffer_in))
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to RPG_Net_Protocol_IRCParserDriver::scan_begin(), aborting\n")));

      // clean up
      myCurrentFragment = NULL;

//       break;
      return false;
    } // end IF

    // parse our data
    result = myParser.parse();
    if (result)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to parse IRC message fragment, aborting\n")));

    // fini buffer/scanner
    scan_end();

    // debug info
    if (myParser.debug_level())
    {
      try
      {
        myCurrentMessage->dump_state();
      }
      catch (...)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("caught exception in RPG_Common_IDumpState::dump_state(), continuing\n")));
      }
    } // end IF
//   } while (myCurrentFragment);

  // reset state
  myIsInitialized = false;

  return (result == 0);
}

const bool
RPG_Net_Protocol_IRCParserDriver::switchBuffer()
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::switchBuffer"));

  // sanity check(s)
  ACE_ASSERT(myCurrentScannerState);
  if (myCurrentFragment->cont() == NULL)
    return false; // <-- nothing to do

  // switch to the next fragment
  myCurrentFragment = myCurrentFragment->cont();

  // clean state
  ACE_ASSERT(myCurrentBufferState);
  RPG_Net_Protocol_IRCscanner__delete_buffer(myCurrentBufferState, myCurrentScannerState);
  myCurrentBufferState = NULL;

  // init next buffer
  //myCurrentBufferState = IRCScanner_scan_bytes(myCurrentFragment->rd_ptr(),
  //                                             myCurrentFragment->length(),
  //                                             myScannerContext);
//   if (myCurrentBufferState == NULL)
//   {
//     ACE_DEBUG((LM_ERROR,
//                ACE_TEXT("failed to ::IRCScanner_scan_bytes(%@, %d), aborting\n"),
//                myCurrentFragment->rd_ptr(),
//                myCurrentFragment->length()));
//
//     // what else can we do ?
//     return false;
//   } // end IF

//  // *WARNING*: contrary (!) to the documentation, still need to switch_buffers()...
  RPG_Net_Protocol_IRCscanner__switch_to_buffer(myCurrentBufferState, myCurrentScannerState);

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("switched to next buffer...\n")));

  return true;
}

const bool
RPG_Net_Protocol_IRCParserDriver::moreData()
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::moreData"));

  return (myCurrentFragment->cont() != NULL);
}

const bool
RPG_Net_Protocol_IRCParserDriver::getDebugScanner() const
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::getDebugScanner"));

  return (RPG_Net_Protocol_IRCscanner_get_debug(myCurrentScannerState) != 0);
}

void
RPG_Net_Protocol_IRCParserDriver::error(const yy::location& location_in,
                                        const std::string& message_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::error"));

  std::ostringstream converter;
  converter << location_in;
  // *NOTE*: the output format has been "adjusted" to fit in with bison error-reporting
  ACE_DEBUG((LM_ERROR,
             ACE_TEXT("(@%s): %s\n"),
             converter.str().c_str(),
             message_in.c_str()));
//   ACE_DEBUG((LM_ERROR,
//              ACE_TEXT("failed to parse \"%s\" (@%s): \"%s\"\n"),
//              std::string(myCurrentFragment->rd_ptr(), myCurrentFragment->length()).c_str(),
//              converter.str().c_str(),
//              message_in.c_str()));

  // dump message
  ACE_Message_Block* head = myCurrentFragment;
  while (head->prev())
    head = head->prev();
  ACE_ASSERT(head);
  RPG_Net_Protocol_Message* message = NULL;
  message = dynamic_cast<RPG_Net_Protocol_Message*>(head);
  ACE_ASSERT(message);
  try
  {
    message->dump_state();
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Common_IDumpState::dump_state(), continuing\n")));
  }

//   std::clog << location_in << ": " << message_in << std::endl;
}

void
RPG_Net_Protocol_IRCParserDriver::error(const std::string& message_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::error"));

  // *NOTE*: the output format has been "adjusted" to fit in with bison error-reporting
  ACE_DEBUG((LM_ERROR,
             ACE_TEXT("\": \"%s\"...\n"),
             message_in.c_str()));
//   ACE_DEBUG((LM_ERROR,
//              ACE_TEXT("failed to parse \"%s\": \"%s\"...\n"),
//              std::string(myCurrentFragment->rd_ptr(), myCurrentFragment->length()).c_str(),
//              message_in.c_str()));

//   std::clog << message_in << std::endl;
}

const bool
RPG_Net_Protocol_IRCParserDriver::scan_begin(const bool& useYYScanBuffer_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::scan_begin"));

  // sanity check(s)
  ACE_ASSERT(myCurrentBufferState == NULL);
  ACE_ASSERT(myCurrentFragment);

  // create/init a new buffer state
  if (useYYScanBuffer_in)
    myCurrentBufferState = RPG_Net_Protocol_IRCscanner__scan_buffer(myCurrentFragment->rd_ptr(),
                                                                    (myCurrentFragment->length() + RPG_NET_PROTOCOL_FLEX_BUFFER_BOUNDARY_SIZE),
                                                                    myCurrentScannerState);
  else
    myCurrentBufferState = RPG_Net_Protocol_IRCscanner__scan_bytes(myCurrentFragment->rd_ptr(),
                                                                   myCurrentFragment->length(),
                                                                   myCurrentScannerState);
  if (myCurrentBufferState == NULL)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to yy_scan_buffer/bytes(%@, %d), aborting\n"),
               myCurrentFragment->rd_ptr(),
               myCurrentFragment->length()));

    // what else can we do ?
    return false;
  } // end IF

  // *WARNING*: contrary (!) to the documentation, still need to switch_buffers()...
  RPG_Net_Protocol_IRCscanner__switch_to_buffer(myCurrentBufferState, myCurrentScannerState);

  return true;
}

void
RPG_Net_Protocol_IRCParserDriver::scan_end()
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_IRCParserDriver::scan_end"));

  // sanity check(s)
  ACE_ASSERT(myCurrentBufferState);

//   // clean buffer
//   if (myFragmentIsResized)
//   {
//     if (myCurrentFragment->size(myCurrentFragment->size() - RPG_NET_PROTOCOL_FLEX_BUFFER_BOUNDARY_SIZE))
//       ACE_DEBUG((LM_ERROR,
//                  ACE_TEXT("failed to ACE_Message_Block::size(%u), continuing\n"),
//                  (myCurrentFragment->size() - RPG_NET_PROTOCOL_FLEX_BUFFER_BOUNDARY_SIZE)));
//     myFragmentIsResized = false;
//   } // end IF

  // clean state
  RPG_Net_Protocol_IRCscanner__delete_buffer(myCurrentBufferState, myCurrentScannerState);
  myCurrentBufferState = NULL;

//   // switch to the next fragment (if any)
//   myCurrentFragment = myCurrentFragment->cont();
}
