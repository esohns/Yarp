
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.0.1-devel
// -------------------------------- * * * ----------------------------------- //

#ifndef RPG_DICE_ROLL_H
#define RPG_DICE_ROLL_H

struct RPG_Dice_Roll
{
  ACE_UINT32 numDice;
  RPG_Dice_DieType typeDice;
  ACE_INT32 modifier;

  // *TODO* will be clobbered by subsequent updates of the schema
  // (refer to rpg_dice_common.h for a template)
  RPG_Dice_Roll& operator*= (int);
};

#endif
