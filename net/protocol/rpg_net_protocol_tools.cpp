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

#include "rpg_net_protocol_tools.h"

#include "rpg_net_protocol_common.h"

#include <sstream>

const std::string
RPG_Net_Protocol_Tools::IRCMessage2String(const RPG_Net_Protocol_IRCMessage& message_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Tools::IRCMessage2String"));

  std::ostringstream converter;
  // see RFC1459
  if (!message_in.prefix.origin.empty())
  {
    converter << ACE_TEXT("PREFIX [origin: \"") << message_in.prefix.origin << ACE_TEXT("\"]");
    if (!message_in.prefix.user.empty())
      converter << ACE_TEXT(", [user: \"") << message_in.prefix.user << ACE_TEXT("\"]");
    if (!message_in.prefix.host.empty())
      converter << ACE_TEXT(", [host: \"") << message_in.prefix.host << ACE_TEXT("\"]");
    converter << ACE_TEXT(" \\PREFIX") << std::endl;
  } // end IF
  converter << ACE_TEXT("COMMAND ");
  switch (message_in.command.discriminator)
  {
    case RPG_Net_Protocol_IRCMessage::Command::STRING:
    {
      converter << ACE_TEXT("[\"") << message_in.command.string << ACE_TEXT("\"]");

      break;
    }
    case RPG_Net_Protocol_IRCMessage::Command::NUMERIC:
    {
      converter << ACE_TEXT("[") << message_in.command.numeric << ACE_TEXT("]");

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid command discriminator (was: %d), aborting\n"),
                 message_in.command.discriminator));

      return converter.str();
    }
  } // end SWITCH
  converter << ACE_TEXT(" \\COMMAND") << std::endl;
  if (!message_in.params.empty())
  {
    converter << ACE_TEXT("PARAMS") << std::endl;
    int i = 1;
    for (std::list<std::string>::const_iterator iterator = message_in.params.begin();
          iterator != message_in.params.end();
          iterator++, i++)
    {
      converter << ACE_TEXT("#") << i << ACE_TEXT(" : \"") << *iterator << ACE_TEXT("\"") << std::endl;
    } // end FOR
    converter << ACE_TEXT("\\PARAMS") << std::endl;
  } // end IF

  return converter.str();
}

const RPG_Net_Protocol_CommandType_t
RPG_Net_Protocol_Tools::IRCCommandString2Type(const std::string& commandString_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Tools::IRCCommandString2Type"));

  if ((commandString_in) == ACE_TEXT("NOTICE"))
    return RPG_Net_Protocol_IRCMessage::NOTICE;
  else if (commandString_in == ACE_TEXT("PING"))
    return RPG_Net_Protocol_IRCMessage::PING;
  else if (commandString_in == ACE_TEXT("PONG"))
    return RPG_Net_Protocol_IRCMessage::PONG;
  else
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid command (was: \"%s\"), aborting\n"),
               commandString_in.c_str()));

    return RPG_Net_Protocol_IRCMessage::RPG_NET_PROTOCOL_COMMANDTYPE_INVALID;
  } // end ELSE
}

const std::string
RPG_Net_Protocol_Tools::IRCCommandType2String(const RPG_Net_Protocol_CommandType_t& command_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Tools::IRCCommandType2String"));

  std::string result;

  switch (command_in)
  {
    case RPG_Net_Protocol_IRCMessage::NOTICE:
    {
      result = ACE_TEXT("NOTICE");

      break;
    }
    case RPG_Net_Protocol_IRCMessage::PING:
    {
      result = ACE_TEXT("PING");

      break;
    }
    case RPG_Net_Protocol_IRCMessage::PONG:
    {
      result = ACE_TEXT("PONG");

      break;
    }
    default:
    {
      // debug info
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid command type (was: %d), aborting\n"),
                 command_in));

      break;
    }
  } // end SWITCH

  return result;
}