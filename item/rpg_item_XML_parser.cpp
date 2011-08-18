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

#include "rpg_item_XML_parser.h"

#include "rpg_item_weapontype.h"
#include "rpg_item_weaponcategory.h"
#include "rpg_item_weaponclass.h"
#include "rpg_item_armorcategory.h"

#include <rpg_common_macros.h>

#include <ace/Log_Msg.h>

RPG_Item_Dictionary_Type::RPG_Item_Dictionary_Type(RPG_Item_WeaponDictionary_t* weaponDictionary_in,
                                                   RPG_Item_ArmorDictionary_t* armorDictionary_in)
 : myWeaponDictionary(weaponDictionary_in),
   myArmorDictionary(armorDictionary_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Dictionary_Type::RPG_Item_Dictionary_Type"));

}

RPG_Item_Dictionary_Type::~RPG_Item_Dictionary_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Dictionary_Type::~RPG_Item_Dictionary_Type"));

}

// void RPG_Item_Dictionary_Type::pre()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_Dictionary_Type::pre"));
//
// }

void RPG_Item_Dictionary_Type::weapon(const RPG_Item_WeaponPropertiesXML& weapon_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Dictionary_Type::weapon"));

  RPG_Item_WeaponProperties prop;
  prop.toHitModifier = weapon_in.toHitModifier;
  prop.weaponCategory = weapon_in.weaponCategory;
  prop.weaponClass = weapon_in.weaponClass;
  prop.baseDamage = weapon_in.baseDamage;
  prop.criticalHit = weapon_in.criticalHit;
  prop.rangeIncrement = weapon_in.rangeIncrement;
  prop.typeOfDamage = PHYSICALDAMAGE_NONE;
  for (std::vector<RPG_Common_PhysicalDamageType>::const_iterator iterator = weapon_in.typeOfDamages.begin();
       iterator != weapon_in.typeOfDamages.end();
       iterator++)
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("weapon %s: damage: %s\n"),
//                RPG_Item_WeaponTypeHelper::RPG_Item_WeaponTypeToString(weapon_in.weaponType).c_str(),
//                RPG_Item_PhysicalDamageTypeHelper::RPG_Item_PhysicalDamageTypeToString(*iterator).c_str()));

    // *IMPORTANT NOTE*: consider that some weapons don't do any damage...
    // --> in that case, the element could be empty OR set to this
    if ((*iterator) != PHYSICALDAMAGE_NONE)
      prop.typeOfDamage.set((*iterator - 1));
  } // end FOR
  prop.isNonLethal = weapon_in.isNonLethal;
  prop.isReachWeapon = weapon_in.isReachWeapon;
  prop.isDoubleWeapon = weapon_in.isDoubleWeapon;
  prop.aura = weapon_in.aura;
  prop.prerequisites = weapon_in.prerequisites;
  prop.baseWeight = weapon_in.baseWeight;
  prop.baseStorePrice = weapon_in.baseStorePrice;
  prop.costToCreate = weapon_in.costToCreate;

  myWeaponDictionary->insert(std::make_pair(weapon_in.weaponType, prop));
}

void RPG_Item_Dictionary_Type::armor(const RPG_Item_ArmorPropertiesXML& armor_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Dictionary_Type::armor"));

  RPG_Item_ArmorProperties prop;
  prop.defenseModifier = armor_in.defenseModifier;
  prop.armorCategory = armor_in.armorCategory;
  prop.baseArmorBonus = armor_in.baseArmorBonus;
  prop.maxDexterityBonus = armor_in.maxDexterityBonus;
  prop.armorCheckPenalty = armor_in.armorCheckPenalty;
  prop.arcaneSpellFailure = armor_in.arcaneSpellFailure;
  prop.baseSpeed = armor_in.baseSpeed;
  prop.aura = armor_in.aura;
  prop.prerequisites = armor_in.prerequisites;
  prop.baseWeight = armor_in.baseWeight;
  prop.baseStorePrice = armor_in.baseStorePrice;
  prop.costToCreate = armor_in.costToCreate;

  myArmorDictionary->insert(std::make_pair(armor_in.armorType, prop));
}

void RPG_Item_Dictionary_Type::post_RPG_Item_Dictionary_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Dictionary_Type::post_RPG_Item_Dictionary_Type"));

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished parsing item dictionary, retrieved %d weapon and %d armor types...\n"),
             myWeaponDictionary->size(),
             myArmorDictionary->size()));
}

RPG_Item_WeaponCategory RPG_Item_WeaponCategory_Type::post_RPG_Item_WeaponCategory_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponCategory_Type::post_RPG_Item_WeaponCategory_Type"));

  return RPG_Item_WeaponCategoryHelper::stringToRPG_Item_WeaponCategory(post_string());
}

// void RPG_Item_WeaponClass_Type::pre()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_WeaponClass_Type::pre"));
//
// }

RPG_Item_WeaponClass RPG_Item_WeaponClass_Type::post_RPG_Item_WeaponClass_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponClass_Type::post_RPG_Item_WeaponClass_Type"));

  return RPG_Item_WeaponClassHelper::stringToRPG_Item_WeaponClass(post_string());
}

// void RPG_Item_WeaponType_Type::pre()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_WeaponType_Type::pre"));
//
// }

RPG_Item_WeaponType RPG_Item_WeaponType_Type::post_RPG_Item_WeaponType_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponType_Type::post_RPG_Item_WeaponType_Type"));

  return RPG_Item_WeaponTypeHelper::stringToRPG_Item_WeaponType(post_string());
}

RPG_Item_StorePrice_Type::RPG_Item_StorePrice_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::RPG_Item_StorePrice_Type"));

  myCurrentStorePrice.numGoldPieces = 0;
  myCurrentStorePrice.numSilverPieces = 0;
}

// void RPG_Item_StorePrice_Type::pre()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::pre"));
//
// }

void RPG_Item_StorePrice_Type::numGoldPieces(unsigned int numGoldPieces_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::numGoldPieces"));

  myCurrentStorePrice.numGoldPieces = numGoldPieces_in;
}

void RPG_Item_StorePrice_Type::numSilverPieces(unsigned int numSilverPieces_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::numSilverPieces"));

  myCurrentStorePrice.numSilverPieces = numSilverPieces_in;
}

RPG_Item_StorePrice RPG_Item_StorePrice_Type::post_RPG_Item_StorePrice_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_StorePrice_Type::post_RPG_Item_StorePrice_Type"));

  return myCurrentStorePrice;
}

RPG_Item_CriticalHitProperties_Type::RPG_Item_CriticalHitProperties_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_CriticalHitProperties_Type::RPG_Item_CriticalHitProperties_Type"));

  myCurrentCriticalHitProperties.minToHitRoll = 20;
  myCurrentCriticalHitProperties.damageModifier = 1;
}

void RPG_Item_CriticalHitProperties_Type::minToHitRoll(unsigned char minToHitRoll_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_CriticalHitProperties_Type::minToHitRoll"));

  myCurrentCriticalHitProperties.minToHitRoll = minToHitRoll_in;
}

void RPG_Item_CriticalHitProperties_Type::damageModifier(unsigned char damageModifier_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_CriticalHitProperties_Type::damageModifier"));

  myCurrentCriticalHitProperties.damageModifier = damageModifier_in;
}

RPG_Item_CriticalHitProperties RPG_Item_CriticalHitProperties_Type::post_RPG_Item_CriticalHitProperties_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_CriticalHitProperties_Type::post_RPG_Item_CriticalHitProperties_Type"));

  return myCurrentCriticalHitProperties;
}

RPG_Item_CreationCost_Type::RPG_Item_CreationCost_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_CreationCost_Type::RPG_Item_CreationCost_Type"));

  myCurrentCreationCost.numGoldPieces = 0;
  myCurrentCreationCost.numExperiencePoints = 0;
}

void RPG_Item_CreationCost_Type::numGoldPieces(unsigned int goldPieces_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_CreationCost_Type::numGoldPieces"));

  myCurrentCreationCost.numGoldPieces = goldPieces_in;
}

void RPG_Item_CreationCost_Type::numExperiencePoints(unsigned int experiencePoints_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_CreationCost_Type::numExperiencePoints"));

  myCurrentCreationCost.numExperiencePoints = experiencePoints_in;
}

RPG_Item_CreationCost RPG_Item_CreationCost_Type::post_RPG_Item_CreationCost_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_CreationCost_Type::post_RPG_Item_CreationCost_Type"));

  RPG_Item_CreationCost result = myCurrentCreationCost;

  myCurrentCreationCost.numGoldPieces = 0;
  myCurrentCreationCost.numExperiencePoints = 0;

  return result;
}

// RPG_Item_BaseProperties_Type::RPG_Item_BaseProperties_Type()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_BaseProperties_Type::RPG_Item_BaseProperties_Type"));
//
//   myBaseProperties.baseWeight = 0;
//   myBaseProperties.baseStorePrice.numGoldPieces = 0;
//   myBaseProperties.baseStorePrice.numSilverPieces = 0;
//   myBaseProperties.costToCreate.numGoldPieces = 0;
//   myBaseProperties.costToCreate.numExperiencePoints = 0;
// }
//
// void RPG_Item_BaseProperties_Type::baseWeight(unsigned short baseWeight_in)
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_BaseProperties_Type::baseWeight"));
//
//   myBaseProperties.baseWeight = baseWeight_in;
// }
//
// void RPG_Item_BaseProperties_Type::baseStorePrice(const RPG_Item_StorePrice& baseStorePrice_in)
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_BaseProperties_Type::baseStorePrice"));
//
//   myBaseProperties.baseStorePrice = baseStorePrice_in;
// }
//
// void RPG_Item_BaseProperties_Type::costToCreate(const RPG_Item_CreationCost& creationCost_in)
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_BaseProperties_Type::costToCreate"));
//
//   myBaseProperties.costToCreate = creationCost_in;
// }
//
// RPG_Item_BaseProperties RPG_Item_BaseProperties_Type::post_RPG_Item_BaseProperties_Type()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_BaseProperties_Type::post_RPG_Item_BaseProperties_Type"));
//
//   RPG_Item_BaseProperties result = myBaseProperties;
//
//   myBaseProperties.baseWeight = 0;
//   myBaseProperties.baseStorePrice.numGoldPieces = 0;
//   myBaseProperties.baseStorePrice.numSilverPieces = 0;
//   myBaseProperties.costToCreate.numGoldPieces = 0;
//   myBaseProperties.costToCreate.numExperiencePoints = 0;
//
//   return result;
// }

RPG_Item_MagicalPrerequisites_Type::RPG_Item_MagicalPrerequisites_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_MagicalPrerequisites_Type::RPG_Item_MagicalPrerequisites_Type"));

  myCurrentPrerequisites.minCasterLevel = 0;
}

void RPG_Item_MagicalPrerequisites_Type::minCasterLevel(unsigned char minCasterLevel_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_MagicalPrerequisites_Type::minCasterLevel"));

  myCurrentPrerequisites.minCasterLevel = minCasterLevel_in;
}

RPG_Item_MagicalPrerequisites RPG_Item_MagicalPrerequisites_Type::post_RPG_Item_MagicalPrerequisites_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_MagicalPrerequisites_Type::post_RPG_Item_MagicalPrerequisites_Type"));

  RPG_Item_MagicalPrerequisites result = myCurrentPrerequisites;

  myCurrentPrerequisites.minCasterLevel = 0;

  return result;
}

RPG_Item_WeaponPropertiesXML_Type::RPG_Item_WeaponPropertiesXML_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::RPG_Item_WeaponPropertiesXML_Type"));

  // reset current properties
  myCurrentWeaponProperties.baseWeight = 0;
  myCurrentWeaponProperties.baseStorePrice.numGoldPieces = 0;
  myCurrentWeaponProperties.baseStorePrice.numSilverPieces = 0;
  myCurrentWeaponProperties.costToCreate.numGoldPieces = 0;
  myCurrentWeaponProperties.costToCreate.numExperiencePoints = 0;
  // -------------------------------------------------------------
  myCurrentWeaponProperties.aura = RPG_MAGIC_SCHOOL_INVALID;
  myCurrentWeaponProperties.prerequisites.minCasterLevel = 0;
  // -------------------------------------------------------------
  myCurrentWeaponProperties.weaponType = RPG_ITEM_WEAPONTYPE_INVALID;
  myCurrentWeaponProperties.weaponCategory = RPG_ITEM_WEAPONCATEGORY_INVALID;
  myCurrentWeaponProperties.weaponClass = RPG_ITEM_WEAPONCLASS_INVALID;
  myCurrentWeaponProperties.baseStorePrice.numGoldPieces = 0;
  myCurrentWeaponProperties.baseStorePrice.numSilverPieces = 0;
  myCurrentWeaponProperties.baseDamage.numDice = 0;
  myCurrentWeaponProperties.baseDamage.typeDice = RPG_DICE_DIETYPE_INVALID;
  myCurrentWeaponProperties.baseDamage.modifier = 0;
  myCurrentWeaponProperties.criticalHit.minToHitRoll = 20;
  myCurrentWeaponProperties.criticalHit.damageModifier = 1;
  myCurrentWeaponProperties.rangeIncrement = 0;
  myCurrentWeaponProperties.baseWeight = 0;
  myCurrentWeaponProperties.typeOfDamages.clear();
  myCurrentWeaponProperties.isNonLethal = false;
  myCurrentWeaponProperties.isReachWeapon = false;
  myCurrentWeaponProperties.isDoubleWeapon = false;
  // -------------------------------------------------------------
  myCurrentWeaponProperties.toHitModifier = 0;
}

// void RPG_Item_WeaponProperties_Type::pre()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_WeaponProperties_Type::pre"));
//
// }

void RPG_Item_WeaponPropertiesXML_Type::baseWeight(unsigned short baseWeight_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::baseWeight"));

  myCurrentWeaponProperties.baseWeight = baseWeight_in;
}

void RPG_Item_WeaponPropertiesXML_Type::baseStorePrice(const RPG_Item_StorePrice& baseStorePrice_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::baseStorePrice"));

  myCurrentWeaponProperties.baseStorePrice = baseStorePrice_in;
}

void RPG_Item_WeaponPropertiesXML_Type::costToCreate(const RPG_Item_CreationCost& creationCost_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::costToCreate"));

  myCurrentWeaponProperties.costToCreate = creationCost_in;
}

RPG_Item_BaseProperties RPG_Item_WeaponPropertiesXML_Type::post_RPG_Item_BaseProperties_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::post_RPG_Item_BaseProperties_Type"));

  RPG_Item_BaseProperties result = myCurrentWeaponProperties;

  return result;
}

void RPG_Item_WeaponPropertiesXML_Type::aura(const RPG_Magic_School& school_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::aura"));

  myCurrentWeaponProperties.aura = school_in;
}

void RPG_Item_WeaponPropertiesXML_Type::prerequisites(const RPG_Item_MagicalPrerequisites& prerequisites_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::prerequisites"));

  myCurrentWeaponProperties.prerequisites = prerequisites_in;
}

RPG_Item_PropertiesBase RPG_Item_WeaponPropertiesXML_Type::post_RPG_Item_PropertiesBase_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::post_RPG_Item_PropertiesBase_Type"));

  RPG_Item_PropertiesBase result = myCurrentWeaponProperties;

  return result;
}

void RPG_Item_WeaponPropertiesXML_Type::weaponType(const RPG_Item_WeaponType& weaponType_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::weaponType"));

  myCurrentWeaponProperties.weaponType = weaponType_in;
}

void RPG_Item_WeaponPropertiesXML_Type::weaponCategory(const RPG_Item_WeaponCategory& weaponCategory_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::weaponCategory"));

  myCurrentWeaponProperties.weaponCategory = weaponCategory_in;
}

void RPG_Item_WeaponPropertiesXML_Type::weaponClass(const RPG_Item_WeaponClass& weaponClass_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::weaponClass"));

  myCurrentWeaponProperties.weaponClass = weaponClass_in;
}

void RPG_Item_WeaponPropertiesXML_Type::baseDamage(const RPG_Item_Damage& baseDamage_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::baseDamage"));

  myCurrentWeaponProperties.baseDamage = baseDamage_in;
}

void RPG_Item_WeaponPropertiesXML_Type::criticalHit(const RPG_Item_CriticalHitProperties& criticalHit_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::criticalHit"));

  myCurrentWeaponProperties.criticalHit = criticalHit_in;
}

void RPG_Item_WeaponPropertiesXML_Type::rangeIncrement(unsigned char rangeIncrement_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::rangeIncrement"));

  myCurrentWeaponProperties.rangeIncrement = rangeIncrement_in;
}

void RPG_Item_WeaponPropertiesXML_Type::typeOfDamage(const RPG_Common_PhysicalDamageType& typeOfDamage_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::typeOfDamage"));

  myCurrentWeaponProperties.typeOfDamages.push_back(typeOfDamage_in);
}

void RPG_Item_WeaponPropertiesXML_Type::isNonLethal(bool isNonLethal_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::isNonLethal"));

  myCurrentWeaponProperties.isNonLethal = isNonLethal_in;
}

void RPG_Item_WeaponPropertiesXML_Type::isReachWeapon(bool isReachWeapon_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::isReachWeapon"));

  myCurrentWeaponProperties.isReachWeapon = isReachWeapon_in;
}

void RPG_Item_WeaponPropertiesXML_Type::isDoubleWeapon(bool isDoubleWeapon_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::isDoubleWeapon"));

  myCurrentWeaponProperties.isDoubleWeapon = isDoubleWeapon_in;
}

RPG_Item_WeaponPropertiesBase RPG_Item_WeaponPropertiesXML_Type::post_RPG_Item_WeaponPropertiesBase_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::post_RPG_Item_WeaponPropertiesBase_Type"));

  RPG_Item_WeaponPropertiesBase result = myCurrentWeaponProperties;

  return result;
}

void RPG_Item_WeaponPropertiesXML_Type::toHitModifier(signed char toHitModifier_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::toHitModifier"));

  myCurrentWeaponProperties.toHitModifier = toHitModifier_in;
}

RPG_Item_WeaponPropertiesXML RPG_Item_WeaponPropertiesXML_Type::post_RPG_Item_WeaponPropertiesXML_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_WeaponPropertiesXML_Type::post_RPG_Item_WeaponPropertiesXML_Type"));

  RPG_Item_WeaponPropertiesXML result = myCurrentWeaponProperties;

  // reset current properties
  myCurrentWeaponProperties.baseWeight = 0;
  myCurrentWeaponProperties.baseStorePrice.numGoldPieces = 0;
  myCurrentWeaponProperties.baseStorePrice.numSilverPieces = 0;
  myCurrentWeaponProperties.costToCreate.numGoldPieces = 0;
  myCurrentWeaponProperties.costToCreate.numExperiencePoints = 0;
  // -------------------------------------------------------------
  myCurrentWeaponProperties.aura = RPG_MAGIC_SCHOOL_INVALID;
  myCurrentWeaponProperties.prerequisites.minCasterLevel = 0;
  // -------------------------------------------------------------
  myCurrentWeaponProperties.weaponType = RPG_ITEM_WEAPONTYPE_INVALID;
  myCurrentWeaponProperties.weaponCategory = RPG_ITEM_WEAPONCATEGORY_INVALID;
  myCurrentWeaponProperties.weaponClass = RPG_ITEM_WEAPONCLASS_INVALID;
  myCurrentWeaponProperties.baseStorePrice.numGoldPieces = 0;
  myCurrentWeaponProperties.baseStorePrice.numSilverPieces = 0;
  myCurrentWeaponProperties.baseDamage.numDice = 0;
  myCurrentWeaponProperties.baseDamage.typeDice = RPG_DICE_DIETYPE_INVALID;
  myCurrentWeaponProperties.baseDamage.modifier = 0;
  myCurrentWeaponProperties.criticalHit.minToHitRoll = 20;
  myCurrentWeaponProperties.criticalHit.damageModifier = 1;
  myCurrentWeaponProperties.rangeIncrement = 0;
  myCurrentWeaponProperties.baseWeight = 0;
  myCurrentWeaponProperties.typeOfDamages.clear();
  myCurrentWeaponProperties.isNonLethal = false;
  myCurrentWeaponProperties.isReachWeapon = false;
  myCurrentWeaponProperties.isDoubleWeapon = false;
  // -------------------------------------------------------------
  myCurrentWeaponProperties.toHitModifier = 0;

  return result;
}

// void RPG_Item_ArmorCategory_Type::pre()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_ArmorCategory_Type::pre"));
//
// }

RPG_Item_ArmorCategory RPG_Item_ArmorCategory_Type::post_RPG_Item_ArmorCategory_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorCategory_Type::post_RPG_Item_ArmorCategory_Type"));

  return RPG_Item_ArmorCategoryHelper::stringToRPG_Item_ArmorCategory(post_string());
}

// void RPG_Item_ArmorType_Type::pre()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_ArmorType_Type::pre"));
//
// }

RPG_Item_ArmorType RPG_Item_ArmorType_Type::post_RPG_Item_ArmorType_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorType_Type::post_RPG_Item_ArmorType_Type"));

  return RPG_Item_ArmorTypeHelper::stringToRPG_Item_ArmorType(post_string());
}

RPG_Item_ArmorPropertiesXML_Type::RPG_Item_ArmorPropertiesXML_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::RPG_Item_ArmorPropertiesXML_Type"));

  // reset properties
  myCurrentArmorProperties.baseWeight = 0;
  myCurrentArmorProperties.baseStorePrice.numGoldPieces = 0;
  myCurrentArmorProperties.baseStorePrice.numSilverPieces = 0;
  myCurrentArmorProperties.costToCreate.numGoldPieces = 0;
  myCurrentArmorProperties.costToCreate.numExperiencePoints = 0;
  // -------------------------------------------------------------
  myCurrentArmorProperties.aura = RPG_MAGIC_SCHOOL_INVALID;
  myCurrentArmorProperties.prerequisites.minCasterLevel = 0;
  // -------------------------------------------------------------
  myCurrentArmorProperties.armorType = RPG_ITEM_ARMORTYPE_INVALID;
  myCurrentArmorProperties.armorCategory = RPG_ITEM_ARMORCATEGORY_INVALID;
  myCurrentArmorProperties.baseStorePrice.numGoldPieces = 0;
  myCurrentArmorProperties.baseStorePrice.numSilverPieces = 0;
  myCurrentArmorProperties.baseArmorBonus = 0;
  myCurrentArmorProperties.maxDexterityBonus = 0;
  myCurrentArmorProperties.armorCheckPenalty = 0;
  myCurrentArmorProperties.arcaneSpellFailure = 0;
  myCurrentArmorProperties.baseSpeed = 0;
  myCurrentArmorProperties.baseWeight = 0;
  // -------------------------------------------------------------
  myCurrentArmorProperties.defenseModifier = 0;
}

// void RPG_Item_ArmorProperties_Type::pre()
// {
//   RPG_TRACE(ACE_TEXT("RPG_Item_ArmorProperties_Type::pre"));
//
// }

void RPG_Item_ArmorPropertiesXML_Type::baseWeight(unsigned short baseWeight_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::baseWeight"));

  myCurrentArmorProperties.baseWeight = baseWeight_in;
}

void RPG_Item_ArmorPropertiesXML_Type::baseStorePrice(const RPG_Item_StorePrice& baseStorePrice_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::baseStorePrice"));

  myCurrentArmorProperties.baseStorePrice = baseStorePrice_in;
}

void RPG_Item_ArmorPropertiesXML_Type::costToCreate(const RPG_Item_CreationCost& creationCost_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::costToCreate"));

  myCurrentArmorProperties.costToCreate = creationCost_in;
}

RPG_Item_BaseProperties RPG_Item_ArmorPropertiesXML_Type::post_RPG_Item_BaseProperties_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::post_RPG_Item_BaseProperties_Type"));

  RPG_Item_BaseProperties result = myCurrentArmorProperties;

  return result;
}

void RPG_Item_ArmorPropertiesXML_Type::aura(const RPG_Magic_School& school_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::aura"));

  myCurrentArmorProperties.aura = school_in;
}

void RPG_Item_ArmorPropertiesXML_Type::prerequisites(const RPG_Item_MagicalPrerequisites& prerequisites_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::prerequisites"));

  myCurrentArmorProperties.prerequisites = prerequisites_in;
}

RPG_Item_PropertiesBase RPG_Item_ArmorPropertiesXML_Type::post_RPG_Item_PropertiesBase_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::post_RPG_Item_PropertiesBase_Type"));

  RPG_Item_PropertiesBase result = myCurrentArmorProperties;

  return result;
}

void RPG_Item_ArmorPropertiesXML_Type::armorType(const RPG_Item_ArmorType& armorType_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::armorType"));

  myCurrentArmorProperties.armorType = armorType_in;
}

void RPG_Item_ArmorPropertiesXML_Type::armorCategory(const RPG_Item_ArmorCategory& armorCategory_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::armorCategory"));

  myCurrentArmorProperties.armorCategory = armorCategory_in;
}

void RPG_Item_ArmorPropertiesXML_Type::baseArmorBonus(unsigned char baseArmorBonus_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::baseArmorBonus"));

  myCurrentArmorProperties.baseArmorBonus = baseArmorBonus_in;
}

void RPG_Item_ArmorPropertiesXML_Type::maxDexterityBonus(unsigned char maxDexterityBonus_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::maxDexterityBonus"));

  myCurrentArmorProperties.maxDexterityBonus = maxDexterityBonus_in;
}

void RPG_Item_ArmorPropertiesXML_Type::armorCheckPenalty(signed char armorCheckPenalty_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::armorCheckPenalty"));

  myCurrentArmorProperties.armorCheckPenalty = armorCheckPenalty_in;
}

void RPG_Item_ArmorPropertiesXML_Type::arcaneSpellFailure(unsigned char arcaneSpellFailure_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::arcaneSpellFailure"));

  myCurrentArmorProperties.arcaneSpellFailure = arcaneSpellFailure_in;
}

void RPG_Item_ArmorPropertiesXML_Type::baseSpeed(unsigned short baseSpeed_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::baseSpeed"));

  myCurrentArmorProperties.baseSpeed = baseSpeed_in;
}

RPG_Item_ArmorPropertiesBase RPG_Item_ArmorPropertiesXML_Type::post_RPG_Item_ArmorPropertiesBase_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::post_RPG_Item_ArmorPropertiesBase_Type"));

  RPG_Item_ArmorPropertiesBase result = myCurrentArmorProperties;

  return result;
}

void RPG_Item_ArmorPropertiesXML_Type::defenseModifier(signed char defenseModifier_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::defenseModifier"));

  myCurrentArmorProperties.defenseModifier = defenseModifier_in;
}

RPG_Item_ArmorPropertiesXML RPG_Item_ArmorPropertiesXML_Type::post_RPG_Item_ArmorPropertiesXML_Type()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_ArmorPropertiesXML_Type::post_RPG_Item_ArmorPropertiesXML_Type"));

  RPG_Item_ArmorPropertiesXML result = myCurrentArmorProperties;

  // reset properties
  myCurrentArmorProperties.baseWeight = 0;
  myCurrentArmorProperties.baseStorePrice.numGoldPieces = 0;
  myCurrentArmorProperties.baseStorePrice.numSilverPieces = 0;
  myCurrentArmorProperties.costToCreate.numGoldPieces = 0;
  myCurrentArmorProperties.costToCreate.numExperiencePoints = 0;
  // -------------------------------------------------------------
  myCurrentArmorProperties.aura = RPG_MAGIC_SCHOOL_INVALID;
  myCurrentArmorProperties.prerequisites.minCasterLevel = 0;
  // -------------------------------------------------------------
  myCurrentArmorProperties.armorType = RPG_ITEM_ARMORTYPE_INVALID;
  myCurrentArmorProperties.armorCategory = RPG_ITEM_ARMORCATEGORY_INVALID;
  myCurrentArmorProperties.baseStorePrice.numGoldPieces = 0;
  myCurrentArmorProperties.baseStorePrice.numSilverPieces = 0;
  myCurrentArmorProperties.baseArmorBonus = 0;
  myCurrentArmorProperties.maxDexterityBonus = 0;
  myCurrentArmorProperties.armorCheckPenalty = 0;
  myCurrentArmorProperties.arcaneSpellFailure = 0;
  myCurrentArmorProperties.baseSpeed = 0;
  myCurrentArmorProperties.baseWeight = 0;
  // -------------------------------------------------------------
  myCurrentArmorProperties.defenseModifier = 0;

  return result;
}
