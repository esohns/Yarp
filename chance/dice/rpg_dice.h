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
#ifndef RPG_DICE_H
#define RPG_DICE_H

#include "rpg_dice_exports.h"
#include "rpg_dice_dietype.h"
#include "rpg_dice_roll.h"
#include "rpg_dice_valuerange.h"
#include "rpg_dice_common.h"

#include <ace/Global_Macros.h>

#include <set>

/**
emulate rolling an n-sided die

	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Dice_Export RPG_Dice
{
 public:
  // init random seed
  static void init();

  static void generateRandomNumbers(const unsigned int&,     // range [1..max]
                                    const unsigned int&,     // number of rolls
                                    RPG_Dice_RollResult_t&); // result(s)
  static void simulateRoll(const RPG_Dice_Roll&,    // specifics (number of dice, type, modifier)
                           const unsigned int&,     // number of rolls
                           RPG_Dice_RollResult_t&); // result(s)
  static void rollToRange(const RPG_Dice_Roll&,  // roll specifics
                          RPG_Dice_ValueRange&); // result
  static void rangeToRoll(const RPG_Dice_ValueRange&, // range
                          RPG_Dice_Roll&);            // roll specifics

 private:
  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Dice());
  ACE_UNIMPLEMENTED_FUNC(~RPG_Dice());
  ACE_UNIMPLEMENTED_FUNC(RPG_Dice(const RPG_Dice&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Dice& operator=(const RPG_Dice&));

  // helper methods
  static const unsigned int distanceRangeToRange(const RPG_Dice_ValueRange&,
                                                 const RPG_Dice_ValueRange&);

  // helper types
  struct rangeToRollElement
  {
    // needed for proper sorting...
    bool operator<(const rangeToRollElement& rhs_in) const
    {
      ACE_ASSERT((range.begin == rhs_in.range.begin) &&
                 (range.end == rhs_in.range.end));

      // compute distance to other
      RPG_Dice_ValueRange possible_range;
      rollToRange(roll, possible_range);
      RPG_Dice_ValueRange possible_range2;
      rollToRange(rhs_in.roll, possible_range2);
      int distance = distanceRangeToRange(range, possible_range);
      int distance2 = distanceRangeToRange(range, possible_range2);
      return (distance < distance2);
    };

    RPG_Dice_ValueRange range;
    RPG_Dice_Roll roll;
  };
  typedef std::set<rangeToRollElement> RPG_Dice_SortedRolls_t;
  typedef RPG_Dice_SortedRolls_t::const_iterator RPG_Dice_SortedRollsIterator_t;
};

#endif
