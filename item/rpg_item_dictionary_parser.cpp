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
#include "rpg_item_dictionary_parser.h"

#include "rpg_chance_dice_common_tools.h"
#include "rpg_item_common_tools.h"

#include <ace/Log_Msg.h>

RPG_Item_Dictionary_Parser::RPG_Item_Dictionary_Parser(RPG_ITEM_WEAPONDICTIONARY_T* weaponDictionary_in,
                                                       RPG_ITEM_ARMORDICTIONARY_T* armorDictionary_in)
 : myWeaponDictionary(weaponDictionary_in),
   myArmorDictionary(armorDictionary_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_Dictionary_Parser::RPG_Item_Dictionary_Parser"));

}

RPG_Item_Dictionary_Parser::~RPG_Item_Dictionary_Parser()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_Dictionary_Parser::~RPG_Item_Dictionary_Parser"));

}

// void RPG_Item_Dictionary_Parser::pre()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_Dictionary_Parser::pre"));
// 
// }

// void RPG_Item_Dictionary_Parser::RPG_Item_WeaponDictionary()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_Dictionary_Parser::RPG_Item_WeaponDictionary"));
// 
//   // TODO
//   //
// }
// 
// void RPG_Item_Dictionary_Parser::RPG_Item_ArmorDictionary()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_Dictionary_Parser::RPG_Item_ArmorDictionary"));
// 
//   // TODO
//   //
// }

// void RPG_Item_Dictionary_Parser::post_RPG_Item_Dictionary_Type()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_Dictionary_Parser::post_RPG_Item_Dictionary_Type"));
// 
//   // TODO
//   //
//   // return ... ;
// }

RPG_Item_WeaponDictionary_Type::RPG_Item_WeaponDictionary_Type(RPG_ITEM_WEAPONDICTIONARY_T* weaponDictionary_in)
 : myWeaponDictionary(weaponDictionary_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponDictionary_Type::RPG_Item_WeaponDictionary_Type"));

}

// void RPG_Item_WeaponDictionary_Type::pre()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_WeaponDictionary_Type::pre"));
// 
// }

void RPG_Item_WeaponDictionary_Type::weapon(const RPG_Item_WeaponProperties_XML& weapon_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponDictionary_Type::weapon"));

  RPG_Item_WeaponProperties prop;
  prop.weaponCategory = weapon_in.weaponCategory;
  prop.weaponClass = weapon_in.weaponClass;
  prop.baseStorePrice = weapon_in.baseStorePrice;
  prop.baseDamage = weapon_in.baseDamage;
  prop.criticalHitModifier = weapon_in.criticalHitModifier;
  prop.rangeIncrement = weapon_in.rangeIncrement;
  prop.baseWeight = weapon_in.baseWeight;
  prop.typeOfDamage = weapon_in.typeOfDamage;

  myWeaponDictionary->insert(RPG_ITEM_WEAPONDICTIONARY_ITEM_T(weapon_in.weaponType, prop));
}

// RPG_ITEM_WEAPON_DICTIONARY_T RPG_Item_WeaponDictionary_Type::post_RPG_Item_WeaponDictionary_Type()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_WeaponDictionary_Type::post_RPG_Item_WeaponDictionary_Type"));
// 
//   // TODO
//   //
//   // return ... ;
// }

RPG_Item_ArmorDictionary_Type::RPG_Item_ArmorDictionary_Type(RPG_ITEM_ARMORDICTIONARY_T* armorDictionary_in)
 : myArmorDictionary(armorDictionary_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorDictionary_Type::RPG_Item_ArmorDictionary_Type"));

}

// void RPG_Item_ArmorDictionary_Type::pre()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_ArmorDictionary_Type::pre"));
// 
// }

void RPG_Item_ArmorDictionary_Type::armor(const RPG_Item_ArmorProperties_XML& armor_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorDictionary_Type::armor"));

  RPG_Item_ArmorProperties prop;
  prop.armorCategory = armor_in.armorCategory;
  prop.baseStorePrice = armor_in.baseStorePrice;
  prop.baseArmorBonus = armor_in.baseArmorBonus;
  prop.maxDexterityBonus = armor_in.maxDexterityBonus;
  prop.armorCheckPenalty = armor_in.armorCheckPenalty;
  prop.arcaneSpellFailure = armor_in.arcaneSpellFailure;
  prop.baseSpeed = armor_in.baseSpeed;
  prop.baseWeight = armor_in.baseWeight;

  myArmorDictionary->insert(RPG_ITEM_ARMORDICTIONARY_ITEM_T(armor_in.armorType, prop));
}

// RPG_ITEM_ARMOR_DICTIONARY_T RPG_Item_ArmorDictionary_Type::post_RPG_Item_ArmorDictionary_Type()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_ArmorDictionary_Type::post_RPG_Item_ArmorDictionary_Type"));
// 
//   // TODO
//   //
//   // return ... ;
// }

void RPG_Item_WeaponCategory_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponCategory_Type::pre"));

}

RPG_Item_WeaponCategory RPG_Item_WeaponCategory_Type::post_RPG_Item_WeaponCategory_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponCategory_Type::post_RPG_Item_WeaponCategory_Type"));

  std::string v = post_string();

  return RPG_Item_Common_Tools::stringToWeaponCategory(v);
}

void RPG_Item_WeaponClass_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponClass_Type::pre"));

}

RPG_Item_WeaponClass RPG_Item_WeaponClass_Type::post_RPG_Item_WeaponClass_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponClass_Type::post_RPG_Item_WeaponClass_Type"));

  std::string v = post_string();

  return RPG_Item_Common_Tools::stringToWeaponClass(v);
}

void RPG_Item_WeaponType_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponType_Type::pre"));

}

RPG_Item_WeaponType RPG_Item_WeaponType_Type::post_RPG_Item_WeaponType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponType_Type::post_RPG_Item_WeaponType_Type"));

  std::string v = post_string();

  return RPG_Item_Common_Tools::stringToWeaponType(v);
}

RPG_Item_StorePrice_Type::RPG_Item_StorePrice_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::RPG_Item_StorePrice_Type"));

  myCurrentStorePrice.numGoldPieces = 0;
  myCurrentStorePrice.numSilverPieces = 0;
}

void RPG_Item_StorePrice_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::pre"));

}

void RPG_Item_StorePrice_Type::numGoldPieces(unsigned int numGoldPieces_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::numGoldPieces"));

  myCurrentStorePrice.numGoldPieces = numGoldPieces_in;
}

void RPG_Item_StorePrice_Type::numSilverPieces(unsigned int numSilverPieces_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::numSilverPieces"));

  myCurrentStorePrice.numSilverPieces = numSilverPieces_in;
}

RPG_Item_StorePrice RPG_Item_StorePrice_Type::post_RPG_Item_StorePrice_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::post_RPG_Item_StorePrice_Type"));

  return myCurrentStorePrice;
}

void RPG_Chance_DiceType_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_DiceType_Type::pre"));

}

RPG_Chance_DiceType RPG_Chance_DiceType_Type::post_RPG_Chance_DiceType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_DiceType_Type::post_RPG_Chance_DiceType_Type"));

  std::string v = post_string();

  return RPG_Chance_Dice_Common_Tools::stringToDiceType(v);
}

RPG_Chance_Roll_Type::RPG_Chance_Roll_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Roll_Type::RPG_Chance_Roll_Type"));

  myCurrentItemDamage.numDice = 0;
  myCurrentItemDamage.typeDice = D_TYPE_INVALID;
  myCurrentItemDamage.modifier = 0;
}

void RPG_Chance_Roll_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Roll_Type::pre"));

}

void RPG_Chance_Roll_Type::numDice(unsigned int numDice_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Roll_Type::numDice"));

  myCurrentItemDamage.numDice = numDice_in;
}

void RPG_Chance_Roll_Type::typeDice(const RPG_Chance_DiceType& typeDice_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Roll_Type::typeDice"));

  myCurrentItemDamage.typeDice = typeDice_in;
}

void RPG_Chance_Roll_Type::modifier(long long modifier_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Roll_Type::modifier"));

  myCurrentItemDamage.modifier = modifier_in;
}

RPG_Item_Damage RPG_Chance_Roll_Type::post_RPG_Chance_Roll_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Roll_Type::post_RPG_Chance_Roll_Type"));

  return myCurrentItemDamage;
}

RPG_Item_CriticalHitModifier_Type::RPG_Item_CriticalHitModifier_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_CriticalHitModifier_Type::RPG_Item_CriticalHitModifier_Type"));

  myCurrentCriticalHitModifier.minToHitRoll = 20;
  myCurrentCriticalHitModifier.damageModifier = 1;
}

void RPG_Item_CriticalHitModifier_Type::minToHitRoll(unsigned int minToHitRoll_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_CriticalHitModifier_Type::minToHitRoll"));

  myCurrentCriticalHitModifier.minToHitRoll = minToHitRoll_in;
}

void RPG_Item_CriticalHitModifier_Type::damageModifier(unsigned int damageModifier_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_CriticalHitModifier_Type::damageModifier"));

  myCurrentCriticalHitModifier.damageModifier = damageModifier_in;
}

void RPG_Item_CriticalHitModifier_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_CriticalHitModifier_Type::pre"));

}

RPG_Item_CriticalHitModifier RPG_Item_CriticalHitModifier_Type::post_RPG_Item_CriticalHitModifier_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_CriticalHitModifier_Type::post_RPG_Item_CriticalHitModifier_Type"));

  return myCurrentCriticalHitModifier;
}

void RPG_Item_WeaponDamageType_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponDamageType_Type::pre"));

}

RPG_Item_WeaponDamageType RPG_Item_WeaponDamageType_Type::post_RPG_Item_WeaponDamageType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponDamageType_Type::post_RPG_Item_WeaponDamageType_Type"));

  std::string v = post_string();

  return RPG_Item_Common_Tools::stringToWeaponDamageType(v);
}

RPG_Item_WeaponProperties_Type::RPG_Item_WeaponProperties_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::RPG_Item_WeaponProperties_Type"));

  myCurrentWeaponProperty.weaponCategory = WEAPONCATEGORY_INVALID;
  myCurrentWeaponProperty.weaponClass = WEAPONCLASS_INVALID;
  myCurrentWeaponProperty.baseStorePrice.numGoldPieces = 0;
  myCurrentWeaponProperty.baseStorePrice.numSilverPieces = 0;
  myCurrentWeaponProperty.baseDamage.numDice = 0;
  myCurrentWeaponProperty.baseDamage.typeDice = D_TYPE_INVALID;
  myCurrentWeaponProperty.baseDamage.modifier = 0;
  myCurrentWeaponProperty.criticalHitModifier.minToHitRoll = 20;
  myCurrentWeaponProperty.criticalHitModifier.damageModifier = 1;
  myCurrentWeaponProperty.rangeIncrement = 30;
  myCurrentWeaponProperty.baseWeight = 0;
  myCurrentWeaponProperty.typeOfDamage = WEAPONDAMAGE_INVALID;
}

void RPG_Item_WeaponProperties_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::pre"));

}

void RPG_Item_WeaponProperties_Type::weaponType(const RPG_Item_WeaponType& weaponType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::weaponType"));

  myCurrentWeaponProperty.weaponType = weaponType_in;
}

void RPG_Item_WeaponProperties_Type::weaponCategory(const RPG_Item_WeaponCategory& weaponCategory_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::weaponCategory"));

  myCurrentWeaponProperty.weaponCategory = weaponCategory_in;
}

void RPG_Item_WeaponProperties_Type::weaponClass(const RPG_Item_WeaponClass& weaponClass_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::weaponClass"));

  myCurrentWeaponProperty.weaponClass = weaponClass_in;
}

void RPG_Item_WeaponProperties_Type::baseStorePrice(const RPG_Item_StorePrice& baseStorePrice_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::baseStorePrice"));

  myCurrentWeaponProperty.baseStorePrice = baseStorePrice_in;
}

void RPG_Item_WeaponProperties_Type::baseDamage(const RPG_Item_Damage& baseDamage_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::baseDamage"));

  myCurrentWeaponProperty.baseDamage = baseDamage_in;
}

void RPG_Item_WeaponProperties_Type::criticalHitModifier(const RPG_Item_CriticalHitModifier& criticalHitModifier_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::criticalHitModifier"));

  myCurrentWeaponProperty.criticalHitModifier = criticalHitModifier_in;
}

void RPG_Item_WeaponProperties_Type::rangeIncrement(unsigned int rangeIncrement_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::rangeIncrement"));

  myCurrentWeaponProperty.rangeIncrement = rangeIncrement_in;
}

void RPG_Item_WeaponProperties_Type::baseWeight(unsigned int baseWeight_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::baseWeight"));

  myCurrentWeaponProperty.baseWeight = baseWeight_in;
}

void RPG_Item_WeaponProperties_Type::typeOfDamage(const RPG_Item_WeaponDamageType& typeOfDamage_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::typeOfDamage"));

  myCurrentWeaponProperty.typeOfDamage = typeOfDamage_in;
}

RPG_Item_WeaponProperties_XML RPG_Item_WeaponProperties_Type::post_RPG_Item_WeaponProperties_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::post_RPG_Item_WeaponProperties_Type"));

  return myCurrentWeaponProperty;
}

void RPG_Item_ArmorCategory_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorCategory_Type::pre"));

}

RPG_Item_ArmorCategory RPG_Item_ArmorCategory_Type::post_RPG_Item_ArmorCategory_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorCategory_Type::post_RPG_Item_ArmorCategory_Type"));

  std::string v = post_string();

  return RPG_Item_Common_Tools::stringToArmorCategory(v);
}

void RPG_Item_ArmorType_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorType_Type::pre"));

}

RPG_Item_ArmorType RPG_Item_ArmorType_Type::post_RPG_Item_ArmorType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorType_Type::post_RPG_Item_ArmorType_Type"));

  std::string v = post_string();

  return RPG_Item_Common_Tools::stringToArmorType(v);
}

void RPG_Item_ArmorProperties_Type::pre()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::pre"));

}

void RPG_Item_ArmorProperties_Type::armorType(const RPG_Item_ArmorType& armorType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::armorType"));

  myCurrenArmorProperty.armorType = armorType_in;
}

void RPG_Item_ArmorProperties_Type::armorCategory(const RPG_Item_ArmorCategory& armorCategory_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::armorCategory"));

  myCurrenArmorProperty.armorCategory = armorCategory_in;
}

void RPG_Item_ArmorProperties_Type::baseStorePrice(const RPG_Item_StorePrice& baseStorePrice_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::baseStorePrice"));

  myCurrenArmorProperty.baseStorePrice = baseStorePrice_in;
}

void RPG_Item_ArmorProperties_Type::baseArmorBonus(unsigned int baseArmorBonus_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::baseArmorBonus"));

  myCurrenArmorProperty.baseArmorBonus = baseArmorBonus_in;
}

void RPG_Item_ArmorProperties_Type::maxDexterityBonus(unsigned int maxDexterityBonus_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::maxDexterityBonus"));

  myCurrenArmorProperty.maxDexterityBonus = maxDexterityBonus_in;
}

void RPG_Item_ArmorProperties_Type::armorCheckPenalty(long long armorCheckPenalty_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::armorCheckPenalty"));

  myCurrenArmorProperty.armorCheckPenalty = armorCheckPenalty_in;
}

void RPG_Item_ArmorProperties_Type::arcaneSpellFailure(unsigned int arcaneSpellFailure_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::arcaneSpellFailure"));

  myCurrenArmorProperty.arcaneSpellFailure = arcaneSpellFailure_in;
}

void RPG_Item_ArmorProperties_Type::baseSpeed(unsigned int baseSpeed_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::baseSpeed"));

  myCurrenArmorProperty.baseSpeed = baseSpeed_in;
}

void RPG_Item_ArmorProperties_Type::baseWeight(unsigned int baseWeight_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::baseWeight"));

  myCurrenArmorProperty.baseWeight = baseWeight_in;
}

RPG_Item_ArmorProperties_XML RPG_Item_ArmorProperties_Type::post_RPG_Item_ArmorProperties_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::post_RPG_Item_ArmorProperties_Type"));

  return myCurrenArmorProperty;
}
