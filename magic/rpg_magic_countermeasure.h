
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_COUNTERMEASURE_H
#define RPG_MAGIC_COUNTERMEASURE_H

#include "rpg_magic_exports.h"

struct RPG_Magic_Export RPG_Magic_CounterMeasure
{
  RPG_Common_CounterMeasure type;
  RPG_Magic_Check check;
  std::vector<RPG_Magic_SpellType> spells;
  RPG_Common_SaveReductionType reduction;
};

#endif
