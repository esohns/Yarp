
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_ELEMENT_H
#define RPG_GRAPHICS_ELEMENT_H

#include "rpg_graphics_exports.h"

struct RPG_Graphics_Export RPG_Graphics_Element
{
  RPG_Graphics_ElementTypeUnion type;
  RPG_Graphics_WindowType window;
  unsigned int offsetX;
  unsigned int offsetY;
  unsigned int width;
  unsigned int height;
};

#endif
