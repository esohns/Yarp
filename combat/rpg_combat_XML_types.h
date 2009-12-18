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
class RPG_Combat_SpecialAttack_Type_pskel;
class RPG_Combat_SpecialDamageType_Type_pskel;
class RPG_Combat_DamageEffectType_Type_pskel;
class RPG_Combat_DamageTypeUnion_Type_pskel;
class RPG_Combat_DamageElement_Type_pskel;
class RPG_Combat_Damage_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include <rpg_XMLSchema.h>

#include <rpg_dice_incl.h>
#include <rpg_item_incl.h>
#include "rpg_combat_incl.h"

#include <rpg_dice_XML_types.h>

#include <rpg_item_XML_types.h>

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
  damage (const RPG_Dice_Roll&);

  virtual void
  duration (unsigned short);

  virtual void
  effect (const RPG_Combat_DamageEffectType&);

  virtual RPG_Combat_DamageElement
  post_RPG_Combat_DamageElement_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Combat_DamageTypeUnion_Type_pskel&);

  void
  damage_parser (::RPG_Dice_Roll_Type_pskel&);

  void
  duration_parser (::xml_schema::unsigned_short_pskel&);

  void
  effect_parser (::RPG_Combat_DamageEffectType_Type_pskel&);

  void
  parsers (::RPG_Combat_DamageTypeUnion_Type_pskel& /* type */,
           ::RPG_Dice_Roll_Type_pskel& /* damage */,
           ::xml_schema::unsigned_short_pskel& /* duration */,
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
  ::RPG_Dice_Roll_Type_pskel* damage_parser_;
  ::xml_schema::unsigned_short_pskel* duration_parser_;
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
