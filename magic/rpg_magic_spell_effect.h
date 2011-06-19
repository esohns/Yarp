
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_MAGIC_SPELL_EFFECT_H
#define RPG_MAGIC_SPELL_EFFECT_H

enum RPG_Magic_Spell_Effect
{
  SPELLEFFECT_ABILITIY_LOSS_MAGICAL_ALL = 0,
  SPELLEFFECT_ABILITIY_LOSS_MAGICAL_EXTRAORDINARY,
  SPELLEFFECT_ABILITIY_LOSS_MAGICAL_SPELLLIKE,
  SPELLEFFECT_ABILITIY_LOSS_MAGICAL_SUPERNATURAL,
  SPELLEFFECT_ALIGN_WEAPON,
  SPELLEFFECT_ANIMATE_ANIMAL,
  SPELLEFFECT_ANIMATE_DEAD,
  SPELLEFFECT_ANIMATE_PLANT,
  SPELLEFFECT_ATONEMENT,
  SPELLEFFECT_AUGURY,
  SPELLEFFECT_BANISH_CREATURE,
  SPELLEFFECT_BARRIER_CREATURE,
  SPELLEFFECT_BARRIER_MAGIC,
  SPELLEFFECT_DAMAGE,
  SPELLEFFECT_DAZE,
  SPELLEFFECT_DETECT_MAGIC,
  SPELLEFFECT_ENTANGLE,
  SPELLEFFECT_FASCINATE,
  SPELLEFFECT_GROW,
  SPELLEFFECT_HOLD_CREATURE,
  SPELLEFFECT_IDENTIFY,
  SPELLEFFECT_KILL,
  SPELLEFFECT_LEVITATE,
  SPELLEFFECT_LOCK,
  SPELLEFFECT_MARK,
  SPELLEFFECT_MESSENGER,
  SPELLEFFECT_MODIFIER_ARMOR_CLASS,
  SPELLEFFECT_MODIFIER_ATTACK_ROLL,
  SPELLEFFECT_MODIFIER_ATTRIBUTE,
  SPELLEFFECT_MODIFIER_CHECK_ATTRIBUTE_ALL,
  SPELLEFFECT_MODIFIER_CHECK_SKILL_ALL,
  SPELLEFFECT_MODIFIER_HP,
  SPELLEFFECT_MODIFIER_MORALE,
  SPELLEFFECT_MODIFIER_SAVE_ALL,
  SPELLEFFECT_MODIFIER_SAVE_FEAR,
  SPELLEFFECT_MODIFIER_SAVE_REFLEX,
  SPELLEFFECT_PARALYSIS,
  SPELLEFFECT_POLYMORPH,
  SPELLEFFECT_RAISE_DEAD,
  SPELLEFFECT_SENSOR_VISUAL,
  SPELLEFFECT_TELEPORT_INTERPLANAR,
  SPELLEFFECT_TRIGGER_ALARM,
  //
  RPG_MAGIC_SPELL_EFFECT_MAX,
  RPG_MAGIC_SPELL_EFFECT_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_Spell_Effect, std::string> RPG_Magic_Spell_EffectToStringTable_t;
typedef RPG_Magic_Spell_EffectToStringTable_t::const_iterator RPG_Magic_Spell_EffectToStringTableIterator_t;

class RPG_Magic_Spell_EffectHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_Spell_EffectToStringTable.clear();
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ABILITIY_LOSS_MAGICAL_ALL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ABILITIY_LOSS_MAGICAL_ALL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ABILITIY_LOSS_MAGICAL_EXTRAORDINARY, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ABILITIY_LOSS_MAGICAL_EXTRAORDINARY")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ABILITIY_LOSS_MAGICAL_SPELLLIKE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ABILITIY_LOSS_MAGICAL_SPELLLIKE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ABILITIY_LOSS_MAGICAL_SUPERNATURAL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ABILITIY_LOSS_MAGICAL_SUPERNATURAL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ALIGN_WEAPON, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ALIGN_WEAPON")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ANIMATE_ANIMAL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ANIMATE_ANIMAL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ANIMATE_DEAD, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ANIMATE_DEAD")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ANIMATE_PLANT, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ANIMATE_PLANT")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ATONEMENT, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ATONEMENT")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_AUGURY, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_AUGURY")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_BANISH_CREATURE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_BANISH_CREATURE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_BARRIER_CREATURE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_BARRIER_CREATURE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_BARRIER_MAGIC, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_BARRIER_MAGIC")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_DAMAGE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_DAMAGE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_DAZE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_DAZE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_DETECT_MAGIC, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_DETECT_MAGIC")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_ENTANGLE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_ENTANGLE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_FASCINATE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_FASCINATE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_GROW, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_GROW")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_HOLD_CREATURE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_HOLD_CREATURE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_IDENTIFY, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_IDENTIFY")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_KILL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_KILL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_LEVITATE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_LEVITATE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_LOCK, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_LOCK")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MARK, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MARK")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MESSENGER, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MESSENGER")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_ARMOR_CLASS, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_ARMOR_CLASS")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_ATTACK_ROLL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_ATTACK_ROLL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_ATTRIBUTE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_ATTRIBUTE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_CHECK_ATTRIBUTE_ALL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_CHECK_ATTRIBUTE_ALL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_CHECK_SKILL_ALL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_CHECK_SKILL_ALL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_HP, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_HP")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_MORALE, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_MORALE")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_SAVE_ALL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_SAVE_ALL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_SAVE_FEAR, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_SAVE_FEAR")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_MODIFIER_SAVE_REFLEX, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_MODIFIER_SAVE_REFLEX")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_PARALYSIS, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_PARALYSIS")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_POLYMORPH, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_POLYMORPH")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_RAISE_DEAD, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_RAISE_DEAD")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_SENSOR_VISUAL, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_SENSOR_VISUAL")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_TELEPORT_INTERPLANAR, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_TELEPORT_INTERPLANAR")));
    myRPG_Magic_Spell_EffectToStringTable.insert(std::make_pair(SPELLEFFECT_TRIGGER_ALARM, ACE_TEXT_ALWAYS_CHAR("SPELLEFFECT_TRIGGER_ALARM")));
  };

  inline static std::string RPG_Magic_Spell_EffectToString(const RPG_Magic_Spell_Effect& element_in)
  {
    std::string result;
    RPG_Magic_Spell_EffectToStringTableIterator_t iterator = myRPG_Magic_Spell_EffectToStringTable.find(element_in);
    if (iterator != myRPG_Magic_Spell_EffectToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_SPELL_EFFECT_INVALID");

    return result;
  };

  inline static RPG_Magic_Spell_Effect stringToRPG_Magic_Spell_Effect(const std::string& string_in)
  {
    RPG_Magic_Spell_EffectToStringTableIterator_t iterator = myRPG_Magic_Spell_EffectToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_Spell_EffectToStringTable.end());

    return RPG_MAGIC_SPELL_EFFECT_INVALID;
  };

  static RPG_Magic_Spell_EffectToStringTable_t myRPG_Magic_Spell_EffectToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_EffectHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_EffectHelper(const RPG_Magic_Spell_EffectHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_EffectHelper& operator=(const RPG_Magic_Spell_EffectHelper&));
};

#endif
