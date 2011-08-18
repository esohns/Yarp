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

#include "rpg_engine_XML_tree.h"

// RPG_Engine_Command_XMLTree_Type
// 

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (value v)
: ::xml_schema::string (_xsd_RPG_Engine_Command_XMLTree_Type_literals_[v])
{
}

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (const char* v)
: ::xml_schema::string (v)
{
}

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (const ::std::string& v)
: ::xml_schema::string (v)
{
}

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (const ::xml_schema::string& v)
: ::xml_schema::string (v)
{
}

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (const RPG_Engine_Command_XMLTree_Type& v,
                                 ::xml_schema::flags f,
                                 ::xml_schema::container* c)
: ::xml_schema::string (v, f, c)
{
}

RPG_Engine_Command_XMLTree_Type& RPG_Engine_Command_XMLTree_Type::
operator= (value v)
{
  static_cast< ::xml_schema::string& > (*this) = 
  ::xml_schema::string (_xsd_RPG_Engine_Command_XMLTree_Type_literals_[v]);

  return *this;
}


// RPG_Engine_Player_XMLTree_Type
// 

const RPG_Engine_Player_XMLTree_Type::position_type& RPG_Engine_Player_XMLTree_Type::
position () const
{
  return this->position_.get ();
}

RPG_Engine_Player_XMLTree_Type::position_type& RPG_Engine_Player_XMLTree_Type::
position ()
{
  return this->position_.get ();
}

void RPG_Engine_Player_XMLTree_Type::
position (const position_type& x)
{
  this->position_.set (x);
}

void RPG_Engine_Player_XMLTree_Type::
position (::std::auto_ptr< position_type > x)
{
  this->position_.set (x);
}

const RPG_Engine_Player_XMLTree_Type::sprite_type& RPG_Engine_Player_XMLTree_Type::
sprite () const
{
  return this->sprite_.get ();
}

RPG_Engine_Player_XMLTree_Type::sprite_type& RPG_Engine_Player_XMLTree_Type::
sprite ()
{
  return this->sprite_.get ();
}

void RPG_Engine_Player_XMLTree_Type::
sprite (const sprite_type& x)
{
  this->sprite_.set (x);
}

void RPG_Engine_Player_XMLTree_Type::
sprite (::std::auto_ptr< sprite_type > x)
{
  this->sprite_.set (x);
}


#include <xsd/cxx/xml/dom/parsing-source.hxx>

// RPG_Engine_Command_XMLTree_Type
//

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (const ::xercesc::DOMElement& e,
                                 ::xml_schema::flags f,
                                 ::xml_schema::container* c)
: ::xml_schema::string (e, f, c)
{
  _xsd_RPG_Engine_Command_XMLTree_Type_convert ();
}

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                 ::xml_schema::flags f,
                                 ::xml_schema::container* c)
: ::xml_schema::string (a, f, c)
{
  _xsd_RPG_Engine_Command_XMLTree_Type_convert ();
}

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (const ::std::string& s,
                                 const ::xercesc::DOMElement* e,
                                 ::xml_schema::flags f,
                                 ::xml_schema::container* c)
: ::xml_schema::string (s, e, f, c)
{
  _xsd_RPG_Engine_Command_XMLTree_Type_convert ();
}

RPG_Engine_Command_XMLTree_Type* RPG_Engine_Command_XMLTree_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Engine_Command_XMLTree_Type (*this, f, c);
}

RPG_Engine_Command_XMLTree_Type::value RPG_Engine_Command_XMLTree_Type::
_xsd_RPG_Engine_Command_XMLTree_Type_convert () const
{
  ::xsd::cxx::tree::enum_comparator< char > c (_xsd_RPG_Engine_Command_XMLTree_Type_literals_);
  const value* i (::std::lower_bound (
                    _xsd_RPG_Engine_Command_XMLTree_Type_indexes_,
                    _xsd_RPG_Engine_Command_XMLTree_Type_indexes_ + 6,
                    *this,
                    c));

  if (i == _xsd_RPG_Engine_Command_XMLTree_Type_indexes_ + 6 || _xsd_RPG_Engine_Command_XMLTree_Type_literals_[*i] != *this)
  {
    throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
  }

  return *i;
}

const char* const RPG_Engine_Command_XMLTree_Type::
_xsd_RPG_Engine_Command_XMLTree_Type_literals_[6] =
{
  "COMMAND_ATTACK",
  "COMMAND_DOOR_CLOSE",
  "COMMAND_DOOR_OPEN",
  "COMMAND_STEP",
  "COMMAND_STOP",
  "COMMAND_TRAVEL"
};

const RPG_Engine_Command_XMLTree_Type::value RPG_Engine_Command_XMLTree_Type::
_xsd_RPG_Engine_Command_XMLTree_Type_indexes_[6] =
{
  ::RPG_Engine_Command_XMLTree_Type::COMMAND_ATTACK,
  ::RPG_Engine_Command_XMLTree_Type::COMMAND_DOOR_CLOSE,
  ::RPG_Engine_Command_XMLTree_Type::COMMAND_DOOR_OPEN,
  ::RPG_Engine_Command_XMLTree_Type::COMMAND_STEP,
  ::RPG_Engine_Command_XMLTree_Type::COMMAND_STOP,
  ::RPG_Engine_Command_XMLTree_Type::COMMAND_TRAVEL
};

// RPG_Engine_Player_XMLTree_Type
//

RPG_Engine_Player_XMLTree_Type::
RPG_Engine_Player_XMLTree_Type (const name_type& name,
                                const alignment_type& alignment,
                                const attributes_type& attributes,
                                const defaultSize_type& defaultSize,
                                const maxHP_type& maxHP,
                                const conditions_type& conditions,
                                const HP_type& HP,
                                const XP_type& XP,
                                const gold_type& gold,
                                const inventory_type& inventory,
                                const gender_type& gender,
                                const classXML_type& classXML,
                                const offhand_type& offhand,
                                const position_type& position,
                                const sprite_type& sprite)
: ::RPG_Character_PlayerXML_XMLTree_Type (name,
                                          alignment,
                                          attributes,
                                          defaultSize,
                                          maxHP,
                                          conditions,
                                          HP,
                                          XP,
                                          gold,
                                          inventory,
                                          gender,
                                          classXML,
                                          offhand),
  position_ (position, ::xml_schema::flags (), this),
  sprite_ (sprite, ::xml_schema::flags (), this)
{
}

RPG_Engine_Player_XMLTree_Type::
RPG_Engine_Player_XMLTree_Type (const name_type& name,
                                ::std::auto_ptr< alignment_type >& alignment,
                                ::std::auto_ptr< attributes_type >& attributes,
                                const defaultSize_type& defaultSize,
                                const maxHP_type& maxHP,
                                ::std::auto_ptr< conditions_type >& conditions,
                                const HP_type& HP,
                                const XP_type& XP,
                                const gold_type& gold,
                                ::std::auto_ptr< inventory_type >& inventory,
                                const gender_type& gender,
                                ::std::auto_ptr< classXML_type >& classXML,
                                const offhand_type& offhand,
                                ::std::auto_ptr< position_type >& position,
                                const sprite_type& sprite)
: ::RPG_Character_PlayerXML_XMLTree_Type (name,
                                          alignment,
                                          attributes,
                                          defaultSize,
                                          maxHP,
                                          conditions,
                                          HP,
                                          XP,
                                          gold,
                                          inventory,
                                          gender,
                                          classXML,
                                          offhand),
  position_ (position, ::xml_schema::flags (), this),
  sprite_ (sprite, ::xml_schema::flags (), this)
{
}

RPG_Engine_Player_XMLTree_Type::
RPG_Engine_Player_XMLTree_Type (const RPG_Engine_Player_XMLTree_Type& x,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
: ::RPG_Character_PlayerXML_XMLTree_Type (x, f, c),
  position_ (x.position_, f, this),
  sprite_ (x.sprite_, f, this)
{
}

RPG_Engine_Player_XMLTree_Type::
RPG_Engine_Player_XMLTree_Type (const ::xercesc::DOMElement& e,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
: ::RPG_Character_PlayerXML_XMLTree_Type (e, f | ::xml_schema::flags::base, c),
  position_ (f, this),
  sprite_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void RPG_Engine_Player_XMLTree_Type::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  this->::RPG_Character_PlayerXML_XMLTree_Type::parse (p, f);

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

    // sprite
    //
    if (n.name () == "sprite" && n.namespace_ () == "urn:rpg")
    {
      ::std::auto_ptr< sprite_type > r (
        sprite_traits::create (i, f, this));

      if (!sprite_.present ())
      {
        this->sprite_.set (r);
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

  if (!sprite_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "sprite",
      "urn:rpg");
  }
}

RPG_Engine_Player_XMLTree_Type* RPG_Engine_Player_XMLTree_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Engine_Player_XMLTree_Type (*this, f, c);
}

RPG_Engine_Player_XMLTree_Type::
~RPG_Engine_Player_XMLTree_Type ()
{
}

bool
operator== (const RPG_Engine_Player_XMLTree_Type& x, const RPG_Engine_Player_XMLTree_Type& y)
{
  if (!(static_cast< const ::RPG_Character_PlayerXML_XMLTree_Type& > (x) ==
        static_cast< const ::RPG_Character_PlayerXML_XMLTree_Type& > (y)))
    return false;

  if (!(x.position () == y.position ()))
    return false;

  if (!(x.sprite () == y.sprite ()))
    return false;

  return true;
}

bool
operator!= (const RPG_Engine_Player_XMLTree_Type& x, const RPG_Engine_Player_XMLTree_Type& y)
{
  return !(x == y);
}

#include <ostream>

::std::ostream&
operator<< (::std::ostream& o, RPG_Engine_Command_XMLTree_Type::value i)
{
  return o << RPG_Engine_Command_XMLTree_Type::_xsd_RPG_Engine_Command_XMLTree_Type_literals_[i];
}

::std::ostream&
operator<< (::std::ostream& o, const RPG_Engine_Command_XMLTree_Type& i)
{
  return o << static_cast< const ::xml_schema::string& > (i);
}

::std::ostream&
operator<< (::std::ostream& o, const RPG_Engine_Player_XMLTree_Type& i)
{
  o << static_cast< const ::RPG_Character_PlayerXML_XMLTree_Type& > (i);

  o << ::std::endl << "position: " << i.position ();
  o << ::std::endl << "sprite: " << i.sprite ();
  return o;
}

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (const ::std::string& u,
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

  ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
    ::engine_player (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (const ::std::string& u,
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

  ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
    ::engine_player (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (const ::std::string& u,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      u, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
    ::engine_player (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::engine_player (isrc, f, p);
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               ::xml_schema::error_handler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::engine_player (isrc, h, f, p);
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::sax::std_input_source isrc (is);
  return ::engine_player (isrc, h, f, p);
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               const ::std::string& sid,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::engine_player (isrc, f, p);
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               const ::std::string& sid,
               ::xml_schema::error_handler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0,
    (f & ::xml_schema::flags::keep_dom) == 0);

  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::engine_player (isrc, h, f, p);
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               const ::std::string& sid,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xsd::cxx::xml::sax::std_input_source isrc (is, sid);
  return ::engine_player (isrc, h, f, p);
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::xercesc::InputSource& i,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xsd::cxx::tree::error_handler< char > h;

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  h.throw_if_failed< ::xsd::cxx::tree::parsing< char > > ();

  ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
    ::engine_player (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::xercesc::InputSource& i,
               ::xml_schema::error_handler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
    ::engine_player (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::xercesc::InputSource& i,
               ::xercesc::DOMErrorHandler& h,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::parse< char > (
      i, h, p, f));

  if (!d.get ())
    throw ::xsd::cxx::tree::parsing< char > ();

  ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
    ::engine_player (
      d, f | ::xml_schema::flags::own_dom, p));

  return r;
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (const ::xercesc::DOMDocument& d,
               ::xml_schema::flags f,
               const ::xml_schema::properties& p)
{
  if (f & ::xml_schema::flags::keep_dom)
  {
    ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > c (
      static_cast< ::xercesc::DOMDocument* > (d.cloneNode (true)));

    ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
      ::engine_player (
        c, f | ::xml_schema::flags::own_dom, p));

    return r;
  }

  const ::xercesc::DOMElement& e (*d.getDocumentElement ());
  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (n.name () == "engine_player" &&
      n.namespace_ () == "urn:rpg")
  {
    ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
      ::xsd::cxx::tree::traits< ::RPG_Engine_Player_XMLTree_Type, char >::create (
        e, f, 0));
    return r;
  }

  throw ::xsd::cxx::tree::unexpected_element < char > (
    n.name (),
    n.namespace_ (),
    "engine_player",
    "urn:rpg");
}

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
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

  if (n.name () == "engine_player" &&
      n.namespace_ () == "urn:rpg")
  {
    ::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type > r (
      ::xsd::cxx::tree::traits< ::RPG_Engine_Player_XMLTree_Type, char >::create (
        e, f, 0));
    return r;
  }

  throw ::xsd::cxx::tree::unexpected_element < char > (
    n.name (),
    n.namespace_ (),
    "engine_player",
    "urn:rpg");
}

#include <ostream>
#include <xsd/cxx/tree/error-handler.hxx>
#include <xsd/cxx/xml/dom/serialization-source.hxx>

void
operator<< (::xercesc::DOMElement& e, const RPG_Engine_Command_XMLTree_Type& i)
{
  e << static_cast< const ::xml_schema::string& > (i);
}

void
operator<< (::xercesc::DOMAttr& a, const RPG_Engine_Command_XMLTree_Type& i)
{
  a << static_cast< const ::xml_schema::string& > (i);
}

void
operator<< (::xml_schema::list_stream& l,
            const RPG_Engine_Command_XMLTree_Type& i)
{
  l << static_cast< const ::xml_schema::string& > (i);
}

void
operator<< (::xercesc::DOMElement& e, const RPG_Engine_Player_XMLTree_Type& i)
{
  e << static_cast< const ::RPG_Character_PlayerXML_XMLTree_Type& > (i);

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

  // sprite
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "sprite",
        "urn:rpg",
        e));

    s << i.sprite ();
  }
}

void
engine_player (::std::ostream& o,
               const ::RPG_Engine_Player_XMLTree_Type& s,
               const ::xml_schema::namespace_infomap& m,
               const ::std::string& e,
               ::xml_schema::flags f)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0);

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::engine_player (s, m, f));

  ::xsd::cxx::tree::error_handler< char > h;

  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
  }
}

void
engine_player (::std::ostream& o,
               const ::RPG_Engine_Player_XMLTree_Type& s,
               ::xml_schema::error_handler& h,
               const ::xml_schema::namespace_infomap& m,
               const ::std::string& e,
               ::xml_schema::flags f)
{
  ::xsd::cxx::xml::auto_initializer i (
    (f & ::xml_schema::flags::dont_initialize) == 0);

  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::engine_player (s, m, f));
  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
engine_player (::std::ostream& o,
               const ::RPG_Engine_Player_XMLTree_Type& s,
               ::xercesc::DOMErrorHandler& h,
               const ::xml_schema::namespace_infomap& m,
               const ::std::string& e,
               ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::engine_player (s, m, f));
  ::xsd::cxx::xml::dom::ostream_format_target t (o);
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
engine_player (::xercesc::XMLFormatTarget& t,
               const ::RPG_Engine_Player_XMLTree_Type& s,
               const ::xml_schema::namespace_infomap& m,
               const ::std::string& e,
               ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::engine_player (s, m, f));

  ::xsd::cxx::tree::error_handler< char > h;

  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    h.throw_if_failed< ::xsd::cxx::tree::serialization< char > > ();
  }
}

void
engine_player (::xercesc::XMLFormatTarget& t,
               const ::RPG_Engine_Player_XMLTree_Type& s,
               ::xml_schema::error_handler& h,
               const ::xml_schema::namespace_infomap& m,
               const ::std::string& e,
               ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::engine_player (s, m, f));
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
engine_player (::xercesc::XMLFormatTarget& t,
               const ::RPG_Engine_Player_XMLTree_Type& s,
               ::xercesc::DOMErrorHandler& h,
               const ::xml_schema::namespace_infomap& m,
               const ::std::string& e,
               ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::engine_player (s, m, f));
  if (!::xsd::cxx::xml::dom::serialize (t, *d, e, h, f))
  {
    throw ::xsd::cxx::tree::serialization< char > ();
  }
}

void
engine_player (::xercesc::DOMDocument& d,
               const ::RPG_Engine_Player_XMLTree_Type& s,
               ::xml_schema::flags)
{
  ::xercesc::DOMElement& e (*d.getDocumentElement ());
  const ::xsd::cxx::xml::qualified_name< char > n (
    ::xsd::cxx::xml::dom::name< char > (e));

  if (n.name () == "engine_player" &&
      n.namespace_ () == "urn:rpg")
  {
    e << s;
  }
  else
  {
    throw ::xsd::cxx::tree::unexpected_element < char > (
      n.name (),
      n.namespace_ (),
      "engine_player",
      "urn:rpg");
  }
}

::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
engine_player (const ::RPG_Engine_Player_XMLTree_Type& s,
               const ::xml_schema::namespace_infomap& m,
               ::xml_schema::flags f)
{
  ::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument > d (
    ::xsd::cxx::xml::dom::serialize< char > (
      "engine_player",
      "urn:rpg",
      m, f));

  ::engine_player (*d, s, f);
  return d;
}

RPG_Engine_Command_XMLTree_Type::
RPG_Engine_Command_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                 ::xml_schema::flags f,
                                 ::xml_schema::container* c)
: ::xml_schema::string (s, f, c)
{
  _xsd_RPG_Engine_Command_XMLTree_Type_convert ();
}

RPG_Engine_Player_XMLTree_Type::
RPG_Engine_Player_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                ::xml_schema::flags f,
                                ::xml_schema::container* c)
: ::RPG_Character_PlayerXML_XMLTree_Type (s, f, c),
  position_ (f, this),
  sprite_ (f, this)
{
  this->parse (s, f);
}

void RPG_Engine_Player_XMLTree_Type::
parse (::xml_schema::istream< ACE_InputCDR >& s,
       ::xml_schema::flags f)
{
  {
    ::std::auto_ptr< position_type > r (new position_type (s, f, this));
    this->position_.set (r);
  }

  {
    ::std::auto_ptr< sprite_type > r (new sprite_type (s, f, this));
    this->sprite_.set (r);
  }
}

::xsd::cxx::tree::ostream< ACE_OutputCDR >&
operator<< (::xsd::cxx::tree::ostream< ACE_OutputCDR >& s,
            const RPG_Engine_Command_XMLTree_Type& x)
{
  return s << static_cast< const ::xml_schema::string& > (x);
}

::xsd::cxx::tree::ostream< ACE_OutputCDR >&
operator<< (::xsd::cxx::tree::ostream< ACE_OutputCDR >& s,
            const RPG_Engine_Player_XMLTree_Type& x)
{
  s << static_cast< const ::RPG_Character_PlayerXML_XMLTree_Type& > (x);
  s << x.position ();
  s << x.sprite ();
  return s;
}

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

