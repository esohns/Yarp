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

#ifndef CXX_____ETC_RPG_DICE_XML_TREE_H
#define CXX_____ETC_RPG_DICE_XML_TREE_H

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

// Begin prologue.
//
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 4009911L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#include "rpg_XMLSchema_XML_tree.h"

// Forward declarations.
//
class RPG_Dice_DieType_XMLTree_Type;
class RPG_Dice_Roll_XMLTree_Type;
class RPG_Dice_ValueRange_XMLTree_Type;

#include <memory>    // ::std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

class RPG_Dice_DieType_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    D_0,
    D_2,
    D_3,
    D_4,
    D_6,
    D_8,
    D_10,
    D_12,
    D_20,
    D_100
  };

  RPG_Dice_DieType_XMLTree_Type (value v);

  RPG_Dice_DieType_XMLTree_Type (const char* v);

  RPG_Dice_DieType_XMLTree_Type (const ::std::string& v);

  RPG_Dice_DieType_XMLTree_Type (const ::xml_schema::string& v);

  RPG_Dice_DieType_XMLTree_Type (const ::xercesc::DOMElement& e,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Dice_DieType_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Dice_DieType_XMLTree_Type (const ::std::string& s,
                                 const ::xercesc::DOMElement* e,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Dice_DieType_XMLTree_Type (const RPG_Dice_DieType_XMLTree_Type& x,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  virtual RPG_Dice_DieType_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Dice_DieType_XMLTree_Type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_RPG_Dice_DieType_XMLTree_Type_convert ();
  }

  protected:
  value
  _xsd_RPG_Dice_DieType_XMLTree_Type_convert () const;

  public:
  static const char* const _xsd_RPG_Dice_DieType_XMLTree_Type_literals_[10];
  static const value _xsd_RPG_Dice_DieType_XMLTree_Type_indexes_[10];
};

class RPG_Dice_Roll_XMLTree_Type: public ::xml_schema::type
{
  public:
  // numDice
  //
  typedef ::xml_schema::unsigned_int numDice_type;
  typedef ::xsd::cxx::tree::optional< numDice_type > numDice_optional;
  typedef ::xsd::cxx::tree::traits< numDice_type, char > numDice_traits;

  const numDice_optional&
  numDice () const;

  numDice_optional&
  numDice ();

  void
  numDice (const numDice_type& x);

  void
  numDice (const numDice_optional& x);

  // typeDice
  //
  typedef ::RPG_Dice_DieType_XMLTree_Type typeDice_type;
  typedef ::xsd::cxx::tree::traits< typeDice_type, char > typeDice_traits;

  const typeDice_type&
  typeDice () const;

  typeDice_type&
  typeDice ();

  void
  typeDice (const typeDice_type& x);

  void
  typeDice (::std::auto_ptr< typeDice_type > p);

  // modifier
  //
  typedef ::xml_schema::int_ modifier_type;
  typedef ::xsd::cxx::tree::optional< modifier_type > modifier_optional;
  typedef ::xsd::cxx::tree::traits< modifier_type, char > modifier_traits;

  const modifier_optional&
  modifier () const;

  modifier_optional&
  modifier ();

  void
  modifier (const modifier_type& x);

  void
  modifier (const modifier_optional& x);

  // Constructors.
  //
  RPG_Dice_Roll_XMLTree_Type (const typeDice_type&);

  RPG_Dice_Roll_XMLTree_Type (const ::xercesc::DOMElement& e,
                              ::xml_schema::flags f = 0,
                              ::xml_schema::container* c = 0);

  RPG_Dice_Roll_XMLTree_Type (const RPG_Dice_Roll_XMLTree_Type& x,
                              ::xml_schema::flags f = 0,
                              ::xml_schema::container* c = 0);

  virtual RPG_Dice_Roll_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Dice_Roll_XMLTree_Type&
  operator= (const RPG_Dice_Roll_XMLTree_Type& x);

  virtual 
  ~RPG_Dice_Roll_XMLTree_Type ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  numDice_optional numDice_;
  ::xsd::cxx::tree::one< typeDice_type > typeDice_;
  modifier_optional modifier_;
};

bool
operator== (const RPG_Dice_Roll_XMLTree_Type&, const RPG_Dice_Roll_XMLTree_Type&);

bool
operator!= (const RPG_Dice_Roll_XMLTree_Type&, const RPG_Dice_Roll_XMLTree_Type&);


class RPG_Dice_ValueRange_XMLTree_Type: public ::xml_schema::type
{
  public:
  // begin
  //
  typedef ::xml_schema::int_ begin_type;
  typedef ::xsd::cxx::tree::traits< begin_type, char > begin_traits;

  const begin_type&
  begin () const;

  begin_type&
  begin ();

  void
  begin (const begin_type& x);

  // end
  //
  typedef ::xml_schema::int_ end_type;
  typedef ::xsd::cxx::tree::traits< end_type, char > end_traits;

  const end_type&
  end () const;

  end_type&
  end ();

  void
  end (const end_type& x);

  // Constructors.
  //
  RPG_Dice_ValueRange_XMLTree_Type (const begin_type&,
                                    const end_type&);

  RPG_Dice_ValueRange_XMLTree_Type (const ::xercesc::DOMElement& e,
                                    ::xml_schema::flags f = 0,
                                    ::xml_schema::container* c = 0);

  RPG_Dice_ValueRange_XMLTree_Type (const RPG_Dice_ValueRange_XMLTree_Type& x,
                                    ::xml_schema::flags f = 0,
                                    ::xml_schema::container* c = 0);

  virtual RPG_Dice_ValueRange_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Dice_ValueRange_XMLTree_Type&
  operator= (const RPG_Dice_ValueRange_XMLTree_Type& x);

  virtual 
  ~RPG_Dice_ValueRange_XMLTree_Type ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  ::xsd::cxx::tree::one< begin_type > begin_;
  ::xsd::cxx::tree::one< end_type > end_;
};

bool
operator== (const RPG_Dice_ValueRange_XMLTree_Type&, const RPG_Dice_ValueRange_XMLTree_Type&);

bool
operator!= (const RPG_Dice_ValueRange_XMLTree_Type&, const RPG_Dice_ValueRange_XMLTree_Type&);


#include <iosfwd>

::std::ostream&
operator<< (::std::ostream&, RPG_Dice_DieType_XMLTree_Type::value);

::std::ostream&
operator<< (::std::ostream&, const RPG_Dice_DieType_XMLTree_Type&);

::std::ostream&
operator<< (::std::ostream&, const RPG_Dice_Roll_XMLTree_Type&);

::std::ostream&
operator<< (::std::ostream&, const RPG_Dice_ValueRange_XMLTree_Type&);

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

void
operator<< (::xercesc::DOMElement&, const RPG_Dice_DieType_XMLTree_Type&);

void
operator<< (::xercesc::DOMAttr&, const RPG_Dice_DieType_XMLTree_Type&);

void
operator<< (::xml_schema::list_stream&,
            const RPG_Dice_DieType_XMLTree_Type&);

void
operator<< (::xercesc::DOMElement&, const RPG_Dice_Roll_XMLTree_Type&);

void
operator<< (::xercesc::DOMElement&, const RPG_Dice_ValueRange_XMLTree_Type&);

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX_____ETC_RPG_DICE_XML_TREE_H
