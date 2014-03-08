/***************************************************************************
 *   Copyright (C) 2010 by Erik Sohns   *
 *   erik.sohns@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#ifndef RPG_CLIENT_ENTITY_MANAGER_H
#define RPG_CLIENT_ENTITY_MANAGER_H

#include "rpg_client_exports.h"
#include "rpg_client_engine.h"

#include "rpg_engine_common.h"

#include "rpg_graphics_common.h"
#include "rpg_graphics_iwindow.h"

#include <SDL.h>

#include <ace/Global_Macros.h>
#include <ace/Singleton.h>
#include <ace/Synch.h>

#include <map>

/**
  @author Erik Sohns <erik.sohns@web.de>
 */
class RPG_Client_Export RPG_Client_Entity_Manager
{
  // singleton requires access to the ctor/dtor
  friend class ACE_Singleton<RPG_Client_Entity_Manager,
                             ACE_Recursive_Thread_Mutex>;

 public:
  // init (clipping)
  void init(RPG_Client_Engine*,     // client engine handle
            RPG_Graphics_IWindow*); // (target) window handle

  // manage entities
  void add(const RPG_Engine_EntityID_t&, // id
           SDL_Surface*,                 // graphic handle
           const bool& = false);         // free on remove() ?
  void remove(const RPG_Engine_EntityID_t&, // id
              SDL_Rect&);                   // return value: "dirty" region
  bool cached(const RPG_Engine_EntityID_t&) const; // id

  // draw the entity
  void put(const RPG_Engine_EntityID_t&,   // id
           const RPG_Graphics_Position_t&, // target tile (screen coordinates !)
           SDL_Rect&);                     // return value: "dirty" region

  // clear the stored BG
  void invalidateBG(const RPG_Engine_EntityID_t&); // id

 private:
  virtual ~RPG_Client_Entity_Manager();
  RPG_Client_Entity_Manager();
  ACE_UNIMPLEMENTED_FUNC(RPG_Client_Entity_Manager(const RPG_Client_Entity_Manager&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Client_Entity_Manager& operator=(const RPG_Client_Entity_Manager&));

  // helper types
  struct RPG_Client_EntityCacheEntry_t
  {
    SDL_Surface*            graphic;
    bool                    free_on_remove;
    SDL_Surface*            bg;
    RPG_Graphics_Position_t bg_position;
  };
  typedef std::map<RPG_Engine_EntityID_t, RPG_Client_EntityCacheEntry_t> RPG_Client_EntityCache_t;
  typedef RPG_Client_EntityCache_t::iterator RPG_Client_EntityCacheIterator_t;
  typedef RPG_Client_EntityCache_t::const_iterator RPG_Client_EntityCacheConstIterator_t;

  // helper methods
  // restore the BG
  void restoreBG(const RPG_Engine_EntityID_t&, // id
                 SDL_Rect&);                   // return value: "dirty" region

  RPG_Client_Engine*       myClient;
  RPG_Graphics_IWindow*    myWindow;
  RPG_Client_EntityCache_t myCache;
};

typedef ACE_Singleton<RPG_Client_Entity_Manager,
                      ACE_Recursive_Thread_Mutex> RPG_CLIENT_ENTITY_MANAGER_SINGLETON;
RPG_CLIENT_SINGLETON_DECLARE(ACE_Singleton,
                             RPG_Client_Entity_Manager,
                             ACE_Recursive_Thread_Mutex);
#endif
