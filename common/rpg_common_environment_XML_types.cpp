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

// Begin prologue.
//
//
// End prologue.

#include "rpg_common_environment_XML_types.h"

// RPG_Common_Environment_Type_pskel
//

void RPG_Common_Environment_Type_pskel::
terrain_parser (::RPG_Common_Terrain_Type_pskel& p)
{
  this->terrain_parser_ = &p;
}

void RPG_Common_Environment_Type_pskel::
climate_parser (::RPG_Common_Climate_Type_pskel& p)
{
  this->climate_parser_ = &p;
}

void RPG_Common_Environment_Type_pskel::
outdoors_parser (::xml_schema::boolean_pskel& p)
{
  this->outdoors_parser_ = &p;
}

void RPG_Common_Environment_Type_pskel::
parsers (::RPG_Common_Terrain_Type_pskel& terrain,
         ::RPG_Common_Climate_Type_pskel& climate,
         ::xml_schema::boolean_pskel& outdoors)
{
  this->terrain_parser_ = &terrain;
  this->climate_parser_ = &climate;
  this->outdoors_parser_ = &outdoors;
}

RPG_Common_Environment_Type_pskel::
RPG_Common_Environment_Type_pskel ()
: terrain_parser_ (0),
  climate_parser_ (0),
  outdoors_parser_ (0)
{
}

// RPG_Common_Environment_Type_pskel
//

void RPG_Common_Environment_Type_pskel::
terrain (const RPG_Common_Terrain&)
{
}

void RPG_Common_Environment_Type_pskel::
climate (const RPG_Common_Climate&)
{
}

void RPG_Common_Environment_Type_pskel::
outdoors (bool)
{
}

bool RPG_Common_Environment_Type_pskel::
_start_element_impl (const ::xml_schema::ro_string& ns,
                     const ::xml_schema::ro_string& n,
                     const ::xml_schema::ro_string* t)
{
  XSD_UNUSED (t);

  if (this->::xml_schema::complex_content::_start_element_impl (ns, n, t))
    return true;

  if (n == "terrain" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->terrain_parser_;

    if (this->terrain_parser_)
      this->terrain_parser_->pre ();

    return true;
  }

  if (n == "climate" && ns == "urn:rpg")
  {
    this->::xml_schema::complex_content::context_.top ().parser_ = this->climate_parser_;

    if (this->climate_parser_)
      this->climate_parser_->pre ();

    return true;
  }

  return false;
}

bool RPG_Common_Environment_Type_pskel::
_end_element_impl (const ::xml_schema::ro_string& ns,
                   const ::xml_schema::ro_string& n)
{
  if (this->::xml_schema::complex_content::_end_element_impl (ns, n))
    return true;

  if (n == "terrain" && ns == "urn:rpg")
  {
    if (this->terrain_parser_)
      this->terrain (this->terrain_parser_->post_RPG_Common_Terrain_Type ());

    return true;
  }

  if (n == "climate" && ns == "urn:rpg")
  {
    if (this->climate_parser_)
      this->climate (this->climate_parser_->post_RPG_Common_Climate_Type ());

    return true;
  }

  return false;
}

bool RPG_Common_Environment_Type_pskel::
_attribute_impl (const ::xml_schema::ro_string& ns,
                 const ::xml_schema::ro_string& n,
                 const ::xml_schema::ro_string& v)
{
  if (this->::xml_schema::complex_content::_attribute_impl (ns, n, v))
    return true;

  if (n == "outdoors" && ns.empty ())
  {
    if (this->outdoors_parser_)
    {
      this->outdoors_parser_->pre ();
      this->outdoors_parser_->_pre_impl ();
      this->outdoors_parser_->_characters (v);
      this->outdoors_parser_->_post_impl ();
      this->outdoors (this->outdoors_parser_->post_boolean ());
    }

    return true;
  }

  return false;
}

// Begin epilogue.
//
//
// End epilogue.

