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

#ifndef CXX___RPG_ENGINE_XML_TREE_H
#define CXX___RPG_ENGINE_XML_TREE_H

// Begin prologue.
//
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
class RPG_Engine_Command_XMLTree_Type;
class RPG_Engine_Player_XMLTree_Type;

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

#include "rpg_character_player_XML_tree.h"

#include "rpg_map_XML_tree.h"

#include "rpg_graphics_XML_tree.h"

class RPG_Engine_Command_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    COMMAND_ATTACK,
    COMMAND_DOOR_CLOSE,
    COMMAND_DOOR_OPEN,
    COMMAND_STEP,
    COMMAND_STOP,
    COMMAND_TRAVEL
  };

  RPG_Engine_Command_XMLTree_Type (value v);

  RPG_Engine_Command_XMLTree_Type (const char* v);

  RPG_Engine_Command_XMLTree_Type (const ::std::string& v);

  RPG_Engine_Command_XMLTree_Type (const ::xml_schema::string& v);

  RPG_Engine_Command_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Engine_Command_XMLTree_Type (const ::xercesc::DOMElement& e,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Engine_Command_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Engine_Command_XMLTree_Type (const ::std::string& s,
                                   const ::xercesc::DOMElement* e,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  RPG_Engine_Command_XMLTree_Type (const RPG_Engine_Command_XMLTree_Type& x,
                                   ::xml_schema::flags f = 0,
                                   ::xml_schema::container* c = 0);

  virtual RPG_Engine_Command_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Engine_Command_XMLTree_Type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_RPG_Engine_Command_XMLTree_Type_convert ();
  }

  protected:
  value
  _xsd_RPG_Engine_Command_XMLTree_Type_convert () const;

  public:
  static const char* const _xsd_RPG_Engine_Command_XMLTree_Type_literals_[6];
  static const value _xsd_RPG_Engine_Command_XMLTree_Type_indexes_[6];
};

class RPG_Engine_Player_XMLTree_Type: public ::RPG_Character_PlayerXML_XMLTree_Type
{
  public:
  // position
  // 
  typedef ::RPG_Map_Position_XMLTree_Type position_type;
  typedef ::xsd::cxx::tree::traits< position_type, char > position_traits;

  const position_type&
  position () const;

  position_type&
  position ();

  void
  position (const position_type& x);

  void
  position (::std::auto_ptr< position_type > p);

  // sprite
  // 
  typedef ::RPG_Graphics_Sprite_XMLTree_Type sprite_type;
  typedef ::xsd::cxx::tree::traits< sprite_type, char > sprite_traits;

  const sprite_type&
  sprite () const;

  sprite_type&
  sprite ();

  void
  sprite (const sprite_type& x);

  void
  sprite (::std::auto_ptr< sprite_type > p);

  // Constructors.
  //
  RPG_Engine_Player_XMLTree_Type (const name_type&,
                                  const alignment_type&,
                                  const attributes_type&,
                                  const defaultSize_type&,
                                  const maxHP_type&,
                                  const conditions_type&,
                                  const HP_type&,
                                  const XP_type&,
                                  const gold_type&,
                                  const inventory_type&,
                                  const gender_type&,
                                  const classXML_type&,
                                  const offhand_type&,
                                  const position_type&,
                                  const sprite_type&);

  RPG_Engine_Player_XMLTree_Type (const name_type&,
                                  ::std::auto_ptr< alignment_type >&,
                                  ::std::auto_ptr< attributes_type >&,
                                  const defaultSize_type&,
                                  const maxHP_type&,
                                  ::std::auto_ptr< conditions_type >&,
                                  const HP_type&,
                                  const XP_type&,
                                  const gold_type&,
                                  ::std::auto_ptr< inventory_type >&,
                                  const gender_type&,
                                  ::std::auto_ptr< classXML_type >&,
                                  const offhand_type&,
                                  ::std::auto_ptr< position_type >&,
                                  const sprite_type&);

  RPG_Engine_Player_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                  ::xml_schema::flags f = 0,
                                  ::xml_schema::container* c = 0);

  RPG_Engine_Player_XMLTree_Type (const ::xercesc::DOMElement& e,
                                  ::xml_schema::flags f = 0,
                                  ::xml_schema::container* c = 0);

  RPG_Engine_Player_XMLTree_Type (const RPG_Engine_Player_XMLTree_Type& x,
                                  ::xml_schema::flags f = 0,
                                  ::xml_schema::container* c = 0);

  virtual RPG_Engine_Player_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  virtual 
  ~RPG_Engine_Player_XMLTree_Type ();

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

  ::xsd::cxx::tree::one< position_type > position_;
  ::xsd::cxx::tree::one< sprite_type > sprite_;
};

bool
operator== (const RPG_Engine_Player_XMLTree_Type&, const RPG_Engine_Player_XMLTree_Type&);

bool
operator!= (const RPG_Engine_Player_XMLTree_Type&, const RPG_Engine_Player_XMLTree_Type&);


#include <iosfwd>

::std::ostream&
operator<< (::std::ostream&, RPG_Engine_Command_XMLTree_Type::value);

::std::ostream&
operator<< (::std::ostream&, const RPG_Engine_Command_XMLTree_Type&);

::std::ostream&
operator<< (::std::ostream&, const RPG_Engine_Player_XMLTree_Type&);

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

// Parse a URI or a local file.
//

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (const ::std::string& uri,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (const ::std::string& uri,
               ::xml_schema::error_handler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (const ::std::string& uri,
               ::xercesc::DOMErrorHandler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               ::xml_schema::error_handler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               ::xercesc::DOMErrorHandler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               const ::std::string& id,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               const ::std::string& id,
               ::xml_schema::error_handler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::std::istream& is,
               const ::std::string& id,
               ::xercesc::DOMErrorHandler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::xercesc::InputSource& is,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::xercesc::InputSource& is,
               ::xml_schema::error_handler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::xercesc::InputSource& is,
               ::xercesc::DOMErrorHandler& eh,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (const ::xercesc::DOMDocument& d,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
               ::xml_schema::flags f = 0,
               const ::xml_schema::properties& p = ::xml_schema::properties ());

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

void
operator<< (::xercesc::DOMElement&, const RPG_Engine_Command_XMLTree_Type&);

void
operator<< (::xercesc::DOMAttr&, const RPG_Engine_Command_XMLTree_Type&);

void
operator<< (::xml_schema::list_stream&,
            const RPG_Engine_Command_XMLTree_Type&);

void
operator<< (::xercesc::DOMElement&, const RPG_Engine_Player_XMLTree_Type&);

// Serialize to std::ostream.
//

void
engine_player (::std::ostream& os,
               const ::RPG_Engine_Player_XMLTree_Type& x, 
               const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
               const ::std::string& e = "UTF-8",
               ::xml_schema::flags f = 0);

void
engine_player (::std::ostream& os,
               const ::RPG_Engine_Player_XMLTree_Type& x, 
               ::xml_schema::error_handler& eh,
               const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
               const ::std::string& e = "UTF-8",
               ::xml_schema::flags f = 0);

void
engine_player (::std::ostream& os,
               const ::RPG_Engine_Player_XMLTree_Type& x, 
               ::xercesc::DOMErrorHandler& eh,
               const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
               const ::std::string& e = "UTF-8",
               ::xml_schema::flags f = 0);

// Serialize to xercesc::XMLFormatTarget.
//

void
engine_player (::xercesc::XMLFormatTarget& ft,
               const ::RPG_Engine_Player_XMLTree_Type& x, 
               const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
               const ::std::string& e = "UTF-8",
               ::xml_schema::flags f = 0);

void
engine_player (::xercesc::XMLFormatTarget& ft,
               const ::RPG_Engine_Player_XMLTree_Type& x, 
               ::xml_schema::error_handler& eh,
               const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
               const ::std::string& e = "UTF-8",
               ::xml_schema::flags f = 0);

void
engine_player (::xercesc::XMLFormatTarget& ft,
               const ::RPG_Engine_Player_XMLTree_Type& x, 
               ::xercesc::DOMErrorHandler& eh,
               const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
               const ::std::string& e = "UTF-8",
               ::xml_schema::flags f = 0);

// Serialize to an existing xercesc::DOMDocument.
//

void
engine_player (::xercesc::DOMDocument& d,
               const ::RPG_Engine_Player_XMLTree_Type& x,
               ::xml_schema::flags f = 0);

// Serialize to a new xercesc::DOMDocument.
//

::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
engine_player (const ::RPG_Engine_Player_XMLTree_Type& x, 
               const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
               ::xml_schema::flags f = 0);

::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Engine_Command_XMLTree_Type&);

::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Engine_Player_XMLTree_Type&);

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_ENGINE_XML_TREE_H
