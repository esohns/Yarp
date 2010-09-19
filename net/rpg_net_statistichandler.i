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

#include <rpg_common_macros.h>

#include <ace/Log_Msg.h>

template <typename StatisticsInfoContainer_t>
RPG_Net_StatisticHandler<StatisticsInfoContainer_t>::RPG_Net_StatisticHandler(const COLLECTOR_TYPE* interface_in,
                                                                              const ActionSpecifier& action_in)
 : inherited(NULL,                            // no reactor
             ACE_Event_Handler::LO_PRIORITY), // priority
   myInterface(interface_in),
   myAction(action_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_StatisticHandler::RPG_Net_StatisticHandler"));

}

template <typename StatisticsInfoContainer_t>
RPG_Net_StatisticHandler<StatisticsInfoContainer_t>::~RPG_Net_StatisticHandler()
{
  RPG_TRACE(ACE_TEXT("RPG_Net_StatisticHandler::~RPG_Net_StatisticHandler"));

}

template <typename StatisticsInfoContainer_t>
int
RPG_Net_StatisticHandler<StatisticsInfoContainer_t>::handle_timeout(const ACE_Time_Value& tv_in,
                                                                    const void* arg_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Net_StatisticHandler::handle_timeout"));

  ACE_UNUSED_ARG(tv_in);
  ACE_UNUSED_ARG(arg_in);

  switch (myAction)
  {
    case ACTION_COLLECT:
    {
      StatisticsInfoContainer_t result;
      ACE_OS::memset(&result,
                     0,
                     sizeof(StatisticsInfoContainer_t));

      try
      {
        if (!myInterface->collect(result))
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("failed to RPG_Common_IStatistic::collect(), continuing\n")));
        } // end IF
      }
      catch (...)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("caught an exception in RPG_Common_IStatistic::collect(), continuing\n")));

      }

      // *TODO*: what else can we do, dump the result somehow ?
      break;
    }
    case ACTION_REPORT:
    {
      try
      {
        myInterface->report();
      }
      catch (...)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("caught an exception in RPG_Common_IStatistic::report(), continuing\n")));
      }

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("unknown/invalid action %u, aborting\n"),
                 myAction));

      return -1;
    }
  } // end SWITCH

  // reschedule timer...
  return 0;
}

// *NOTE*: specialization to work around case where StatisticsInfoContainer_t is void... :-(
// *TODO*: this generates multiple defined symbols linker issues (which in turn can be solved with
// /FORCE:MULTIPLE linker option on MSVC)...
//template <>
//int RPG_Net_StatisticHandler<void>::handle_timeout(const ACE_Time_Value& tv_in,
//                                                   const void* arg_in)
//{
//  RPG_TRACE(ACE_TEXT("RPG_Net_StatisticHandler::handle_timeout"));
//
//  ACE_UNUSED_ARG(tv_in);
//  ACE_UNUSED_ARG(arg_in);
//
//  switch(myAction)
//  {
//    case ACTION_COLLECT:
//    {
//      try
//      {
//        if (!myInterface->collect(NULL))
//        {
//          ACE_DEBUG((LM_ERROR,
//                     ACE_TEXT("failed to RPG_Common_IStatistic::collect(), continuing\n")));
//        }
//      }
//      catch (...)
//      {
//        ACE_DEBUG((LM_ERROR,
//                   ACE_TEXT("caught an exception in RPG_Common_IStatistic::collect(), continuing\n")));
//
//        // *TODO*: what else can we do ?
//      }
//
//      break;
//    }
//    case ACTION_REPORT:
//    {
//      try
//      {
//        myInterface->report();
//      }
//      catch (...)
//      {
//        ACE_DEBUG((LM_ERROR,
//                   ACE_TEXT("caught an exception in RPS_FLB_Common_IStatistic::report(), continuing\n")));
//
//        // *TODO*: what else can we do ?
//      }
//
//      break;
//    }
//    default:
//    {
//      ACE_DEBUG((LM_ERROR,
//                 ACE_TEXT("unknown/invalid action %u, continuing\n"),
//                 myAction));
//
//      break;
//    }
//  } // end SWITCH
//
//  return 0;
//}
