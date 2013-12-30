
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_ELEMENTTYPEUNION_H
#define RPG_GRAPHICS_ELEMENTTYPEUNION_H

#include "rpg_graphics_exports.h"

struct RPG_Graphics_Export RPG_Graphics_ElementTypeUnion
{
  union
  {
    RPG_Graphics_InterfaceElementType interfaceelementtype;
    RPG_Graphics_HotspotType hotspottype;
  };

  enum Discriminator_t
  {
    INTERFACEELEMENTTYPE,
    HOTSPOTTYPE,
    INVALID
  };
  Discriminator_t discriminator;
};

#endif
