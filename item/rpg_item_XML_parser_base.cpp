// Not copyrighted - public domain.
//
// This sample parser implementation was generated by CodeSynthesis XSD,
// an XML Schema to C++ data binding compiler. You may use it in your
// programs without any restrictions.
//

#include <rpg_item_XML_parser_base.h>

// RPG_Item_Type_Type_pimpl
//

void RPG_Item_Type_Type_pimpl::
pre ()
{
}

void RPG_Item_Type_Type_pimpl::
post_RPG_Item_Type_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
}

// RPG_Item_Money_Type_pimpl
//

void RPG_Item_Money_Type_pimpl::
pre ()
{
}

void RPG_Item_Money_Type_pimpl::
post_RPG_Item_Money_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
}

// RPG_Item_WeaponCategory_Type_pimpl
//

void RPG_Item_WeaponCategory_Type_pimpl::
pre ()
{
}

RPG_Item_WeaponCategory RPG_Item_WeaponCategory_Type_pimpl::
post_RPG_Item_WeaponCategory_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Item_WeaponClass_Type_pimpl
//

void RPG_Item_WeaponClass_Type_pimpl::
pre ()
{
}

RPG_Item_WeaponClass RPG_Item_WeaponClass_Type_pimpl::
post_RPG_Item_WeaponClass_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Item_WeaponType_Type_pimpl
//

void RPG_Item_WeaponType_Type_pimpl::
pre ()
{
}

RPG_Item_WeaponType RPG_Item_WeaponType_Type_pimpl::
post_RPG_Item_WeaponType_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Item_StorePrice_Type_pimpl
//

void RPG_Item_StorePrice_Type_pimpl::
pre ()
{
}

void RPG_Item_StorePrice_Type_pimpl::
numGoldPieces (unsigned int numGoldPieces)
{
  // TODO
  //
}

void RPG_Item_StorePrice_Type_pimpl::
numSilverPieces (unsigned int numSilverPieces)
{
  // TODO
  //
}

RPG_Item_StorePrice RPG_Item_StorePrice_Type_pimpl::
post_RPG_Item_StorePrice_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Item_CriticalHitModifier_Type_pimpl
//

void RPG_Item_CriticalHitModifier_Type_pimpl::
pre ()
{
}

void RPG_Item_CriticalHitModifier_Type_pimpl::
minToHitRoll (unsigned char minToHitRoll)
{
  // TODO
  //
}

void RPG_Item_CriticalHitModifier_Type_pimpl::
damageModifier (unsigned char damageModifier)
{
  // TODO
  //
}

RPG_Item_CriticalHitModifier RPG_Item_CriticalHitModifier_Type_pimpl::
post_RPG_Item_CriticalHitModifier_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Item_PhysicalDamageType_Type_pimpl
//

void RPG_Item_PhysicalDamageType_Type_pimpl::
pre ()
{
}

RPG_Item_PhysicalDamageType RPG_Item_PhysicalDamageType_Type_pimpl::
post_RPG_Item_PhysicalDamageType_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Item_WeaponPropertiesXML_Type_pimpl
//

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
pre ()
{
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
weaponType (const RPG_Item_WeaponType& weaponType)
{
  // TODO
  //
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
weaponCategory (const RPG_Item_WeaponCategory& weaponCategory)
{
  // TODO
  //
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
weaponClass (const RPG_Item_WeaponClass& weaponClass)
{
  // TODO
  //
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
baseStorePrice (const RPG_Item_StorePrice& baseStorePrice)
{
  // TODO
  //
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
baseDamage (const RPG_Item_Damage& baseDamage)
{
  // TODO
  //
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
criticalHitModifier (const RPG_Item_CriticalHitModifier& criticalHitModifier)
{
  // TODO
  //
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
rangeIncrement (unsigned char rangeIncrement)
{
  // TODO
  //
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
baseWeight (unsigned short baseWeight)
{
  // TODO
  //
}

void RPG_Item_WeaponPropertiesXML_Type_pimpl::
typeOfDamage (const RPG_Item_PhysicalDamageType& typeOfDamage)
{
  // TODO
  //
}

RPG_Item_WeaponPropertiesXML RPG_Item_WeaponPropertiesXML_Type_pimpl::
post_RPG_Item_WeaponPropertiesXML_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Item_MagicWeaponPropertiesXML_Type_pimpl
//

void RPG_Item_MagicWeaponPropertiesXML_Type_pimpl::
pre ()
{
}

void RPG_Item_MagicWeaponPropertiesXML_Type_pimpl::
toHitModifier (signed char toHitModifier)
{
  // TODO
  //
}

void RPG_Item_MagicWeaponPropertiesXML_Type_pimpl::
post_RPG_Item_MagicWeaponPropertiesXML_Type ()
{
  const RPG_Item_WeaponPropertiesXML& v (post_RPG_Item_WeaponPropertiesXML_Type ());

  // TODO
  //
}

// RPG_Item_WeaponDictionary_Type_pimpl
//

void RPG_Item_WeaponDictionary_Type_pimpl::
pre ()
{
}

void RPG_Item_WeaponDictionary_Type_pimpl::
weapon (const RPG_Item_WeaponPropertiesXML& weapon)
{
  // TODO
  //
}

void RPG_Item_WeaponDictionary_Type_pimpl::
post_RPG_Item_WeaponDictionary_Type ()
{
}

// RPG_Item_ArmorCategory_Type_pimpl
//

void RPG_Item_ArmorCategory_Type_pimpl::
pre ()
{
}

RPG_Item_ArmorCategory RPG_Item_ArmorCategory_Type_pimpl::
post_RPG_Item_ArmorCategory_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Item_ArmorType_Type_pimpl
//

void RPG_Item_ArmorType_Type_pimpl::
pre ()
{
}

RPG_Item_ArmorType RPG_Item_ArmorType_Type_pimpl::
post_RPG_Item_ArmorType_Type ()
{
  const ::std::string& v (post_string ());

  // TODO
  //
  // return ... ;
}

// RPG_Item_ArmorPropertiesXML_Type_pimpl
//

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
pre ()
{
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
armorType (const RPG_Item_ArmorType& armorType)
{
  // TODO
  //
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
armorCategory (const RPG_Item_ArmorCategory& armorCategory)
{
  // TODO
  //
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
baseStorePrice (const RPG_Item_StorePrice& baseStorePrice)
{
  // TODO
  //
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
baseArmorBonus (unsigned char baseArmorBonus)
{
  // TODO
  //
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
maxDexterityBonus (unsigned char maxDexterityBonus)
{
  // TODO
  //
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
armorCheckPenalty (signed char armorCheckPenalty)
{
  // TODO
  //
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
arcaneSpellFailure (unsigned char arcaneSpellFailure)
{
  // TODO
  //
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
baseSpeed (unsigned short baseSpeed)
{
  // TODO
  //
}

void RPG_Item_ArmorPropertiesXML_Type_pimpl::
baseWeight (unsigned short baseWeight)
{
  // TODO
  //
}

RPG_Item_ArmorPropertiesXML RPG_Item_ArmorPropertiesXML_Type_pimpl::
post_RPG_Item_ArmorPropertiesXML_Type ()
{
  // TODO
  //
  // return ... ;
}

// RPG_Item_MagicArmorPropertiesXML_Type_pimpl
//

void RPG_Item_MagicArmorPropertiesXML_Type_pimpl::
pre ()
{
}

void RPG_Item_MagicArmorPropertiesXML_Type_pimpl::
defenseModifier (signed char defenseModifier)
{
  // TODO
  //
}

void RPG_Item_MagicArmorPropertiesXML_Type_pimpl::
post_RPG_Item_MagicArmorPropertiesXML_Type ()
{
  const RPG_Item_ArmorPropertiesXML& v (post_RPG_Item_ArmorPropertiesXML_Type ());

  // TODO
  //
}

// RPG_Item_ArmorDictionary_Type_pimpl
//

void RPG_Item_ArmorDictionary_Type_pimpl::
pre ()
{
}

void RPG_Item_ArmorDictionary_Type_pimpl::
armor (const RPG_Item_ArmorPropertiesXML& armor)
{
  // TODO
  //
}

void RPG_Item_ArmorDictionary_Type_pimpl::
post_RPG_Item_ArmorDictionary_Type ()
{
}

// RPG_Item_Dictionary_Type_pimpl
//

void RPG_Item_Dictionary_Type_pimpl::
pre ()
{
}

void RPG_Item_Dictionary_Type_pimpl::
weaponDictionary ()
{
}

void RPG_Item_Dictionary_Type_pimpl::
armorDictionary ()
{
}

void RPG_Item_Dictionary_Type_pimpl::
post_RPG_Item_Dictionary_Type ()
{
}

