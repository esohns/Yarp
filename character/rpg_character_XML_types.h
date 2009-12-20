// Copyright (C) 2005-2008 Code Synthesis Tools CC
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

#ifndef CXX___RPG_CHARACTER_XML_TYPES_H
#define CXX___RPG_CHARACTER_XML_TYPES_H

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3020000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

// Forward declarations
//
class RPG_Character_Gender_Type_pskel;
class RPG_Character_Race_Type_pskel;
class RPG_Character_MetaClass_Type_pskel;
class RPG_Character_SubClass_Type_pskel;
class RPG_Character_Class_Type_pskel;
class RPG_Character_Attribute_Type_pskel;
class RPG_Character_Condition_Type_pskel;
class RPG_Character_Ability_Type_pskel;
class RPG_Character_Size_Type_pskel;
class RPG_Character_Attributes_Type_pskel;
class RPG_Character_Skill_Type_pskel;
class RPG_Character_SkillValue_Type_pskel;
class RPG_Character_Skills_Type_pskel;
class RPG_Character_Feat_Type_pskel;
class RPG_Character_Feats_Type_pskel;
class RPG_Character_Plane_Type_pskel;
class RPG_Character_Terrain_Type_pskel;
class RPG_Character_Climate_Type_pskel;
class RPG_Character_Environment_Type_pskel;
class RPG_Character_AlignmentCivic_Type_pskel;
class RPG_Character_AlignmentEthic_Type_pskel;
class RPG_Character_Alignment_Type_pskel;
class RPG_Character_EquipmentSlot_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_XMLSchema.h"

#include <rpg_dice_incl.h>
#include "rpg_character_incl.h"

class RPG_Character_Gender_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Gender
  post_RPG_Character_Gender_Type () = 0;
};

class RPG_Character_Race_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Race
  post_RPG_Character_Race_Type () = 0;
};

class RPG_Character_MetaClass_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_MetaClass
  post_RPG_Character_MetaClass_Type () = 0;
};

class RPG_Character_SubClass_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_SubClass
  post_RPG_Character_SubClass_Type () = 0;
};

class RPG_Character_Class_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  metaClass (const RPG_Character_MetaClass&);

  virtual void
  subClass (const RPG_Character_SubClass&);

  virtual RPG_Character_Class
  post_RPG_Character_Class_Type () = 0;

  // Parser construction API.
  //
  void
  metaClass_parser (::RPG_Character_MetaClass_Type_pskel&);

  void
  subClass_parser (::RPG_Character_SubClass_Type_pskel&);

  void
  parsers (::RPG_Character_MetaClass_Type_pskel& /* metaClass */,
           ::RPG_Character_SubClass_Type_pskel& /* subClass */);

  // Constructor.
  //
  RPG_Character_Class_Type_pskel ();

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
  ::RPG_Character_MetaClass_Type_pskel* metaClass_parser_;
  ::RPG_Character_SubClass_Type_pskel* subClass_parser_;
};

class RPG_Character_Attribute_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Attribute
  post_RPG_Character_Attribute_Type () = 0;
};

class RPG_Character_Condition_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Condition
  post_RPG_Character_Condition_Type () = 0;
};

class RPG_Character_Ability_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Ability
  post_RPG_Character_Ability_Type () = 0;
};

class RPG_Character_Size_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Size
  post_RPG_Character_Size_Type () = 0;
};

class RPG_Character_Attributes_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  strength (unsigned char);

  virtual void
  dexterity (unsigned char);

  virtual void
  constitution (unsigned char);

  virtual void
  intelligence (unsigned char);

  virtual void
  wisdom (unsigned char);

  virtual void
  charisma (unsigned char);

  virtual RPG_Character_Attributes
  post_RPG_Character_Attributes_Type () = 0;

  // Parser construction API.
  //
  void
  strength_parser (::xml_schema::unsigned_byte_pskel&);

  void
  dexterity_parser (::xml_schema::unsigned_byte_pskel&);

  void
  constitution_parser (::xml_schema::unsigned_byte_pskel&);

  void
  intelligence_parser (::xml_schema::unsigned_byte_pskel&);

  void
  wisdom_parser (::xml_schema::unsigned_byte_pskel&);

  void
  charisma_parser (::xml_schema::unsigned_byte_pskel&);

  void
  parsers (::xml_schema::unsigned_byte_pskel& /* strength */,
           ::xml_schema::unsigned_byte_pskel& /* dexterity */,
           ::xml_schema::unsigned_byte_pskel& /* constitution */,
           ::xml_schema::unsigned_byte_pskel& /* intelligence */,
           ::xml_schema::unsigned_byte_pskel& /* wisdom */,
           ::xml_schema::unsigned_byte_pskel& /* charisma */);

  // Constructor.
  //
  RPG_Character_Attributes_Type_pskel ();

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
  ::xml_schema::unsigned_byte_pskel* strength_parser_;
  ::xml_schema::unsigned_byte_pskel* dexterity_parser_;
  ::xml_schema::unsigned_byte_pskel* constitution_parser_;
  ::xml_schema::unsigned_byte_pskel* intelligence_parser_;
  ::xml_schema::unsigned_byte_pskel* wisdom_parser_;
  ::xml_schema::unsigned_byte_pskel* charisma_parser_;
};

class RPG_Character_Skill_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Skill
  post_RPG_Character_Skill_Type () = 0;
};

class RPG_Character_SkillValue_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  skill (const RPG_Character_Skill&);

  virtual void
  rank (signed char);

  virtual RPG_Character_SkillValue
  post_RPG_Character_SkillValue_Type () = 0;

  // Parser construction API.
  //
  void
  skill_parser (::RPG_Character_Skill_Type_pskel&);

  void
  rank_parser (::xml_schema::byte_pskel&);

  void
  parsers (::RPG_Character_Skill_Type_pskel& /* skill */,
           ::xml_schema::byte_pskel& /* rank */);

  // Constructor.
  //
  RPG_Character_SkillValue_Type_pskel ();

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
  ::RPG_Character_Skill_Type_pskel* skill_parser_;
  ::xml_schema::byte_pskel* rank_parser_;
};

class RPG_Character_Skills_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  skill (const RPG_Character_SkillValue&);

  virtual RPG_Character_Skills
  post_RPG_Character_Skills_Type () = 0;

  // Parser construction API.
  //
  void
  skill_parser (::RPG_Character_SkillValue_Type_pskel&);

  void
  parsers (::RPG_Character_SkillValue_Type_pskel& /* skill */);

  // Constructor.
  //
  RPG_Character_Skills_Type_pskel ();

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
  ::RPG_Character_SkillValue_Type_pskel* skill_parser_;
};

class RPG_Character_Feat_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Feat
  post_RPG_Character_Feat_Type () = 0;
};

class RPG_Character_Feats_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  feat (const RPG_Character_Feat&);

  virtual RPG_Character_Feats
  post_RPG_Character_Feats_Type () = 0;

  // Parser construction API.
  //
  void
  feat_parser (::RPG_Character_Feat_Type_pskel&);

  void
  parsers (::RPG_Character_Feat_Type_pskel& /* feat */);

  // Constructor.
  //
  RPG_Character_Feats_Type_pskel ();

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
  ::RPG_Character_Feat_Type_pskel* feat_parser_;
};

class RPG_Character_Plane_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  post_RPG_Character_Plane_Type ();
};

class RPG_Character_Terrain_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Terrain
  post_RPG_Character_Terrain_Type () = 0;
};

class RPG_Character_Climate_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_Climate
  post_RPG_Character_Climate_Type () = 0;
};

class RPG_Character_Environment_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  terrain (const RPG_Character_Terrain&);

  virtual void
  climate (const RPG_Character_Climate&);

  virtual RPG_Character_Environment
  post_RPG_Character_Environment_Type () = 0;

  // Parser construction API.
  //
  void
  terrain_parser (::RPG_Character_Terrain_Type_pskel&);

  void
  climate_parser (::RPG_Character_Climate_Type_pskel&);

  void
  parsers (::RPG_Character_Terrain_Type_pskel& /* terrain */,
           ::RPG_Character_Climate_Type_pskel& /* climate */);

  // Constructor.
  //
  RPG_Character_Environment_Type_pskel ();

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
  ::RPG_Character_Terrain_Type_pskel* terrain_parser_;
  ::RPG_Character_Climate_Type_pskel* climate_parser_;
};

class RPG_Character_AlignmentCivic_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_AlignmentCivic
  post_RPG_Character_AlignmentCivic_Type () = 0;
};

class RPG_Character_AlignmentEthic_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_AlignmentEthic
  post_RPG_Character_AlignmentEthic_Type () = 0;
};

class RPG_Character_Alignment_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  civic (const RPG_Character_AlignmentCivic&);

  virtual void
  ethic (const RPG_Character_AlignmentEthic&);

  virtual RPG_Character_Alignment
  post_RPG_Character_Alignment_Type () = 0;

  // Parser construction API.
  //
  void
  civic_parser (::RPG_Character_AlignmentCivic_Type_pskel&);

  void
  ethic_parser (::RPG_Character_AlignmentEthic_Type_pskel&);

  void
  parsers (::RPG_Character_AlignmentCivic_Type_pskel& /* civic */,
           ::RPG_Character_AlignmentEthic_Type_pskel& /* ethic */);

  // Constructor.
  //
  RPG_Character_Alignment_Type_pskel ();

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
  ::RPG_Character_AlignmentCivic_Type_pskel* civic_parser_;
  ::RPG_Character_AlignmentEthic_Type_pskel* ethic_parser_;
};

class RPG_Character_EquipmentSlot_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Character_EquipmentSlot
  post_RPG_Character_EquipmentSlot_Type () = 0;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_CHARACTER_XML_TYPES_H
