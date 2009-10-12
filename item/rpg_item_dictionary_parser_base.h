// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#ifndef CXX___RPG_ITEM_DICTIONARY_PARSER_BASE_H
#define CXX___RPG_ITEM_DICTIONARY_PARSER_BASE_H

#include "rpg_item_dictionary_types.h"

class RPG_Item_Dictionary_Type_pimpl: public virtual RPG_Item_Dictionary_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  RPG_Item_Weapon_Dictionary (const RPG_ITEM_WEAPON_DICTIONARY_T&);

  virtual void
  RPG_Item_Armor_Dictionary (const RPG_ITEM_ARMOR_DICTIONARY_T&);

  virtual void
  post_RPG_Item_Dictionary_Type ();
};

class RPG_Item_Weapon_Dictionary_Type_pimpl: public virtual RPG_Item_Weapon_Dictionary_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  weapon (const RPG_Item_Weapon_Properties&);

  virtual RPG_ITEM_WEAPON_DICTIONARY_T
  post_RPG_Item_Weapon_Dictionary_Type ();
};

class RPG_Item_Armor_Dictionary_Type_pimpl: public virtual RPG_Item_Armor_Dictionary_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  armor (const RPG_Item_Armor_Properties&);

  virtual RPG_ITEM_ARMOR_DICTIONARY_T
  post_RPG_Item_Armor_Dictionary_Type ();
};

class RPG_Item_Weapon_Category_Type_pimpl: public virtual RPG_Item_Weapon_Category_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_Weapon_Category
  post_RPG_Item_Weapon_Category_Type ();
};

class RPG_Item_Weapon_Class_Type_pimpl: public virtual RPG_Item_Weapon_Class_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_Weapon_Class
  post_RPG_Item_Weapon_Class_Type ();
};

class RPG_Item_Weapon_Type_pimpl: public virtual RPG_Item_Weapon_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_Weapon_Type
  post_RPG_Item_Weapon_Type ();
};

class RPG_Item_Store_Price_Type_pimpl: public virtual RPG_Item_Store_Price_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  numGoldPieces (unsigned int);

  virtual void
  numSilverPieces (unsigned int);

  virtual RPG_Item_Store_Price
  post_RPG_Item_Store_Price_Type ();
};

class RPG_Chance_Dice_Type_pimpl: public virtual RPG_Chance_Dice_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Chance_Dice_Type
  post_RPG_Chance_Dice_Type ();
};

class RPG_Chance_Roll_Type_pimpl: public virtual RPG_Chance_Roll_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  numDice (unsigned int);

  virtual void
  typeDice (const RPG_Chance_Dice_Type&);

  virtual void
  modifier (long long);

  virtual RPG_Item_Damage
  post_RPG_Chance_Roll_Type ();
};

class RPG_Item_CriticalHit_Modifier_Type_pimpl: public virtual RPG_Item_CriticalHit_Modifier_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  minToHitRoll (unsigned int);

  virtual void
  damageModifier (unsigned int);

  virtual RPG_Item_CriticalHit_Modifier
  post_RPG_Item_CriticalHit_Modifier_Type ();
};

class RPG_Item_Weapon_Damage_Type_pimpl: public virtual RPG_Item_Weapon_Damage_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_Weapon_Damage_Type
  post_RPG_Item_Weapon_Damage_Type ();
};

class RPG_Item_Weapon_Properties_Type_pimpl: public virtual RPG_Item_Weapon_Properties_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  weaponType (const RPG_Item_Weapon_Type&);

  virtual void
  weaponCategory (const RPG_Item_Weapon_Category&);

  virtual void
  weaponClass (const RPG_Item_Weapon_Class&);

  virtual void
  baseStorePrice (const RPG_Item_Store_Price&);

  virtual void
  baseDamage (const RPG_Item_Damage&);

  virtual void
  criticalHitModifier (const RPG_Item_CriticalHit_Modifier&);

  virtual void
  rangeIncrement (unsigned int);

  virtual void
  baseWeight (unsigned int);

  virtual void
  typeOfDamage (const RPG_Item_Weapon_Damage_Type&);

  virtual RPG_Item_Weapon_Properties
  post_RPG_Item_Weapon_Properties_Type ();
};

class RPG_Item_Armor_Category_Type_pimpl: public virtual RPG_Item_Armor_Category_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_Armor_Category
  post_RPG_Item_Armor_Category_Type ();
};

class RPG_Item_Armor_Type_pimpl: public virtual RPG_Item_Armor_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_Armor_Type
  post_RPG_Item_Armor_Type ();
};

class RPG_Item_Armor_Properties_Type_pimpl: public virtual RPG_Item_Armor_Properties_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  armorType (const RPG_Item_Armor_Type&);

  virtual void
  armorCategory (const RPG_Item_Armor_Category&);

  virtual void
  baseStorePrice (const RPG_Item_Store_Price&);

  virtual void
  baseArmorBonus (unsigned int);

  virtual void
  maxDexterityBonus (unsigned int);

  virtual void
  armorCheckPenalty (long long);

  virtual void
  arcaneSpellFailure (unsigned int);

  virtual void
  baseSpeed (unsigned int);

  virtual void
  baseWeight (unsigned int);

  virtual RPG_Item_Armor_Properties
  post_RPG_Item_Armor_Properties_Type ();
};

#endif // CXX___RPG_ITEM_DICTIONARY_PARSER_BASE_H