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

// Begin prologue.
//
//
// End prologue.

#include <rpg_combat_XML_types.h>

// RPG_Combat_DamageElement_Type_pskel
//

void RPG_Combat_DamageElement_Type_pskel::
type_parser (::RPG_Combat_DamageTypeUnion_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
damage_parser (::RPG_Dice_Roll_Type_pskel& p)
{
  this->damage_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
duration_parser (::xml_schema::unsigned_short_pskel& p)
{
  this->duration_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
effect_parser (::RPG_Combat_DamageEffectType_Type_pskel& p)
{
  this->effect_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
parsers (::RPG_Combat_DamageTypeUnion_Type_pskel& type,
         ::RPG_Dice_Roll_Type_pskel& damage,
         ::xml_schema::unsigned_short_pskel& duration,
         ::RPG_Combat_DamageEffectType_Type_pskel& effect)
{
  this->type_parser_ = &type;
  this->damage_parser_ = &damage;
  this->duration_parser_ = &duration;
  this->effect_parser_ = &effect;
}

RPG_Combat_DamageElement_Type_pskel::
RPG_Combat_DamageElement_Type_pskel ()
: type_parser_ (0),
  damage_parser_ (0),
  duration_parser_ (0),
  effect_parser_ (0)
{
}

// RPG_Combat_Damage_Type_pskel
//

void RPG_Combat_Damage_Type_pskel::
element_parser (::RPG_Combat_DamageElement_Type_pskel& p)
{
  this->element_parser_ = &p;
}

void RPG_Combat_Damage_Type_pskel::
parsers (::RPG_Combat_DamageElement_Type_pskel& element)
{
  this->element_parser_ = &element;
}

RPG_Combat_Damage_Type_pskel::
RPG_Combat_Damage_Type_pskel ()
: element_parser_ (0)
{
}

// RPG_Combat_SpecialAttack_Type_pskel
//

void RPG_Combat_SpecialAttack_Type_pskel::
post_RPG_Combat_SpecialAttack_Type ()
{
}

// RPG_Combat_SpecialDamageType_Type_pskel
//

void RPG_Combat_SpecialDamageType_Type_pskel::
post_RPG_Combat_SpecialDamageType_Type ()
{
}

// RPG_Combat_DamageEffectType_Type_pskel
//

void RPG_Combat_DamageEffectType_Type_pskel::
post_RPG_Combat_DamageEffectType_Type ()
{
}

// RPG_Combat_DamageTypeUnion_Type_pskel
//

void RPG_Combat_DamageTypeUnion_Type_pskel::
post_RPG_Combat_DamageTypeUnion_Type ()
{
}

// RPG_Combat_DamageElement_Type_pskel
//

void RPG_Combat_DamageElement_Type_pskel::
type ()
{
}

void RPG_Combat_DamageElement_Type_pskel::
damage ()
{
}

void RPG_Combat_DamageElement_Type_pskel::
duration (unsigned short)
{
}

void RPG_Combat_DamageElement_Type_pskel::
effect ()
{
}

void RPG_Combat_DamageElement_Type_pskel::
post_RPG_Combat_DamageElement_Type ()
{
}

bool RPG_Combat_DamageElement_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->type_parser_;

    if (this->type_parser_)
      this->type_parser_->pre ();

    return true;
  }

  if (n == "damage" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->damage_parser_;

    if (this->damage_parser_)
      this->damage_parser_->pre ();

    return true;
  }

  if (n == "duration" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->duration_parser_;

    if (this->duration_parser_)
      this->duration_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Combat_DamageElement_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
    {
      this->type_parser_->post_RPG_Combat_DamageTypeUnion_Type ();
      this->type ();
    }

    return true;
  }

  if (n == "damage" && ns == "urn:rpg")
  {
    if (this->damage_parser_)
    {
      this->damage_parser_->post_RPG_Dice_Roll_Type ();
      this->damage ();
    }

    return true;
  }

  if (n == "duration" && ns == "urn:rpg")
  {
    if (this->duration_parser_)
      this->duration (this->duration_parser_->post_unsigned_short ());

    return true;
  }

  return false;
}

bool RPG_Combat_DamageElement_Type_pskel::
_attribute_impl (const ::xml_schema::ro_string& ns,
                 const ::xml_schema::ro_string& n,
                 const ::xml_schema::ro_string& v)
{
  if (this->::xml_schema::complex_content::_attribute_impl (ns, n, v))
    return true;

  if (n == "effect" && ns == "urn:rpg")
  {
    if (this->effect_parser_)
    {
      this->effect_parser_->pre ();
      this->effect_parser_->_pre_impl ();
      this->effect_parser_->_characters (v);
      this->effect_parser_->_post_impl ();
      this->effect_parser_->post_RPG_Combat_DamageEffectType_Type ();
      this->effect ();
    }

    return true;
  }

  return false;
}

// RPG_Combat_Damage_Type_pskel
//

void RPG_Combat_Damage_Type_pskel::
element ()
{
}

void RPG_Combat_Damage_Type_pskel::
post_RPG_Combat_Damage_Type ()
{
}

bool RPG_Combat_Damage_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "element" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->element_parser_;

    if (this->element_parser_)
      this->element_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Combat_Damage_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "element" && ns == "urn:rpg")
  {
    if (this->element_parser_)
    {
      this->element_parser_->post_RPG_Combat_DamageElement_Type ();
      this->element ();
    }

    return true;
  }

  return false;
}

// Begin epilogue.
//
//
// End epilogue.

