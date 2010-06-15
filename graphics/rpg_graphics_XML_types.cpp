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

// Begin prologue.
//
//
// End prologue.

#include "rpg_graphics_XML_types.h"

// RPG_Graphics_Graphic_Type_pskel
//

void RPG_Graphics_Graphic_Type_pskel::
category_parser (::RPG_Graphics_Category_Type_pskel& p)
{
  this->category_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
type_parser (::RPG_Graphics_Type_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
orientation_parser (::RPG_Graphics_TileOrientation_Type_pskel& p)
{
  this->orientation_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
style_parser (::RPG_Graphics_TileStyleUnion_Type_pskel& p)
{
  this->style_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
file_parser (::xml_schema::string_pskel& p)
{
  this->file_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
parsers (::RPG_Graphics_Category_Type_pskel& category,
         ::RPG_Graphics_Type_Type_pskel& type,
         ::RPG_Graphics_TileOrientation_Type_pskel& orientation,
         ::RPG_Graphics_TileStyleUnion_Type_pskel& style,
         ::xml_schema::string_pskel& file)
{
  this->category_parser_ = &category;
  this->type_parser_ = &type;
  this->orientation_parser_ = &orientation;
  this->style_parser_ = &style;
  this->file_parser_ = &file;
}

RPG_Graphics_Graphic_Type_pskel::
RPG_Graphics_Graphic_Type_pskel ()
: category_parser_ (0),
  type_parser_ (0),
  orientation_parser_ (0),
  style_parser_ (0),
  file_parser_ (0)
{
}

// RPG_Graphics_Dictionary_Type_pskel
//

void RPG_Graphics_Dictionary_Type_pskel::
graphic_parser (::RPG_Graphics_Graphic_Type_pskel& p)
{
  this->graphic_parser_ = &p;
}

void RPG_Graphics_Dictionary_Type_pskel::
parsers (::RPG_Graphics_Graphic_Type_pskel& graphic)
{
  this->graphic_parser_ = &graphic;
}

RPG_Graphics_Dictionary_Type_pskel::
RPG_Graphics_Dictionary_Type_pskel ()
: graphic_parser_ (0)
{
}

// RPG_Graphics_Graphic_Type_pskel
//

void RPG_Graphics_Graphic_Type_pskel::
category (const RPG_Graphics_Category&)
{
}

void RPG_Graphics_Graphic_Type_pskel::
type (const RPG_Graphics_Type&)
{
}

void RPG_Graphics_Graphic_Type_pskel::
orientation (const RPG_Graphics_TileOrientation&)
{
}

void RPG_Graphics_Graphic_Type_pskel::
style (const RPG_Graphics_TileStyleUnion&)
{
}

void RPG_Graphics_Graphic_Type_pskel::
file (const ::std::string&)
{
}

bool RPG_Graphics_Graphic_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "category" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->category_parser_;

    if (this->category_parser_)
      this->category_parser_->pre ();

    return true;
  }

  if (n == "type" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->type_parser_;

    if (this->type_parser_)
      this->type_parser_->pre ();

    return true;
  }

  if (n == "orientation" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->orientation_parser_;

    if (this->orientation_parser_)
      this->orientation_parser_->pre ();

    return true;
  }

  if (n == "style" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->style_parser_;

    if (this->style_parser_)
      this->style_parser_->pre ();

    return true;
  }

  if (n == "file" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->file_parser_;

    if (this->file_parser_)
      this->file_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Graphics_Graphic_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "category" && ns == "urn:rpg")
  {
    if (this->category_parser_)
      this->category (this->category_parser_->post_RPG_Graphics_Category_Type ());

    return true;
  }

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Graphics_Type_Type ());

    return true;
  }

  if (n == "orientation" && ns == "urn:rpg")
  {
    if (this->orientation_parser_)
      this->orientation (this->orientation_parser_->post_RPG_Graphics_TileOrientation_Type ());

    return true;
  }

  if (n == "style" && ns == "urn:rpg")
  {
    if (this->style_parser_)
      this->style (this->style_parser_->post_RPG_Graphics_TileStyleUnion_Type ());

    return true;
  }

  if (n == "file" && ns == "urn:rpg")
  {
    if (this->file_parser_)
      this->file (this->file_parser_->post_string ());

    return true;
  }

  return false;
}

// RPG_Graphics_Dictionary_Type_pskel
//

void RPG_Graphics_Dictionary_Type_pskel::
graphic (const RPG_Graphics_Graphic&)
{
}

void RPG_Graphics_Dictionary_Type_pskel::
post_RPG_Graphics_Dictionary_Type ()
{
}

bool RPG_Graphics_Dictionary_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "graphic" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->graphic_parser_;

    if (this->graphic_parser_)
      this->graphic_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Graphics_Dictionary_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "graphic" && ns == "urn:rpg")
  {
    if (this->graphic_parser_)
      this->graphic (this->graphic_parser_->post_RPG_Graphics_Graphic_Type ());

    return true;
  }

  return false;
}

// Begin epilogue.
//
//
// End epilogue.

