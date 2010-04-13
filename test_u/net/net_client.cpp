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

// *NOTE*: need this to import correct VERSION !
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "net_common.h"
#include "net_client_timeouthandler.h"
#include "net_client_signalhandler.h"

#include <rpg_net_defines.h>
#include <rpg_net_common_tools.h>
#include <rpg_net_connection_manager.h>
#include <rpg_net_stream_messageallocator.h>

#include <rpg_common_tools.h>

#include <stream_allocatorheap.h>

#include <ace/Version.h>
#include <ace/Get_Opt.h>
#include <ace/Profile_Timer.h>
#include <ace/Reactor.h>
#include <ace/TP_Reactor.h>
#include <ace/Signal.h>
#include <ace/Sig_Handler.h>
#include <ace/Connector.h>
#include <ace/SOCK_Connector.h>
#include <ace/High_Res_Timer.h>

#include <string>
#include <iostream>
#include <sstream>
#include <list>

#define NET_CLIENT_DEF_SERVER_HOSTNAME         ACE_LOCALHOST
#define NET_CLIENT_DEF_SERVER_CONNECT_INTERVAL 1
#define NET_CLIENT_DEF_CLIENT_USES_TP          false
#define NET_CLIENT_DEF_NUM_TP_THREADS          5

void
print_usage(const std::string& programName_in)
{
  ACE_TRACE(ACE_TEXT("::print_usage"));

  // enable verbatim boolean output
  std::cout.setf(ios::boolalpha);

  std::cout << ACE_TEXT("usage: ") << programName_in << ACE_TEXT(" [OPTIONS]") << std::endl << std::endl;
  std::cout << ACE_TEXT("currently available options:") << std::endl;
  std::cout << ACE_TEXT("-h [STRING] : server (host)name [\"") << NET_CLIENT_DEF_SERVER_HOSTNAME << "\"]" << std::endl;
  std::cout << ACE_TEXT("-i [VALUE]  : connection interval ([") << NET_CLIENT_DEF_SERVER_CONNECT_INTERVAL << ACE_TEXT("] second(s))") << std::endl;
  std::cout << ACE_TEXT("-l          : log to a file") << ACE_TEXT(" [") << false << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-p [VALUE]  : server port [") << RPG_NET_DEF_LISTENING_PORT << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-s          : stress-test server") << ACE_TEXT(" [") << false << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-t          : trace information") << ACE_TEXT(" [") << false << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-v          : print version information and exit") << ACE_TEXT(" [") << false << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-x<[VALUE]> : use thread pool <#threads>") << ACE_TEXT(" [") << NET_CLIENT_DEF_CLIENT_USES_TP << ACE_TEXT("]") << std::endl;
} // end print_usage

const bool
process_arguments(const int argc_in,
                  ACE_TCHAR* argv_in[], // cannot be const...
                  std::string& serverHostname_out,
                  unsigned long& connectionInterval_out,
                  bool& logToFile_out,
                  unsigned short& serverPortNumber_out,
                  bool& stressTestServer_out,
                  bool& traceInformation_out,
                  bool& printVersionAndExit_out,
                  bool& useThreadPool_out,
                  unsigned long& numThreadPoolThreads_out)
{
  ACE_TRACE(ACE_TEXT("::process_arguments"));

  // init results
  serverHostname_out = NET_CLIENT_DEF_SERVER_HOSTNAME;
  connectionInterval_out = NET_CLIENT_DEF_SERVER_CONNECT_INTERVAL;
  logToFile_out = false;
  serverPortNumber_out = RPG_NET_DEF_LISTENING_PORT;
  stressTestServer_out = false;
  traceInformation_out = false;
  printVersionAndExit_out = false;
  useThreadPool_out = NET_CLIENT_DEF_CLIENT_USES_TP;
  numThreadPoolThreads_out = NET_CLIENT_DEF_NUM_TP_THREADS;

  ACE_Get_Opt argumentParser(argc_in,
                             argv_in,
                             ACE_TEXT("h:i:lp:stvx::"),
                             1, // skip command name
                             1, // report parsing errors
                             ACE_Get_Opt::PERMUTE_ARGS, // ordering
                             0); // for now, don't use long options

  int option = 0;
  std::stringstream converter;
  while ((option = argumentParser()) != EOF)
  {
    switch (option)
    {
      case 'h':
      {
        serverHostname_out = argumentParser.opt_arg();

        break;
      }
      case 'i':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> connectionInterval_out;

        break;
      }
      case 'l':
      {
        logToFile_out = true;

        break;
      }
      case 'p':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> serverPortNumber_out;

        break;
      }
      case 's':
      {
        stressTestServer_out = true;

        break;
      }
      case 't':
      {
        traceInformation_out = true;

        break;
      }
      case 'v':
      {
        printVersionAndExit_out = true;

        break;
      }
      case 'x':
      {
        useThreadPool_out = true;
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> numThreadPoolThreads_out;

        break;
      }
      // error handling
      case ':':
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("option \"%c\" requires an argument, aborting\n"),
                   argumentParser.opt_opt()));

        return false;
      }
      case '?':
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("unrecognized option \"%s\", aborting\n"),
                   argumentParser.last_option()));

        return false;
      }
      case 0:
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("found long option \"%s\", aborting\n"),
                   argumentParser.long_option()));

        return false;
      }
      default:
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("parse error, aborting\n")));

        return false;
      }
    } // end SWITCH
  } // end WHILE

  return true;
}

const bool
init_threadPool()
{
  ACE_TRACE(ACE_TEXT("::init_threadPool"));

  ACE_TP_Reactor* threadpool_reactor = NULL;
  ACE_NEW_RETURN(threadpool_reactor,
                 ACE_TP_Reactor(),
                                false);
  ACE_Reactor* new_reactor = NULL;
  ACE_NEW_RETURN(new_reactor,
                 ACE_Reactor(threadpool_reactor, 1), // delete in dtor
                             false);
  // make this the "default" reactor...
  ACE_Reactor::instance(new_reactor, 1); // delete in dtor

  return true;
}

void
init_signals(const bool& allowUserRuntimeConnect_in,
             std::vector<int>& signals_inout)
{
  ACE_TRACE(ACE_TEXT("::init_signals"));

  // init return value(s)
  signals_inout.clear();

  // init list of handled signals...
  // *PORTABILITY*: on Windows SIGHUP and SIGQUIT are not defined,
  // so we handle SIGBREAK (21) and SIGABRT (22) instead...
#if !defined (ACE_WIN32) && !defined (ACE_WIN64)
  // *NOTE*: don't handle SIGHUP !!!! --> program will hang !
  //signals_inout.push_back(SIGHUP);
#endif
  signals_inout.push_back(SIGINT);
#if !defined (ACE_WIN32) && !defined (ACE_WIN64)
  signals_inout.push_back(SIGQUIT);
#endif
//   signals_inout.push_back(SIGILL);
//   signals_inout.push_back(SIGTRAP);
  signals_inout.push_back(SIGABRT);
//   signals_inout.push_back(SIGBUS);
//   signals_inout.push_back(SIGFPE);
//   signals_inout.push_back(SIGKILL); // cannot catch this one...
  if (allowUserRuntimeConnect_in)
    signals_inout.push_back(SIGUSR1);
//   signals_inout.push_back(SIGSEGV);
  if (allowUserRuntimeConnect_in)
    signals_inout.push_back(SIGUSR2); // if we allow SIGUSR1, we allow SIGUSR2
//   signals_inout.push_back(SIGPIPE);
//   signals_inout.push_back(SIGALRM);
  signals_inout.push_back(SIGTERM);
//   signals_inout.push_back(SIGSTKFLT);
//   signals_inout.push_back(SIGCHLD);
//   signals_inout.push_back(SIGCONT);
//   signals_inout.push_back(SIGSTOP); // cannot catch this one...
//   signals_inout.push_back(SIGTSTP);
//   signals_inout.push_back(SIGTTIN);
#if defined (ACE_WIN32) || defined (ACE_WIN64)
  signals_inout.push_back(SIGBREAK);
#endif
//   signals_inout.push_back(SIGTTOU);
//   signals_inout.push_back(SIGURG);
//   signals_inout.push_back(SIGXCPU);
//   signals_inout.push_back(SIGXFSZ);
//   signals_inout.push_back(SIGVTALRM);
//   signals_inout.push_back(SIGPROF);
//   signals_inout.push_back(SIGWINCH);
//   signals_inout.push_back(SIGIO);
//   signals_inout.push_back(SIGPWR);
//   signals_inout.push_back(SIGSYS);
//   signals_inout.push_back(SIGRTMIN);
//   signals_inout.push_back(SIGRTMIN+1);
// ...
//   signals_inout.push_back(SIGRTMAX-1);
//   signals_inout.push_back(SIGRTMAX);
}

const bool
init_signalHandling(const std::vector<int>& signals_inout,
                    Net_Client_SignalHandler& eventHandler_in,
                    ACE_Sig_Handlers& signalHandlers_in)
{
  ACE_TRACE(ACE_TEXT("::init_signalHandling"));

  // step1: register signal handlers for the list of signals we want to catch

  // specify (default) action...
  // --> we don't actually need to keep this around after registration
  ACE_Sig_Action signalAction((ACE_SignalHandler)SIG_DFL, // default action (will be overridden below)...
                              ACE_Sig_Set(1),             // mask of signals to be blocked when we're servicing
                                                          // --> block them all ! (except KILL off course...)
                              (SA_RESTART | SA_SIGINFO)); // flags
//                                SA_SIGINFO);               // flags

  // register different signals...
  int sigkey = -1;
  for (std::vector<int>::const_iterator iter = signals_inout.begin();
       iter != signals_inout.end();
       iter++)
  {
    sigkey = signalHandlers_in.register_handler(*iter,            // signal
                                                &eventHandler_in, // new handler
                                                &signalAction,    // new action
                                                NULL,             // old handler
                                                NULL);            // old action
    if (sigkey == -1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE_Sig_Handlers::register_handler(\"%S\": %d): \"%m\", aborting\n"),
                 *iter,
                 *iter));

      return false;
    } // end IF

    // debug info
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("registered handler for \"%S\": %d (key: %d)...\n"),
               *iter,
               *iter,
               sigkey));
  } // end FOR

  // actually, there is only a single handler for ALL signals in the set...
  // debug info
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("handling %d signal(s)...\n"),
//              signals_inout.size()));

  // step2: ignore SIGPIPE; need this to enable sending to exit gracefully
  // after an asynchronous client disconnect (i.e. crash/...)
  // specify ignore action...
  // --> we don't actually need to keep this around after registration
  ACE_Sig_Action ignoreAction((ACE_SignalHandler)SIG_IGN, // ignore action...
                              ACE_Sig_Set(1),             // mask of signals to be blocked when we're servicing
                                                          // --> block them all ! (except KILL off course...)
                              (SA_RESTART | SA_SIGINFO)); // flags
  ACE_Sig_Action originalAction;
  ignoreAction.register_action(SIGPIPE, &originalAction);

  return true;
}

static
ACE_THR_FUNC_RETURN
tp_worker_func(void* args_in)
{
  ACE_TRACE(ACE_TEXT("::tp_worker_func"));

  ACE_UNUSED_ARG(args_in);

  while (!ACE_Reactor::event_loop_done())
  {
    // block and wait for an event...
    if (ACE_Reactor::instance()->handle_events(NULL) == -1)
      ACE_ERROR((LM_ERROR,
                 ACE_TEXT("(%t) error handling events: \"%m\"\n")));
  } // end WHILE

  return 0;
}

void
do_work(const std::string& serverHostname_in,
        const unsigned long& connectionInterval_in,
        const unsigned short& serverPortNumber_in,
        const bool& stressTestServer_in,
        const bool& useThreadPool_in,
        const unsigned long& numThreadPoolThreads_in)
{
  ACE_TRACE(ACE_TEXT("::do_work"));

  // step0a: (if necessary) init the TP_Reactor
  if (useThreadPool_in)
  {
    if (!init_threadPool())
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to init_threadPool(), aborting\n")));

      return;
    } // end IF
  } // end IF

  // step0b: init client connector
  RPG_Net_Client_Connector connector(ACE_Reactor::instance(), // reactor
                                     ACE_NONBLOCK);           // flags: non-blocking I/O
//                                      0);                      // flags (*TODO*: ACE_NONBLOCK ?);

  // step1: signal handling
  // event handler for signals
  Net_Client_SignalHandler signalEventHandler(serverHostname_in,   // target hostname
                                              serverPortNumber_in, // target port
                                              &connector);         // connector
  ACE_Sig_Handlers signalHandlers;
  // *WARNING*: 'signals' appears to be a keyword in some contexts...
  std::vector<int> signalss;
  init_signals((stressTestServer_in == 0),  // allow SIGUSR1 IF regular connections are off
               signalss);
  if (!init_signalHandling(signalss,
                           signalEventHandler,
                           signalHandlers))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to init_signalHandling(), aborting\n")));

    return;
  } // end IF

  // step2a: init stream configuration object
  Stream_AllocatorHeap heapAllocator;
  RPG_Net_StreamMessageAllocator messageAllocator(RPG_NET_DEF_MAX_MESSAGES,
                                                  &heapAllocator);
  RPG_Net_ConfigPOD config;
  ACE_OS::memset(&config,
                  0,
                  sizeof(RPG_Net_ConfigPOD));
  config.clientPingInterval = 0; // servers do this...
  config.socketBufferSize = RPG_NET_DEF_SOCK_RECVBUF_SIZE;
  config.messageAllocator = &messageAllocator;
  config.statisticsReportingInterval = 0; // == off

  // step2b: init connection manager
  RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->init(std::numeric_limits<unsigned int>::max(),
                                                        config); // will be passed to all handlers

  // step2ca: init timer...
  long timerID = -1;
  Net_Client_TimeoutHandler timeoutHandler(serverHostname_in,
                                           serverPortNumber_in,
                                           &connector);
  if (stressTestServer_in && connectionInterval_in)
  {
    // schedule server query interval timer
    ACE_Time_Value interval(connectionInterval_in, 0);
    timerID = ACE_Reactor::instance()->schedule_timer(&timeoutHandler, // event handler
                                                      NULL,            // args passed to handler
                                                      interval,        // first delay
                                                      interval);       // recurrence interval
    if (timerID == -1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE_Reactor::schedule_timer(): \"%m\", aborting\n")));

      return;
    } // end IF
  } // end IF
  else
  {
    // step2cb: ...or (try to) connect to the server immediately
    RPG_Net_Client_SocketHandler* handler = NULL;
    ACE_INET_Addr remote_address(serverPortNumber_in, // remote SAP
                                 serverHostname_in.c_str());
    if (connector.connect(handler,                     // service handler
                          remote_address/*,              // remote SAP
                          ACE_Synch_Options::defaults, // synch options
                          ACE_INET_Addr::sap_any,      // local SAP
                          0,                           // try to re-use address (SO_REUSEADDR)
                          O_RDWR,                      // flags
                          0*/) == -1)                  // perms
    {
      // debug info
      ACE_TCHAR buf[BUFSIZ];
      ACE_OS::memset(buf,
                     0,
                     (BUFSIZ * sizeof(ACE_TCHAR)));
      if (remote_address.addr_to_string(buf,
                                        (BUFSIZ * sizeof(ACE_TCHAR))) == -1)
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to ACE_INET_Addr::addr_to_string(): \"%m\", continuing\n")));
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE_Connector::connect(%s): \"%m\", aborting\n"),
                 buf));

      return;
    } // end IF
  } // end ELSE

  // *NOTE*: from this point on, we need to clean up any remote connections !

  // event loop:
  // - catch SIGINT/SIGQUIT/SIGTERM/... signals (and perform orderly shutdown)
  // - signal timer expiration to perform server queries

//   // *NOTE*: make sure we generally restart system calls (after e.g. EINTR) for the reactor...
//   ACE_Reactor::instance()->restart(1);

  // step3: dispatch events...
  // *NOTE*: if we use a thread pool, we need to do this differently...
  if (useThreadPool_in)
  {
    // start a (group of) worker(s)...
    int grp_id = -1;
    grp_id = ACE_Thread_Manager::instance()->spawn_n(numThreadPoolThreads_in,     // # threads
                                                     ::tp_worker_func,            // function
                                                     NULL,                        // argument
                                                     (THR_NEW_LWP | THR_JOINABLE | THR_INHERIT_SCHED), // flags
                                                     ACE_DEFAULT_THREAD_PRIORITY, // priority
                                                     -1,                          // group id --> create new
                                                     NULL,                        // task
                                                     NULL,                        // handle(s)
                                                     NULL,                        // stack(s)
                                                     NULL,                        // stack size(s)
                                                     NULL);                       // name(s)
    if (grp_id == -1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE_Thread_Manager::spawn_n(%u): \"%m\", aborting\n"),
                 numThreadPoolThreads_in));

      // clean up
//       if (stressTestServer_in)
//       {
//         if (ACE_Reactor::instance()->cancel_timer(timerID,  // timer ID
//             NULL,     // pointer to args passed to handler
//             1) != 1)  // don't invoke handle_close() on handler
//         {
//           ACE_DEBUG((LM_ERROR,
//                      ACE_TEXT("failed to ACE_Reactor::cancel_timer(): \"%p\", continuing\n")));
//         } // end IF
//       } // end IF
      RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->abortConnections();
      RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->waitConnections();

      return;
    } // end IF

    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("started group (ID: %u) of %u worker thread(s)...\n"),
               grp_id,
               numThreadPoolThreads_in));

    // ... and wait for this group to join
    ACE_Thread_Manager::instance()->wait_grp(grp_id);
  } // end IF
  else
  {
    if (ACE_Reactor::instance()->run_reactor_event_loop() == -1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE_Reactor::run_reactor_event_loop(): \"%m\", aborting\n")));

      // clean up
//       if (stressTestServer_in)
//       {
//         if (ACE_Reactor::instance()->cancel_timer(timerID,  // timer ID
//                                                   NULL,     // pointer to args passed to handler
//                                                   1) != 1)  // don't invoke handle_close() on handler
//         {
//           ACE_DEBUG((LM_ERROR,
//                     ACE_TEXT("failed to ACE_Reactor::cancel_timer(): \"%p\", continuing\n")));
//         } // end IF
//       } // end IF
      RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->abortConnections();
      RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->waitConnections();

      return;
    } // end IF
  } // end ELSE

  // step4: clean up
//   if (stressTestServer_in)
//   {
//     if (ACE_Reactor::instance()->cancel_timer(timerID,  // timer ID
//                                               NULL,     // pointer to args passed to handler
//                                               1) != 1)  // don't invoke handle_close() on handler
//     {
//       ACE_DEBUG((LM_ERROR,
//                  ACE_TEXT("failed to ACE_Reactor::cancel_timer(): \"%p\", continuing\n")));
//     } // end IF
//   } // end IF
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("closing %u connection(s)...\n"),
             RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->numConnections()));
  RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->abortConnections();
  RPG_NET_CONNECTIONMANAGER_SINGLETON::instance()->waitConnections();

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished working...\n")));
}

void
do_printVersion(const std::string& programName_in)
{
  ACE_TRACE(ACE_TEXT("::do_printVersion"));

  std::cout << programName_in << ACE_TEXT(" : ") << VERSION << std::endl;

  // create version string...
  // *IMPORTANT NOTE*: cannot use ACE_VERSION, as it doesn't contain the (potential) beta version
  // number... We need this, as the library soname is compared to this string.
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
ACE_TMAIN(int argc,
          ACE_TCHAR* argv[])
{
  ACE_TRACE(ACE_TEXT("::main"));

  // *PROCESS PROFILE*
  ACE_Profile_Timer process_profile;
  // start profile timer...
  process_profile.start();

  // step1: init
  // *PORTABILITY*: on Windows, we need to init ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
  if (ACE::init() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE::init(): \"%m\", aborting\n")));

    return EXIT_FAILURE;
  } // end IF
#endif

  // step1a set defaults
  std::string serverHostname         = NET_CLIENT_DEF_SERVER_HOSTNAME;
  unsigned long connectionInterval   = NET_CLIENT_DEF_SERVER_CONNECT_INTERVAL;
  bool logToFile                     = false;
  unsigned short serverPortNumber    = RPG_NET_DEF_LISTENING_PORT;
  bool stressTestServer              = false;
  bool traceInformation              = false;
  bool printVersionAndExit           = false;
  bool useThreadPool                 = NET_CLIENT_DEF_CLIENT_USES_TP;
  unsigned long numThreadPoolThreads = NET_CLIENT_DEF_NUM_TP_THREADS;

  // step1b: parse/process/validate configuration
  if (!(process_arguments(argc,
                          argv,
                          serverHostname,
                          connectionInterval,
                          logToFile,
                          serverPortNumber,
                          stressTestServer,
                          traceInformation,
                          printVersionAndExit,
                          useThreadPool,
                          numThreadPoolThreads)))
  {
    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

    return EXIT_FAILURE;
  } // end IF

  // step1c: validate arguments
  if (serverPortNumber <= 1023)
  {
    ACE_DEBUG((LM_WARNING,
               ACE_TEXT("using (privileged) port #: %d...\n"),
               serverPortNumber));

//     // make 'em learn...
//     print_usage(std::string(ACE::basename(argv[0])));
    //
//     return EXIT_FAILURE;
  } // end IF

  // step1d: set correct trace level
  //ACE_Trace::start_tracing();
  if (!traceInformation)
  {
    u_long process_priority_mask = (LM_SHUTDOWN |
                                    //LM_TRACE |  // <-- DISABLE trace messages !
                                    //LM_DEBUG |
                                    LM_INFO |
                                    LM_NOTICE |
                                    LM_WARNING |
                                    LM_STARTUP |
                                    LM_ERROR |
                                    LM_CRITICAL |
                                    LM_ALERT |
                                    LM_EMERGENCY);

    // set new mask...
    ACE_LOG_MSG->priority_mask(process_priority_mask,
                               ACE_Log_Msg::PROCESS);

    //ACE_LOG_MSG->stop_tracing();

    // don't go VERBOSE...
    //ACE_LOG_MSG->clr_flags(ACE_Log_Msg::VERBOSE_LITE);
  } // end IF

  // step1e: handle specific program modes
  if (printVersionAndExit)
  {
    do_printVersion(std::string(ACE::basename(argv[0])));

    return EXIT_SUCCESS;
  } // end IF

  ACE_High_Res_Timer timer;
  timer.start();
  // step2: do actual work
  do_work(serverHostname,
          connectionInterval,
          serverPortNumber,
          stressTestServer,
          useThreadPool,
          numThreadPoolThreads);
  timer.stop();

  // debug info
  std::string working_time_string;
  ACE_Time_Value working_time;
  timer.elapsed_time(working_time);
  RPG_Common_Tools::period2String(working_time,
                                  working_time_string);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("total working time (h:m:s.us): \"%s\"...\n"),
             working_time_string.c_str()));

  // *PORTABILITY*: on Windows, we must fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
  if (ACE::fini() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE::fini(): \"%m\", aborting\n")));

    return EXIT_FAILURE;
  } // end IF
#endif

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

  return EXIT_SUCCESS;
} // end main
