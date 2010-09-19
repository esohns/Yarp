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

#include "rpg_net_protocol_module_IRCstreamer.h"

#include "rpg_net_protocol_defines.h"
#include "rpg_net_protocol_sessionmessage.h"
#include "rpg_net_protocol_message.h"
#include "rpg_net_protocol_tools.h"

#include <rpg_common_macros.h>

RPG_Net_Protocol_Module_IRCStreamer::RPG_Net_Protocol_Module_IRCStreamer()
//  : inherited()
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_Module_IRCStreamer::RPG_Net_Protocol_Module_IRCStreamer"));

}

RPG_Net_Protocol_Module_IRCStreamer::~RPG_Net_Protocol_Module_IRCStreamer()
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_Module_IRCStreamer::~RPG_Net_Protocol_Module_IRCStreamer"));

}

void
RPG_Net_Protocol_Module_IRCStreamer::handleDataMessage(RPG_Net_Protocol_Message*& message_inout,
                                                       bool& passMessageDownstream_out)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_Protocol_Module_IRCStreamer::handleDataMessage"));

  // don't care (implies yes per default, if we're part of a stream)
  // *NOTE*: as this is an "upstream" module, the "wording" is wrong
  // --> the logic remains the same, though
  passMessageDownstream_out = true;

  // sanity check(s)
  ACE_ASSERT(message_inout->length() == 0);
  ACE_ASSERT(message_inout->space() >= RPG_NET_PROTOCOL_IRC_FRAME_MAXSIZE);

  // serialize our structured data
  // --> create the appropriate bytestream corresponding to its elements

  // according to RFC1459:
  //  <message>  ::= [':' <prefix> <SPACE> ] <command> <params> <crlf>
  //  <prefix>   ::= <servername> | <nick> [ '!' <user> ] [ '@' <host> ]
  //  <command>  ::= <letter> { <letter> } | <number> <number> <number>
  //  <SPACE>    ::= ' ' { ' ' }
  //  <params>   ::= <SPACE> [ ':' <trailing> | <middle> <params> ]
  //  <middle>   ::= <Any *non-empty* sequence of octets not including SPACE
  //                 or NUL or CR or LF, the first of which may not be ':'>
  //  <trailing> ::= <Any, possibly *empty*, sequence of octets not including
  //                   NUL or CR or LF>

  // prefix
  if (!message_inout->getData()->prefix.origin.empty())
  {
    // prefix the prefix
    *message_inout->wr_ptr() = ':';
    message_inout->wr_ptr(1);

    if (message_inout->copy(message_inout->getData()->prefix.origin.c_str(),
                            message_inout->getData()->prefix.origin.size()) == -1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE_Message_Block::copy(\"%s\", %u): \"%m\", aborting\n"),
                 message_inout->getData()->prefix.origin.c_str(),
                 message_inout->getData()->prefix.origin.size()));

      // clean up
      passMessageDownstream_out = false;
      message_inout->release();
      message_inout = NULL;

      return;
    } // end IF

    // append user
    if (!message_inout->getData()->prefix.user.empty())
    {
      // sanity check
      if (message_inout->space() < 1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("[%u]: out of buffer space (\"%s\", %u), aborting\n"),
                   message_inout->getID(),
                   std::string(message_inout->rd_ptr(), message_inout->length()).c_str(),
                   message_inout->length()));

        // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF
      // user prefix
      *message_inout->wr_ptr() = '!';
      message_inout->wr_ptr(1);

      if (message_inout->copy(message_inout->getData()->prefix.user.c_str(),
                              message_inout->getData()->prefix.user.size()) == -1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to ACE_Message_Block::copy(\"%s\", %u): \"%m\", aborting\n"),
                   message_inout->getData()->prefix.user.c_str(),
                   message_inout->getData()->prefix.user.size()));

      // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF
    } // end IF

    // append host
    if (!message_inout->getData()->prefix.host.empty())
    {
      // sanity check
      if (message_inout->space() < 1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("[%u]: out of buffer space (\"%s\", %u), aborting\n"),
                   message_inout->getID(),
                   std::string(message_inout->rd_ptr(), message_inout->length()).c_str(),
                   message_inout->length()));

        // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF
      // host prefix
      *message_inout->wr_ptr() = '@';
      message_inout->wr_ptr(1);

      if (message_inout->copy(message_inout->getData()->prefix.host.c_str(),
                              message_inout->getData()->prefix.host.size()) == -1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to ACE_Message_Block::copy(\"%s\", %u): \"%m\", aborting\n"),
                   message_inout->getData()->prefix.host.c_str(),
                   message_inout->getData()->prefix.host.size()));

        // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF
    } // end IF

    // sanity check
    if (message_inout->space() < 1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("[%u]: out of buffer space (\"%s\", %u), aborting\n"),
                 message_inout->getID(),
                 std::string(message_inout->rd_ptr(), message_inout->length()).c_str(),
                 message_inout->length()));

        // clean up
      passMessageDownstream_out = false;
      message_inout->release();
      message_inout = NULL;

      return;
    } // end IF
    // add a <SPACE>
    *message_inout->wr_ptr() = ' ';
    message_inout->wr_ptr(1);
  } // end IF

  // command
  // *NOTE*: select correct parameter separator (either ' ' (default) or ',' (list))
  char param_separator = ' ';
  switch (message_inout->getData()->command.discriminator)
  {
    case RPG_Net_Protocol_IRCMessage::Command::NUMERIC:
    {
      // sanity check
      if (message_inout->space() < 4)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("[%u]: out of buffer space (\"%s\", %u), aborting\n"),
                   message_inout->getID(),
                   std::string(message_inout->rd_ptr(), message_inout->length()).c_str(),
                   message_inout->length()));

        // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF
      // convert number into the equivalent 3-letter string
      if (::snprintf(message_inout->wr_ptr(),      // target
                     4,                            // max length
                     ACE_TEXT_ALWAYS_CHAR("%.3u"), // format string
                     message_inout->getData()->command.numeric) != 3)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to ::snprintf: \"%m\", aborting\n")));

        // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF

      //... and adjust the write pointer accordingly
      message_inout->wr_ptr(3);

      break;
    }
    case RPG_Net_Protocol_IRCMessage::Command::STRING:
    {
      if (message_inout->copy(message_inout->getData()->command.string->c_str(),
                              message_inout->getData()->command.string->size()) == -1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to ACE_Message_Block::copy(\"%s\", %u): \"%m\", aborting\n"),
                   message_inout->getData()->command.string->c_str(),
                   message_inout->getData()->command.string->size()));

        // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF

      // find correct parameter separator
      switch (RPG_Net_Protocol_Tools::IRCCommandString2Type(*message_inout->getData()->command.string))
      {
        case RPG_Net_Protocol_IRCMessage::NAMES:
        case RPG_Net_Protocol_IRCMessage::LIST:
          param_separator = ','; break;
        default:
          break;
      } // end SWITCH

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("[%u]: invalid command type (was: %u), aborting\n"),
                 message_inout->getID(),
                 message_inout->getData()->command.discriminator));

      // clean up
      passMessageDownstream_out = false;
      message_inout->release();
      message_inout = NULL;

      return;
    }
  } // end SWITCH

  // parameter(s)
  if (!message_inout->getData()->params.empty())
  {
    unsigned long  i = message_inout->getData()->params.size();
    for (RPG_Net_Protocol_ParametersIterator_t iterator = message_inout->getData()->params.begin();
         iterator != message_inout->getData()->params.end();
         iterator++, i--)
    {
      // sanity check
      if (message_inout->space() < 1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("[%u]: out of buffer space (\"%s\", %u), aborting\n"),
                   message_inout->getID(),
                   std::string(message_inout->rd_ptr(), message_inout->length()).c_str(),
                   message_inout->length()));

        // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF
      // add a <SPACE>
      if (i == message_inout->getData()->params.size())
        *message_inout->wr_ptr() = ' ';
      else
        *message_inout->wr_ptr() = param_separator;
      message_inout->wr_ptr(1);

      // special handling for last parameter
      if ((i == 1) &&
          (param_separator == ' ')) // doesn't make sense for lists...
      {
        // if necessary, prefix the trailing parameter
        if ((*iterator).find(' ') != std::string::npos)
        {
          // sanity check
          if (message_inout->space() < 1)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("[%u]: out of buffer space (\"%s\", %u), aborting\n"),
                       message_inout->getID(),
                       std::string(message_inout->rd_ptr(), message_inout->length()).c_str(),
                       message_inout->length()));

            // clean up
            passMessageDownstream_out = false;
            message_inout->release();
            message_inout = NULL;

            return;
          } // end IF
          *message_inout->wr_ptr() = ':';
          message_inout->wr_ptr(1);
        } // end IF
      } // end IF

      if (message_inout->copy((*iterator).c_str(),
                              (*iterator).size()) == -1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to ACE_Message_Block::copy(\"%s\", %u): \"%m\", aborting\n"),
                   (*iterator).c_str(),
                   (*iterator).size()));

        // clean up
        passMessageDownstream_out = false;
        message_inout->release();
        message_inout = NULL;

        return;
      } // end IF
    } // end FOR
  } // end IF

  // sanity check
  if (message_inout->space() < RPG_NET_PROTOCOL_IRC_FRAME_BOUNDARY_SIZE)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("[%u]: out of buffer space (\"%s\", %u), aborting\n"),
               message_inout->getID(),
               std::string(message_inout->rd_ptr(), message_inout->length()).c_str(),
               message_inout->length()));

    // clean up
    passMessageDownstream_out = false;
    message_inout->release();
    message_inout = NULL;

    return;
  } // end IF
  // append a <CRLF>
  *message_inout->wr_ptr() = '\r';
  *(message_inout->wr_ptr() + 1) = '\n';
  message_inout->wr_ptr(RPG_NET_PROTOCOL_IRC_FRAME_BOUNDARY_SIZE);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("[%u]: streamed [%u byte(s)]...\n"),
             message_inout->getID(),
             message_inout->length()));
}
