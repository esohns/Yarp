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

#ifndef CXX___RPG_ITEM_DICTIONARY_TYPES_H
#define CXX___RPG_ITEM_DICTIONARY_TYPES_H

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
class RPG_Item_Dictionary_Type_pskel;
class RPG_Item_Weapon_Dictionary_Type_pskel;
class RPG_Item_Armor_Dictionary_Type_pskel;
class RPG_Item_Weapon_Category_Type_pskel;
class RPG_Item_Weapon_Class_Type_pskel;
class RPG_Item_Weapon_Type_pskel;
class RPG_Item_Store_Price_Type_pskel;
class RPG_Chance_Dice_Type_pskel;
class RPG_Chance_Roll_Type_pskel;
class RPG_Item_CriticalHit_Modifier_Type_pskel;
class RPG_Item_Weapon_Damage_Type_pskel;
class RPG_Item_Weapon_Properties_Type_pskel;
class RPG_Item_Armor_Category_Type_pskel;
class RPG_Item_Armor_Type_pskel;
class RPG_Item_Armor_Properties_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_item_schema_dictionary_types.h"

#include "rpg_item_common.h"
#include "rpg_chance_dice_common.h"

class RPG_Item_Dictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  RPG_Item_Weapon_Dictionary (const RPG_ITEM_WEAPON_DICTIONARY_T&);

  virtual void
  RPG_Item_Armor_Dictionary (const RPG_ITEM_ARMOR_DICTIONARY_T&);

  virtual void
  post_RPG_Item_Dictionary_Type ();

  // Parser construction API.
  //
  void
  RPG_Item_Weapon_Dictionary_parser (::RPG_Item_Weapon_Dictionary_Type_pskel&);

  void
  RPG_Item_Armor_Dictionary_parser (::RPG_Item_Armor_Dictionary_Type_pskel&);

  void
  parsers (::RPG_Item_Weapon_Dictionary_Type_pskel& /* RPG_Item_Weapon_Dictionary */,
           ::RPG_Item_Armor_Dictionary_Type_pskel& /* RPG_Item_Armor_Dictionary */);

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
  ::RPG_Item_Weapon_Dictionary_Type_pskel* RPG_Item_Weapon_Dictionary_parser_;
  ::RPG_Item_Armor_Dictionary_Type_pskel* RPG_Item_Armor_Dictionary_parser_;

  protected:
  struct v_state_descr_
  {
    void (::RPG_Item_Dictionary_Type_pskel::*func) (
      unsigned long&,
      unsigned long&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string*,
      bool);
    unsigned long state;
    unsigned long count;
  };

  struct v_state_
  {
    v_state_descr_ data[2UL];
    unsigned long size;
  };

  v_state_ v_state_first_;
  ::xsd::cxx::parser::pod_stack v_state_stack_;

  virtual void
  _pre_e_validate ();

  virtual void
  _post_e_validate ();

  void
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start);
};

class RPG_Item_Weapon_Dictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  weapon (const RPG_Item_Weapon_Properties&);

  virtual RPG_ITEM_WEAPON_DICTIONARY_T
  post_RPG_Item_Weapon_Dictionary_Type () = 0;

  // Parser construction API.
  //
  void
  weapon_parser (::RPG_Item_Weapon_Properties_Type_pskel&);

  void
  parsers (::RPG_Item_Weapon_Properties_Type_pskel& /* weapon */);

  // Constructor.
  //
  RPG_Item_Weapon_Dictionary_Type_pskel ();

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
  ::RPG_Item_Weapon_Properties_Type_pskel* weapon_parser_;

  protected:
  struct v_state_descr_
  {
    void (::RPG_Item_Weapon_Dictionary_Type_pskel::*func) (
      unsigned long&,
      unsigned long&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string*,
      bool);
    unsigned long state;
    unsigned long count;
  };

  struct v_state_
  {
    v_state_descr_ data[2UL];
    unsigned long size;
  };

  v_state_ v_state_first_;
  ::xsd::cxx::parser::pod_stack v_state_stack_;

  virtual void
  _pre_e_validate ();

  virtual void
  _post_e_validate ();

  void
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start);
};

class RPG_Item_Armor_Dictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  armor (const RPG_Item_Armor_Properties&);

  virtual RPG_ITEM_ARMOR_DICTIONARY_T
  post_RPG_Item_Armor_Dictionary_Type () = 0;

  // Parser construction API.
  //
  void
  armor_parser (::RPG_Item_Armor_Properties_Type_pskel&);

  void
  parsers (::RPG_Item_Armor_Properties_Type_pskel& /* armor */);

  // Constructor.
  //
  RPG_Item_Armor_Dictionary_Type_pskel ();

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
  ::RPG_Item_Armor_Properties_Type_pskel* armor_parser_;

  protected:
  struct v_state_descr_
  {
    void (::RPG_Item_Armor_Dictionary_Type_pskel::*func) (
      unsigned long&,
      unsigned long&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string*,
      bool);
    unsigned long state;
    unsigned long count;
  };

  struct v_state_
  {
    v_state_descr_ data[2UL];
    unsigned long size;
  };

  v_state_ v_state_first_;
  ::xsd::cxx::parser::pod_stack v_state_stack_;

  virtual void
  _pre_e_validate ();

  virtual void
  _post_e_validate ();

  void
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start);
};

class RPG_Item_Weapon_Category_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_Weapon_Category
  post_RPG_Item_Weapon_Category_Type () = 0;
};

class RPG_Item_Weapon_Class_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_Weapon_Class
  post_RPG_Item_Weapon_Class_Type () = 0;
};

class RPG_Item_Weapon_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_Weapon_Type
  post_RPG_Item_Weapon_Type () = 0;
};

class RPG_Item_Store_Price_Type_pskel: public ::xml_schema::complex_content
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

  virtual RPG_Item_Store_Price
  post_RPG_Item_Store_Price_Type () = 0;

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
  RPG_Item_Store_Price_Type_pskel ();

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

  protected:
  struct v_state_descr_
  {
    void (::RPG_Item_Store_Price_Type_pskel::*func) (
      unsigned long&,
      unsigned long&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string*,
      bool);
    unsigned long state;
    unsigned long count;
  };

  struct v_state_
  {
    v_state_descr_ data[2UL];
    unsigned long size;
  };

  v_state_ v_state_first_;
  ::xsd::cxx::parser::pod_stack v_state_stack_;

  virtual void
  _pre_e_validate ();

  virtual void
  _post_e_validate ();

  void
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start);
};

class RPG_Chance_Dice_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Chance_Dice_Type
  post_RPG_Chance_Dice_Type () = 0;
};

class RPG_Chance_Roll_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  numDice (unsigned int);

  virtual void
  typeDice (const RPG_Chance_Dice_Type&);

  virtual void
  modifier (long long);

  virtual RPG_Item_Damage
  post_RPG_Chance_Roll_Type () = 0;

  // Parser construction API.
  //
  void
  numDice_parser (::xml_schema::unsigned_int_pskel&);

  void
  typeDice_parser (::RPG_Chance_Dice_Type_pskel&);

  void
  modifier_parser (::xml_schema::integer_pskel&);

  void
  parsers (::xml_schema::unsigned_int_pskel& /* numDice */,
           ::RPG_Chance_Dice_Type_pskel& /* typeDice */,
           ::xml_schema::integer_pskel& /* modifier */);

  // Constructor.
  //
  RPG_Chance_Roll_Type_pskel ();

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
  ::xml_schema::unsigned_int_pskel* numDice_parser_;
  ::RPG_Chance_Dice_Type_pskel* typeDice_parser_;
  ::xml_schema::integer_pskel* modifier_parser_;

  protected:
  struct v_state_descr_
  {
    void (::RPG_Chance_Roll_Type_pskel::*func) (
      unsigned long&,
      unsigned long&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string*,
      bool);
    unsigned long state;
    unsigned long count;
  };

  struct v_state_
  {
    v_state_descr_ data[2UL];
    unsigned long size;
  };

  v_state_ v_state_first_;
  ::xsd::cxx::parser::pod_stack v_state_stack_;

  virtual void
  _pre_e_validate ();

  virtual void
  _post_e_validate ();

  void
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start);
};

class RPG_Item_CriticalHit_Modifier_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  minToHitRoll (unsigned int);

  virtual void
  damageModifier (unsigned int);

  virtual RPG_Item_CriticalHit_Modifier
  post_RPG_Item_CriticalHit_Modifier_Type () = 0;

  // Parser construction API.
  //
  void
  minToHitRoll_parser (::xml_schema::unsigned_int_pskel&);

  void
  damageModifier_parser (::xml_schema::unsigned_int_pskel&);

  void
  parsers (::xml_schema::unsigned_int_pskel& /* minToHitRoll */,
           ::xml_schema::unsigned_int_pskel& /* damageModifier */);

  // Constructor.
  //
  RPG_Item_CriticalHit_Modifier_Type_pskel ();

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
  ::xml_schema::unsigned_int_pskel* minToHitRoll_parser_;
  ::xml_schema::unsigned_int_pskel* damageModifier_parser_;

  protected:
  struct v_state_descr_
  {
    void (::RPG_Item_CriticalHit_Modifier_Type_pskel::*func) (
      unsigned long&,
      unsigned long&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string*,
      bool);
    unsigned long state;
    unsigned long count;
  };

  struct v_state_
  {
    v_state_descr_ data[2UL];
    unsigned long size;
  };

  v_state_ v_state_first_;
  ::xsd::cxx::parser::pod_stack v_state_stack_;

  virtual void
  _pre_e_validate ();

  virtual void
  _post_e_validate ();

  void
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start);
};

class RPG_Item_Weapon_Damage_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_Weapon_Damage_Type
  post_RPG_Item_Weapon_Damage_Type () = 0;
};

class RPG_Item_Weapon_Properties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  weaponType (const RPG_Item_Weapon_Type&);

  virtual void
  weaponCategory (const RPG_Item_Weapon_Category&);

  virtual void
  weaponClass (const RPG_Item_Weapon_Class&);

  virtual void
  baseStorePrice (const RPG_Item_Store_Price&);

  virtual void
  baseDamage (const RPG_Item_Damage&);

  virtual void
  criticalHitModifier (const RPG_Item_CriticalHit_Modifier&);

  virtual void
  rangeIncrement (unsigned int);

  virtual void
  baseWeight (unsigned int);

  virtual void
  typeOfDamage (const RPG_Item_Weapon_Damage_Type&);

  virtual RPG_Item_Weapon_Properties
  post_RPG_Item_Weapon_Properties_Type () = 0;

  // Parser construction API.
  //
  void
  weaponType_parser (::RPG_Item_Weapon_Type_pskel&);

  void
  weaponCategory_parser (::RPG_Item_Weapon_Category_Type_pskel&);

  void
  weaponClass_parser (::RPG_Item_Weapon_Class_Type_pskel&);

  void
  baseStorePrice_parser (::RPG_Item_Store_Price_Type_pskel&);

  void
  baseDamage_parser (::RPG_Chance_Roll_Type_pskel&);

  void
  criticalHitModifier_parser (::RPG_Item_CriticalHit_Modifier_Type_pskel&);

  void
  rangeIncrement_parser (::xml_schema::unsigned_int_pskel&);

  void
  baseWeight_parser (::xml_schema::unsigned_int_pskel&);

  void
  typeOfDamage_parser (::RPG_Item_Weapon_Damage_Type_pskel&);

  void
  parsers (::RPG_Item_Weapon_Type_pskel& /* weaponType */,
           ::RPG_Item_Weapon_Category_Type_pskel& /* weaponCategory */,
           ::RPG_Item_Weapon_Class_Type_pskel& /* weaponClass */,
           ::RPG_Item_Store_Price_Type_pskel& /* baseStorePrice */,
           ::RPG_Chance_Roll_Type_pskel& /* baseDamage */,
           ::RPG_Item_CriticalHit_Modifier_Type_pskel& /* criticalHitModifier */,
           ::xml_schema::unsigned_int_pskel& /* rangeIncrement */,
           ::xml_schema::unsigned_int_pskel& /* baseWeight */,
           ::RPG_Item_Weapon_Damage_Type_pskel& /* typeOfDamage */);

  // Constructor.
  //
  RPG_Item_Weapon_Properties_Type_pskel ();

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
  ::RPG_Item_Weapon_Type_pskel* weaponType_parser_;
  ::RPG_Item_Weapon_Category_Type_pskel* weaponCategory_parser_;
  ::RPG_Item_Weapon_Class_Type_pskel* weaponClass_parser_;
  ::RPG_Item_Store_Price_Type_pskel* baseStorePrice_parser_;
  ::RPG_Chance_Roll_Type_pskel* baseDamage_parser_;
  ::RPG_Item_CriticalHit_Modifier_Type_pskel* criticalHitModifier_parser_;
  ::xml_schema::unsigned_int_pskel* rangeIncrement_parser_;
  ::xml_schema::unsigned_int_pskel* baseWeight_parser_;
  ::RPG_Item_Weapon_Damage_Type_pskel* typeOfDamage_parser_;

  protected:
  struct v_state_descr_
  {
    void (::RPG_Item_Weapon_Properties_Type_pskel::*func) (
      unsigned long&,
      unsigned long&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string*,
      bool);
    unsigned long state;
    unsigned long count;
  };

  struct v_state_
  {
    v_state_descr_ data[2UL];
    unsigned long size;
  };

  v_state_ v_state_first_;
  ::xsd::cxx::parser::pod_stack v_state_stack_;

  virtual void
  _pre_e_validate ();

  virtual void
  _post_e_validate ();

  void
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start);
};

class RPG_Item_Armor_Category_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_Armor_Category
  post_RPG_Item_Armor_Category_Type () = 0;
};

class RPG_Item_Armor_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Item_Armor_Type
  post_RPG_Item_Armor_Type () = 0;
};

class RPG_Item_Armor_Properties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  armorType (const RPG_Item_Armor_Type&);

  virtual void
  armorCategory (const RPG_Item_Armor_Category&);

  virtual void
  baseStorePrice (const RPG_Item_Store_Price&);

  virtual void
  baseArmorBonus (unsigned int);

  virtual void
  maxDexterityBonus (unsigned int);

  virtual void
  armorCheckPenalty (long long);

  virtual void
  arcaneSpellFailure (unsigned int);

  virtual void
  baseSpeed (unsigned int);

  virtual void
  baseWeight (unsigned int);

  virtual RPG_Item_Armor_Properties
  post_RPG_Item_Armor_Properties_Type () = 0;

  // Parser construction API.
  //
  void
  armorType_parser (::RPG_Item_Armor_Type_pskel&);

  void
  armorCategory_parser (::RPG_Item_Armor_Category_Type_pskel&);

  void
  baseStorePrice_parser (::RPG_Item_Store_Price_Type_pskel&);

  void
  baseArmorBonus_parser (::xml_schema::unsigned_int_pskel&);

  void
  maxDexterityBonus_parser (::xml_schema::unsigned_int_pskel&);

  void
  armorCheckPenalty_parser (::xml_schema::integer_pskel&);

  void
  arcaneSpellFailure_parser (::xml_schema::unsigned_int_pskel&);

  void
  baseSpeed_parser (::xml_schema::unsigned_int_pskel&);

  void
  baseWeight_parser (::xml_schema::unsigned_int_pskel&);

  void
  parsers (::RPG_Item_Armor_Type_pskel& /* armorType */,
           ::RPG_Item_Armor_Category_Type_pskel& /* armorCategory */,
           ::RPG_Item_Store_Price_Type_pskel& /* baseStorePrice */,
           ::xml_schema::unsigned_int_pskel& /* baseArmorBonus */,
           ::xml_schema::unsigned_int_pskel& /* maxDexterityBonus */,
           ::xml_schema::integer_pskel& /* armorCheckPenalty */,
           ::xml_schema::unsigned_int_pskel& /* arcaneSpellFailure */,
           ::xml_schema::unsigned_int_pskel& /* baseSpeed */,
           ::xml_schema::unsigned_int_pskel& /* baseWeight */);

  // Constructor.
  //
  RPG_Item_Armor_Properties_Type_pskel ();

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
  ::RPG_Item_Armor_Type_pskel* armorType_parser_;
  ::RPG_Item_Armor_Category_Type_pskel* armorCategory_parser_;
  ::RPG_Item_Store_Price_Type_pskel* baseStorePrice_parser_;
  ::xml_schema::unsigned_int_pskel* baseArmorBonus_parser_;
  ::xml_schema::unsigned_int_pskel* maxDexterityBonus_parser_;
  ::xml_schema::integer_pskel* armorCheckPenalty_parser_;
  ::xml_schema::unsigned_int_pskel* arcaneSpellFailure_parser_;
  ::xml_schema::unsigned_int_pskel* baseSpeed_parser_;
  ::xml_schema::unsigned_int_pskel* baseWeight_parser_;

  protected:
  struct v_state_descr_
  {
    void (::RPG_Item_Armor_Properties_Type_pskel::*func) (
      unsigned long&,
      unsigned long&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string&,
      const ::xml_schema::ro_string*,
      bool);
    unsigned long state;
    unsigned long count;
  };

  struct v_state_
  {
    v_state_descr_ data[2UL];
    unsigned long size;
  };

  v_state_ v_state_first_;
  ::xsd::cxx::parser::pod_stack v_state_stack_;

  virtual void
  _pre_e_validate ();

  virtual void
  _post_e_validate ();

  void
  sequence_0 (unsigned long& state,
              unsigned long& count,
              const ::xml_schema::ro_string& ns,
              const ::xml_schema::ro_string& n,
              const ::xml_schema::ro_string* t,
              bool start);
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_ITEM_DICTIONARY_TYPES_H