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

RPG_Common_CheckType RPG_Common_CheckType_Type::post_RPG_Common_CheckType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_CheckType_Type::post_RPG_Common_CheckType_Type"));

  return RPG_Common_CheckTypeHelper::stringToRPG_Common_CheckType(post_string());
}

RPG_Common_SavingThrow RPG_Common_SavingThrow_Type::post_RPG_Common_SavingThrow_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrow_Type::post_RPG_Common_SavingThrow_Type"));

  return RPG_Common_SavingThrowHelper::stringToRPG_Common_SavingThrow(post_string());
}

RPG_Common_BaseCheckTypeUnion_Type::RPG_Common_BaseCheckTypeUnion_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_BaseCheckTypeUnion_Type::RPG_Common_BaseCheckTypeUnion_Type"));

  myBaseCheckTypeUnion.checktype = RPG_COMMON_CHECKTYPE_INVALID;
  myBaseCheckTypeUnion.savingthrow = RPG_COMMON_SAVINGTHROW_INVALID;
}

void RPG_Common_BaseCheckTypeUnion_Type::_characters(const ::xml_schema::ro_string& checkType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_BaseCheckTypeUnion_Type::_characters"));

  // can be either:
  // - RPG_Common_CheckType_Type --> "CHECK_xxx"
  // - RPG_Common_SavingThrow_Type --> "SAVE_xxx"
  std::string type = checkType_in;
  if (type.find(ACE_TEXT_ALWAYS_CHAR("CHECK_")) == 0)
    myBaseCheckTypeUnion.checktype = RPG_Common_CheckTypeHelper::stringToRPG_Common_CheckType(checkType_in);
  else
    myBaseCheckTypeUnion.savingthrow = RPG_Common_SavingThrowHelper::stringToRPG_Common_SavingThrow(checkType_in);
}

RPG_Common_BaseCheckTypeUnion RPG_Common_BaseCheckTypeUnion_Type::post_RPG_Common_BaseCheckTypeUnion_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_BaseCheckTypeUnion_Type::post_RPG_Common_BaseCheckTypeUnion_Type"));

  RPG_Common_BaseCheckTypeUnion result = myBaseCheckTypeUnion;

  // clear structure
  myBaseCheckTypeUnion.checktype = RPG_COMMON_CHECKTYPE_INVALID;
  myBaseCheckTypeUnion.savingthrow = RPG_COMMON_SAVINGTHROW_INVALID;

  return result;
}

RPG_Common_SaveReductionType RPG_Common_SaveReductionType_Type::post_RPG_Common_SaveReductionType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SaveReductionType_Type::post_RPG_Common_SaveReductionType_Type"));

  return RPG_Common_SaveReductionTypeHelper::stringToRPG_Common_SaveReductionType(post_string());
}

RPG_Common_SavingThrowCheck_Type::RPG_Common_SavingThrowCheck_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowCheck_Type::RPG_Common_SavingThrowCheck_Type"));

  myCurrentCheck.type = RPG_COMMON_SAVINGTHROW_INVALID;
  myCurrentCheck.attribute = RPG_COMMON_ATTRIBUTE_INVALID;
  myCurrentCheck.difficultyClass = 0;
  myCurrentCheck.reduction = RPG_COMMON_SAVEREDUCTIONTYPE_INVALID;
}

void RPG_Common_SavingThrowCheck_Type::type(const RPG_Common_SavingThrow& type_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowCheck_Type::type"));

  myCurrentCheck.type = type_in;
}

void RPG_Common_SavingThrowCheck_Type::attribute(const RPG_Common_Attribute& attribute_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowCheck_Type::attribute"));

  myCurrentCheck.attribute = attribute_in;
}

void RPG_Common_SavingThrowCheck_Type::difficultyClass(unsigned char difficultyClass_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowCheck_Type::difficultyClass"));

  myCurrentCheck.difficultyClass = difficultyClass_in;
}

void RPG_Common_SavingThrowCheck_Type::reduction(const RPG_Common_SaveReductionType& reduction_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowCheck_Type::reduction"));

  myCurrentCheck.reduction = reduction_in;
}

RPG_Common_SavingThrowCheck RPG_Common_SavingThrowCheck_Type::post_RPG_Common_SavingThrowCheck_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_SavingThrowCheck_Type::post_RPG_Common_SavingThrowCheck_Type"));

  RPG_Common_SavingThrowCheck result = myCurrentCheck;

  // clear structure
  myCurrentCheck.type = RPG_COMMON_SAVINGTHROW_INVALID;
  myCurrentCheck.attribute = RPG_COMMON_ATTRIBUTE_INVALID;
  myCurrentCheck.difficultyClass = 0;
  myCurrentCheck.reduction = RPG_COMMON_SAVEREDUCTIONTYPE_INVALID;

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

RPG_Common_Duration_Type::RPG_Common_Duration_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Duration_Type::RPG_Common_Duration_Type"));

  myCurrentDuration.activationPeriod = 0;
  myCurrentDuration.interval = 0;
  myCurrentDuration.totalDuration = 0;
}

void RPG_Common_Duration_Type::activationPeriod(unsigned short activationPeriod_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Duration_Type::activationPeriod"));

  myCurrentDuration.activationPeriod = activationPeriod_in;
}

void RPG_Common_Duration_Type::interval(unsigned short interval_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Duration_Type::interval"));

  myCurrentDuration.interval = interval_in;
}

void RPG_Common_Duration_Type::totalDuration(unsigned short totalDuration_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Duration_Type::totalDuration"));

  myCurrentDuration.totalDuration = totalDuration_in;
}

RPG_Common_Duration RPG_Common_Duration_Type::post_RPG_Common_Duration_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Common_Duration_Type::post_RPG_Common_Duration_Type"));

  RPG_Common_Duration result = myCurrentDuration;

  // clear structure
  myCurrentDuration.activationPeriod = 0;
  myCurrentDuration.interval = 0;
  myCurrentDuration.totalDuration = 0;

  return result;
}
