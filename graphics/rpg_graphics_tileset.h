
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_TILESET_H
#define RPG_GRAPHICS_TILESET_H

struct RPG_Graphics_TileSet
{
  RPG_Graphics_TileSetType type;
  RPG_Graphics_StyleUnion style;
  std::vector<RPG_Graphics_Tile> tiles;
  bool half;
};

#endif
