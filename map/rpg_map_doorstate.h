
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_MAP_DOORSTATE_H
#define RPG_MAP_DOORSTATE_H

enum RPG_Map_DoorState
{
  DOORSTATE_OPEN = 0,
  DOORSTATE_CLOSED,
  DOORSTATE_LOCKED,
  DOORSTATE_BROKEN,
  //
  RPG_MAP_DOORSTATE_MAX,
  RPG_MAP_DOORSTATE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Map_DoorState, std::string> RPG_Map_DoorStateToStringTable_t;
typedef RPG_Map_DoorStateToStringTable_t::const_iterator RPG_Map_DoorStateToStringTableIterator_t;

class RPG_Map_DoorStateHelper
{
 public:
  inline static void init()
  {
    myRPG_Map_DoorStateToStringTable.clear();
    myRPG_Map_DoorStateToStringTable.insert(std::make_pair(DOORSTATE_OPEN, ACE_TEXT_ALWAYS_CHAR("DOORSTATE_OPEN")));
    myRPG_Map_DoorStateToStringTable.insert(std::make_pair(DOORSTATE_CLOSED, ACE_TEXT_ALWAYS_CHAR("DOORSTATE_CLOSED")));
    myRPG_Map_DoorStateToStringTable.insert(std::make_pair(DOORSTATE_LOCKED, ACE_TEXT_ALWAYS_CHAR("DOORSTATE_LOCKED")));
    myRPG_Map_DoorStateToStringTable.insert(std::make_pair(DOORSTATE_BROKEN, ACE_TEXT_ALWAYS_CHAR("DOORSTATE_BROKEN")));
  };

  inline static std::string RPG_Map_DoorStateToString(const RPG_Map_DoorState& element_in)
  {
    std::string result;
    RPG_Map_DoorStateToStringTableIterator_t iterator = myRPG_Map_DoorStateToStringTable.find(element_in);
    if (iterator != myRPG_Map_DoorStateToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAP_DOORSTATE_INVALID");

    return result;
  };

  inline static RPG_Map_DoorState stringToRPG_Map_DoorState(const std::string& string_in)
  {
    RPG_Map_DoorStateToStringTableIterator_t iterator = myRPG_Map_DoorStateToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Map_DoorStateToStringTable.end());

    return RPG_MAP_DOORSTATE_INVALID;
  };

  static RPG_Map_DoorStateToStringTable_t myRPG_Map_DoorStateToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Map_DoorStateHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Map_DoorStateHelper(const RPG_Map_DoorStateHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Map_DoorStateHelper& operator=(const RPG_Map_DoorStateHelper&));
};

#endif
