
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_ITEM_TYPE_H
#define RPG_ITEM_TYPE_H

enum RPG_Item_Type
{
  ITEM_ARMOR = 0,
  ITEM_GOODS,
  ITEM_OTHER,
  ITEM_VALUABLE,
  ITEM_WEAPON,
  //
  RPG_ITEM_TYPE_MAX,
  RPG_ITEM_TYPE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Item_Type, std::string> RPG_Item_TypeToStringTable_t;
typedef RPG_Item_TypeToStringTable_t::const_iterator RPG_Item_TypeToStringTableIterator_t;

class RPG_Item_TypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Item_TypeToStringTable.clear();
    myRPG_Item_TypeToStringTable.insert(std::make_pair(ITEM_ARMOR, ACE_TEXT_ALWAYS_CHAR("ITEM_ARMOR")));
    myRPG_Item_TypeToStringTable.insert(std::make_pair(ITEM_GOODS, ACE_TEXT_ALWAYS_CHAR("ITEM_GOODS")));
    myRPG_Item_TypeToStringTable.insert(std::make_pair(ITEM_OTHER, ACE_TEXT_ALWAYS_CHAR("ITEM_OTHER")));
    myRPG_Item_TypeToStringTable.insert(std::make_pair(ITEM_VALUABLE, ACE_TEXT_ALWAYS_CHAR("ITEM_VALUABLE")));
    myRPG_Item_TypeToStringTable.insert(std::make_pair(ITEM_WEAPON, ACE_TEXT_ALWAYS_CHAR("ITEM_WEAPON")));
  };

  inline static std::string RPG_Item_TypeToString(const RPG_Item_Type& element_in)
  {
    std::string result;
    RPG_Item_TypeToStringTableIterator_t iterator = myRPG_Item_TypeToStringTable.find(element_in);
    if (iterator != myRPG_Item_TypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_ITEM_TYPE_INVALID");

    return result;
  };

  inline static RPG_Item_Type stringToRPG_Item_Type(const std::string& string_in)
  {
    RPG_Item_TypeToStringTableIterator_t iterator = myRPG_Item_TypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Item_TypeToStringTable.end());

    return RPG_ITEM_TYPE_INVALID;
  };

  static RPG_Item_TypeToStringTable_t myRPG_Item_TypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_TypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_TypeHelper(const RPG_Item_TypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_TypeHelper& operator=(const RPG_Item_TypeHelper&));
};

#endif
