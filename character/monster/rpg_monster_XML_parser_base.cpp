// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#include "rpg_monster_XML_parser_base.h"

// RPG_Monster_MetaType_Type_pimpl
//

void RPG_Monster_MetaType_Type_pimpl::
pre ()
{
}

RPG_Monster_MetaType RPG_Monster_MetaType_Type_pimpl::
post_RPG_Monster_MetaType_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Monster_SubType_Type_pimpl
//

void RPG_Monster_SubType_Type_pimpl::
pre ()
{
}

RPG_Monster_SubType RPG_Monster_SubType_Type_pimpl::
post_RPG_Monster_SubType_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Monster_Type_Type_pimpl
//

void RPG_Monster_Type_Type_pimpl::
pre ()
{
}

void RPG_Monster_Type_Type_pimpl::
metaType (const RPG_Monster_MetaType& metaType)
{
  // TODO
  //
}

void RPG_Monster_Type_Type_pimpl::
subType (const RPG_Monster_SubType& subType)
{
  // TODO
  //
}

RPG_Monster_Type RPG_Monster_Type_Type_pimpl::
post_RPG_Monster_Type_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_NaturalArmorClass_Type_pimpl
//

void RPG_Monster_NaturalArmorClass_Type_pimpl::
pre ()
{
}

void RPG_Monster_NaturalArmorClass_Type_pimpl::
normal (signed char normal)
{
  // TODO
  //
}

void RPG_Monster_NaturalArmorClass_Type_pimpl::
touch (signed char touch)
{
  // TODO
  //
}

void RPG_Monster_NaturalArmorClass_Type_pimpl::
flatFooted (signed char flatFooted)
{
  // TODO
  //
}

RPG_Monster_NaturalArmorClass RPG_Monster_NaturalArmorClass_Type_pimpl::
post_RPG_Monster_NaturalArmorClass_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_NaturalWeapon_Type_pimpl
//

void RPG_Monster_NaturalWeapon_Type_pimpl::
pre ()
{
}

RPG_Monster_NaturalWeapon RPG_Monster_NaturalWeapon_Type_pimpl::
post_RPG_Monster_NaturalWeapon_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Monster_AttackAction_Type_pimpl
//

void RPG_Monster_AttackAction_Type_pimpl::
pre ()
{
}

void RPG_Monster_AttackAction_Type_pimpl::
monsterWeapon (const RPG_Monster_NaturalWeapon& monsterWeapon)
{
  // TODO
  //
}

void RPG_Monster_AttackAction_Type_pimpl::
attackBonus (signed char attackBonus)
{
  // TODO
  //
}

void RPG_Monster_AttackAction_Type_pimpl::
attackForm (const RPG_Combat_AttackForm& attackForm)
{
  // TODO
  //
}

void RPG_Monster_AttackAction_Type_pimpl::
physicalDamage (const RPG_Dice_Roll& physicalDamage)
{
  // TODO
  //
}

void RPG_Monster_AttackAction_Type_pimpl::
numAttacksPerRound (unsigned char numAttacksPerRound)
{
  // TODO
  //
}

RPG_Monster_AttackAction RPG_Monster_AttackAction_Type_pimpl::
post_RPG_Monster_AttackAction_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_Attack_Type_pimpl
//

void RPG_Monster_Attack_Type_pimpl::
pre ()
{
}

void RPG_Monster_Attack_Type_pimpl::
baseAttackBonus (signed char baseAttackBonus)
{
  // TODO
  //
}

void RPG_Monster_Attack_Type_pimpl::
grappleBonus (signed char grappleBonus)
{
  // TODO
  //
}

void RPG_Monster_Attack_Type_pimpl::
standardAttackAction (const RPG_Monster_AttackAction& standardAttackAction)
{
  // TODO
  //
}

void RPG_Monster_Attack_Type_pimpl::
fullAttackAction (const RPG_Monster_AttackAction& fullAttackAction)
{
  // TODO
  //
}

RPG_Monster_Attack RPG_Monster_Attack_Type_pimpl::
post_RPG_Monster_Attack_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_SavingThrowModifiers_Type_pimpl
//

void RPG_Monster_SavingThrowModifiers_Type_pimpl::
pre ()
{
}

void RPG_Monster_SavingThrowModifiers_Type_pimpl::
fortitude (signed char fortitude)
{
  // TODO
  //
}

void RPG_Monster_SavingThrowModifiers_Type_pimpl::
reflex (signed char reflex)
{
  // TODO
  //
}

void RPG_Monster_SavingThrowModifiers_Type_pimpl::
will (signed char will)
{
  // TODO
  //
}

RPG_Monster_SavingThrowModifiers RPG_Monster_SavingThrowModifiers_Type_pimpl::
post_RPG_Monster_SavingThrowModifiers_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_Organization_Type_pimpl
//

void RPG_Monster_Organization_Type_pimpl::
pre ()
{
}

RPG_Monster_Organization RPG_Monster_Organization_Type_pimpl::
post_RPG_Monster_Organization_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Monster_OrganizationSlaverStep_Type_pimpl
//

void RPG_Monster_OrganizationSlaverStep_Type_pimpl::
pre ()
{
}

void RPG_Monster_OrganizationSlaverStep_Type_pimpl::
name (const ::std::string& name)
{
  // TODO
  //
}

void RPG_Monster_OrganizationSlaverStep_Type_pimpl::
range (const RPG_Dice_ValueRange& range)
{
  // TODO
  //
}

RPG_Monster_OrganizationSlaverStep RPG_Monster_OrganizationSlaverStep_Type_pimpl::
post_RPG_Monster_OrganizationSlaverStep_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_OrganizationStep_Type_pimpl
//

void RPG_Monster_OrganizationStep_Type_pimpl::
pre ()
{
}

void RPG_Monster_OrganizationStep_Type_pimpl::
type (const RPG_Monster_Organization& type)
{
  // TODO
  //
}

void RPG_Monster_OrganizationStep_Type_pimpl::
range (const RPG_Dice_ValueRange& range)
{
  // TODO
  //
}

void RPG_Monster_OrganizationStep_Type_pimpl::
slaves (const RPG_Monster_OrganizationSlaverStep& slaves)
{
  // TODO
  //
}

RPG_Monster_OrganizationStep RPG_Monster_OrganizationStep_Type_pimpl::
post_RPG_Monster_OrganizationStep_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_Organizations_Type_pimpl
//

void RPG_Monster_Organizations_Type_pimpl::
pre ()
{
}

void RPG_Monster_Organizations_Type_pimpl::
step (const RPG_Monster_OrganizationStep& step)
{
  // TODO
  //
}

RPG_Monster_Organizations RPG_Monster_Organizations_Type_pimpl::
post_RPG_Monster_Organizations_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_AdvancementStep_Type_pimpl
//

void RPG_Monster_AdvancementStep_Type_pimpl::
pre ()
{
}

void RPG_Monster_AdvancementStep_Type_pimpl::
size (const RPG_Character_Size& size)
{
  // TODO
  //
}

void RPG_Monster_AdvancementStep_Type_pimpl::
range (const RPG_Dice_ValueRange& range)
{
  // TODO
  //
}

RPG_Monster_AdvancementStep RPG_Monster_AdvancementStep_Type_pimpl::
post_RPG_Monster_AdvancementStep_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_Advancement_Type_pimpl
//

void RPG_Monster_Advancement_Type_pimpl::
pre ()
{
}

void RPG_Monster_Advancement_Type_pimpl::
step (const RPG_Monster_AdvancementStep& step)
{
  // TODO
  //
}

RPG_Monster_Advancement RPG_Monster_Advancement_Type_pimpl::
post_RPG_Monster_Advancement_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_PropertiesXML_Type_pimpl
//

void RPG_Monster_PropertiesXML_Type_pimpl::
pre ()
{
}

void RPG_Monster_PropertiesXML_Type_pimpl::
name (const ::std::string& name)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
size (const RPG_Character_Size& size)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
type (const RPG_Monster_Type& type)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
hitDice (const RPG_Dice_Roll& hitDice)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
initiative (signed char initiative)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
speed (unsigned char speed)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
armorClass (const RPG_Monster_NaturalArmorClass& armorClass)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
attack (const RPG_Monster_Attack& attack)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
space (unsigned char space)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
reach (unsigned char reach)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
saves (const RPG_Monster_SavingThrowModifiers& saves)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
attributes (const RPG_Character_Attributes& attributes)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
skills (const RPG_Character_Skills& skills)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
feats (const RPG_Character_Feats& feats)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
environment (const RPG_Character_Environment& environment)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
organizations (const RPG_Monster_Organizations& organizations)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
challengeRating (unsigned char challengeRating)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
treasureModifier (unsigned char treasureModifier)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
alignment (const RPG_Character_Alignment& alignment)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
advancements (const RPG_Monster_Advancement& advancements)
{
  // TODO
  //
}

void RPG_Monster_PropertiesXML_Type_pimpl::
levelAdjustment (unsigned char levelAdjustment)
{
  // TODO
  //
}

RPG_Monster_PropertiesXML RPG_Monster_PropertiesXML_Type_pimpl::
post_RPG_Monster_PropertiesXML_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Monster_Dictionary_Type_pimpl
//

void RPG_Monster_Dictionary_Type_pimpl::
pre ()
{
}

void RPG_Monster_Dictionary_Type_pimpl::
monster (const RPG_Monster_PropertiesXML& monster)
{
  // TODO
  //
}

void RPG_Monster_Dictionary_Type_pimpl::
post_RPG_Monster_Dictionary_Type ()
{
}

