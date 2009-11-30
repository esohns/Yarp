// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#ifndef CXX___RPG_ITEM_XML_PARSER_BASE_H
#define CXX___RPG_ITEM_XML_PARSER_BASE_H

#include <rpg_item_XML_types.h>

#include <rpg_chance_dice_XML_parser_base.h>

class RPG_Item_WeaponCategory_Type_pimpl: public virtual RPG_Item_WeaponCategory_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_WeaponCategory
  post_RPG_Item_WeaponCategory_Type ();
};

class RPG_Item_WeaponClass_Type_pimpl: public virtual RPG_Item_WeaponClass_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_WeaponClass
  post_RPG_Item_WeaponClass_Type ();
};

class RPG_Item_WeaponType_Type_pimpl: public virtual RPG_Item_WeaponType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_WeaponType
  post_RPG_Item_WeaponType_Type ();
};

class RPG_Item_StorePrice_Type_pimpl: public virtual RPG_Item_StorePrice_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  numGoldPieces (unsigned int);

  virtual void
  numSilverPieces (unsigned int);

  virtual RPG_Item_StorePrice
  post_RPG_Item_StorePrice_Type ();
};

class RPG_Item_CriticalHitModifier_Type_pimpl: public virtual RPG_Item_CriticalHitModifier_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  minToHitRoll (unsigned char);

  virtual void
  damageModifier (unsigned char);

  virtual RPG_Item_CriticalHitModifier
  post_RPG_Item_CriticalHitModifier_Type ();
};

class RPG_Item_WeaponDamageType_Type_pimpl: public virtual RPG_Item_WeaponDamageType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_WeaponDamageType
  post_RPG_Item_WeaponDamageType_Type ();
};

class RPG_Item_WeaponProperties_Type_pimpl: public virtual RPG_Item_WeaponProperties_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  weaponType (const RPG_Item_WeaponType&);

  virtual void
  weaponCategory (const RPG_Item_WeaponCategory&);

  virtual void
  weaponClass (const RPG_Item_WeaponClass&);

  virtual void
  baseStorePrice (const RPG_Item_StorePrice&);

  virtual void
  baseDamage (const RPG_Item_Damage&);

  virtual void
  criticalHitModifier (const RPG_Item_CriticalHitModifier&);

  virtual void
  rangeIncrement (unsigned char);

  virtual void
  baseWeight (unsigned short);

  virtual void
  typeOfDamage (const RPG_Item_WeaponDamageType&);

  virtual RPG_Item_WeaponProperties_XML
  post_RPG_Item_WeaponProperties_Type ();
};

class RPG_Item_WeaponDictionary_Type_pimpl: public virtual RPG_Item_WeaponDictionary_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  weapon (const RPG_Item_WeaponProperties_XML&);

  virtual void
  post_RPG_Item_WeaponDictionary_Type ();
};

class RPG_Item_ArmorCategory_Type_pimpl: public virtual RPG_Item_ArmorCategory_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_ArmorCategory
  post_RPG_Item_ArmorCategory_Type ();
};

class RPG_Item_ArmorType_Type_pimpl: public virtual RPG_Item_ArmorType_Type_pskel,
  public ::xml_schema::string_pimpl
{
  public:
  virtual void
  pre ();

  virtual RPG_Item_ArmorType
  post_RPG_Item_ArmorType_Type ();
};

class RPG_Item_ArmorProperties_Type_pimpl: public virtual RPG_Item_ArmorProperties_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  armorType (const RPG_Item_ArmorType&);

  virtual void
  armorCategory (const RPG_Item_ArmorCategory&);

  virtual void
  baseStorePrice (const RPG_Item_StorePrice&);

  virtual void
  baseArmorBonus (unsigned char);

  virtual void
  maxDexterityBonus (unsigned char);

  virtual void
  armorCheckPenalty (signed char);

  virtual void
  arcaneSpellFailure (unsigned char);

  virtual void
  baseSpeed (unsigned short);

  virtual void
  baseWeight (unsigned short);

  virtual RPG_Item_ArmorProperties_XML
  post_RPG_Item_ArmorProperties_Type ();
};

class RPG_Item_ArmorDictionary_Type_pimpl: public virtual RPG_Item_ArmorDictionary_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  armor (const RPG_Item_ArmorProperties_XML&);

  virtual void
  post_RPG_Item_ArmorDictionary_Type ();
};

class RPG_Item_Dictionary_Type_pimpl: public virtual RPG_Item_Dictionary_Type_pskel
{
  public:
  virtual void
  pre ();

  virtual void
  weaponDictionary ();

  virtual void
  armorDictionary ();

  virtual void
  post_RPG_Item_Dictionary_Type ();
};

#endif // CXX___RPG_ITEM_XML_PARSER_BASE_H
