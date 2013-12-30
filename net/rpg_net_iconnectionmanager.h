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

#ifndef RPG_NET_ICONNECTIONMANAGER_H
#define RPG_NET_ICONNECTIONMANAGER_H

#include "rpg_net_iconnection.h"

#include "rpg_common_icontrol.h"

template <typename ConfigType,
          typename StatisticsContainerType>
class RPG_Net_IConnectionManager
 : public RPG_Common_IControl
{
 public:
  virtual ~RPG_Net_IConnectionManager() {};

  // API
  virtual void getConfig(ConfigType&) = 0; // return value: configuration
  virtual bool registerConnection(RPG_Net_IConnection<StatisticsContainerType>*) = 0; // connection
  virtual void deregisterConnection(const RPG_Net_IConnection<StatisticsContainerType>*) = 0; // connection
};

#endif
