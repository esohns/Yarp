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
#ifndef RPG_GRAPHICS_XML_PARSER_H
#define RPG_GRAPHICS_XML_PARSER_H

#include "rpg_graphics_XML_types.h"
#include "rpg_graphics_common.h"

#include <ace/Global_Macros.h>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Graphics_Category_Type
 : public RPG_Graphics_Category_Type_pskel,
   public ::xml_schema::string_pimpl
{
 public:
//   virtual void pre();
  virtual RPG_Graphics_Category post_RPG_Graphics_Category_Type();
};

class RPG_Graphics_TileOrientation_Type
 : public RPG_Graphics_TileOrientation_Type_pskel,
   public ::xml_schema::string_pimpl
{
 public:
//   virtual void pre();
  virtual RPG_Graphics_TileOrientation post_RPG_Graphics_TileOrientation_Type();
};

class RPG_Graphics_FloorStyle_Type
 : public RPG_Graphics_FloorStyle_Type_pskel,
   public ::xml_schema::string_pimpl
{
 public:
//   virtual void pre();
  virtual RPG_Graphics_FloorStyle post_RPG_Graphics_FloorStyle_Type();
};

class RPG_Graphics_StairsStyle_Type
 : public RPG_Graphics_StairsStyle_Type_pskel,
   public ::xml_schema::string_pimpl
{
  public:
//   virtual void pre();
    virtual RPG_Graphics_StairsStyle post_RPG_Graphics_StairsStyle_Type();
};

class RPG_Graphics_WallStyle_Type
 : public RPG_Graphics_WallStyle_Type_pskel,
   public ::xml_schema::string_pimpl
{
 public:
//   virtual void pre();
  virtual RPG_Graphics_WallStyle post_RPG_Graphics_WallStyle_Type();
};

class RPG_Graphics_DoorStyle_Type
 : public RPG_Graphics_DoorStyle_Type_pskel,
   public ::xml_schema::string_pimpl
{
  public:
//   virtual void pre();
    virtual RPG_Graphics_DoorStyle post_RPG_Graphics_DoorStyle_Type();
};

class RPG_Graphics_StyleUnion_Type
 : public RPG_Graphics_StyleUnion_Type_pskel
{
 public:
  RPG_Graphics_StyleUnion_Type();

//   virtual void pre();
  virtual void _characters(const ::xml_schema::ro_string&);
  virtual RPG_Graphics_StyleUnion post_RPG_Graphics_StyleUnion_Type();

 private:
  RPG_Graphics_StyleUnion myCurrentStyle;
};

class RPG_Graphics_Type_Type
 : public RPG_Graphics_Type_Type_pskel,
   public ::xml_schema::string_pimpl
{
 public:
//   virtual void pre();
  virtual RPG_Graphics_Type post_RPG_Graphics_Type_Type();
};

class RPG_Graphics_Graphic_Type
 : public RPG_Graphics_Graphic_Type_pskel
{
 public:
  RPG_Graphics_Graphic_Type();

//     virtual void pre();
  virtual void category(const RPG_Graphics_Category&);
  virtual void type(const RPG_Graphics_Type&);
  virtual void orientation(const RPG_Graphics_TileOrientation&);
  virtual void style(const RPG_Graphics_StyleUnion&);
  virtual void file(const ::std::string&);
  virtual RPG_Graphics_Graphic post_RPG_Graphics_Graphic_Type();

 private:
  RPG_Graphics_Graphic myCurrentGraphic;
};

class RPG_Graphics_Dictionary_Type
 : public RPG_Graphics_Dictionary_Type_pskel
{
 public:
  RPG_Graphics_Dictionary_Type(RPG_Graphics_Dictionary_t*); // graphics dictionary
  virtual ~RPG_Graphics_Dictionary_Type();

//   virtual void pre();
  virtual void graphic(const RPG_Graphics_Graphic&);
  virtual void post_RPG_Graphics_Dictionary_Type();

 private:
  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_Dictionary_Type());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_Dictionary_Type(const RPG_Graphics_Dictionary_Type&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_Dictionary_Type& operator=(const RPG_Graphics_Dictionary_Type&));

  RPG_Graphics_Dictionary_t* myDictionary;
};

#endif
