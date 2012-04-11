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

#ifndef CXX___RPG_COMMON_ENVIRONMENT_XML_TREE_H
#define CXX___RPG_COMMON_ENVIRONMENT_XML_TREE_H

// Begin prologue.
//
#include "rpg_common_exports.h"
//
// End prologue.

#include <xsd/cxx/config.hxx>

#if (XSD_INT_VERSION != 3030000L)
#error XSD runtime version mismatch
#endif

#include <xsd/cxx/pre.hxx>

#ifndef XSD_USE_CHAR
#define XSD_USE_CHAR
#endif

#ifndef XSD_CXX_TREE_USE_CHAR
#define XSD_CXX_TREE_USE_CHAR
#endif

#include "rpg_XMLSchema_XML_tree.h"

// Forward declarations.
//
class RPG_Common_Plane_XMLTree_Type;
class RPG_Common_Terrain_XMLTree_Type;
class RPG_Common_Climate_XMLTree_Type;
class RPG_Common_TimeOfDay_XMLTree_Type;
class RPG_Common_AmbientLighting_XMLTree_Type;
class RPG_Common_Environment_XMLTree_Type;

#include <memory>    // std::auto_ptr
#include <limits>    // std::numeric_limits
#include <algorithm> // std::binary_search

#include <xsd/cxx/xml/char-utf8.hxx>

#include <xsd/cxx/tree/exceptions.hxx>
#include <xsd/cxx/tree/elements.hxx>
#include <xsd/cxx/tree/containers.hxx>
#include <xsd/cxx/tree/list.hxx>

#include <xsd/cxx/xml/dom/parsing-header.hxx>

#include <xsd/cxx/tree/istream-fwd.hxx>

class RPG_Common_Export RPG_Common_Plane_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    PLANE_INNER,
    PLANE_MATERIAL,
    PLANE_OUTER,
    PLANE_TRANSITIVE,
    PLANE_ANY
  };

  RPG_Common_Plane_XMLTree_Type (value v);

  RPG_Common_Plane_XMLTree_Type (const char* v);

  RPG_Common_Plane_XMLTree_Type (const ::std::string& v);

  RPG_Common_Plane_XMLTree_Type (const ::xml_schema::string& v);

  RPG_Common_Plane_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Common_Plane_XMLTree_Type (const ::xercesc::DOMElement& e,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Common_Plane_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Common_Plane_XMLTree_Type (const ::std::string& s,
                                 const ::xercesc::DOMElement* e,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Common_Plane_XMLTree_Type (const RPG_Common_Plane_XMLTree_Type& x,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  virtual RPG_Common_Plane_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Common_Plane_XMLTree_Type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_RPG_Common_Plane_XMLTree_Type_convert ();
  }

  protected:
  value
  _xsd_RPG_Common_Plane_XMLTree_Type_convert () const;

  public:
  static const char* const _xsd_RPG_Common_Plane_XMLTree_Type_literals_[5];
  static const value _xsd_RPG_Common_Plane_XMLTree_Type_indexes_[5];
};

class RPG_Common_Export RPG_Common_Terrain_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    TERRAIN_DESERTS,
    TERRAIN_FORESTS,
    TERRAIN_HILLS,
    TERRAIN_MARSHES,
    TERRAIN_MOUNTAINS,
    TERRAIN_PLAINS,
    TERRAIN_PLANE_INNER_AIR,
    TERRAIN_PLANE_INNER_EARTH,
    TERRAIN_PLANE_INNER_FIRE,
    TERRAIN_PLANE_INNER_WATER,
    TERRAIN_PLANE_INNER_POSITIVE,
    TERRAIN_PLANE_INNER_NEGATIVE,
    TERRAIN_PLANE_INNER_ANY,
    TERRAIN_PLANE_MATERIAL_ANY,
    TERRAIN_PLANE_OUTER_LAWFUL_ANY,
    TERRAIN_PLANE_OUTER_CHAOTIC_ANY,
    TERRAIN_PLANE_OUTER_GOOD_ANY,
    TERRAIN_PLANE_OUTER_EVIL_ANY,
    TERRAIN_PLANE_OUTER_LAWFUL_GOOD,
    TERRAIN_PLANE_OUTER_LAWFUL_EVIL,
    TERRAIN_PLANE_OUTER_CHAOTIC_GOOD,
    TERRAIN_PLANE_OUTER_CHAOTIC_EVIL,
    TERRAIN_PLANE_OUTER_NEUTRAL,
    TERRAIN_PLANE_OUTER_MILD_ANY,
    TERRAIN_PLANE_OUTER_STRONG_ANY,
    TERRAIN_PLANE_OUTER_ANY,
    TERRAIN_PLANE_TRANSITIVE_ASTRAL,
    TERRAIN_PLANE_TRANSITIVE_ETHERAL,
    TERRAIN_PLANE_TRANSITIVE_SHADOW,
    TERRAIN_PLANE_TRANSITIVE_ANY,
    TERRAIN_SETTLEMENT,
    TERRAIN_UNDER_GROUND,
    TERRAIN_UNDER_WATER,
    TERRAIN_ANY
  };

  RPG_Common_Terrain_XMLTree_Type (value v);

  RPG_Common_Terrain_XMLTree_Type (const char* v);

  RPG_Common_Terrain_XMLTree_Type (const ::std::string& v);

  RPG_Common_Terrain_XMLTree_Type (const ::xml_schema::string& v);

  RPG_Common_Terrain_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Common_Terrain_XMLTree_Type (const ::xercesc::DOMElement& e,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Common_Terrain_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Common_Terrain_XMLTree_Type (const ::std::string& s,
                                   const ::xercesc::DOMElement* e,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Common_Terrain_XMLTree_Type (const RPG_Common_Terrain_XMLTree_Type& x,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  virtual RPG_Common_Terrain_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Common_Terrain_XMLTree_Type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_RPG_Common_Terrain_XMLTree_Type_convert ();
  }

  protected:
  value
  _xsd_RPG_Common_Terrain_XMLTree_Type_convert () const;

  public:
  static const char* const _xsd_RPG_Common_Terrain_XMLTree_Type_literals_[34];
  static const value _xsd_RPG_Common_Terrain_XMLTree_Type_indexes_[34];
};

class RPG_Common_Export RPG_Common_Climate_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    CLIMATE_COLD,
    CLIMATE_TEMPERATE,
    CLIMATE_WARM,
    CLIMATE_ANY
  };

  RPG_Common_Climate_XMLTree_Type (value v);

  RPG_Common_Climate_XMLTree_Type (const char* v);

  RPG_Common_Climate_XMLTree_Type (const ::std::string& v);

  RPG_Common_Climate_XMLTree_Type (const ::xml_schema::string& v);

  RPG_Common_Climate_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Common_Climate_XMLTree_Type (const ::xercesc::DOMElement& e,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Common_Climate_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Common_Climate_XMLTree_Type (const ::std::string& s,
                                   const ::xercesc::DOMElement* e,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Common_Climate_XMLTree_Type (const RPG_Common_Climate_XMLTree_Type& x,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  virtual RPG_Common_Climate_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Common_Climate_XMLTree_Type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_RPG_Common_Climate_XMLTree_Type_convert ();
  }

  protected:
  value
  _xsd_RPG_Common_Climate_XMLTree_Type_convert () const;

  public:
  static const char* const _xsd_RPG_Common_Climate_XMLTree_Type_literals_[4];
  static const value _xsd_RPG_Common_Climate_XMLTree_Type_indexes_[4];
};

class RPG_Common_Export RPG_Common_TimeOfDay_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    TIMEOFDAY_DAYTIME,
    TIMEOFDAY_NIGHTTIME,
    TIMEOFDAY_ANY
  };

  RPG_Common_TimeOfDay_XMLTree_Type (value v);

  RPG_Common_TimeOfDay_XMLTree_Type (const char* v);

  RPG_Common_TimeOfDay_XMLTree_Type (const ::std::string& v);

  RPG_Common_TimeOfDay_XMLTree_Type (const ::xml_schema::string& v);

  RPG_Common_TimeOfDay_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                     ::xml_schema::flags f = 0,
                                     ::xml_schema::container* c = 0);

  RPG_Common_TimeOfDay_XMLTree_Type (const ::xercesc::DOMElement& e,
                                     ::xml_schema::flags f = 0,
                                     ::xml_schema::container* c = 0);

  RPG_Common_TimeOfDay_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                     ::xml_schema::flags f = 0,
                                     ::xml_schema::container* c = 0);

  RPG_Common_TimeOfDay_XMLTree_Type (const ::std::string& s,
                                     const ::xercesc::DOMElement* e,
                                     ::xml_schema::flags f = 0,
                                     ::xml_schema::container* c = 0);

  RPG_Common_TimeOfDay_XMLTree_Type (const RPG_Common_TimeOfDay_XMLTree_Type& x,
                                     ::xml_schema::flags f = 0,
                                     ::xml_schema::container* c = 0);

  virtual RPG_Common_TimeOfDay_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Common_TimeOfDay_XMLTree_Type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_RPG_Common_TimeOfDay_XMLTree_Type_convert ();
  }

  protected:
  value
  _xsd_RPG_Common_TimeOfDay_XMLTree_Type_convert () const;

  public:
  static const char* const _xsd_RPG_Common_TimeOfDay_XMLTree_Type_literals_[3];
  static const value _xsd_RPG_Common_TimeOfDay_XMLTree_Type_indexes_[3];
};

class RPG_Common_Export RPG_Common_AmbientLighting_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    AMBIENCE_BRIGHT,
    AMBIENCE_SHADOWY,
    AMBIENCE_DARKNESS
  };

  RPG_Common_AmbientLighting_XMLTree_Type (value v);

  RPG_Common_AmbientLighting_XMLTree_Type (const char* v);

  RPG_Common_AmbientLighting_XMLTree_Type (const ::std::string& v);

  RPG_Common_AmbientLighting_XMLTree_Type (const ::xml_schema::string& v);

  RPG_Common_AmbientLighting_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                           ::xml_schema::flags f = 0,
                                           ::xml_schema::container* c = 0);

  RPG_Common_AmbientLighting_XMLTree_Type (const ::xercesc::DOMElement& e,
                                           ::xml_schema::flags f = 0,
                                           ::xml_schema::container* c = 0);

  RPG_Common_AmbientLighting_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                           ::xml_schema::flags f = 0,
                                           ::xml_schema::container* c = 0);

  RPG_Common_AmbientLighting_XMLTree_Type (const ::std::string& s,
                                           const ::xercesc::DOMElement* e,
                                           ::xml_schema::flags f = 0,
                                           ::xml_schema::container* c = 0);

  RPG_Common_AmbientLighting_XMLTree_Type (const RPG_Common_AmbientLighting_XMLTree_Type& x,
                                           ::xml_schema::flags f = 0,
                                           ::xml_schema::container* c = 0);

  virtual RPG_Common_AmbientLighting_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Common_AmbientLighting_XMLTree_Type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_RPG_Common_AmbientLighting_XMLTree_Type_convert ();
  }

  protected:
  value
  _xsd_RPG_Common_AmbientLighting_XMLTree_Type_convert () const;

  public:
  static const char* const _xsd_RPG_Common_AmbientLighting_XMLTree_Type_literals_[3];
  static const value _xsd_RPG_Common_AmbientLighting_XMLTree_Type_indexes_[3];
};

class RPG_Common_Export RPG_Common_Environment_XMLTree_Type: public ::xml_schema::type
{
  public:
  // plane
  // 
  typedef ::RPG_Common_Plane_XMLTree_Type plane_type;
  typedef ::xsd::cxx::tree::optional< plane_type > plane_optional;
  typedef ::xsd::cxx::tree::traits< plane_type, char > plane_traits;

  const plane_optional&
  plane () const;

  plane_optional&
  plane ();

  void
  plane (const plane_type& x);

  void
  plane (const plane_optional& x);

  void
  plane (::std::auto_ptr< plane_type > p);

  // terrain
  // 
  typedef ::RPG_Common_Terrain_XMLTree_Type terrain_type;
  typedef ::xsd::cxx::tree::optional< terrain_type > terrain_optional;
  typedef ::xsd::cxx::tree::traits< terrain_type, char > terrain_traits;

  const terrain_optional&
  terrain () const;

  terrain_optional&
  terrain ();

  void
  terrain (const terrain_type& x);

  void
  terrain (const terrain_optional& x);

  void
  terrain (::std::auto_ptr< terrain_type > p);

  // climate
  // 
  typedef ::RPG_Common_Climate_XMLTree_Type climate_type;
  typedef ::xsd::cxx::tree::optional< climate_type > climate_optional;
  typedef ::xsd::cxx::tree::traits< climate_type, char > climate_traits;

  const climate_optional&
  climate () const;

  climate_optional&
  climate ();

  void
  climate (const climate_type& x);

  void
  climate (const climate_optional& x);

  void
  climate (::std::auto_ptr< climate_type > p);

  // time
  // 
  typedef ::RPG_Common_TimeOfDay_XMLTree_Type time_type;
  typedef ::xsd::cxx::tree::optional< time_type > time_optional;
  typedef ::xsd::cxx::tree::traits< time_type, char > time_traits;

  const time_optional&
  time () const;

  time_optional&
  time ();

  void
  time (const time_type& x);

  void
  time (const time_optional& x);

  void
  time (::std::auto_ptr< time_type > p);

  // lighting
  // 
  typedef ::RPG_Common_AmbientLighting_XMLTree_Type lighting_type;
  typedef ::xsd::cxx::tree::optional< lighting_type > lighting_optional;
  typedef ::xsd::cxx::tree::traits< lighting_type, char > lighting_traits;

  const lighting_optional&
  lighting () const;

  lighting_optional&
  lighting ();

  void
  lighting (const lighting_type& x);

  void
  lighting (const lighting_optional& x);

  void
  lighting (::std::auto_ptr< lighting_type > p);

  // outdoors
  // 
  typedef ::xml_schema::boolean outdoors_type;
  typedef ::xsd::cxx::tree::traits< outdoors_type, char > outdoors_traits;

  const outdoors_type&
  outdoors () const;

  outdoors_type&
  outdoors ();

  void
  outdoors (const outdoors_type& x);

  static outdoors_type
  outdoors_default_value ();

  // Constructors.
  //
  RPG_Common_Environment_XMLTree_Type ();

  RPG_Common_Environment_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                       ::xml_schema::flags f = 0,
                                       ::xml_schema::container* c = 0);

  RPG_Common_Environment_XMLTree_Type (const ::xercesc::DOMElement& e,
                                       ::xml_schema::flags f = 0,
                                       ::xml_schema::container* c = 0);

  RPG_Common_Environment_XMLTree_Type (const RPG_Common_Environment_XMLTree_Type& x,
                                       ::xml_schema::flags f = 0,
                                       ::xml_schema::container* c = 0);

  virtual RPG_Common_Environment_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  virtual 
  ~RPG_Common_Environment_XMLTree_Type ();

  // Implementation.
  //
  protected:
  void
  parse (::xsd::cxx::xml::dom::parser< char >&,
         ::xml_schema::flags);

  protected:
  void
  parse (::xml_schema::istream< ACE_InputCDR >&,
         ::xml_schema::flags);

  plane_optional plane_;
  terrain_optional terrain_;
  climate_optional climate_;
  time_optional time_;
  lighting_optional lighting_;
  ::xsd::cxx::tree::one< outdoors_type > outdoors_;
};

RPG_Common_Export
bool
operator== (const RPG_Common_Environment_XMLTree_Type&, const RPG_Common_Environment_XMLTree_Type&);

RPG_Common_Export
bool
operator!= (const RPG_Common_Environment_XMLTree_Type&, const RPG_Common_Environment_XMLTree_Type&);


#include <iosfwd>

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, RPG_Common_Plane_XMLTree_Type::value);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Common_Plane_XMLTree_Type&);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, RPG_Common_Terrain_XMLTree_Type::value);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Common_Terrain_XMLTree_Type&);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, RPG_Common_Climate_XMLTree_Type::value);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Common_Climate_XMLTree_Type&);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, RPG_Common_TimeOfDay_XMLTree_Type::value);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Common_TimeOfDay_XMLTree_Type&);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, RPG_Common_AmbientLighting_XMLTree_Type::value);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Common_AmbientLighting_XMLTree_Type&);

RPG_Common_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Common_Environment_XMLTree_Type&);

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

RPG_Common_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Common_Plane_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMAttr&, const RPG_Common_Plane_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xml_schema::list_stream&,
            const RPG_Common_Plane_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Common_Terrain_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMAttr&, const RPG_Common_Terrain_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xml_schema::list_stream&,
            const RPG_Common_Terrain_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Common_Climate_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMAttr&, const RPG_Common_Climate_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xml_schema::list_stream&,
            const RPG_Common_Climate_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Common_TimeOfDay_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMAttr&, const RPG_Common_TimeOfDay_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xml_schema::list_stream&,
            const RPG_Common_TimeOfDay_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Common_AmbientLighting_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMAttr&, const RPG_Common_AmbientLighting_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xml_schema::list_stream&,
            const RPG_Common_AmbientLighting_XMLTree_Type&);

RPG_Common_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Common_Environment_XMLTree_Type&);

RPG_Common_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Common_Plane_XMLTree_Type&);

RPG_Common_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Common_Terrain_XMLTree_Type&);

RPG_Common_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Common_Climate_XMLTree_Type&);

RPG_Common_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Common_TimeOfDay_XMLTree_Type&);

RPG_Common_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Common_AmbientLighting_XMLTree_Type&);

RPG_Common_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Common_Environment_XMLTree_Type&);

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_COMMON_ENVIRONMENT_XML_TREE_H
