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
class RPG_Engine_EntityState_XMLTree_Type;
class RPG_Engine_Level_XMLTree_Type;
class RPG_Engine_State_XMLTree_Type;

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

#include "rpg_player_XML_tree.h"

#include "rpg_monster_XML_tree.h"

#include "rpg_map_XML_tree.h"

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
    COMMAND_IDLE,
    COMMAND_RUN,
    COMMAND_SEARCH,
    COMMAND_STEP,
    COMMAND_STOP,
    COMMAND_TRAVEL,
    COMMAND_E2C_ENTITY_ADD,
    COMMAND_E2C_ENTITY_REMOVE,
    COMMAND_E2C_ENTITY_HIT,
    COMMAND_E2C_ENTITY_MISS,
    COMMAND_E2C_ENTITY_CONDITION,
    COMMAND_E2C_ENTITY_POSITION,
    COMMAND_E2C_ENTITY_VISION,
    COMMAND_E2C_ENTITY_LEVEL_UP,
    COMMAND_E2C_INIT,
    COMMAND_E2C_MESSAGE,
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
  static const char* const _xsd_RPG_Engine_Command_XMLTree_Type_literals_[22];
  static const value _xsd_RPG_Engine_Command_XMLTree_Type_indexes_[22];
};

class RPG_Engine_Export RPG_Engine_EntityMode_XMLTree_Type: public ::xml_schema::string
{
  public:
  enum value
  {
    ENTITYMODE_FIGHTING,
    ENTITYMODE_RUNNING,
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
  static const char* const _xsd_RPG_Engine_EntityMode_XMLTree_Type_literals_[4];
  static const value _xsd_RPG_Engine_EntityMode_XMLTree_Type_indexes_[4];
};

class RPG_Engine_Export RPG_Engine_EntityState_XMLTree_Type: public ::xml_schema::type
{
  public:
  // player
  // 
  typedef ::RPG_Player_State_XMLTree_Type player_type;
  typedef ::xsd::cxx::tree::optional< player_type > player_optional;
  typedef ::xsd::cxx::tree::traits< player_type, char > player_traits;

  const player_optional&
  player () const;

  player_optional&
  player ();

  void
  player (const player_type& x);

  void
  player (const player_optional& x);

  void
  player (::std::auto_ptr< player_type > p);

  // monster
  // 
  typedef ::RPG_Monster_State_XMLTree_Type monster_type;
  typedef ::xsd::cxx::tree::optional< monster_type > monster_optional;
  typedef ::xsd::cxx::tree::traits< monster_type, char > monster_traits;

  const monster_optional&
  monster () const;

  monster_optional&
  monster ();

  void
  monster (const monster_type& x);

  void
  monster (const monster_optional& x);

  void
  monster (::std::auto_ptr< monster_type > p);

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

  // Constructors.
  //
  RPG_Engine_EntityState_XMLTree_Type (const position_type&);

  RPG_Engine_EntityState_XMLTree_Type (::std::auto_ptr< position_type >&);

  RPG_Engine_EntityState_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                       ::xml_schema::flags f = 0,
                                       ::xml_schema::container* c = 0);

  RPG_Engine_EntityState_XMLTree_Type (const ::xercesc::DOMElement& e,
                                       ::xml_schema::flags f = 0,
                                       ::xml_schema::container* c = 0);

  RPG_Engine_EntityState_XMLTree_Type (const RPG_Engine_EntityState_XMLTree_Type& x,
                                       ::xml_schema::flags f = 0,
                                       ::xml_schema::container* c = 0);

  virtual RPG_Engine_EntityState_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  virtual 
  ~RPG_Engine_EntityState_XMLTree_Type ();

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

  player_optional player_;
  monster_optional monster_;
  ::xsd::cxx::tree::one< position_type > position_;
  mode_sequence mode_;
};

RPG_Engine_Export
bool
operator== (const RPG_Engine_EntityState_XMLTree_Type&, const RPG_Engine_EntityState_XMLTree_Type&);

RPG_Engine_Export
bool
operator!= (const RPG_Engine_EntityState_XMLTree_Type&, const RPG_Engine_EntityState_XMLTree_Type&);


class RPG_Engine_Export RPG_Engine_Level_XMLTree_Type: public ::RPG_Map_Level_XMLTree_Type
{
  public:
  // spawn
  // 
  typedef ::RPG_Monster_Spawn_XMLTree_Type spawn_type;
  typedef ::xsd::cxx::tree::sequence< spawn_type > spawn_sequence;
  typedef spawn_sequence::iterator spawn_iterator;
  typedef spawn_sequence::const_iterator spawn_const_iterator;
  typedef ::xsd::cxx::tree::traits< spawn_type, char > spawn_traits;

  const spawn_sequence&
  spawn () const;

  spawn_sequence&
  spawn ();

  void
  spawn (const spawn_sequence& s);

  // max_num_spawned
  // 
  typedef ::xml_schema::unsigned_int max_num_spawned_type;
  typedef ::xsd::cxx::tree::traits< max_num_spawned_type, char > max_num_spawned_traits;

  const max_num_spawned_type&
  max_num_spawned () const;

  max_num_spawned_type&
  max_num_spawned ();

  void
  max_num_spawned (const max_num_spawned_type& x);

  // Constructors.
  //
  RPG_Engine_Level_XMLTree_Type (const name_type&,
                                 const environment_type&,
                                 const map_type&,
                                 const max_num_spawned_type&);

  RPG_Engine_Level_XMLTree_Type (const name_type&,
                                 ::std::auto_ptr< environment_type >&,
                                 const map_type&,
                                 const max_num_spawned_type&);

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

  spawn_sequence spawn_;
  ::xsd::cxx::tree::one< max_num_spawned_type > max_num_spawned_;
};

RPG_Engine_Export
bool
operator== (const RPG_Engine_Level_XMLTree_Type&, const RPG_Engine_Level_XMLTree_Type&);

RPG_Engine_Export
bool
operator!= (const RPG_Engine_Level_XMLTree_Type&, const RPG_Engine_Level_XMLTree_Type&);


class RPG_Engine_Export RPG_Engine_State_XMLTree_Type: public ::RPG_Map_State_XMLTree_Type
{
  public:
  // entities
  // 
  typedef ::RPG_Engine_EntityState_XMLTree_Type entities_type;
  typedef ::xsd::cxx::tree::sequence< entities_type > entities_sequence;
  typedef entities_sequence::iterator entities_iterator;
  typedef entities_sequence::const_iterator entities_const_iterator;
  typedef ::xsd::cxx::tree::traits< entities_type, char > entities_traits;

  const entities_sequence&
  entities () const;

  entities_sequence&
  entities ();

  void
  entities (const entities_sequence& s);

  // Constructors.
  //
  RPG_Engine_State_XMLTree_Type (const file_type&);

  RPG_Engine_State_XMLTree_Type (::xml_schema::istream< ACE_InputCDR >& s,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Engine_State_XMLTree_Type (const ::xercesc::DOMElement& e,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  RPG_Engine_State_XMLTree_Type (const RPG_Engine_State_XMLTree_Type& x,
                                 ::xml_schema::flags f = 0,
                                 ::xml_schema::container* c = 0);

  virtual RPG_Engine_State_XMLTree_Type*
  _clone (::xml_schema::flags f = 0,
          ::xml_schema::container* c = 0) const;

  virtual 
  ~RPG_Engine_State_XMLTree_Type ();

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

  entities_sequence entities_;
};

RPG_Engine_Export
bool
operator== (const RPG_Engine_State_XMLTree_Type&, const RPG_Engine_State_XMLTree_Type&);

RPG_Engine_Export
bool
operator!= (const RPG_Engine_State_XMLTree_Type&, const RPG_Engine_State_XMLTree_Type&);


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
operator<< (::std::ostream&, const RPG_Engine_EntityState_XMLTree_Type&);

RPG_Engine_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Engine_Level_XMLTree_Type&);

RPG_Engine_Export
::std::ostream&
operator<< (::std::ostream&, const RPG_Engine_State_XMLTree_Type&);

#include <iosfwd>

#include <xercesc/sax/InputSource.hpp>
#include <xercesc/dom/DOMDocument.hpp>
#include <xercesc/dom/DOMErrorHandler.hpp>

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

// Parse a URI or a local file.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (const ::std::string& uri,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (const ::std::string& uri,
                ::xml_schema::error_handler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (const ::std::string& uri,
                ::xercesc::DOMErrorHandler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse std::istream.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::std::istream& is,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::std::istream& is,
                ::xml_schema::error_handler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::std::istream& is,
                ::xercesc::DOMErrorHandler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::std::istream& is,
                const ::std::string& id,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::std::istream& is,
                const ::std::string& id,
                ::xml_schema::error_handler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::std::istream& is,
                const ::std::string& id,
                ::xercesc::DOMErrorHandler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::InputSource.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::xercesc::InputSource& is,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::xercesc::InputSource& is,
                ::xml_schema::error_handler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::xercesc::InputSource& is,
                ::xercesc::DOMErrorHandler& eh,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

// Parse xercesc::DOMDocument.
//

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (const ::xercesc::DOMDocument& d,
                ::xml_schema::flags f = 0,
                const ::xml_schema::properties& p = ::xml_schema::properties ());

RPG_Engine_Export
::std::auto_ptr< ::RPG_Engine_State_XMLTree_Type >
engine_state_t (::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >& d,
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
operator<< (::xercesc::DOMElement&, const RPG_Engine_EntityState_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Engine_Level_XMLTree_Type&);

RPG_Engine_Export
void
operator<< (::xercesc::DOMElement&, const RPG_Engine_State_XMLTree_Type&);

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

// Serialize to std::ostream.
//

RPG_Engine_Export
void
engine_state_t (::std::ostream& os,
                const ::RPG_Engine_State_XMLTree_Type& x, 
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_state_t (::std::ostream& os,
                const ::RPG_Engine_State_XMLTree_Type& x, 
                ::xml_schema::error_handler& eh,
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_state_t (::std::ostream& os,
                const ::RPG_Engine_State_XMLTree_Type& x, 
                ::xercesc::DOMErrorHandler& eh,
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

// Serialize to xercesc::XMLFormatTarget.
//

RPG_Engine_Export
void
engine_state_t (::xercesc::XMLFormatTarget& ft,
                const ::RPG_Engine_State_XMLTree_Type& x, 
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_state_t (::xercesc::XMLFormatTarget& ft,
                const ::RPG_Engine_State_XMLTree_Type& x, 
                ::xml_schema::error_handler& eh,
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

RPG_Engine_Export
void
engine_state_t (::xercesc::XMLFormatTarget& ft,
                const ::RPG_Engine_State_XMLTree_Type& x, 
                ::xercesc::DOMErrorHandler& eh,
                const ::xml_schema::namespace_infomap& m = ::xml_schema::namespace_infomap (),
                const ::std::string& e = "UTF-8",
                ::xml_schema::flags f = 0);

// Serialize to an existing xercesc::DOMDocument.
//

RPG_Engine_Export
void
engine_state_t (::xercesc::DOMDocument& d,
                const ::RPG_Engine_State_XMLTree_Type& x,
                ::xml_schema::flags f = 0);

// Serialize to a new xercesc::DOMDocument.
//

RPG_Engine_Export
::xml_schema::dom::auto_ptr< ::xercesc::DOMDocument >
engine_state_t (const ::RPG_Engine_State_XMLTree_Type& x, 
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
            const RPG_Engine_EntityState_XMLTree_Type&);

RPG_Engine_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Engine_Level_XMLTree_Type&);

RPG_Engine_Export
::xml_schema::ostream< ACE_OutputCDR >&
operator<< (::xml_schema::ostream< ACE_OutputCDR >&,
            const RPG_Engine_State_XMLTree_Type&);

#include <xsd/cxx/post.hxx>

// Begin epilogue.
//
//
// End epilogue.

#endif // CXX___RPG_ENGINE_XML_TREE_H
