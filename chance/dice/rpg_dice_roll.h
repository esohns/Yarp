
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_DICE_ROLL_H
#define RPG_DICE_ROLL_H

struct RPG_Dice_Roll
{
  unsigned int numDice;
  RPG_Dice_DieType typeDice;
  int modifier;

	RPG_Dice_Roll& operator*=(int);
};

#endif
