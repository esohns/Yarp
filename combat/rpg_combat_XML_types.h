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

#ifndef CXX___RPG_COMBAT_XML_TYPES_H
#define CXX___RPG_COMBAT_XML_TYPES_H

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
class RPG_Combat_AttackForm_Type_pskel;
class RPG_Combat_AreaOfEffect_Type_pskel;
class RPG_Combat_RangedEffectUnion_Type_pskel;
class RPG_Combat_RangedAttackProperties_Type_pskel;
class RPG_Combat_AttackSituation_Type_pskel;
class RPG_Combat_DefenseSituation_Type_pskel;
class RPG_Combat_SpecialAttack_Type_pskel;
class RPG_Combat_SpecialDamageType_Type_pskel;
class RPG_Combat_DamageTypeUnion_Type_pskel;
class RPG_Combat_DamageDuration_Type_pskel;
class RPG_Combat_DamageBonusType_Type_pskel;
class RPG_Combat_DamageBonus_Type_pskel;
class RPG_Combat_DamageEffectType_Type_pskel;
class RPG_Combat_DamageElement_Type_pskel;
class RPG_Combat_Damage_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include <rpg_XMLSchema.h>

#include <rpg_magic_school.h>
#include <rpg_dice_incl.h>
#include <rpg_item_incl.h>
#include <rpg_common_incl.h>
#include <rpg_character_size.h>
#include "rpg_combat_incl.h"

#include <rpg_dice_XML_types.h>

#include <rpg_common_XML_types.h>

#include <rpg_item_XML_types.h>

#include <rpg_character_XML_types.h>

class RPG_Combat_AttackForm_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Combat_AttackForm
  post_RPG_Combat_AttackForm_Type () = 0;
};

class RPG_Combat_AreaOfEffect_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Combat_AreaOfEffect
  post_RPG_Combat_AreaOfEffect_Type () = 0;
};

class RPG_Combat_RangedEffectUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Combat_RangedEffectUnion
  post_RPG_Combat_RangedEffectUnion_Type () = 0;
};

class RPG_Combat_RangedAttackProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  maxRange (unsigned char);

  virtual void
  increment (unsigned char);

  virtual void
  effect (const RPG_Combat_RangedEffectUnion&);

  virtual RPG_Combat_RangedAttackProperties
  post_RPG_Combat_RangedAttackProperties_Type () = 0;

  // Parser construction API.
  //
  void
  maxRange_parser (::xml_schema::unsigned_byte_pskel&);

  void
  increment_parser (::xml_schema::unsigned_byte_pskel&);

  void
  effect_parser (::RPG_Combat_RangedEffectUnion_Type_pskel&);

  void
  parsers (::xml_schema::unsigned_byte_pskel& /* maxRange */,
           ::xml_schema::unsigned_byte_pskel& /* increment */,
           ::RPG_Combat_RangedEffectUnion_Type_pskel& /* effect */);

  // Constructor.
  //
  RPG_Combat_RangedAttackProperties_Type_pskel ();

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
  ::xml_schema::unsigned_byte_pskel* maxRange_parser_;
  ::xml_schema::unsigned_byte_pskel* increment_parser_;
  ::RPG_Combat_RangedEffectUnion_Type_pskel* effect_parser_;
};

class RPG_Combat_AttackSituation_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Combat_AttackSituation
  post_RPG_Combat_AttackSituation_Type () = 0;
};

class RPG_Combat_DefenseSituation_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Combat_DefenseSituation
  post_RPG_Combat_DefenseSituation_Type () = 0;
};

class RPG_Combat_SpecialAttack_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Combat_SpecialAttack
  post_RPG_Combat_SpecialAttack_Type () = 0;
};

class RPG_Combat_SpecialDamageType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Combat_SpecialDamageType
  post_RPG_Combat_SpecialDamageType_Type () = 0;
};

class RPG_Combat_DamageTypeUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Combat_DamageTypeUnion
  post_RPG_Combat_DamageTypeUnion_Type () = 0;
};

class RPG_Combat_DamageDuration_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  incubationPeriod (const RPG_Dice_Roll&);

  virtual void
  interval (unsigned short);

  virtual void
  totalDuration (unsigned short);

  virtual RPG_Combat_DamageDuration
  post_RPG_Combat_DamageDuration_Type () = 0;

  // Parser construction API.
  //
  void
  incubationPeriod_parser (::RPG_Dice_Roll_Type_pskel&);

  void
  interval_parser (::xml_schema::unsigned_short_pskel&);

  void
  totalDuration_parser (::xml_schema::unsigned_short_pskel&);

  void
  parsers (::RPG_Dice_Roll_Type_pskel& /* incubationPeriod */,
           ::xml_schema::unsigned_short_pskel& /* interval */,
           ::xml_schema::unsigned_short_pskel& /* totalDuration */);

  // Constructor.
  //
  RPG_Combat_DamageDuration_Type_pskel ();

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
  ::RPG_Dice_Roll_Type_pskel* incubationPeriod_parser_;
  ::xml_schema::unsigned_short_pskel* interval_parser_;
  ::xml_schema::unsigned_short_pskel* totalDuration_parser_;
};

class RPG_Combat_DamageBonusType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Combat_DamageBonusType
  post_RPG_Combat_DamageBonusType_Type () = 0;
};

class RPG_Combat_DamageBonus_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Combat_DamageBonusType&);

  virtual void
  modifier (signed char);

  virtual RPG_Combat_DamageBonus
  post_RPG_Combat_DamageBonus_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Combat_DamageBonusType_Type_pskel&);

  void
  modifier_parser (::xml_schema::byte_pskel&);

  void
  parsers (::RPG_Combat_DamageBonusType_Type_pskel& /* type */,
           ::xml_schema::byte_pskel& /* modifier */);

  // Constructor.
  //
  RPG_Combat_DamageBonus_Type_pskel ();

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
  ::RPG_Combat_DamageBonusType_Type_pskel* type_parser_;
  ::xml_schema::byte_pskel* modifier_parser_;
};

class RPG_Combat_DamageEffectType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Combat_DamageEffectType
  post_RPG_Combat_DamageEffectType_Type () = 0;
};

class RPG_Combat_DamageElement_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Combat_DamageTypeUnion&);

  virtual void
  amount (const RPG_Dice_Roll&);

  virtual void
  duration (const RPG_Combat_DamageDuration&);

  virtual void
  other (const RPG_Combat_DamageBonus&);

  virtual void
  attribute (const RPG_Common_Attribute&);

  virtual void
  save (const RPG_Common_SavingThrowModifier&);

  virtual void
  counterMeasure (bool);

  virtual void
  effect (const RPG_Combat_DamageEffectType&);

  virtual RPG_Combat_DamageElement
  post_RPG_Combat_DamageElement_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Combat_DamageTypeUnion_Type_pskel&);

  void
  amount_parser (::RPG_Dice_Roll_Type_pskel&);

  void
  duration_parser (::RPG_Combat_DamageDuration_Type_pskel&);

  void
  other_parser (::RPG_Combat_DamageBonus_Type_pskel&);

  void
  attribute_parser (::RPG_Common_Attribute_Type_pskel&);

  void
  save_parser (::RPG_Common_SavingThrowModifier_Type_pskel&);

  void
  counterMeasure_parser (::xml_schema::boolean_pskel&);

  void
  effect_parser (::RPG_Combat_DamageEffectType_Type_pskel&);

  void
  parsers (::RPG_Combat_DamageTypeUnion_Type_pskel& /* type */,
           ::RPG_Dice_Roll_Type_pskel& /* amount */,
           ::RPG_Combat_DamageDuration_Type_pskel& /* duration */,
           ::RPG_Combat_DamageBonus_Type_pskel& /* other */,
           ::RPG_Common_Attribute_Type_pskel& /* attribute */,
           ::RPG_Common_SavingThrowModifier_Type_pskel& /* save */,
           ::xml_schema::boolean_pskel& /* counterMeasure */,
           ::RPG_Combat_DamageEffectType_Type_pskel& /* effect */);

  // Constructor.
  //
  RPG_Combat_DamageElement_Type_pskel ();

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
  ::RPG_Combat_DamageTypeUnion_Type_pskel* type_parser_;
  ::RPG_Dice_Roll_Type_pskel* amount_parser_;
  ::RPG_Combat_DamageDuration_Type_pskel* duration_parser_;
  ::RPG_Combat_DamageBonus_Type_pskel* other_parser_;
  ::RPG_Common_Attribute_Type_pskel* attribute_parser_;
  ::RPG_Common_SavingThrowModifier_Type_pskel* save_parser_;
  ::xml_schema::boolean_pskel* counterMeasure_parser_;
  ::RPG_Combat_DamageEffectType_Type_pskel* effect_parser_;
};

class RPG_Combat_Damage_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  element (const RPG_Combat_DamageElement&);

  virtual RPG_Combat_Damage
  post_RPG_Combat_Damage_Type () = 0;

  // Parser construction API.
  //
  void
  element_parser (::RPG_Combat_DamageElement_Type_pskel&);

  void
  parsers (::RPG_Combat_DamageElement_Type_pskel& /* element */);

  // Constructor.
  //
  RPG_Combat_Damage_Type_pskel ();

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
  ::RPG_Combat_DamageElement_Type_pskel* element_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_COMBAT_XML_TYPES_H
