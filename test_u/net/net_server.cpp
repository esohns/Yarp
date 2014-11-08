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
#include "stdafx.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#if defined(ACE_WIN32) || defined(ACE_WIN64)
#include "ace/Init_ACE.h"
#endif
#include "ace/Version.h"
#include "ace/Get_Opt.h"
#include "ace/Profile_Timer.h"
#include "ace/Signal.h"
#include "ace/Sig_Handler.h"
#include "ace/High_Res_Timer.h"
#include "ace/POSIX_Proactor.h"

#ifdef RPG_ENABLE_VALGRIND_SUPPORT
#include <valgrind/valgrind.h>
#endif

// *NOTE*: need this to import correct VERSION !
#ifdef HAVE_CONFIG_H
#include "rpg_config.h"
#endif

#include "rpg_common_macros.h"
#include "rpg_common.h"
#include "rpg_common_tools.h"
#include "rpg_common_file_tools.h"

#include "rpg_stream_allocatorheap.h"

#include "rpg_net_defines.h"
#include "rpg_net_common.h"
#include "rpg_net_common_tools.h"
#include "rpg_net_stream_messageallocator.h"
#include "rpg_net_module_eventhandler.h"

#include "rpg_client_common.h"
#include "rpg_client_logger.h"
#include "rpg_client_GTK_manager.h"
#include "rpg_client_ui_tools.h"

#include "rpg_net_server_defines.h"
#include "rpg_net_server_listener.h"
#include "rpg_net_server_asynchlistener.h"
#include "rpg_net_server_common_tools.h"

#include "net_defines.h"
#include "net_common.h"
#include "net_callbacks.h"
#include "net_eventhandler.h"

#include "net_server_signalhandler.h"

void
do_printUsage(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("::do_printUsage"));

  // enable verbatim boolean output
  std::cout.setf(ios::boolalpha);

  std::string configuration_path =
      RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                           true);
#if defined(DEBUG_DEBUGGER)
  configuration_path = RPG_Common_File_Tools::getWorkingDirectory();
#endif // #ifdef BASEDIR

  std::cout << ACE_TEXT("usage: ")
            << programName_in
            << ACE_TEXT(" [OPTIONS]")
            << std::endl
            << std::endl;
  std::cout << ACE_TEXT("currently available options:") << std::endl;
  std::cout << ACE_TEXT("-c [VALUE]   : max #connections ([")
            << RPG_NET_SERVER_MAXIMUM_NUMBER_OF_OPEN_CONNECTIONS
            << ACE_TEXT("])")
            << std::endl;
  std::cout << ACE_TEXT("-i [VALUE]   : client ping interval (second(s)) [")
            << RPG_NET_SERVER_DEFAULT_CLIENT_PING_INTERVAL
            << ACE_TEXT("] {0 --> OFF})")
            << std::endl;
//  std::cout << ACE_TEXT("-k [VALUE]  : client keep-alive timeout ([")
//            << RPG_NET_SERVER_DEF_CLIENT_KEEPALIVE
//            << ACE_TEXT("] second(s) {0 --> no timeout})")
//            << std::endl;
  std::cout << ACE_TEXT("-l           : log to a file [")
            << false
            << ACE_TEXT("]")
            << std::endl;
  std::cout << ACE_TEXT("-m           : receive uni/multi/broadcast UDP [")
            << false
            << ACE_TEXT("]")
            << std::endl;
  std::cout << ACE_TEXT("-n [STRING]  : network interface [\"")
            << ACE_TEXT(RPG_NET_DEFAULT_NETWORK_INTERFACE)
            << ACE_TEXT("\"]")
            << std::endl;
  // *TODO*: this doesn't really make sense (yet)
  std::cout << ACE_TEXT("-o           : use loopback [")
            << false
            << ACE_TEXT("]")
            << std::endl;
  std::cout << ACE_TEXT("-p [VALUE]   : listening port [")
            << RPG_NET_SERVER_DEFAULT_LISTENING_PORT
            << ACE_TEXT("]")
            << std::endl;
  std::cout << ACE_TEXT("-r           : use reactor [")
            << RPG_NET_USES_REACTOR
            << ACE_TEXT("]")
            << std::endl;
  std::cout << ACE_TEXT("-s [VALUE]   : statistics reporting interval (second(s)) [")
            << RPG_NET_SERVER_DEFAULT_STATISTICS_REPORTING_INTERVAL
            << ACE_TEXT("] {0 --> OFF})")
            << std::endl;
  std::cout << ACE_TEXT("-t           : trace information") << std::endl;
  std::string path = configuration_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
//#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
//  path += ACE_TEXT_ALWAYS_CHAR("net");
//  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
//#endif
  path += ACE_TEXT_ALWAYS_CHAR(NET_SERVER_UI_FILE);
  std::cout << ACE_TEXT("-u [[STRING]]: UI file [\"")
            << path
            << ACE_TEXT("\"] {\"\" --> no GUI}")
            << std::endl;
  std::cout << ACE_TEXT("-v           : print version information and exit")
            << std::endl;
  std::cout << ACE_TEXT("-x [VALUE]   : #dispatch threads [")
            << RPG_NET_SERVER_DEFAULT_NUMBER_OF_DISPATCHING_THREADS
            << ACE_TEXT("]")
            << std::endl;
}

bool
do_processArguments(const int& argc_in,
                    ACE_TCHAR** argv_in, // cannot be const...
                    unsigned int& maxNumConnections_out,
                    unsigned int& clientPingInterval_out,
                    //                  unsigned int& keepAliveTimeout_out,
                    bool& logToFile_out,
                    bool& useUDP_out,
                    std::string& networkInterface_out,
                    bool& useLoopback_out,
                    unsigned short& listeningPortNumber_out,
                    bool& useReactor_out,
                    unsigned int& statisticsReportingInterval_out,
                    bool& traceInformation_out,
                    std::string& UIFile_out,
                    bool& printVersionAndExit_out,
                    unsigned int& numDispatchThreads_out)
{
  RPG_TRACE(ACE_TEXT("::do_processArguments"));

  std::string configuration_path =
      RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                           true);
#if defined(DEBUG_DEBUGGER)
  configuration_path = RPG_Common_File_Tools::getWorkingDirectory();
#endif // #ifdef BASEDIR

  // init results
  maxNumConnections_out           = RPG_NET_SERVER_MAXIMUM_NUMBER_OF_OPEN_CONNECTIONS;
  clientPingInterval_out          = RPG_NET_SERVER_DEFAULT_CLIENT_PING_INTERVAL;
//  keepAliveTimeout_out = RPG_NET_SERVER_DEF_CLIENT_KEEPALIVE;
  logToFile_out                   = false;
  useUDP_out                      = false;
  networkInterface_out            =
      ACE_TEXT_ALWAYS_CHAR(RPG_NET_DEFAULT_NETWORK_INTERFACE);
  useLoopback_out                 = false;
  listeningPortNumber_out         = RPG_NET_SERVER_DEFAULT_LISTENING_PORT;
  useReactor_out                  = RPG_NET_USES_REACTOR;
  statisticsReportingInterval_out =
      RPG_NET_SERVER_DEFAULT_STATISTICS_REPORTING_INTERVAL;
  traceInformation_out            = false;
  std::string path = configuration_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
//#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
//  path += ACE_TEXT_ALWAYS_CHAR("net");
//  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
//#endif
  path += ACE_TEXT_ALWAYS_CHAR(NET_SERVER_UI_FILE);
  UIFile_out                      = path;
  printVersionAndExit_out         = false;
  numDispatchThreads_out          = RPG_NET_SERVER_DEFAULT_NUMBER_OF_DISPATCHING_THREADS;

  ACE_Get_Opt argumentParser(argc_in,
                             argv_in,
                             ACE_TEXT("c:i:k:lmn:op:rs:tu::vx:"));

  int option = 0;
  std::stringstream converter;
  while ((option = argumentParser()) != EOF)
  {
    switch (option)
    {
      case 'c':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> maxNumConnections_out;
        break;
      }
      case 'i':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> clientPingInterval_out;
        break;
      }
//      case 'k':
//      {
//        converter.clear();
//        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
//        converter << argumentParser.opt_arg();
//        converter >> keepAliveTimeout_out;
//        break;
//      }
      case 'l':
      {
        logToFile_out = true;
        break;
      }
      case 'm':
      {
        useUDP_out = true;
        break;
      }
      case 'n':
      {
        networkInterface_out = ACE_TEXT_ALWAYS_CHAR(argumentParser.opt_arg());
        break;
      }
      case 'o':
      {
        useLoopback_out = true;
        break;
      }
      case 'p':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> listeningPortNumber_out;
        break;
      }
      case 'r':
      {
        useReactor_out = true;
        break;
      }
      case 's':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> statisticsReportingInterval_out;
        break;
      }
      case 't':
      {
        traceInformation_out = true;
        break;
      }
      case 'u':
      {
        ACE_TCHAR* opt_arg = argumentParser.opt_arg();
        if (opt_arg)
          UIFile_out = ACE_TEXT_ALWAYS_CHAR(opt_arg);
        else
          UIFile_out.clear();
        break;
      }
      case 'v':
      {
        printVersionAndExit_out = true;
        break;
      }
      case 'x':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> numDispatchThreads_out;
        break;
      }
      // error handling
      case '?':
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("unrecognized option \"%s\", aborting\n"),
                   ACE_TEXT(argumentParser.last_option())));
        return false;
      }
      default:
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("unrecognized option \"%c\", continuing\n"),
                   option));
        break;
      }
    } // end SWITCH
  } // end WHILE

  return true;
}

void
init_signals(const bool& useReactor_in,
             const bool& allowUserRuntimeStats_in,
             ACE_Sig_Set& signals_inout)
{
  RPG_TRACE(ACE_TEXT("::init_signals"));

  // init return value(s)
  if (signals_inout.empty_set() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Sig_Set::empty_set(): \"%m\", aborting\n")));

    return;
  } // end IF

  // *PORTABILITY*: on Windows most signals are not defined,
  // and ACE_Sig_Set::fill_set() doesn't really work as specified
  // --> add valid signals (see <signal.h>)...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
  signals_inout.sig_add(SIGINT);         // 2       /* interrupt */
  signals_inout.sig_add(SIGILL);         // 4       /* illegal instruction - invalid function image */
  signals_inout.sig_add(SIGFPE);         // 8       /* floating point exception */
//  signals_inout.sig_add(SIGSEGV);        // 11      /* segment violation */
  signals_inout.sig_add(SIGTERM);        // 15      /* Software termination signal from kill */
  if (allowUserRuntimeStats_in)
    signals_inout.sig_add(SIGBREAK);       // 21      /* Ctrl-Break sequence */
  signals_inout.sig_add(SIGABRT);        // 22      /* abnormal termination triggered by abort call */
  signals_inout.sig_add(SIGABRT_COMPAT); // 6       /* SIGABRT compatible with other platforms, same as SIGABRT */
#else
  if (signals_inout.fill_set() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Sig_Set::fill_set(): \"%m\", aborting\n")));

    return;
  } // end IF
  // *NOTE*: cannot handle some signals --> registration fails for these...
  signals_inout.sig_del(SIGKILL);          // 9       /* Kill signal */
  signals_inout.sig_del(SIGSTOP);          // 19      /* Stop process */
	// ---------------------------------------------------------------------------
	if (!allowUserRuntimeStats_in)
		signals_inout.sig_del(SIGUSR1);        // 10      /* User-defined signal 1 */
	// *NOTE* core dump on SIGSEGV
	signals_inout.sig_del(SIGSEGV);          // 11      /* Segmentation fault: Invalid memory reference */
  // *NOTE* don't care about SIGPIPE
  signals_inout.sig_del(SIGPIPE);          // 12      /* Broken pipe: write to pipe with no readers */
  if (!useReactor_in)
  {
    ACE_POSIX_Proactor* proactor_impl = dynamic_cast<ACE_POSIX_Proactor*>(ACE_Proactor::instance()->implementation());
    ACE_ASSERT(proactor_impl);
    if (proactor_impl->get_impl_type() == ACE_POSIX_Proactor::PROACTOR_SIG)
      signals_inout.sig_del(ACE_SIGRTMIN); // 34      /* SIGRTMIN */
  } // end IF
#endif
}

void
do_work(const unsigned int& maxNumConnections_in,
        const unsigned int& pingInterval_in,
//        const unsigned int& keepAliveTimeout_in,
        const bool& useUDP_in,
        const std::string& networkInterface_in,
        const bool& useLoopback_in,
        const unsigned short& listeningPortNumber_in,
        const bool& useReactor_in,
        const unsigned int& statisticsReportingInterval_in,
        const unsigned int& numDispatchThreads_in,
				const bool& hasUI_in,
        Net_GTK_CBData_t& CBData_in,
        ACE_Sig_Set& signalSet_inout,
        RPG_Common_SignalActions_t& previousSignalActions_inout)
{
  RPG_TRACE(ACE_TEXT("::do_work"));

  // step0a: init stream configuration object
  Net_EventHandler ui_event_handler(&CBData_in);
  RPG_Net_Module_EventHandler_Module event_handler(ACE_TEXT_ALWAYS_CHAR("EventHandler"),
                                                   NULL);
  RPG_Net_Module_EventHandler* eventHandler_impl = NULL;
  eventHandler_impl = dynamic_cast<RPG_Net_Module_EventHandler*>(event_handler.writer());
  if (!eventHandler_impl)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("dynamic_cast<RPG_Net_Module_EventHandler> failed, aborting\n")));

    return;
  } // end IF
  eventHandler_impl->init(&CBData_in.subscribers,
                          &CBData_in.lock);
  eventHandler_impl->subscribe(&ui_event_handler);
  RPG_Stream_AllocatorHeap heapAllocator;
  RPG_Net_StreamMessageAllocator messageAllocator(RPG_NET_MAXIMUM_NUMBER_OF_INFLIGHT_MESSAGES,
                                                  &heapAllocator);
  RPG_Net_ConfigPOD config;
  ACE_OS::memset(&config, 0, sizeof(RPG_Net_ConfigPOD));
  // ************************ connection config data ***************************
  config.peerPingInterval = pingInterval_in;
  config.pingAutoAnswer = true;
//  config.printPongMessages = false;
  config.socketBufferSize = RPG_NET_DEFAULT_SOCKET_RECEIVE_BUFFER_SIZE;
  config.messageAllocator = &messageAllocator;
  config.bufferSize = RPG_NET_STREAM_BUFFER_SIZE;
//  config.useThreadPerConnection = false;
//  config.serializeOutput = false;
  // *************************** stream config data ****************************
  config.module = (hasUI_in ? &event_handler
		                        : NULL);
//  config.delete_module = false;
  // *WARNING*: set at runtime, by the appropriate connection handler
//  config.sessionID = 0; // (== socket handle !)
//  config.statisticsReportingInterval = 0; // don't do it per stream (see below)...
//  config.printFinalReport = false;
  // ****************************** runtime data *******************************
//  config.currentStatistics = {};
//  config.lastCollectionTimestamp = ACE_Time_Value::zero;

  // step0b: init event dispatch
  if (!RPG_Net_Common_Tools::initEventDispatch(useReactor_in,
                                               numDispatchThreads_in,
                                               config.serializeOutput))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to init event dispatch, aborting\n")));

    return;
  } // end IF

  // step1: init regular (global) stats reporting
  long timer_id = -1;
  RPG_Net_StatisticHandler_Reactor_t statistics_handler(RPG_NET_CONNECTIONMANAGER_SINGLETON::instance(),
                                                        RPG_Net_StatisticHandler_Reactor_t::ACTION_REPORT);
  if (statisticsReportingInterval_in)
  {
    ACE_Event_Handler* event_handler = &statistics_handler;
    ACE_Time_Value interval(statisticsReportingInterval_in,
                            0);
    timer_id =
      RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->schedule(event_handler,              // event handler
                                                              NULL,                       // ACT
                                                              (RPG_COMMON_TIME_POLICY() +
                                                               interval),                 // first wakeup time
                                                              interval);                  // interval
    if (timer_id == -1)
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("failed to schedule timer: \"%m\", aborting\n")));

      // clean up
      RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->stop();

      return;
    } // end IF
  } // end IF

  // step2: signal handling
  if (useReactor_in)
    CBData_in.listener_handle =
        RPG_NET_SERVER_LISTENER_SINGLETON::instance();
  else
    CBData_in.listener_handle =
        RPG_NET_SERVER_ASYNCHLISTENER_SINGLETON::instance();
  // event handler for signals
  Net_Server_SignalHandler signal_handler(timer_id,
                                          CBData_in.listener_handle,
                                          RPG_NET_CONNECTIONMANAGER_SINGLETON::instance(),
																					useReactor_in);
  if (!RPG_Common_Tools::initSignals(signalSet_inout,
                                     &signal_handler,
                                     previousSignalActions_inout))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to init signal handling, aborting\n")));

    // clean up
    if (timer_id == -1)
    {
      const void* act = NULL;
      if (RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->cancel(timer_id,
                                                                &act) <= 0)
        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("failed to cancel timer (ID: %d): \"%m\", continuing\n"),
                   timer_id));
    } // end IF
    RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->stop();

    return;
  } // end IF

  // step3: init connection manager
  RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->init(maxNumConnections_in);
  RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->set(config); // will be passed to all handlers

  // step4: handle events (signals, incoming connections/data, timers, ...)
  // reactor/proactor event loop:
  // - dispatch connection attempts to acceptor
  // - dispatch socket events
  // timer events:
  // - perform statistics collecting/reporting
  // [GTK events:]
  // - dispatch UI events (if any)

  // step4a: start GTK event loop ?
  if (hasUI_in)
  {
    RPG_CLIENT_GTK_MANAGER_SINGLETON::instance()->start();
    if (!RPG_CLIENT_GTK_MANAGER_SINGLETON::instance()->isRunning())
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to start GTK event dispatch, aborting\n")));

      // clean up
      if (timer_id == -1)
      {
        const void* act = NULL;
        if (RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->cancel(timer_id,
                                                                  &act) <= 0)
          ACE_DEBUG((LM_DEBUG,
                     ACE_TEXT("failed to cancel timer (ID: %d): \"%m\", continuing\n"),
                     timer_id));
      } // end IF
      RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->stop();
      RPG_Common_Tools::finiSignals(signalSet_inout,
                                    useReactor_in,
                                    previousSignalActions_inout);

      return;
    } // end IF
  } // end IF

  // step4b: init worker(s)
  int group_id = -1;
  if (!RPG_Net_Common_Tools::startEventDispatch(useReactor_in,
                                                numDispatchThreads_in,
                                                group_id))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to start event dispatch, aborting\n")));

    // clean up
    if (timer_id == -1)
    {
      const void* act = NULL;
      if (RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->cancel(timer_id,
                                                                &act) <= 0)
        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("failed to cancel timer (ID: %d): \"%m\", continuing\n"),
                   timer_id));
    } // end IF
    //		{ // synch access
    //			ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(CBData_in.lock);

    //			for (Net_GTK_EventSourceIDsIterator_t iterator = CBData_in.event_source_ids.begin();
    //					 iterator != CBData_in.event_source_ids.end();
    //					 iterator++)
    //				g_source_remove(*iterator);
    //		} // end lock scope
    RPG_CLIENT_GTK_MANAGER_SINGLETON::instance()->stop();
    RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->stop();
    RPG_Common_Tools::finiSignals(signalSet_inout,
                                  useReactor_in,
                                  previousSignalActions_inout);

    return;
  } // end IF

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("started event dispatch...\n")));

  // step4c: start listening
  CBData_in.listener_handle->init(listeningPortNumber_in,
                                  useLoopback_in);
  CBData_in.listener_handle->start();
  if (!CBData_in.listener_handle->isRunning())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to start listener (port: %u), aborting\n"),
               listeningPortNumber_in));

    // clean up
    RPG_Net_Common_Tools::finiEventDispatch(useReactor_in,
                                            !useReactor_in,
                                            group_id);
    if (timer_id == -1)
    {
      const void* act = NULL;
      if (RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->cancel(timer_id,
                                                                &act) <= 0)
        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("failed to cancel timer (ID: %d): \"%m\", continuing\n"),
                   timer_id));
    } // end IF
    //		{ // synch access
    //			ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(CBData_in.lock);

    //			for (Net_GTK_EventSourceIDsIterator_t iterator = CBData_in.event_source_ids.begin();
    //					 iterator != CBData_in.event_source_ids.end();
    //					 iterator++)
    //				g_source_remove(*iterator);
    //		} // end lock scope
    RPG_CLIENT_GTK_MANAGER_SINGLETON::instance()->stop();
    RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->stop();
    RPG_Common_Tools::finiSignals(signalSet_inout,
                                  useReactor_in,
                                  previousSignalActions_inout);

    return;
  } // end IF

  // *NOTE*: from this point on, clean up any remote connections !

  // *NOTE*: when using a thread pool, handle things differently...
  if (numDispatchThreads_in > 1)
  {
    if (ACE_Thread_Manager::instance()->wait_grp(group_id) == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE_Thread_Manager::wait_grp(%d): \"%m\", continuing\n"),
                 group_id));
  } // end IF
  else
  {
    if (useReactor_in)
    {
/*      // *WARNING*: restart system calls (after e.g. SIGINT) for the reactor
      ACE_Reactor::instance()->restart(1);
*/
      if (ACE_Reactor::instance()->run_reactor_event_loop(0) == -1)
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to handle events: \"%m\", aborting\n")));
    } // end IF
    else
      if (ACE_Proactor::instance()->proactor_run_event_loop(0) == -1)
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to handle events: \"%m\", aborting\n")));
  } // end ELSE

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished event dispatch...\n")));

  // clean up
  // *NOTE*: listener has stopped, interval timer has been cancelled,
  // and connections have been aborted...
  //		{ // synch access
  //			ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(CBData_in.lock);

  //			for (Net_GTK_EventSourceIDsIterator_t iterator = CBData_in.event_source_ids.begin();
  //					 iterator != CBData_in.event_source_ids.end();
  //					 iterator++)
  //				g_source_remove(*iterator);
  //		} // end lock scope
  RPG_CLIENT_GTK_MANAGER_SINGLETON::instance()->stop();
  RPG_COMMON_TIMERMANAGER_SINGLETON::instance()->stop();
  RPG_Common_Tools::finiSignals(signalSet_inout,
                                useReactor_in,
                                previousSignalActions_inout);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished working...\n")));
}

void
do_printVersion(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("::do_printVersion"));

  std::cout << programName_in
#ifdef HAVE_CONFIG_H
            << ACE_TEXT(" : ")
            << RPG_VERSION
#endif
            << std::endl;

  // create version string...
  // *NOTE*: cannot use ACE_VERSION, as it doesn't contain the (potential) beta
  // version number... Need this, as the library soname is compared to this
  // string
  std::ostringstream version_number;
  version_number << ACE::major_version();
  version_number << ACE_TEXT(".");
  version_number << ACE::minor_version();
  version_number << ACE_TEXT(".");

  std::cout << ACE_TEXT("ACE: ") << version_number.str() << std::endl;
//   std::cout << "ACE: "
//             << ACE_VERSION
//             << std::endl;
}

int
ACE_TMAIN(int argc_in,
          ACE_TCHAR** argv_in)
{
  RPG_TRACE(ACE_TEXT("::main"));

  // step0: init
// *PORTABILITY*: on Windows, need to init ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
  if (ACE::init() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE::init(): \"%m\", aborting\n")));

    return EXIT_FAILURE;
  } // end IF
#endif

  // *PROCESS PROFILE*
  ACE_Profile_Timer process_profile;
  // start profile timer...
  process_profile.start();

  std::string configuration_path =
      RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                                           true);
#if defined(DEBUG_DEBUGGER)
  configuration_path = RPG_Common_File_Tools::getWorkingDirectory();
#endif // #ifdef BASEDIR

  // step1a set defaults
  unsigned int max_num_connections           = RPG_NET_SERVER_MAXIMUM_NUMBER_OF_OPEN_CONNECTIONS;
  unsigned int ping_interval                 = RPG_NET_SERVER_DEFAULT_CLIENT_PING_INTERVAL;
//  unsigned int keep_alive_timeout            = RPG_NET_SERVER_DEFAULT_TCP_KEEPALIVE;
  bool log_to_file                           = false;
  bool use_udp                               = false;
  std::string network_interface              = ACE_TEXT_ALWAYS_CHAR(RPG_NET_DEFAULT_NETWORK_INTERFACE);
  bool use_loopback                          = false;
  unsigned short listening_port_number       = RPG_NET_SERVER_DEFAULT_LISTENING_PORT;
  bool use_reactor                           = RPG_NET_USES_REACTOR;
  unsigned int statistics_reporting_interval = RPG_NET_SERVER_DEFAULT_STATISTICS_REPORTING_INTERVAL;
  bool trace_information                     = false;
  std::string path = configuration_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
//#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
//  path += ACE_TEXT_ALWAYS_CHAR("net");
//  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
//#endif
  path += ACE_TEXT_ALWAYS_CHAR(NET_SERVER_UI_FILE);
  std::string UI_file                        = path;
  bool print_version_and_exit                = false;
  unsigned int num_dispatch_threads          = RPG_NET_SERVER_DEFAULT_NUMBER_OF_DISPATCHING_THREADS;

  // step1b: parse/process/validate configuration
  if (!do_processArguments(argc_in,
                           argv_in,
                           max_num_connections,
                           ping_interval,
//                           keep_alive_timeout,
                           log_to_file,
                           use_udp,
                           network_interface,
                           use_loopback,
                           listening_port_number,
                           use_reactor,
                           statistics_reporting_interval,
                           trace_information,
                           UI_file,
                           print_version_and_exit,
                           num_dispatch_threads))
  {
    // make 'em learn...
    do_printUsage(ACE::basename(argv_in[0]));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
		if (ACE::fini() == -1)
			ACE_DEBUG((LM_ERROR,
								 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF

  // step1c: validate arguments
  // *NOTE*: probably requires CAP_NET_BIND_SERVICE
  if (listening_port_number <= 1023)
    ACE_DEBUG((LM_NOTICE,
               ACE_TEXT("using (privileged) port #: %d...\n"),
               listening_port_number));
  if (!UI_file.empty() &&
      !RPG_Common_File_Tools::isReadable(UI_file))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid UI definition file (was: %s), aborting\n"),
               ACE_TEXT(UI_file.c_str())));

    // make 'em learn...
    do_printUsage(ACE::basename(argv_in[0]));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF
  if (num_dispatch_threads == 0)
    num_dispatch_threads = 1;

  // step1d: pre-init signal handling
  ACE_Sig_Set signal_set(0);
  init_signals(use_reactor,
               (statistics_reporting_interval == 0), // allow SIGUSR1/SIGBREAK
                                                     // IFF regular reporting
                                                     // is off
               signal_set);
  RPG_Common_SignalActions_t previous_signal_actions;
  if (!RPG_Common_Tools::preInitSignals(signal_set,
                                        use_reactor,
                                        previous_signal_actions))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Common_Tools::preInitSignals(), aborting\n")));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF

  Net_GTK_CBData_t gtk_cb_user_data;
  // step1e: initialize logging and/or tracing
  RPG_Client_Logger logger(&gtk_cb_user_data.log_stack,
                           &gtk_cb_user_data.lock);
  std::string log_file;
  if (log_to_file &&
      !RPG_Net_Server_Common_Tools::getNextLogFilename(ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DEF_LOG_DIRECTORY),
                                                       log_file))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Net_Common_Tools::getNextLogFilename(), aborting\n")));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF
  if (!RPG_Common_Tools::initLogging(ACE::basename(argv_in[0]),   // program name
                                     log_file,                    // logfile
                                     true,                        // log to syslog ?
                                     false,                       // trace messages ?
                                     trace_information,           // debug messages ?
                                     (UI_file.empty() ? NULL
                                                      : &logger))) // logger ?
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Common_Tools::initLogging(), aborting\n")));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF

  // step1f: handle specific program modes
  if (print_version_and_exit)
  {
    do_printVersion(ACE::basename(argv_in[0]));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_SUCCESS;
  } // end IF

  // step1g: set process resource limits
  // *NOTE*: settings will be inherited by any child processes
  // *TODO*: the reasoning here is incomplete
  bool use_fd_based_reactor = use_reactor;
#if defined(ACE_WIN32) || defined(ACE_WIN64)
  use_fd_based_reactor = (use_reactor && !RPG_COMMON_USE_WFMO_REACTOR);
#endif
  if (!RPG_Common_Tools::initResourceLimits(use_fd_based_reactor, // file descriptors
                                            true))                // stack traces
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Common_Tools::initResourceLimits(), aborting\n")));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF

  // step1h: init GLIB / G(D|T)K[+] / GNOME ?
	Net_GTKUIDefinition gtk_initializer(Net_GTKUIDefinition::ROLE_SERVER,
                                      (statistics_reporting_interval == 0), // allow SIGUSR1/SIGBREAK
                                      // IFF regular reporting
                                      // is off
                                      &gtk_cb_user_data);
  if (!UI_file.empty())
  {
    RPG_CLIENT_GTK_MANAGER_SINGLETON::instance()->init(argc_in,
                                                       argv_in,
                                                       UI_file,
                                                       &gtk_initializer);
  } // end IF

  ACE_High_Res_Timer timer;
  timer.start();
  // step2: do actual work
  do_work(max_num_connections,
          ping_interval,
//          keep_alive_timeout,
          use_udp,
          network_interface,
          use_loopback,
          listening_port_number,
          use_reactor,
          statistics_reporting_interval,
          num_dispatch_threads,
          !UI_file.empty(),
          gtk_cb_user_data,
          signal_set,
          previous_signal_actions);
  timer.stop();

  // debug info
  std::string working_time_string;
  ACE_Time_Value working_time;
  timer.elapsed_time(working_time);
  RPG_Common_Tools::period2String(working_time,
                                  working_time_string);
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("total working time (h:m:s.us): \"%s\"...\n"),
             ACE_TEXT(working_time_string.c_str())));

  // stop profile timer...
  process_profile.stop();

  // only process profile left to do...
  ACE_Profile_Timer::ACE_Elapsed_Time elapsed_time;
  elapsed_time.real_time = 0.0;
  elapsed_time.user_time = 0.0;
  elapsed_time.system_time = 0.0;
  if (process_profile.elapsed_time(elapsed_time) == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Profile_Timer::elapsed_time: \"%m\", aborting\n")));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF
  ACE_Profile_Timer::Rusage elapsed_rusage;
  ACE_OS::memset(&elapsed_rusage,
                 0,
                 sizeof(ACE_Profile_Timer::Rusage));
  process_profile.elapsed_rusage(elapsed_rusage);
  ACE_Time_Value user_time(elapsed_rusage.ru_utime);
  ACE_Time_Value system_time(elapsed_rusage.ru_stime);
  std::string user_time_string;
  std::string system_time_string;
  RPG_Common_Tools::period2String(user_time,
                                  user_time_string);
  RPG_Common_Tools::period2String(system_time,
                                  system_time_string);

  // debug info
#if !defined(ACE_WIN32) && !defined(ACE_WIN64)
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT(" --> Process Profile <--\nreal time = %A seconds\nuser time = %A seconds\nsystem time = %A seconds\n --> Resource Usage <--\nuser time used: %s\nsystem time used: %s\nmaximum resident set size = %d\nintegral shared memory size = %d\nintegral unshared data size = %d\nintegral unshared stack size = %d\npage reclaims = %d\npage faults = %d\nswaps = %d\nblock input operations = %d\nblock output operations = %d\nmessages sent = %d\nmessages received = %d\nsignals received = %d\nvoluntary context switches = %d\ninvoluntary context switches = %d\n"),
             elapsed_time.real_time,
             elapsed_time.user_time,
             elapsed_time.system_time,
             user_time_string.c_str(),
             system_time_string.c_str(),
             elapsed_rusage.ru_maxrss,
             elapsed_rusage.ru_ixrss,
             elapsed_rusage.ru_idrss,
             elapsed_rusage.ru_isrss,
             elapsed_rusage.ru_minflt,
             elapsed_rusage.ru_majflt,
             elapsed_rusage.ru_nswap,
             elapsed_rusage.ru_inblock,
             elapsed_rusage.ru_oublock,
             elapsed_rusage.ru_msgsnd,
             elapsed_rusage.ru_msgrcv,
             elapsed_rusage.ru_nsignals,
             elapsed_rusage.ru_nvcsw,
             elapsed_rusage.ru_nivcsw));
#else
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT(" --> Process Profile <--\nreal time = %A seconds\nuser time = %A seconds\nsystem time = %A seconds\n --> Resource Usage <--\nuser time used: %s\nsystem time used: %s\n"),
             elapsed_time.real_time,
             elapsed_time.user_time,
             elapsed_time.system_time,
             user_time_string.c_str(),
             system_time_string.c_str()));
#endif

// *PORTABILITY*: on Windows, must fini ACE...
#if defined(ACE_WIN32) || defined(ACE_WIN64)
  if (ACE::fini() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE::fini(): \"%m\", aborting\n")));

    return EXIT_FAILURE;
  } // end IF
#endif

  return EXIT_SUCCESS;
} // end main
