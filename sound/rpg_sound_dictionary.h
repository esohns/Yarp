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

#ifndef RPG_SOUND_DICTIONARY_H
#define RPG_SOUND_DICTIONARY_H

#include "rpg_sound_common.h"

#include <xsd/cxx/xml/error-handler.hxx>

#include <ace/Global_Macros.h>
#include <ace/Singleton.h>
#include <ace/Synch.h>

#include <string>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Sound_Dictionary
{
  // we use the singleton pattern, so we need to enable access to the ctor/dtors
  friend class ACE_Singleton<RPG_Sound_Dictionary,
                             ACE_Thread_Mutex>;

 public:
  // init sound dictionary
  void init(const std::string&,  // filename
            const bool& = true); // validate XML ?

  const RPG_Sound_t getSound(const RPG_Sound_Event&) const; // event

  // debug info
  void dump() const;

 private:
  // safety measures
  RPG_Sound_Dictionary();
  virtual ~RPG_Sound_Dictionary();
  ACE_UNIMPLEMENTED_FUNC(RPG_Sound_Dictionary(const RPG_Sound_Dictionary&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Sound_Dictionary& operator=(const RPG_Sound_Dictionary&));

  // private error handler
  class XSD_Error_Handler
   : public ::xsd::cxx::xml::error_handler<char>
  {
   public:
    virtual bool handle(const std::string&,                             // id
                        unsigned long,                                  // line
                        unsigned long,                                  // column
                        ::xsd::cxx::xml::error_handler<char>::severity, // severity
                        const std::string&);                            // message
  };

  RPG_Sound_Dictionary_t myDictionary;
  XSD_Error_Handler      myXSDErrorHandler;
};

typedef ACE_Singleton<RPG_Sound_Dictionary,
                      ACE_Thread_Mutex> RPG_SOUND_DICTIONARY_SINGLETON;

#endif
