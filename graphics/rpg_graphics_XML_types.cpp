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

// RPG_Graphics_Element_Type_pskel
//

void RPG_Graphics_Element_Type_pskel::
type_parser (::RPG_Graphics_ElementTypeUnion_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Graphics_Element_Type_pskel::
offsetX_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->offsetX_parser_ = &p;
}

void RPG_Graphics_Element_Type_pskel::
offsetY_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->offsetY_parser_ = &p;
}

void RPG_Graphics_Element_Type_pskel::
width_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->width_parser_ = &p;
}

void RPG_Graphics_Element_Type_pskel::
height_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->height_parser_ = &p;
}

void RPG_Graphics_Element_Type_pskel::
parsers (::RPG_Graphics_ElementTypeUnion_Type_pskel& type,
         ::xml_schema::unsigned_int_pskel& offsetX,
         ::xml_schema::unsigned_int_pskel& offsetY,
         ::xml_schema::unsigned_int_pskel& width,
         ::xml_schema::unsigned_int_pskel& height)
{
  this->type_parser_ = &type;
  this->offsetX_parser_ = &offsetX;
  this->offsetY_parser_ = &offsetY;
  this->width_parser_ = &width;
  this->height_parser_ = &height;
}

RPG_Graphics_Element_Type_pskel::
RPG_Graphics_Element_Type_pskel ()
: type_parser_ (0),
  offsetX_parser_ (0),
  offsetY_parser_ (0),
  width_parser_ (0),
  height_parser_ (0)
{
}

// RPG_Graphics_Tile_Type_pskel
//

void RPG_Graphics_Tile_Type_pskel::
type_parser (::RPG_Graphics_TileType_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Graphics_Tile_Type_pskel::
style_parser (::RPG_Graphics_StyleUnion_Type_pskel& p)
{
  this->style_parser_ = &p;
}

void RPG_Graphics_Tile_Type_pskel::
orientation_parser (::RPG_Graphics_Orientation_Type_pskel& p)
{
  this->orientation_parser_ = &p;
}

void RPG_Graphics_Tile_Type_pskel::
file_parser (::xml_schema::string_pskel& p)
{
  this->file_parser_ = &p;
}

void RPG_Graphics_Tile_Type_pskel::
offsetX_parser (::xml_schema::integer_pskel& p)
{
  this->offsetX_parser_ = &p;
}

void RPG_Graphics_Tile_Type_pskel::
offsetY_parser (::xml_schema::integer_pskel& p)
{
  this->offsetY_parser_ = &p;
}

void RPG_Graphics_Tile_Type_pskel::
open_parser (::xml_schema::boolean_pskel& p)
{
  this->open_parser_ = &p;
}

void RPG_Graphics_Tile_Type_pskel::
broken_parser (::xml_schema::boolean_pskel& p)
{
  this->broken_parser_ = &p;
}

void RPG_Graphics_Tile_Type_pskel::
parsers (::RPG_Graphics_TileType_Type_pskel& type,
         ::RPG_Graphics_StyleUnion_Type_pskel& style,
         ::RPG_Graphics_Orientation_Type_pskel& orientation,
         ::xml_schema::string_pskel& file,
         ::xml_schema::integer_pskel& offsetX,
         ::xml_schema::integer_pskel& offsetY,
         ::xml_schema::boolean_pskel& open,
         ::xml_schema::boolean_pskel& broken)
{
  this->type_parser_ = &type;
  this->style_parser_ = &style;
  this->orientation_parser_ = &orientation;
  this->file_parser_ = &file;
  this->offsetX_parser_ = &offsetX;
  this->offsetY_parser_ = &offsetY;
  this->open_parser_ = &open;
  this->broken_parser_ = &broken;
}

RPG_Graphics_Tile_Type_pskel::
RPG_Graphics_Tile_Type_pskel ()
: type_parser_ (0),
  style_parser_ (0),
  orientation_parser_ (0),
  file_parser_ (0),
  offsetX_parser_ (0),
  offsetY_parser_ (0),
  open_parser_ (0),
  broken_parser_ (0)
{
}

// RPG_Graphics_TileSet_Type_pskel
//

void RPG_Graphics_TileSet_Type_pskel::
type_parser (::RPG_Graphics_TileSetType_Type_pskel& p)
{
  this->type_parser_ = &p;
}

void RPG_Graphics_TileSet_Type_pskel::
style_parser (::RPG_Graphics_StyleUnion_Type_pskel& p)
{
  this->style_parser_ = &p;
}

void RPG_Graphics_TileSet_Type_pskel::
tile_parser (::RPG_Graphics_Tile_Type_pskel& p)
{
  this->tile_parser_ = &p;
}

void RPG_Graphics_TileSet_Type_pskel::
half_parser (::xml_schema::boolean_pskel& p)
{
  this->half_parser_ = &p;
}

void RPG_Graphics_TileSet_Type_pskel::
parsers (::RPG_Graphics_TileSetType_Type_pskel& type,
         ::RPG_Graphics_StyleUnion_Type_pskel& style,
         ::RPG_Graphics_Tile_Type_pskel& tile,
         ::xml_schema::boolean_pskel& half)
{
  this->type_parser_ = &type;
  this->style_parser_ = &style;
  this->tile_parser_ = &tile;
  this->half_parser_ = &half;
}

RPG_Graphics_TileSet_Type_pskel::
RPG_Graphics_TileSet_Type_pskel ()
: type_parser_ (0),
  style_parser_ (0),
  tile_parser_ (0),
  half_parser_ (0)
{
}

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
tile_parser (::RPG_Graphics_Tile_Type_pskel& p)
{
  this->tile_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
tileset_parser (::RPG_Graphics_TileSet_Type_pskel& p)
{
  this->tileset_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
element_parser (::RPG_Graphics_Element_Type_pskel& p)
{
  this->element_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
file_parser (::xml_schema::string_pskel& p)
{
  this->file_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
size_parser (::xml_schema::unsigned_int_pskel& p)
{
  this->size_parser_ = &p;
}

void RPG_Graphics_Graphic_Type_pskel::
parsers (::RPG_Graphics_Category_Type_pskel& category,
         ::RPG_Graphics_Type_Type_pskel& type,
         ::RPG_Graphics_Tile_Type_pskel& tile,
         ::RPG_Graphics_TileSet_Type_pskel& tileset,
         ::RPG_Graphics_Element_Type_pskel& element,
         ::xml_schema::string_pskel& file,
         ::xml_schema::unsigned_int_pskel& size)
{
  this->category_parser_ = &category;
  this->type_parser_ = &type;
  this->tile_parser_ = &tile;
  this->tileset_parser_ = &tileset;
  this->element_parser_ = &element;
  this->file_parser_ = &file;
  this->size_parser_ = &size;
}

RPG_Graphics_Graphic_Type_pskel::
RPG_Graphics_Graphic_Type_pskel ()
: category_parser_ (0),
  type_parser_ (0),
  tile_parser_ (0),
  tileset_parser_ (0),
  element_parser_ (0),
  file_parser_ (0),
  size_parser_ (0)
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

// RPG_Graphics_Element_Type_pskel
//

void RPG_Graphics_Element_Type_pskel::
type (const RPG_Graphics_ElementTypeUnion&)
{
}

void RPG_Graphics_Element_Type_pskel::
offsetX (unsigned int)
{
}

void RPG_Graphics_Element_Type_pskel::
offsetY (unsigned int)
{
}

void RPG_Graphics_Element_Type_pskel::
width (unsigned int)
{
}

void RPG_Graphics_Element_Type_pskel::
height (unsigned int)
{
}

bool RPG_Graphics_Element_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->type_parser_;

    if (this->type_parser_)
      this->type_parser_->pre ();

    return true;
  }

  if (n == "offsetX" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->offsetX_parser_;

    if (this->offsetX_parser_)
      this->offsetX_parser_->pre ();

    return true;
  }

  if (n == "offsetY" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->offsetY_parser_;

    if (this->offsetY_parser_)
      this->offsetY_parser_->pre ();

    return true;
  }

  if (n == "width" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->width_parser_;

    if (this->width_parser_)
      this->width_parser_->pre ();

    return true;
  }

  if (n == "height" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->height_parser_;

    if (this->height_parser_)
      this->height_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Graphics_Element_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Graphics_ElementTypeUnion_Type ());

    return true;
  }

  if (n == "offsetX" && ns == "urn:rpg")
  {
    if (this->offsetX_parser_)
      this->offsetX (this->offsetX_parser_->post_unsigned_int ());

    return true;
  }

  if (n == "offsetY" && ns == "urn:rpg")
  {
    if (this->offsetY_parser_)
      this->offsetY (this->offsetY_parser_->post_unsigned_int ());

    return true;
  }

  if (n == "width" && ns == "urn:rpg")
  {
    if (this->width_parser_)
      this->width (this->width_parser_->post_unsigned_int ());

    return true;
  }

  if (n == "height" && ns == "urn:rpg")
  {
    if (this->height_parser_)
      this->height (this->height_parser_->post_unsigned_int ());

    return true;
  }

  return false;
}

// RPG_Graphics_Tile_Type_pskel
//

void RPG_Graphics_Tile_Type_pskel::
type (const RPG_Graphics_TileType&)
{
}

void RPG_Graphics_Tile_Type_pskel::
style (const RPG_Graphics_StyleUnion&)
{
}

void RPG_Graphics_Tile_Type_pskel::
orientation (const RPG_Graphics_Orientation&)
{
}

void RPG_Graphics_Tile_Type_pskel::
file (const ::std::string&)
{
}

void RPG_Graphics_Tile_Type_pskel::
offsetX (long long)
{
}

void RPG_Graphics_Tile_Type_pskel::
offsetY (long long)
{
}

void RPG_Graphics_Tile_Type_pskel::
open (bool)
{
}

void RPG_Graphics_Tile_Type_pskel::
broken (bool)
{
}

bool RPG_Graphics_Tile_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->type_parser_;

    if (this->type_parser_)
      this->type_parser_->pre ();

    return true;
  }

  if (n == "style" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->style_parser_;

    if (this->style_parser_)
      this->style_parser_->pre ();

    return true;
  }

  if (n == "orientation" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->orientation_parser_;

    if (this->orientation_parser_)
      this->orientation_parser_->pre ();

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

bool RPG_Graphics_Tile_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Graphics_TileType_Type ());

    return true;
  }

  if (n == "style" && ns == "urn:rpg")
  {
    if (this->style_parser_)
      this->style (this->style_parser_->post_RPG_Graphics_StyleUnion_Type ());

    return true;
  }

  if (n == "orientation" && ns == "urn:rpg")
  {
    if (this->orientation_parser_)
      this->orientation (this->orientation_parser_->post_RPG_Graphics_Orientation_Type ());

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

bool RPG_Graphics_Tile_Type_pskel::
_attribute_impl (const ::xml_schema::ro_string& ns,
                 const ::xml_schema::ro_string& n,
                 const ::xml_schema::ro_string& v)
{
  if (this->::xml_schema::complex_content::_attribute_impl (ns, n, v))
    return true;

  if (n == "offsetX" && ns.empty ())
  {
    if (this->offsetX_parser_)
    {
      this->offsetX_parser_->pre ();
      this->offsetX_parser_->_pre_impl ();
      this->offsetX_parser_->_characters (v);
      this->offsetX_parser_->_post_impl ();
      this->offsetX (this->offsetX_parser_->post_integer ());
    }

    return true;
  }

  if (n == "offsetY" && ns.empty ())
  {
    if (this->offsetY_parser_)
    {
      this->offsetY_parser_->pre ();
      this->offsetY_parser_->_pre_impl ();
      this->offsetY_parser_->_characters (v);
      this->offsetY_parser_->_post_impl ();
      this->offsetY (this->offsetY_parser_->post_integer ());
    }

    return true;
  }

  if (n == "open" && ns.empty ())
  {
    if (this->open_parser_)
    {
      this->open_parser_->pre ();
      this->open_parser_->_pre_impl ();
      this->open_parser_->_characters (v);
      this->open_parser_->_post_impl ();
      this->open (this->open_parser_->post_boolean ());
    }

    return true;
  }

  if (n == "broken" && ns.empty ())
  {
    if (this->broken_parser_)
    {
      this->broken_parser_->pre ();
      this->broken_parser_->_pre_impl ();
      this->broken_parser_->_characters (v);
      this->broken_parser_->_post_impl ();
      this->broken (this->broken_parser_->post_boolean ());
    }

    return true;
  }

  return false;
}

// RPG_Graphics_TileSet_Type_pskel
//

void RPG_Graphics_TileSet_Type_pskel::
type (const RPG_Graphics_TileSetType&)
{
}

void RPG_Graphics_TileSet_Type_pskel::
style (const RPG_Graphics_StyleUnion&)
{
}

void RPG_Graphics_TileSet_Type_pskel::
tile (const RPG_Graphics_Tile&)
{
}

void RPG_Graphics_TileSet_Type_pskel::
half (bool)
{
}

bool RPG_Graphics_TileSet_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->type_parser_;

    if (this->type_parser_)
      this->type_parser_->pre ();

    return true;
  }

  if (n == "style" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->style_parser_;

    if (this->style_parser_)
      this->style_parser_->pre ();

    return true;
  }

  if (n == "tile" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->tile_parser_;

    if (this->tile_parser_)
      this->tile_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Graphics_TileSet_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "type" && ns == "urn:rpg")
  {
    if (this->type_parser_)
      this->type (this->type_parser_->post_RPG_Graphics_TileSetType_Type ());

    return true;
  }

  if (n == "style" && ns == "urn:rpg")
  {
    if (this->style_parser_)
      this->style (this->style_parser_->post_RPG_Graphics_StyleUnion_Type ());

    return true;
  }

  if (n == "tile" && ns == "urn:rpg")
  {
    if (this->tile_parser_)
      this->tile (this->tile_parser_->post_RPG_Graphics_Tile_Type ());

    return true;
  }

  return false;
}

bool RPG_Graphics_TileSet_Type_pskel::
_attribute_impl (const ::xml_schema::ro_string& ns,
                 const ::xml_schema::ro_string& n,
                 const ::xml_schema::ro_string& v)
{
  if (this->::xml_schema::complex_content::_attribute_impl (ns, n, v))
    return true;

  if (n == "half" && ns.empty ())
  {
    if (this->half_parser_)
    {
      this->half_parser_->pre ();
      this->half_parser_->_pre_impl ();
      this->half_parser_->_characters (v);
      this->half_parser_->_post_impl ();
      this->half (this->half_parser_->post_boolean ());
    }

    return true;
  }

  return false;
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
tile (const RPG_Graphics_Tile&)
{
}

void RPG_Graphics_Graphic_Type_pskel::
tileset (const RPG_Graphics_TileSet&)
{
}

void RPG_Graphics_Graphic_Type_pskel::
element (const RPG_Graphics_Element&)
{
}

void RPG_Graphics_Graphic_Type_pskel::
file (const ::std::string&)
{
}

void RPG_Graphics_Graphic_Type_pskel::
size (unsigned int)
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

  if (n == "tile" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->tile_parser_;

    if (this->tile_parser_)
      this->tile_parser_->pre ();

    return true;
  }

  if (n == "tileset" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->tileset_parser_;

    if (this->tileset_parser_)
      this->tileset_parser_->pre ();

    return true;
  }

  if (n == "element" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->element_parser_;

    if (this->element_parser_)
      this->element_parser_->pre ();

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

  if (n == "tile" && ns == "urn:rpg")
  {
    if (this->tile_parser_)
      this->tile (this->tile_parser_->post_RPG_Graphics_Tile_Type ());

    return true;
  }

  if (n == "tileset" && ns == "urn:rpg")
  {
    if (this->tileset_parser_)
      this->tileset (this->tileset_parser_->post_RPG_Graphics_TileSet_Type ());

    return true;
  }

  if (n == "element" && ns == "urn:rpg")
  {
    if (this->element_parser_)
      this->element (this->element_parser_->post_RPG_Graphics_Element_Type ());

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

bool RPG_Graphics_Graphic_Type_pskel::
_attribute_impl (const ::xml_schema::ro_string& ns,
                 const ::xml_schema::ro_string& n,
                 const ::xml_schema::ro_string& v)
{
  if (this->::xml_schema::complex_content::_attribute_impl (ns, n, v))
    return true;

  if (n == "size" && ns.empty ())
  {
    if (this->size_parser_)
    {
      this->size_parser_->pre ();
      this->size_parser_->_pre_impl ();
      this->size_parser_->_characters (v);
      this->size_parser_->_post_impl ();
      this->size (this->size_parser_->post_unsigned_int ());
    }

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

