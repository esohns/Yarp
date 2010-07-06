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
#include "rpg_graphics_dictionary.h"

#include "rpg_graphics_XML_parser.h"
#include "rpg_graphics_common_tools.h"

#include <ace/Log_Msg.h>

#include <string>
#include <sstream>

RPG_Graphics_Dictionary::RPG_Graphics_Dictionary()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary::RPG_Graphics_Dictionary"));

}

RPG_Graphics_Dictionary::~RPG_Graphics_Dictionary()
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary::~RPG_Graphics_Dictionary"));

}

void
RPG_Graphics_Dictionary::init(const std::string& filename_in,
                              const bool& validateXML_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary::init"));

  // Construct the parser.
  //

  RPG_Graphics_Category_Type                  category_p;
  RPG_Graphics_Type_Type                      type_p;
  RPG_Graphics_Tile_Type                      tile_p;
  RPG_Graphics_TileType_Type                  tileType_p;
  RPG_Graphics_StyleUnion_Type                style_p;
  RPG_Graphics_Orientation_Type               orientation_p;
  ::xml_schema::string_pimpl                  string_p;
  ::xml_schema::unsigned_int_pimpl            unsigned_int_p;
  ::xml_schema::boolean_pimpl                 bool_p;
  tile_p.parsers(tileType_p,
                 style_p,
                 orientation_p,
                 string_p,
                 unsigned_int_p,
                 unsigned_int_p,
                 bool_p,
                 bool_p);
  RPG_Graphics_TileSetType_Type               tileSetType_p;
  RPG_Graphics_TileSet_Type                   tileSet_p;
  tileSet_p.parsers(tileSetType_p,
                    style_p,
                    tile_p,
                    bool_p);
  RPG_Graphics_ElementTypeUnion_Type          elementType_p;
  RPG_Graphics_Element_Type                   element_p;
  element_p.parsers(elementType_p,
                    unsigned_int_p,
                    unsigned_int_p,
                    unsigned_int_p,
                    unsigned_int_p);
  RPG_Graphics_Graphic_Type                   graphic_p;
  graphic_p.parsers(category_p,
                    type_p,
                    tile_p,
                    tileSet_p,
                    element_p,
                    string_p,
                    unsigned_int_p);

  RPG_Graphics_Dictionary_Type                dictionary_p(&myDictionary);
  dictionary_p.parsers(graphic_p);

  // Parse the document to obtain the object model.
  //
  ::xml_schema::document doc_p(dictionary_p,
                               ACE_TEXT_ALWAYS_CHAR("urn:rpg"),
                               ACE_TEXT_ALWAYS_CHAR("graphicsDictionary"));

  dictionary_p.pre();

  // OK: parse the file...
  ::xml_schema::flags flags;
  if (!validateXML_in)
    flags = flags | ::xml_schema::flags::dont_validate;
  try
  {
    doc_p.parse(filename_in,
                myXSDErrorHandler,
                flags);
  }
  catch (const ::xml_schema::parsing& exception)
  {
    std::ostringstream converter;
    converter << exception;
    std::string text = converter.str();
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("RPG_Graphics_Dictionary::init(): exception occurred: \"%s\", returning\n"),
               text.c_str()));

    throw(exception);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("RPG_Graphics_Dictionary::init(): exception occurred, returning\n")));

    throw;
  }

  dictionary_p.post_RPG_Graphics_Dictionary_Type();

//   // debug info
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("finished parsing graphics dictionary file \"%s\"...\n"),
//              filename_in.c_str()));
}

const RPG_Graphics_t
RPG_Graphics_Dictionary::getGraphic(const RPG_Graphics_Type& type_in) const
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary::getGraphic"));

  RPG_Graphics_DictionaryIterator_t iterator = myDictionary.find(type_in);
  if (iterator == myDictionary.end())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid graphics type \"%s\", continuing\n"),
               RPG_Graphics_TypeHelper::RPG_Graphics_TypeToString(type_in).c_str()));

    // *TODO*: what else can we do ?
    ACE_ASSERT(false);
  } // end IF

  return iterator->second;
}

const RPG_Graphics_Fonts_t
RPG_Graphics_Dictionary::getFonts() const
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary::getFonts"));

  RPG_Graphics_Fonts_t result;

  RPG_Graphics_Font_t font;
  font.type = RPG_GRAPHICS_TYPE_INVALID;
  font.size = 0;
  font.file.clear();
  for (RPG_Graphics_DictionaryIterator_t iterator = myDictionary.begin();
       iterator != myDictionary.end();
       iterator++)
    if ((*iterator).second.category == CATEGORY_FONT)
    {
      font.type = (*iterator).second.type;
      font.size = (*iterator).second.size;
      font.file = (*iterator).second.file;
      result.push_back(font);
    } // end IF

  return result;
}

bool
RPG_Graphics_Dictionary::XSD_Error_Handler::handle(const std::string& id_in,
                                                   unsigned long line_in,
                                                   unsigned long column_in,
                                                   ::xml_schema::error_handler::severity severity_in,
                                                   const std::string& message_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary::XSD_Error_Handler::handle"));

//   // debug info
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("error occured (ID: \"%s\", location: %d, %d): \"%s\" --> check implementation !, continuing\n"),
//              id_in.c_str(),
//              line_in,
//              column_in,
//              message_in.c_str()));

  switch (severity_in)
  {
    case ::xml_schema::error_handler::severity::warning:
    {
      ACE_DEBUG((LM_WARNING,
                 ACE_TEXT("WARNING: error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
                 id_in.c_str(),
                 line_in,
                 column_in,
                 message_in.c_str()));

      break;
    }
    case ::xml_schema::error_handler::severity::error:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("ERROR: error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
                 id_in.c_str(),
                 line_in,
                 column_in,
                 message_in.c_str()));

      break;
    }
    case ::xml_schema::error_handler::severity::fatal:
    {
      ACE_DEBUG((LM_CRITICAL,
                 ACE_TEXT("FATAL: error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
                 id_in.c_str(),
                 line_in,
                 column_in,
                 message_in.c_str()));

      break;
    }
    default:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("unkown error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
                 id_in.c_str(),
                 line_in,
                 column_in,
                 message_in.c_str()));

      break;
    }
  } // end SWITCH

  // try to continue anyway...
  return true;
}

void
RPG_Graphics_Dictionary::dump() const
{
  ACE_TRACE(ACE_TEXT("RPG_Graphics_Dictionary::dump"));

  unsigned long index = 0;
  std::string tile, tileset, elements;
  for (RPG_Graphics_DictionaryIterator_t iterator = myDictionary.begin();
       iterator != myDictionary.end();
       iterator++, index++)
  {
    if ((iterator->second).tile.type == RPG_GRAPHICS_TILETYPE_INVALID)
      tile = ACE_TEXT_ALWAYS_CHAR("N/A\n");
    else
    {
      tile = ACE_TEXT_ALWAYS_CHAR("\n");
      tile += RPG_Graphics_Common_Tools::tileToString((iterator->second).tile);
    } // end ELSE
    if ((iterator->second).tileset.type == RPG_GRAPHICS_TILESETTYPE_INVALID)
      tileset = ACE_TEXT_ALWAYS_CHAR("N/A\n");
    else
    {
      tileset = ACE_TEXT_ALWAYS_CHAR("\n");
      tileset += RPG_Graphics_Common_Tools::tileSetToString((iterator->second).tileset);
    } // end ELSE
    if ((iterator->second).elements.empty())
      elements = ACE_TEXT_ALWAYS_CHAR("N/A\n");
    else
    {
      elements = ACE_TEXT_ALWAYS_CHAR("\n");
      elements += RPG_Graphics_Common_Tools::elementsToString((iterator->second).elements);
    } // end ELSE

    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("Graphic[#%u]:\nCategory: %s\nType: %s\nTile: %sTileSet: %sElement(s)[%u]: %sFile: %s\nSize: %u\n"),
               index,
               RPG_Graphics_CategoryHelper::RPG_Graphics_CategoryToString((iterator->second).category).c_str(),
               RPG_Graphics_TypeHelper::RPG_Graphics_TypeToString((iterator->second).type).c_str(),
               tile.c_str(),
               tileset.c_str(),
               (iterator->second).elements.size(),
               elements.c_str(),
               ((iterator->second).file.empty() ? ACE_TEXT("N/A") : ((iterator->second).file).c_str()),
               (iterator->second).size));
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("===========================\n")));
  } // end FOR
}