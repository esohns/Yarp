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

#ifndef RPG_NET_PROTOCOL_COMMON_H
#define RPG_NET_PROTOCOL_COMMON_H

#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>

#include "ace/Date_Time.h"

struct RPG_Net_Protocol_IRCLoginOptions
{
  std::string password;
  std::string nick;
  struct User
  {
    std::string username;
    struct Hostname
    {
      union
      {
        // *NOTE*: "traditional" connects (see RFC1459 Section 4.1.3)
        std::string* string;
        // *NOTE*: "modern" connects (see RFC2812 Section 3.1.3)
        unsigned char mode;
      };
      enum discriminator_t
      {
        STRING = 0,
        BITMASK,
        INVALID
      };
      discriminator_t discriminator;
    } hostname;
    std::string servername;
    std::string realname;
  } user;
  std::string channel;
};

// see (RFC1459 section 4.2.3.1)
//            o - give/take channel operator privileges
//            p - private channel flag
//            s - secret channel flag
//            i - invite-only channel flag
//            t - topic settable by channel operator only flag
//            n - no messages to channel from clients on the outside
//            m - moderated channel
//            l - set the user limit to channel
//            b - set a ban mask to keep users out
//            v - give/take the ability to speak on a moderated channel
//            k - set a channel key (password)
// see (RFC2812 section 4.2 and following)
//            a - anonymous channel ('&!'-channels only)
//            i - invite-only channel flag
//            m - moderated channel
//            n - no messages to channel from clients on the outside
//            q - quiet channel (server use only)
//            p - private channel flag
//            s - secret channel flag
//            r - server reop flag ('!'-channels only)
//            t - topic settable by channel operator only flag
//            l - set the user limit to channel
//            k - set a channel key (password)
enum RPG_Net_Protocol_ChannelMode
{
  CHANNELMODE_PASSWORD = 0,
  CHANNELMODE_VOICE,
  CHANNELMODE_BAN,
  CHANNELMODE_USERLIMIT,
  CHANNELMODE_MODERATED,
  CHANNELMODE_BLOCKFOREIGNMSGS,
  CHANNELMODE_RESTRICTEDTOPIC,
  CHANNELMODE_INVITEONLY,
  CHANNELMODE_SECRET,
  CHANNELMODE_PRIVATE,
  CHANNELMODE_OPERATOR,
  //
  CHANNELMODE_MAX,
  CHANNELMODE_INVALID
};
typedef std::bitset<11> RPG_Net_Protocol_ChannelModes_t;

// see (RFC1459 section 4.2.3.2)
//            i - marks a users as invisible
//            s - marks a user for receipt of server notices
//            w - user receives wallops
//            o - operator flag
// see (RFC2812 section 3.1.5)
//            a - user is flagged as away (server-to-server only)
//            i - marks a users as invisible
//            w - user receives wallops
//            r - restricted user connection
//            o - operator flag
//            O - local operator flag
//            s - marks a user for receipt of server notices
enum RPG_Net_Protocol_UserMode
{
  USERMODE_LOCALOPERATOR = 0,
  USERMODE_OPERATOR,
  USERMODE_RESTRICTEDCONN,
  USERMODE_RECVWALLOPS,
  USERMODE_RECVNOTICES,
  USERMODE_INVISIBLE,
  USERMODE_AWAY,
  //
  USERMODE_MAX,
  USERMODE_INVALID
};
typedef std::bitset<7> RPG_Net_Protocol_UserModes_t;

// phonebook
typedef std::set<std::string> RPG_Net_Protocol_Networks_t;
typedef RPG_Net_Protocol_Networks_t::const_iterator RPG_Net_Protocol_NetworksIterator_t;
typedef std::pair<unsigned short, unsigned short> RPG_Net_Protocol_PortRange_t;
typedef std::vector<RPG_Net_Protocol_PortRange_t> RPG_Net_Protocol_PortRanges_t;
typedef RPG_Net_Protocol_PortRanges_t::const_iterator RPG_Net_Protocol_PortRangesIterator_t;
struct RPG_Net_Protocol_ConnectionEntry
{
  std::string                   hostName;
  RPG_Net_Protocol_PortRanges_t listeningPorts;
  std::string                   network;
};
typedef std::multimap<std::string,
                      RPG_Net_Protocol_ConnectionEntry> RPG_Net_Protocol_Servers_t;
typedef RPG_Net_Protocol_Servers_t::const_iterator RPG_Net_Protocol_ServersIterator_t;
struct RPG_Net_Protocol_PhoneBook
{
  ACE_Date_Time               timestamp;
  // *NOTE*: this member is redundant (but still useful ?)...
  RPG_Net_Protocol_Networks_t networks;
  RPG_Net_Protocol_Servers_t  servers;
};

#endif
