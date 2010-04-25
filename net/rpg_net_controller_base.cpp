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

#include "rpg_net_controller_base.h"

#include <ace/Log_Msg.h>

RPG_Net_Controller_Base::RPG_Net_Controller_Base()
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Controller_Base::RPG_Net_Controller_Base"));

}

RPG_Net_Controller_Base::~RPG_Net_Controller_Base()
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Controller_Base::~RPG_Net_Controller_Base"));

}

void
RPG_Net_Controller_Base::start()
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Controller_Base::start"));

  ACE_DEBUG((LM_NOTICE,
             ACE_TEXT("%D: starting...\n")));
}

void
RPG_Net_Controller_Base::stop()
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Controller_Base::stop"));

  ACE_DEBUG((LM_NOTICE,
             ACE_TEXT("%D: stopping...\n")));
}

const bool
RPG_Net_Controller_Base::isRunning()
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Controller_Base::isRunning"));

  ACE_DEBUG((LM_NOTICE,
             ACE_TEXT("%D: isRunning ?...\n")));

  return true;
}