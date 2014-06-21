// Copyright (C) 2005-2010 Code Synthesis Tools CC
//
// This program was generated by CodeSynthesis XSD, an XML Schema to
// C++ data binding compiler.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License version 2 as
// published by the Free Software Foundation.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
//
// In addition, as a special exception, Code Synthesis Tools CC gives
// permission to link this program with the Xerces-C++ library (or with
// modified versions of Xerces-C++ that use the same license as Xerces-C++),
// and distribute linked combinations including the two. You must obey
// the GNU General Public License version 2 in all respects for all of
// the code used other than Xerces-C++. If you modify this copy of the
// program, you may extend this exception to your version of the program,
// but you are not obligated to do so. If you do not wish to do so, delete
// this exception statement from your version.
//
// Furthermore, Code Synthesis Tools CC makes a special exception for
// the Free/Libre and Open Source Software (FLOSS) which is described
// in the accompanying FLOSSE file.
//

#ifndef CXX___RPG_PLAYER_XML_TYPES_H
#define CXX___RPG_PLAYER_XML_TYPES_H

// Begin prologue.
//
#include "rpg_player_exports.h"
#include "rpg_player_exports.h"
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

// Forward declarations
//
class RPG_Player_Abilities_Type_pskel;
class RPG_Player_Conditions_Type_pskel;
class RPG_Player_Spells_Type_pskel;
class RPG_Player_CharacterBaseXML_Type_pskel;
class RPG_Player_CharacterXML_Type_pskel;
class RPG_Player_PlayerXML_Type_pskel;
class RPG_Player_StateBase_Type_pskel;
class RPG_Player_State_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_XMLSchema_XML_types.h"

#include "rpg_player_incl.h"
#include "rpg_magic_incl.h"
#include "rpg_item_incl.h"
#include "rpg_dice_incl.h"
#include "rpg_common_incl.h"
#include "rpg_common_environment_incl.h"
#include "rpg_character_incl.h"

#include "rpg_common_XML_types.h"

#include "rpg_magic_XML_types.h"

#include "rpg_item_XML_types.h"

#include "rpg_character_XML_types.h"

class RPG_Player_Export RPG_Player_Abilities_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  ability (const RPG_Character_Ability&);

  virtual RPG_Player_Abilities
  post_RPG_Player_Abilities_Type () = 0;

  // Parser construction API.
  //
  void
  ability_parser (::RPG_Character_Ability_Type_pskel&);

  void
  parsers (::RPG_Character_Ability_Type_pskel& /* ability */);

  // Constructor.
  //
  RPG_Player_Abilities_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Character_Ability_Type_pskel* ability_parser_;
};

class RPG_Player_Export RPG_Player_Conditions_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  condition (const RPG_Common_Condition&);

  virtual RPG_Player_Conditions
  post_RPG_Player_Conditions_Type () = 0;

  // Parser construction API.
  //
  void
  condition_parser (::RPG_Common_Condition_Type_pskel&);

  void
  parsers (::RPG_Common_Condition_Type_pskel& /* condition */);

  // Constructor.
  //
  RPG_Player_Conditions_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Common_Condition_Type_pskel* condition_parser_;
};

class RPG_Player_Export RPG_Player_Spells_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  spell (const RPG_Magic_SpellType&);

  virtual RPG_Player_Spells
  post_RPG_Player_Spells_Type () = 0;

  // Parser construction API.
  //
  void
  spell_parser (::RPG_Magic_SpellType_Type_pskel&);

  void
  parsers (::RPG_Magic_SpellType_Type_pskel& /* spell */);

  // Constructor.
  //
  RPG_Player_Spells_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Magic_SpellType_Type_pskel* spell_parser_;
};

class RPG_Player_Export RPG_Player_CharacterBaseXML_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  name (const ::std::string&);

  virtual void
  abilities (const RPG_Player_Abilities&);

  virtual void
  alignment (const RPG_Character_Alignment&);

  virtual void
  attributes (const RPG_Character_Attributes&);

  virtual void
  defaultSize (const RPG_Common_Size&);

  virtual void
  feats (const RPG_Character_Feats&);

  virtual void
  knownSpells (const RPG_Player_Spells&);

  virtual void
  maxHP (unsigned short);

  virtual void
  skills (const RPG_Character_Skills&);

  virtual RPG_Player_CharacterBaseXML
  post_RPG_Player_CharacterBaseXML_Type () = 0;

  // Parser construction API.
  //
  void
  name_parser (::xml_schema::string_pskel&);

  void
  abilities_parser (::RPG_Player_Abilities_Type_pskel&);

  void
  alignment_parser (::RPG_Character_Alignment_Type_pskel&);

  void
  attributes_parser (::RPG_Character_Attributes_Type_pskel&);

  void
  defaultSize_parser (::RPG_Common_Size_Type_pskel&);

  void
  feats_parser (::RPG_Character_Feats_Type_pskel&);

  void
  knownSpells_parser (::RPG_Player_Spells_Type_pskel&);

  void
  maxHP_parser (::xml_schema::unsigned_short_pskel&);

  void
  skills_parser (::RPG_Character_Skills_Type_pskel&);

  void
  parsers (::xml_schema::string_pskel& /* name */,
           ::RPG_Player_Abilities_Type_pskel& /* abilities */,
           ::RPG_Character_Alignment_Type_pskel& /* alignment */,
           ::RPG_Character_Attributes_Type_pskel& /* attributes */,
           ::RPG_Common_Size_Type_pskel& /* defaultSize */,
           ::RPG_Character_Feats_Type_pskel& /* feats */,
           ::RPG_Player_Spells_Type_pskel& /* knownSpells */,
           ::xml_schema::unsigned_short_pskel& /* maxHP */,
           ::RPG_Character_Skills_Type_pskel& /* skills */);

  // Constructor.
  //
  RPG_Player_CharacterBaseXML_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::string_pskel* name_parser_;
  ::RPG_Player_Abilities_Type_pskel* abilities_parser_;
  ::RPG_Character_Alignment_Type_pskel* alignment_parser_;
  ::RPG_Character_Attributes_Type_pskel* attributes_parser_;
  ::RPG_Common_Size_Type_pskel* defaultSize_parser_;
  ::RPG_Character_Feats_Type_pskel* feats_parser_;
  ::RPG_Player_Spells_Type_pskel* knownSpells_parser_;
  ::xml_schema::unsigned_short_pskel* maxHP_parser_;
  ::RPG_Character_Skills_Type_pskel* skills_parser_;
};

class RPG_Player_Export RPG_Player_CharacterXML_Type_pskel: public virtual ::RPG_Player_CharacterBaseXML_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  classXML (const RPG_Character_ClassXML&);

  virtual void
  gender (const RPG_Character_Gender&);

  virtual void
  offhand (const RPG_Character_OffHand&);

  virtual void
  race (const RPG_Character_Race&);

  virtual RPG_Player_CharacterXML
  post_RPG_Player_CharacterXML_Type () = 0;

  // Parser construction API.
  //
  void
  classXML_parser (::RPG_Character_ClassXML_Type_pskel&);

  void
  gender_parser (::RPG_Character_Gender_Type_pskel&);

  void
  offhand_parser (::RPG_Character_OffHand_Type_pskel&);

  void
  race_parser (::RPG_Character_Race_Type_pskel&);

  void
  parsers (::xml_schema::string_pskel& /* name */,
           ::RPG_Player_Abilities_Type_pskel& /* abilities */,
           ::RPG_Character_Alignment_Type_pskel& /* alignment */,
           ::RPG_Character_Attributes_Type_pskel& /* attributes */,
           ::RPG_Common_Size_Type_pskel& /* defaultSize */,
           ::RPG_Character_Feats_Type_pskel& /* feats */,
           ::RPG_Player_Spells_Type_pskel& /* knownSpells */,
           ::xml_schema::unsigned_short_pskel& /* maxHP */,
           ::RPG_Character_Skills_Type_pskel& /* skills */,
           ::RPG_Character_ClassXML_Type_pskel& /* classXML */,
           ::RPG_Character_Gender_Type_pskel& /* gender */,
           ::RPG_Character_OffHand_Type_pskel& /* offhand */,
           ::RPG_Character_Race_Type_pskel& /* race */);

  // Constructor.
  //
  RPG_Player_CharacterXML_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Character_ClassXML_Type_pskel* classXML_parser_;
  ::RPG_Character_Gender_Type_pskel* gender_parser_;
  ::RPG_Character_OffHand_Type_pskel* offhand_parser_;
  ::RPG_Character_Race_Type_pskel* race_parser_;
};

class RPG_Player_Export RPG_Player_PlayerXML_Type_pskel: public virtual ::RPG_Player_CharacterXML_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  gold (unsigned int);

  virtual void
  inventory (const RPG_Item_InventoryXML&);

  virtual void
  XP (unsigned int);

  virtual RPG_Player_PlayerXML
  post_RPG_Player_PlayerXML_Type () = 0;

  // Parser construction API.
  //
  void
  gold_parser (::xml_schema::unsigned_int_pskel&);

  void
  inventory_parser (::RPG_Item_InventoryXML_Type_pskel&);

  void
  XP_parser (::xml_schema::unsigned_int_pskel&);

  void
  parsers (::xml_schema::string_pskel& /* name */,
           ::RPG_Player_Abilities_Type_pskel& /* abilities */,
           ::RPG_Character_Alignment_Type_pskel& /* alignment */,
           ::RPG_Character_Attributes_Type_pskel& /* attributes */,
           ::RPG_Common_Size_Type_pskel& /* defaultSize */,
           ::RPG_Character_Feats_Type_pskel& /* feats */,
           ::RPG_Player_Spells_Type_pskel& /* knownSpells */,
           ::xml_schema::unsigned_short_pskel& /* maxHP */,
           ::RPG_Character_Skills_Type_pskel& /* skills */,
           ::RPG_Character_ClassXML_Type_pskel& /* classXML */,
           ::RPG_Character_Gender_Type_pskel& /* gender */,
           ::RPG_Character_OffHand_Type_pskel& /* offhand */,
           ::RPG_Character_Race_Type_pskel& /* race */,
           ::xml_schema::unsigned_int_pskel& /* gold */,
           ::RPG_Item_InventoryXML_Type_pskel& /* inventory */,
           ::xml_schema::unsigned_int_pskel& /* XP */);

  // Constructor.
  //
  RPG_Player_PlayerXML_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::unsigned_int_pskel* gold_parser_;
  ::RPG_Item_InventoryXML_Type_pskel* inventory_parser_;
  ::xml_schema::unsigned_int_pskel* XP_parser_;
};

class RPG_Player_Export RPG_Player_StateBase_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  conditions (const RPG_Player_Conditions&);

  virtual void
  HP (short);

  virtual void
  post_RPG_Player_StateBase_Type ();

  // Parser construction API.
  //
  void
  conditions_parser (::RPG_Player_Conditions_Type_pskel&);

  void
  HP_parser (::xml_schema::short_pskel&);

  void
  parsers (::RPG_Player_Conditions_Type_pskel& /* conditions */,
           ::xml_schema::short_pskel& /* HP */);

  // Constructor.
  //
  RPG_Player_StateBase_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::RPG_Player_Conditions_Type_pskel* conditions_parser_;
  ::xml_schema::short_pskel* HP_parser_;
};

class RPG_Player_Export RPG_Player_State_Type_pskel: public virtual ::RPG_Player_StateBase_Type_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  file (const ::std::string&);

  virtual void
  post_RPG_Player_State_Type ();

  // Parser construction API.
  //
  void
  file_parser (::xml_schema::string_pskel&);

  void
  parsers (::RPG_Player_Conditions_Type_pskel& /* conditions */,
           ::xml_schema::short_pskel& /* HP */,
           ::xml_schema::string_pskel& /* file */);

  // Constructor.
  //
  RPG_Player_State_Type_pskel ();

  // Implementation.
  //
  protected:
  virtual bool
  _start_element_impl (const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string&,
                       const ::xml_schema::ro_string*);

  virtual bool
  _end_element_impl (const ::xml_schema::ro_string&,
                     const ::xml_schema::ro_string&);

  protected:
  ::xml_schema::string_pskel* file_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_PLAYER_XML_TYPES_H