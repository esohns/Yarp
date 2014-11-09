
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_COMMON_TERRAIN_H
#define RPG_COMMON_TERRAIN_H

enum RPG_Common_Terrain
{
  TERRAIN_DESERT_SANDY = 0,
  TERRAIN_FOREST,
  TERRAIN_HILLS,
  TERRAIN_JUNGLE,
  TERRAIN_MOOR,
  TERRAIN_MOUNTAINS,
  TERRAIN_PLAINS,
  TERRAIN_PLANE_INNER_AIR,
  TERRAIN_PLANE_INNER_EARTH,
  TERRAIN_PLANE_INNER_FIRE,
  TERRAIN_PLANE_INNER_WATER,
  TERRAIN_PLANE_INNER_POSITIVE,
  TERRAIN_PLANE_INNER_NEGATIVE,
  TERRAIN_PLANE_INNER_ANY,
  TERRAIN_PLANE_MATERIAL_ANY,
  TERRAIN_PLANE_OUTER_LAWFUL_ANY,
  TERRAIN_PLANE_OUTER_CHAOTIC_ANY,
  TERRAIN_PLANE_OUTER_GOOD_ANY,
  TERRAIN_PLANE_OUTER_EVIL_ANY,
  TERRAIN_PLANE_OUTER_LAWFUL_GOOD,
  TERRAIN_PLANE_OUTER_LAWFUL_EVIL,
  TERRAIN_PLANE_OUTER_CHAOTIC_GOOD,
  TERRAIN_PLANE_OUTER_CHAOTIC_EVIL,
  TERRAIN_PLANE_OUTER_NEUTRAL,
  TERRAIN_PLANE_OUTER_MILD_ANY,
  TERRAIN_PLANE_OUTER_STRONG_ANY,
  TERRAIN_PLANE_OUTER_ANY,
  TERRAIN_PLANE_TRANSITIVE_ASTRAL,
  TERRAIN_PLANE_TRANSITIVE_ETHERAL,
  TERRAIN_PLANE_TRANSITIVE_SHADOW,
  TERRAIN_PLANE_TRANSITIVE_ANY,
  TERRAIN_SETTLEMENT,
  TERRAIN_SWAMP,
  TERRAIN_TUNDRA_FROZEN,
  TERRAIN_UNDER_GROUND,
  TERRAIN_UNDER_WATER,
  TERRAIN_ANY,
  //
  RPG_COMMON_TERRAIN_MAX,
  RPG_COMMON_TERRAIN_INVALID
};

#include "rpg_common_exports.h"

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Common_Terrain, std::string> RPG_Common_TerrainToStringTable_t;
typedef RPG_Common_TerrainToStringTable_t::const_iterator RPG_Common_TerrainToStringTableIterator_t;

class RPG_Common_Export RPG_Common_TerrainHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_TerrainToStringTable.clear();
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_DESERT_SANDY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_DESERT_SANDY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_FOREST, ACE_TEXT_ALWAYS_CHAR("TERRAIN_FOREST")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_HILLS, ACE_TEXT_ALWAYS_CHAR("TERRAIN_HILLS")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_JUNGLE, ACE_TEXT_ALWAYS_CHAR("TERRAIN_JUNGLE")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_MOOR, ACE_TEXT_ALWAYS_CHAR("TERRAIN_MOOR")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_MOUNTAINS, ACE_TEXT_ALWAYS_CHAR("TERRAIN_MOUNTAINS")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLAINS, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLAINS")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_INNER_AIR, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_INNER_AIR")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_INNER_EARTH, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_INNER_EARTH")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_INNER_FIRE, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_INNER_FIRE")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_INNER_WATER, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_INNER_WATER")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_INNER_POSITIVE, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_INNER_POSITIVE")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_INNER_NEGATIVE, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_INNER_NEGATIVE")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_INNER_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_INNER_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_MATERIAL_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_MATERIAL_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_LAWFUL_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_LAWFUL_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_CHAOTIC_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_CHAOTIC_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_GOOD_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_GOOD_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_EVIL_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_EVIL_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_LAWFUL_GOOD, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_LAWFUL_GOOD")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_LAWFUL_EVIL, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_LAWFUL_EVIL")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_CHAOTIC_GOOD, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_CHAOTIC_GOOD")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_CHAOTIC_EVIL, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_CHAOTIC_EVIL")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_NEUTRAL, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_NEUTRAL")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_MILD_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_MILD_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_STRONG_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_STRONG_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_OUTER_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_OUTER_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_TRANSITIVE_ASTRAL, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_TRANSITIVE_ASTRAL")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_TRANSITIVE_ETHERAL, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_TRANSITIVE_ETHERAL")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_TRANSITIVE_SHADOW, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_TRANSITIVE_SHADOW")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_PLANE_TRANSITIVE_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_PLANE_TRANSITIVE_ANY")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_SETTLEMENT, ACE_TEXT_ALWAYS_CHAR("TERRAIN_SETTLEMENT")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_SWAMP, ACE_TEXT_ALWAYS_CHAR("TERRAIN_SWAMP")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_TUNDRA_FROZEN, ACE_TEXT_ALWAYS_CHAR("TERRAIN_TUNDRA_FROZEN")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_UNDER_GROUND, ACE_TEXT_ALWAYS_CHAR("TERRAIN_UNDER_GROUND")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_UNDER_WATER, ACE_TEXT_ALWAYS_CHAR("TERRAIN_UNDER_WATER")));
    myRPG_Common_TerrainToStringTable.insert(std::make_pair(TERRAIN_ANY, ACE_TEXT_ALWAYS_CHAR("TERRAIN_ANY")));
  };

  inline static std::string RPG_Common_TerrainToString(const RPG_Common_Terrain& element_in)
  {
    std::string result;
    RPG_Common_TerrainToStringTableIterator_t iterator = myRPG_Common_TerrainToStringTable.find(element_in);
    if (iterator != myRPG_Common_TerrainToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_TERRAIN_INVALID");

    return result;
  };

  inline static RPG_Common_Terrain stringToRPG_Common_Terrain(const std::string& string_in)
  {
    RPG_Common_TerrainToStringTableIterator_t iterator = myRPG_Common_TerrainToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_TerrainToStringTable.end());

    return RPG_COMMON_TERRAIN_INVALID;
  };

  static RPG_Common_TerrainToStringTable_t myRPG_Common_TerrainToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_TerrainHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_TerrainHelper(const RPG_Common_TerrainHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_TerrainHelper& operator=(const RPG_Common_TerrainHelper&));
};

#endif
