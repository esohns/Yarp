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
totalPeriod_parser (::RPG_Dice_Roll_Type_pskel& p)
{
  this->totalPeriod_parser_ = &p;
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
vicinity_parser (::xml_schema::boolean_pskel& p)
{
  this->vicinity_parser_ = &p;
}

void RPG_Combat_DamageDuration_Type_pskel::
parsers (::RPG_Dice_Roll_Type_pskel& incubationPeriod,
         ::RPG_Dice_Roll_Type_pskel& totalPeriod,
         ::xml_schema::unsigned_short_pskel& interval,
         ::xml_schema::unsigned_short_pskel& totalDuration,
         ::xml_schema::boolean_pskel& vicinity)
{
  this->incubationPeriod_parser_ = &incubationPeriod;
  this->totalPeriod_parser_ = &totalPeriod;
  this->interval_parser_ = &interval;
  this->totalDuration_parser_ = &totalDuration;
  this->vicinity_parser_ = &vicinity;
}

RPG_Combat_DamageDuration_Type_pskel::
RPG_Combat_DamageDuration_Type_pskel ()
: incubationPeriod_parser_ (0),
  totalPeriod_parser_ (0),
  interval_parser_ (0),
  totalDuration_parser_ (0),
  vicinity_parser_ (0)
{
}

// RPG_Combat_Check_Type_pskel
//

void RPG_Combat_Check_Type_pskel::
type_parser (::RPG_Combat_CheckTypeUnion_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Combat_Check_Type_pskel::
attribute_parser (::RPG_Common_Attribute_Type_pskel& p)
{
  this->attribute_parser_ = &p;
}

void RPG_Combat_Check_Type_pskel::
difficultyClass_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->difficultyClass_parser_ = &p;
}

void RPG_Combat_Check_Type_pskel::
parsers (::RPG_Combat_CheckTypeUnion_Type_pskel& type,
         ::RPG_Common_Attribute_Type_pskel& attribute,
         ::xml_schema::unsigned_byte_pskel& difficultyClass)
{
  this->type_parser_ = &type;
  this->attribute_parser_ = &attribute;
  this->difficultyClass_parser_ = &difficultyClass;
}

RPG_Combat_Check_Type_pskel::
RPG_Combat_Check_Type_pskel ()
: type_parser_ (0),
  attribute_parser_ (0),
  difficultyClass_parser_ (0)
{
}

// RPG_Combat_DamageCounterMeasure_Type_pskel
//

void RPG_Combat_DamageCounterMeasure_Type_pskel::
type_parser (::RPG_Common_CounterMeasure_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
check_parser (::RPG_Combat_Check_Type_pskel& p)
{
  this->check_parser_ = &p;
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
spell_parser (::RPG_Magic_SpellType_Type_pskel& p)
{
  this->spell_parser_ = &p;
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
duration_parser (::RPG_Common_Duration_Type_pskel& p)
{
  this->duration_parser_ = &p;
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
condition_parser (::RPG_Common_Condition_Type_pskel& p)
{
  this->condition_parser_ = &p;
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
reduction_parser (::RPG_Combat_DamageReductionType_Type_pskel& p)
{
  this->reduction_parser_ = &p;
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
parsers (::RPG_Common_CounterMeasure_Type_pskel& type,
         ::RPG_Combat_Check_Type_pskel& check,
         ::RPG_Magic_SpellType_Type_pskel& spell,
         ::RPG_Common_Duration_Type_pskel& duration,
         ::RPG_Common_Condition_Type_pskel& condition,
         ::RPG_Combat_DamageReductionType_Type_pskel& reduction)
{
  this->type_parser_ = &type;
  this->check_parser_ = &check;
  this->spell_parser_ = &spell;
  this->duration_parser_ = &duration;
  this->condition_parser_ = &condition;
  this->reduction_parser_ = &reduction;
}

RPG_Combat_DamageCounterMeasure_Type_pskel::
RPG_Combat_DamageCounterMeasure_Type_pskel ()
: type_parser_ (0),
  check_parser_ (0),
  spell_parser_ (0),
  duration_parser_ (0),
  condition_parser_ (0),
  reduction_parser_ (0)
{
}

// RPG_Combat_OtherDamage_Type_pskel
//

void RPG_Combat_OtherDamage_Type_pskel::
type_parser (::RPG_Combat_OtherDamageType_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Combat_OtherDamage_Type_pskel::
modifier_parser (::xml_schema::byte_pskel& p)
{
  this->modifier_parser_ = &p;
}

void RPG_Combat_OtherDamage_Type_pskel::
counterMeasure_parser (::RPG_Combat_DamageCounterMeasure_Type_pskel& p)
{
  this->counterMeasure_parser_ = &p;
}

void RPG_Combat_OtherDamage_Type_pskel::
parsers (::RPG_Combat_OtherDamageType_Type_pskel& type,
         ::xml_schema::byte_pskel& modifier,
         ::RPG_Combat_DamageCounterMeasure_Type_pskel& counterMeasure)
{
  this->type_parser_ = &type;
  this->modifier_parser_ = &modifier;
  this->counterMeasure_parser_ = &counterMeasure;
}

RPG_Combat_OtherDamage_Type_pskel::
RPG_Combat_OtherDamage_Type_pskel ()
: type_parser_ (0),
  modifier_parser_ (0),
  counterMeasure_parser_ (0)
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
secondary_parser (::RPG_Dice_Roll_Type_pskel& p)
{
  this->secondary_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
attribute_parser (::RPG_Common_Attribute_Type_pskel& p)
{
  this->attribute_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
condition_parser (::RPG_Common_Condition_Type_pskel& p)
{
  this->condition_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
duration_parser (::RPG_Combat_DamageDuration_Type_pskel& p)
{
  this->duration_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
counterMeasure_parser (::RPG_Combat_DamageCounterMeasure_Type_pskel& p)
{
  this->counterMeasure_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
other_parser (::RPG_Combat_OtherDamage_Type_pskel& p)
{
  this->other_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
effect_parser (::RPG_Common_EffectType_Type_pskel& p)
{
  this->effect_parser_ = &p;
}

void RPG_Combat_DamageElement_Type_pskel::
parsers (::RPG_Combat_DamageTypeUnion_Type_pskel& type,
         ::RPG_Dice_Roll_Type_pskel& amount,
         ::RPG_Dice_Roll_Type_pskel& secondary,
         ::RPG_Common_Attribute_Type_pskel& attribute,
         ::RPG_Common_Condition_Type_pskel& condition,
         ::RPG_Combat_DamageDuration_Type_pskel& duration,
         ::RPG_Combat_DamageCounterMeasure_Type_pskel& counterMeasure,
         ::RPG_Combat_OtherDamage_Type_pskel& other,
         ::RPG_Common_EffectType_Type_pskel& effect)
{
  this->type_parser_ = &type;
  this->amount_parser_ = &amount;
  this->secondary_parser_ = &secondary;
  this->attribute_parser_ = &attribute;
  this->condition_parser_ = &condition;
  this->duration_parser_ = &duration;
  this->counterMeasure_parser_ = &counterMeasure;
  this->other_parser_ = &other;
  this->effect_parser_ = &effect;
}

RPG_Combat_DamageElement_Type_pskel::
RPG_Combat_DamageElement_Type_pskel ()
: type_parser_ (0),
  amount_parser_ (0),
  secondary_parser_ (0),
  attribute_parser_ (0),
  condition_parser_ (0),
  duration_parser_ (0),
  counterMeasure_parser_ (0),
  other_parser_ (0),
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
elementsAreInclusive_parser (::xml_schema::boolean_pskel& p)
{
  this->elementsAreInclusive_parser_ = &p;
}

void RPG_Combat_Damage_Type_pskel::
parsers (::RPG_Combat_DamageElement_Type_pskel& element,
         ::xml_schema::boolean_pskel& elementsAreInclusive)
{
  this->element_parser_ = &element;
  this->elementsAreInclusive_parser_ = &elementsAreInclusive;
}

RPG_Combat_Damage_Type_pskel::
RPG_Combat_Damage_Type_pskel ()
: element_parser_ (0),
  elementsAreInclusive_parser_ (0)
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

  return false;
}

bool RPG_Combat_RangedAttackProperties_Type_pskel::
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
      this->effect (this->effect_parser_->post_RPG_Combat_RangedEffectUnion_Type ());
    }

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
totalPeriod (const RPG_Dice_Roll&)
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

void RPG_Combat_DamageDuration_Type_pskel::
vicinity (bool)
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

  if (n == "totalPeriod" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->totalPeriod_parser_;

    if (this->totalPeriod_parser_)
      this->totalPeriod_parser_->pre ();

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

  if (n == "totalPeriod" && ns == "urn:rpg")
  {
    if (this->totalPeriod_parser_)
      this->totalPeriod (this->totalPeriod_parser_->post_RPG_Dice_Roll_Type ());

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

bool RPG_Combat_DamageDuration_Type_pskel::
_attribute_impl (const ::xml_schema::ro_string& ns,
                 const ::xml_schema::ro_string& n,
                 const ::xml_schema::ro_string& v)
{
  if (this->::xml_schema::complex_content::_attribute_impl (ns, n, v))
    return true;

  if (n == "vicinity" && ns.empty ())
  {
    if (this->vicinity_parser_)
    {
      this->vicinity_parser_->pre ();
      this->vicinity_parser_->_pre_impl ();
      this->vicinity_parser_->_characters (v);
      this->vicinity_parser_->_post_impl ();
      this->vicinity (this->vicinity_parser_->post_boolean ());
    }

    return true;
  }

  return false;
}

// RPG_Combat_Check_Type_pskel
//

void RPG_Combat_Check_Type_pskel::
type (const RPG_Combat_CheckTypeUnion&)
{
}

void RPG_Combat_Check_Type_pskel::
attribute (const RPG_Common_Attribute&)
{
}

void RPG_Combat_Check_Type_pskel::
difficultyClass (unsigned char)
{
}

bool RPG_Combat_Check_Type_pskel::
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

  if (n == "attribute" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->attribute_parser_;

    if (this->attribute_parser_)
      this->attribute_parser_->pre ();

    return true;
  }

  if (n == "difficultyClass" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->difficultyClass_parser_;

    if (this->difficultyClass_parser_)
      this->difficultyClass_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Combat_Check_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Combat_CheckTypeUnion_Type ());

    return true;
  }

  if (n == "attribute" && ns == "urn:rpg")
  {
    if (this->attribute_parser_)
      this->attribute (this->attribute_parser_->post_RPG_Common_Attribute_Type ());

    return true;
  }

  if (n == "difficultyClass" && ns == "urn:rpg")
  {
    if (this->difficultyClass_parser_)
      this->difficultyClass (this->difficultyClass_parser_->post_unsigned_byte ());

    return true;
  }

  return false;
}

// RPG_Combat_DamageCounterMeasure_Type_pskel
//

void RPG_Combat_DamageCounterMeasure_Type_pskel::
type (const RPG_Common_CounterMeasure&)
{
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
check (const RPG_Combat_Check&)
{
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
spell ()
{
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
duration ()
{
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
condition (const RPG_Common_Condition&)
{
}

void RPG_Combat_DamageCounterMeasure_Type_pskel::
reduction (const RPG_Combat_DamageReductionType&)
{
}

bool RPG_Combat_DamageCounterMeasure_Type_pskel::
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

  if (n == "check" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->check_parser_;

    if (this->check_parser_)
      this->check_parser_->pre ();

    return true;
  }

  if (n == "spell" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->spell_parser_;

    if (this->spell_parser_)
      this->spell_parser_->pre ();

    return true;
  }

  if (n == "duration" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->duration_parser_;

    if (this->duration_parser_)
      this->duration_parser_->pre ();

    return true;
  }

  if (n == "condition" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->condition_parser_;

    if (this->condition_parser_)
      this->condition_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Combat_DamageCounterMeasure_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Common_CounterMeasure_Type ());

    return true;
  }

  if (n == "check" && ns == "urn:rpg")
  {
    if (this->check_parser_)
      this->check (this->check_parser_->post_RPG_Combat_Check_Type ());

    return true;
  }

  if (n == "spell" && ns == "urn:rpg")
  {
    if (this->spell_parser_)
    {
      this->spell_parser_->post_RPG_Magic_SpellType_Type ();
      this->spell ();
    }

    return true;
  }

  if (n == "duration" && ns == "urn:rpg")
  {
    if (this->duration_parser_)
    {
      this->duration_parser_->post_RPG_Common_Duration_Type ();
      this->duration ();
    }

    return true;
  }

  if (n == "condition" && ns == "urn:rpg")
  {
    if (this->condition_parser_)
      this->condition (this->condition_parser_->post_RPG_Common_Condition_Type ());

    return true;
  }

  return false;
}

bool RPG_Combat_DamageCounterMeasure_Type_pskel::
_attribute_impl (const ::xml_schema::ro_string& ns,
                 const ::xml_schema::ro_string& n,
                 const ::xml_schema::ro_string& v)
{
  if (this->::xml_schema::complex_content::_attribute_impl (ns, n, v))
    return true;

  if (n == "reduction" && ns.empty ())
  {
    if (this->reduction_parser_)
    {
      this->reduction_parser_->pre ();
      this->reduction_parser_->_pre_impl ();
      this->reduction_parser_->_characters (v);
      this->reduction_parser_->_post_impl ();
      this->reduction (this->reduction_parser_->post_RPG_Combat_DamageReductionType_Type ());
    }

    return true;
  }

  return false;
}

// RPG_Combat_OtherDamage_Type_pskel
//

void RPG_Combat_OtherDamage_Type_pskel::
type (const RPG_Combat_OtherDamageType&)
{
}

void RPG_Combat_OtherDamage_Type_pskel::
modifier (signed char)
{
}

void RPG_Combat_OtherDamage_Type_pskel::
counterMeasure (const RPG_Combat_DamageCounterMeasure&)
{
}

bool RPG_Combat_OtherDamage_Type_pskel::
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

  if (n == "counterMeasure" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->counterMeasure_parser_;

    if (this->counterMeasure_parser_)
      this->counterMeasure_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Combat_OtherDamage_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Combat_OtherDamageType_Type ());

    return true;
  }

  if (n == "modifier" && ns == "urn:rpg")
  {
    if (this->modifier_parser_)
      this->modifier (this->modifier_parser_->post_byte ());

    return true;
  }

  if (n == "counterMeasure" && ns == "urn:rpg")
  {
    if (this->counterMeasure_parser_)
      this->counterMeasure (this->counterMeasure_parser_->post_RPG_Combat_DamageCounterMeasure_Type ());

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
secondary (const RPG_Dice_Roll&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
attribute (const RPG_Common_Attribute&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
condition (const RPG_Common_Condition&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
duration (const RPG_Combat_DamageDuration&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
counterMeasure (const RPG_Combat_DamageCounterMeasure&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
other (const RPG_Combat_OtherDamage&)
{
}

void RPG_Combat_DamageElement_Type_pskel::
effect (const RPG_Common_EffectType&)
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

  if (n == "secondary" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->secondary_parser_;

    if (this->secondary_parser_)
      this->secondary_parser_->pre ();

    return true;
  }

  if (n == "attribute" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->attribute_parser_;

    if (this->attribute_parser_)
      this->attribute_parser_->pre ();

    return true;
  }

  if (n == "condition" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->condition_parser_;

    if (this->condition_parser_)
      this->condition_parser_->pre ();

    return true;
  }

  if (n == "duration" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->duration_parser_;

    if (this->duration_parser_)
      this->duration_parser_->pre ();

    return true;
  }

  if (n == "counterMeasure" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->counterMeasure_parser_;

    if (this->counterMeasure_parser_)
      this->counterMeasure_parser_->pre ();

    return true;
  }

  if (n == "other" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->other_parser_;

    if (this->other_parser_)
      this->other_parser_->pre ();

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

  if (n == "secondary" && ns == "urn:rpg")
  {
    if (this->secondary_parser_)
      this->secondary (this->secondary_parser_->post_RPG_Dice_Roll_Type ());

    return true;
  }

  if (n == "attribute" && ns == "urn:rpg")
  {
    if (this->attribute_parser_)
      this->attribute (this->attribute_parser_->post_RPG_Common_Attribute_Type ());

    return true;
  }

  if (n == "condition" && ns == "urn:rpg")
  {
    if (this->condition_parser_)
      this->condition (this->condition_parser_->post_RPG_Common_Condition_Type ());

    return true;
  }

  if (n == "duration" && ns == "urn:rpg")
  {
    if (this->duration_parser_)
      this->duration (this->duration_parser_->post_RPG_Combat_DamageDuration_Type ());

    return true;
  }

  if (n == "counterMeasure" && ns == "urn:rpg")
  {
    if (this->counterMeasure_parser_)
      this->counterMeasure (this->counterMeasure_parser_->post_RPG_Combat_DamageCounterMeasure_Type ());

    return true;
  }

  if (n == "other" && ns == "urn:rpg")
  {
    if (this->other_parser_)
      this->other (this->other_parser_->post_RPG_Combat_OtherDamage_Type ());

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
      this->effect (this->effect_parser_->post_RPG_Common_EffectType_Type ());
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

void RPG_Combat_Damage_Type_pskel::
elementsAreInclusive (bool)
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

bool RPG_Combat_Damage_Type_pskel::
_attribute_impl (const ::xml_schema::ro_string& ns,
                 const ::xml_schema::ro_string& n,
                 const ::xml_schema::ro_string& v)
{
  if (this->::xml_schema::complex_content::_attribute_impl (ns, n, v))
    return true;

  if (n == "elementsAreInclusive" && ns.empty ())
  {
    if (this->elementsAreInclusive_parser_)
    {
      this->elementsAreInclusive_parser_->pre ();
      this->elementsAreInclusive_parser_->_pre_impl ();
      this->elementsAreInclusive_parser_->_characters (v);
      this->elementsAreInclusive_parser_->_post_impl ();
      this->elementsAreInclusive (this->elementsAreInclusive_parser_->post_boolean ());
    }

    return true;
  }

  return false;
}

// Begin epilogue.
//
//
// End epilogue.

