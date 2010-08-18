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

#include <xsd/cxx/pre.hxx>

#include "rpg_dice_XML_tree.h"

// RPG_Dice_DieType_Type
// 

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (value v)
: ::xml_schema::string (_xsd_RPG_Dice_DieType_Type_literals_[v])
{
}

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (const char* v)
: ::xml_schema::string (v)
{
}

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (const ::std::string& v)
: ::xml_schema::string (v)
{
}

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (const ::xml_schema::string& v)
: ::xml_schema::string (v)
{
}

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (const RPG_Dice_DieType_Type& v,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
: ::xml_schema::string (v, f, c)
{
}

RPG_Dice_DieType_Type& RPG_Dice_DieType_Type::
operator= (value v)
{
  static_cast< ::xml_schema::string& > (*this) = 
  ::xml_schema::string (_xsd_RPG_Dice_DieType_Type_literals_[v]);

  return *this;
}


// RPG_Dice_Roll_Type
// 

const RPG_Dice_Roll_Type::numDice_type& RPG_Dice_Roll_Type::
numDice () const
{
  return this->numDice_.get ();
}

RPG_Dice_Roll_Type::numDice_type& RPG_Dice_Roll_Type::
numDice ()
{
  return this->numDice_.get ();
}

void RPG_Dice_Roll_Type::
numDice (const numDice_type& x)
{
  this->numDice_.set (x);
}

const RPG_Dice_Roll_Type::typeDice_type& RPG_Dice_Roll_Type::
typeDice () const
{
  return this->typeDice_.get ();
}

RPG_Dice_Roll_Type::typeDice_type& RPG_Dice_Roll_Type::
typeDice ()
{
  return this->typeDice_.get ();
}

void RPG_Dice_Roll_Type::
typeDice (const typeDice_type& x)
{
  this->typeDice_.set (x);
}

void RPG_Dice_Roll_Type::
typeDice (::std::auto_ptr< typeDice_type > x)
{
  this->typeDice_.set (x);
}

const RPG_Dice_Roll_Type::modifier_type& RPG_Dice_Roll_Type::
modifier () const
{
  return this->modifier_.get ();
}

RPG_Dice_Roll_Type::modifier_type& RPG_Dice_Roll_Type::
modifier ()
{
  return this->modifier_.get ();
}

void RPG_Dice_Roll_Type::
modifier (const modifier_type& x)
{
  this->modifier_.set (x);
}


// RPG_Dice_ValueRange_Type
// 

const RPG_Dice_ValueRange_Type::begin_type& RPG_Dice_ValueRange_Type::
begin () const
{
  return this->begin_.get ();
}

RPG_Dice_ValueRange_Type::begin_type& RPG_Dice_ValueRange_Type::
begin ()
{
  return this->begin_.get ();
}

void RPG_Dice_ValueRange_Type::
begin (const begin_type& x)
{
  this->begin_.set (x);
}

const RPG_Dice_ValueRange_Type::end_type& RPG_Dice_ValueRange_Type::
end () const
{
  return this->end_.get ();
}

RPG_Dice_ValueRange_Type::end_type& RPG_Dice_ValueRange_Type::
end ()
{
  return this->end_.get ();
}

void RPG_Dice_ValueRange_Type::
end (const end_type& x)
{
  this->end_.set (x);
}


#include <xsd/cxx/xml/dom/parsing-source.hxx>

#include <xsd/cxx/tree/type-factory-map.hxx>

#include <xsd/cxx/tree/comparison-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_factory_plate< 0, char >
  type_factory_plate_init;

  static
  const ::xsd::cxx::tree::comparison_plate< 0, char >
  comparison_plate_init;
}

// RPG_Dice_DieType_Type
//

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (const ::xercesc::DOMElement& e,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
: ::xml_schema::string (e, f, c)
{
  _xsd_RPG_Dice_DieType_Type_convert ();
}

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (const ::xercesc::DOMAttr& a,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
: ::xml_schema::string (a, f, c)
{
  _xsd_RPG_Dice_DieType_Type_convert ();
}

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (const ::std::string& s,
                       const ::xercesc::DOMElement* e,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
: ::xml_schema::string (s, e, f, c)
{
  _xsd_RPG_Dice_DieType_Type_convert ();
}

RPG_Dice_DieType_Type* RPG_Dice_DieType_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Dice_DieType_Type (*this, f, c);
}

RPG_Dice_DieType_Type::value RPG_Dice_DieType_Type::
_xsd_RPG_Dice_DieType_Type_convert () const
{
  ::xsd::cxx::tree::enum_comparator< char > c (_xsd_RPG_Dice_DieType_Type_literals_);
  const value* i (::std::lower_bound (
                    _xsd_RPG_Dice_DieType_Type_indexes_,
                    _xsd_RPG_Dice_DieType_Type_indexes_ + 10,
                    *this,
                    c));

  if (i == _xsd_RPG_Dice_DieType_Type_indexes_ + 10 || _xsd_RPG_Dice_DieType_Type_literals_[*i] != *this)
  {
    throw ::xsd::cxx::tree::unexpected_enumerator < char > (*this);
  }

  return *i;
}

const char* const RPG_Dice_DieType_Type::
_xsd_RPG_Dice_DieType_Type_literals_[10] =
{
  "D_0",
  "D_2",
  "D_3",
  "D_4",
  "D_6",
  "D_8",
  "D_10",
  "D_12",
  "D_20",
  "D_100"
};

const RPG_Dice_DieType_Type::value RPG_Dice_DieType_Type::
_xsd_RPG_Dice_DieType_Type_indexes_[10] =
{
  ::RPG_Dice_DieType_Type::D_0,
  ::RPG_Dice_DieType_Type::D_10,
  ::RPG_Dice_DieType_Type::D_100,
  ::RPG_Dice_DieType_Type::D_12,
  ::RPG_Dice_DieType_Type::D_2,
  ::RPG_Dice_DieType_Type::D_20,
  ::RPG_Dice_DieType_Type::D_3,
  ::RPG_Dice_DieType_Type::D_4,
  ::RPG_Dice_DieType_Type::D_6,
  ::RPG_Dice_DieType_Type::D_8
};

static
const ::xsd::cxx::tree::type_factory_initializer< 0, char, RPG_Dice_DieType_Type >
_xsd_RPG_Dice_DieType_Type_type_factory_init (
  "RPG_Dice_DieType_Type",
  "urn:rpg");

static
const ::xsd::cxx::tree::comparison_initializer< 0, char, RPG_Dice_DieType_Type >
_xsd_RPG_Dice_DieType_Type_comparison_init;

// RPG_Dice_Roll_Type
//

RPG_Dice_Roll_Type::
RPG_Dice_Roll_Type (const numDice_type& numDice,
                    const typeDice_type& typeDice,
                    const modifier_type& modifier)
: ::xml_schema::type (),
  numDice_ (numDice, ::xml_schema::flags (), this),
  typeDice_ (typeDice, ::xml_schema::flags (), this),
  modifier_ (modifier, ::xml_schema::flags (), this)
{
}

RPG_Dice_Roll_Type::
RPG_Dice_Roll_Type (const numDice_type& numDice,
                    ::std::auto_ptr< typeDice_type >& typeDice,
                    const modifier_type& modifier)
: ::xml_schema::type (),
  numDice_ (numDice, ::xml_schema::flags (), this),
  typeDice_ (typeDice, ::xml_schema::flags (), this),
  modifier_ (modifier, ::xml_schema::flags (), this)
{
}

RPG_Dice_Roll_Type::
RPG_Dice_Roll_Type (const RPG_Dice_Roll_Type& x,
                    ::xml_schema::flags f,
                    ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  numDice_ (x.numDice_, f, this),
  typeDice_ (x.typeDice_, f, this),
  modifier_ (x.modifier_, f, this)
{
}

RPG_Dice_Roll_Type::
RPG_Dice_Roll_Type (const ::xercesc::DOMElement& e,
                    ::xml_schema::flags f,
                    ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  numDice_ (f, this),
  typeDice_ (f, this),
  modifier_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void RPG_Dice_Roll_Type::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // numDice
    //
    if (n.name () == "numDice" && n.namespace_ () == "urn:rpg")
    {
      if (!numDice_.present ())
      {
        this->numDice_.set (numDice_traits::create (i, f, this));
        continue;
      }
    }

    // typeDice
    //
    {
      ::xsd::cxx::tree::type_factory_map< char >& tfm (
        ::xsd::cxx::tree::type_factory_map_instance< 0, char > ());

      ::std::auto_ptr< ::xsd::cxx::tree::type > tmp (
        tfm.create (
          "typeDice",
          "urn:rpg",
          &::xsd::cxx::tree::factory_impl< typeDice_type >,
          false, true, i, n, f, this));

      if (tmp.get () != 0)
      {
        if (!typeDice_.present ())
        {
          ::std::auto_ptr< typeDice_type > r (
            dynamic_cast< typeDice_type* > (tmp.get ()));

          if (r.get ())
            tmp.release ();
          else
            throw ::xsd::cxx::tree::not_derived< char > ();

          this->typeDice_.set (r);
          continue;
        }
      }
    }

    // modifier
    //
    if (n.name () == "modifier" && n.namespace_ () == "urn:rpg")
    {
      if (!modifier_.present ())
      {
        this->modifier_.set (modifier_traits::create (i, f, this));
        continue;
      }
    }

    break;
  }

  if (!numDice_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "numDice",
      "urn:rpg");
  }

  if (!typeDice_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "typeDice",
      "urn:rpg");
  }

  if (!modifier_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "modifier",
      "urn:rpg");
  }
}

RPG_Dice_Roll_Type* RPG_Dice_Roll_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Dice_Roll_Type (*this, f, c);
}

RPG_Dice_Roll_Type::
~RPG_Dice_Roll_Type ()
{
}

static
const ::xsd::cxx::tree::type_factory_initializer< 0, char, RPG_Dice_Roll_Type >
_xsd_RPG_Dice_Roll_Type_type_factory_init (
  "RPG_Dice_Roll_Type",
  "urn:rpg");

static
const ::xsd::cxx::tree::comparison_initializer< 0, char, RPG_Dice_Roll_Type >
_xsd_RPG_Dice_Roll_Type_comparison_init;

bool
operator== (const RPG_Dice_Roll_Type& x, const RPG_Dice_Roll_Type& y)
{
  if (!(x.numDice () == y.numDice ()))
    return false;

  {
    ::xsd::cxx::tree::comparison_map< char >& cm (
      ::xsd::cxx::tree::comparison_map_instance< 0, char > ());

    if (!cm.compare (x.typeDice (), y.typeDice ()))
      return false;
  }

  if (!(x.modifier () == y.modifier ()))
    return false;

  return true;
}

bool
operator!= (const RPG_Dice_Roll_Type& x, const RPG_Dice_Roll_Type& y)
{
  return !(x == y);
}

// RPG_Dice_ValueRange_Type
//

RPG_Dice_ValueRange_Type::
RPG_Dice_ValueRange_Type (const begin_type& begin,
                          const end_type& end)
: ::xml_schema::type (),
  begin_ (begin, ::xml_schema::flags (), this),
  end_ (end, ::xml_schema::flags (), this)
{
}

RPG_Dice_ValueRange_Type::
RPG_Dice_ValueRange_Type (const RPG_Dice_ValueRange_Type& x,
                          ::xml_schema::flags f,
                          ::xml_schema::container* c)
: ::xml_schema::type (x, f, c),
  begin_ (x.begin_, f, this),
  end_ (x.end_, f, this)
{
}

RPG_Dice_ValueRange_Type::
RPG_Dice_ValueRange_Type (const ::xercesc::DOMElement& e,
                          ::xml_schema::flags f,
                          ::xml_schema::container* c)
: ::xml_schema::type (e, f | ::xml_schema::flags::base, c),
  begin_ (f, this),
  end_ (f, this)
{
  if ((f & ::xml_schema::flags::base) == 0)
  {
    ::xsd::cxx::xml::dom::parser< char > p (e, true, false);
    this->parse (p, f);
  }
}

void RPG_Dice_ValueRange_Type::
parse (::xsd::cxx::xml::dom::parser< char >& p,
       ::xml_schema::flags f)
{
  for (; p.more_elements (); p.next_element ())
  {
    const ::xercesc::DOMElement& i (p.cur_element ());
    const ::xsd::cxx::xml::qualified_name< char > n (
      ::xsd::cxx::xml::dom::name< char > (i));

    // begin
    //
    if (n.name () == "begin" && n.namespace_ () == "urn:rpg")
    {
      if (!begin_.present ())
      {
        this->begin_.set (begin_traits::create (i, f, this));
        continue;
      }
    }

    // end
    //
    if (n.name () == "end" && n.namespace_ () == "urn:rpg")
    {
      if (!end_.present ())
      {
        this->end_.set (end_traits::create (i, f, this));
        continue;
      }
    }

    break;
  }

  if (!begin_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "begin",
      "urn:rpg");
  }

  if (!end_.present ())
  {
    throw ::xsd::cxx::tree::expected_element< char > (
      "end",
      "urn:rpg");
  }
}

RPG_Dice_ValueRange_Type* RPG_Dice_ValueRange_Type::
_clone (::xml_schema::flags f,
        ::xml_schema::container* c) const
{
  return new class RPG_Dice_ValueRange_Type (*this, f, c);
}

RPG_Dice_ValueRange_Type::
~RPG_Dice_ValueRange_Type ()
{
}

static
const ::xsd::cxx::tree::type_factory_initializer< 0, char, RPG_Dice_ValueRange_Type >
_xsd_RPG_Dice_ValueRange_Type_type_factory_init (
  "RPG_Dice_ValueRange_Type",
  "urn:rpg");

static
const ::xsd::cxx::tree::comparison_initializer< 0, char, RPG_Dice_ValueRange_Type >
_xsd_RPG_Dice_ValueRange_Type_comparison_init;

bool
operator== (const RPG_Dice_ValueRange_Type& x, const RPG_Dice_ValueRange_Type& y)
{
  if (!(x.begin () == y.begin ()))
    return false;

  if (!(x.end () == y.end ()))
    return false;

  return true;
}

bool
operator!= (const RPG_Dice_ValueRange_Type& x, const RPG_Dice_ValueRange_Type& y)
{
  return !(x == y);
}

#include <ostream>

#include <xsd/cxx/tree/std-ostream-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::std_ostream_plate< 0, char >
  std_ostream_plate_init;
}

::std::ostream&
operator<< (::std::ostream& o, RPG_Dice_DieType_Type::value i)
{
  return o << RPG_Dice_DieType_Type::_xsd_RPG_Dice_DieType_Type_literals_[i];
}

::std::ostream&
operator<< (::std::ostream& o, const RPG_Dice_DieType_Type& i)
{
  return o << static_cast< const ::xml_schema::string& > (i);
}

static
const ::xsd::cxx::tree::std_ostream_initializer< 0, char, RPG_Dice_DieType_Type >
_xsd_RPG_Dice_DieType_Type_std_ostream_init;

::std::ostream&
operator<< (::std::ostream& o, const RPG_Dice_Roll_Type& i)
{
  o << ::std::endl << "numDice: " << i.numDice ();
  {
    ::xsd::cxx::tree::std_ostream_map< char >& om (
      ::xsd::cxx::tree::std_ostream_map_instance< 0, char > ());

    o << ::std::endl << "typeDice: ";
    om.insert (o, i.typeDice ());
  }

  o << ::std::endl << "modifier: " << i.modifier ();
  return o;
}

static
const ::xsd::cxx::tree::std_ostream_initializer< 0, char, RPG_Dice_Roll_Type >
_xsd_RPG_Dice_Roll_Type_std_ostream_init;

::std::ostream&
operator<< (::std::ostream& o, const RPG_Dice_ValueRange_Type& i)
{
  o << ::std::endl << "begin: " << i.begin ();
  o << ::std::endl << "end: " << i.end ();
  return o;
}

static
const ::xsd::cxx::tree::std_ostream_initializer< 0, char, RPG_Dice_ValueRange_Type >
_xsd_RPG_Dice_ValueRange_Type_std_ostream_init;

#include <istream>
#include <xsd/cxx/xml/sax/std-input-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

#include <ostream>
#include <xsd/cxx/xml/dom/serialization-source.hxx>
#include <xsd/cxx/tree/error-handler.hxx>

#include <xsd/cxx/tree/type-serializer-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::type_serializer_plate< 0, char >
  type_serializer_plate_init;
}

void
operator<< (::xercesc::DOMElement& e, const RPG_Dice_DieType_Type& i)
{
  e << static_cast< const ::xml_schema::string& > (i);
}

void
operator<< (::xercesc::DOMAttr& a, const RPG_Dice_DieType_Type& i)
{
  a << static_cast< const ::xml_schema::string& > (i);
}

void
operator<< (::xml_schema::list_stream& l,
            const RPG_Dice_DieType_Type& i)
{
  l << static_cast< const ::xml_schema::string& > (i);
}

static
const ::xsd::cxx::tree::type_serializer_initializer< 0, char, RPG_Dice_DieType_Type >
_xsd_RPG_Dice_DieType_Type_type_serializer_init (
  "RPG_Dice_DieType_Type",
  "urn:rpg");


void
operator<< (::xercesc::DOMElement& e, const RPG_Dice_Roll_Type& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // numDice
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "numDice",
        "urn:rpg",
        e));

    s << i.numDice ();
  }

  // typeDice
  //
  {
    ::xsd::cxx::tree::type_serializer_map< char >& tsm (
      ::xsd::cxx::tree::type_serializer_map_instance< 0, char > ());

    const RPG_Dice_Roll_Type::typeDice_type& x (i.typeDice ());
    if (typeid (RPG_Dice_Roll_Type::typeDice_type) == typeid (x))
    {
      ::xercesc::DOMElement& s (
        ::xsd::cxx::xml::dom::create_element (
          "typeDice",
          "urn:rpg",
          e));

      s << x;
    }
    else
      tsm.serialize (
        "typeDice",
        "urn:rpg",
        false, true, e, x);
  }

  // modifier
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "modifier",
        "urn:rpg",
        e));

    s << i.modifier ();
  }
}

static
const ::xsd::cxx::tree::type_serializer_initializer< 0, char, RPG_Dice_Roll_Type >
_xsd_RPG_Dice_Roll_Type_type_serializer_init (
  "RPG_Dice_Roll_Type",
  "urn:rpg");


void
operator<< (::xercesc::DOMElement& e, const RPG_Dice_ValueRange_Type& i)
{
  e << static_cast< const ::xml_schema::type& > (i);

  // begin
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "begin",
        "urn:rpg",
        e));

    s << i.begin ();
  }

  // end
  //
  {
    ::xercesc::DOMElement& s (
      ::xsd::cxx::xml::dom::create_element (
        "end",
        "urn:rpg",
        e));

    s << i.end ();
  }
}

static
const ::xsd::cxx::tree::type_serializer_initializer< 0, char, RPG_Dice_ValueRange_Type >
_xsd_RPG_Dice_ValueRange_Type_type_serializer_init (
  "RPG_Dice_ValueRange_Type",
  "urn:rpg");


#include <xsd/cxx/tree/stream-extraction-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::stream_extraction_plate< 0, ACE_InputCDR, char >
  stream_extraction_plate_init_0;
}

RPG_Dice_DieType_Type::
RPG_Dice_DieType_Type (::xml_schema::istream< ACE_InputCDR >& s,
                       ::xml_schema::flags f,
                       ::xml_schema::container* c)
: ::xml_schema::string (s, f, c)
{
  _xsd_RPG_Dice_DieType_Type_convert ();
}

static
const ::xsd::cxx::tree::stream_extraction_initializer< 0, ACE_InputCDR, char, RPG_Dice_DieType_Type >
_xsd_RPG_Dice_DieType_Type_stream_extraction_init_0 (
  "RPG_Dice_DieType_Type",
  "urn:rpg");

RPG_Dice_Roll_Type::
RPG_Dice_Roll_Type (::xml_schema::istream< ACE_InputCDR >& s,
                    ::xml_schema::flags f,
                    ::xml_schema::container* c)
: ::xml_schema::type (s, f, c),
  numDice_ (f, this),
  typeDice_ (f, this),
  modifier_ (f, this)
{
  this->parse (s, f);
}

void RPG_Dice_Roll_Type::
parse (::xml_schema::istream< ACE_InputCDR >& s,
       ::xml_schema::flags f)
{
  {
    numDice_type r;
    s >> r;
    this->numDice_.set (r);
  }

  {
    bool d;
    ::std::auto_ptr< typeDice_type > r;
    s >> d;

    if (!d)
      r.reset (new typeDice_type (s, f, this));
    else
    {
      ::std::auto_ptr< ::xsd::cxx::tree::type > tmp (
        ::xsd::cxx::tree::stream_extraction_map_instance< 0, ACE_InputCDR, char > ().extract (
          s, f, this));
      r.reset (dynamic_cast< typeDice_type* > (tmp.get ()));
      if (r.get ())
        tmp.release ();
      else
        throw ::xsd::cxx::tree::not_derived< char > ();
    }

    this->typeDice_.set (r);
  }

  {
    modifier_type r;
    s >> r;
    this->modifier_.set (r);
  }
}

static
const ::xsd::cxx::tree::stream_extraction_initializer< 0, ACE_InputCDR, char, RPG_Dice_Roll_Type >
_xsd_RPG_Dice_Roll_Type_stream_extraction_init_0 (
  "RPG_Dice_Roll_Type",
  "urn:rpg");

RPG_Dice_ValueRange_Type::
RPG_Dice_ValueRange_Type (::xml_schema::istream< ACE_InputCDR >& s,
                          ::xml_schema::flags f,
                          ::xml_schema::container* c)
: ::xml_schema::type (s, f, c),
  begin_ (f, this),
  end_ (f, this)
{
  this->parse (s, f);
}

void RPG_Dice_ValueRange_Type::
parse (::xml_schema::istream< ACE_InputCDR >& s,
       ::xml_schema::flags f)
{
  {
    begin_type r;
    s >> r;
    this->begin_.set (r);
  }

  {
    end_type r;
    s >> r;
    this->end_.set (r);
  }
}

static
const ::xsd::cxx::tree::stream_extraction_initializer< 0, ACE_InputCDR, char, RPG_Dice_ValueRange_Type >
_xsd_RPG_Dice_ValueRange_Type_stream_extraction_init_0 (
  "RPG_Dice_ValueRange_Type",
  "urn:rpg");

#include <xsd/cxx/tree/stream-insertion-map.hxx>

namespace _xsd
{
  static
  const ::xsd::cxx::tree::stream_insertion_plate< 0, ACE_OutputCDR, char >
  stream_insertion_plate_init_0;
}

::xsd::cxx::tree::ostream< ACE_OutputCDR >&
operator<< (::xsd::cxx::tree::ostream< ACE_OutputCDR >& s,
            const RPG_Dice_DieType_Type& x)
{
  return s << static_cast< const ::xml_schema::string& > (x);
}

static
const ::xsd::cxx::tree::stream_insertion_initializer< 0, ACE_OutputCDR, char, RPG_Dice_DieType_Type >
_xsd_RPG_Dice_DieType_Type_stream_insertion_init_0 (
  "RPG_Dice_DieType_Type",
  "urn:rpg");

::xsd::cxx::tree::ostream< ACE_OutputCDR >&
operator<< (::xsd::cxx::tree::ostream< ACE_OutputCDR >& s,
            const RPG_Dice_Roll_Type& x)
{
  s << x.numDice ();
  {
    const RPG_Dice_Roll_Type::typeDice_type& i (x.typeDice ());
    bool d (typeid (RPG_Dice_Roll_Type::typeDice_type) != typeid (i));
    s << d;
    if (!d)
      s << i;
    else
      ::xsd::cxx::tree::stream_insertion_map_instance< 0, ACE_OutputCDR, char > ().insert (s, i);
  }

  s << x.modifier ();
  return s;
}

static
const ::xsd::cxx::tree::stream_insertion_initializer< 0, ACE_OutputCDR, char, RPG_Dice_Roll_Type >
_xsd_RPG_Dice_Roll_Type_stream_insertion_init_0 (
  "RPG_Dice_Roll_Type",
  "urn:rpg");

::xsd::cxx::tree::ostream< ACE_OutputCDR >&
operator<< (::xsd::cxx::tree::ostream< ACE_OutputCDR >& s,
            const RPG_Dice_ValueRange_Type& x)
{
  s << x.begin ();
  s << x.end ();
  return s;
}

static
const ::xsd::cxx::tree::stream_insertion_initializer< 0, ACE_OutputCDR, char, RPG_Dice_ValueRange_Type >
_xsd_RPG_Dice_ValueRange_Type_stream_insertion_init_0 (
  "RPG_Dice_ValueRange_Type",
  "urn:rpg");

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

