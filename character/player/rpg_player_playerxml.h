
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_PLAYER_PLAYERXML_H
#define RPG_PLAYER_PLAYERXML_H

#include "rpg_player_exports.h"

struct RPG_Player_Export RPG_Player_PlayerXML
 : public RPG_Player_CharacterXML
{
  unsigned int gold;
  RPG_Item_InventoryXML inventory;
  unsigned int XP;
};

#endif
