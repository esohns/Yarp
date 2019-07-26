
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_CHECKTYPEUNION_H
#define RPG_MAGIC_CHECKTYPEUNION_H

struct RPG_Magic_CheckTypeUnion
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
