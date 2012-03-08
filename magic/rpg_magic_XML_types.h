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

#ifndef CXX___RPG_MAGIC_XML_TYPES_H
#define CXX___RPG_MAGIC_XML_TYPES_H

// Begin prologue.
//
#include "rpg_magic_exports.h"
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

// Forward declarations
//
class RPG_Magic_School_Type_pskel;
class RPG_Magic_SubSchool_Type_pskel;
class RPG_Magic_Descriptor_Type_pskel;
class RPG_Magic_Domain_Type_pskel;
class RPG_Magic_SpellType_Type_pskel;
class RPG_Magic_AbilityClass_Type_pskel;
class RPG_Magic_AbilityType_Type_pskel;
class RPG_Magic_Spell_Type_Type_pskel;
class RPG_Magic_CasterClassUnion_Type_pskel;
class RPG_Magic_Spell_Level_Type_pskel;
class RPG_Magic_Spell_CastingTime_Type_pskel;
class RPG_Magic_Spell_RangeEffect_Type_pskel;
class RPG_Magic_Spell_RangeProperties_Type_pskel;
class RPG_Magic_Spell_Target_Type_pskel;
class RPG_Magic_Spell_AreaOfEffect_Type_pskel;
class RPG_Magic_Spell_TargetProperties_Type_pskel;
class RPG_Magic_Spell_Duration_Type_pskel;
class RPG_Magic_Spell_DurationProperties_Type_pskel;
class RPG_Magic_Spell_Precondition_Type_pskel;
class RPG_Magic_Spell_PreconditionProperties_Type_pskel;
class RPG_Magic_Spell_Effect_Type_pskel;
class RPG_Magic_Spell_DamageTypeUnion_Type_pskel;
class RPG_Magic_CheckTypeUnion_Type_pskel;
class RPG_Magic_Check_Type_pskel;
class RPG_Magic_CounterMeasure_Type_pskel;
class RPG_Magic_Spell_EffectProperties_Type_pskel;
class RPG_Magic_Spell_PropertiesXML_Type_pskel;
class RPG_Magic_SpellLikeProperties_Type_pskel;
class RPG_Magic_Dictionary_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_XMLSchema_XML_types.h"

#include <rpg_dice_incl.h>
#include <rpg_common_incl.h>
#include <rpg_common_environment_incl.h>
#include <rpg_character_incl.h>
#include "rpg_magic_incl.h"

#include "../chance/dice/rpg_dice_XML_types.h"

#include "../common/rpg_common_XML_types.h"

#include "../common/rpg_common_environment_XML_types.h"

#include "../character/rpg_character_XML_types.h"

class RPG_Magic_Export RPG_Magic_School_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_School
  post_RPG_Magic_School_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_SubSchool_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_SubSchool
  post_RPG_Magic_SubSchool_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Descriptor_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_Descriptor
  post_RPG_Magic_Descriptor_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Domain_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_Domain
  post_RPG_Magic_Domain_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_SpellType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_SpellType
  post_RPG_Magic_SpellType_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_AbilityClass_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_AbilityClass
  post_RPG_Magic_AbilityClass_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_AbilityType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_AbilityType
  post_RPG_Magic_AbilityType_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Spell_Type_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Magic_SpellType&);

  virtual void
  school (const RPG_Magic_School&);

  virtual void
  subSchool (const RPG_Magic_SubSchool&);

  virtual void
  descriptor (const RPG_Magic_Descriptor&);

  virtual void
  counterSpell (const RPG_Magic_SpellType&);

  virtual RPG_Magic_Spell_Type
  post_RPG_Magic_Spell_Type_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Magic_SpellType_Type_pskel&);

  void
  school_parser (::RPG_Magic_School_Type_pskel&);

  void
  subSchool_parser (::RPG_Magic_SubSchool_Type_pskel&);

  void
  descriptor_parser (::RPG_Magic_Descriptor_Type_pskel&);

  void
  counterSpell_parser (::RPG_Magic_SpellType_Type_pskel&);

  void
  parsers (::RPG_Magic_SpellType_Type_pskel& /* type */,
           ::RPG_Magic_School_Type_pskel& /* school */,
           ::RPG_Magic_SubSchool_Type_pskel& /* subSchool */,
           ::RPG_Magic_Descriptor_Type_pskel& /* descriptor */,
           ::RPG_Magic_SpellType_Type_pskel& /* counterSpell */);

  // Constructor.
  //
  RPG_Magic_Spell_Type_Type_pskel ();

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
  ::RPG_Magic_SpellType_Type_pskel* type_parser_;
  ::RPG_Magic_School_Type_pskel* school_parser_;
  ::RPG_Magic_SubSchool_Type_pskel* subSchool_parser_;
  ::RPG_Magic_Descriptor_Type_pskel* descriptor_parser_;
  ::RPG_Magic_SpellType_Type_pskel* counterSpell_parser_;
};

class RPG_Magic_Export RPG_Magic_CasterClassUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Magic_CasterClassUnion
  post_RPG_Magic_CasterClassUnion_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Spell_Level_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  casterClass (const RPG_Magic_CasterClassUnion&);

  virtual void
  level (unsigned char);

  virtual RPG_Magic_Spell_Level
  post_RPG_Magic_Spell_Level_Type () = 0;

  // Parser construction API.
  //
  void
  casterClass_parser (::RPG_Magic_CasterClassUnion_Type_pskel&);

  void
  level_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::RPG_Magic_CasterClassUnion_Type_pskel& /* casterClass */,
           ::xml_schema::unsigned_byte_pskel& /* level */);

  // Constructor.
  //
  RPG_Magic_Spell_Level_Type_pskel ();

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
  ::RPG_Magic_CasterClassUnion_Type_pskel* casterClass_parser_;
  ::xml_schema::unsigned_byte_pskel* level_parser_;
};

class RPG_Magic_Export RPG_Magic_Spell_CastingTime_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  rounds (unsigned int);

  virtual void
  action (const RPG_Common_ActionType&);

  virtual RPG_Magic_Spell_CastingTime
  post_RPG_Magic_Spell_CastingTime_Type () = 0;

  // Parser construction API.
  //
  void
  rounds_parser (::xml_schema::unsigned_int_pskel&);

  void
  action_parser (::RPG_Common_ActionType_Type_pskel&);

  void
  parsers (::xml_schema::unsigned_int_pskel& /* rounds */,
           ::RPG_Common_ActionType_Type_pskel& /* action */);

  // Constructor.
  //
  RPG_Magic_Spell_CastingTime_Type_pskel ();

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
  ::xml_schema::unsigned_int_pskel* rounds_parser_;
  ::RPG_Common_ActionType_Type_pskel* action_parser_;
};

class RPG_Magic_Export RPG_Magic_Spell_RangeEffect_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_Spell_RangeEffect
  post_RPG_Magic_Spell_RangeEffect_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Spell_RangeProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  maximum (unsigned int);

  virtual void
  increment (unsigned int);

  virtual void
  effect (const RPG_Magic_Spell_RangeEffect&);

  virtual RPG_Magic_Spell_RangeProperties
  post_RPG_Magic_Spell_RangeProperties_Type () = 0;

  // Parser construction API.
  //
  void
  maximum_parser (::xml_schema::unsigned_int_pskel&);

  void
  increment_parser (::xml_schema::unsigned_int_pskel&);

  void
  effect_parser (::RPG_Magic_Spell_RangeEffect_Type_pskel&);

  void
  parsers (::xml_schema::unsigned_int_pskel& /* maximum */,
           ::xml_schema::unsigned_int_pskel& /* increment */,
           ::RPG_Magic_Spell_RangeEffect_Type_pskel& /* effect */);

  // Constructor.
  //
  RPG_Magic_Spell_RangeProperties_Type_pskel ();

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
  ::xml_schema::unsigned_int_pskel* maximum_parser_;
  ::xml_schema::unsigned_int_pskel* increment_parser_;
  ::RPG_Magic_Spell_RangeEffect_Type_pskel* effect_parser_;
};

class RPG_Magic_Export RPG_Magic_Spell_Target_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_Spell_Target
  post_RPG_Magic_Spell_Target_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Spell_AreaOfEffect_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_Spell_AreaOfEffect
  post_RPG_Magic_Spell_AreaOfEffect_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Spell_TargetProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  base (const RPG_Common_Amount&);

  virtual void
  levelIncrement (unsigned char);

  virtual void
  levelIncrementMax (unsigned char);

  virtual void
  effect (const RPG_Magic_Spell_AreaOfEffect&);

  virtual void
  shape (const RPG_Common_AreaOfEffect&);

  virtual void
  radius (unsigned int);

  virtual void
  height (unsigned int);

  virtual void
  target (const RPG_Magic_Spell_Target&);

  virtual void
  shapeable (bool);

  virtual void
  rangeIsInHD (bool);

  virtual void
  incrementIsReciprocal (bool);

  virtual RPG_Magic_Spell_TargetProperties
  post_RPG_Magic_Spell_TargetProperties_Type () = 0;

  // Parser construction API.
  //
  void
  base_parser (::RPG_Common_Amount_Type_pskel&);

  void
  levelIncrement_parser (::xml_schema::unsigned_byte_pskel&);

  void
  levelIncrementMax_parser (::xml_schema::unsigned_byte_pskel&);

  void
  effect_parser (::RPG_Magic_Spell_AreaOfEffect_Type_pskel&);

  void
  shape_parser (::RPG_Common_AreaOfEffect_Type_pskel&);

  void
  radius_parser (::xml_schema::unsigned_int_pskel&);

  void
  height_parser (::xml_schema::unsigned_int_pskel&);

  void
  target_parser (::RPG_Magic_Spell_Target_Type_pskel&);

  void
  shapeable_parser (::xml_schema::boolean_pskel&);

  void
  rangeIsInHD_parser (::xml_schema::boolean_pskel&);

  void
  incrementIsReciprocal_parser (::xml_schema::boolean_pskel&);

  void
  parsers (::RPG_Common_Amount_Type_pskel& /* base */,
           ::xml_schema::unsigned_byte_pskel& /* levelIncrement */,
           ::xml_schema::unsigned_byte_pskel& /* levelIncrementMax */,
           ::RPG_Magic_Spell_AreaOfEffect_Type_pskel& /* effect */,
           ::RPG_Common_AreaOfEffect_Type_pskel& /* shape */,
           ::xml_schema::unsigned_int_pskel& /* radius */,
           ::xml_schema::unsigned_int_pskel& /* height */,
           ::RPG_Magic_Spell_Target_Type_pskel& /* target */,
           ::xml_schema::boolean_pskel& /* shapeable */,
           ::xml_schema::boolean_pskel& /* rangeIsInHD */,
           ::xml_schema::boolean_pskel& /* incrementIsReciprocal */);

  // Constructor.
  //
  RPG_Magic_Spell_TargetProperties_Type_pskel ();

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
  ::RPG_Common_Amount_Type_pskel* base_parser_;
  ::xml_schema::unsigned_byte_pskel* levelIncrement_parser_;
  ::xml_schema::unsigned_byte_pskel* levelIncrementMax_parser_;
  ::RPG_Magic_Spell_AreaOfEffect_Type_pskel* effect_parser_;
  ::RPG_Common_AreaOfEffect_Type_pskel* shape_parser_;
  ::xml_schema::unsigned_int_pskel* radius_parser_;
  ::xml_schema::unsigned_int_pskel* height_parser_;
  ::RPG_Magic_Spell_Target_Type_pskel* target_parser_;
  ::xml_schema::boolean_pskel* shapeable_parser_;
  ::xml_schema::boolean_pskel* rangeIsInHD_parser_;
  ::xml_schema::boolean_pskel* incrementIsReciprocal_parser_;
};

class RPG_Magic_Export RPG_Magic_Spell_Duration_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_Spell_Duration
  post_RPG_Magic_Spell_Duration_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Spell_DurationProperties_Type_pskel: public virtual ::RPG_Common_EffectDuration_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  duration (const RPG_Magic_Spell_Duration&);

  virtual void
  dismissible (bool);

  virtual RPG_Magic_Spell_DurationProperties
  post_RPG_Magic_Spell_DurationProperties_Type () = 0;

  // Parser construction API.
  //
  void
  duration_parser (::RPG_Magic_Spell_Duration_Type_pskel&);

  void
  dismissible_parser (::xml_schema::boolean_pskel&);

  void
  parsers (::RPG_Common_Amount_Type_pskel& /* base */,
           ::xml_schema::byte_pskel& /* levelIncrement */,
           ::xml_schema::unsigned_byte_pskel& /* levelIncrementMax */,
           ::xml_schema::unsigned_byte_pskel& /* reciprocalIncrement */,
           ::xml_schema::boolean_pskel& /* isMaxDelay */,
           ::xml_schema::boolean_pskel& /* incrementIsInHD */,
           ::RPG_Magic_Spell_Duration_Type_pskel& /* duration */,
           ::xml_schema::boolean_pskel& /* dismissible */);

  // Constructor.
  //
  RPG_Magic_Spell_DurationProperties_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _attribute_impl (const ::xml_schema::ro_string&,
                   const ::xml_schema::ro_string&,
                   const ::xml_schema::ro_string&);

  protected:
  ::RPG_Magic_Spell_Duration_Type_pskel* duration_parser_;
  ::xml_schema::boolean_pskel* dismissible_parser_;
};

class RPG_Magic_Export RPG_Magic_Spell_Precondition_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_Spell_Precondition
  post_RPG_Magic_Spell_Precondition_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Spell_PreconditionProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Magic_Spell_Precondition&);

  virtual void
  value (int);

  virtual void
  levelIncrement (unsigned char);

  virtual void
  levelIncrementMax (unsigned char);

  virtual void
  alignment ();

  virtual void
  attribute (const RPG_Common_Attribute&);

  virtual void
  condition (const RPG_Common_Condition&);

  virtual void
  creature (const RPG_Common_CreatureType&);

  virtual void
  size (const RPG_Common_Size&);

  virtual void
  environment (const RPG_Common_Environment&);

  virtual void
  reverse (bool);

  virtual void
  baseIsCasterLevel (bool);

  virtual RPG_Magic_Spell_PreconditionProperties
  post_RPG_Magic_Spell_PreconditionProperties_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Magic_Spell_Precondition_Type_pskel&);

  void
  value_parser (::xml_schema::int_pskel&);

  void
  levelIncrement_parser (::xml_schema::unsigned_byte_pskel&);

  void
  levelIncrementMax_parser (::xml_schema::unsigned_byte_pskel&);

  void
  alignment_parser (::RPG_Character_Alignment_Type_pskel&);

  void
  attribute_parser (::RPG_Common_Attribute_Type_pskel&);

  void
  condition_parser (::RPG_Common_Condition_Type_pskel&);

  void
  creature_parser (::RPG_Common_CreatureType_Type_pskel&);

  void
  size_parser (::RPG_Common_Size_Type_pskel&);

  void
  environment_parser (::RPG_Common_Environment_Type_pskel&);

  void
  reverse_parser (::xml_schema::boolean_pskel&);

  void
  baseIsCasterLevel_parser (::xml_schema::boolean_pskel&);

  void
  parsers (::RPG_Magic_Spell_Precondition_Type_pskel& /* type */,
           ::xml_schema::int_pskel& /* value */,
           ::xml_schema::unsigned_byte_pskel& /* levelIncrement */,
           ::xml_schema::unsigned_byte_pskel& /* levelIncrementMax */,
           ::RPG_Character_Alignment_Type_pskel& /* alignment */,
           ::RPG_Common_Attribute_Type_pskel& /* attribute */,
           ::RPG_Common_Condition_Type_pskel& /* condition */,
           ::RPG_Common_CreatureType_Type_pskel& /* creature */,
           ::RPG_Common_Size_Type_pskel& /* size */,
           ::RPG_Common_Environment_Type_pskel& /* environment */,
           ::xml_schema::boolean_pskel& /* reverse */,
           ::xml_schema::boolean_pskel& /* baseIsCasterLevel */);

  // Constructor.
  //
  RPG_Magic_Spell_PreconditionProperties_Type_pskel ();

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
  ::RPG_Magic_Spell_Precondition_Type_pskel* type_parser_;
  ::xml_schema::int_pskel* value_parser_;
  ::xml_schema::unsigned_byte_pskel* levelIncrement_parser_;
  ::xml_schema::unsigned_byte_pskel* levelIncrementMax_parser_;
  ::RPG_Character_Alignment_Type_pskel* alignment_parser_;
  ::RPG_Common_Attribute_Type_pskel* attribute_parser_;
  ::RPG_Common_Condition_Type_pskel* condition_parser_;
  ::RPG_Common_CreatureType_Type_pskel* creature_parser_;
  ::RPG_Common_Size_Type_pskel* size_parser_;
  ::RPG_Common_Environment_Type_pskel* environment_parser_;
  ::xml_schema::boolean_pskel* reverse_parser_;
  ::xml_schema::boolean_pskel* baseIsCasterLevel_parser_;
};

class RPG_Magic_Export RPG_Magic_Spell_Effect_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Magic_Spell_Effect
  post_RPG_Magic_Spell_Effect_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Spell_DamageTypeUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Magic_Spell_DamageTypeUnion
  post_RPG_Magic_Spell_DamageTypeUnion_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_CheckTypeUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Magic_CheckTypeUnion
  post_RPG_Magic_CheckTypeUnion_Type () = 0;
};

class RPG_Magic_Export RPG_Magic_Check_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Magic_CheckTypeUnion&);

  virtual void
  difficultyClass (unsigned char);

  virtual void
  modifier (signed char);

  virtual void
  levelIncrementMax (unsigned char);

  virtual void
  baseIsCasterLevel (bool);

  virtual RPG_Magic_Check
  post_RPG_Magic_Check_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Magic_CheckTypeUnion_Type_pskel&);

  void
  difficultyClass_parser (::xml_schema::unsigned_byte_pskel&);

  void
  modifier_parser (::xml_schema::byte_pskel&);

  void
  levelIncrementMax_parser (::xml_schema::unsigned_byte_pskel&);

  void
  baseIsCasterLevel_parser (::xml_schema::boolean_pskel&);

  void
  parsers (::RPG_Magic_CheckTypeUnion_Type_pskel& /* type */,
           ::xml_schema::unsigned_byte_pskel& /* difficultyClass */,
           ::xml_schema::byte_pskel& /* modifier */,
           ::xml_schema::unsigned_byte_pskel& /* levelIncrementMax */,
           ::xml_schema::boolean_pskel& /* baseIsCasterLevel */);

  // Constructor.
  //
  RPG_Magic_Check_Type_pskel ();

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
  ::RPG_Magic_CheckTypeUnion_Type_pskel* type_parser_;
  ::xml_schema::unsigned_byte_pskel* difficultyClass_parser_;
  ::xml_schema::byte_pskel* modifier_parser_;
  ::xml_schema::unsigned_byte_pskel* levelIncrementMax_parser_;
  ::xml_schema::boolean_pskel* baseIsCasterLevel_parser_;
};

class RPG_Magic_Export RPG_Magic_CounterMeasure_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Common_CounterMeasure&);

  virtual void
  check (const RPG_Magic_Check&);

  virtual void
  spell (const RPG_Magic_SpellType&);

  virtual void
  reduction (const RPG_Common_SaveReductionType&);

  virtual RPG_Magic_CounterMeasure
  post_RPG_Magic_CounterMeasure_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Common_CounterMeasure_Type_pskel&);

  void
  check_parser (::RPG_Magic_Check_Type_pskel&);

  void
  spell_parser (::RPG_Magic_SpellType_Type_pskel&);

  void
  reduction_parser (::RPG_Common_SaveReductionType_Type_pskel&);

  void
  parsers (::RPG_Common_CounterMeasure_Type_pskel& /* type */,
           ::RPG_Magic_Check_Type_pskel& /* check */,
           ::RPG_Magic_SpellType_Type_pskel& /* spell */,
           ::RPG_Common_SaveReductionType_Type_pskel& /* reduction */);

  // Constructor.
  //
  RPG_Magic_CounterMeasure_Type_pskel ();

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
  ::RPG_Common_CounterMeasure_Type_pskel* type_parser_;
  ::RPG_Magic_Check_Type_pskel* check_parser_;
  ::RPG_Magic_SpellType_Type_pskel* spell_parser_;
  ::RPG_Common_SaveReductionType_Type_pskel* reduction_parser_;
};

class RPG_Magic_Export RPG_Magic_Spell_EffectProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Magic_Spell_Effect&);

  virtual void
  damage (const RPG_Magic_Spell_DamageTypeUnion&);

  virtual void
  base (const RPG_Common_Amount&);

  virtual void
  increment (unsigned int);

  virtual void
  levelIncrement (const RPG_Common_Amount&);

  virtual void
  levelIncrementMax (unsigned char);

  virtual void
  attribute (const RPG_Common_Attribute&);

  virtual void
  domain (const RPG_Magic_Domain&);

  virtual void
  creature (const RPG_Common_CreatureType&);

  virtual void
  duration (const RPG_Common_EffectDuration&);

  virtual void
  precondition (const RPG_Magic_Spell_PreconditionProperties&);

  virtual void
  maxRange (unsigned char);

  virtual void
  counterMeasure (const RPG_Magic_CounterMeasure&);

  virtual void
  includeAdjacent (bool);

  virtual void
  incrementIsReciprocal (bool);

  virtual RPG_Magic_Spell_EffectProperties
  post_RPG_Magic_Spell_EffectProperties_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Magic_Spell_Effect_Type_pskel&);

  void
  damage_parser (::RPG_Magic_Spell_DamageTypeUnion_Type_pskel&);

  void
  base_parser (::RPG_Common_Amount_Type_pskel&);

  void
  increment_parser (::xml_schema::unsigned_int_pskel&);

  void
  levelIncrement_parser (::RPG_Common_Amount_Type_pskel&);

  void
  levelIncrementMax_parser (::xml_schema::unsigned_byte_pskel&);

  void
  attribute_parser (::RPG_Common_Attribute_Type_pskel&);

  void
  domain_parser (::RPG_Magic_Domain_Type_pskel&);

  void
  creature_parser (::RPG_Common_CreatureType_Type_pskel&);

  void
  duration_parser (::RPG_Common_EffectDuration_Type_pskel&);

  void
  precondition_parser (::RPG_Magic_Spell_PreconditionProperties_Type_pskel&);

  void
  maxRange_parser (::xml_schema::unsigned_byte_pskel&);

  void
  counterMeasure_parser (::RPG_Magic_CounterMeasure_Type_pskel&);

  void
  includeAdjacent_parser (::xml_schema::boolean_pskel&);

  void
  incrementIsReciprocal_parser (::xml_schema::boolean_pskel&);

  void
  parsers (::RPG_Magic_Spell_Effect_Type_pskel& /* type */,
           ::RPG_Magic_Spell_DamageTypeUnion_Type_pskel& /* damage */,
           ::RPG_Common_Amount_Type_pskel& /* base */,
           ::xml_schema::unsigned_int_pskel& /* increment */,
           ::RPG_Common_Amount_Type_pskel& /* levelIncrement */,
           ::xml_schema::unsigned_byte_pskel& /* levelIncrementMax */,
           ::RPG_Common_Attribute_Type_pskel& /* attribute */,
           ::RPG_Magic_Domain_Type_pskel& /* domain */,
           ::RPG_Common_CreatureType_Type_pskel& /* creature */,
           ::RPG_Common_EffectDuration_Type_pskel& /* duration */,
           ::RPG_Magic_Spell_PreconditionProperties_Type_pskel& /* precondition */,
           ::xml_schema::unsigned_byte_pskel& /* maxRange */,
           ::RPG_Magic_CounterMeasure_Type_pskel& /* counterMeasure */,
           ::xml_schema::boolean_pskel& /* includeAdjacent */,
           ::xml_schema::boolean_pskel& /* incrementIsReciprocal */);

  // Constructor.
  //
  RPG_Magic_Spell_EffectProperties_Type_pskel ();

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
  ::RPG_Magic_Spell_Effect_Type_pskel* type_parser_;
  ::RPG_Magic_Spell_DamageTypeUnion_Type_pskel* damage_parser_;
  ::RPG_Common_Amount_Type_pskel* base_parser_;
  ::xml_schema::unsigned_int_pskel* increment_parser_;
  ::RPG_Common_Amount_Type_pskel* levelIncrement_parser_;
  ::xml_schema::unsigned_byte_pskel* levelIncrementMax_parser_;
  ::RPG_Common_Attribute_Type_pskel* attribute_parser_;
  ::RPG_Magic_Domain_Type_pskel* domain_parser_;
  ::RPG_Common_CreatureType_Type_pskel* creature_parser_;
  ::RPG_Common_EffectDuration_Type_pskel* duration_parser_;
  ::RPG_Magic_Spell_PreconditionProperties_Type_pskel* precondition_parser_;
  ::xml_schema::unsigned_byte_pskel* maxRange_parser_;
  ::RPG_Magic_CounterMeasure_Type_pskel* counterMeasure_parser_;
  ::xml_schema::boolean_pskel* includeAdjacent_parser_;
  ::xml_schema::boolean_pskel* incrementIsReciprocal_parser_;
};

class RPG_Magic_Export RPG_Magic_Spell_PropertiesXML_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  name (const ::std::string&);

  virtual void
  type (const RPG_Magic_Spell_Type&);

  virtual void
  level (const RPG_Magic_Spell_Level&);

  virtual void
  cost (unsigned int);

  virtual void
  time (const RPG_Magic_Spell_CastingTime&);

  virtual void
  range (const RPG_Magic_Spell_RangeProperties&);

  virtual void
  target (const RPG_Magic_Spell_TargetProperties&);

  virtual void
  duration (const RPG_Magic_Spell_DurationProperties&);

  virtual void
  precondition (const RPG_Magic_Spell_PreconditionProperties&);

  virtual void
  effect (const RPG_Magic_Spell_EffectProperties&);

  virtual void
  counterMeasure (const RPG_Magic_CounterMeasure&);

  virtual void
  saveable (const RPG_Common_SavingThrow&);

  virtual void
  resistible (bool);

  virtual void
  effectsAreInclusive (bool);

  virtual RPG_Magic_Spell_PropertiesXML
  post_RPG_Magic_Spell_PropertiesXML_Type () = 0;

  // Parser construction API.
  //
  void
  name_parser (::xml_schema::string_pskel&);

  void
  type_parser (::RPG_Magic_Spell_Type_Type_pskel&);

  void
  level_parser (::RPG_Magic_Spell_Level_Type_pskel&);

  void
  cost_parser (::xml_schema::unsigned_int_pskel&);

  void
  time_parser (::RPG_Magic_Spell_CastingTime_Type_pskel&);

  void
  range_parser (::RPG_Magic_Spell_RangeProperties_Type_pskel&);

  void
  target_parser (::RPG_Magic_Spell_TargetProperties_Type_pskel&);

  void
  duration_parser (::RPG_Magic_Spell_DurationProperties_Type_pskel&);

  void
  precondition_parser (::RPG_Magic_Spell_PreconditionProperties_Type_pskel&);

  void
  effect_parser (::RPG_Magic_Spell_EffectProperties_Type_pskel&);

  void
  counterMeasure_parser (::RPG_Magic_CounterMeasure_Type_pskel&);

  void
  saveable_parser (::RPG_Common_SavingThrow_Type_pskel&);

  void
  resistible_parser (::xml_schema::boolean_pskel&);

  void
  effectsAreInclusive_parser (::xml_schema::boolean_pskel&);

  void
  parsers (::xml_schema::string_pskel& /* name */,
           ::RPG_Magic_Spell_Type_Type_pskel& /* type */,
           ::RPG_Magic_Spell_Level_Type_pskel& /* level */,
           ::xml_schema::unsigned_int_pskel& /* cost */,
           ::RPG_Magic_Spell_CastingTime_Type_pskel& /* time */,
           ::RPG_Magic_Spell_RangeProperties_Type_pskel& /* range */,
           ::RPG_Magic_Spell_TargetProperties_Type_pskel& /* target */,
           ::RPG_Magic_Spell_DurationProperties_Type_pskel& /* duration */,
           ::RPG_Magic_Spell_PreconditionProperties_Type_pskel& /* precondition */,
           ::RPG_Magic_Spell_EffectProperties_Type_pskel& /* effect */,
           ::RPG_Magic_CounterMeasure_Type_pskel& /* counterMeasure */,
           ::RPG_Common_SavingThrow_Type_pskel& /* saveable */,
           ::xml_schema::boolean_pskel& /* resistible */,
           ::xml_schema::boolean_pskel& /* effectsAreInclusive */);

  // Constructor.
  //
  RPG_Magic_Spell_PropertiesXML_Type_pskel ();

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
  ::xml_schema::string_pskel* name_parser_;
  ::RPG_Magic_Spell_Type_Type_pskel* type_parser_;
  ::RPG_Magic_Spell_Level_Type_pskel* level_parser_;
  ::xml_schema::unsigned_int_pskel* cost_parser_;
  ::RPG_Magic_Spell_CastingTime_Type_pskel* time_parser_;
  ::RPG_Magic_Spell_RangeProperties_Type_pskel* range_parser_;
  ::RPG_Magic_Spell_TargetProperties_Type_pskel* target_parser_;
  ::RPG_Magic_Spell_DurationProperties_Type_pskel* duration_parser_;
  ::RPG_Magic_Spell_PreconditionProperties_Type_pskel* precondition_parser_;
  ::RPG_Magic_Spell_EffectProperties_Type_pskel* effect_parser_;
  ::RPG_Magic_CounterMeasure_Type_pskel* counterMeasure_parser_;
  ::RPG_Common_SavingThrow_Type_pskel* saveable_parser_;
  ::xml_schema::boolean_pskel* resistible_parser_;
  ::xml_schema::boolean_pskel* effectsAreInclusive_parser_;
};

class RPG_Magic_Export RPG_Magic_SpellLikeProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Magic_SpellType&);

  virtual void
  casterLevel (unsigned char);

  virtual void
  duration (const RPG_Common_Duration&);

  virtual void
  save ();

  virtual RPG_Magic_SpellLikeProperties
  post_RPG_Magic_SpellLikeProperties_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Magic_SpellType_Type_pskel&);

  void
  casterLevel_parser (::xml_schema::unsigned_byte_pskel&);

  void
  duration_parser (::RPG_Common_Duration_Type_pskel&);

  void
  save_parser (::RPG_Common_SavingThrowCheck_Type_pskel&);

  void
  parsers (::RPG_Magic_SpellType_Type_pskel& /* type */,
           ::xml_schema::unsigned_byte_pskel& /* casterLevel */,
           ::RPG_Common_Duration_Type_pskel& /* duration */,
           ::RPG_Common_SavingThrowCheck_Type_pskel& /* save */);

  // Constructor.
  //
  RPG_Magic_SpellLikeProperties_Type_pskel ();

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
  ::RPG_Magic_SpellType_Type_pskel* type_parser_;
  ::xml_schema::unsigned_byte_pskel* casterLevel_parser_;
  ::RPG_Common_Duration_Type_pskel* duration_parser_;
  ::RPG_Common_SavingThrowCheck_Type_pskel* save_parser_;
};

class RPG_Magic_Export RPG_Magic_Dictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  spell (const RPG_Magic_Spell_PropertiesXML&);

  virtual void
  post_RPG_Magic_Dictionary_Type ();

  // Parser construction API.
  //
  void
  spell_parser (::RPG_Magic_Spell_PropertiesXML_Type_pskel&);

  void
  parsers (::RPG_Magic_Spell_PropertiesXML_Type_pskel& /* spell */);

  // Constructor.
  //
  RPG_Magic_Dictionary_Type_pskel ();

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
  ::RPG_Magic_Spell_PropertiesXML_Type_pskel* spell_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_MAGIC_XML_TYPES_H
