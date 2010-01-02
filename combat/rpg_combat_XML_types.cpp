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

// RPG_Combat_RangedAttackProperties_Type_pskel
//

void RPG_Combat_RangedAttackProperties_Type_pskel::
maxRange_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->maxRange_parser_ = &p;
}

void RPG_Combat_RangedAttackProperties_Type_pskel::
increment_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->increment_parser_ = &p;
}

void RPG_Combat_RangedAttackProperties_Type_pskel::
effect_parser (::RPG_Combat_RangedEffectUnion_Type_pskel& p)
{
  this->effect_parser_ = &p;
}

void RPG_Combat_RangedAttackProperties_Type_pskel::
parsers (::xml_schema::unsigned_byte_pskel& maxRange,
         ::xml_schema::unsigned_byte_pskel& increment,
         ::RPG_Combat_RangedEffectUnion_Type_pskel& effect)
{
  this->maxRange_parser_ = &maxRange;
  this->increment_parser_ = &increment;
  this->effect_parser_ = &effect;
}

RPG_Combat_RangedAttackProperties_Type_pskel::
RPG_Combat_RangedAttackProperties_Type_pskel ()
: maxRange_parser_ (0),
  increment_parser_ (0),
  effect_parser_ (0)
{
}

// RPG_Combat_DamageDuration_Type_pskel
//

void RPG_Combat_DamageDuration_Type_pskel::
incubationPeriod_parser (::RPG_Dice_Roll_Type_pskel& p)
{
  this->incubationPeriod_parser_ = &p;
}

void RPG_Combat_DamageDuration_Type_pskel::
interval_parser (::xml_schema::unsigned_short_pskel& p)
{
  this->interval_parser_ = &p;
}

void RPG_Combat_DamageDuration_Type_pskel::
totalDuration_parser (::xml_schema::unsigned_short_pskel& p)
{
  this->totalDuration_parser_ = &p;
}

void RPG_Combat_DamageDuration_Type_pskel::
parsers (::RPG_Dice_Roll_Type_pskel& incubationPeriod,
         ::xml_schema::unsigned_short_pskel& interval,
         ::xml_schema::unsigned_short_pskel& totalDuration)
{
  this->incubationPeriod_parser_ = &incubationPeriod;
  this->interval_parser_ = &interval;
  this->totalDuration_parser_ = &totalDuration;
}

RPG_Combat_DamageDuration_Type_pskel::
RPG_Combat_DamageDuration_Type_pskel ()
: incubationPeriod_parser_ (0),
  interval_parser_ (0),
  totalDuration_parser_ (0)
{
}

// RPG_Combat_DamageBonus_Type_pskel
//

void RPG_Combat_DamageBonus_Type_pskel::
type_parser (::RPG_Combat_DamageBonusType_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Combat_DamageBonus_Type_pskel::
modifier_parser (::xml_schema::byte_pskel& p)
{
  this->modifier_parser_ = &p;
}

void RPG_Combat_DamageBonus_Type_pskel::
parsers (::RPG_Combat_DamageBonusType_Type_pskel& type,
         ::xml_schema::byte_pskel& modifier)
{
  this->type_parser_ = &type;
  this->modifier_parser_ = &modifier;
}

RPG_Combat_DamageBonus_Type_pskel::
RPG_Combat_DamageBonus_Type_pskel ()
: type_parser_ (0),
  modifier_parser_ (0)
{
}

// RPG_Combat_DamageElement_Type_pskel
//

void RPG_Combat_DamageElement_Type_pskel::
type_parser (::RPG_Combat_DamageTypeUnion_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
amount_parser (::RPG_Dice_Roll_Type_pskel& p)
{
  this->amount_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
duration_parser (::RPG_Combat_DamageDuration_Type_pskel& p)
{
  this->duration_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
other_parser (::RPG_Combat_DamageBonus_Type_pskel& p)
{
  this->other_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
attribute_parser (::RPG_Common_Attribute_Type_pskel& p)
{
  this->attribute_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
save_parser (::RPG_Common_SavingThrowModifier_Type_pskel& p)
{
  this->save_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
counterMeasure_parser (::xml_schema::boolean_pskel& p)
{
  this->counterMeasure_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
effect_parser (::RPG_Combat_DamageEffectType_Type_pskel& p)
{
  this->effect_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
parsers (::RPG_Combat_DamageTypeUnion_Type_pskel& type,
         ::RPG_Dice_Roll_Type_pskel& amount,
         ::RPG_Combat_DamageDuration_Type_pskel& duration,
         ::RPG_Combat_DamageBonus_Type_pskel& other,
         ::RPG_Common_Attribute_Type_pskel& attribute,
         ::RPG_Common_SavingThrowModifier_Type_pskel& save,
         ::xml_schema::boolean_pskel& counterMeasure,
         ::RPG_Combat_DamageEffectType_Type_pskel& effect)
{
  this->type_parser_ = &type;
  this->amount_parser_ = &amount;
  this->duration_parser_ = &duration;
  this->other_parser_ = &other;
  this->attribute_parser_ = &attribute;
  this->save_parser_ = &save;
  this->counterMeasure_parser_ = &counterMeasure;
  this->effect_parser_ = &effect;
}

RPG_Combat_DamageElement_Type_pskel::
RPG_Combat_DamageElement_Type_pskel ()
: type_parser_ (0),
  amount_parser_ (0),
  duration_parser_ (0),
  other_parser_ (0),
  attribute_parser_ (0),
  save_parser_ (0),
  counterMeasure_parser_ (0),
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

// RPG_Combat_RangedAttackProperties_Type_pskel
//

void RPG_Combat_RangedAttackProperties_Type_pskel::
maxRange (unsigned char)
{
}

void RPG_Combat_RangedAttackProperties_Type_pskel::
increment (unsigned char)
{
}

void RPG_Combat_RangedAttackProperties_Type_pskel::
effect (const RPG_Combat_RangedEffectUnion&)
{
}

bool RPG_Combat_RangedAttackProperties_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "maxRange" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->maxRange_parser_;

    if (this->maxRange_parser_)
      this->maxRange_parser_->pre ();

    return true;
  }

  if (n == "increment" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->increment_parser_;

    if (this->increment_parser_)
      this->increment_parser_->pre ();

    return true;
  }

  if (n == "effect" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->effect_parser_;

    if (this->effect_parser_)
      this->effect_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Combat_RangedAttackProperties_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "maxRange" && ns == "urn:rpg")
  {
    if (this->maxRange_parser_)
      this->maxRange (this->maxRange_parser_->post_unsigned_byte ());

    return true;
  }

  if (n == "increment" && ns == "urn:rpg")
  {
    if (this->increment_parser_)
      this->increment (this->increment_parser_->post_unsigned_byte ());

    return true;
  }

  if (n == "effect" && ns == "urn:rpg")
  {
    if (this->effect_parser_)
      this->effect (this->effect_parser_->post_RPG_Combat_RangedEffectUnion_Type ());

    return true;
  }

  return false;
}

// RPG_Combat_DamageDuration_Type_pskel
//

void RPG_Combat_DamageDuration_Type_pskel::
incubationPeriod (const RPG_Dice_Roll&)
{
}

void RPG_Combat_DamageDuration_Type_pskel::
interval (unsigned short)
{
}

void RPG_Combat_DamageDuration_Type_pskel::
totalDuration (unsigned short)
{
}

bool RPG_Combat_DamageDuration_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "incubationPeriod" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->incubationPeriod_parser_;

    if (this->incubationPeriod_parser_)
      this->incubationPeriod_parser_->pre ();

    return true;
  }

  if (n == "interval" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->interval_parser_;

    if (this->interval_parser_)
      this->interval_parser_->pre ();

    return true;
  }

  if (n == "totalDuration" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->totalDuration_parser_;

    if (this->totalDuration_parser_)
      this->totalDuration_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Combat_DamageDuration_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "incubationPeriod" && ns == "urn:rpg")
  {
    if (this->incubationPeriod_parser_)
      this->incubationPeriod (this->incubationPeriod_parser_->post_RPG_Dice_Roll_Type ());

    return true;
  }

  if (n == "interval" && ns == "urn:rpg")
  {
    if (this->interval_parser_)
      this->interval (this->interval_parser_->post_unsigned_short ());

    return true;
  }

  if (n == "totalDuration" && ns == "urn:rpg")
  {
    if (this->totalDuration_parser_)
      this->totalDuration (this->totalDuration_parser_->post_unsigned_short ());

    return true;
  }

  return false;
}

// RPG_Combat_DamageBonus_Type_pskel
//

void RPG_Combat_DamageBonus_Type_pskel::
type (const RPG_Combat_DamageBonusType&)
{
}

void RPG_Combat_DamageBonus_Type_pskel::
modifier (signed char)
{
}

bool RPG_Combat_DamageBonus_Type_pskel::
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

  if (n == "modifier" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->modifier_parser_;

    if (this->modifier_parser_)
      this->modifier_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Combat_DamageBonus_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Combat_DamageBonusType_Type ());

    return true;
  }

  if (n == "modifier" && ns == "urn:rpg")
  {
    if (this->modifier_parser_)
      this->modifier (this->modifier_parser_->post_byte ());

    return true;
  }

  return false;
}

// RPG_Combat_DamageElement_Type_pskel
//

void RPG_Combat_DamageElement_Type_pskel::
type (const RPG_Combat_DamageTypeUnion&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
amount (const RPG_Dice_Roll&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
duration (const RPG_Combat_DamageDuration&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
other (const RPG_Combat_DamageBonus&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
attribute (const RPG_Common_Attribute&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
save (const RPG_Common_SavingThrowModifier&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
counterMeasure (bool)
{
}

void RPG_Combat_DamageElement_Type_pskel::
effect (const RPG_Combat_DamageEffectType&)
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

  if (n == "amount" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->amount_parser_;

    if (this->amount_parser_)
      this->amount_parser_->pre ();

    return true;
  }

  if (n == "duration" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->duration_parser_;

    if (this->duration_parser_)
      this->duration_parser_->pre ();

    return true;
  }

  if (n == "other" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->other_parser_;

    if (this->other_parser_)
      this->other_parser_->pre ();

    return true;
  }

  if (n == "attribute" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->attribute_parser_;

    if (this->attribute_parser_)
      this->attribute_parser_->pre ();

    return true;
  }

  if (n == "save" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->save_parser_;

    if (this->save_parser_)
      this->save_parser_->pre ();

    return true;
  }

  if (n == "counterMeasure" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->counterMeasure_parser_;

    if (this->counterMeasure_parser_)
      this->counterMeasure_parser_->pre ();

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
      this->type (this->type_parser_->post_RPG_Combat_DamageTypeUnion_Type ());

    return true;
  }

  if (n == "amount" && ns == "urn:rpg")
  {
    if (this->amount_parser_)
      this->amount (this->amount_parser_->post_RPG_Dice_Roll_Type ());

    return true;
  }

  if (n == "duration" && ns == "urn:rpg")
  {
    if (this->duration_parser_)
      this->duration (this->duration_parser_->post_RPG_Combat_DamageDuration_Type ());

    return true;
  }

  if (n == "other" && ns == "urn:rpg")
  {
    if (this->other_parser_)
      this->other (this->other_parser_->post_RPG_Combat_DamageBonus_Type ());

    return true;
  }

  if (n == "attribute" && ns == "urn:rpg")
  {
    if (this->attribute_parser_)
      this->attribute (this->attribute_parser_->post_RPG_Common_Attribute_Type ());

    return true;
  }

  if (n == "save" && ns == "urn:rpg")
  {
    if (this->save_parser_)
      this->save (this->save_parser_->post_RPG_Common_SavingThrowModifier_Type ());

    return true;
  }

  if (n == "counterMeasure" && ns == "urn:rpg")
  {
    if (this->counterMeasure_parser_)
      this->counterMeasure (this->counterMeasure_parser_->post_boolean ());

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

  if (n == "effect" && ns.empty ())
  {
    if (this->effect_parser_)
    {
      this->effect_parser_->pre ();
      this->effect_parser_->_pre_impl ();
      this->effect_parser_->_characters (v);
      this->effect_parser_->_post_impl ();
      this->effect (this->effect_parser_->post_RPG_Combat_DamageEffectType_Type ());
    }

    return true;
  }

  return false;
}

// RPG_Combat_Damage_Type_pskel
//

void RPG_Combat_Damage_Type_pskel::
element (const RPG_Combat_DamageElement&)
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
      this->element (this->element_parser_->post_RPG_Combat_DamageElement_Type ());

    return true;
  }

  return false;
}

// Begin epilogue.
//
//
// End epilogue.

