
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_TILE_H
#define RPG_GRAPHICS_TILE_H

#include "rpg_graphics_exports.h"

struct RPG_Graphics_Export RPG_Graphics_Tile
{
  RPG_Graphics_TileType type;
  RPG_Graphics_GraphicTypeUnion reference;
  RPG_Graphics_StyleUnion style;
  RPG_Graphics_Orientation orientation;
  std::string file;
  int offsetX;
  int offsetY;
  bool open;
  bool broken;
};

#endif
