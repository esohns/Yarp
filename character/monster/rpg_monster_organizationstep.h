
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MONSTER_ORGANIZATIONSTEP_H
#define RPG_MONSTER_ORGANIZATIONSTEP_H

#include "rpg_monster_exports.h"

struct RPG_Monster_Export RPG_Monster_OrganizationStep
{
  RPG_Monster_Organization type;
  RPG_Dice_ValueRange range;
  std::vector<RPG_Monster_OrganizationSlaverStep> slaves;
};

#endif
