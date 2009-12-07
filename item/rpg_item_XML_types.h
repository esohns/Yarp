// Copyright (C) 2005-2008 Code Synthesis Tools CC
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

#ifndef CXX___RPG_ITEM_XML_TYPES_H
#define CXX___RPG_ITEM_XML_TYPES_H

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3020000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

// Forward declarations
//
class RPG_Item_Type_Type_pskel;
class RPG_Item_Money_Type_pskel;
class RPG_Item_WeaponCategory_Type_pskel;
class RPG_Item_WeaponClass_Type_pskel;
class RPG_Item_WeaponType_Type_pskel;
class RPG_Item_StorePrice_Type_pskel;
class RPG_Item_CriticalHitModifier_Type_pskel;
class RPG_Item_PhysicalDamageType_Type_pskel;
class RPG_Item_WeaponPropertiesXML_Type_pskel;
class RPG_Item_MagicWeaponPropertiesXML_Type_pskel;
class RPG_Item_WeaponDictionary_Type_pskel;
class RPG_Item_ArmorCategory_Type_pskel;
class RPG_Item_ArmorType_Type_pskel;
class RPG_Item_ArmorPropertiesXML_Type_pskel;
class RPG_Item_MagicArmorPropertiesXML_Type_pskel;
class RPG_Item_ArmorDictionary_Type_pskel;
class RPG_Item_Dictionary_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include <rpg_XMLSchema.h>

#include <rpg_chance_dicetype.h>
#include <rpg_chance_diceroll.h>
#include "rpg_item_weapontype.h"
#include "rpg_item_weaponclass.h"
#include "rpg_item_weaponcategory.h"
#include "rpg_item_storeprice.h"
#include "rpg_item_physicaldamagetype.h"
#include "rpg_item_criticalhitmodifier.h"
#include "rpg_item_common.h"
#include "rpg_item_armortype.h"
#include "rpg_item_armorcategory.h"

#include <rpg_chance_dice_XML_types.h>

class RPG_Item_Type_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  post_RPG_Item_Type_Type ();
};

class RPG_Item_Money_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  post_RPG_Item_Money_Type ();
};

class RPG_Item_WeaponCategory_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_WeaponCategory
  post_RPG_Item_WeaponCategory_Type () = 0;
};

class RPG_Item_WeaponClass_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_WeaponClass
  post_RPG_Item_WeaponClass_Type () = 0;
};

class RPG_Item_WeaponType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_WeaponType
  post_RPG_Item_WeaponType_Type () = 0;
};

class RPG_Item_StorePrice_Type_pskel: public ::xml_schema::complex_content
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

class RPG_Item_CriticalHitModifier_Type_pskel: public ::xml_schema::complex_content
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

  virtual RPG_Item_CriticalHitModifier
  post_RPG_Item_CriticalHitModifier_Type () = 0;

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
  RPG_Item_CriticalHitModifier_Type_pskel ();

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

class RPG_Item_PhysicalDamageType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_PhysicalDamageType
  post_RPG_Item_PhysicalDamageType_Type () = 0;
};

class RPG_Item_WeaponPropertiesXML_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  weaponType (const RPG_Item_WeaponType&);

  virtual void
  weaponCategory (const RPG_Item_WeaponCategory&);

  virtual void
  weaponClass (const RPG_Item_WeaponClass&);

  virtual void
  baseStorePrice (const RPG_Item_StorePrice&);

  virtual void
  baseDamage (const RPG_Item_Damage&);

  virtual void
  criticalHitModifier (const RPG_Item_CriticalHitModifier&);

  virtual void
  rangeIncrement (unsigned char);

  virtual void
  baseWeight (unsigned short);

  virtual void
  typeOfDamage (const RPG_Item_PhysicalDamageType&);

  virtual RPG_Item_WeaponPropertiesXML
  post_RPG_Item_WeaponPropertiesXML_Type () = 0;

  // Parser construction API.
  //
  void
  weaponType_parser (::RPG_Item_WeaponType_Type_pskel&);

  void
  weaponCategory_parser (::RPG_Item_WeaponCategory_Type_pskel&);

  void
  weaponClass_parser (::RPG_Item_WeaponClass_Type_pskel&);

  void
  baseStorePrice_parser (::RPG_Item_StorePrice_Type_pskel&);

  void
  baseDamage_parser (::RPG_Chance_DiceRoll_Type_pskel&);

  void
  criticalHitModifier_parser (::RPG_Item_CriticalHitModifier_Type_pskel&);

  void
  rangeIncrement_parser (::xml_schema::unsigned_byte_pskel&);

  void
  baseWeight_parser (::xml_schema::unsigned_short_pskel&);

  void
  typeOfDamage_parser (::RPG_Item_PhysicalDamageType_Type_pskel&);

  void
  parsers (::RPG_Item_WeaponType_Type_pskel& /* weaponType */,
           ::RPG_Item_WeaponCategory_Type_pskel& /* weaponCategory */,
           ::RPG_Item_WeaponClass_Type_pskel& /* weaponClass */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Chance_DiceRoll_Type_pskel& /* baseDamage */,
           ::RPG_Item_CriticalHitModifier_Type_pskel& /* criticalHitModifier */,
           ::xml_schema::unsigned_byte_pskel& /* rangeIncrement */,
           ::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_PhysicalDamageType_Type_pskel& /* typeOfDamage */);

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
  ::RPG_Item_WeaponType_Type_pskel* weaponType_parser_;
  ::RPG_Item_WeaponCategory_Type_pskel* weaponCategory_parser_;
  ::RPG_Item_WeaponClass_Type_pskel* weaponClass_parser_;
  ::RPG_Item_StorePrice_Type_pskel* baseStorePrice_parser_;
  ::RPG_Chance_DiceRoll_Type_pskel* baseDamage_parser_;
  ::RPG_Item_CriticalHitModifier_Type_pskel* criticalHitModifier_parser_;
  ::xml_schema::unsigned_byte_pskel* rangeIncrement_parser_;
  ::xml_schema::unsigned_short_pskel* baseWeight_parser_;
  ::RPG_Item_PhysicalDamageType_Type_pskel* typeOfDamage_parser_;
};

class RPG_Item_MagicWeaponPropertiesXML_Type_pskel: public virtual ::RPG_Item_WeaponPropertiesXML_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  toHitModifier (signed char);

  virtual void
  post_RPG_Item_MagicWeaponPropertiesXML_Type ();

  // Parser construction API.
  //
  void
  toHitModifier_parser (::xml_schema::byte_pskel&);

  void
  parsers (::RPG_Item_WeaponType_Type_pskel& /* weaponType */,
           ::RPG_Item_WeaponCategory_Type_pskel& /* weaponCategory */,
           ::RPG_Item_WeaponClass_Type_pskel& /* weaponClass */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::RPG_Chance_DiceRoll_Type_pskel& /* baseDamage */,
           ::RPG_Item_CriticalHitModifier_Type_pskel& /* criticalHitModifier */,
           ::xml_schema::unsigned_byte_pskel& /* rangeIncrement */,
           ::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::RPG_Item_PhysicalDamageType_Type_pskel& /* typeOfDamage */,
           ::xml_schema::byte_pskel& /* toHitModifier */);

  // Constructor.
  //
  RPG_Item_MagicWeaponPropertiesXML_Type_pskel ();

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

class RPG_Item_WeaponDictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  weapon (const RPG_Item_WeaponPropertiesXML&);

  virtual void
  post_RPG_Item_WeaponDictionary_Type ();

  // Parser construction API.
  //
  void
  weapon_parser (::RPG_Item_WeaponPropertiesXML_Type_pskel&);

  void
  parsers (::RPG_Item_WeaponPropertiesXML_Type_pskel& /* weapon */);

  // Constructor.
  //
  RPG_Item_WeaponDictionary_Type_pskel ();

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
  ::RPG_Item_WeaponPropertiesXML_Type_pskel* weapon_parser_;
};

class RPG_Item_ArmorCategory_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_ArmorCategory
  post_RPG_Item_ArmorCategory_Type () = 0;
};

class RPG_Item_ArmorType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_ArmorType
  post_RPG_Item_ArmorType_Type () = 0;
};

class RPG_Item_ArmorPropertiesXML_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  armorType (const RPG_Item_ArmorType&);

  virtual void
  armorCategory (const RPG_Item_ArmorCategory&);

  virtual void
  baseStorePrice (const RPG_Item_StorePrice&);

  virtual void
  baseArmorBonus (unsigned char);

  virtual void
  maxDexterityBonus (unsigned char);

  virtual void
  armorCheckPenalty (signed char);

  virtual void
  arcaneSpellFailure (unsigned char);

  virtual void
  baseSpeed (unsigned short);

  virtual void
  baseWeight (unsigned short);

  virtual RPG_Item_ArmorPropertiesXML
  post_RPG_Item_ArmorPropertiesXML_Type () = 0;

  // Parser construction API.
  //
  void
  armorType_parser (::RPG_Item_ArmorType_Type_pskel&);

  void
  armorCategory_parser (::RPG_Item_ArmorCategory_Type_pskel&);

  void
  baseStorePrice_parser (::RPG_Item_StorePrice_Type_pskel&);

  void
  baseArmorBonus_parser (::xml_schema::unsigned_byte_pskel&);

  void
  maxDexterityBonus_parser (::xml_schema::unsigned_byte_pskel&);

  void
  armorCheckPenalty_parser (::xml_schema::byte_pskel&);

  void
  arcaneSpellFailure_parser (::xml_schema::unsigned_byte_pskel&);

  void
  baseSpeed_parser (::xml_schema::unsigned_short_pskel&);

  void
  baseWeight_parser (::xml_schema::unsigned_short_pskel&);

  void
  parsers (::RPG_Item_ArmorType_Type_pskel& /* armorType */,
           ::RPG_Item_ArmorCategory_Type_pskel& /* armorCategory */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::xml_schema::unsigned_byte_pskel& /* baseArmorBonus */,
           ::xml_schema::unsigned_byte_pskel& /* maxDexterityBonus */,
           ::xml_schema::byte_pskel& /* armorCheckPenalty */,
           ::xml_schema::unsigned_byte_pskel& /* arcaneSpellFailure */,
           ::xml_schema::unsigned_short_pskel& /* baseSpeed */,
           ::xml_schema::unsigned_short_pskel& /* baseWeight */);

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
  ::RPG_Item_ArmorType_Type_pskel* armorType_parser_;
  ::RPG_Item_ArmorCategory_Type_pskel* armorCategory_parser_;
  ::RPG_Item_StorePrice_Type_pskel* baseStorePrice_parser_;
  ::xml_schema::unsigned_byte_pskel* baseArmorBonus_parser_;
  ::xml_schema::unsigned_byte_pskel* maxDexterityBonus_parser_;
  ::xml_schema::byte_pskel* armorCheckPenalty_parser_;
  ::xml_schema::unsigned_byte_pskel* arcaneSpellFailure_parser_;
  ::xml_schema::unsigned_short_pskel* baseSpeed_parser_;
  ::xml_schema::unsigned_short_pskel* baseWeight_parser_;
};

class RPG_Item_MagicArmorPropertiesXML_Type_pskel: public virtual ::RPG_Item_ArmorPropertiesXML_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  defenseModifier (signed char);

  virtual void
  post_RPG_Item_MagicArmorPropertiesXML_Type ();

  // Parser construction API.
  //
  void
  defenseModifier_parser (::xml_schema::byte_pskel&);

  void
  parsers (::RPG_Item_ArmorType_Type_pskel& /* armorType */,
           ::RPG_Item_ArmorCategory_Type_pskel& /* armorCategory */,
           ::RPG_Item_StorePrice_Type_pskel& /* baseStorePrice */,
           ::xml_schema::unsigned_byte_pskel& /* baseArmorBonus */,
           ::xml_schema::unsigned_byte_pskel& /* maxDexterityBonus */,
           ::xml_schema::byte_pskel& /* armorCheckPenalty */,
           ::xml_schema::unsigned_byte_pskel& /* arcaneSpellFailure */,
           ::xml_schema::unsigned_short_pskel& /* baseSpeed */,
           ::xml_schema::unsigned_short_pskel& /* baseWeight */,
           ::xml_schema::byte_pskel& /* defenseModifier */);

  // Constructor.
  //
  RPG_Item_MagicArmorPropertiesXML_Type_pskel ();

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

class RPG_Item_ArmorDictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  armor (const RPG_Item_ArmorPropertiesXML&);

  virtual void
  post_RPG_Item_ArmorDictionary_Type ();

  // Parser construction API.
  //
  void
  armor_parser (::RPG_Item_ArmorPropertiesXML_Type_pskel&);

  void
  parsers (::RPG_Item_ArmorPropertiesXML_Type_pskel& /* armor */);

  // Constructor.
  //
  RPG_Item_ArmorDictionary_Type_pskel ();

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
};

class RPG_Item_Dictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  weaponDictionary ();

  virtual void
  armorDictionary ();

  virtual void
  post_RPG_Item_Dictionary_Type ();

  // Parser construction API.
  //
  void
  weaponDictionary_parser (::RPG_Item_WeaponDictionary_Type_pskel&);

  void
  armorDictionary_parser (::RPG_Item_ArmorDictionary_Type_pskel&);

  void
  parsers (::RPG_Item_WeaponDictionary_Type_pskel& /* weaponDictionary */,
           ::RPG_Item_ArmorDictionary_Type_pskel& /* armorDictionary */);

  // Constructor.
  //
  RPG_Item_Dictionary_Type_pskel ();

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
  ::RPG_Item_WeaponDictionary_Type_pskel* weaponDictionary_parser_;
  ::RPG_Item_ArmorDictionary_Type_pskel* armorDictionary_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_ITEM_XML_TYPES_H