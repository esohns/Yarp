
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_COMBAT_RANGEDEFFECTUNION_H
#define RPG_COMBAT_RANGEDEFFECTUNION_H

struct RPG_Combat_RangedEffectUnion
{
  union
  {
    RPG_Common_Size size;
    RPG_Common_AreaOfEffect areaofeffect;
  };

  enum Discriminator_t
  {
    SIZE,
    AREAOFEFFECT,
    INVALID
  };
  Discriminator_t discriminator;
};

#endif
