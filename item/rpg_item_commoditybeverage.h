
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_ITEM_COMMODITYBEVERAGE_H
#define RPG_ITEM_COMMODITYBEVERAGE_H

enum RPG_Item_CommodityBeverage
{
  COMMODITY_BEVERAGE_BEER = 0,
  COMMODITY_BEVERAGE_WATER,
  COMMODITY_BEVERAGE_WINE,
  //
  RPG_ITEM_COMMODITYBEVERAGE_MAX,
  RPG_ITEM_COMMODITYBEVERAGE_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Item_CommodityBeverage, std::string> RPG_Item_CommodityBeverageToStringTable_t;
typedef RPG_Item_CommodityBeverageToStringTable_t::const_iterator RPG_Item_CommodityBeverageToStringTableIterator_t;

class RPG_Item_CommodityBeverageHelper
{
 public:
  inline static void init()
  {
    myRPG_Item_CommodityBeverageToStringTable.clear();
    myRPG_Item_CommodityBeverageToStringTable.insert(std::make_pair(COMMODITY_BEVERAGE_BEER, ACE_TEXT_ALWAYS_CHAR("COMMODITY_BEVERAGE_BEER")));
    myRPG_Item_CommodityBeverageToStringTable.insert(std::make_pair(COMMODITY_BEVERAGE_WATER, ACE_TEXT_ALWAYS_CHAR("COMMODITY_BEVERAGE_WATER")));
    myRPG_Item_CommodityBeverageToStringTable.insert(std::make_pair(COMMODITY_BEVERAGE_WINE, ACE_TEXT_ALWAYS_CHAR("COMMODITY_BEVERAGE_WINE")));
  };

  inline static std::string RPG_Item_CommodityBeverageToString(const RPG_Item_CommodityBeverage& element_in)
  {
    std::string result;
    RPG_Item_CommodityBeverageToStringTableIterator_t iterator = myRPG_Item_CommodityBeverageToStringTable.find(element_in);
    if (iterator != myRPG_Item_CommodityBeverageToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_ITEM_COMMODITYBEVERAGE_INVALID");

    return result;
  };

  inline static RPG_Item_CommodityBeverage stringToRPG_Item_CommodityBeverage(const std::string& string_in)
  {
    RPG_Item_CommodityBeverageToStringTableIterator_t iterator = myRPG_Item_CommodityBeverageToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Item_CommodityBeverageToStringTable.end());

    return RPG_ITEM_COMMODITYBEVERAGE_INVALID;
  };

  static RPG_Item_CommodityBeverageToStringTable_t myRPG_Item_CommodityBeverageToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_CommodityBeverageHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_CommodityBeverageHelper(const RPG_Item_CommodityBeverageHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_CommodityBeverageHelper& operator=(const RPG_Item_CommodityBeverageHelper&));
};

#endif
