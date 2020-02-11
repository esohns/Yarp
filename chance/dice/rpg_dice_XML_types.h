// Copyright (c) 2005-2017 Code Synthesis Tools CC
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

#ifndef CXX_____RPG_DICE_XML_TYPES_H
#define CXX_____RPG_DICE_XML_TYPES_H

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4009911L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

// Forward declarations
//
class RPG_Dice_DieType_Type_pskel;
class RPG_Dice_Roll_Type_pskel;
class RPG_Dice_ValueRange_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_XMLSchema_XML_types.h"

#include "rpg_dice_incl.h"

class RPG_Dice_DieType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Dice_DieType
  post_RPG_Dice_DieType_Type () = 0;
};

class RPG_Dice_Roll_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  numDice (unsigned int);

  virtual void
  typeDice (const RPG_Dice_DieType&);

  virtual void
  modifier (int);

  virtual RPG_Dice_Roll
  post_RPG_Dice_Roll_Type () = 0;

  // Parser construction API.
  //
  void
  numDice_parser (::xml_schema::unsigned_int_pskel&);

  void
  typeDice_parser (::RPG_Dice_DieType_Type_pskel&);

  void
  modifier_parser (::xml_schema::int_pskel&);

  void
  parsers (::xml_schema::unsigned_int_pskel& /* numDice */,
           ::RPG_Dice_DieType_Type_pskel& /* typeDice */,
           ::xml_schema::int_pskel& /* modifier */);

  // Constructor.
  //
  RPG_Dice_Roll_Type_pskel ();

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
  ::xml_schema::unsigned_int_pskel* numDice_parser_;
  ::RPG_Dice_DieType_Type_pskel* typeDice_parser_;
  ::xml_schema::int_pskel* modifier_parser_;
};

class RPG_Dice_ValueRange_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  begin (int);

  virtual void
  end (int);

  virtual RPG_Dice_ValueRange
  post_RPG_Dice_ValueRange_Type () = 0;

  // Parser construction API.
  //
  void
  begin_parser (::xml_schema::int_pskel&);

  void
  end_parser (::xml_schema::int_pskel&);

  void
  parsers (::xml_schema::int_pskel& /* begin */,
           ::xml_schema::int_pskel& /* end */);

  // Constructor.
  //
  RPG_Dice_ValueRange_Type_pskel ();

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
  ::xml_schema::int_pskel* begin_parser_;
  ::xml_schema::int_pskel* end_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX_____RPG_DICE_XML_TYPES_H
