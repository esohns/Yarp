
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.0.1-devel
// -------------------------------- * * * ----------------------------------- //

#ifndef RPG_GRAPHICS_SPRITE_H
#define RPG_GRAPHICS_SPRITE_H

enum RPG_Graphics_Sprite
{
  SPRITE_GOBLIN = 0,
  SPRITE_HUMAN,
  SPRITE_PRIEST,
  //
  RPG_GRAPHICS_SPRITE_MAX,
  RPG_GRAPHICS_SPRITE_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Graphics_Sprite, std::string> RPG_Graphics_SpriteToStringTable_t;
typedef RPG_Graphics_SpriteToStringTable_t::const_iterator RPG_Graphics_SpriteToStringTableIterator_t;

class RPG_Graphics_SpriteHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_SpriteToStringTable.clear();
    myRPG_Graphics_SpriteToStringTable.insert(std::make_pair(SPRITE_GOBLIN, ACE_TEXT_ALWAYS_CHAR("SPRITE_GOBLIN")));
    myRPG_Graphics_SpriteToStringTable.insert(std::make_pair(SPRITE_HUMAN, ACE_TEXT_ALWAYS_CHAR("SPRITE_HUMAN")));
    myRPG_Graphics_SpriteToStringTable.insert(std::make_pair(SPRITE_PRIEST, ACE_TEXT_ALWAYS_CHAR("SPRITE_PRIEST")));
  };

  inline static std::string RPG_Graphics_SpriteToString(const RPG_Graphics_Sprite& element_in)
  {
    std::string result;
    RPG_Graphics_SpriteToStringTableIterator_t iterator = myRPG_Graphics_SpriteToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_SpriteToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_SPRITE_INVALID");

    return result;
  };

  inline static RPG_Graphics_Sprite stringToRPG_Graphics_Sprite(const std::string& string_in)
  {
    RPG_Graphics_SpriteToStringTableIterator_t iterator = myRPG_Graphics_SpriteToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_SpriteToStringTable.end());

    return RPG_GRAPHICS_SPRITE_INVALID;
  };

  static RPG_Graphics_SpriteToStringTable_t myRPG_Graphics_SpriteToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_SpriteHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_SpriteHelper(const RPG_Graphics_SpriteHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_SpriteHelper& operator=(const RPG_Graphics_SpriteHelper&));
};

#endif
