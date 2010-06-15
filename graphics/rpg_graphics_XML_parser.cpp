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
#include "rpg_graphics_XML_parser.h"

#include <ace/Log_Msg.h>

RPG_Graphics_Category RPG_Graphics_Category_Type::post_RPG_Graphics_Category_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Category_Type::post_RPG_Graphics_Category_Type"));

  return RPG_Graphics_CategoryHelper::stringToRPG_Graphics_Category(post_string());
}

RPG_Graphics_TileOrientation RPG_Graphics_TileOrientation_Type::post_RPG_Graphics_TileOrientation_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_TileOrientation_Type::post_RPG_Graphics_TileOrientation_Type"));

  return RPG_Graphics_TileOrientationHelper::stringToRPG_Graphics_TileOrientation(post_string());
}

RPG_Graphics_FloorTileStyle RPG_Graphics_FloorTileStyle_Type::post_RPG_Graphics_FloorTileStyle_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_FloorTileStyle_Type::post_RPG_Graphics_FloorTileStyle_Type"));

  return RPG_Graphics_FloorTileStyleHelper::stringToRPG_Graphics_FloorTileStyle(post_string());
}

RPG_Graphics_WallTileStyle RPG_Graphics_WallTileStyle_Type::post_RPG_Graphics_WallTileStyle_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_WallTileStyle_Type::post_RPG_Graphics_WallTileStyle_Type"));

  return RPG_Graphics_WallTileStyleHelper::stringToRPG_Graphics_WallTileStyle(post_string());
}

RPG_Graphics_TileStyleUnion_Type::RPG_Graphics_TileStyleUnion_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_TileStyleUnion_Type::RPG_Graphics_TileStyleUnion_Type"));

  myCurrentTileStyle.discriminator = RPG_Graphics_TileStyleUnion::INVALID;
  myCurrentTileStyle.floortilestyle = RPG_GRAPHICS_FLOORTILESTYLE_INVALID;
}

void RPG_Graphics_TileStyleUnion_Type::_characters(const ::xml_schema::ro_string& styleType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_TileStyleUnion_Type::_characters"));

  // can be either:
  // - RPG_Graphics_FloorTileStyle --> "FLOORSTYLE_xxx"
  // - RPG_Graphics_WallTileStyle --> "WALLSTYLE_xxx"
  std::string style = styleType_in;
  if (style.find(ACE_TEXT_ALWAYS_CHAR("FLOORSTYLE_")) == 0)
  {
    myCurrentTileStyle.discriminator = RPG_Graphics_TileStyleUnion::FLOORTILESTYLE;
    myCurrentTileStyle.floortilestyle = RPG_Graphics_FloorTileStyleHelper::stringToRPG_Graphics_FloorTileStyle(styleType_in);
  } // end IF
  else
  {
    myCurrentTileStyle.discriminator = RPG_Graphics_TileStyleUnion::WALLTILESTYLE;
    myCurrentTileStyle.walltilestyle = RPG_Graphics_WallTileStyleHelper::stringToRPG_Graphics_WallTileStyle(styleType_in);
  } // end ELSE
}

RPG_Graphics_TileStyleUnion RPG_Graphics_TileStyleUnion_Type::post_RPG_Graphics_TileStyleUnion_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_TileStyleUnion_Type::post_RPG_Graphics_TileStyleUnion_Type"));

  RPG_Graphics_TileStyleUnion result = myCurrentTileStyle;

  // clear structure
  myCurrentTileStyle.discriminator = RPG_Graphics_TileStyleUnion::INVALID;
  myCurrentTileStyle.floortilestyle = RPG_GRAPHICS_FLOORTILESTYLE_INVALID;

  return result;
}

RPG_Graphics_Type RPG_Graphics_Type_Type::post_RPG_Graphics_Type_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Type_Type::post_RPG_Graphics_Type_Type"));

  return RPG_Graphics_TypeHelper::stringToRPG_Graphics_Type(post_string());
}

RPG_Graphics_Graphic_Type::RPG_Graphics_Graphic_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Graphic_Type::RPG_Graphics_Graphic_Type"));

  myCurrentGraphic.category = RPG_GRAPHICS_CATEGORY_INVALID;
  myCurrentGraphic.type = RPG_GRAPHICS_TYPE_INVALID;
  myCurrentGraphic.orientation = RPG_GRAPHICS_TILEORIENTATION_MAX;
  myCurrentGraphic.style.discriminator = RPG_Graphics_TileStyleUnion::INVALID;
  myCurrentGraphic.style.floortilestyle = RPG_GRAPHICS_FLOORTILESTYLE_INVALID;
  myCurrentGraphic.file.clear();
}

void RPG_Graphics_Graphic_Type::category(const RPG_Graphics_Category& category_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Graphic_Type::category"));

  myCurrentGraphic.category = category_in;
}

void RPG_Graphics_Graphic_Type::type(const RPG_Graphics_Type& type_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Graphic_Type::type"));

  myCurrentGraphic.type = type_in;
}

void RPG_Graphics_Graphic_Type::orientation(const RPG_Graphics_TileOrientation& orientation_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Graphic_Type::orientation"));

  myCurrentGraphic.orientation = orientation_in;
}

void RPG_Graphics_Graphic_Type::style(const RPG_Graphics_TileStyleUnion& style_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Graphic_Type::style"));

  myCurrentGraphic.style = style_in;
}

void RPG_Graphics_Graphic_Type::file(const ::std::string& file_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Graphic_Type::file"));

  myCurrentGraphic.file = file_in;
}

RPG_Graphics_Graphic RPG_Graphics_Graphic_Type::post_RPG_Graphics_Graphic_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Graphic_Type::post_RPG_Graphics_Graphic_Type"));

  RPG_Graphics_Graphic result = myCurrentGraphic;

  // clear structure
  myCurrentGraphic.category = RPG_GRAPHICS_CATEGORY_INVALID;
  myCurrentGraphic.type = RPG_GRAPHICS_TYPE_INVALID;
  myCurrentGraphic.orientation = RPG_GRAPHICS_TILEORIENTATION_MAX;
  myCurrentGraphic.style.discriminator = RPG_Graphics_TileStyleUnion::INVALID;
  myCurrentGraphic.style.floortilestyle = RPG_GRAPHICS_FLOORTILESTYLE_INVALID;
  myCurrentGraphic.file.clear();

  return result;
}

RPG_Graphics_Dictionary_Type::RPG_Graphics_Dictionary_Type(RPG_Graphics_Dictionary_t* graphicsDictionary_in)
 : myDictionary(graphicsDictionary_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary_Type::RPG_Graphics_Dictionary_Type"));

}

RPG_Graphics_Dictionary_Type::~RPG_Graphics_Dictionary_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary_Type::~RPG_Graphics_Dictionary_Type"));

}

// void RPG_Graphics_Dictionary_Type::pre()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary_Type::pre"));
//
// }

void RPG_Graphics_Dictionary_Type::graphic(const RPG_Graphics_Graphic& graphic_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary_Type::graphic"));

  RPG_Graphics_t graphic = graphic_in;

  myDictionary->insert(std::make_pair(graphic.type, graphic));
}

void RPG_Graphics_Dictionary_Type::post_RPG_Graphics_Dictionary_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary_Type::post_RPG_Graphics_Dictionary_Type"));

  // debug info
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished parsing graphics dictionary, retrieved %d image(s)...\n"),
             myDictionary->size()));
}
