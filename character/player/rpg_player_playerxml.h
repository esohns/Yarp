
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_PLAYER_PLAYERXML_H
#define RPG_PLAYER_PLAYERXML_H

struct RPG_Player_PlayerXML
 : public RPG_Player_CharacterXML
{
  unsigned int gold;
  RPG_Item_InventoryXML inventory;
  unsigned int XP;
};

#endif
