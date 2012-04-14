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
#include "rpg_engine_exports.h"
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
class RPG_Engine_EntityMode_XMLTree_Type;
class RPG_Engine_Player_XMLTree_Type;
class RPG_Engine_Level_XMLTree_Type;

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

#include "../common/rpg_common_environment_XML_tree.h"

#include "../character/player/rpg_player_XML_tree.h"

#include "../map/rpg_map_XML_tree.h"

#include "../graphics/rpg_graphics_XML_tree.h"

class RPG_Engine_Export RPG_Engine_Command_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    COMMAND_ATTACK,
    COMMAND_ATTACK_FULL,
    COMMAND_ATTACK_STANDARD,
    COMMAND_DOOR_CLOSE,
    COMMAND_DOOR_OPEN,
    COMMAND_SEARCH,
    COMMAND_STEP,
    COMMAND_STOP,
    COMMAND_TRAVEL,
    COMMAND_E2C_ENTITY_ADD,
    COMMAND_E2C_ENTITY_REMOVE,
    COMMAND_E2C_ENTITY_UPDATE,
    COMMAND_E2C_QUIT
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
  static const char* const _xsd_RPG_Engine_Command_XMLTree_Type_literals_[13];
  static const value _xsd_RPG_Engine_Command_XMLTree_Type_indexes_[13];
};

class RPG_Engine_Export RPG_Engine_EntityMode_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    ENTITYMODE_FIGHTING,
    ENTITYMODE_SEARCHING,
    ENTITYMODE_TRAVELLING
  };

  RPG_Engine_EntityMode_XMLTree_Type (value v);

  RPG_Engine_EntityMode_XMLTree_Type (const char* v);

  RPG_Engine_EntityMode_XMLTree_Type (const ::std::string& v);

  RPG_Engine_EntityMode_XMLTree_Type (const ::xml_schema::string& v);

  RPG_Engine_EntityMode_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                      ::xml_schema::flags f = 0,
                                      ::xml_schema::container* c = 0);

  RPG_Engine_EntityMode_XMLTree_Type (const ::xercesc::DOMElement& e,
                                      ::xml_schema::flags f = 0,
                                      ::xml_schema::container* c = 0);

  RPG_Engine_EntityMode_XMLTree_Type (const ::xercesc::DOMAttr& a,
                                      ::xml_schema::flags f = 0,
                                      ::xml_schema::container* c = 0);

  RPG_Engine_EntityMode_XMLTree_Type (const ::std::string& s,
                                      const ::xercesc::DOMElement* e,
                                      ::xml_schema::flags f = 0,
                                      ::xml_schema::container* c = 0);

  RPG_Engine_EntityMode_XMLTree_Type (const RPG_Engine_EntityMode_XMLTree_Type& x,
                                      ::xml_schema::flags f = 0,
                                      ::xml_schema::container* c = 0);

  virtual RPG_Engine_EntityMode_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  RPG_Engine_EntityMode_XMLTree_Type&
  operator= (value v);

  virtual
  operator value () const
  {
    return _xsd_RPG_Engine_EntityMode_XMLTree_Type_convert ();
  }

  protected:
  value
  _xsd_RPG_Engine_EntityMode_XMLTree_Type_convert () const;

  public:
  static const char* const _xsd_RPG_Engine_EntityMode_XMLTree_Type_literals_[3];
  static const value _xsd_RPG_Engine_EntityMode_XMLTree_Type_indexes_[3];
};

class RPG_Engine_Export RPG_Engine_Player_XMLTree_Type: public ::RPG_Player_PlayerXML_XMLTree_Type
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

  // mode
  // 
  typedef ::RPG_Engine_EntityMode_XMLTree_Type mode_type;
  typedef ::xsd::cxx::tree::sequence< mode_type > mode_sequence;
  typedef mode_sequence::iterator mode_iterator;
  typedef mode_sequence::const_iterator mode_const_iterator;
  typedef ::xsd::cxx::tree::traits< mode_type, char > mode_traits;

  const mode_sequence&
  mode () const;

  mode_sequence&
  mode ();

  void
  mode (const mode_sequence& s);

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
  mode_sequence mode_;
  ::xsd::cxx::tree::one< sprite_type > sprite_;
};

RPG_Engine_Export
bool
operator== (const RPG_Engine_Player_XMLTree_Type&, const RPG_Engine_Player_XMLTree_Type&);

RPG_Engine_Export
bool
operator!= (const RPG_Engine_Player_XMLTree_Type&, const RPG_Engine_Player_XMLTree_Type&);


class RPG_Engine_Export RPG_Engine_Level_XMLTree_Type: public ::xml_schema::type
{
  public:
  // name
  // 
  typedef ::xml_schema::string name_type;
  typedef ::xsd::cxx::tree::traits< name_type, char > name_traits;

  const name_type&
  name () const;

  name_type&
  name ();

  void
  name (const name_type& x);

  void
  name (::std::auto_ptr< name_type > p);

  // environment
  // 
  typedef ::RPG_Common_Environment_XMLTree_Type environment_type;
  typedef ::xsd::cxx::tree::traits< environment_type, char > environment_traits;

  const environment_type&
  environment () const;

  environment_type&
  environment ();

  void
  environment (const environment_type& x);

  void
  environment (::std::auto_ptr< environment_type > p);

  // monster
  // 
  typedef ::xml_schema::string monster_type;
  typedef ::xsd::cxx::tree::sequence< monster_type > monster_sequence;
  typedef monster_sequence::iterator monster_iterator;
  typedef monster_sequence::const_iterator monster_const_iterator;
  typedef ::xsd::cxx::tree::traits< monster_type, char > monster_traits;

  const monster_sequence&
  monster () const;

  monster_sequence&
  monster ();

  void
  monster (const monster_sequence& s);

  // spawn_interval
  // 
  typedef ::RPG_Common_FixedPeriod_XMLTree_Type spawn_interval_type;
  typedef ::xsd::cxx::tree::traits< spawn_interval_type, char > spawn_interval_traits;

  const spawn_interval_type&
  spawn_interval () const;

  spawn_interval_type&
  spawn_interval ();

  void
  spawn_interval (const spawn_interval_type& x);

  void
  spawn_interval (::std::auto_ptr< spawn_interval_type > p);

  // spawn_probability
  // 
  typedef ::xml_schema::float_ spawn_probability_type;
  typedef ::xsd::cxx::tree::traits< spawn_probability_type, char > spawn_probability_traits;

  const spawn_probability_type&
  spawn_probability () const;

  spawn_probability_type&
  spawn_probability ();

  void
  spawn_probability (const spawn_probability_type& x);

  // max_spawned
  // 
  typedef ::xml_schema::unsigned_int max_spawned_type;
  typedef ::xsd::cxx::tree::traits< max_spawned_type, char > max_spawned_traits;

  const max_spawned_type&
  max_spawned () const;

  max_spawned_type&
  max_spawned ();

  void
  max_spawned (const max_spawned_type& x);

  // map
  // 
  typedef ::xml_schema::string map_type;
  typedef ::xsd::cxx::tree::traits< map_type, char > map_traits;

  const map_type&
  map () const;

  map_type&
  map ();

  void
  map (const map_type& x);

  void
  map (::std::auto_ptr< map_type > p);

  // Constructors.
  //
  RPG_Engine_Level_XMLTree_Type (const name_type&,
                                 const environment_type&,
                                 const spawn_interval_type&,
                                 const spawn_probability_type&,
                                 const max_spawned_type&,
                                 const map_type&);

  RPG_Engine_Level_XMLTree_Type (const name_type&,
                                 ::std::auto_ptr< environment_type >&,
                                 ::std::auto_ptr< spawn_interval_type >&,
                                 const spawn_probability_type&,
                                 const max_spawned_type&,
                                 const map_type&);

  RPG_Engine_Level_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Engine_Level_XMLTree_Type (const ::xercesc::DOMElement& e,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Engine_Level_XMLTree_Type (const RPG_Engine_Level_XMLTree_Type& x,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  virtual RPG_Engine_Level_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  virtual 
  ~RPG_Engine_Level_XMLTree_Type ();

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

  ::xsd::cxx::tree::one< name_type > name_;
  ::xsd::cxx::tree::one< environment_type > environment_;
  monster_sequence monster_;
  ::xsd::cxx::tree::one< spawn_interval_type > spawn_interval_;
  ::xsd::cxx::tree::one< spawn_probability_type > spawn_probability_;
  ::xsd::cxx::tree::one< max_spawned_type > max_spawned_;
  ::xsd::cxx::tree::one< map_type > map_;
};

RPG_Engine_Export
bool
operator== (const RPG_Engine_Level_XMLTree_Type&, const RPG_Engine_Level_XMLTree_Type&);

RPG_Engine_Export
bool
operator!= (const RPG_Engine_Level_XMLTree_Type&, const RPG_Engine_Level_XMLTree_Type&);


#include <iosfwd>

RPG_Engine_Export
::std::ostream&
operator<< (::std::ostream&, RPG_Engine_Command_XMLTree_Type::value);

RPG_Engine_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Engine_Command_XMLTree_Type&);

RPG_Engine_Export
::std::ostream&
operator<< (::std::ostream&, RPG_Engine_EntityMode_XMLTree_Type::value);

RPG_Engine_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Engine_EntityMode_XMLTree_Type&);

RPG_Engine_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Engine_Player_XMLTree_Type&);

RPG_Engine_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Engine_Level_XMLTree_Type&);

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

// Parse a URI or a local file.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (const ::std::string& uri,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (const ::std::string& uri,
                 ::xml_schema::error_handler& eh,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (const ::std::string& uri,
                 ::xercesc::DOMErrorHandler& eh,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::std::istream& is,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::std::istream& is,
                 ::xml_schema::error_handler& eh,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::std::istream& is,
                 ::xercesc::DOMErrorHandler& eh,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::std::istream& is,
                 const ::std::string& id,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::std::istream& is,
                 const ::std::string& id,
                 ::xml_schema::error_handler& eh,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::std::istream& is,
                 const ::std::string& id,
                 ::xercesc::DOMErrorHandler& eh,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::xercesc::InputSource& is,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::xercesc::InputSource& is,
                 ::xml_schema::error_handler& eh,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::xercesc::InputSource& is,
                 ::xercesc::DOMErrorHandler& eh,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (const ::xercesc::DOMDocument& d,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Player_XMLTree_Type >
engine_player_t (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
                 ::xml_schema::flags f = 0,
                 const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse a URI or a local file.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (const ::std::string& uri,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (const ::std::string& uri,
                ::xml_schema::error_handler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (const ::std::string& uri,
                ::xercesc::DOMErrorHandler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::std::istream& is,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::std::istream& is,
                ::xml_schema::error_handler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::std::istream& is,
                ::xercesc::DOMErrorHandler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::std::istream& is,
                const ::std::string& id,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::std::istream& is,
                const ::std::string& id,
                ::xml_schema::error_handler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::std::istream& is,
                const ::std::string& id,
                ::xercesc::DOMErrorHandler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::xercesc::InputSource& is,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::xercesc::InputSource& is,
                ::xml_schema::error_handler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::xercesc::InputSource& is,
                ::xercesc::DOMErrorHandler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (const ::xercesc::DOMDocument& d,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_Level_XMLTree_Type >
engine_level_t (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

#include <iosfwd>

#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>
#include <xercesc/framework/XMLFormatter.hpp>

#include <xsd/cxx/xml/dom/auto-ptr.hxx>

RPG_Engine_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Engine_Command_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xercesc::DOMAttr&, const RPG_Engine_Command_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xml_schema::list_stream&,
            const RPG_Engine_Command_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Engine_EntityMode_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xercesc::DOMAttr&, const RPG_Engine_EntityMode_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xml_schema::list_stream&,
            const RPG_Engine_EntityMode_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Engine_Player_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Engine_Level_XMLTree_Type&);

// Serialize to std::ostream.
//

RPG_Engine_Export
void
engine_player_t (::std::ostream& os,
                 const ::RPG_Engine_Player_XMLTree_Type& x, 
                 const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                 const ::std::string& e = "UTF-8",
                 ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_player_t (::std::ostream& os,
                 const ::RPG_Engine_Player_XMLTree_Type& x, 
                 ::xml_schema::error_handler& eh,
                 const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                 const ::std::string& e = "UTF-8",
                 ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_player_t (::std::ostream& os,
                 const ::RPG_Engine_Player_XMLTree_Type& x, 
                 ::xercesc::DOMErrorHandler& eh,
                 const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                 const ::std::string& e = "UTF-8",
                 ::xml_schema::flags f = 0);

// Serialize to xercesc::XMLFormatTarget.
//

RPG_Engine_Export
void
engine_player_t (::xercesc::XMLFormatTarget& ft,
                 const ::RPG_Engine_Player_XMLTree_Type& x, 
                 const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                 const ::std::string& e = "UTF-8",
                 ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_player_t (::xercesc::XMLFormatTarget& ft,
                 const ::RPG_Engine_Player_XMLTree_Type& x, 
                 ::xml_schema::error_handler& eh,
                 const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                 const ::std::string& e = "UTF-8",
                 ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_player_t (::xercesc::XMLFormatTarget& ft,
                 const ::RPG_Engine_Player_XMLTree_Type& x, 
                 ::xercesc::DOMErrorHandler& eh,
                 const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                 const ::std::string& e = "UTF-8",
                 ::xml_schema::flags f = 0);

// Serialize to an existing xercesc::DOMDocument.
//

RPG_Engine_Export
void
engine_player_t (::xercesc::DOMDocument& d,
                 const ::RPG_Engine_Player_XMLTree_Type& x,
                 ::xml_schema::flags f = 0);

// Serialize to a new xercesc::DOMDocument.
//

RPG_Engine_Export
::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
engine_player_t (const ::RPG_Engine_Player_XMLTree_Type& x, 
                 const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                 ::xml_schema::flags f = 0);

// Serialize to std::ostream.
//

RPG_Engine_Export
void
engine_level_t (::std::ostream& os,
                const ::RPG_Engine_Level_XMLTree_Type& x, 
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_level_t (::std::ostream& os,
                const ::RPG_Engine_Level_XMLTree_Type& x, 
                ::xml_schema::error_handler& eh,
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_level_t (::std::ostream& os,
                const ::RPG_Engine_Level_XMLTree_Type& x, 
                ::xercesc::DOMErrorHandler& eh,
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

// Serialize to xercesc::XMLFormatTarget.
//

RPG_Engine_Export
void
engine_level_t (::xercesc::XMLFormatTarget& ft,
                const ::RPG_Engine_Level_XMLTree_Type& x, 
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_level_t (::xercesc::XMLFormatTarget& ft,
                const ::RPG_Engine_Level_XMLTree_Type& x, 
                ::xml_schema::error_handler& eh,
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_level_t (::xercesc::XMLFormatTarget& ft,
                const ::RPG_Engine_Level_XMLTree_Type& x, 
                ::xercesc::DOMErrorHandler& eh,
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

// Serialize to an existing xercesc::DOMDocument.
//

RPG_Engine_Export
void
engine_level_t (::xercesc::DOMDocument& d,
                const ::RPG_Engine_Level_XMLTree_Type& x,
                ::xml_schema::flags f = 0);

// Serialize to a new xercesc::DOMDocument.
//

RPG_Engine_Export
::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
engine_level_t (const ::RPG_Engine_Level_XMLTree_Type& x, 
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                ::xml_schema::flags f = 0);

RPG_Engine_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Engine_Command_XMLTree_Type&);

RPG_Engine_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Engine_EntityMode_XMLTree_Type&);

RPG_Engine_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Engine_Player_XMLTree_Type&);

RPG_Engine_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Engine_Level_XMLTree_Type&);

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_ENGINE_XML_TREE_H
