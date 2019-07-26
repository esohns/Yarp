
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_COMBAT_DAMAGETYPEUNION_H
#define RPG_COMBAT_DAMAGETYPEUNION_H

struct RPG_Combat_DamageTypeUnion
{
  union
  {
    RPG_Common_PhysicalDamageType physicaldamagetype;
    RPG_Combat_SpecialDamageType specialdamagetype;
  };

  enum Discriminator_t
  {
    PHYSICALDAMAGETYPE,
    SPECIALDAMAGETYPE,
    INVALID
  };
  Discriminator_t discriminator;
};

#endif
