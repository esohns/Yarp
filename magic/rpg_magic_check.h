
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_CHECK_H
#define RPG_MAGIC_CHECK_H

struct RPG_Magic_Check
{
  RPG_Magic_CheckTypeUnion type;
  unsigned char difficultyClass;
  signed char modifier;
  unsigned char levelIncrementMax;
  bool baseIsCasterLevel;
};

#endif
