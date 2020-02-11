
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_ITEM_COMMODITYTYPE_H
#define RPG_ITEM_COMMODITYTYPE_H

enum RPG_Item_CommodityType
{
  COMMODITY_BEVERAGE = 0,
  COMMODITY_FOOD,
  COMMODITY_LIGHT,
  COMMODITY_OTHER,
  //
  RPG_ITEM_COMMODITYTYPE_MAX,
  RPG_ITEM_COMMODITYTYPE_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Item_CommodityType, std::string> RPG_Item_CommodityTypeToStringTable_t;
typedef RPG_Item_CommodityTypeToStringTable_t::const_iterator RPG_Item_CommodityTypeToStringTableIterator_t;

class RPG_Item_CommodityTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Item_CommodityTypeToStringTable.clear();
    myRPG_Item_CommodityTypeToStringTable.insert(std::make_pair(COMMODITY_BEVERAGE, ACE_TEXT_ALWAYS_CHAR("COMMODITY_BEVERAGE")));
    myRPG_Item_CommodityTypeToStringTable.insert(std::make_pair(COMMODITY_FOOD, ACE_TEXT_ALWAYS_CHAR("COMMODITY_FOOD")));
    myRPG_Item_CommodityTypeToStringTable.insert(std::make_pair(COMMODITY_LIGHT, ACE_TEXT_ALWAYS_CHAR("COMMODITY_LIGHT")));
    myRPG_Item_CommodityTypeToStringTable.insert(std::make_pair(COMMODITY_OTHER, ACE_TEXT_ALWAYS_CHAR("COMMODITY_OTHER")));
  };

  inline static std::string RPG_Item_CommodityTypeToString(const RPG_Item_CommodityType& element_in)
  {
    std::string result;
    RPG_Item_CommodityTypeToStringTableIterator_t iterator = myRPG_Item_CommodityTypeToStringTable.find(element_in);
    if (iterator != myRPG_Item_CommodityTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_ITEM_COMMODITYTYPE_INVALID");

    return result;
  };

  inline static RPG_Item_CommodityType stringToRPG_Item_CommodityType(const std::string& string_in)
  {
    RPG_Item_CommodityTypeToStringTableIterator_t iterator = myRPG_Item_CommodityTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Item_CommodityTypeToStringTable.end());

    return RPG_ITEM_COMMODITYTYPE_INVALID;
  };

  static RPG_Item_CommodityTypeToStringTable_t myRPG_Item_CommodityTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_CommodityTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_CommodityTypeHelper(const RPG_Item_CommodityTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_CommodityTypeHelper& operator=(const RPG_Item_CommodityTypeHelper&));
};

#endif
