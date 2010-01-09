// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#ifndef CXX___RPG_COMBAT_XML_PARSER_BASE_H
#define CXX___RPG_COMBAT_XML_PARSER_BASE_H

#include <rpg_combat_XML_types.h>

#include <rpg_dice_XML_parser_base.h>

#include <rpg_common_XML_parser_base.h>

#include <rpg_character_XML_parser_base.h>

#include <rpg_magic_XML_parser_base.h>

class RPG_Combat_AttackForm_Type_pimpl: public virtual RPG_Combat_AttackForm_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_AttackForm
  post_RPG_Combat_AttackForm_Type ();
};

class RPG_Combat_AreaOfEffect_Type_pimpl: public virtual RPG_Combat_AreaOfEffect_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_AreaOfEffect
  post_RPG_Combat_AreaOfEffect_Type ();
};

class RPG_Combat_RangedEffectUnion_Type_pimpl: public virtual RPG_Combat_RangedEffectUnion_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  _characters (const ::xml_schema::ro_string&);

  virtual RPG_Combat_RangedEffectUnion
  post_RPG_Combat_RangedEffectUnion_Type ();
};

class RPG_Combat_RangedAttackProperties_Type_pimpl: public virtual RPG_Combat_RangedAttackProperties_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  maxRange (unsigned char);

  virtual void
  increment (unsigned char);

  virtual void
  effect (const RPG_Combat_RangedEffectUnion&);

  virtual RPG_Combat_RangedAttackProperties
  post_RPG_Combat_RangedAttackProperties_Type ();
};

class RPG_Combat_AttackSituation_Type_pimpl: public virtual RPG_Combat_AttackSituation_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_AttackSituation
  post_RPG_Combat_AttackSituation_Type ();
};

class RPG_Combat_DefenseSituation_Type_pimpl: public virtual RPG_Combat_DefenseSituation_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_DefenseSituation
  post_RPG_Combat_DefenseSituation_Type ();
};

class RPG_Combat_SpecialAttack_Type_pimpl: public virtual RPG_Combat_SpecialAttack_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_SpecialAttack
  post_RPG_Combat_SpecialAttack_Type ();
};

class RPG_Combat_SpecialDamageType_Type_pimpl: public virtual RPG_Combat_SpecialDamageType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_SpecialDamageType
  post_RPG_Combat_SpecialDamageType_Type ();
};

class RPG_Combat_DamageTypeUnion_Type_pimpl: public virtual RPG_Combat_DamageTypeUnion_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  _characters (const ::xml_schema::ro_string&);

  virtual RPG_Combat_DamageTypeUnion
  post_RPG_Combat_DamageTypeUnion_Type ();
};

class RPG_Combat_DamageDuration_Type_pimpl: public virtual RPG_Combat_DamageDuration_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  incubationPeriod (const RPG_Dice_Roll&);

  virtual void
  interval (unsigned short);

  virtual void
  totalDuration (unsigned short);

  virtual RPG_Combat_DamageDuration
  post_RPG_Combat_DamageDuration_Type ();
};

class RPG_Combat_DamageBonusType_Type_pimpl: public virtual RPG_Combat_DamageBonusType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_DamageBonusType
  post_RPG_Combat_DamageBonusType_Type ();
};

class RPG_Combat_DamageBonus_Type_pimpl: public virtual RPG_Combat_DamageBonus_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  type (const RPG_Combat_DamageBonusType&);

  virtual void
  modifier (signed char);

  virtual RPG_Combat_DamageBonus
  post_RPG_Combat_DamageBonus_Type ();
};

class RPG_Combat_DamageEffectType_Type_pimpl: public virtual RPG_Combat_DamageEffectType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_DamageEffectType
  post_RPG_Combat_DamageEffectType_Type ();
};

class RPG_Combat_DamageCounterMeasureType_Type_pimpl: public virtual RPG_Combat_DamageCounterMeasureType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_DamageCounterMeasureType
  post_RPG_Combat_DamageCounterMeasureType_Type ();
};

class RPG_Combat_CheckTypeUnion_Type_pimpl: public virtual RPG_Combat_CheckTypeUnion_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  _characters (const ::xml_schema::ro_string&);

  virtual RPG_Combat_CheckTypeUnion
  post_RPG_Combat_CheckTypeUnion_Type ();
};

class RPG_Combat_Check_Type_pimpl: public virtual RPG_Combat_Check_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  type (const RPG_Combat_CheckTypeUnion&);

  virtual void
  attribute (const RPG_Common_Attribute&);

  virtual void
  difficultyClass (unsigned char);

  virtual RPG_Combat_Check
  post_RPG_Combat_Check_Type ();
};

class RPG_Combat_DamageReductionType_Type_pimpl: public virtual RPG_Combat_DamageReductionType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_DamageReductionType
  post_RPG_Combat_DamageReductionType_Type ();
};

class RPG_Combat_DamageCounterMeasure_Type_pimpl: public virtual RPG_Combat_DamageCounterMeasure_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  type (const RPG_Combat_DamageCounterMeasureType&);

  virtual void
  check (const RPG_Combat_Check&);

  virtual void
  spell (const RPG_Magic_Spell&);

  virtual void
  reduction (const RPG_Combat_DamageReductionType&);

  virtual RPG_Combat_DamageCounterMeasure
  post_RPG_Combat_DamageCounterMeasure_Type ();
};

class RPG_Combat_DamageElement_Type_pimpl: public virtual RPG_Combat_DamageElement_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  type (const RPG_Combat_DamageTypeUnion&);

  virtual void
  amount (const RPG_Dice_Roll&);

  virtual void
  secondary (const RPG_Dice_Roll&);

  virtual void
  duration (const RPG_Combat_DamageDuration&);

  virtual void
  other (const RPG_Combat_DamageBonus&);

  virtual void
  attribute (const RPG_Common_Attribute&);

  virtual void
  counterMeasure (const RPG_Combat_DamageCounterMeasure&);

  virtual void
  effect (const RPG_Combat_DamageEffectType&);

  virtual RPG_Combat_DamageElement
  post_RPG_Combat_DamageElement_Type ();
};

class RPG_Combat_Damage_Type_pimpl: public virtual RPG_Combat_Damage_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  element (const RPG_Combat_DamageElement&);

  virtual RPG_Combat_Damage
  post_RPG_Combat_Damage_Type ();
};

class RPG_Combat_ActionType_Type_pimpl: public virtual RPG_Combat_ActionType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Combat_ActionType
  post_RPG_Combat_ActionType_Type ();
};

#endif // CXX___RPG_COMBAT_XML_PARSER_BASE_H
