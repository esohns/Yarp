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


// RPG_Map_Door_XMLTree_Type
// 

const RPG_Map_Door_XMLTree_Type::position_type& RPG_Map_Door_XMLTree_Type::
position () const
{
  return this->position_.get ();
}

RPG_Map_Door_XMLTree_Type::position_type& RPG_Map_Door_XMLTree_Type::
position ()
{
  return this->position_.get ();
}

void RPG_Map_Door_XMLTree_Type::
position (const position_type& x)
{
  this->position_.set (x);
}

void RPG_Map_Door_XMLTree_Type::
position (::std::auto_ptr< position_type > x)
{
  this->position_.set (x);
}

const RPG_Map_Door_XMLTree_Type::state_type& RPG_Map_Door_XMLTree_Type::
state () const
{
  return this->state_.get ();
}

RPG_Map_Door_XMLTree_Type::state_type& RPG_Map_Door_XMLTree_Type::
state ()
{
  return this->state_.get ();
}

void RPG_Map_Door_XMLTree_Type::
state (const state_type& x)
{
  this->state_.set (x);
}

void RPG_Map_Door_XMLTree_Type::
state (::std::auto_ptr< state_type > x)
{
  this->state_.set (x);
}


// RPG_Map_Level_XMLTree_Type
// 

const RPG_Map_Level_XMLTree_Type::name_type& RPG_Map_Level_XMLTree_Type::
name () const
{
  return this->name_.get ();
}

RPG_Map_Level_XMLTree_Type::name_type& RPG_Map_Level_XMLTree_Type::
name ()
{
  return this->name_.get ();
}

void RPG_Map_Level_XMLTree_Type::
name (const name_type& x)
{
  this->name_.set (x);
}

void RPG_Map_Level_XMLTree_Type::
name (::std::auto_ptr< name_type > x)
{
  this->name_.set (x);
}

const RPG_Map_Level_XMLTree_Type::environment_type& RPG_Map_Level_XMLTree_Type::
environment () const
{
  return this->environment_.get ();
}

RPG_Map_Level_XMLTree_Type::environment_type& RPG_Map_Level_XMLTree_Type::
environment ()
{
  return this->environment_.get ();
}

void RPG_Map_Level_XMLTree_Type::
environment (const environment_type& x)
{
  this->environment_.set (x);
}

void RPG_Map_Level_XMLTree_Type::
environment (::std::auto_ptr< environment_type > x)
{
  this->environment_.set (x);
}

const RPG_Map_Level_XMLTree_Type::map_type& RPG_Map_Level_XMLTree_Type::
map () const
{
  return this->map_.get ();
}

RPG_Map_Level_XMLTree_Type::map_type& RPG_Map_Level_XMLTree_Type::
map ()
{
  return this->map_.get ();
}

void RPG_Map_Level_XMLTree_Type::
map (const map_type& x)
{
  this->map_.set (x);
}

void RPG_Map_Level_XMLTree_Type::
map (::std::auto_ptr< map_type > x)
{
  this->map_.set (x);
}


// RPG_Map_State_XMLTree_Type
// 

const RPG_Map_State_XMLTree_Type::file_type& RPG_Map_State_XMLTree_Type::
file () const
{
  return this->file_.get ();
}

RPG_Map_State_XMLTree_Type::file_type& RPG_Map_State_XMLTree_Type::
file ()
{
  return this->file_.get ();
}

void RPG_Map_State_XMLTree_Type::
file (const file_type& x)
{
  this->file_.set (x);
}

void RPG_Map_State_XMLTree_Type::
file (::std::auto_ptr< file_type > x)
{
  this->file_.set (x);
}

const RPG_Map_State_XMLTree_Type::door_sequence& RPG_Map_State_XMLTree_Type::
door () const
{
  return this->door_;
}

RPG_Map_State_XMLTree_Type::door_sequence& RPG_Map_State_XMLTree_Type::
door ()
{
  return this->door_;
}

void RPG_Map_State_XMLTree_Type::
door (const door_sequence& s)
{
  this->door_ = s;
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

// RPG_Map_Door_XMLTree_Type
//

RPG_Map_Door_XMLTree_Type::
RPG_Map_Door_XMLTree_Type (const position_type& position,
                           const state_type& state)
: ::xml_schema::type (),
  position_ (position, ::xml_schema::flags (), this),
  state_ (state, ::xml_schema::flags (), this)
{
}

RPG_Map_Door_XMLTree_Type::
RPG_Map_Door_XMLTree_Type (::std::auto_ptr< position_type >& position,
                           const state_type& state)
: ::xml_schema::type (),
  position_ (position, ::xml_schema::flags (), this),
  state_ (state, ::xml_schema::flags (), this)
{
}

RPG_Map_Door_XMLTree_Type::
RPG_Map_Door_XMLTree_Type (const RPG_Map_Door_XMLTree_Type& x,
                           ::xml_schema::flags f,
                           ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  position_ (x.position_, f, this),
  state_ (x.state_, f, this)
{
}

RPG_Map_Door_XMLTree_Type::
RPG_Map_Door_XMLTree_Type (const ::xercesc::DOMElement& e,
                           ::xml_schema::flags f,
                           ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  position_ (f, this),
  state_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void RPG_Map_Door_XMLTree_Type::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // position
    //
    if (n.name () == "position" && n.namespace_ () == "urn:rpg")
    {
      ::std::auto_ptr< position_type > r (
        position_traits::create (i, f, this));

      if (!position_.present ())
      {
        this->position_.set (r);
        continue;
      }
    }

    // state
    //
    if (n.name () == "state" && n.namespace_ () == "urn:rpg")
    {
      ::std::auto_ptr< state_type > r (
        state_traits::create (i, f, this));

      if (!state_.present ())
      {
        this->state_.set (r);
        continue;
      }
    }

    break;
  }

  if (!position_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "position",
      "urn:rpg");
  }

  if (!state_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "state",
      "urn:rpg");
  }
}

RPG_Map_Door_XMLTree_Type* RPG_Map_Door_XMLTree_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Map_Door_XMLTree_Type (*this, f, c);
}

RPG_Map_Door_XMLTree_Type::
~RPG_Map_Door_XMLTree_Type ()
{
}

bool
operator== (const RPG_Map_Door_XMLTree_Type& x, const RPG_Map_Door_XMLTree_Type& y)
{
  if (!(x.position () == y.position ()))
    return false;

  if (!(x.state () == y.state ()))
    return false;

  return true;
}

bool
operator!= (const RPG_Map_Door_XMLTree_Type& x, const RPG_Map_Door_XMLTree_Type& y)
{
  return !(x == y);
}

// RPG_Map_Level_XMLTree_Type
//

RPG_Map_Level_XMLTree_Type::
RPG_Map_Level_XMLTree_Type (const name_type& name,
                            const environment_type& environment,
                            const map_type& map)
: ::xml_schema::type (),
  name_ (name, ::xml_schema::flags (), this),
  environment_ (environment, ::xml_schema::flags (), this),
  map_ (map, ::xml_schema::flags (), this)
{
}

RPG_Map_Level_XMLTree_Type::
RPG_Map_Level_XMLTree_Type (const name_type& name,
                            ::std::auto_ptr< environment_type >& environment,
                            const map_type& map)
: ::xml_schema::type (),
  name_ (name, ::xml_schema::flags (), this),
  environment_ (environment, ::xml_schema::flags (), this),
  map_ (map, ::xml_schema::flags (), this)
{
}

RPG_Map_Level_XMLTree_Type::
RPG_Map_Level_XMLTree_Type (const RPG_Map_Level_XMLTree_Type& x,
                            ::xml_schema::flags f,
                            ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  name_ (x.name_, f, this),
  environment_ (x.environment_, f, this),
  map_ (x.map_, f, this)
{
}

RPG_Map_Level_XMLTree_Type::
RPG_Map_Level_XMLTree_Type (const ::xercesc::DOMElement& e,
                            ::xml_schema::flags f,
                            ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  name_ (f, this),
  environment_ (f, this),
  map_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void RPG_Map_Level_XMLTree_Type::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // name
    //
    if (n.name () == "name" && n.namespace_ () == "urn:rpg")
    {
      ::std::auto_ptr< name_type > r (
        name_traits::create (i, f, this));

      if (!name_.present ())
      {
        this->name_.set (r);
        continue;
      }
    }

    // environment
    //
    if (n.name () == "environment" && n.namespace_ () == "urn:rpg")
    {
      ::std::auto_ptr< environment_type > r (
        environment_traits::create (i, f, this));

      if (!environment_.present ())
      {
        this->environment_.set (r);
        continue;
      }
    }

    // map
    //
    if (n.name () == "map" && n.namespace_ () == "urn:rpg")
    {
      ::std::auto_ptr< map_type > r (
        map_traits::create (i, f, this));

      if (!map_.present ())
      {
        this->map_.set (r);
        continue;
      }
    }

    break;
  }

  if (!name_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "name",
      "urn:rpg");
  }

  if (!environment_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "environment",
      "urn:rpg");
  }

  if (!map_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "map",
      "urn:rpg");
  }
}

RPG_Map_Level_XMLTree_Type* RPG_Map_Level_XMLTree_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Map_Level_XMLTree_Type (*this, f, c);
}

RPG_Map_Level_XMLTree_Type::
~RPG_Map_Level_XMLTree_Type ()
{
}

bool
operator== (const RPG_Map_Level_XMLTree_Type& x, const RPG_Map_Level_XMLTree_Type& y)
{
  if (!(x.name () == y.name ()))
    return false;

  if (!(x.environment () == y.environment ()))
    return false;

  if (!(x.map () == y.map ()))
    return false;

  return true;
}

bool
operator!= (const RPG_Map_Level_XMLTree_Type& x, const RPG_Map_Level_XMLTree_Type& y)
{
  return !(x == y);
}

// RPG_Map_State_XMLTree_Type
//

RPG_Map_State_XMLTree_Type::
RPG_Map_State_XMLTree_Type (const file_type& file)
: ::xml_schema::type (),
  file_ (file, ::xml_schema::flags (), this),
  door_ (::xml_schema::flags (), this)
{
}

RPG_Map_State_XMLTree_Type::
RPG_Map_State_XMLTree_Type (const RPG_Map_State_XMLTree_Type& x,
                            ::xml_schema::flags f,
                            ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  file_ (x.file_, f, this),
  door_ (x.door_, f, this)
{
}

RPG_Map_State_XMLTree_Type::
RPG_Map_State_XMLTree_Type (const ::xercesc::DOMElement& e,
                            ::xml_schema::flags f,
                            ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  file_ (f, this),
  door_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void RPG_Map_State_XMLTree_Type::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // file
    //
    if (n.name () == "file" && n.namespace_ () == "urn:rpg")
    {
      ::std::auto_ptr< file_type > r (
        file_traits::create (i, f, this));

      if (!file_.present ())
      {
        this->file_.set (r);
        continue;
      }
    }

    // door
    //
    if (n.name () == "door" && n.namespace_ () == "urn:rpg")
    {
      ::std::auto_ptr< door_type > r (
        door_traits::create (i, f, this));

      this->door_.push_back (r);
      continue;
    }

    break;
  }

  if (!file_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "file",
      "urn:rpg");
  }
}

RPG_Map_State_XMLTree_Type* RPG_Map_State_XMLTree_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Map_State_XMLTree_Type (*this, f, c);
}

RPG_Map_State_XMLTree_Type::
~RPG_Map_State_XMLTree_Type ()
{
}

bool
operator== (const RPG_Map_State_XMLTree_Type& x, const RPG_Map_State_XMLTree_Type& y)
{
  if (!(x.file () == y.file ()))
    return false;

  if (!(x.door () == y.door ()))
    return false;

  return true;
}

bool
operator!= (const RPG_Map_State_XMLTree_Type& x, const RPG_Map_State_XMLTree_Type& y)
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

::std::ostream&
operator<< (::std::ostream& o, const RPG_Map_Door_XMLTree_Type& i)
{
  o << ::std::endl << "position: " << i.position ();
  o << ::std::endl << "state: " << i.state ();
  return o;
}

::std::ostream&
operator<< (::std::ostream& o, const RPG_Map_Level_XMLTree_Type& i)
{
  o << ::std::endl << "name: " << i.name ();
  o << ::std::endl << "environment: " << i.environment ();
  o << ::std::endl << "map: " << i.map ();
  return o;
}

::std::ostream&
operator<< (::std::ostream& o, const RPG_Map_State_XMLTree_Type& i)
{
  o << ::std::endl << "file: " << i.file ();
  for (RPG_Map_State_XMLTree_Type::door_const_iterator
       b (i.door ().begin ()), e (i.door ().end ());
       b != e; ++b)
  {
    o << ::std::endl << "door: " << *b;
  }

  return o;
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (const ::std::string& u,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::tree::error_handler< char > h;

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

  ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
    ::map_t (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (const ::std::string& u,
       ::xml_schema::error_handler& h,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
    ::map_t (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (const ::std::string& u,
       ::xercesc::DOMErrorHandler& h,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
    ::map_t (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::std::istream& is,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::map_t (isrc, f, p);
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::std::istream& is,
       ::xml_schema::error_handler& h,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::map_t (isrc, h, f, p);
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::std::istream& is,
       ::xercesc::DOMErrorHandler& h,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::map_t (isrc, h, f, p);
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::std::istream& is,
       const ::std::string& sid,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::map_t (isrc, f, p);
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::std::istream& is,
       const ::std::string& sid,
       ::xml_schema::error_handler& h,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::map_t (isrc, h, f, p);
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::std::istream& is,
       const ::std::string& sid,
       ::xercesc::DOMErrorHandler& h,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::map_t (isrc, h, f, p);
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::xercesc::InputSource& i,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xsd::cxx::tree::error_handler< char > h;

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

  ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
    ::map_t (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::xercesc::InputSource& i,
       ::xml_schema::error_handler& h,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
    ::map_t (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::xercesc::InputSource& i,
       ::xercesc::DOMErrorHandler& h,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
    ::map_t (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (const ::xercesc::DOMDocument& d,
       ::xml_schema::flags f,
       const ::xml_schema::properties& p)
{
  if (f & ::xml_schema::flags::keep_dom)
  {
    ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > c (
      static_cast< ::xercesc::DOMDocument* > (d.cloneNode (true)));

    ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
      ::map_t (
        c, f | ::xml_schema::flags::own_dom, p));

    return r;
  }

  const ::xercesc::DOMElement& e (*d.getDocumentElement ());
  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (n.name () == "map_t" &&
      n.namespace_ () == "urn:rpg")
  {
    ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
      ::xsd::cxx::tree::traits< ::RPG_Map_Level_XMLTree_Type, char >::create (
        e, f, 0));
    return r;
  }

  throw ::xsd::cxx::tree::unexpected_element < char > (
    n.name (),
    n.namespace_ (),
    "map_t",
    "urn:rpg");
}

::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type >
map_t (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
       ::xml_schema::flags f,
       const ::xml_schema::properties&)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > c (
    ((f & ::xml_schema::flags::keep_dom) &&
     !(f & ::xml_schema::flags::own_dom))
    ? static_cast< ::xercesc::DOMDocument* > (d->cloneNode (true))
    : 0);

  ::xercesc::DOMDocument& doc (c.get () ? *c : *d);
  const ::xercesc::DOMElement& e (*doc.getDocumentElement ());

  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (f & ::xml_schema::flags::keep_dom)
    doc.setUserData (::xml_schema::dom::tree_node_key,
                     (c.get () ? &c : &d),
                     0);

  if (n.name () == "map_t" &&
      n.namespace_ () == "urn:rpg")
  {
    ::std::auto_ptr< ::RPG_Map_Level_XMLTree_Type > r (
      ::xsd::cxx::tree::traits< ::RPG_Map_Level_XMLTree_Type, char >::create (
        e, f, 0));
    return r;
  }

  throw ::xsd::cxx::tree::unexpected_element < char > (
    n.name (),
    n.namespace_ (),
    "map_t",
    "urn:rpg");
}

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

void
operator<< (::xercesc::DOMElement& e, const RPG_Map_Door_XMLTree_Type& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // position
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "position",
        "urn:rpg",
        e));

    s << i.position ();
  }

  // state
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "state",
        "urn:rpg",
        e));

    s << i.state ();
  }
}

void
operator<< (::xercesc::DOMElement& e, const RPG_Map_Level_XMLTree_Type& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // name
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "name",
        "urn:rpg",
        e));

    s << i.name ();
  }

  // environment
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "environment",
        "urn:rpg",
        e));

    s << i.environment ();
  }

  // map
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "map",
        "urn:rpg",
        e));

    s << i.map ();
  }
}

void
operator<< (::xercesc::DOMElement& e, const RPG_Map_State_XMLTree_Type& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // file
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "file",
        "urn:rpg",
        e));

    s << i.file ();
  }

  // door
  //
  for (RPG_Map_State_XMLTree_Type::door_const_iterator
       b (i.door ().begin ()), n (i.door ().end ());
       b != n; ++b)
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "door",
        "urn:rpg",
        e));

    s << *b;
  }
}

void
map_t (::std::ostream& o,
       const ::RPG_Map_Level_XMLTree_Type& s,
       const ::xml_schema::namespace_infomap& m,
       const ::std::string& e,
       ::xml_schema::flags f)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0);

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::map_t (s, m, f));

  ::xsd::cxx::tree::error_handler< char > h;

  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
  }
}

void
map_t (::std::ostream& o,
       const ::RPG_Map_Level_XMLTree_Type& s,
       ::xml_schema::error_handler& h,
       const ::xml_schema::namespace_infomap& m,
       const ::std::string& e,
       ::xml_schema::flags f)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0);

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::map_t (s, m, f));
  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
map_t (::std::ostream& o,
       const ::RPG_Map_Level_XMLTree_Type& s,
       ::xercesc::DOMErrorHandler& h,
       const ::xml_schema::namespace_infomap& m,
       const ::std::string& e,
       ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::map_t (s, m, f));
  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
map_t (::xercesc::XMLFormatTarget& t,
       const ::RPG_Map_Level_XMLTree_Type& s,
       const ::xml_schema::namespace_infomap& m,
       const ::std::string& e,
       ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::map_t (s, m, f));

  ::xsd::cxx::tree::error_handler< char > h;

  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
  }
}

void
map_t (::xercesc::XMLFormatTarget& t,
       const ::RPG_Map_Level_XMLTree_Type& s,
       ::xml_schema::error_handler& h,
       const ::xml_schema::namespace_infomap& m,
       const ::std::string& e,
       ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::map_t (s, m, f));
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
map_t (::xercesc::XMLFormatTarget& t,
       const ::RPG_Map_Level_XMLTree_Type& s,
       ::xercesc::DOMErrorHandler& h,
       const ::xml_schema::namespace_infomap& m,
       const ::std::string& e,
       ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::map_t (s, m, f));
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
map_t (::xercesc::DOMDocument& d,
       const ::RPG_Map_Level_XMLTree_Type& s,
       ::xml_schema::flags)
{
  ::xercesc::DOMElement& e (*d.getDocumentElement ());
  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (n.name () == "map_t" &&
      n.namespace_ () == "urn:rpg")
  {
    e << s;
  }
  else
  {
    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "map_t",
      "urn:rpg");
  }
}

::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
map_t (const ::RPG_Map_Level_XMLTree_Type& s,
       const ::xml_schema::namespace_infomap& m,
       ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::serialize< char > (
      "map_t",
      "urn:rpg",
      m, f));

  ::map_t (*d, s, f);
  return d;
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

