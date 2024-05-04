
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.0.1-devel
// -------------------------------- * * * ----------------------------------- //

#ifndef RPG_MAP_DIRECTION_H
#define RPG_MAP_DIRECTION_H

enum RPG_Map_Direction
{
  DIRECTION_UP = 0,
  DIRECTION_RIGHT,
  DIRECTION_DOWN,
  DIRECTION_LEFT,
  //
  RPG_MAP_DIRECTION_MAX,
  RPG_MAP_DIRECTION_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Map_Direction, std::string> RPG_Map_DirectionToStringTable_t;
typedef RPG_Map_DirectionToStringTable_t::const_iterator RPG_Map_DirectionToStringTableIterator_t;

class RPG_Map_DirectionHelper
{
 public:
  inline static void init()
  {
    myRPG_Map_DirectionToStringTable.clear();
    myRPG_Map_DirectionToStringTable.insert(std::make_pair(DIRECTION_UP, ACE_TEXT_ALWAYS_CHAR("DIRECTION_UP")));
    myRPG_Map_DirectionToStringTable.insert(std::make_pair(DIRECTION_RIGHT, ACE_TEXT_ALWAYS_CHAR("DIRECTION_RIGHT")));
    myRPG_Map_DirectionToStringTable.insert(std::make_pair(DIRECTION_DOWN, ACE_TEXT_ALWAYS_CHAR("DIRECTION_DOWN")));
    myRPG_Map_DirectionToStringTable.insert(std::make_pair(DIRECTION_LEFT, ACE_TEXT_ALWAYS_CHAR("DIRECTION_LEFT")));
  };

  inline static std::string RPG_Map_DirectionToString(const RPG_Map_Direction& element_in)
  {
    std::string result;
    RPG_Map_DirectionToStringTableIterator_t iterator = myRPG_Map_DirectionToStringTable.find(element_in);
    if (iterator != myRPG_Map_DirectionToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAP_DIRECTION_INVALID");

    return result;
  };

  inline static RPG_Map_Direction stringToRPG_Map_Direction(const std::string& string_in)
  {
    RPG_Map_DirectionToStringTableIterator_t iterator = myRPG_Map_DirectionToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Map_DirectionToStringTable.end());

    return RPG_MAP_DIRECTION_INVALID;
  };

  static RPG_Map_DirectionToStringTable_t myRPG_Map_DirectionToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Map_DirectionHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Map_DirectionHelper(const RPG_Map_DirectionHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Map_DirectionHelper& operator=(const RPG_Map_DirectionHelper&));
};

#endif
