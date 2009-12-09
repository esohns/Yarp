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
#ifndef RPG_DICE_COMMON_H
#define RPG_DICE_COMMON_H

#include "rpg_dice_dietype.h"
#include "rpg_dice_roll.h"

#include <vector>

// some convenient types...
typedef std::vector<RPG_Dice_Roll> RPG_Dice_Rolls_t;
typedef RPG_Dice_Rolls_t::const_iterator RPG_Dice_RollsIterator_t;

typedef std::vector<int> RPG_Dice_RollResult_t;
typedef RPG_Dice_RollResult_t::const_iterator RPG_Dice_RollResultIterator_t;

#endif