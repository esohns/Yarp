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
#include "stdafx.h"

#include "rpg_graphics_SDL_tools.h"

#include <ace/OS.h>
#include <ace/Log_Msg.h>

#include <SDL_syswm.h>

#include "rpg_common_macros.h"
#include "rpg_common_defines.h"

#include "rpg_graphics_defines.h"
#include "rpg_graphics_common.h"
#include "rpg_graphics_dictionary.h"
#include "rpg_graphics_surface.h"
#include "rpg_graphics_common_tools.h"

// init statics
Uint32 RPG_Graphics_SDL_Tools::CLR32_BLACK_A0   = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_BLACK_A10  = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_BLACK_A30  = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_BLACK_A50  = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_BLACK_A70  = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_BLACK_A90  = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_BLACK      = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_GREEN      = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_YELLOW     = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_ORANGE     = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_RED        = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_GRAY20     = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_GRAY20_A10 = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_GRAY70     = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_GRAY77     = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_PURPLE44   = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_LIGHTPINK  = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_LIGHTGREEN = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_BROWN      = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_WHITE      = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_BLESS_BLUE = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_CURSE_RED  = 0;
Uint32 RPG_Graphics_SDL_Tools::CLR32_GOLD_SHADE = 0;

bool
RPG_Graphics_SDL_Tools::initVideo(const RPG_Graphics_SDL_VideoConfiguration_t& configuration_in,
                                  const std::string& caption_in,
                                  SDL_Surface*& windowSurface_out,
                                  const bool& initWindow_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDL_Tools::initVideo"));

  // init return value(s)
  windowSurface_out = NULL;

  // step1: init video subsystem
  std::string video_driver = configuration_in.video_driver;
  if (video_driver.empty())
  {
    char* environment =
        ACE_OS::getenv(ACE_TEXT_ALWAYS_CHAR(RPG_GRAPHICS_SDL_VIDEO_DRIVER_ENV_VAR));
    if (environment)
      video_driver = environment;
  } // end IF
  // sanity check
  if (video_driver.empty())
  {
    video_driver = ACE_TEXT_ALWAYS_CHAR(RPG_GRAPHICS_DEF_SDL_VIDEO_DRIVER_NAME); // fallback

    ACE_DEBUG((LM_INFO,
               ACE_TEXT("using video driver: \"%s\"\n"),
               ACE_TEXT(video_driver.c_str())));
  } // end IF

  // set flags passed to SDL_StartEventLoop
  Uint32 flags = 0;
  if (SDL_VideoInit(video_driver.c_str(), // driver name
                    flags) == -1)         // flags
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_VideoInit(\"%s\", %x): \"%s\", aborting"),
               ACE_TEXT(video_driver.c_str()),
               flags,
               SDL_GetError()));

    return false;
  } // end IF

  // debug info
  SDL_SysWMinfo wm_info;
  ACE_OS::memset(&wm_info, 0, sizeof(wm_info));
  SDL_VERSION(&wm_info.version);
  if (SDL_GetWMInfo(&wm_info) <= 0)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GetWMInfo(): \"%s\", continuing"),
               SDL_GetError()));
  std::ostringstream version_number;
  version_number << wm_info.version.major;
  version_number << ACE_TEXT_ALWAYS_CHAR(".");
  version_number << wm_info.version.minor;
  version_number << ACE_TEXT_ALWAYS_CHAR(".");
  version_number << wm_info.version.patch;
#if defined(ACE_WIN32) || defined(ACE_WIN64)
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("*** wm info (SDL: %s) ***\nwindow: %d\nOpenGL context: %@\n"),
             ACE_TEXT(version_number.str().c_str()),
             wm_info.hwnd,
             wm_info.hglrc));
#else
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("*** wm info (SDL: %s) ***\nsubsystem: %d\ndisplay: %@\nwindow: %u\nfull-screen window: %u\nmanaged input window: %u\nrender display: %@\n"),
             ACE_TEXT(version_number.str().c_str()),
             wm_info.subsystem,
             wm_info.info.x11.display,
             wm_info.info.x11.window,
             wm_info.info.x11.fswindow,
             wm_info.info.x11.wmwindow,
             wm_info.info.x11.gfxdisplay));
#endif

  // step2: set window/icon caption
  SDL_WM_SetCaption(caption_in.c_str(),  // window caption
                    caption_in.c_str()); // icon caption
  // set window icon
  RPG_Graphics_GraphicTypeUnion type;
  type.discriminator = RPG_Graphics_GraphicTypeUnion::IMAGE;
  type.image = IMAGE_WM_ICON;
  RPG_Graphics_t icon_graphic = RPG_GRAPHICS_DICTIONARY_SINGLETON::instance()->get(type);
  ACE_ASSERT(icon_graphic.type.image == IMAGE_WM_ICON);
  std::string path = RPG_Graphics_Common_Tools::getGraphicsDirectory();
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  path += ACE_TEXT_ALWAYS_CHAR(RPG_GRAPHICS_TILE_DEF_IMAGES_SUB);
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  path += icon_graphic.file;
  SDL_Surface* icon_image = NULL;
  icon_image = RPG_Graphics_Surface::load(path,   // graphics file
                                          false); // don't convert to display format (no screen yet !)
  if (!icon_image)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Common_Tools::loadFile(\"%s\"), aborting\n"),
               ACE_TEXT(path.c_str())));

    return false;
  } // end IF
  SDL_WM_SetIcon(icon_image, // surface
                 NULL);      // mask (--> everything)

  // step3: init screen
  if (initWindow_in)
  {
    windowSurface_out = RPG_Graphics_SDL_Tools::initScreen(configuration_in);
    if (!windowSurface_out)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to RPG_Graphics_SDL_Tools::initScreen(%d,%d,%d), aborting\n"),
                 configuration_in.screen_width,
                 configuration_in.screen_height,
                 configuration_in.screen_colordepth));

      return false;
    } // end IF
  } // end IF

  return true;
}

SDL_Surface*
RPG_Graphics_SDL_Tools::initScreen(const RPG_Graphics_SDL_VideoConfiguration_t& configuration_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDL_Tools::initScreen"));

  // init return value
  SDL_Surface* result = NULL;

  // sanity check
  char driver[RPG_COMMON_BUFSIZE];
  if (!SDL_VideoDriverName(driver,
                           sizeof(driver)))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_VideoDriverName(): \"%s\", aborting\n"),
               SDL_GetError()));

    return result;
  } // end IF

  // retrieve/list "best" available video mode
  const SDL_VideoInfo* videoInfo = NULL;
  videoInfo = SDL_GetVideoInfo();
  ACE_ASSERT(videoInfo);
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("*** video capabilities (driver: \"%s\") ***\nhardware surfaces:\t\t\t\t\t\"%s\"\nwindow manager:\t\t\t\t\t\t\"%s\"\nhardware to hardware blits accelerated:\t\t\t\"%s\"\nhardware to hardware colorkey blits accelerated:\t\"%s\"\nhardware to hardware alpha blits accelerated:\t\t\"%s\"\nsoftware to hardware blits accelerated:\t\t\t\"%s\"\nsoftware to hardware colorkey blits accelerated:\t\"%s\"\nsoftware to hardware alpha blits accelerated:\t\t\"%s\"\ncolor fills accelerated:\t\t\t\t\"%s\"\nvideo memory:\t\t\t\t\t\t%d kBytes\n*** (suggested) video mode ***\npalette:\t\t%@\nbits[bytes]/pixel:\t%d[%d]\nmask[RGBA]:\t\t%x %x %x %x\nshift[RGBA]:\t\t%d %d %d %d\nloss[RGBA]:\t\t%d %d %d %d\ntransparent colorkey:\t%d\noverall surface alpha:\t%d\n"),
             driver,
             (videoInfo->hw_available ? ACE_TEXT("yes") : ACE_TEXT("no")),
             (videoInfo->wm_available ? ACE_TEXT("yes") : ACE_TEXT("no")),
             (videoInfo->blit_hw      ? ACE_TEXT("yes") : ACE_TEXT("no")),
             (videoInfo->blit_hw_CC   ? ACE_TEXT("yes") : ACE_TEXT("no")),
             (videoInfo->blit_hw_A    ? ACE_TEXT("yes") : ACE_TEXT("no")),
             (videoInfo->blit_sw      ? ACE_TEXT("yes") : ACE_TEXT("no")),
             (videoInfo->blit_sw_CC   ? ACE_TEXT("yes") : ACE_TEXT("no")),
             (videoInfo->blit_sw_A    ? ACE_TEXT("yes") : ACE_TEXT("no")),
             (videoInfo->blit_fill    ? ACE_TEXT("yes") : ACE_TEXT("no")),
             videoInfo->video_mem,
             videoInfo->vfmt->palette,
             videoInfo->vfmt->BitsPerPixel,
             videoInfo->vfmt->BytesPerPixel,
             videoInfo->vfmt->Rmask, videoInfo->vfmt->Gmask, videoInfo->vfmt->Bmask, videoInfo->vfmt->Amask,
             videoInfo->vfmt->Rshift, videoInfo->vfmt->Gshift, videoInfo->vfmt->Bshift, videoInfo->vfmt->Ashift,
             videoInfo->vfmt->Rloss, videoInfo->vfmt->Gloss, videoInfo->vfmt->Bloss, videoInfo->vfmt->Aloss,
             videoInfo->vfmt->colorkey,
             static_cast<int>(videoInfo->vfmt->alpha)));

  // set surface flags
  RPG_Graphics_Surface::SDL_surface_flags =
      ((videoInfo->hw_available ? SDL_HWSURFACE : SDL_SWSURFACE) |
       SDL_SRCCOLORKEY | // "This flag turns on color keying for blits from this surface.
                         // ...Use SDL_SetColorKey to set or clear this flag after surface creation."
       SDL_SRCALPHA);    // "This flag turns on alpha-blending for blits from this surface.
                         // ...Use SDL_SetAlpha to set or clear this flag after surface creation."
  Uint32 SDL_surface_flags =
      ((videoInfo->hw_available ? SDL_HWSURFACE : SDL_SWSURFACE) |
       SDL_ASYNCBLIT | // "...will usually slow down blitting on single CPU machines,
                       //  but may provide a speed increase on SMP systems..."
       SDL_ANYFORMAT | // "...Allow any video depth/pixel-format..."
       SDL_HWPALETTE | // "...Surface has exclusive palette..."
       (configuration_in.double_buffer ? SDL_DOUBLEBUF                  : 0) |
       (configuration_in.use_OpenGL    ? (SDL_OPENGL | SDL_OPENGLBLIT)  : 0) |
       (configuration_in.full_screen   ? (SDL_FULLSCREEN | SDL_NOFRAME) : SDL_RESIZABLE));
  // get available fullscreen/hardware/... modes
  SDL_Rect** modes = NULL;
  modes = SDL_ListModes(NULL,               // use same as videoInfo
                        SDL_surface_flags); // surface flags
  // --> any valid modes available ?
  if (modes == NULL)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("no available resolutions (flags: 0x%x) --> change settings, aborting\n"),
               SDL_surface_flags));

    return NULL;
  } // end IF
  else if (modes == reinterpret_cast<SDL_Rect**>(-1))
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("all resolutions available (flags: 0x%x)...\n"),
               SDL_surface_flags));
  }
  else
  {
    // print valid modes
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("*** available resolutions (flags: 0x%x) ***\n"),
               SDL_surface_flags));
    for (unsigned int i = 0;
         modes[i];
         i++)
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("[%d]: %d x %d\n"),
                 i + 1,
                 modes[i]->w,
                 modes[i]->h));
  } // end ELSE

  // check to see whether the requested mode is possible
  int suggested_bpp = SDL_VideoModeOK(configuration_in.screen_width,
                                      configuration_in.screen_height,
                                      configuration_in.screen_colordepth,
                                      SDL_surface_flags);
  switch (suggested_bpp)
  {
    case 0:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("requested mode (width: %d, height: %d, depth: %d, flags: 0x%x) not supported --> change settings, aborting\n"),
                 configuration_in.screen_width,
                 configuration_in.screen_height,
                 configuration_in.screen_colordepth,
                 SDL_surface_flags));

      return NULL;
    }
    default:
    {
      if (suggested_bpp != configuration_in.screen_colordepth)
      {
        ACE_DEBUG((LM_WARNING,
                   ACE_TEXT("using suggested color depth: %d...\n"),
                   suggested_bpp));
      } // end IF

      break;
    }
  } // end SWITCH

  // open SDL window
  SDL_Surface* screen = NULL;
  screen = SDL_SetVideoMode(configuration_in.screen_width,
                            configuration_in.screen_height,
                            suggested_bpp,
                            SDL_surface_flags);
  if (!screen)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetVideoMode(%d, %d, %d, 0x%x): \"%s\", aborting\n"),
               configuration_in.screen_width,
               configuration_in.screen_height,
               suggested_bpp,
               SDL_surface_flags,
               SDL_GetError()));

    return NULL;
  } // end IF

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("*** screen flags ***\nsurface:\t\t\t\t%sRAM\nasynch blits:\t\t\t\t\"%s\"\nany video depth/pixel-format:\t\t\"%s\"\nsurface has exclusive palette:\t\t\"%s\"\ndouble-buffered:\t\t\t\"%s\"\nblit uses hardware acceleration:\t\"%s\"\nblit uses a source color key:\t\t\"%s\"\nsurface is RLE encoded:\t\t\t\"%s\"\nblit uses source alpha blending:\t\"%s\"\nsurface uses preallocated memory:\t\"%s\"\n"),
             ((screen->flags & SDL_HWSURFACE)   ? ACE_TEXT("Video") : ACE_TEXT("")),
             ((screen->flags & SDL_ASYNCBLIT)   ? ACE_TEXT("yes")   : ACE_TEXT("no")),
             ((screen->flags & SDL_ANYFORMAT)   ? ACE_TEXT("yes")   : ACE_TEXT("no")),
             ((screen->flags & SDL_HWPALETTE)   ? ACE_TEXT("yes")   : ACE_TEXT("no")),
             ((screen->flags & SDL_DOUBLEBUF)   ? ACE_TEXT("yes")   : ACE_TEXT("no")),
             ((screen->flags & SDL_HWACCEL)     ? ACE_TEXT("yes")   : ACE_TEXT("no")),
             ((screen->flags & SDL_SRCCOLORKEY) ? ACE_TEXT("yes")   : ACE_TEXT("no")),
             ((screen->flags & SDL_RLEACCEL)    ? ACE_TEXT("yes")   : ACE_TEXT("no")),
             ((screen->flags & SDL_SRCALPHA)    ? ACE_TEXT("yes")   : ACE_TEXT("no")),
             ((screen->flags & SDL_PREALLOC)    ? ACE_TEXT("yes")   : ACE_TEXT("no"))));

  return screen;
}

std::string
RPG_Graphics_SDL_Tools::keyToString(const SDL_keysym& key_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDL_Tools::keyToString"));

  std::string result;

  char buffer[RPG_GRAPHICS_SDL_KEYSYM_BUFFER_SIZE];
  result += ACE_TEXT("scancode: ");
  ACE_OS::sprintf(buffer,
                  ACE_TEXT_ALWAYS_CHAR("0x%02X"),
                  key_in.scancode);
  result += buffer;
  result += ACE_TEXT_ALWAYS_CHAR("\n");
  result += ACE_TEXT("name: \"");
  result += SDL_GetKeyName(key_in.sym);
  result += ACE_TEXT_ALWAYS_CHAR("\"\n");
  result += ACE_TEXT("unicode: ");
  ACE_OS::sprintf(buffer,
                  ACE_TEXT_ALWAYS_CHAR("0x%04X"),
                  key_in.unicode);
  result += buffer;
  result += ACE_TEXT_ALWAYS_CHAR("\n");
  result += ACE_TEXT("modifier(s): ");
  if (key_in.mod == KMOD_NONE)
    result += ACE_TEXT("N/A");
  else
  {
    if (key_in.mod & KMOD_NUM)
      result += ACE_TEXT("NUMLOCK ");
    if (key_in.mod & KMOD_CAPS)
      result += ACE_TEXT("CAPSLOCK ");
    if (key_in.mod & KMOD_LCTRL)
      result += ACE_TEXT("LCTRL ");
    if (key_in.mod & KMOD_RCTRL)
      result += ACE_TEXT("RCTRL ");
    if (key_in.mod & KMOD_LSHIFT)
      result += ACE_TEXT("LSHIFT ");
    if (key_in.mod & KMOD_RSHIFT)
      result += ACE_TEXT("RSHIFT ");
    if (key_in.mod & KMOD_LALT)
      result += ACE_TEXT("LALT ");
    if (key_in.mod & KMOD_RALT)
      result += ACE_TEXT("RALT ");
//     if (key_in.mod & KMOD_CTRL)
//       result += ACE_TEXT("CTRL ");
//     if (key_in.mod & KMOD_SHIFT)
//       result += ACE_TEXT("SHIFT ");
//     if (key_in.mod & KMOD_ALT)
//       result += ACE_TEXT("ALT ");
  } // end ELSE

  return result;
}

SDL_Color
RPG_Graphics_SDL_Tools::colorToSDLColor(const Uint32& color_in,
                                        const SDL_Surface& targetSurface_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDL_Tools::colorToSDLColor"));

  // init return value
  SDL_Color result;
  ACE_OS::memset(&result, 0, sizeof(result));

  // extract components from the 32-bit color value
  result.r = (color_in & targetSurface_in.format->Rmask) >> targetSurface_in.format->Rshift;
  result.g = (color_in & targetSurface_in.format->Gmask) >> targetSurface_in.format->Gshift;
  result.b = (color_in & targetSurface_in.format->Bmask) >> targetSurface_in.format->Bshift;
  result.unused = 0;

  return result;
}

void
RPG_Graphics_SDL_Tools::initColors()
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDL_Tools::initColors"));

  // set up the colors used in the game
  // *NOTE*: the only way to do this without needing graphics to have been loaded first
  // is to manually create a surface and put it into display format + alpha
  SDL_Surface* dummy = NULL;
  dummy = SDL_CreateRGBSurface(RPG_Graphics_Surface::SDL_surface_flags,
                               1, // dummy
                               1, // dummy
                               32,
                               ((SDL_BYTEORDER == SDL_LIL_ENDIAN) ? 0x000000FF : 0xFF000000),
                               ((SDL_BYTEORDER == SDL_LIL_ENDIAN) ? 0x0000FF00 : 0x00FF0000),
                               ((SDL_BYTEORDER == SDL_LIL_ENDIAN) ? 0x00FF0000 : 0x0000FF00),
                               ((SDL_BYTEORDER == SDL_LIL_ENDIAN) ? 0xFF000000 : 0x000000FF));
  if (!dummy)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_CreateRGBSurface(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  SDL_Surface* dummy_converted = NULL;
  dummy_converted = SDL_DisplayFormatAlpha(dummy);
  if (!dummy_converted)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_DisplayFormatAlpha(): %s, aborting\n"),
               SDL_GetError()));

    // clean up
    SDL_FreeSurface(dummy);

    return;
  } // end IF

  // clean up
  SDL_FreeSurface(dummy);

//   SDL_PixelFormat* pixelFormat = NULL;
//   try
//   {
//     pixelFormat = new SDL_PixelFormat;
//   }
//   catch (...)
//   {
//     ACE_DEBUG((LM_ERROR,
//                ACE_TEXT("failed to allocate memory(%u): %m, aborting\n"),
//                sizeof(SDL_PixelFormat)));
//
//     // clean up
//     SDL_FreeSurface(dummy_converted);
//
//     return;
//   }
//   if (!pixelFormat)
//   {
//     ACE_DEBUG((LM_ERROR,
//                ACE_TEXT("failed to allocate memory(%u): %m, aborting\n"),
//                sizeof(SDL_PixelFormat)));
//
//     // clean up
//     SDL_FreeSurface(dummy_converted);
//
//     return;
//   } // end IF
//   ACE_OS::memcpy(pixelFormat,
//                  dummy_converted->format,
//                  sizeof(SDL_PixelFormat));

  // *TODO*: import this from a (XML-)definition file
  CLR32_BLACK_A0   = SDL_MapRGBA(dummy_converted->format, 0, 0, 0, 0);
  CLR32_BLACK_A10  = SDL_MapRGBA(dummy_converted->format, 0, 0, 0, 0x1a);
  CLR32_BLACK_A30  = SDL_MapRGBA(dummy_converted->format, 0, 0, 0, 0x4d);
  CLR32_BLACK_A50  = SDL_MapRGBA(dummy_converted->format, 0, 0, 0, 0x80);
  CLR32_BLACK_A70  = SDL_MapRGBA(dummy_converted->format, 0, 0, 0, 0xb3);
  CLR32_BLACK_A90  = SDL_MapRGBA(dummy_converted->format, 0, 0, 0, 0xe7);
  CLR32_BLACK      = SDL_MapRGBA(dummy_converted->format, 0, 0, 0, 0xff);
  CLR32_GREEN      = SDL_MapRGBA(dummy_converted->format, 0x57, 0xff, 0x57, 0xff);
  CLR32_YELLOW     = SDL_MapRGBA(dummy_converted->format, 0xff, 0xff, 0x57, 0xff);
  CLR32_ORANGE     = SDL_MapRGBA(dummy_converted->format, 0xff, 0xc7, 0x3b, 0xff);
  CLR32_RED        = SDL_MapRGBA(dummy_converted->format, 0xff, 0x23, 0x07, 0xff);
  CLR32_GRAY20     = SDL_MapRGBA(dummy_converted->format, 0xb7, 0xab, 0xab, 0xff);
  CLR32_GRAY20_A10 = SDL_MapRGBA(dummy_converted->format, 0xb7, 0xab, 0xab, 0x1a);
  CLR32_GRAY70     = SDL_MapRGBA(dummy_converted->format, 0x53, 0x53, 0x53, 0xff);
  CLR32_GRAY77     = SDL_MapRGBA(dummy_converted->format, 0x43, 0x3b, 0x3b, 0xff);
  CLR32_PURPLE44   = SDL_MapRGBA(dummy_converted->format, 0x4f, 0x43, 0x6f, 0xff);
  CLR32_LIGHTPINK  = SDL_MapRGBA(dummy_converted->format, 0xcf, 0xbb, 0xd3, 0xff);
  CLR32_LIGHTGREEN = SDL_MapRGBA(dummy_converted->format, 0xaa, 0xff, 0xcc, 0xff);
  CLR32_BROWN      = SDL_MapRGBA(dummy_converted->format, 0x9b, 0x6f, 0x57, 0xff);
  CLR32_WHITE      = SDL_MapRGBA(dummy_converted->format, 0xff, 0xff, 0xff, 0xff);
  CLR32_BLESS_BLUE = SDL_MapRGBA(dummy_converted->format, 0x96, 0xdc, 0xfe, 0x60);
  CLR32_CURSE_RED  = SDL_MapRGBA(dummy_converted->format, 0x60, 0x00, 0x00, 0x50);
  CLR32_GOLD_SHADE = SDL_MapRGBA(dummy_converted->format, 0xf0, 0xe0, 0x57, 0x40);

  // clean up
  SDL_FreeSurface(dummy_converted);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("RPG_Graphics_SDL_Tools: initialized colors...\n")));
}

SDL_Rect
RPG_Graphics_SDL_Tools::boundingBox(const SDL_Rect& rect1_in,
                                    const SDL_Rect& rect2_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDL_Tools::boundingBox"));

  // init result
  SDL_Rect result;
  ACE_OS::memset(&result, 0, sizeof(SDL_Rect));

  result.x = static_cast<int16_t>((rect1_in.x < rect2_in.x) ? rect1_in.x : rect2_in.x);
  result.y = static_cast<int16_t>((rect1_in.y < rect2_in.y) ? rect1_in.y : rect2_in.y);
  result.w = static_cast<uint16_t>((((rect1_in.x + rect1_in.w) > (rect2_in.x + rect2_in.w)) ? (rect1_in.x + rect1_in.w - 1) : (rect2_in.x + rect2_in.w - 1)) - result.x) + 1;
  result.h = static_cast<uint16_t>((((rect1_in.y + rect1_in.h) > (rect2_in.y + rect2_in.h)) ? (rect1_in.y + rect1_in.h - 1) : (rect2_in.y + rect2_in.h - 1)) - result.y) + 1;

  return result;
}

SDL_Rect
RPG_Graphics_SDL_Tools::intersect(const SDL_Rect& rect1_in,
                                  const SDL_Rect& rect2_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDL_Tools::intersect"));

  // init result
  SDL_Rect result;
  ACE_OS::memset(&result, 0, sizeof(SDL_Rect));

  // test for intersection first
  if ((((rect1_in.x >= rect2_in.x) && (rect1_in.x <= (rect2_in.x + rect2_in.w))) ||
       ((rect2_in.x >= rect1_in.x) && (rect2_in.x <= (rect1_in.x + rect1_in.w)))) &&
      (((rect1_in.y >= rect2_in.y) && (rect1_in.y <= (rect2_in.y + rect2_in.h))) ||
       ((rect2_in.y >= rect1_in.y) && (rect2_in.y <= (rect1_in.y + rect1_in.h)))))
  {
    // compute overlap
    result.x = static_cast<int16_t>((rect1_in.x > rect2_in.x) ? rect1_in.x : rect2_in.x);
    result.y = static_cast<int16_t>((rect1_in.y > rect2_in.y) ? rect1_in.y : rect2_in.y);
    result.w = static_cast<uint16_t>((((rect1_in.x + rect1_in.w) < (rect2_in.x + rect2_in.w)) ? (rect1_in.x + rect1_in.w - 1) : (rect2_in.x + rect2_in.w - 1)) - result.x) + 1;
    result.h = static_cast<uint16_t>((((rect1_in.y + rect1_in.h) < (rect2_in.y + rect2_in.h)) ? (rect1_in.y + rect1_in.h - 1) : (rect2_in.y + rect2_in.h - 1)) - result.y) + 1;
  } // end IF

  return result;
}
