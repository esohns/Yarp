
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.0.1-devel
// -------------------------------- * * * ----------------------------------- //

#ifndef RPG_ITEM_WEAPONCLASS_H
#define RPG_ITEM_WEAPONCLASS_H

enum RPG_Item_WeaponClass
{
  WEAPONCLASS_UNARMED = 0,
  WEAPONCLASS_LIGHT_MELEE,
  WEAPONCLASS_ONE_HANDED_MELEE,
  WEAPONCLASS_TWO_HANDED_MELEE,
  WEAPONCLASS_RANGED,
  //
  RPG_ITEM_WEAPONCLASS_MAX,
  RPG_ITEM_WEAPONCLASS_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Item_WeaponClass, std::string> RPG_Item_WeaponClassToStringTable_t;
typedef RPG_Item_WeaponClassToStringTable_t::const_iterator RPG_Item_WeaponClassToStringTableIterator_t;

class RPG_Item_WeaponClassHelper
{
 public:
  inline static void init()
  {
    myRPG_Item_WeaponClassToStringTable.clear();
    myRPG_Item_WeaponClassToStringTable.insert(std::make_pair(WEAPONCLASS_UNARMED, ACE_TEXT_ALWAYS_CHAR("WEAPONCLASS_UNARMED")));
    myRPG_Item_WeaponClassToStringTable.insert(std::make_pair(WEAPONCLASS_LIGHT_MELEE, ACE_TEXT_ALWAYS_CHAR("WEAPONCLASS_LIGHT_MELEE")));
    myRPG_Item_WeaponClassToStringTable.insert(std::make_pair(WEAPONCLASS_ONE_HANDED_MELEE, ACE_TEXT_ALWAYS_CHAR("WEAPONCLASS_ONE_HANDED_MELEE")));
    myRPG_Item_WeaponClassToStringTable.insert(std::make_pair(WEAPONCLASS_TWO_HANDED_MELEE, ACE_TEXT_ALWAYS_CHAR("WEAPONCLASS_TWO_HANDED_MELEE")));
    myRPG_Item_WeaponClassToStringTable.insert(std::make_pair(WEAPONCLASS_RANGED, ACE_TEXT_ALWAYS_CHAR("WEAPONCLASS_RANGED")));
  };

  inline static std::string RPG_Item_WeaponClassToString(const RPG_Item_WeaponClass& element_in)
  {
    std::string result;
    RPG_Item_WeaponClassToStringTableIterator_t iterator = myRPG_Item_WeaponClassToStringTable.find(element_in);
    if (iterator != myRPG_Item_WeaponClassToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_ITEM_WEAPONCLASS_INVALID");

    return result;
  };

  inline static RPG_Item_WeaponClass stringToRPG_Item_WeaponClass(const std::string& string_in)
  {
    RPG_Item_WeaponClassToStringTableIterator_t iterator = myRPG_Item_WeaponClassToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Item_WeaponClassToStringTable.end());

    return RPG_ITEM_WEAPONCLASS_INVALID;
  };

  static RPG_Item_WeaponClassToStringTable_t myRPG_Item_WeaponClassToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_WeaponClassHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_WeaponClassHelper(const RPG_Item_WeaponClassHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_WeaponClassHelper& operator=(const RPG_Item_WeaponClassHelper&));
};

#endif
