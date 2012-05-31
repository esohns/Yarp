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
#include "stdafx.h"
//
// End prologue.

#include <xsd/cxx/pre.hxx>

#include "rpg_map_XML_tree.h"

// RPG_Map_DoorState_XMLTree_Type
// 

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (value v)
: ::xml_schema::string (_xsd_RPG_Map_DoorState_XMLTree_Type_literals_[v])
{
}

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (const char* v)
: ::xml_schema::string (v)
{
}

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (const ::std::string& v)
: ::xml_schema::string (v)
{
}

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (const ::xml_schema::string& v)
: ::xml_schema::string (v)
{
}

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (const RPG_Map_DoorState_XMLTree_Type& v,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
: ::xml_schema::string (v, f, c)
{
}

RPG_Map_DoorState_XMLTree_Type& RPG_Map_DoorState_XMLTree_Type::
operator= (value v)
{
  static_cast< ::xml_schema::string& > (*this) = 
  ::xml_schema::string (_xsd_RPG_Map_DoorState_XMLTree_Type_literals_[v]);

  return *this;
}


// RPG_Map_Position_XMLTree_Type
// 

const RPG_Map_Position_XMLTree_Type::x_type& RPG_Map_Position_XMLTree_Type::
x () const
{
  return this->x_.get ();
}

RPG_Map_Position_XMLTree_Type::x_type& RPG_Map_Position_XMLTree_Type::
x ()
{
  return this->x_.get ();
}

void RPG_Map_Position_XMLTree_Type::
x (const x_type& x)
{
  this->x_.set (x);
}

const RPG_Map_Position_XMLTree_Type::y_type& RPG_Map_Position_XMLTree_Type::
y () const
{
  return this->y_.get ();
}

RPG_Map_Position_XMLTree_Type::y_type& RPG_Map_Position_XMLTree_Type::
y ()
{
  return this->y_.get ();
}

void RPG_Map_Position_XMLTree_Type::
y (const y_type& x)
{
  this->y_.set (x);
}


#include <xsd/cxx/xml/dom/parsing-source.hxx>

// RPG_Map_DoorState_XMLTree_Type
//

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (const ::xercesc::DOMElement& e,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
: ::xml_schema::string (e, f, c)
{
  _xsd_RPG_Map_DoorState_XMLTree_Type_convert ();
}

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
: ::xml_schema::string (a, f, c)
{
  _xsd_RPG_Map_DoorState_XMLTree_Type_convert ();
}

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (const ::std::string& s,
                                const ::xercesc::DOMElement* e,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
: ::xml_schema::string (s, e, f, c)
{
  _xsd_RPG_Map_DoorState_XMLTree_Type_convert ();
}

RPG_Map_DoorState_XMLTree_Type* RPG_Map_DoorState_XMLTree_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Map_DoorState_XMLTree_Type (*this, f, c);
}

RPG_Map_DoorState_XMLTree_Type::value RPG_Map_DoorState_XMLTree_Type::
_xsd_RPG_Map_DoorState_XMLTree_Type_convert () const
{
  ::xsd::cxx::tree::enum_comparator< char > c (_xsd_RPG_Map_DoorState_XMLTree_Type_literals_);
  const value* i (::std::lower_bound (
                    _xsd_RPG_Map_DoorState_XMLTree_Type_indexes_,
                    _xsd_RPG_Map_DoorState_XMLTree_Type_indexes_ + 4,
                    *this,
                    c));

  if (i == _xsd_RPG_Map_DoorState_XMLTree_Type_indexes_ + 4 || _xsd_RPG_Map_DoorState_XMLTree_Type_literals_[*i] != *this)
  {
    throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
  }

  return *i;
}

const char* const RPG_Map_DoorState_XMLTree_Type::
_xsd_RPG_Map_DoorState_XMLTree_Type_literals_[4] =
{
  "DOORSTATE_OPEN",
  "DOORSTATE_CLOSED",
  "DOORSTATE_LOCKED",
  "DOORSTATE_BROKEN"
};

const RPG_Map_DoorState_XMLTree_Type::value RPG_Map_DoorState_XMLTree_Type::
_xsd_RPG_Map_DoorState_XMLTree_Type_indexes_[4] =
{
  ::RPG_Map_DoorState_XMLTree_Type::DOORSTATE_BROKEN,
  ::RPG_Map_DoorState_XMLTree_Type::DOORSTATE_CLOSED,
  ::RPG_Map_DoorState_XMLTree_Type::DOORSTATE_LOCKED,
  ::RPG_Map_DoorState_XMLTree_Type::DOORSTATE_OPEN
};

// RPG_Map_Position_XMLTree_Type
//

RPG_Map_Position_XMLTree_Type::
RPG_Map_Position_XMLTree_Type (const x_type& x,
                               const y_type& y)
: ::xml_schema::type (),
  x_ (x, ::xml_schema::flags (), this),
  y_ (y, ::xml_schema::flags (), this)
{
}

RPG_Map_Position_XMLTree_Type::
RPG_Map_Position_XMLTree_Type (const RPG_Map_Position_XMLTree_Type& x,
                               ::xml_schema::flags f,
                               ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  x_ (x.x_, f, this),
  y_ (x.y_, f, this)
{
}

RPG_Map_Position_XMLTree_Type::
RPG_Map_Position_XMLTree_Type (const ::xercesc::DOMElement& e,
                               ::xml_schema::flags f,
                               ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  x_ (f, this),
  y_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void RPG_Map_Position_XMLTree_Type::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // x
    //
    if (n.name () == "x" && n.namespace_ () == "urn:rpg")
    {
      if (!x_.present ())
      {
        this->x_.set (x_traits::create (i, f, this));
        continue;
      }
    }

    // y
    //
    if (n.name () == "y" && n.namespace_ () == "urn:rpg")
    {
      if (!y_.present ())
      {
        this->y_.set (y_traits::create (i, f, this));
        continue;
      }
    }

    break;
  }

  if (!x_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "x",
      "urn:rpg");
  }

  if (!y_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "y",
      "urn:rpg");
  }
}

RPG_Map_Position_XMLTree_Type* RPG_Map_Position_XMLTree_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Map_Position_XMLTree_Type (*this, f, c);
}

RPG_Map_Position_XMLTree_Type::
~RPG_Map_Position_XMLTree_Type ()
{
}

bool
operator== (const RPG_Map_Position_XMLTree_Type& x, const RPG_Map_Position_XMLTree_Type& y)
{
  if (!(x.x () == y.x ()))
    return false;

  if (!(x.y () == y.y ()))
    return false;

  return true;
}

bool
operator!= (const RPG_Map_Position_XMLTree_Type& x, const RPG_Map_Position_XMLTree_Type& y)
{
  return !(x == y);
}

#include <ostream>

::std::ostream&
operator<< (::std::ostream& o, RPG_Map_DoorState_XMLTree_Type::value i)
{
  return o << RPG_Map_DoorState_XMLTree_Type::_xsd_RPG_Map_DoorState_XMLTree_Type_literals_[i];
}

::std::ostream&
operator<< (::std::ostream& o, const RPG_Map_DoorState_XMLTree_Type& i)
{
  return o << static_cast< const ::xml_schema::string& > (i);
}

::std::ostream&
operator<< (::std::ostream& o, const RPG_Map_Position_XMLTree_Type& i)
{
  o << ::std::endl << "x: " << i.x ();
  o << ::std::endl << "y: " << i.y ();
  return o;
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

void
operator<< (::xercesc::DOMElement& e, const RPG_Map_DoorState_XMLTree_Type& i)
{
  e << static_cast< const ::xml_schema::string& > (i);
}

void
operator<< (::xercesc::DOMAttr& a, const RPG_Map_DoorState_XMLTree_Type& i)
{
  a << static_cast< const ::xml_schema::string& > (i);
}

void
operator<< (::xml_schema::list_stream& l,
            const RPG_Map_DoorState_XMLTree_Type& i)
{
  l << static_cast< const ::xml_schema::string& > (i);
}

void
operator<< (::xercesc::DOMElement& e, const RPG_Map_Position_XMLTree_Type& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // x
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "x",
        "urn:rpg",
        e));

    s << i.x ();
  }

  // y
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "y",
        "urn:rpg",
        e));

    s << i.y ();
  }
}

RPG_Map_DoorState_XMLTree_Type::
RPG_Map_DoorState_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
: ::xml_schema::string (s, f, c)
{
  _xsd_RPG_Map_DoorState_XMLTree_Type_convert ();
}

RPG_Map_Position_XMLTree_Type::
RPG_Map_Position_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                               ::xml_schema::flags f,
                               ::xml_schema::container* c)
: ::xml_schema::type (s, f, c),
  x_ (f, this),
  y_ (f, this)
{
  this->parse (s, f);
}

void RPG_Map_Position_XMLTree_Type::
parse (::xml_schema::istream< ACE_InputCDR >& s,
       ::xml_schema::flags f)
{
  {
    x_type r;
    s >> r;
    this->x_.set (r);
  }

  {
    y_type r;
    s >> r;
    this->y_.set (r);
  }
}

::xsd::cxx::tree::ostream< ACE_OutputCDR >&
operator<< (::xsd::cxx::tree::ostream< ACE_OutputCDR >& s,
            const RPG_Map_DoorState_XMLTree_Type& x)
{
  return s << static_cast< const ::xml_schema::string& > (x);
}

::xsd::cxx::tree::ostream< ACE_OutputCDR >&
operator<< (::xsd::cxx::tree::ostream< ACE_OutputCDR >& s,
            const RPG_Map_Position_XMLTree_Type& x)
{
  s << x.x ();
  s << x.y ();
  return s;
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

