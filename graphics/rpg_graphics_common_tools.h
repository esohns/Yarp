/***************************************************************************
 *   Copyright (C) 2009 by Erik Sohns   *
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
#ifndef RPG_GRAPHICS_COMMON_TOOLS_H
#define RPG_GRAPHICS_COMMON_TOOLS_H

#include "rpg_graphics_incl.h"
#include "rpg_graphics_common.h"

#include <png.h>

#include <ace/Global_Macros.h>
#include <ace/Synch.h>

#include <string>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Graphics_Common_Tools
{
 public:
  // init string conversion facilities
  static void initStringConversionTables();
  // *WARNING*: needs to be called AFTER SDL_SetVideoMode !
  static void init(const std::string&,      // graphics directory
                   const unsigned long&);   // cache size
  static void fini();
  static const std::string styleToString(const RPG_Graphics_StyleUnion&);
  static const std::string tileToString(const RPG_Graphics_Tile&);
  static const std::string tileSetToString(const RPG_Graphics_TileSet&);
  static const std::string elementTypeToString(const RPG_Graphics_ElementTypeUnion&);
  static const std::string elementsToString(const RPG_Graphics_Elements_t&);

  static const RPG_Graphics_TextSize_t textSize(const RPG_Graphics_Type&, // font
                                                const std::string&);      // string

  // *NOTE*: tileset needs to be SDL_FreeSurface()ed by the user !
  static void loadFloorTileSet(const RPG_Graphics_FloorStyle&, // style
                               RPG_Graphics_FloorTileSet_t&);  // return value: tileset
  // *NOTE*: tileset needs to be SDL_FreeSurface()ed by the user !
  static void loadWallTileSet(const RPG_Graphics_WallStyle&, // style
                              RPG_Graphics_WallTileSet_t&);  // return value: tileset
    // *NOTE*: tileset needs to be SDL_FreeSurface()ed by the user !
  static void loadDoorTileSet(const RPG_Graphics_DoorStyle&, // style
                              RPG_Graphics_DoorTileSet_t&);  // return value: tileset
  // *NOTE*: uncached (!) surfaces need to be SDL_FreeSurface()ed by the user !
  static SDL_Surface* loadGraphic(const RPG_Graphics_Type&, // graphic
                                  const bool& = true);      // cache graphic ?
  // *NOTE*: results need to be SDL_FreeSurface()ed by the user !
  // *WARNING*: display format is not available UNTIL AFTER SDL_SetVideoMode !
  static SDL_Surface* loadFile(const std::string&,  // image file
                               const bool& = true); // convert to display format ?

  static SDL_Surface* get(const unsigned long&, // offset x (top-left == 0,0)
                          const unsigned long&, // offset y (top-left == 0,0)
                          const unsigned long&, // width
                          const unsigned long&, // height
                          const SDL_Surface&);  // image
  static void put(const unsigned long&, // offset x (top left == 0,0)
                  const unsigned long&, // offset y (top left == 0,0)
                  const SDL_Surface&,   // image
                  SDL_Surface*);        // target surface (screen)
  static void putText(const RPG_Graphics_Type&, // font
                      const std::string&,       // string
                      const SDL_Color&,         // color
                      const bool&,              // shade ?
                      const SDL_Color&,         // shade color
                      const unsigned long&,     // offset x (top left == 0,0)
                      const unsigned long&,     // offset y (top left == 0,0)
                      SDL_Surface*);            // target surface (screen)

  // *NOTE*: source/target image must already be loaded into the framebuffer !
  static void fade(const bool&,   // fade in ? (else out)
                   const float&,  // interval (seconds)
                   const Uint32&, // fade to/from color
                   SDL_Surface*); // screen

  static void savePNG(const SDL_Surface&, // image
                      const std::string&, // file
                      const bool&);       // with alpha ?

 private:
  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_Common_Tools());
  ACE_UNIMPLEMENTED_FUNC(~RPG_Graphics_Common_Tools());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_Common_Tools(const RPG_Graphics_Common_Tools&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_Common_Tools& operator=(const RPG_Graphics_Common_Tools&));

  // helper methods
  static const bool initFonts();
  static const bool initWallBlend();

  // convert style (wall-, floor-, ...) to appropriate graphic metatype
  static const RPG_Graphics_Type styleToType(const RPG_Graphics_StyleUnion&);

  static const bool loadPNG(const unsigned char*, // source buffer
//                             const unsigned char&, // alpha (0: transparent --> 255: opaque)
                            SDL_Surface*&);       // return value: SDL surface

  static SDL_Surface* renderText(const RPG_Graphics_Type&, // font
                                 const std::string&,       // string
                                 const SDL_Color&);        // color

  static void blend(const SDL_Surface&, // source image
                    SDL_Surface*);      // target image
  // *NOTE*: results need to be SDL_FreeSurface()ed by the user !
  static SDL_Surface* shade(const SDL_Surface&,               // source image
                            const Uint8& = SDL_ALPHA_OPAQUE); // alpha (0: transparent --> 255: opaque)

  static void fade(const float&,  // interval (seconds)
                   SDL_Surface*,  // target image
                   SDL_Surface*); // screen

  static std::string                  myGraphicsDirectory;

  static ACE_Thread_Mutex             myCacheLock;

  static unsigned long                myOldestCacheEntry;
  static unsigned long                myCacheSize;
  static RPG_Graphics_GraphicsCache_t myGraphicsCache;

  static SDL_Surface*                 myWallBlend;

  static RPG_Graphics_FontCache_t     myFontCache;

  static bool                         myInitialized;
};

#endif