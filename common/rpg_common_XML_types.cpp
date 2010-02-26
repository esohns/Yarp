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

#include "rpg_common_XML_types.h"

// RPG_Common_CreatureType_Type_pskel
//

void RPG_Common_CreatureType_Type_pskel::
metaType_parser (::RPG_Common_CreatureMetaType_Type_pskel& p)
{
  this->metaType_parser_ = &p;
}

void RPG_Common_CreatureType_Type_pskel::
subType_parser (::RPG_Common_CreatureSubType_Type_pskel& p)
{
  this->subType_parser_ = &p;
}

void RPG_Common_CreatureType_Type_pskel::
parsers (::RPG_Common_CreatureMetaType_Type_pskel& metaType,
         ::RPG_Common_CreatureSubType_Type_pskel& subType)
{
  this->metaType_parser_ = &metaType;
  this->subType_parser_ = &subType;
}

RPG_Common_CreatureType_Type_pskel::
RPG_Common_CreatureType_Type_pskel ()
: metaType_parser_ (0),
  subType_parser_ (0)
{
}

// RPG_Common_SavingThrowCheck_Type_pskel
//

void RPG_Common_SavingThrowCheck_Type_pskel::
type_parser (::RPG_Common_SavingThrow_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Common_SavingThrowCheck_Type_pskel::
attribute_parser (::RPG_Common_Attribute_Type_pskel& p)
{
  this->attribute_parser_ = &p;
}

void RPG_Common_SavingThrowCheck_Type_pskel::
difficultyClass_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->difficultyClass_parser_ = &p;
}

void RPG_Common_SavingThrowCheck_Type_pskel::
reduction_parser (::RPG_Common_SaveReductionType_Type_pskel& p)
{
  this->reduction_parser_ = &p;
}

void RPG_Common_SavingThrowCheck_Type_pskel::
parsers (::RPG_Common_SavingThrow_Type_pskel& type,
         ::RPG_Common_Attribute_Type_pskel& attribute,
         ::xml_schema::unsigned_byte_pskel& difficultyClass,
         ::RPG_Common_SaveReductionType_Type_pskel& reduction)
{
  this->type_parser_ = &type;
  this->attribute_parser_ = &attribute;
  this->difficultyClass_parser_ = &difficultyClass;
  this->reduction_parser_ = &reduction;
}

RPG_Common_SavingThrowCheck_Type_pskel::
RPG_Common_SavingThrowCheck_Type_pskel ()
: type_parser_ (0),
  attribute_parser_ (0),
  difficultyClass_parser_ (0),
  reduction_parser_ (0)
{
}

// RPG_Common_Amount_Type_pskel
//

void RPG_Common_Amount_Type_pskel::
value_parser (::xml_schema::byte_pskel& p)
{
  this->value_parser_ = &p;
}

void RPG_Common_Amount_Type_pskel::
range_parser (::RPG_Dice_Roll_Type_pskel& p)
{
  this->range_parser_ = &p;
}

void RPG_Common_Amount_Type_pskel::
parsers (::xml_schema::byte_pskel& value,
         ::RPG_Dice_Roll_Type_pskel& range)
{
  this->value_parser_ = &value;
  this->range_parser_ = &range;
}

RPG_Common_Amount_Type_pskel::
RPG_Common_Amount_Type_pskel ()
: value_parser_ (0),
  range_parser_ (0)
{
}

// RPG_Common_Usage_Type_pskel
//

void RPG_Common_Usage_Type_pskel::
numUses_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->numUses_parser_ = &p;
}

void RPG_Common_Usage_Type_pskel::
period_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->period_parser_ = &p;
}

void RPG_Common_Usage_Type_pskel::
interval_parser (::RPG_Dice_Roll_Type_pskel& p)
{
  this->interval_parser_ = &p;
}

void RPG_Common_Usage_Type_pskel::
parsers (::xml_schema::unsigned_byte_pskel& numUses,
         ::xml_schema::unsigned_int_pskel& period,
         ::RPG_Dice_Roll_Type_pskel& interval)
{
  this->numUses_parser_ = &numUses;
  this->period_parser_ = &period;
  this->interval_parser_ = &interval;
}

RPG_Common_Usage_Type_pskel::
RPG_Common_Usage_Type_pskel ()
: numUses_parser_ (0),
  period_parser_ (0),
  interval_parser_ (0)
{
}

// RPG_Common_Duration_Type_pskel
//

void RPG_Common_Duration_Type_pskel::
activation_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->activation_parser_ = &p;
}

void RPG_Common_Duration_Type_pskel::
interval_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->interval_parser_ = &p;
}

void RPG_Common_Duration_Type_pskel::
total_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->total_parser_ = &p;
}

void RPG_Common_Duration_Type_pskel::
parsers (::xml_schema::unsigned_int_pskel& activation,
         ::xml_schema::unsigned_int_pskel& interval,
         ::xml_schema::unsigned_int_pskel& total)
{
  this->activation_parser_ = &activation;
  this->interval_parser_ = &interval;
  this->total_parser_ = &total;
}

RPG_Common_Duration_Type_pskel::
RPG_Common_Duration_Type_pskel ()
: activation_parser_ (0),
  interval_parser_ (0),
  total_parser_ (0)
{
}

// RPG_Common_CreatureType_Type_pskel
//

void RPG_Common_CreatureType_Type_pskel::
metaType (const RPG_Common_CreatureMetaType&)
{
}

void RPG_Common_CreatureType_Type_pskel::
subType (const RPG_Common_CreatureSubType&)
{
}

bool RPG_Common_CreatureType_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "metaType" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->metaType_parser_;

    if (this->metaType_parser_)
      this->metaType_parser_->pre ();

    return true;
  }

  if (n == "subType" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->subType_parser_;

    if (this->subType_parser_)
      this->subType_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Common_CreatureType_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "metaType" && ns == "urn:rpg")
  {
    if (this->metaType_parser_)
      this->metaType (this->metaType_parser_->post_RPG_Common_CreatureMetaType_Type ());

    return true;
  }

  if (n == "subType" && ns == "urn:rpg")
  {
    if (this->subType_parser_)
      this->subType (this->subType_parser_->post_RPG_Common_CreatureSubType_Type ());

    return true;
  }

  return false;
}

// RPG_Common_SavingThrowCheck_Type_pskel
//

void RPG_Common_SavingThrowCheck_Type_pskel::
type (const RPG_Common_SavingThrow&)
{
}

void RPG_Common_SavingThrowCheck_Type_pskel::
attribute (const RPG_Common_Attribute&)
{
}

void RPG_Common_SavingThrowCheck_Type_pskel::
difficultyClass (unsigned char)
{
}

void RPG_Common_SavingThrowCheck_Type_pskel::
reduction (const RPG_Common_SaveReductionType&)
{
}

bool RPG_Common_SavingThrowCheck_Type_pskel::
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

bool RPG_Common_SavingThrowCheck_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Common_SavingThrow_Type ());

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

bool RPG_Common_SavingThrowCheck_Type_pskel::
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
      this->reduction (this->reduction_parser_->post_RPG_Common_SaveReductionType_Type ());
    }

    return true;
  }

  return false;
}

// RPG_Common_Amount_Type_pskel
//

void RPG_Common_Amount_Type_pskel::
value (signed char)
{
}

void RPG_Common_Amount_Type_pskel::
range (const RPG_Dice_Roll&)
{
}

bool RPG_Common_Amount_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "value" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->value_parser_;

    if (this->value_parser_)
      this->value_parser_->pre ();

    return true;
  }

  if (n == "range" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->range_parser_;

    if (this->range_parser_)
      this->range_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Common_Amount_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "value" && ns == "urn:rpg")
  {
    if (this->value_parser_)
      this->value (this->value_parser_->post_byte ());

    return true;
  }

  if (n == "range" && ns == "urn:rpg")
  {
    if (this->range_parser_)
      this->range (this->range_parser_->post_RPG_Dice_Roll_Type ());

    return true;
  }

  return false;
}

// RPG_Common_Usage_Type_pskel
//

void RPG_Common_Usage_Type_pskel::
numUses (unsigned char)
{
}

void RPG_Common_Usage_Type_pskel::
period (unsigned int)
{
}

void RPG_Common_Usage_Type_pskel::
interval (const RPG_Dice_Roll&)
{
}

bool RPG_Common_Usage_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "numUses" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->numUses_parser_;

    if (this->numUses_parser_)
      this->numUses_parser_->pre ();

    return true;
  }

  if (n == "period" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->period_parser_;

    if (this->period_parser_)
      this->period_parser_->pre ();

    return true;
  }

  if (n == "interval" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->interval_parser_;

    if (this->interval_parser_)
      this->interval_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Common_Usage_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "numUses" && ns == "urn:rpg")
  {
    if (this->numUses_parser_)
      this->numUses (this->numUses_parser_->post_unsigned_byte ());

    return true;
  }

  if (n == "period" && ns == "urn:rpg")
  {
    if (this->period_parser_)
      this->period (this->period_parser_->post_unsigned_int ());

    return true;
  }

  if (n == "interval" && ns == "urn:rpg")
  {
    if (this->interval_parser_)
      this->interval (this->interval_parser_->post_RPG_Dice_Roll_Type ());

    return true;
  }

  return false;
}

// RPG_Common_Duration_Type_pskel
//

void RPG_Common_Duration_Type_pskel::
activation (unsigned int)
{
}

void RPG_Common_Duration_Type_pskel::
interval (unsigned int)
{
}

void RPG_Common_Duration_Type_pskel::
total (unsigned int)
{
}

bool RPG_Common_Duration_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "activation" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->activation_parser_;

    if (this->activation_parser_)
      this->activation_parser_->pre ();

    return true;
  }

  if (n == "interval" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->interval_parser_;

    if (this->interval_parser_)
      this->interval_parser_->pre ();

    return true;
  }

  if (n == "total" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->total_parser_;

    if (this->total_parser_)
      this->total_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Common_Duration_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "activation" && ns == "urn:rpg")
  {
    if (this->activation_parser_)
      this->activation (this->activation_parser_->post_unsigned_int ());

    return true;
  }

  if (n == "interval" && ns == "urn:rpg")
  {
    if (this->interval_parser_)
      this->interval (this->interval_parser_->post_unsigned_int ());

    return true;
  }

  if (n == "total" && ns == "urn:rpg")
  {
    if (this->total_parser_)
      this->total (this->total_parser_->post_unsigned_int ());

    return true;
  }

  return false;
}

// Begin epilogue.
//
//
// End epilogue.

