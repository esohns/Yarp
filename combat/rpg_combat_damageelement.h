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

#ifndef RPG_COMBAT_DAMAGEELEMENT_H
#define RPG_COMBAT_DAMAGEELEMENT_H

struct RPG_Combat_DamageElement
{
  std::vector<RPG_Combat_DamageTypeUnion> types;
  RPG_Dice_Roll amount;
  RPG_Combat_DamageDuration duration;
  std::vector<RPG_Combat_DamageBonus> others;
  RPG_Common_Attribute attribute;
  std::vector<RPG_Combat_DamageCounterMeasure> counterMeasures;
  RPG_Combat_DamageEffectType effect;
};

#endif
