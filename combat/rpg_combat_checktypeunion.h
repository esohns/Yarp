
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_COMBAT_CHECKTYPEUNION_H
#define RPG_COMBAT_CHECKTYPEUNION_H

#include "rpg_combat_exports.h"

struct RPG_Combat_Export RPG_Combat_CheckTypeUnion
{
  union
  {
    RPG_Common_Skill skill;
    RPG_Common_Attribute attribute;
    RPG_Common_BaseCheckTypeUnion basechecktypeunion;
  };

  enum Discriminator_t
  {
    SKILL,
    ATTRIBUTE,
    BASECHECKTYPEUNION,
    INVALID
  };
  Discriminator_t discriminator;
};

#endif
