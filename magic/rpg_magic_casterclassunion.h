
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_CASTERCLASSUNION_H
#define RPG_MAGIC_CASTERCLASSUNION_H

#include "rpg_magic_exports.h"

struct RPG_Magic_Export RPG_Magic_CasterClassUnion
{
  union
  {
    RPG_Common_SubClass subclass;
    RPG_Magic_Domain domain;
  };

  enum Discriminator_t
  {
    SUBCLASS,
    __QUIRK__DOMAIN,
    INVALID
  };
  Discriminator_t discriminator;
};

#endif
