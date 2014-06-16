
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_DOMAIN_H
#define RPG_MAGIC_DOMAIN_H

enum RPG_Magic_Domain
{
  DOMAIN_NONE = 0,
  DOMAIN_AIR,
  DOMAIN_ANIMAL,
  DOMAIN_CHAOS,
  DOMAIN_DEATH,
  DOMAIN_DESTRUCTION,
  DOMAIN_EARTH,
  DOMAIN_EVIL,
  DOMAIN_FIRE,
  DOMAIN_GOOD,
  DOMAIN_HEALING,
  DOMAIN_KNOWLEDGE,
  DOMAIN_LAW,
  DOMAIN_LUCK,
  DOMAIN_MAGIC,
  DOMAIN_PLANT,
  DOMAIN_PROTECTION,
  DOMAIN_STRENGTH,
  DOMAIN_SUN,
  DOMAIN_TRAVEL,
  DOMAIN_TRICKERY,
  DOMAIN_WAR,
  DOMAIN_WATER,
  //
  RPG_MAGIC_DOMAIN_MAX,
  RPG_MAGIC_DOMAIN_INVALID
};

#include "rpg_magic_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_Domain, std::string> RPG_Magic_DomainToStringTable_t;
typedef RPG_Magic_DomainToStringTable_t::const_iterator RPG_Magic_DomainToStringTableIterator_t;

class RPG_Magic_Export RPG_Magic_DomainHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_DomainToStringTable.clear();
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_NONE, ACE_TEXT_ALWAYS_CHAR("DOMAIN_NONE")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_AIR, ACE_TEXT_ALWAYS_CHAR("DOMAIN_AIR")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_ANIMAL, ACE_TEXT_ALWAYS_CHAR("DOMAIN_ANIMAL")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_CHAOS, ACE_TEXT_ALWAYS_CHAR("DOMAIN_CHAOS")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_DEATH, ACE_TEXT_ALWAYS_CHAR("DOMAIN_DEATH")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_DESTRUCTION, ACE_TEXT_ALWAYS_CHAR("DOMAIN_DESTRUCTION")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_EARTH, ACE_TEXT_ALWAYS_CHAR("DOMAIN_EARTH")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_EVIL, ACE_TEXT_ALWAYS_CHAR("DOMAIN_EVIL")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_FIRE, ACE_TEXT_ALWAYS_CHAR("DOMAIN_FIRE")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_GOOD, ACE_TEXT_ALWAYS_CHAR("DOMAIN_GOOD")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_HEALING, ACE_TEXT_ALWAYS_CHAR("DOMAIN_HEALING")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_KNOWLEDGE, ACE_TEXT_ALWAYS_CHAR("DOMAIN_KNOWLEDGE")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_LAW, ACE_TEXT_ALWAYS_CHAR("DOMAIN_LAW")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_LUCK, ACE_TEXT_ALWAYS_CHAR("DOMAIN_LUCK")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_MAGIC, ACE_TEXT_ALWAYS_CHAR("DOMAIN_MAGIC")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_PLANT, ACE_TEXT_ALWAYS_CHAR("DOMAIN_PLANT")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_PROTECTION, ACE_TEXT_ALWAYS_CHAR("DOMAIN_PROTECTION")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_STRENGTH, ACE_TEXT_ALWAYS_CHAR("DOMAIN_STRENGTH")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_SUN, ACE_TEXT_ALWAYS_CHAR("DOMAIN_SUN")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_TRAVEL, ACE_TEXT_ALWAYS_CHAR("DOMAIN_TRAVEL")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_TRICKERY, ACE_TEXT_ALWAYS_CHAR("DOMAIN_TRICKERY")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_WAR, ACE_TEXT_ALWAYS_CHAR("DOMAIN_WAR")));
    myRPG_Magic_DomainToStringTable.insert(std::make_pair(DOMAIN_WATER, ACE_TEXT_ALWAYS_CHAR("DOMAIN_WATER")));
  };

  inline static std::string RPG_Magic_DomainToString(const RPG_Magic_Domain& element_in)
  {
    std::string result;
    RPG_Magic_DomainToStringTableIterator_t iterator = myRPG_Magic_DomainToStringTable.find(element_in);
    if (iterator != myRPG_Magic_DomainToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_DOMAIN_INVALID");

    return result;
  };

  inline static RPG_Magic_Domain stringToRPG_Magic_Domain(const std::string& string_in)
  {
    RPG_Magic_DomainToStringTableIterator_t iterator = myRPG_Magic_DomainToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_DomainToStringTable.end());

    return RPG_MAGIC_DOMAIN_INVALID;
  };

  static RPG_Magic_DomainToStringTable_t myRPG_Magic_DomainToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_DomainHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_DomainHelper(const RPG_Magic_DomainHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_DomainHelper& operator=(const RPG_Magic_DomainHelper&));
};

#endif
