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
#include "rpg_common_XML_parser.h"

#include "rpg_common_incl.h"

#include <ace/Log_Msg.h>

RPG_Common_Attribute RPG_Common_Attribute_Type::post_RPG_Common_Attribute_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Attribute_Type::post_RPG_Common_Attribute_Type"));

  return RPG_Common_AttributeHelper::stringToRPG_Common_Attribute(post_string());
}

RPG_Common_PhysicalDamageType RPG_Common_PhysicalDamageType_Type::post_RPG_Common_PhysicalDamageType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_PhysicalDamageType_Type::post_RPG_Common_PhysicalDamageType_Type"));

  return RPG_Common_PhysicalDamageTypeHelper::stringToRPG_Common_PhysicalDamageType(post_string());
}

RPG_Common_SavingThrow RPG_Common_SavingThrow_Type::post_RPG_Common_SavingThrow_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrow_Type::post_RPG_Common_SavingThrow_Type"));

  return RPG_Common_SavingThrowHelper::stringToRPG_Common_SavingThrow(post_string());
}

RPG_Common_SavingThrowCheck_Type::RPG_Common_SavingThrowCheck_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowCheck_Type::RPG_Common_SavingThrowCheck_Type"));

  myCurrentSavingThrowCheck.type = RPG_COMMON_SAVINGTHROW_INVALID;
  myCurrentSavingThrowCheck.attribute = RPG_COMMON_ATTRIBUTE_INVALID;
  myCurrentSavingThrowCheck.difficultyClass = 0;
}

void RPG_Common_SavingThrowCheck_Type::type(const RPG_Common_SavingThrow& type_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowUnion_Type::type"));

  myCurrentSavingThrowCheck.type = type_in;
}

void RPG_Common_SavingThrowCheck_Type::attribute(const RPG_Common_Attribute& attribute_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowUnion_Type::attribute"));

  myCurrentSavingThrowCheck.attribute = attribute_in;
}

void RPG_Common_SavingThrowCheck_Type::difficultyClass(unsigned char DC_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowUnion_Type::difficultyClass"));

  myCurrentSavingThrowCheck.difficultyClass = DC_in;
}

RPG_Common_SavingThrowCheck RPG_Common_SavingThrowCheck_Type::post_RPG_Common_SavingThrowCheck_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowCheck_Type::post_RPG_Common_SavingThrowCheck_Type"));

  RPG_Common_SavingThrowCheck result = myCurrentSavingThrowCheck;

  // clear structure
  myCurrentSavingThrowCheck.type = RPG_COMMON_SAVINGTHROW_INVALID;
  myCurrentSavingThrowCheck.attribute = RPG_COMMON_ATTRIBUTE_INVALID;
  myCurrentSavingThrowCheck.difficultyClass = 0;

  return result;
}

RPG_Common_Usage_Type::RPG_Common_Usage_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Usage_Type::RPG_Common_Usage_Type"));

  myCurrentUsage.numUses = 0;
  myCurrentUsage.period = 0;
}

void RPG_Common_Usage_Type::numUses(unsigned char numUses_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Usage_Type::numUses"));

  myCurrentUsage.numUses = numUses_in;
}

void RPG_Common_Usage_Type::period(unsigned int period_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Usage_Type::period"));

  myCurrentUsage.period = period_in;
}

RPG_Common_Usage RPG_Common_Usage_Type::post_RPG_Common_Usage_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Usage_Type::post_RPG_Common_Usage_Type"));

  RPG_Common_Usage result = myCurrentUsage;

  // clear structure
  myCurrentUsage.numUses = 0;
  myCurrentUsage.period = 0;

  return result;
}
