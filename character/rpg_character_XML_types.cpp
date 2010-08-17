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

#include "rpg_character_XML_types.h"

// RPG_Character_ClassXML_Type_pskel
//

void RPG_Character_ClassXML_Type_pskel::
metaClass_parser (::RPG_Character_MetaClass_Type_pskel& p)
{
  this->metaClass_parser_ = &p;
}

void RPG_Character_ClassXML_Type_pskel::
subClass_parser (::RPG_Common_SubClass_Type_pskel& p)
{
  this->subClass_parser_ = &p;
}

void RPG_Character_ClassXML_Type_pskel::
parsers (::RPG_Character_MetaClass_Type_pskel& metaClass,
         ::RPG_Common_SubClass_Type_pskel& subClass)
{
  this->metaClass_parser_ = &metaClass;
  this->subClass_parser_ = &subClass;
}

RPG_Character_ClassXML_Type_pskel::
RPG_Character_ClassXML_Type_pskel ()
: metaClass_parser_ (0),
  subClass_parser_ (0)
{
}

// RPG_Character_Attributes_Type_pskel
//

void RPG_Character_Attributes_Type_pskel::
strength_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->strength_parser_ = &p;
}

void RPG_Character_Attributes_Type_pskel::
dexterity_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->dexterity_parser_ = &p;
}

void RPG_Character_Attributes_Type_pskel::
constitution_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->constitution_parser_ = &p;
}

void RPG_Character_Attributes_Type_pskel::
intelligence_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->intelligence_parser_ = &p;
}

void RPG_Character_Attributes_Type_pskel::
wisdom_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->wisdom_parser_ = &p;
}

void RPG_Character_Attributes_Type_pskel::
charisma_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->charisma_parser_ = &p;
}

void RPG_Character_Attributes_Type_pskel::
parsers (::xml_schema::unsigned_byte_pskel& strength,
         ::xml_schema::unsigned_byte_pskel& dexterity,
         ::xml_schema::unsigned_byte_pskel& constitution,
         ::xml_schema::unsigned_byte_pskel& intelligence,
         ::xml_schema::unsigned_byte_pskel& wisdom,
         ::xml_schema::unsigned_byte_pskel& charisma)
{
  this->strength_parser_ = &strength;
  this->dexterity_parser_ = &dexterity;
  this->constitution_parser_ = &constitution;
  this->intelligence_parser_ = &intelligence;
  this->wisdom_parser_ = &wisdom;
  this->charisma_parser_ = &charisma;
}

RPG_Character_Attributes_Type_pskel::
RPG_Character_Attributes_Type_pskel ()
: strength_parser_ (0),
  dexterity_parser_ (0),
  constitution_parser_ (0),
  intelligence_parser_ (0),
  wisdom_parser_ (0),
  charisma_parser_ (0)
{
}

// RPG_Character_SkillValue_Type_pskel
//

void RPG_Character_SkillValue_Type_pskel::
skill_parser (::RPG_Common_Skill_Type_pskel& p)
{
  this->skill_parser_ = &p;
}

void RPG_Character_SkillValue_Type_pskel::
rank_parser (::xml_schema::byte_pskel& p)
{
  this->rank_parser_ = &p;
}

void RPG_Character_SkillValue_Type_pskel::
parsers (::RPG_Common_Skill_Type_pskel& skill,
         ::xml_schema::byte_pskel& rank)
{
  this->skill_parser_ = &skill;
  this->rank_parser_ = &rank;
}

RPG_Character_SkillValue_Type_pskel::
RPG_Character_SkillValue_Type_pskel ()
: skill_parser_ (0),
  rank_parser_ (0)
{
}

// RPG_Character_Skills_Type_pskel
//

void RPG_Character_Skills_Type_pskel::
skill_parser (::RPG_Character_SkillValue_Type_pskel& p)
{
  this->skill_parser_ = &p;
}

void RPG_Character_Skills_Type_pskel::
parsers (::RPG_Character_SkillValue_Type_pskel& skill)
{
  this->skill_parser_ = &skill;
}

RPG_Character_Skills_Type_pskel::
RPG_Character_Skills_Type_pskel ()
: skill_parser_ (0)
{
}

// RPG_Character_Check_Type_pskel
//

void RPG_Character_Check_Type_pskel::
type_parser (::RPG_Character_CheckTypeUnion_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Character_Check_Type_pskel::
difficultyClass_parser (::xml_schema::unsigned_byte_pskel& p)
{
  this->difficultyClass_parser_ = &p;
}

void RPG_Character_Check_Type_pskel::
parsers (::RPG_Character_CheckTypeUnion_Type_pskel& type,
         ::xml_schema::unsigned_byte_pskel& difficultyClass)
{
  this->type_parser_ = &type;
  this->difficultyClass_parser_ = &difficultyClass;
}

RPG_Character_Check_Type_pskel::
RPG_Character_Check_Type_pskel ()
: type_parser_ (0),
  difficultyClass_parser_ (0)
{
}

// RPG_Character_Feats_Type_pskel
//

void RPG_Character_Feats_Type_pskel::
feat_parser (::RPG_Character_Feat_Type_pskel& p)
{
  this->feat_parser_ = &p;
}

void RPG_Character_Feats_Type_pskel::
parsers (::RPG_Character_Feat_Type_pskel& feat)
{
  this->feat_parser_ = &feat;
}

RPG_Character_Feats_Type_pskel::
RPG_Character_Feats_Type_pskel ()
: feat_parser_ (0)
{
}

// RPG_Character_Alignment_Type_pskel
//

void RPG_Character_Alignment_Type_pskel::
civic_parser (::RPG_Character_AlignmentCivic_Type_pskel& p)
{
  this->civic_parser_ = &p;
}

void RPG_Character_Alignment_Type_pskel::
ethic_parser (::RPG_Character_AlignmentEthic_Type_pskel& p)
{
  this->ethic_parser_ = &p;
}

void RPG_Character_Alignment_Type_pskel::
parsers (::RPG_Character_AlignmentCivic_Type_pskel& civic,
         ::RPG_Character_AlignmentEthic_Type_pskel& ethic)
{
  this->civic_parser_ = &civic;
  this->ethic_parser_ = &ethic;
}

RPG_Character_Alignment_Type_pskel::
RPG_Character_Alignment_Type_pskel ()
: civic_parser_ (0),
  ethic_parser_ (0)
{
}

// RPG_Character_ClassXML_Type_pskel
//

void RPG_Character_ClassXML_Type_pskel::
metaClass (const RPG_Character_MetaClass&)
{
}

void RPG_Character_ClassXML_Type_pskel::
subClass (const RPG_Common_SubClass&)
{
}

bool RPG_Character_ClassXML_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "metaClass" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->metaClass_parser_;

    if (this->metaClass_parser_)
      this->metaClass_parser_->pre ();

    return true;
  }

  if (n == "subClass" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->subClass_parser_;

    if (this->subClass_parser_)
      this->subClass_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Character_ClassXML_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "metaClass" && ns == "urn:rpg")
  {
    if (this->metaClass_parser_)
      this->metaClass (this->metaClass_parser_->post_RPG_Character_MetaClass_Type ());

    return true;
  }

  if (n == "subClass" && ns == "urn:rpg")
  {
    if (this->subClass_parser_)
      this->subClass (this->subClass_parser_->post_RPG_Common_SubClass_Type ());

    return true;
  }

  return false;
}

// RPG_Character_Attributes_Type_pskel
//

void RPG_Character_Attributes_Type_pskel::
strength (unsigned char)
{
}

void RPG_Character_Attributes_Type_pskel::
dexterity (unsigned char)
{
}

void RPG_Character_Attributes_Type_pskel::
constitution (unsigned char)
{
}

void RPG_Character_Attributes_Type_pskel::
intelligence (unsigned char)
{
}

void RPG_Character_Attributes_Type_pskel::
wisdom (unsigned char)
{
}

void RPG_Character_Attributes_Type_pskel::
charisma (unsigned char)
{
}

bool RPG_Character_Attributes_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "strength" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->strength_parser_;

    if (this->strength_parser_)
      this->strength_parser_->pre ();

    return true;
  }

  if (n == "dexterity" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->dexterity_parser_;

    if (this->dexterity_parser_)
      this->dexterity_parser_->pre ();

    return true;
  }

  if (n == "constitution" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->constitution_parser_;

    if (this->constitution_parser_)
      this->constitution_parser_->pre ();

    return true;
  }

  if (n == "intelligence" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->intelligence_parser_;

    if (this->intelligence_parser_)
      this->intelligence_parser_->pre ();

    return true;
  }

  if (n == "wisdom" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->wisdom_parser_;

    if (this->wisdom_parser_)
      this->wisdom_parser_->pre ();

    return true;
  }

  if (n == "charisma" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->charisma_parser_;

    if (this->charisma_parser_)
      this->charisma_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Character_Attributes_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "strength" && ns == "urn:rpg")
  {
    if (this->strength_parser_)
      this->strength (this->strength_parser_->post_unsigned_byte ());

    return true;
  }

  if (n == "dexterity" && ns == "urn:rpg")
  {
    if (this->dexterity_parser_)
      this->dexterity (this->dexterity_parser_->post_unsigned_byte ());

    return true;
  }

  if (n == "constitution" && ns == "urn:rpg")
  {
    if (this->constitution_parser_)
      this->constitution (this->constitution_parser_->post_unsigned_byte ());

    return true;
  }

  if (n == "intelligence" && ns == "urn:rpg")
  {
    if (this->intelligence_parser_)
      this->intelligence (this->intelligence_parser_->post_unsigned_byte ());

    return true;
  }

  if (n == "wisdom" && ns == "urn:rpg")
  {
    if (this->wisdom_parser_)
      this->wisdom (this->wisdom_parser_->post_unsigned_byte ());

    return true;
  }

  if (n == "charisma" && ns == "urn:rpg")
  {
    if (this->charisma_parser_)
      this->charisma (this->charisma_parser_->post_unsigned_byte ());

    return true;
  }

  return false;
}

// RPG_Character_SkillValue_Type_pskel
//

void RPG_Character_SkillValue_Type_pskel::
skill (const RPG_Common_Skill&)
{
}

void RPG_Character_SkillValue_Type_pskel::
rank (signed char)
{
}

bool RPG_Character_SkillValue_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "skill" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->skill_parser_;

    if (this->skill_parser_)
      this->skill_parser_->pre ();

    return true;
  }

  if (n == "rank" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->rank_parser_;

    if (this->rank_parser_)
      this->rank_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Character_SkillValue_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "skill" && ns == "urn:rpg")
  {
    if (this->skill_parser_)
      this->skill (this->skill_parser_->post_RPG_Common_Skill_Type ());

    return true;
  }

  if (n == "rank" && ns == "urn:rpg")
  {
    if (this->rank_parser_)
      this->rank (this->rank_parser_->post_byte ());

    return true;
  }

  return false;
}

// RPG_Character_Skills_Type_pskel
//

void RPG_Character_Skills_Type_pskel::
skill (const RPG_Character_SkillValue&)
{
}

bool RPG_Character_Skills_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "skill" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->skill_parser_;

    if (this->skill_parser_)
      this->skill_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Character_Skills_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "skill" && ns == "urn:rpg")
  {
    if (this->skill_parser_)
      this->skill (this->skill_parser_->post_RPG_Character_SkillValue_Type ());

    return true;
  }

  return false;
}

// RPG_Character_Check_Type_pskel
//

void RPG_Character_Check_Type_pskel::
type (const RPG_Character_CheckTypeUnion&)
{
}

void RPG_Character_Check_Type_pskel::
difficultyClass (unsigned char)
{
}

bool RPG_Character_Check_Type_pskel::
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

  if (n == "difficultyClass" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->difficultyClass_parser_;

    if (this->difficultyClass_parser_)
      this->difficultyClass_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Character_Check_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Character_CheckTypeUnion_Type ());

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

// RPG_Character_Feats_Type_pskel
//

void RPG_Character_Feats_Type_pskel::
feat (const RPG_Character_Feat&)
{
}

bool RPG_Character_Feats_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "feat" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->feat_parser_;

    if (this->feat_parser_)
      this->feat_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Character_Feats_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "feat" && ns == "urn:rpg")
  {
    if (this->feat_parser_)
      this->feat (this->feat_parser_->post_RPG_Character_Feat_Type ());

    return true;
  }

  return false;
}

// RPG_Character_Alignment_Type_pskel
//

void RPG_Character_Alignment_Type_pskel::
civic (const RPG_Character_AlignmentCivic&)
{
}

void RPG_Character_Alignment_Type_pskel::
ethic (const RPG_Character_AlignmentEthic&)
{
}

bool RPG_Character_Alignment_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "civic" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->civic_parser_;

    if (this->civic_parser_)
      this->civic_parser_->pre ();

    return true;
  }

  if (n == "ethic" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->ethic_parser_;

    if (this->ethic_parser_)
      this->ethic_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Character_Alignment_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "civic" && ns == "urn:rpg")
  {
    if (this->civic_parser_)
      this->civic (this->civic_parser_->post_RPG_Character_AlignmentCivic_Type ());

    return true;
  }

  if (n == "ethic" && ns == "urn:rpg")
  {
    if (this->ethic_parser_)
      this->ethic (this->ethic_parser_->post_RPG_Character_AlignmentEthic_Type ());

    return true;
  }

  return false;
}

// Begin epilogue.
//
//
// End epilogue.

