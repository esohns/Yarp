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

#ifndef CXX_____RPG_GRAPHICS_XML_TYPES_H
#define CXX_____RPG_GRAPHICS_XML_TYPES_H

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
class RPG_Graphics_Category_Type_pskel;
class RPG_Graphics_TileOrientation_Type_pskel;
class RPG_Graphics_FloorStyle_Type_pskel;
class RPG_Graphics_StairsStyle_Type_pskel;
class RPG_Graphics_WallStyle_Type_pskel;
class RPG_Graphics_DoorStyle_Type_pskel;
class RPG_Graphics_StyleUnion_Type_pskel;
class RPG_Graphics_Type_Type_pskel;
class RPG_Graphics_InterfaceElementType_Type_pskel;
class RPG_Graphics_ElementTypeUnion_Type_pskel;
class RPG_Graphics_Element_Type_pskel;
class RPG_Graphics_Graphic_Type_pskel;
class RPG_Graphics_Dictionary_Type_pskel;

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_PARSER_USE_CHAR
#define XSD_CXX_PARSER_USE_CHAR
#endif

#include "rpg_XMLSchema_XML_types.h"

#include "rpg_graphics_incl.h"

class RPG_Graphics_Category_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Graphics_Category
  post_RPG_Graphics_Category_Type () = 0;
};

class RPG_Graphics_TileOrientation_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Graphics_TileOrientation
  post_RPG_Graphics_TileOrientation_Type () = 0;
};

class RPG_Graphics_FloorStyle_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Graphics_FloorStyle
  post_RPG_Graphics_FloorStyle_Type () = 0;
};

class RPG_Graphics_StairsStyle_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Graphics_StairsStyle
  post_RPG_Graphics_StairsStyle_Type () = 0;
};

class RPG_Graphics_WallStyle_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Graphics_WallStyle
  post_RPG_Graphics_WallStyle_Type () = 0;
};

class RPG_Graphics_DoorStyle_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Graphics_DoorStyle
  post_RPG_Graphics_DoorStyle_Type () = 0;
};

class RPG_Graphics_StyleUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Graphics_StyleUnion
  post_RPG_Graphics_StyleUnion_Type () = 0;
};

class RPG_Graphics_Type_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Graphics_Type
  post_RPG_Graphics_Type_Type () = 0;
};

class RPG_Graphics_InterfaceElementType_Type_pskel: public virtual ::xml_schema::string_pskel
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual RPG_Graphics_InterfaceElementType
  post_RPG_Graphics_InterfaceElementType_Type () = 0;
};

class RPG_Graphics_ElementTypeUnion_Type_pskel: public ::xml_schema::simple_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();
  //
  // virtual void
  // _characters (const ::xml_schema::ro_string&);

  virtual RPG_Graphics_ElementTypeUnion
  post_RPG_Graphics_ElementTypeUnion_Type () = 0;
};

class RPG_Graphics_Element_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  type (const RPG_Graphics_ElementTypeUnion&);

  virtual void
  offsetX (unsigned int);

  virtual void
  offsetY (unsigned int);

  virtual void
  width (unsigned int);

  virtual void
  height (unsigned int);

  virtual RPG_Graphics_Element
  post_RPG_Graphics_Element_Type () = 0;

  // Parser construction API.
  //
  void
  type_parser (::RPG_Graphics_ElementTypeUnion_Type_pskel&);

  void
  offsetX_parser (::xml_schema::unsigned_int_pskel&);

  void
  offsetY_parser (::xml_schema::unsigned_int_pskel&);

  void
  width_parser (::xml_schema::unsigned_int_pskel&);

  void
  height_parser (::xml_schema::unsigned_int_pskel&);

  void
  parsers (::RPG_Graphics_ElementTypeUnion_Type_pskel& /* type */,
           ::xml_schema::unsigned_int_pskel& /* offsetX */,
           ::xml_schema::unsigned_int_pskel& /* offsetY */,
           ::xml_schema::unsigned_int_pskel& /* width */,
           ::xml_schema::unsigned_int_pskel& /* height */);

  // Constructor.
  //
  RPG_Graphics_Element_Type_pskel ();

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
  ::RPG_Graphics_ElementTypeUnion_Type_pskel* type_parser_;
  ::xml_schema::unsigned_int_pskel* offsetX_parser_;
  ::xml_schema::unsigned_int_pskel* offsetY_parser_;
  ::xml_schema::unsigned_int_pskel* width_parser_;
  ::xml_schema::unsigned_int_pskel* height_parser_;
};

class RPG_Graphics_Graphic_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  category (const RPG_Graphics_Category&);

  virtual void
  type (const RPG_Graphics_Type&);

  virtual void
  orientation (const RPG_Graphics_TileOrientation&);

  virtual void
  style (const RPG_Graphics_StyleUnion&);

  virtual void
  element (const RPG_Graphics_Element&);

  virtual void
  file (const ::std::string&);

  virtual RPG_Graphics_Graphic
  post_RPG_Graphics_Graphic_Type () = 0;

  // Parser construction API.
  //
  void
  category_parser (::RPG_Graphics_Category_Type_pskel&);

  void
  type_parser (::RPG_Graphics_Type_Type_pskel&);

  void
  orientation_parser (::RPG_Graphics_TileOrientation_Type_pskel&);

  void
  style_parser (::RPG_Graphics_StyleUnion_Type_pskel&);

  void
  element_parser (::RPG_Graphics_Element_Type_pskel&);

  void
  file_parser (::xml_schema::string_pskel&);

  void
  parsers (::RPG_Graphics_Category_Type_pskel& /* category */,
           ::RPG_Graphics_Type_Type_pskel& /* type */,
           ::RPG_Graphics_TileOrientation_Type_pskel& /* orientation */,
           ::RPG_Graphics_StyleUnion_Type_pskel& /* style */,
           ::RPG_Graphics_Element_Type_pskel& /* element */,
           ::xml_schema::string_pskel& /* file */);

  // Constructor.
  //
  RPG_Graphics_Graphic_Type_pskel ();

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
  ::RPG_Graphics_Category_Type_pskel* category_parser_;
  ::RPG_Graphics_Type_Type_pskel* type_parser_;
  ::RPG_Graphics_TileOrientation_Type_pskel* orientation_parser_;
  ::RPG_Graphics_StyleUnion_Type_pskel* style_parser_;
  ::RPG_Graphics_Element_Type_pskel* element_parser_;
  ::xml_schema::string_pskel* file_parser_;
};

class RPG_Graphics_Dictionary_Type_pskel: public ::xml_schema::complex_content
{
  public:
  // Parser callbacks. Override them in your implementation.
  //
  // virtual void
  // pre ();

  virtual void
  graphic (const RPG_Graphics_Graphic&);

  virtual void
  post_RPG_Graphics_Dictionary_Type ();

  // Parser construction API.
  //
  void
  graphic_parser (::RPG_Graphics_Graphic_Type_pskel&);

  void
  parsers (::RPG_Graphics_Graphic_Type_pskel& /* graphic */);

  // Constructor.
  //
  RPG_Graphics_Dictionary_Type_pskel ();

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
  ::RPG_Graphics_Graphic_Type_pskel* graphic_parser_;
};

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX_____RPG_GRAPHICS_XML_TYPES_H
