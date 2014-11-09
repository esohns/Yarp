
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_CHARACTER_EQUIPMENTSLOT_H
#define RPG_CHARACTER_EQUIPMENTSLOT_H

enum RPG_Character_EquipmentSlot
{
  EQUIPMENTSLOT_BODY = 0,
  EQUIPMENTSLOT_EYES,
  EQUIPMENTSLOT_FEET,
  EQUIPMENTSLOT_FINGER,
  EQUIPMENTSLOT_HAND_LEFT,
  EQUIPMENTSLOT_HAND_RIGHT,
  EQUIPMENTSLOT_HANDS,
  EQUIPMENTSLOT_HEAD,
  EQUIPMENTSLOT_NECK,
  EQUIPMENTSLOT_SHOULDERS,
  EQUIPMENTSLOT_TORSO,
  EQUIPMENTSLOT_WAIST,
  EQUIPMENTSLOT_WRIST_LEFT,
  EQUIPMENTSLOT_WRIST_RIGHT,
  EQUIPMENTSLOT_WRISTS,
  EQUIPMENTSLOT_ANY,
  //
  RPG_CHARACTER_EQUIPMENTSLOT_MAX,
  RPG_CHARACTER_EQUIPMENTSLOT_INVALID
};

#include "rpg_character_exports.h"

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Character_EquipmentSlot, std::string> RPG_Character_EquipmentSlotToStringTable_t;
typedef RPG_Character_EquipmentSlotToStringTable_t::const_iterator RPG_Character_EquipmentSlotToStringTableIterator_t;

class RPG_Character_Export RPG_Character_EquipmentSlotHelper
{
 public:
  inline static void init()
  {
    myRPG_Character_EquipmentSlotToStringTable.clear();
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_BODY, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_BODY")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_EYES, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_EYES")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_FEET, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_FEET")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_FINGER, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_FINGER")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_HAND_LEFT, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_HAND_LEFT")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_HAND_RIGHT, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_HAND_RIGHT")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_HANDS, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_HANDS")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_HEAD, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_HEAD")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_NECK, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_NECK")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_SHOULDERS, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_SHOULDERS")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_TORSO, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_TORSO")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_WAIST, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_WAIST")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_WRIST_LEFT, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_WRIST_LEFT")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_WRIST_RIGHT, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_WRIST_RIGHT")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_WRISTS, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_WRISTS")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_ANY, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_ANY")));
  };

  inline static std::string RPG_Character_EquipmentSlotToString(const RPG_Character_EquipmentSlot& element_in)
  {
    std::string result;
    RPG_Character_EquipmentSlotToStringTableIterator_t iterator = myRPG_Character_EquipmentSlotToStringTable.find(element_in);
    if (iterator != myRPG_Character_EquipmentSlotToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_CHARACTER_EQUIPMENTSLOT_INVALID");

    return result;
  };

  inline static RPG_Character_EquipmentSlot stringToRPG_Character_EquipmentSlot(const std::string& string_in)
  {
    RPG_Character_EquipmentSlotToStringTableIterator_t iterator = myRPG_Character_EquipmentSlotToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Character_EquipmentSlotToStringTable.end());

    return RPG_CHARACTER_EQUIPMENTSLOT_INVALID;
  };

  static RPG_Character_EquipmentSlotToStringTable_t myRPG_Character_EquipmentSlotToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EquipmentSlotHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EquipmentSlotHelper(const RPG_Character_EquipmentSlotHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EquipmentSlotHelper& operator=(const RPG_Character_EquipmentSlotHelper&));
};

#endif
