
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_STYLEUNION_H
#define RPG_GRAPHICS_STYLEUNION_H

#include "rpg_graphics_exports.h"

struct RPG_Graphics_Export RPG_Graphics_StyleUnion
{
  union
  {
    RPG_Graphics_FloorStyle floorstyle;
    RPG_Graphics_StairsStyle stairsstyle;
    RPG_Graphics_WallStyle wallstyle;
    RPG_Graphics_EdgeStyle edgestyle;
    RPG_Graphics_DoorStyle doorstyle;
  };

  enum Discriminator_t
  {
    FLOORSTYLE,
    STAIRSSTYLE,
    WALLSTYLE,
    EDGESTYLE,
    DOORSTYLE,
    INVALID
  };
  Discriminator_t discriminator;
};

#endif
