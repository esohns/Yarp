// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef CXX__ITEM_RPG_ITEM_XML_TYPES_H
#define CXX__ITEM_RPG_ITEM_XML_TYPES_H

// Begin prologue.
//
#include "rpg_item_exports.h"
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

// Forward declarations
//
class RPG_Item_Type_Type_pskel;
class RPG_Item_CommodityType_Type_pskel;
class RPG_Item_CommodityBeverage_Type_pskel;
class RPG_Item_CommodityLight_Type_pskel;
class RPG_Item_CommodityUnion_Type_pskel;
class RPG_Item_Money_Type_pskel;
class RPG_Item_WeaponCategory_Type_pskel;
class RPG_Item_WeaponClass_Type_pskel;
class RPG_Item_WeaponType_Type_pskel;
class RPG_Item_StorePrice_Type_pskel;
class RPG_Item_CriticalHitProperties_Type_pskel;
class RPG_Item_CreationCost_Type_pskel;
class RPG_Item_BaseProperties_Type_pskel;
class RPG_Item_MagicalPrerequisites_Type_pskel;
class RPG_Item_PropertiesBase_Type_pskel;
class RPG_Item_CommodityPropertiesBase_Type_pskel;
class RPG_Item_WeaponPropertiesBase_Type_pskel;
class RPG_Item_WeaponPropertiesXML_Type_pskel;
class RPG_Item_ArmorCategory_Type_pskel;
class RPG_Item_ArmorType_Type_pskel;
class RPG_Item_ArmorPropertiesBase_Type_pskel;
class RPG_Item_ArmorPropertiesXML_Type_pskel;
class RPG_Item_BaseXML_Type_pskel;
class RPG_Item_InventoryXML_Type_pskel;
class RPG_Item_DictionaryXML_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_XMLSchema_XML_types.h"

#include "rpg_dice_incl.h"
#include "rpg_common_incl.h"
#include "rpg_common_environment_incl.h"
#include "rpg_character_incl.h"
#include "rpg_magic_incl.h"
#include "rpg_item_incl.h"
#include "rpg_item_common.h"

#include "rpg_dice_XML_types.h"

#include "rpg_common_XML_types.h"

#include "rpg_magic_XML_types.h"

class RPG_Item_Export RPG_Item_Type_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_Type
  post_RPG_Item_Type_Type () = 0;
};

class RPG_Item_Export RPG_Item_CommodityType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_CommodityType
  post_RPG_Item_CommodityType_Type () = 0;
};

class RPG_Item_Export RPG_Item_CommodityBeverage_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_CommodityBeverage
  post_RPG_Item_CommodityBeverage_Type () = 0;
};

class RPG_Item_Export RPG_Item_CommodityLight_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_CommodityLight
  post_RPG_Item_CommodityLight_Type () = 0;
};

class RPG_Item_Export RPG_Item_CommodityUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Item_CommodityUnion
  post_RPG_Item_CommodityUnion_Type () = 0;
};

class RPG_Item_Export RPG_Item_Money_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_Money
  post_RPG_Item_Money_Type () = 0;
};

class RPG_Item_Export RPG_Item_WeaponCategory_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_WeaponCategory
  post_RPG_Item_WeaponCategory_Type () = 0;
};

class RPG_Item_Export RPG_Item_WeaponClass_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_WeaponClass
  post_RPG_Item_WeaponClass_Type () = 0;
};

class RPG_Item_Export RPG_Item_WeaponType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_WeaponType
  post_RPG_Item_WeaponType_Type () = 0;
};

class RPG_Item_Export RPG_Item_StorePrice_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  numGoldPieces (unsigned int);

  virtual void
  numSilverPieces (unsigned int);

  virtual RPG_Item_StorePrice
  post_RPG_Item_StorePrice_Type () = 0;

  // Parser construction API.
  //
  void
  numGoldPieces_parser (::xml_schema::unsigned_int_pskel&);

  void
  numSilverPieces_parser (::xml_schema::unsigned_int_pskel&);

  void
  parsers (::xml_schema::unsigned_int_pskel& /* numGoldPieces */,
           ::xml_schema::unsigned_int_pskel& /* numSilverPieces */);

  // Constructor.
  //
  RPG_Item_StorePrice_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::unsigned_int_pskel* numGoldPieces_parser_;
  ::xml_schema::unsigned_int_pskel* numSilverPieces_parser_;
};

class RPG_Item_Export RPG_Item_CriticalHitProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  minToHitRoll (unsigned char);

  virtual void
  damageModifier (unsigned char);

  virtual RPG_Item_CriticalHitProperties
  post_RPG_Item_CriticalHitProperties_Type () = 0;

  // Parser construction API.
  //
  void
  minToHitRoll_parser (::xml_schema::unsigned_byte_pskel&);

  void
  damageModifier_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::xml_schema::unsigned_byte_pskel& /* minToHitRoll */,
           ::xml_schema::unsigned_byte_pskel& /* damageModifier */);

  // Constructor.
  //
  RPG_Item_CriticalHitProperties_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::unsigned_byte_pskel* minToHitRoll_parser_;
  ::xml_schema::unsigned_byte_pskel* damageModifier_parser_;
};

class RPG_Item_Export RPG_Item_CreationCost_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  numGoldPieces (unsigned int);

  virtual void
  numExperiencePoints (unsigned int);

  virtual RPG_Item_CreationCost
  post_RPG_Item_CreationCost_Type () = 0;

  // Parser construction API.
  //
  void
  numGoldPieces_parser (::xml_schema::unsigned_int_pskel&);

  void
  numExperiencePoints_parser (::xml_schema::unsigned_int_pskel&);

  void
  parsers (::xml_schema::unsigned_int_pskel& /* numGoldPieces */,
           ::xml_schema::unsigned_int_pskel& /* numExperiencePoints */);

  // Constructor.
  //
  RPG_Item_CreationCost_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::unsigned_int_pskel* numGoldPieces_parser_;
  ::xml_schema::unsigned_int_pskel* numExperiencePoints_parser_;
};

class RPG_Item_Export RPG_Item_BaseProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  baseWeight (unsigned short);

  virtual void
  baseStorePrice (const RPG_Item_StorePrice&);

  virtual void
  costToCreate (const RPG_Item_CreationCost&);

  virtual RPG_Item_BaseProperties
  post_RPG_Item_BaseProperties_Type () = 0;

  // Parser construction API.
  //
  void
  baseWeight_parser (::xml_schema::unsigned_short_pskel&);

  void
  baseStorePrice_parser (::RPG_Item_StorePrice_Type_pskel&);

  void
  costToCreate_parser (::RPG_Item_CreationCost_Type_pskel&);

  void
  parsers (::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Item_CreationCost_Type_pskel& /* costToCreate */);

  // Constructor.
  //
  RPG_Item_BaseProperties_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::unsigned_short_pskel* baseWeight_parser_;
  ::RPG_Item_StorePrice_Type_pskel* baseStorePrice_parser_;
  ::RPG_Item_CreationCost_Type_pskel* costToCreate_parser_;
};

class RPG_Item_Export RPG_Item_MagicalPrerequisites_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  minCasterLevel (unsigned char);

  virtual RPG_Item_MagicalPrerequisites
  post_RPG_Item_MagicalPrerequisites_Type () = 0;

  // Parser construction API.
  //
  void
  minCasterLevel_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::xml_schema::unsigned_byte_pskel& /* minCasterLevel */);

  // Constructor.
  //
  RPG_Item_MagicalPrerequisites_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::unsigned_byte_pskel* minCasterLevel_parser_;
};

class RPG_Item_Export RPG_Item_PropertiesBase_Type_pskel: public virtual ::RPG_Item_BaseProperties_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  aura (const RPG_Magic_School&);

  virtual void
  prerequisites (const RPG_Item_MagicalPrerequisites&);

  virtual RPG_Item_PropertiesBase
  post_RPG_Item_PropertiesBase_Type () = 0;

  // Parser construction API.
  //
  void
  aura_parser (::RPG_Magic_School_Type_pskel&);

  void
  prerequisites_parser (::RPG_Item_MagicalPrerequisites_Type_pskel&);

  void
  parsers (::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Item_CreationCost_Type_pskel& /* costToCreate */,
           ::RPG_Magic_School_Type_pskel& /* aura */,
           ::RPG_Item_MagicalPrerequisites_Type_pskel& /* prerequisites */);

  // Constructor.
  //
  RPG_Item_PropertiesBase_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Magic_School_Type_pskel* aura_parser_;
  ::RPG_Item_MagicalPrerequisites_Type_pskel* prerequisites_parser_;
};

class RPG_Item_Export RPG_Item_CommodityPropertiesBase_Type_pskel: public virtual ::RPG_Item_PropertiesBase_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Item_CommodityType&);

  virtual void
  subType (const RPG_Item_CommodityUnion&);

  virtual RPG_Item_CommodityPropertiesBase
  post_RPG_Item_CommodityPropertiesBase_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Item_CommodityType_Type_pskel&);

  void
  subType_parser (::RPG_Item_CommodityUnion_Type_pskel&);

  void
  parsers (::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Item_CreationCost_Type_pskel& /* costToCreate */,
           ::RPG_Magic_School_Type_pskel& /* aura */,
           ::RPG_Item_MagicalPrerequisites_Type_pskel& /* prerequisites */,
           ::RPG_Item_CommodityType_Type_pskel& /* type */,
           ::RPG_Item_CommodityUnion_Type_pskel& /* subType */);

  // Constructor.
  //
  RPG_Item_CommodityPropertiesBase_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Item_CommodityType_Type_pskel* type_parser_;
  ::RPG_Item_CommodityUnion_Type_pskel* subType_parser_;
};

class RPG_Item_Export RPG_Item_WeaponPropertiesBase_Type_pskel: public virtual ::RPG_Item_PropertiesBase_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Item_WeaponType&);

  virtual void
  category (const RPG_Item_WeaponCategory&);

  virtual void
  weaponClass (const RPG_Item_WeaponClass&);

  virtual void
  baseDamage (const RPG_Item_Damage&);

  virtual void
  criticalHit (const RPG_Item_CriticalHitProperties&);

  virtual void
  rangeIncrement (unsigned char);

  virtual void
  typeOfDamage (const RPG_Common_PhysicalDamageType&);

  virtual void
  isNonLethal (bool);

  virtual void
  isReachWeapon (bool);

  virtual void
  isDoubleWeapon (bool);

  virtual RPG_Item_WeaponPropertiesBase
  post_RPG_Item_WeaponPropertiesBase_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Item_WeaponType_Type_pskel&);

  void
  category_parser (::RPG_Item_WeaponCategory_Type_pskel&);

  void
  weaponClass_parser (::RPG_Item_WeaponClass_Type_pskel&);

  void
  baseDamage_parser (::RPG_Dice_Roll_Type_pskel&);

  void
  criticalHit_parser (::RPG_Item_CriticalHitProperties_Type_pskel&);

  void
  rangeIncrement_parser (::xml_schema::unsigned_byte_pskel&);

  void
  typeOfDamage_parser (::RPG_Common_PhysicalDamageType_Type_pskel&);

  void
  isNonLethal_parser (::xml_schema::boolean_pskel&);

  void
  isReachWeapon_parser (::xml_schema::boolean_pskel&);

  void
  isDoubleWeapon_parser (::xml_schema::boolean_pskel&);

  void
  parsers (::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Item_CreationCost_Type_pskel& /* costToCreate */,
           ::RPG_Magic_School_Type_pskel& /* aura */,
           ::RPG_Item_MagicalPrerequisites_Type_pskel& /* prerequisites */,
           ::RPG_Item_WeaponType_Type_pskel& /* type */,
           ::RPG_Item_WeaponCategory_Type_pskel& /* category */,
           ::RPG_Item_WeaponClass_Type_pskel& /* weaponClass */,
           ::RPG_Dice_Roll_Type_pskel& /* baseDamage */,
           ::RPG_Item_CriticalHitProperties_Type_pskel& /* criticalHit */,
           ::xml_schema::unsigned_byte_pskel& /* rangeIncrement */,
           ::RPG_Common_PhysicalDamageType_Type_pskel& /* typeOfDamage */,
           ::xml_schema::boolean_pskel& /* isNonLethal */,
           ::xml_schema::boolean_pskel& /* isReachWeapon */,
           ::xml_schema::boolean_pskel& /* isDoubleWeapon */);

  // Constructor.
  //
  RPG_Item_WeaponPropertiesBase_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  virtual bool
  _attribute_impl (const ::xml_schema::ro_string&,
                   const ::xml_schema::ro_string&,
                   const ::xml_schema::ro_string&);

  protected:
  ::RPG_Item_WeaponType_Type_pskel* type_parser_;
  ::RPG_Item_WeaponCategory_Type_pskel* category_parser_;
  ::RPG_Item_WeaponClass_Type_pskel* weaponClass_parser_;
  ::RPG_Dice_Roll_Type_pskel* baseDamage_parser_;
  ::RPG_Item_CriticalHitProperties_Type_pskel* criticalHit_parser_;
  ::xml_schema::unsigned_byte_pskel* rangeIncrement_parser_;
  ::RPG_Common_PhysicalDamageType_Type_pskel* typeOfDamage_parser_;
  ::xml_schema::boolean_pskel* isNonLethal_parser_;
  ::xml_schema::boolean_pskel* isReachWeapon_parser_;
  ::xml_schema::boolean_pskel* isDoubleWeapon_parser_;
};

class RPG_Item_Export RPG_Item_WeaponPropertiesXML_Type_pskel: public virtual ::RPG_Item_WeaponPropertiesBase_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  toHitModifier (signed char);

  virtual RPG_Item_WeaponPropertiesXML
  post_RPG_Item_WeaponPropertiesXML_Type () = 0;

  // Parser construction API.
  //
  void
  toHitModifier_parser (::xml_schema::byte_pskel&);

  void
  parsers (::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Item_CreationCost_Type_pskel& /* costToCreate */,
           ::RPG_Magic_School_Type_pskel& /* aura */,
           ::RPG_Item_MagicalPrerequisites_Type_pskel& /* prerequisites */,
           ::RPG_Item_WeaponType_Type_pskel& /* type */,
           ::RPG_Item_WeaponCategory_Type_pskel& /* category */,
           ::RPG_Item_WeaponClass_Type_pskel& /* weaponClass */,
           ::RPG_Dice_Roll_Type_pskel& /* baseDamage */,
           ::RPG_Item_CriticalHitProperties_Type_pskel& /* criticalHit */,
           ::xml_schema::unsigned_byte_pskel& /* rangeIncrement */,
           ::RPG_Common_PhysicalDamageType_Type_pskel& /* typeOfDamage */,
           ::xml_schema::boolean_pskel& /* isNonLethal */,
           ::xml_schema::boolean_pskel& /* isReachWeapon */,
           ::xml_schema::boolean_pskel& /* isDoubleWeapon */,
           ::xml_schema::byte_pskel& /* toHitModifier */);

  // Constructor.
  //
  RPG_Item_WeaponPropertiesXML_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::byte_pskel* toHitModifier_parser_;
};

class RPG_Item_Export RPG_Item_ArmorCategory_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_ArmorCategory
  post_RPG_Item_ArmorCategory_Type () = 0;
};

class RPG_Item_Export RPG_Item_ArmorType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_ArmorType
  post_RPG_Item_ArmorType_Type () = 0;
};

class RPG_Item_Export RPG_Item_ArmorPropertiesBase_Type_pskel: public virtual ::RPG_Item_PropertiesBase_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Item_ArmorType&);

  virtual void
  category (const RPG_Item_ArmorCategory&);

  virtual void
  baseBonus (unsigned char);

  virtual void
  maxDexterityBonus (unsigned char);

  virtual void
  checkPenalty (signed char);

  virtual void
  arcaneSpellFailure (unsigned char);

  virtual void
  baseSpeed (unsigned char);

  virtual RPG_Item_ArmorPropertiesBase
  post_RPG_Item_ArmorPropertiesBase_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Item_ArmorType_Type_pskel&);

  void
  category_parser (::RPG_Item_ArmorCategory_Type_pskel&);

  void
  baseBonus_parser (::xml_schema::unsigned_byte_pskel&);

  void
  maxDexterityBonus_parser (::xml_schema::unsigned_byte_pskel&);

  void
  checkPenalty_parser (::xml_schema::byte_pskel&);

  void
  arcaneSpellFailure_parser (::xml_schema::unsigned_byte_pskel&);

  void
  baseSpeed_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Item_CreationCost_Type_pskel& /* costToCreate */,
           ::RPG_Magic_School_Type_pskel& /* aura */,
           ::RPG_Item_MagicalPrerequisites_Type_pskel& /* prerequisites */,
           ::RPG_Item_ArmorType_Type_pskel& /* type */,
           ::RPG_Item_ArmorCategory_Type_pskel& /* category */,
           ::xml_schema::unsigned_byte_pskel& /* baseBonus */,
           ::xml_schema::unsigned_byte_pskel& /* maxDexterityBonus */,
           ::xml_schema::byte_pskel& /* checkPenalty */,
           ::xml_schema::unsigned_byte_pskel& /* arcaneSpellFailure */,
           ::xml_schema::unsigned_byte_pskel& /* baseSpeed */);

  // Constructor.
  //
  RPG_Item_ArmorPropertiesBase_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Item_ArmorType_Type_pskel* type_parser_;
  ::RPG_Item_ArmorCategory_Type_pskel* category_parser_;
  ::xml_schema::unsigned_byte_pskel* baseBonus_parser_;
  ::xml_schema::unsigned_byte_pskel* maxDexterityBonus_parser_;
  ::xml_schema::byte_pskel* checkPenalty_parser_;
  ::xml_schema::unsigned_byte_pskel* arcaneSpellFailure_parser_;
  ::xml_schema::unsigned_byte_pskel* baseSpeed_parser_;
};

class RPG_Item_Export RPG_Item_ArmorPropertiesXML_Type_pskel: public virtual ::RPG_Item_ArmorPropertiesBase_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  defenseModifier (signed char);

  virtual RPG_Item_ArmorPropertiesXML
  post_RPG_Item_ArmorPropertiesXML_Type () = 0;

  // Parser construction API.
  //
  void
  defenseModifier_parser (::xml_schema::byte_pskel&);

  void
  parsers (::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Item_CreationCost_Type_pskel& /* costToCreate */,
           ::RPG_Magic_School_Type_pskel& /* aura */,
           ::RPG_Item_MagicalPrerequisites_Type_pskel& /* prerequisites */,
           ::RPG_Item_ArmorType_Type_pskel& /* type */,
           ::RPG_Item_ArmorCategory_Type_pskel& /* category */,
           ::xml_schema::unsigned_byte_pskel& /* baseBonus */,
           ::xml_schema::unsigned_byte_pskel& /* maxDexterityBonus */,
           ::xml_schema::byte_pskel& /* checkPenalty */,
           ::xml_schema::unsigned_byte_pskel& /* arcaneSpellFailure */,
           ::xml_schema::unsigned_byte_pskel& /* baseSpeed */,
           ::xml_schema::byte_pskel& /* defenseModifier */);

  // Constructor.
  //
  RPG_Item_ArmorPropertiesXML_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::byte_pskel* defenseModifier_parser_;
};

class RPG_Item_Export RPG_Item_BaseXML_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Item_Type&);

  virtual void
  armor (const RPG_Item_ArmorPropertiesXML&);

  virtual void
  commodity (const RPG_Item_CommodityPropertiesBase&);

  virtual void
  weapon (const RPG_Item_WeaponPropertiesXML&);

  virtual RPG_Item_BaseXML
  post_RPG_Item_BaseXML_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Item_Type_Type_pskel&);

  void
  armor_parser (::RPG_Item_ArmorPropertiesXML_Type_pskel&);

  void
  commodity_parser (::RPG_Item_CommodityPropertiesBase_Type_pskel&);

  void
  weapon_parser (::RPG_Item_WeaponPropertiesXML_Type_pskel&);

  void
  parsers (::RPG_Item_Type_Type_pskel& /* type */,
           ::RPG_Item_ArmorPropertiesXML_Type_pskel& /* armor */,
           ::RPG_Item_CommodityPropertiesBase_Type_pskel& /* commodity */,
           ::RPG_Item_WeaponPropertiesXML_Type_pskel& /* weapon */);

  // Constructor.
  //
  RPG_Item_BaseXML_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Item_Type_Type_pskel* type_parser_;
  ::RPG_Item_ArmorPropertiesXML_Type_pskel* armor_parser_;
  ::RPG_Item_CommodityPropertiesBase_Type_pskel* commodity_parser_;
  ::RPG_Item_WeaponPropertiesXML_Type_pskel* weapon_parser_;
};

class RPG_Item_Export RPG_Item_InventoryXML_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  item (const RPG_Item_BaseXML&);

  virtual RPG_Item_InventoryXML
  post_RPG_Item_InventoryXML_Type () = 0;

  // Parser construction API.
  //
  void
  item_parser (::RPG_Item_BaseXML_Type_pskel&);

  void
  parsers (::RPG_Item_BaseXML_Type_pskel& /* item */);

  // Constructor.
  //
  RPG_Item_InventoryXML_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Item_BaseXML_Type_pskel* item_parser_;
};

class RPG_Item_Export RPG_Item_DictionaryXML_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  armor (const RPG_Item_ArmorPropertiesXML&);

  virtual void
  commodity (const RPG_Item_CommodityPropertiesBase&);

  virtual void
  weapon (const RPG_Item_WeaponPropertiesXML&);

  virtual void
  post_RPG_Item_DictionaryXML_Type ();

  // Parser construction API.
  //
  void
  armor_parser (::RPG_Item_ArmorPropertiesXML_Type_pskel&);

  void
  commodity_parser (::RPG_Item_CommodityPropertiesBase_Type_pskel&);

  void
  weapon_parser (::RPG_Item_WeaponPropertiesXML_Type_pskel&);

  void
  parsers (::RPG_Item_ArmorPropertiesXML_Type_pskel& /* armor */,
           ::RPG_Item_CommodityPropertiesBase_Type_pskel& /* commodity */,
           ::RPG_Item_WeaponPropertiesXML_Type_pskel& /* weapon */);

  // Constructor.
  //
  RPG_Item_DictionaryXML_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Item_ArmorPropertiesXML_Type_pskel* armor_parser_;
  ::RPG_Item_CommodityPropertiesBase_Type_pskel* commodity_parser_;
  ::RPG_Item_WeaponPropertiesXML_Type_pskel* weapon_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX__ITEM_RPG_ITEM_XML_TYPES_H
