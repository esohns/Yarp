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

#ifndef RPG_NET_ICONNECTION_H
#define RPG_NET_ICONNECTION_H

#include "rpg_net_common.h"

#include <rpg_common_istatistic.h>
#include <rpg_common_idumpstate.h>

template <typename ConfigType>
class RPG_Net_IConnection
 : public RPG_Common_IStatistic<RPG_Net_RuntimeStatistic>, // collect some stats
   public RPG_Common_IDumpState // ...and dump some information
{
 public:
  // *NOTE*: to shut up the compiler (gcc4) complaining about missing virtual dtors, set
  // -Wno-non-virtual-dtor in the project settings...

  // API
  virtual void init(const ConfigType&) = 0;
//   virtual const bool isRegistered() const = 0;
  // *TODO*: this clashes with Event_Handler::close()...
  //virtual void close(void) = 0;
  virtual void abort() = 0;
  virtual const unsigned long getID() const = 0;
};

#endif