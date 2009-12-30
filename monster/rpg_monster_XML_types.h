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

#ifndef CXX_____RPG_MONSTER_XML_TYPES_H
#define CXX_____RPG_MONSTER_XML_TYPES_H

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
class RPG_Monster_MetaType_Type_pskel;
class RPG_Monster_SubType_Type_pskel;
class RPG_Monster_Type_Type_pskel;
class RPG_Monster_NaturalArmorClass_Type_pskel;
class RPG_Monster_NaturalWeapon_Type_pskel;
class RPG_Monster_WeaponTypeUnion_Type_pskel;
class RPG_Monster_AttackAction_Type_pskel;
class RPG_Monster_Attack_Type_pskel;
class RPG_Monster_SavingThrowModifiers_Type_pskel;
class RPG_Monster_Organization_Type_pskel;
class RPG_Monster_OrganizationSlaverStep_Type_pskel;
class RPG_Monster_OrganizationStep_Type_pskel;
class RPG_Monster_Organizations_Type_pskel;
class RPG_Monster_AdvancementStep_Type_pskel;
class RPG_Monster_Advancement_Type_pskel;
class RPG_Monster_PropertiesXML_Type_pskel;
class RPG_Monster_Dictionary_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_XMLSchema.h"

#include <rpg_item_weapontype.h>
#include <rpg_item_physicaldamagetype.h>
#include <rpg_dice_incl.h>
#include <rpg_common_savingthrow.h>
#include <rpg_common_attribute.h>
#include <rpg_common_savingthrowmodifier.h>
#include <rpg_combat_incl.h>
#include <rpg_character_incl.h>
#include "rpg_monster_incl.h"

#include "rpg_dice_XML_types.h"

#include "rpg_item_XML_types.h"

#include "rpg_character_XML_types.h"

#include "rpg_combat_XML_types.h"

class RPG_Monster_MetaType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Monster_MetaType
  post_RPG_Monster_MetaType_Type () = 0;
};

class RPG_Monster_SubType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Monster_SubType
  post_RPG_Monster_SubType_Type () = 0;
};

class RPG_Monster_Type_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  metaType (const RPG_Monster_MetaType&);

  virtual void
  subType (const RPG_Monster_SubType&);

  virtual RPG_Monster_Type
  post_RPG_Monster_Type_Type () = 0;

  // Parser construction API.
  //
  void
  metaType_parser (::RPG_Monster_MetaType_Type_pskel&);

  void
  subType_parser (::RPG_Monster_SubType_Type_pskel&);

  void
  parsers (::RPG_Monster_MetaType_Type_pskel& /* metaType */,
           ::RPG_Monster_SubType_Type_pskel& /* subType */);

  // Constructor.
  //
  RPG_Monster_Type_Type_pskel ();

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
  ::RPG_Monster_MetaType_Type_pskel* metaType_parser_;
  ::RPG_Monster_SubType_Type_pskel* subType_parser_;
};

class RPG_Monster_NaturalArmorClass_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  normal (signed char);

  virtual void
  touch (signed char);

  virtual void
  flatFooted (signed char);

  virtual RPG_Monster_NaturalArmorClass
  post_RPG_Monster_NaturalArmorClass_Type () = 0;

  // Parser construction API.
  //
  void
  normal_parser (::xml_schema::byte_pskel&);

  void
  touch_parser (::xml_schema::byte_pskel&);

  void
  flatFooted_parser (::xml_schema::byte_pskel&);

  void
  parsers (::xml_schema::byte_pskel& /* normal */,
           ::xml_schema::byte_pskel& /* touch */,
           ::xml_schema::byte_pskel& /* flatFooted */);

  // Constructor.
  //
  RPG_Monster_NaturalArmorClass_Type_pskel ();

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
  ::xml_schema::byte_pskel* normal_parser_;
  ::xml_schema::byte_pskel* touch_parser_;
  ::xml_schema::byte_pskel* flatFooted_parser_;
};

class RPG_Monster_NaturalWeapon_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Monster_NaturalWeapon
  post_RPG_Monster_NaturalWeapon_Type () = 0;
};

class RPG_Monster_WeaponTypeUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Monster_WeaponTypeUnion
  post_RPG_Monster_WeaponTypeUnion_Type () = 0;
};

class RPG_Monster_AttackAction_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  weapon (const RPG_Monster_WeaponTypeUnion&);

  virtual void
  attackBonus (signed char);

  virtual void
  attackForm (const RPG_Combat_AttackForm&);

  virtual void
  damage (const RPG_Combat_Damage&);

  virtual void
  numAttacksPerRound (unsigned char);

  virtual RPG_Monster_AttackAction
  post_RPG_Monster_AttackAction_Type () = 0;

  // Parser construction API.
  //
  void
  weapon_parser (::RPG_Monster_WeaponTypeUnion_Type_pskel&);

  void
  attackBonus_parser (::xml_schema::byte_pskel&);

  void
  attackForm_parser (::RPG_Combat_AttackForm_Type_pskel&);

  void
  damage_parser (::RPG_Combat_Damage_Type_pskel&);

  void
  numAttacksPerRound_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::RPG_Monster_WeaponTypeUnion_Type_pskel& /* weapon */,
           ::xml_schema::byte_pskel& /* attackBonus */,
           ::RPG_Combat_AttackForm_Type_pskel& /* attackForm */,
           ::RPG_Combat_Damage_Type_pskel& /* damage */,
           ::xml_schema::unsigned_byte_pskel& /* numAttacksPerRound */);

  // Constructor.
  //
  RPG_Monster_AttackAction_Type_pskel ();

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
  ::RPG_Monster_WeaponTypeUnion_Type_pskel* weapon_parser_;
  ::xml_schema::byte_pskel* attackBonus_parser_;
  ::RPG_Combat_AttackForm_Type_pskel* attackForm_parser_;
  ::RPG_Combat_Damage_Type_pskel* damage_parser_;
  ::xml_schema::unsigned_byte_pskel* numAttacksPerRound_parser_;
};

class RPG_Monster_Attack_Type_pskel: public ::xml_schema::complex_content
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
  standardAttackAction (const RPG_Monster_AttackAction&);

  virtual void
  fullAttackAction (const RPG_Monster_AttackAction&);

  virtual void
  attackActionsAreInclusive (bool);

  virtual RPG_Monster_Attack
  post_RPG_Monster_Attack_Type () = 0;

  // Parser construction API.
  //
  void
  baseAttackBonus_parser (::xml_schema::byte_pskel&);

  void
  grappleBonus_parser (::xml_schema::byte_pskel&);

  void
  standardAttackAction_parser (::RPG_Monster_AttackAction_Type_pskel&);

  void
  fullAttackAction_parser (::RPG_Monster_AttackAction_Type_pskel&);

  void
  attackActionsAreInclusive_parser (::xml_schema::boolean_pskel&);

  void
  parsers (::xml_schema::byte_pskel& /* baseAttackBonus */,
           ::xml_schema::byte_pskel& /* grappleBonus */,
           ::RPG_Monster_AttackAction_Type_pskel& /* standardAttackAction */,
           ::RPG_Monster_AttackAction_Type_pskel& /* fullAttackAction */,
           ::xml_schema::boolean_pskel& /* attackActionsAreInclusive */);

  // Constructor.
  //
  RPG_Monster_Attack_Type_pskel ();

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
  ::xml_schema::byte_pskel* baseAttackBonus_parser_;
  ::xml_schema::byte_pskel* grappleBonus_parser_;
  ::RPG_Monster_AttackAction_Type_pskel* standardAttackAction_parser_;
  ::RPG_Monster_AttackAction_Type_pskel* fullAttackAction_parser_;
  ::xml_schema::boolean_pskel* attackActionsAreInclusive_parser_;
};

class RPG_Monster_SavingThrowModifiers_Type_pskel: public ::xml_schema::complex_content
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

  virtual RPG_Monster_SavingThrowModifiers
  post_RPG_Monster_SavingThrowModifiers_Type () = 0;

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
  RPG_Monster_SavingThrowModifiers_Type_pskel ();

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

class RPG_Monster_Organization_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Monster_Organization
  post_RPG_Monster_Organization_Type () = 0;
};

class RPG_Monster_OrganizationSlaverStep_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  name (const ::std::string&);

  virtual void
  range (const RPG_Dice_ValueRange&);

  virtual RPG_Monster_OrganizationSlaverStep
  post_RPG_Monster_OrganizationSlaverStep_Type () = 0;

  // Parser construction API.
  //
  void
  name_parser (::xml_schema::string_pskel&);

  void
  range_parser (::RPG_Dice_ValueRange_Type_pskel&);

  void
  parsers (::xml_schema::string_pskel& /* name */,
           ::RPG_Dice_ValueRange_Type_pskel& /* range */);

  // Constructor.
  //
  RPG_Monster_OrganizationSlaverStep_Type_pskel ();

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
  ::RPG_Dice_ValueRange_Type_pskel* range_parser_;
};

class RPG_Monster_OrganizationStep_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Monster_Organization&);

  virtual void
  range (const RPG_Dice_ValueRange&);

  virtual void
  slaves (const RPG_Monster_OrganizationSlaverStep&);

  virtual RPG_Monster_OrganizationStep
  post_RPG_Monster_OrganizationStep_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Monster_Organization_Type_pskel&);

  void
  range_parser (::RPG_Dice_ValueRange_Type_pskel&);

  void
  slaves_parser (::RPG_Monster_OrganizationSlaverStep_Type_pskel&);

  void
  parsers (::RPG_Monster_Organization_Type_pskel& /* type */,
           ::RPG_Dice_ValueRange_Type_pskel& /* range */,
           ::RPG_Monster_OrganizationSlaverStep_Type_pskel& /* slaves */);

  // Constructor.
  //
  RPG_Monster_OrganizationStep_Type_pskel ();

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
  ::RPG_Monster_Organization_Type_pskel* type_parser_;
  ::RPG_Dice_ValueRange_Type_pskel* range_parser_;
  ::RPG_Monster_OrganizationSlaverStep_Type_pskel* slaves_parser_;
};

class RPG_Monster_Organizations_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  step (const RPG_Monster_OrganizationStep&);

  virtual RPG_Monster_Organizations
  post_RPG_Monster_Organizations_Type () = 0;

  // Parser construction API.
  //
  void
  step_parser (::RPG_Monster_OrganizationStep_Type_pskel&);

  void
  parsers (::RPG_Monster_OrganizationStep_Type_pskel& /* step */);

  // Constructor.
  //
  RPG_Monster_Organizations_Type_pskel ();

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
  ::RPG_Monster_OrganizationStep_Type_pskel* step_parser_;
};

class RPG_Monster_AdvancementStep_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  size (const RPG_Character_Size&);

  virtual void
  range (const RPG_Dice_ValueRange&);

  virtual RPG_Monster_AdvancementStep
  post_RPG_Monster_AdvancementStep_Type () = 0;

  // Parser construction API.
  //
  void
  size_parser (::RPG_Character_Size_Type_pskel&);

  void
  range_parser (::RPG_Dice_ValueRange_Type_pskel&);

  void
  parsers (::RPG_Character_Size_Type_pskel& /* size */,
           ::RPG_Dice_ValueRange_Type_pskel& /* range */);

  // Constructor.
  //
  RPG_Monster_AdvancementStep_Type_pskel ();

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
  ::RPG_Dice_ValueRange_Type_pskel* range_parser_;
};

class RPG_Monster_Advancement_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  step (const RPG_Monster_AdvancementStep&);

  virtual RPG_Monster_Advancement
  post_RPG_Monster_Advancement_Type () = 0;

  // Parser construction API.
  //
  void
  step_parser (::RPG_Monster_AdvancementStep_Type_pskel&);

  void
  parsers (::RPG_Monster_AdvancementStep_Type_pskel& /* step */);

  // Constructor.
  //
  RPG_Monster_Advancement_Type_pskel ();

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
  ::RPG_Monster_AdvancementStep_Type_pskel* step_parser_;
};

class RPG_Monster_PropertiesXML_Type_pskel: public ::xml_schema::complex_content
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
  type (const RPG_Monster_Type&);

  virtual void
  hitDice (const RPG_Dice_Roll&);

  virtual void
  initiative (signed char);

  virtual void
  speed (unsigned char);

  virtual void
  armorClass (const RPG_Monster_NaturalArmorClass&);

  virtual void
  attack (const RPG_Monster_Attack&);

  virtual void
  space (unsigned char);

  virtual void
  reach (unsigned char);

  virtual void
  saves (const RPG_Monster_SavingThrowModifiers&);

  virtual void
  attributes (const RPG_Character_Attributes&);

  virtual void
  skills (const RPG_Character_Skills&);

  virtual void
  feats (const RPG_Character_Feats&);

  virtual void
  environment (const RPG_Character_Environment&);

  virtual void
  organizations (const RPG_Monster_Organizations&);

  virtual void
  challengeRating (unsigned char);

  virtual void
  treasureModifier (unsigned char);

  virtual void
  alignment (const RPG_Character_Alignment&);

  virtual void
  advancements (const RPG_Monster_Advancement&);

  virtual void
  levelAdjustment (unsigned char);

  virtual RPG_Monster_PropertiesXML
  post_RPG_Monster_PropertiesXML_Type () = 0;

  // Parser construction API.
  //
  void
  name_parser (::xml_schema::string_pskel&);

  void
  size_parser (::RPG_Character_Size_Type_pskel&);

  void
  type_parser (::RPG_Monster_Type_Type_pskel&);

  void
  hitDice_parser (::RPG_Dice_Roll_Type_pskel&);

  void
  initiative_parser (::xml_schema::byte_pskel&);

  void
  speed_parser (::xml_schema::unsigned_byte_pskel&);

  void
  armorClass_parser (::RPG_Monster_NaturalArmorClass_Type_pskel&);

  void
  attack_parser (::RPG_Monster_Attack_Type_pskel&);

  void
  space_parser (::xml_schema::unsigned_byte_pskel&);

  void
  reach_parser (::xml_schema::unsigned_byte_pskel&);

  void
  saves_parser (::RPG_Monster_SavingThrowModifiers_Type_pskel&);

  void
  attributes_parser (::RPG_Character_Attributes_Type_pskel&);

  void
  skills_parser (::RPG_Character_Skills_Type_pskel&);

  void
  feats_parser (::RPG_Character_Feats_Type_pskel&);

  void
  environment_parser (::RPG_Character_Environment_Type_pskel&);

  void
  organizations_parser (::RPG_Monster_Organizations_Type_pskel&);

  void
  challengeRating_parser (::xml_schema::unsigned_byte_pskel&);

  void
  treasureModifier_parser (::xml_schema::unsigned_byte_pskel&);

  void
  alignment_parser (::RPG_Character_Alignment_Type_pskel&);

  void
  advancements_parser (::RPG_Monster_Advancement_Type_pskel&);

  void
  levelAdjustment_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::xml_schema::string_pskel& /* name */,
           ::RPG_Character_Size_Type_pskel& /* size */,
           ::RPG_Monster_Type_Type_pskel& /* type */,
           ::RPG_Dice_Roll_Type_pskel& /* hitDice */,
           ::xml_schema::byte_pskel& /* initiative */,
           ::xml_schema::unsigned_byte_pskel& /* speed */,
           ::RPG_Monster_NaturalArmorClass_Type_pskel& /* armorClass */,
           ::RPG_Monster_Attack_Type_pskel& /* attack */,
           ::xml_schema::unsigned_byte_pskel& /* space */,
           ::xml_schema::unsigned_byte_pskel& /* reach */,
           ::RPG_Monster_SavingThrowModifiers_Type_pskel& /* saves */,
           ::RPG_Character_Attributes_Type_pskel& /* attributes */,
           ::RPG_Character_Skills_Type_pskel& /* skills */,
           ::RPG_Character_Feats_Type_pskel& /* feats */,
           ::RPG_Character_Environment_Type_pskel& /* environment */,
           ::RPG_Monster_Organizations_Type_pskel& /* organizations */,
           ::xml_schema::unsigned_byte_pskel& /* challengeRating */,
           ::xml_schema::unsigned_byte_pskel& /* treasureModifier */,
           ::RPG_Character_Alignment_Type_pskel& /* alignment */,
           ::RPG_Monster_Advancement_Type_pskel& /* advancements */,
           ::xml_schema::unsigned_byte_pskel& /* levelAdjustment */);

  // Constructor.
  //
  RPG_Monster_PropertiesXML_Type_pskel ();

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
  ::RPG_Monster_Type_Type_pskel* type_parser_;
  ::RPG_Dice_Roll_Type_pskel* hitDice_parser_;
  ::xml_schema::byte_pskel* initiative_parser_;
  ::xml_schema::unsigned_byte_pskel* speed_parser_;
  ::RPG_Monster_NaturalArmorClass_Type_pskel* armorClass_parser_;
  ::RPG_Monster_Attack_Type_pskel* attack_parser_;
  ::xml_schema::unsigned_byte_pskel* space_parser_;
  ::xml_schema::unsigned_byte_pskel* reach_parser_;
  ::RPG_Monster_SavingThrowModifiers_Type_pskel* saves_parser_;
  ::RPG_Character_Attributes_Type_pskel* attributes_parser_;
  ::RPG_Character_Skills_Type_pskel* skills_parser_;
  ::RPG_Character_Feats_Type_pskel* feats_parser_;
  ::RPG_Character_Environment_Type_pskel* environment_parser_;
  ::RPG_Monster_Organizations_Type_pskel* organizations_parser_;
  ::xml_schema::unsigned_byte_pskel* challengeRating_parser_;
  ::xml_schema::unsigned_byte_pskel* treasureModifier_parser_;
  ::RPG_Character_Alignment_Type_pskel* alignment_parser_;
  ::RPG_Monster_Advancement_Type_pskel* advancements_parser_;
  ::xml_schema::unsigned_byte_pskel* levelAdjustment_parser_;
};

class RPG_Monster_Dictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  monster (const RPG_Monster_PropertiesXML&);

  virtual void
  post_RPG_Monster_Dictionary_Type ();

  // Parser construction API.
  //
  void
  monster_parser (::RPG_Monster_PropertiesXML_Type_pskel&);

  void
  parsers (::RPG_Monster_PropertiesXML_Type_pskel& /* monster */);

  // Constructor.
  //
  RPG_Monster_Dictionary_Type_pskel ();

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
  ::RPG_Monster_PropertiesXML_Type_pskel* monster_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX_____RPG_MONSTER_XML_TYPES_H
