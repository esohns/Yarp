
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_TILESETGRAPHIC_H
#define RPG_GRAPHICS_TILESETGRAPHIC_H

enum RPG_Graphics_TileSetGraphic
{
  TILESET_DOOR_WOOD = 0,
  TILESET_FLOOR_AIR,
  TILESET_FLOOR_CARPET,
  TILESET_FLOOR_CERAMIC,
  TILESET_FLOOR_DARK,
  TILESET_FLOOR_ICE,
  TILESET_FLOOR_LAVA,
  TILESET_FLOOR_MARBLE,
  TILESET_FLOOR_MURAL,
  TILESET_FLOOR_MURAL2,
  TILESET_FLOOR_ROUGH,
  TILESET_FLOOR_ROUGH_LIT,
  TILESET_FLOOR_STONE_COBBLED,
  TILESET_FLOOR_STONE_MOSS_COVERED,
  TILESET_FLOOR_WATER,
  TILESET_EDGE_FLOOR_STONE_COBBLED,
  TILESET_WALL_BRICK,
  TILESET_WALL_BRICK_HALF,
  TILESET_WALL_BRICK_BANNER,
  TILESET_WALL_BRICK_BANNER_HALF,
  TILESET_WALL_BRICK_PAINTING,
  TILESET_WALL_BRICK_PAINTING_HALF,
  TILESET_WALL_BRICK_PILLAR,
  TILESET_WALL_BRICK_PILLAR_HALF,
  TILESET_WALL_BRICK_POCKET,
  TILESET_WALL_BRICK_POCKET_HALF,
  TILESET_WALL_DARK,
  TILESET_WALL_DARK_HALF,
  TILESET_WALL_LIGHT,
  TILESET_WALL_LIGHT_HALF,
  TILESET_WALL_MARBLE,
  TILESET_WALL_MARBLE_HALF,
  TILESET_WALL_ROUGH,
  TILESET_WALL_ROUGH_HALF,
  TILESET_WALL_STUCCO,
  TILESET_WALL_STUCCO_HALF,
  TILESET_WALL_VINE_COVERED,
  TILESET_WALL_VINE_COVERED_HALF,
  //
  RPG_GRAPHICS_TILESETGRAPHIC_MAX,
  RPG_GRAPHICS_TILESETGRAPHIC_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_TileSetGraphic, std::string> RPG_Graphics_TileSetGraphicToStringTable_t;
typedef RPG_Graphics_TileSetGraphicToStringTable_t::const_iterator RPG_Graphics_TileSetGraphicToStringTableIterator_t;

class RPG_Graphics_TileSetGraphicHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_TileSetGraphicToStringTable.clear();
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_DOOR_WOOD, ACE_TEXT_ALWAYS_CHAR("TILESET_DOOR_WOOD")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_AIR, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_AIR")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_CARPET, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_CARPET")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_CERAMIC, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_CERAMIC")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_DARK, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_DARK")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_ICE, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_ICE")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_LAVA, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_LAVA")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_MARBLE, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_MARBLE")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_MURAL, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_MURAL")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_MURAL2, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_MURAL2")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_ROUGH, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_ROUGH")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_ROUGH_LIT, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_ROUGH_LIT")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_STONE_COBBLED, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_STONE_COBBLED")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_STONE_MOSS_COVERED, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_STONE_MOSS_COVERED")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_FLOOR_WATER, ACE_TEXT_ALWAYS_CHAR("TILESET_FLOOR_WATER")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_EDGE_FLOOR_STONE_COBBLED, ACE_TEXT_ALWAYS_CHAR("TILESET_EDGE_FLOOR_STONE_COBBLED")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_BANNER, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_BANNER")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_BANNER_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_BANNER_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_PAINTING, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_PAINTING")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_PAINTING_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_PAINTING_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_PILLAR, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_PILLAR")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_PILLAR_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_PILLAR_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_POCKET, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_POCKET")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_BRICK_POCKET_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_BRICK_POCKET_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_DARK, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_DARK")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_DARK_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_DARK_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_LIGHT, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_LIGHT")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_LIGHT_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_LIGHT_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_MARBLE, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_MARBLE")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_MARBLE_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_MARBLE_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_ROUGH, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_ROUGH")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_ROUGH_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_ROUGH_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_STUCCO, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_STUCCO")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_STUCCO_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_STUCCO_HALF")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_VINE_COVERED, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_VINE_COVERED")));
    myRPG_Graphics_TileSetGraphicToStringTable.insert(std::make_pair(TILESET_WALL_VINE_COVERED_HALF, ACE_TEXT_ALWAYS_CHAR("TILESET_WALL_VINE_COVERED_HALF")));
  };

  inline static std::string RPG_Graphics_TileSetGraphicToString(const RPG_Graphics_TileSetGraphic& element_in)
  {
    std::string result;
    RPG_Graphics_TileSetGraphicToStringTableIterator_t iterator = myRPG_Graphics_TileSetGraphicToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_TileSetGraphicToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_TILESETGRAPHIC_INVALID");

    return result;
  };

  inline static RPG_Graphics_TileSetGraphic stringToRPG_Graphics_TileSetGraphic(const std::string& string_in)
  {
    RPG_Graphics_TileSetGraphicToStringTableIterator_t iterator = myRPG_Graphics_TileSetGraphicToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_TileSetGraphicToStringTable.end());

    return RPG_GRAPHICS_TILESETGRAPHIC_INVALID;
  };

  static RPG_Graphics_TileSetGraphicToStringTable_t myRPG_Graphics_TileSetGraphicToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileSetGraphicHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileSetGraphicHelper(const RPG_Graphics_TileSetGraphicHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileSetGraphicHelper& operator=(const RPG_Graphics_TileSetGraphicHelper&));
};

#endif
