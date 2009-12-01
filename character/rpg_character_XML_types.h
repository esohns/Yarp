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

#ifndef CXX___RPG_CHARACTER_XML_TYPES_H
#define CXX___RPG_CHARACTER_XML_TYPES_H

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
class RPG_Character_MonsterMetaType_Type_pskel;
class RPG_Character_MonsterSubType_Type_pskel;
class RPG_Character_MonsterType_Type_pskel;
class RPG_Character_MonsterArmorClass_Type_pskel;
class RPG_Character_MonsterWeapon_Type_pskel;
class RPG_Character_AttackForm_Type_pskel;
class RPG_Character_MonsterAttackAction_Type_pskel;
class RPG_Character_MonsterAttack_Type_pskel;
class RPG_Character_Size_Type_pskel;
class RPG_Character_SavingThrowModifiers_Type_pskel;
class RPG_Character_Attributes_Type_pskel;
class RPG_Character_Skill_Type_pskel;
class RPG_Character_SkillValue_Type_pskel;
class RPG_Character_Skills_Type_pskel;
class RPG_Character_Feat_Type_pskel;
class RPG_Character_Feats_Type_pskel;
class RPG_Character_Environment_Type_pskel;
class RPG_Character_Organization_Type_pskel;
class RPG_Character_AlignmentCivic_Type_pskel;
class RPG_Character_AlignmentEthic_Type_pskel;
class RPG_Character_Alignment_Type_pskel;
class RPG_Character_MonsterAdvancementStep_Type_pskel;
class RPG_Character_MonsterAdvancement_Type_pskel;
class RPG_Character_MonsterProperties_Type_pskel;
class RPG_Character_MonsterDictionary_Type_pskel;
class RPG_Character_Dictionary_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_XMLSchema.h"

#include "rpg_character_skills_common.h"
#include "rpg_character_monster_common.h"
#include "rpg_character_common.h"

#include <rpg_item_XML_types.h>

#include <rpg_chance_dice_common.h>
#include <rpg_chance_dice_XML_types.h>

class RPG_Character_MonsterMetaType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_MonsterMetaType
  post_RPG_Character_MonsterMetaType_Type () = 0;
};

class RPG_Character_MonsterSubType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_MonsterSubType
  post_RPG_Character_MonsterSubType_Type () = 0;
};

class RPG_Character_MonsterType_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  metaType (const RPG_Character_MonsterMetaType&);

  virtual void
  subType (const RPG_Character_MonsterSubType&);

  virtual RPG_Character_MonsterType
  post_RPG_Character_MonsterType_Type () = 0;

  // Parser construction API.
  //
  void
  metaType_parser (::RPG_Character_MonsterMetaType_Type_pskel&);

  void
  subType_parser (::RPG_Character_MonsterSubType_Type_pskel&);

  void
  parsers (::RPG_Character_MonsterMetaType_Type_pskel& /* metaType */,
           ::RPG_Character_MonsterSubType_Type_pskel& /* subType */);

  // Constructor.
  //
  RPG_Character_MonsterType_Type_pskel ();

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
  ::RPG_Character_MonsterMetaType_Type_pskel* metaType_parser_;
  ::RPG_Character_MonsterSubType_Type_pskel* subType_parser_;
};

class RPG_Character_MonsterArmorClass_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  normal (unsigned char);

  virtual void
  touch (unsigned char);

  virtual void
  flatFooted (unsigned char);

  virtual RPG_Character_MonsterArmorClass
  post_RPG_Character_MonsterArmorClass_Type () = 0;

  // Parser construction API.
  //
  void
  normal_parser (::xml_schema::unsigned_byte_pskel&);

  void
  touch_parser (::xml_schema::unsigned_byte_pskel&);

  void
  flatFooted_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::xml_schema::unsigned_byte_pskel& /* normal */,
           ::xml_schema::unsigned_byte_pskel& /* touch */,
           ::xml_schema::unsigned_byte_pskel& /* flatFooted */);

  // Constructor.
  //
  RPG_Character_MonsterArmorClass_Type_pskel ();

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
  ::xml_schema::unsigned_byte_pskel* normal_parser_;
  ::xml_schema::unsigned_byte_pskel* touch_parser_;
  ::xml_schema::unsigned_byte_pskel* flatFooted_parser_;
};

class RPG_Character_MonsterWeapon_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_MonsterWeapon
  post_RPG_Character_MonsterWeapon_Type () = 0;
};

class RPG_Character_AttackForm_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_AttackForm
  post_RPG_Character_AttackForm_Type () = 0;
};

class RPG_Character_MonsterAttackAction_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  monsterWeapon (const RPG_Character_MonsterWeapon&);

  virtual void
  attackBonus (signed char);

  virtual void
  attackForm (const RPG_Character_AttackForm&);

  virtual void
  damage (const RPG_Chance_DiceRoll&);

  virtual void
  numAttacksPerRound (unsigned char);

  virtual RPG_Character_MonsterAttackAction
  post_RPG_Character_MonsterAttackAction_Type () = 0;

  // Parser construction API.
  //
  void
  monsterWeapon_parser (::RPG_Character_MonsterWeapon_Type_pskel&);

  void
  attackBonus_parser (::xml_schema::byte_pskel&);

  void
  attackForm_parser (::RPG_Character_AttackForm_Type_pskel&);

  void
  damage_parser (::RPG_Chance_DiceRoll_Type_pskel&);

  void
  numAttacksPerRound_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::RPG_Character_MonsterWeapon_Type_pskel& /* monsterWeapon */,
           ::xml_schema::byte_pskel& /* attackBonus */,
           ::RPG_Character_AttackForm_Type_pskel& /* attackForm */,
           ::RPG_Chance_DiceRoll_Type_pskel& /* damage */,
           ::xml_schema::unsigned_byte_pskel& /* numAttacksPerRound */);

  // Constructor.
  //
  RPG_Character_MonsterAttackAction_Type_pskel ();

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
  ::RPG_Character_MonsterWeapon_Type_pskel* monsterWeapon_parser_;
  ::xml_schema::byte_pskel* attackBonus_parser_;
  ::RPG_Character_AttackForm_Type_pskel* attackForm_parser_;
  ::RPG_Chance_DiceRoll_Type_pskel* damage_parser_;
  ::xml_schema::unsigned_byte_pskel* numAttacksPerRound_parser_;
};

class RPG_Character_MonsterAttack_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  baseAttackBonus (signed char);

  virtual void
  grappleBonus (signed char);

  virtual void
  attackAction (const RPG_Character_MonsterAttackAction&);

  virtual RPG_Character_MonsterAttack
  post_RPG_Character_MonsterAttack_Type () = 0;

  // Parser construction API.
  //
  void
  baseAttackBonus_parser (::xml_schema::byte_pskel&);

  void
  grappleBonus_parser (::xml_schema::byte_pskel&);

  void
  attackAction_parser (::RPG_Character_MonsterAttackAction_Type_pskel&);

  void
  parsers (::xml_schema::byte_pskel& /* baseAttackBonus */,
           ::xml_schema::byte_pskel& /* grappleBonus */,
           ::RPG_Character_MonsterAttackAction_Type_pskel& /* attackAction */);

  // Constructor.
  //
  RPG_Character_MonsterAttack_Type_pskel ();

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
  ::xml_schema::byte_pskel* baseAttackBonus_parser_;
  ::xml_schema::byte_pskel* grappleBonus_parser_;
  ::RPG_Character_MonsterAttackAction_Type_pskel* attackAction_parser_;
};

class RPG_Character_Size_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Size
  post_RPG_Character_Size_Type () = 0;
};

class RPG_Character_SavingThrowModifiers_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  fortitude (signed char);

  virtual void
  reflex (signed char);

  virtual void
  will (signed char);

  virtual RPG_Character_SavingThrowModifiers
  post_RPG_Character_SavingThrowModifiers_Type () = 0;

  // Parser construction API.
  //
  void
  fortitude_parser (::xml_schema::byte_pskel&);

  void
  reflex_parser (::xml_schema::byte_pskel&);

  void
  will_parser (::xml_schema::byte_pskel&);

  void
  parsers (::xml_schema::byte_pskel& /* fortitude */,
           ::xml_schema::byte_pskel& /* reflex */,
           ::xml_schema::byte_pskel& /* will */);

  // Constructor.
  //
  RPG_Character_SavingThrowModifiers_Type_pskel ();

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
  ::xml_schema::byte_pskel* fortitude_parser_;
  ::xml_schema::byte_pskel* reflex_parser_;
  ::xml_schema::byte_pskel* will_parser_;
};

class RPG_Character_Attributes_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  strength (unsigned char);

  virtual void
  dexterity (unsigned char);

  virtual void
  constitution (unsigned char);

  virtual void
  intelligence (unsigned char);

  virtual void
  wisdom (unsigned char);

  virtual void
  charisma (unsigned char);

  virtual RPG_Character_Attributes
  post_RPG_Character_Attributes_Type () = 0;

  // Parser construction API.
  //
  void
  strength_parser (::xml_schema::unsigned_byte_pskel&);

  void
  dexterity_parser (::xml_schema::unsigned_byte_pskel&);

  void
  constitution_parser (::xml_schema::unsigned_byte_pskel&);

  void
  intelligence_parser (::xml_schema::unsigned_byte_pskel&);

  void
  wisdom_parser (::xml_schema::unsigned_byte_pskel&);

  void
  charisma_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::xml_schema::unsigned_byte_pskel& /* strength */,
           ::xml_schema::unsigned_byte_pskel& /* dexterity */,
           ::xml_schema::unsigned_byte_pskel& /* constitution */,
           ::xml_schema::unsigned_byte_pskel& /* intelligence */,
           ::xml_schema::unsigned_byte_pskel& /* wisdom */,
           ::xml_schema::unsigned_byte_pskel& /* charisma */);

  // Constructor.
  //
  RPG_Character_Attributes_Type_pskel ();

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
  ::xml_schema::unsigned_byte_pskel* strength_parser_;
  ::xml_schema::unsigned_byte_pskel* dexterity_parser_;
  ::xml_schema::unsigned_byte_pskel* constitution_parser_;
  ::xml_schema::unsigned_byte_pskel* intelligence_parser_;
  ::xml_schema::unsigned_byte_pskel* wisdom_parser_;
  ::xml_schema::unsigned_byte_pskel* charisma_parser_;
};

class RPG_Character_Skill_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Skill
  post_RPG_Character_Skill_Type () = 0;
};

class RPG_Character_SkillValue_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  skill (const RPG_Character_Skill&);

  virtual void
  rank (signed char);

  virtual RPG_Character_SkillsItem_t
  post_RPG_Character_SkillValue_Type () = 0;

  // Parser construction API.
  //
  void
  skill_parser (::RPG_Character_Skill_Type_pskel&);

  void
  rank_parser (::xml_schema::byte_pskel&);

  void
  parsers (::RPG_Character_Skill_Type_pskel& /* skill */,
           ::xml_schema::byte_pskel& /* rank */);

  // Constructor.
  //
  RPG_Character_SkillValue_Type_pskel ();

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
  ::RPG_Character_Skill_Type_pskel* skill_parser_;
  ::xml_schema::byte_pskel* rank_parser_;
};

class RPG_Character_Skills_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  skill (const RPG_Character_SkillsItem_t&);

  virtual RPG_Character_Skills_t
  post_RPG_Character_Skills_Type () = 0;

  // Parser construction API.
  //
  void
  skill_parser (::RPG_Character_SkillValue_Type_pskel&);

  void
  parsers (::RPG_Character_SkillValue_Type_pskel& /* skill */);

  // Constructor.
  //
  RPG_Character_Skills_Type_pskel ();

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
  ::RPG_Character_SkillValue_Type_pskel* skill_parser_;
};

class RPG_Character_Feat_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Feat
  post_RPG_Character_Feat_Type () = 0;
};

class RPG_Character_Feats_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  feat (const RPG_Character_Feat&);

  virtual RPG_Character_Feats_t
  post_RPG_Character_Feats_Type () = 0;

  // Parser construction API.
  //
  void
  feat_parser (::RPG_Character_Feat_Type_pskel&);

  void
  parsers (::RPG_Character_Feat_Type_pskel& /* feat */);

  // Constructor.
  //
  RPG_Character_Feats_Type_pskel ();

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
  ::RPG_Character_Feat_Type_pskel* feat_parser_;
};

class RPG_Character_Environment_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Environment
  post_RPG_Character_Environment_Type () = 0;
};

class RPG_Character_Organization_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Organization
  post_RPG_Character_Organization_Type () = 0;
};

class RPG_Character_AlignmentCivic_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_AlignmentCivic
  post_RPG_Character_AlignmentCivic_Type () = 0;
};

class RPG_Character_AlignmentEthic_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_AlignmentEthic
  post_RPG_Character_AlignmentEthic_Type () = 0;
};

class RPG_Character_Alignment_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  civic (const RPG_Character_AlignmentCivic&);

  virtual void
  ethic (const RPG_Character_AlignmentEthic&);

  virtual RPG_Character_Alignment
  post_RPG_Character_Alignment_Type () = 0;

  // Parser construction API.
  //
  void
  civic_parser (::RPG_Character_AlignmentCivic_Type_pskel&);

  void
  ethic_parser (::RPG_Character_AlignmentEthic_Type_pskel&);

  void
  parsers (::RPG_Character_AlignmentCivic_Type_pskel& /* civic */,
           ::RPG_Character_AlignmentEthic_Type_pskel& /* ethic */);

  // Constructor.
  //
  RPG_Character_Alignment_Type_pskel ();

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
  ::RPG_Character_AlignmentCivic_Type_pskel* civic_parser_;
  ::RPG_Character_AlignmentEthic_Type_pskel* ethic_parser_;
};

class RPG_Character_MonsterAdvancementStep_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  size (const RPG_Character_Size&);

  virtual void
  range (const RPG_Chance_ValueRange&);

  virtual RPG_Character_MonsterAdvancementStep_t
  post_RPG_Character_MonsterAdvancementStep_Type () = 0;

  // Parser construction API.
  //
  void
  size_parser (::RPG_Character_Size_Type_pskel&);

  void
  range_parser (::RPG_Chance_ValueRange_Type_pskel&);

  void
  parsers (::RPG_Character_Size_Type_pskel& /* size */,
           ::RPG_Chance_ValueRange_Type_pskel& /* range */);

  // Constructor.
  //
  RPG_Character_MonsterAdvancementStep_Type_pskel ();

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
  ::RPG_Character_Size_Type_pskel* size_parser_;
  ::RPG_Chance_ValueRange_Type_pskel* range_parser_;
};

class RPG_Character_MonsterAdvancement_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  step (const RPG_Character_MonsterAdvancementStep_t&);

  virtual RPG_Character_MonsterAdvancement_t
  post_RPG_Character_MonsterAdvancement_Type () = 0;

  // Parser construction API.
  //
  void
  step_parser (::RPG_Character_MonsterAdvancementStep_Type_pskel&);

  void
  parsers (::RPG_Character_MonsterAdvancementStep_Type_pskel& /* step */);

  // Constructor.
  //
  RPG_Character_MonsterAdvancement_Type_pskel ();

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
  ::RPG_Character_MonsterAdvancementStep_Type_pskel* step_parser_;
};

class RPG_Character_MonsterProperties_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  name (const ::std::string&);

  virtual void
  size (const RPG_Character_Size&);

  virtual void
  type (const RPG_Character_MonsterType&);

  virtual void
  hitDice (const RPG_Chance_DiceRoll&);

  virtual void
  initiative (signed char);

  virtual void
  speed (unsigned char);

  virtual void
  armorClass (const RPG_Character_MonsterArmorClass&);

  virtual void
  attack (const RPG_Character_MonsterAttack&);

  virtual void
  space (unsigned char);

  virtual void
  reach (unsigned char);

  virtual void
  saves (const RPG_Character_SavingThrowModifiers&);

  virtual void
  attributes (const RPG_Character_Attributes&);

  virtual void
  skills (const RPG_Character_Skills_t&);

  virtual void
  feats (const RPG_Character_Feats_t&);

  virtual void
  environment (const RPG_Character_Environment&);

  virtual void
  organization (const RPG_Character_Organization&);

  virtual void
  challengeRating (unsigned char);

  virtual void
  treasureModifier (unsigned char);

  virtual void
  alignment (const RPG_Character_Alignment&);

  virtual void
  advancement (const RPG_Character_MonsterAdvancement_t&);

  virtual void
  levelAdjustment (unsigned char);

  virtual RPG_Character_MonsterProperties_XML
  post_RPG_Character_MonsterProperties_Type () = 0;

  // Parser construction API.
  //
  void
  name_parser (::xml_schema::string_pskel&);

  void
  size_parser (::RPG_Character_Size_Type_pskel&);

  void
  type_parser (::RPG_Character_MonsterType_Type_pskel&);

  void
  hitDice_parser (::RPG_Chance_DiceRoll_Type_pskel&);

  void
  initiative_parser (::xml_schema::byte_pskel&);

  void
  speed_parser (::xml_schema::unsigned_byte_pskel&);

  void
  armorClass_parser (::RPG_Character_MonsterArmorClass_Type_pskel&);

  void
  attack_parser (::RPG_Character_MonsterAttack_Type_pskel&);

  void
  space_parser (::xml_schema::unsigned_byte_pskel&);

  void
  reach_parser (::xml_schema::unsigned_byte_pskel&);

  void
  saves_parser (::RPG_Character_SavingThrowModifiers_Type_pskel&);

  void
  attributes_parser (::RPG_Character_Attributes_Type_pskel&);

  void
  skills_parser (::RPG_Character_Skills_Type_pskel&);

  void
  feats_parser (::RPG_Character_Feats_Type_pskel&);

  void
  environment_parser (::RPG_Character_Environment_Type_pskel&);

  void
  organization_parser (::RPG_Character_Organization_Type_pskel&);

  void
  challengeRating_parser (::xml_schema::unsigned_byte_pskel&);

  void
  treasureModifier_parser (::xml_schema::unsigned_byte_pskel&);

  void
  alignment_parser (::RPG_Character_Alignment_Type_pskel&);

  void
  advancement_parser (::RPG_Character_MonsterAdvancement_Type_pskel&);

  void
  levelAdjustment_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::xml_schema::string_pskel& /* name */,
           ::RPG_Character_Size_Type_pskel& /* size */,
           ::RPG_Character_MonsterType_Type_pskel& /* type */,
           ::RPG_Chance_DiceRoll_Type_pskel& /* hitDice */,
           ::xml_schema::byte_pskel& /* initiative */,
           ::xml_schema::unsigned_byte_pskel& /* speed */,
           ::RPG_Character_MonsterArmorClass_Type_pskel& /* armorClass */,
           ::RPG_Character_MonsterAttack_Type_pskel& /* attack */,
           ::xml_schema::unsigned_byte_pskel& /* space */,
           ::xml_schema::unsigned_byte_pskel& /* reach */,
           ::RPG_Character_SavingThrowModifiers_Type_pskel& /* saves */,
           ::RPG_Character_Attributes_Type_pskel& /* attributes */,
           ::RPG_Character_Skills_Type_pskel& /* skills */,
           ::RPG_Character_Feats_Type_pskel& /* feats */,
           ::RPG_Character_Environment_Type_pskel& /* environment */,
           ::RPG_Character_Organization_Type_pskel& /* organization */,
           ::xml_schema::unsigned_byte_pskel& /* challengeRating */,
           ::xml_schema::unsigned_byte_pskel& /* treasureModifier */,
           ::RPG_Character_Alignment_Type_pskel& /* alignment */,
           ::RPG_Character_MonsterAdvancement_Type_pskel& /* advancement */,
           ::xml_schema::unsigned_byte_pskel& /* levelAdjustment */);

  // Constructor.
  //
  RPG_Character_MonsterProperties_Type_pskel ();

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
  ::xml_schema::string_pskel* name_parser_;
  ::RPG_Character_Size_Type_pskel* size_parser_;
  ::RPG_Character_MonsterType_Type_pskel* type_parser_;
  ::RPG_Chance_DiceRoll_Type_pskel* hitDice_parser_;
  ::xml_schema::byte_pskel* initiative_parser_;
  ::xml_schema::unsigned_byte_pskel* speed_parser_;
  ::RPG_Character_MonsterArmorClass_Type_pskel* armorClass_parser_;
  ::RPG_Character_MonsterAttack_Type_pskel* attack_parser_;
  ::xml_schema::unsigned_byte_pskel* space_parser_;
  ::xml_schema::unsigned_byte_pskel* reach_parser_;
  ::RPG_Character_SavingThrowModifiers_Type_pskel* saves_parser_;
  ::RPG_Character_Attributes_Type_pskel* attributes_parser_;
  ::RPG_Character_Skills_Type_pskel* skills_parser_;
  ::RPG_Character_Feats_Type_pskel* feats_parser_;
  ::RPG_Character_Environment_Type_pskel* environment_parser_;
  ::RPG_Character_Organization_Type_pskel* organization_parser_;
  ::xml_schema::unsigned_byte_pskel* challengeRating_parser_;
  ::xml_schema::unsigned_byte_pskel* treasureModifier_parser_;
  ::RPG_Character_Alignment_Type_pskel* alignment_parser_;
  ::RPG_Character_MonsterAdvancement_Type_pskel* advancement_parser_;
  ::xml_schema::unsigned_byte_pskel* levelAdjustment_parser_;
};

class RPG_Character_MonsterDictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  monster (const RPG_Character_MonsterProperties_XML&);

  virtual void
  post_RPG_Character_MonsterDictionary_Type ();

  // Parser construction API.
  //
  void
  monster_parser (::RPG_Character_MonsterProperties_Type_pskel&);

  void
  parsers (::RPG_Character_MonsterProperties_Type_pskel& /* monster */);

  // Constructor.
  //
  RPG_Character_MonsterDictionary_Type_pskel ();

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
  ::RPG_Character_MonsterProperties_Type_pskel* monster_parser_;
};

class RPG_Character_Dictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  monsterDictionary ();

  virtual void
  post_RPG_Character_Dictionary_Type ();

  // Parser construction API.
  //
  void
  monsterDictionary_parser (::RPG_Character_MonsterDictionary_Type_pskel&);

  void
  parsers (::RPG_Character_MonsterDictionary_Type_pskel& /* monsterDictionary */);

  // Constructor.
  //
  RPG_Character_Dictionary_Type_pskel ();

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
  ::RPG_Character_MonsterDictionary_Type_pskel* monsterDictionary_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_CHARACTER_XML_TYPES_H
