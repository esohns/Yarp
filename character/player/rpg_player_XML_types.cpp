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

// Begin prologue.
//
#include "stdafx.h"
//
// End prologue.

#include "rpg_player_XML_types.h"

// RPG_Player_Abilities_Type_pskel
//

void RPG_Player_Abilities_Type_pskel::
ability_parser (::RPG_Character_Ability_Type_pskel& p)
{
  this->ability_parser_ = &p;
}

void RPG_Player_Abilities_Type_pskel::
parsers (::RPG_Character_Ability_Type_pskel& ability)
{
  this->ability_parser_ = &ability;
}

RPG_Player_Abilities_Type_pskel::
RPG_Player_Abilities_Type_pskel ()
: ability_parser_ (0)
{
}

// RPG_Player_Conditions_Type_pskel
//

void RPG_Player_Conditions_Type_pskel::
condition_parser (::RPG_Common_Condition_Type_pskel& p)
{
  this->condition_parser_ = &p;
}

void RPG_Player_Conditions_Type_pskel::
parsers (::RPG_Common_Condition_Type_pskel& condition)
{
  this->condition_parser_ = &condition;
}

RPG_Player_Conditions_Type_pskel::
RPG_Player_Conditions_Type_pskel ()
: condition_parser_ (0)
{
}

// RPG_Player_Spells_Type_pskel
//

void RPG_Player_Spells_Type_pskel::
spell_parser (::RPG_Magic_SpellType_Type_pskel& p)
{
  this->spell_parser_ = &p;
}

void RPG_Player_Spells_Type_pskel::
parsers (::RPG_Magic_SpellType_Type_pskel& spell)
{
  this->spell_parser_ = &spell;
}

RPG_Player_Spells_Type_pskel::
RPG_Player_Spells_Type_pskel ()
: spell_parser_ (0)
{
}

// RPG_Player_CharacterBaseXML_Type_pskel
//

void RPG_Player_CharacterBaseXML_Type_pskel::
name_parser (::xml_schema::string_pskel& p)
{
  this->name_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
abilities_parser (::RPG_Player_Abilities_Type_pskel& p)
{
  this->abilities_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
alignment_parser (::RPG_Character_Alignment_Type_pskel& p)
{
  this->alignment_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
attributes_parser (::RPG_Character_Attributes_Type_pskel& p)
{
  this->attributes_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
defaultSize_parser (::RPG_Common_Size_Type_pskel& p)
{
  this->defaultSize_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
feats_parser (::RPG_Character_Feats_Type_pskel& p)
{
  this->feats_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
knownSpells_parser (::RPG_Player_Spells_Type_pskel& p)
{
  this->knownSpells_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
maxHP_parser (::xml_schema::unsigned_short_pskel& p)
{
  this->maxHP_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
skills_parser (::RPG_Character_Skills_Type_pskel& p)
{
  this->skills_parser_ = &p;
}

void RPG_Player_CharacterBaseXML_Type_pskel::
parsers (::xml_schema::string_pskel& name,
         ::RPG_Player_Abilities_Type_pskel& abilities,
         ::RPG_Character_Alignment_Type_pskel& alignment,
         ::RPG_Character_Attributes_Type_pskel& attributes,
         ::RPG_Common_Size_Type_pskel& defaultSize,
         ::RPG_Character_Feats_Type_pskel& feats,
         ::RPG_Player_Spells_Type_pskel& knownSpells,
         ::xml_schema::unsigned_short_pskel& maxHP,
         ::RPG_Character_Skills_Type_pskel& skills)
{
  this->name_parser_ = &name;
  this->abilities_parser_ = &abilities;
  this->alignment_parser_ = &alignment;
  this->attributes_parser_ = &attributes;
  this->defaultSize_parser_ = &defaultSize;
  this->feats_parser_ = &feats;
  this->knownSpells_parser_ = &knownSpells;
  this->maxHP_parser_ = &maxHP;
  this->skills_parser_ = &skills;
}

RPG_Player_CharacterBaseXML_Type_pskel::
RPG_Player_CharacterBaseXML_Type_pskel ()
: name_parser_ (0),
  abilities_parser_ (0),
  alignment_parser_ (0),
  attributes_parser_ (0),
  defaultSize_parser_ (0),
  feats_parser_ (0),
  knownSpells_parser_ (0),
  maxHP_parser_ (0),
  skills_parser_ (0)
{
}

// RPG_Player_CharacterXML_Type_pskel
//

void RPG_Player_CharacterXML_Type_pskel::
classXML_parser (::RPG_Character_ClassXML_Type_pskel& p)
{
  this->classXML_parser_ = &p;
}

void RPG_Player_CharacterXML_Type_pskel::
gender_parser (::RPG_Character_Gender_Type_pskel& p)
{
  this->gender_parser_ = &p;
}

void RPG_Player_CharacterXML_Type_pskel::
offhand_parser (::RPG_Character_OffHand_Type_pskel& p)
{
  this->offhand_parser_ = &p;
}

void RPG_Player_CharacterXML_Type_pskel::
race_parser (::RPG_Character_Race_Type_pskel& p)
{
  this->race_parser_ = &p;
}

void RPG_Player_CharacterXML_Type_pskel::
parsers (::xml_schema::string_pskel& name,
         ::RPG_Player_Abilities_Type_pskel& abilities,
         ::RPG_Character_Alignment_Type_pskel& alignment,
         ::RPG_Character_Attributes_Type_pskel& attributes,
         ::RPG_Common_Size_Type_pskel& defaultSize,
         ::RPG_Character_Feats_Type_pskel& feats,
         ::RPG_Player_Spells_Type_pskel& knownSpells,
         ::xml_schema::unsigned_short_pskel& maxHP,
         ::RPG_Character_Skills_Type_pskel& skills,
         ::RPG_Character_ClassXML_Type_pskel& classXML,
         ::RPG_Character_Gender_Type_pskel& gender,
         ::RPG_Character_OffHand_Type_pskel& offhand,
         ::RPG_Character_Race_Type_pskel& race)
{
  this->name_parser_ = &name;
  this->abilities_parser_ = &abilities;
  this->alignment_parser_ = &alignment;
  this->attributes_parser_ = &attributes;
  this->defaultSize_parser_ = &defaultSize;
  this->feats_parser_ = &feats;
  this->knownSpells_parser_ = &knownSpells;
  this->maxHP_parser_ = &maxHP;
  this->skills_parser_ = &skills;
  this->classXML_parser_ = &classXML;
  this->gender_parser_ = &gender;
  this->offhand_parser_ = &offhand;
  this->race_parser_ = &race;
}

RPG_Player_CharacterXML_Type_pskel::
RPG_Player_CharacterXML_Type_pskel ()
: classXML_parser_ (0),
  gender_parser_ (0),
  offhand_parser_ (0),
  race_parser_ (0)
{
}

// RPG_Player_PlayerXML_Type_pskel
//

void RPG_Player_PlayerXML_Type_pskel::
gold_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->gold_parser_ = &p;
}

void RPG_Player_PlayerXML_Type_pskel::
inventory_parser (::RPG_Item_InventoryXML_Type_pskel& p)
{
  this->inventory_parser_ = &p;
}

void RPG_Player_PlayerXML_Type_pskel::
XP_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->XP_parser_ = &p;
}

void RPG_Player_PlayerXML_Type_pskel::
parsers (::xml_schema::string_pskel& name,
         ::RPG_Player_Abilities_Type_pskel& abilities,
         ::RPG_Character_Alignment_Type_pskel& alignment,
         ::RPG_Character_Attributes_Type_pskel& attributes,
         ::RPG_Common_Size_Type_pskel& defaultSize,
         ::RPG_Character_Feats_Type_pskel& feats,
         ::RPG_Player_Spells_Type_pskel& knownSpells,
         ::xml_schema::unsigned_short_pskel& maxHP,
         ::RPG_Character_Skills_Type_pskel& skills,
         ::RPG_Character_ClassXML_Type_pskel& classXML,
         ::RPG_Character_Gender_Type_pskel& gender,
         ::RPG_Character_OffHand_Type_pskel& offhand,
         ::RPG_Character_Race_Type_pskel& race,
         ::xml_schema::unsigned_int_pskel& gold,
         ::RPG_Item_InventoryXML_Type_pskel& inventory,
         ::xml_schema::unsigned_int_pskel& XP)
{
  this->name_parser_ = &name;
  this->abilities_parser_ = &abilities;
  this->alignment_parser_ = &alignment;
  this->attributes_parser_ = &attributes;
  this->defaultSize_parser_ = &defaultSize;
  this->feats_parser_ = &feats;
  this->knownSpells_parser_ = &knownSpells;
  this->maxHP_parser_ = &maxHP;
  this->skills_parser_ = &skills;
  this->classXML_parser_ = &classXML;
  this->gender_parser_ = &gender;
  this->offhand_parser_ = &offhand;
  this->race_parser_ = &race;
  this->gold_parser_ = &gold;
  this->inventory_parser_ = &inventory;
  this->XP_parser_ = &XP;
}

RPG_Player_PlayerXML_Type_pskel::
RPG_Player_PlayerXML_Type_pskel ()
: gold_parser_ (0),
  inventory_parser_ (0),
  XP_parser_ (0)
{
}

// RPG_Player_StateBase_Type_pskel
//

void RPG_Player_StateBase_Type_pskel::
conditions_parser (::RPG_Player_Conditions_Type_pskel& p)
{
  this->conditions_parser_ = &p;
}

void RPG_Player_StateBase_Type_pskel::
HP_parser (::xml_schema::short_pskel& p)
{
  this->HP_parser_ = &p;
}

void RPG_Player_StateBase_Type_pskel::
parsers (::RPG_Player_Conditions_Type_pskel& conditions,
         ::xml_schema::short_pskel& HP)
{
  this->conditions_parser_ = &conditions;
  this->HP_parser_ = &HP;
}

RPG_Player_StateBase_Type_pskel::
RPG_Player_StateBase_Type_pskel ()
: conditions_parser_ (0),
  HP_parser_ (0)
{
}

// RPG_Player_State_Type_pskel
//

void RPG_Player_State_Type_pskel::
file_parser (::xml_schema::string_pskel& p)
{
  this->file_parser_ = &p;
}

void RPG_Player_State_Type_pskel::
parsers (::RPG_Player_Conditions_Type_pskel& conditions,
         ::xml_schema::short_pskel& HP,
         ::xml_schema::string_pskel& file)
{
  this->conditions_parser_ = &conditions;
  this->HP_parser_ = &HP;
  this->file_parser_ = &file;
}

RPG_Player_State_Type_pskel::
RPG_Player_State_Type_pskel ()
: file_parser_ (0)
{
}

// RPG_Player_Abilities_Type_pskel
//

void RPG_Player_Abilities_Type_pskel::
ability (const RPG_Character_Ability&)
{
}

bool RPG_Player_Abilities_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "ability" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->ability_parser_;

    if (this->ability_parser_)
      this->ability_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Player_Abilities_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "ability" && ns == "urn:rpg")
  {
    if (this->ability_parser_)
      this->ability (this->ability_parser_->post_RPG_Character_Ability_Type ());

    return true;
  }

  return false;
}

// RPG_Player_Conditions_Type_pskel
//

void RPG_Player_Conditions_Type_pskel::
condition (const RPG_Common_Condition&)
{
}

bool RPG_Player_Conditions_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "condition" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->condition_parser_;

    if (this->condition_parser_)
      this->condition_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Player_Conditions_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "condition" && ns == "urn:rpg")
  {
    if (this->condition_parser_)
      this->condition (this->condition_parser_->post_RPG_Common_Condition_Type ());

    return true;
  }

  return false;
}

// RPG_Player_Spells_Type_pskel
//

void RPG_Player_Spells_Type_pskel::
spell (const RPG_Magic_SpellType&)
{
}

bool RPG_Player_Spells_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "spell" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->spell_parser_;

    if (this->spell_parser_)
      this->spell_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Player_Spells_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "spell" && ns == "urn:rpg")
  {
    if (this->spell_parser_)
      this->spell (this->spell_parser_->post_RPG_Magic_SpellType_Type ());

    return true;
  }

  return false;
}

// RPG_Player_CharacterBaseXML_Type_pskel
//

void RPG_Player_CharacterBaseXML_Type_pskel::
name (const ::std::string&)
{
}

void RPG_Player_CharacterBaseXML_Type_pskel::
abilities (const RPG_Player_Abilities&)
{
}

void RPG_Player_CharacterBaseXML_Type_pskel::
alignment (const RPG_Character_Alignment&)
{
}

void RPG_Player_CharacterBaseXML_Type_pskel::
attributes (const RPG_Character_Attributes&)
{
}

void RPG_Player_CharacterBaseXML_Type_pskel::
defaultSize (const RPG_Common_Size&)
{
}

void RPG_Player_CharacterBaseXML_Type_pskel::
feats (const RPG_Character_Feats&)
{
}

void RPG_Player_CharacterBaseXML_Type_pskel::
knownSpells (const RPG_Player_Spells&)
{
}

void RPG_Player_CharacterBaseXML_Type_pskel::
maxHP (unsigned short)
{
}

void RPG_Player_CharacterBaseXML_Type_pskel::
skills (const RPG_Character_Skills&)
{
}

bool RPG_Player_CharacterBaseXML_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "name" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->name_parser_;

    if (this->name_parser_)
      this->name_parser_->pre ();

    return true;
  }

  if (n == "abilities" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->abilities_parser_;

    if (this->abilities_parser_)
      this->abilities_parser_->pre ();

    return true;
  }

  if (n == "alignment" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->alignment_parser_;

    if (this->alignment_parser_)
      this->alignment_parser_->pre ();

    return true;
  }

  if (n == "attributes" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->attributes_parser_;

    if (this->attributes_parser_)
      this->attributes_parser_->pre ();

    return true;
  }

  if (n == "defaultSize" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->defaultSize_parser_;

    if (this->defaultSize_parser_)
      this->defaultSize_parser_->pre ();

    return true;
  }

  if (n == "feats" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->feats_parser_;

    if (this->feats_parser_)
      this->feats_parser_->pre ();

    return true;
  }

  if (n == "knownSpells" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->knownSpells_parser_;

    if (this->knownSpells_parser_)
      this->knownSpells_parser_->pre ();

    return true;
  }

  if (n == "maxHP" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->maxHP_parser_;

    if (this->maxHP_parser_)
      this->maxHP_parser_->pre ();

    return true;
  }

  if (n == "skills" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->skills_parser_;

    if (this->skills_parser_)
      this->skills_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Player_CharacterBaseXML_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "name" && ns == "urn:rpg")
  {
    if (this->name_parser_)
      this->name (this->name_parser_->post_string ());

    return true;
  }

  if (n == "abilities" && ns == "urn:rpg")
  {
    if (this->abilities_parser_)
      this->abilities (this->abilities_parser_->post_RPG_Player_Abilities_Type ());

    return true;
  }

  if (n == "alignment" && ns == "urn:rpg")
  {
    if (this->alignment_parser_)
      this->alignment (this->alignment_parser_->post_RPG_Character_Alignment_Type ());

    return true;
  }

  if (n == "attributes" && ns == "urn:rpg")
  {
    if (this->attributes_parser_)
      this->attributes (this->attributes_parser_->post_RPG_Character_Attributes_Type ());

    return true;
  }

  if (n == "defaultSize" && ns == "urn:rpg")
  {
    if (this->defaultSize_parser_)
      this->defaultSize (this->defaultSize_parser_->post_RPG_Common_Size_Type ());

    return true;
  }

  if (n == "feats" && ns == "urn:rpg")
  {
    if (this->feats_parser_)
      this->feats (this->feats_parser_->post_RPG_Character_Feats_Type ());

    return true;
  }

  if (n == "knownSpells" && ns == "urn:rpg")
  {
    if (this->knownSpells_parser_)
      this->knownSpells (this->knownSpells_parser_->post_RPG_Player_Spells_Type ());

    return true;
  }

  if (n == "maxHP" && ns == "urn:rpg")
  {
    if (this->maxHP_parser_)
      this->maxHP (this->maxHP_parser_->post_unsigned_short ());

    return true;
  }

  if (n == "skills" && ns == "urn:rpg")
  {
    if (this->skills_parser_)
      this->skills (this->skills_parser_->post_RPG_Character_Skills_Type ());

    return true;
  }

  return false;
}

// RPG_Player_CharacterXML_Type_pskel
//

void RPG_Player_CharacterXML_Type_pskel::
classXML (const RPG_Character_ClassXML&)
{
}

void RPG_Player_CharacterXML_Type_pskel::
gender (const RPG_Character_Gender&)
{
}

void RPG_Player_CharacterXML_Type_pskel::
offhand (const RPG_Character_OffHand&)
{
}

void RPG_Player_CharacterXML_Type_pskel::
race (const RPG_Character_Race&)
{
}

bool RPG_Player_CharacterXML_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::RPG_Player_CharacterBaseXML_Type_pskel::_start_element_impl (ns, n, t))
    return true;

  if (n == "classXML" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->classXML_parser_;

    if (this->classXML_parser_)
      this->classXML_parser_->pre ();

    return true;
  }

  if (n == "gender" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->gender_parser_;

    if (this->gender_parser_)
      this->gender_parser_->pre ();

    return true;
  }

  if (n == "offhand" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->offhand_parser_;

    if (this->offhand_parser_)
      this->offhand_parser_->pre ();

    return true;
  }

  if (n == "race" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->race_parser_;

    if (this->race_parser_)
      this->race_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Player_CharacterXML_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::RPG_Player_CharacterBaseXML_Type_pskel::_end_element_impl (ns, n))
    return true;

  if (n == "classXML" && ns == "urn:rpg")
  {
    if (this->classXML_parser_)
      this->classXML (this->classXML_parser_->post_RPG_Character_ClassXML_Type ());

    return true;
  }

  if (n == "gender" && ns == "urn:rpg")
  {
    if (this->gender_parser_)
      this->gender (this->gender_parser_->post_RPG_Character_Gender_Type ());

    return true;
  }

  if (n == "offhand" && ns == "urn:rpg")
  {
    if (this->offhand_parser_)
      this->offhand (this->offhand_parser_->post_RPG_Character_OffHand_Type ());

    return true;
  }

  if (n == "race" && ns == "urn:rpg")
  {
    if (this->race_parser_)
      this->race (this->race_parser_->post_RPG_Character_Race_Type ());

    return true;
  }

  return false;
}

// RPG_Player_PlayerXML_Type_pskel
//

void RPG_Player_PlayerXML_Type_pskel::
gold (unsigned int)
{
}

void RPG_Player_PlayerXML_Type_pskel::
inventory (const RPG_Item_InventoryXML&)
{
}

void RPG_Player_PlayerXML_Type_pskel::
XP (unsigned int)
{
}

bool RPG_Player_PlayerXML_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::RPG_Player_CharacterXML_Type_pskel::_start_element_impl (ns, n, t))
    return true;

  if (n == "gold" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->gold_parser_;

    if (this->gold_parser_)
      this->gold_parser_->pre ();

    return true;
  }

  if (n == "inventory" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->inventory_parser_;

    if (this->inventory_parser_)
      this->inventory_parser_->pre ();

    return true;
  }

  if (n == "XP" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->XP_parser_;

    if (this->XP_parser_)
      this->XP_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Player_PlayerXML_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::RPG_Player_CharacterXML_Type_pskel::_end_element_impl (ns, n))
    return true;

  if (n == "gold" && ns == "urn:rpg")
  {
    if (this->gold_parser_)
      this->gold (this->gold_parser_->post_unsigned_int ());

    return true;
  }

  if (n == "inventory" && ns == "urn:rpg")
  {
    if (this->inventory_parser_)
      this->inventory (this->inventory_parser_->post_RPG_Item_InventoryXML_Type ());

    return true;
  }

  if (n == "XP" && ns == "urn:rpg")
  {
    if (this->XP_parser_)
      this->XP (this->XP_parser_->post_unsigned_int ());

    return true;
  }

  return false;
}

// RPG_Player_StateBase_Type_pskel
//

void RPG_Player_StateBase_Type_pskel::
conditions (const RPG_Player_Conditions&)
{
}

void RPG_Player_StateBase_Type_pskel::
HP (short)
{
}

void RPG_Player_StateBase_Type_pskel::
post_RPG_Player_StateBase_Type ()
{
}

bool RPG_Player_StateBase_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "conditions" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->conditions_parser_;

    if (this->conditions_parser_)
      this->conditions_parser_->pre ();

    return true;
  }

  if (n == "HP" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->HP_parser_;

    if (this->HP_parser_)
      this->HP_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Player_StateBase_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "conditions" && ns == "urn:rpg")
  {
    if (this->conditions_parser_)
      this->conditions (this->conditions_parser_->post_RPG_Player_Conditions_Type ());

    return true;
  }

  if (n == "HP" && ns == "urn:rpg")
  {
    if (this->HP_parser_)
      this->HP (this->HP_parser_->post_short ());

    return true;
  }

  return false;
}

// RPG_Player_State_Type_pskel
//

void RPG_Player_State_Type_pskel::
file (const ::std::string&)
{
}

void RPG_Player_State_Type_pskel::
post_RPG_Player_State_Type ()
{
  post_RPG_Player_StateBase_Type ();
}

bool RPG_Player_State_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::RPG_Player_StateBase_Type_pskel::_start_element_impl (ns, n, t))
    return true;

  if (n == "file" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->file_parser_;

    if (this->file_parser_)
      this->file_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Player_State_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::RPG_Player_StateBase_Type_pskel::_end_element_impl (ns, n))
    return true;

  if (n == "file" && ns == "urn:rpg")
  {
    if (this->file_parser_)
      this->file (this->file_parser_->post_string ());

    return true;
  }

  return false;
}

// Begin epilogue.
//
//
// End epilogue.
