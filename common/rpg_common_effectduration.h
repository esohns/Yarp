
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_COMMON_EFFECTDURATION_H
#define RPG_COMMON_EFFECTDURATION_H

struct RPG_Common_EffectDuration
{
  RPG_Common_Amount base;
  signed char levelIncrement;
  unsigned char levelIncrementMax;
  unsigned char reciprocalIncrement;
  bool isMaxDelay;
  bool incrementIsInHD;
};

#endif
