
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_COMBAT_DAMAGECOUNTERMEASURE_H
#define RPG_COMBAT_DAMAGECOUNTERMEASURE_H

struct RPG_Combat_DamageCounterMeasure
{
  RPG_Common_CounterMeasure type;
  RPG_Combat_Check check;
  std::vector<RPG_Magic_SpellType> spells;
  RPG_Common_Duration duration;
  RPG_Common_Condition condition;
  RPG_Combat_DamageReductionType reduction;
};

#endif
