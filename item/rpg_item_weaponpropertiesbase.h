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

// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_ITEM_WEAPONPROPERTIESBASE_H
#define RPG_ITEM_WEAPONPROPERTIESBASE_H

struct RPG_Item_WeaponPropertiesBase
 : public RPG_Item_PropertiesBase
{
  RPG_Item_WeaponType weaponType;
  RPG_Item_WeaponCategory weaponCategory;
  RPG_Item_WeaponClass weaponClass;
  RPG_Dice_Roll baseDamage;
  RPG_Item_CriticalHitProperties criticalHit;
  unsigned char rangeIncrement;
  std::vector<RPG_Common_PhysicalDamageType> typeOfDamages;
  bool isNonLethal;
  bool isReachWeapon;
  bool isDoubleWeapon;
};

#endif
