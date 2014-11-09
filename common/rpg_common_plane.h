
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_COMMON_PLANE_H
#define RPG_COMMON_PLANE_H

enum RPG_Common_Plane
{
  PLANE_INNER = 0,
  PLANE_MATERIAL,
  PLANE_OUTER,
  PLANE_TRANSITIVE,
  PLANE_ANY,
  //
  RPG_COMMON_PLANE_MAX,
  RPG_COMMON_PLANE_INVALID
};

#include "rpg_common_exports.h"

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Common_Plane, std::string> RPG_Common_PlaneToStringTable_t;
typedef RPG_Common_PlaneToStringTable_t::const_iterator RPG_Common_PlaneToStringTableIterator_t;

class RPG_Common_Export RPG_Common_PlaneHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_PlaneToStringTable.clear();
    myRPG_Common_PlaneToStringTable.insert(std::make_pair(PLANE_INNER, ACE_TEXT_ALWAYS_CHAR("PLANE_INNER")));
    myRPG_Common_PlaneToStringTable.insert(std::make_pair(PLANE_MATERIAL, ACE_TEXT_ALWAYS_CHAR("PLANE_MATERIAL")));
    myRPG_Common_PlaneToStringTable.insert(std::make_pair(PLANE_OUTER, ACE_TEXT_ALWAYS_CHAR("PLANE_OUTER")));
    myRPG_Common_PlaneToStringTable.insert(std::make_pair(PLANE_TRANSITIVE, ACE_TEXT_ALWAYS_CHAR("PLANE_TRANSITIVE")));
    myRPG_Common_PlaneToStringTable.insert(std::make_pair(PLANE_ANY, ACE_TEXT_ALWAYS_CHAR("PLANE_ANY")));
  };

  inline static std::string RPG_Common_PlaneToString(const RPG_Common_Plane& element_in)
  {
    std::string result;
    RPG_Common_PlaneToStringTableIterator_t iterator = myRPG_Common_PlaneToStringTable.find(element_in);
    if (iterator != myRPG_Common_PlaneToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_PLANE_INVALID");

    return result;
  };

  inline static RPG_Common_Plane stringToRPG_Common_Plane(const std::string& string_in)
  {
    RPG_Common_PlaneToStringTableIterator_t iterator = myRPG_Common_PlaneToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_PlaneToStringTable.end());

    return RPG_COMMON_PLANE_INVALID;
  };

  static RPG_Common_PlaneToStringTable_t myRPG_Common_PlaneToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_PlaneHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_PlaneHelper(const RPG_Common_PlaneHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_PlaneHelper& operator=(const RPG_Common_PlaneHelper&));
};

#endif
