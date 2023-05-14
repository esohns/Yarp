
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.0.1-devel
// -------------------------------- * * * ----------------------------------- //

#ifndef RPG_COMMON_TIMEOFDAY_H
#define RPG_COMMON_TIMEOFDAY_H

enum RPG_Common_TimeOfDay
{
  TIMEOFDAY_DAYTIME = 0,
  TIMEOFDAY_NIGHTTIME,
  TIMEOFDAY_ANY,
  //
  RPG_COMMON_TIMEOFDAY_MAX,
  RPG_COMMON_TIMEOFDAY_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Common_TimeOfDay, std::string> RPG_Common_TimeOfDayToStringTable_t;
typedef RPG_Common_TimeOfDayToStringTable_t::const_iterator RPG_Common_TimeOfDayToStringTableIterator_t;

class RPG_Common_TimeOfDayHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_TimeOfDayToStringTable.clear();
    myRPG_Common_TimeOfDayToStringTable.insert(std::make_pair(TIMEOFDAY_DAYTIME, ACE_TEXT_ALWAYS_CHAR("TIMEOFDAY_DAYTIME")));
    myRPG_Common_TimeOfDayToStringTable.insert(std::make_pair(TIMEOFDAY_NIGHTTIME, ACE_TEXT_ALWAYS_CHAR("TIMEOFDAY_NIGHTTIME")));
    myRPG_Common_TimeOfDayToStringTable.insert(std::make_pair(TIMEOFDAY_ANY, ACE_TEXT_ALWAYS_CHAR("TIMEOFDAY_ANY")));
  };

  inline static std::string RPG_Common_TimeOfDayToString(const RPG_Common_TimeOfDay& element_in)
  {
    std::string result;
    RPG_Common_TimeOfDayToStringTableIterator_t iterator = myRPG_Common_TimeOfDayToStringTable.find(element_in);
    if (iterator != myRPG_Common_TimeOfDayToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_TIMEOFDAY_INVALID");

    return result;
  };

  inline static RPG_Common_TimeOfDay stringToRPG_Common_TimeOfDay(const std::string& string_in)
  {
    RPG_Common_TimeOfDayToStringTableIterator_t iterator = myRPG_Common_TimeOfDayToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_TimeOfDayToStringTable.end());

    return RPG_COMMON_TIMEOFDAY_INVALID;
  };

  static RPG_Common_TimeOfDayToStringTable_t myRPG_Common_TimeOfDayToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_TimeOfDayHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_TimeOfDayHelper(const RPG_Common_TimeOfDayHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_TimeOfDayHelper& operator=(const RPG_Common_TimeOfDayHelper&));
};

#endif
