// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#include <rpg_combat_XML_parser_base.h>

// RPG_Combat_AttackForm_Type_pimpl
//

void RPG_Combat_AttackForm_Type_pimpl::
pre ()
{
}

RPG_Combat_AttackForm RPG_Combat_AttackForm_Type_pimpl::
post_RPG_Combat_AttackForm_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Combat_AttackSituation_Type_pimpl
//

void RPG_Combat_AttackSituation_Type_pimpl::
pre ()
{
}

RPG_Combat_AttackSituation RPG_Combat_AttackSituation_Type_pimpl::
post_RPG_Combat_AttackSituation_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Combat_DefenseSituation_Type_pimpl
//

void RPG_Combat_DefenseSituation_Type_pimpl::
pre ()
{
}

RPG_Combat_DefenseSituation RPG_Combat_DefenseSituation_Type_pimpl::
post_RPG_Combat_DefenseSituation_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Combat_SpecialAttack_Type_pimpl
//

void RPG_Combat_SpecialAttack_Type_pimpl::
pre ()
{
}

RPG_Combat_SpecialAttack RPG_Combat_SpecialAttack_Type_pimpl::
post_RPG_Combat_SpecialAttack_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Combat_SpecialDamageType_Type_pimpl
//

void RPG_Combat_SpecialDamageType_Type_pimpl::
pre ()
{
}

RPG_Combat_SpecialDamageType RPG_Combat_SpecialDamageType_Type_pimpl::
post_RPG_Combat_SpecialDamageType_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Combat_DamageEffectType_Type_pimpl
//

void RPG_Combat_DamageEffectType_Type_pimpl::
pre ()
{
}

RPG_Combat_DamageEffectType RPG_Combat_DamageEffectType_Type_pimpl::
post_RPG_Combat_DamageEffectType_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Combat_DamageTypeUnion_Type_pimpl
//

void RPG_Combat_DamageTypeUnion_Type_pimpl::
pre ()
{
}

void RPG_Combat_DamageTypeUnion_Type_pimpl::
_characters (const ::xml_schema::ro_string& s)
{
  // TODO
  //
}

RPG_Combat_DamageTypeUnion RPG_Combat_DamageTypeUnion_Type_pimpl::
post_RPG_Combat_DamageTypeUnion_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Combat_DamageElement_Type_pimpl
//

void RPG_Combat_DamageElement_Type_pimpl::
pre ()
{
}

void RPG_Combat_DamageElement_Type_pimpl::
type (const RPG_Combat_DamageTypeUnion& type)
{
  // TODO
  //
}

void RPG_Combat_DamageElement_Type_pimpl::
damage (const RPG_Dice_Roll& damage)
{
  // TODO
  //
}

void RPG_Combat_DamageElement_Type_pimpl::
duration (unsigned short duration)
{
  // TODO
  //
}

void RPG_Combat_DamageElement_Type_pimpl::
effect (const RPG_Combat_DamageEffectType& effect)
{
  // TODO
  //
}

RPG_Combat_DamageElement RPG_Combat_DamageElement_Type_pimpl::
post_RPG_Combat_DamageElement_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Combat_Damage_Type_pimpl
//

void RPG_Combat_Damage_Type_pimpl::
pre ()
{
}

void RPG_Combat_Damage_Type_pimpl::
element (const RPG_Combat_DamageElement& element)
{
  // TODO
  //
}

RPG_Combat_Damage RPG_Combat_Damage_Type_pimpl::
post_RPG_Combat_Damage_Type ()
{
  // TODO
  //
  // return ... ;
}

