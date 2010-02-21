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
#ifndef RPG_MAGIC_DICTIONARY_H
#define RPG_MAGIC_DICTIONARY_H

#include "rpg_magic_common.h"

#include "rpg_XMLSchema.h"

#include <ace/Global_Macros.h>
#include <ace/Singleton.h>
#include <ace/Synch.h>

#include <string>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Magic_Dictionary
{
  // we use the singleton pattern, so we need to enable access to the ctor/dtors
  friend class ACE_Singleton<RPG_Magic_Dictionary,
                             ACE_Thread_Mutex>;

 public:
  // init item dictionary
  void init(const std::string&,  // filename
            const bool& = true); // validate XML ?

  const RPG_Magic_Spell_Properties getSpellProperties(const std::string&) const; // name of spell

  // debug info
  void dump() const;

 private:
  // safety measures
  RPG_Magic_Dictionary();
  virtual ~RPG_Magic_Dictionary();
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Dictionary(const RPG_Magic_Dictionary&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Dictionary& operator=(const RPG_Magic_Dictionary&));

  // private error handler
  class XSD_Error_Handler
   : public ::xml_schema::error_handler
  {
   public:
    virtual bool handle(const std::string&,                    // id
                        unsigned long,                         // line
                        unsigned long,                         // column
                        ::xml_schema::error_handler::severity, // severity
                        const std::string&);                   // message
  };

  RPG_Magic_Dictionary_t myDictionary;
  XSD_Error_Handler      myXSDErrorHandler;
};

typedef ACE_Singleton<RPG_Magic_Dictionary,
                      ACE_Thread_Mutex> RPG_MAGIC_DICTIONARY_SINGLETON;

#endif