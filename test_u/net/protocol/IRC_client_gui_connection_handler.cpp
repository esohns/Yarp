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
#include "IRC_client_gui_connection_handler.h"

#include "IRC_client_defines.h"
#include "IRC_client_gui_defines.h"
#include "IRC_client_gui_messagehandler.h"

#include <rpg_net_protocol_tools.h>

#include <rpg_common_file_tools.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
void
disconnect_clicked_cb(GtkWidget* button_in,
                      gpointer userData_in)
{
  ACE_TRACE(ACE_TEXT("::disconnect_clicked_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("disconnect_clicked_cb...\n")));

  ACE_UNUSED_ARG(button_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->controller);

  try
  {
    data->controller->quit(std::string(IRC_CLIENT_DEF_LEAVE_REASON));
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
              ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::quit(), continuing\n")));
  }

  // *NOTE*: the server should close the connection after this...
}

void
join_clicked_cb(GtkWidget* button_in,
                gpointer userData_in)
{
  ACE_TRACE(ACE_TEXT("::join_clicked_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("join_clicked_cb...\n")));

  ACE_UNUSED_ARG(button_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);

  // step1: retrieve available data
  // retrieve buffer handle
  GtkEntryBuffer* buffer = NULL;
  GtkEntry* server_tab_channel_entry = NULL;
  server_tab_channel_entry = GTK_ENTRY(gtk_builder_get_object(data->builder,
                                                              ACE_TEXT_ALWAYS_CHAR("server_tab_channel_entry")));
  ACE_ASSERT(server_tab_channel_entry);
  buffer = gtk_entry_get_buffer(server_tab_channel_entry);
  ACE_ASSERT(buffer);

  // sanity check
  if (gtk_entry_buffer_get_length(buffer) == 0)
    return; // nothing to do...

  // retrieve textbuffer data
  std::string channel_string;
  // convert UTF8 to locale
  gchar* converted_text = NULL;
  GError* conversion_error = NULL;
  converted_text = g_locale_from_utf8(gtk_entry_buffer_get_text(buffer),   // text
                                      gtk_entry_buffer_get_length(buffer), // number of bytes
                                      NULL, // bytes read (don't care)
                                      NULL, // bytes written (don't care)
                                      &conversion_error); // return value: error
  if (conversion_error)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert message text: \"%s\", aborting\n"),
               conversion_error->message));

    // clean up
    g_error_free(conversion_error);
    gtk_entry_buffer_delete_text(buffer, // buffer
                                 0,      // start at position 0
                                 -1);    // delete everything

    return;
  } // end IF
  channel_string = converted_text;

  // sanity check: has '#' prefix ?
  if (channel_string.find('#', 0) != 0);
  {
    channel_string = ACE_TEXT_ALWAYS_CHAR("#");
    channel_string += converted_text;
  } // end IF

  // clean up
  g_free(converted_text);

  try
  {
    data->controller->join(channel_string);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::join(), continuing\n")));
  }

  // clear buffer
  gtk_entry_buffer_delete_text(buffer, // buffer
                               0,      // start at position 0
                               -1);    // delete everything
}

void
switch_channel_cb(GtkNotebook* notebook_in,
                  GtkNotebookPage* page_in,
                  guint pageNum_in,
                  gpointer userData_in)
{
  ACE_TRACE(ACE_TEXT("::switch_channel_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("switch_channel_cb...\n")));

  ACE_UNUSED_ARG(notebook_in);
  ACE_UNUSED_ARG(page_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->mainBuilder);
  ACE_ASSERT(data->connectionsLock);

  // check whether we just switched to the server log tab
  // --> disable corresponding widgets in the main UI
  // synch access
  {
    ACE_Guard<ACE_Thread_Mutex> aGuard(*data->connectionsLock);

    GtkHBox* main_send_hbox = GTK_HBOX(gtk_builder_get_object(data->mainBuilder,
                                                              ACE_TEXT_ALWAYS_CHAR("main_send_hbox")));
    ACE_ASSERT(main_send_hbox);
    gtk_widget_set_sensitive(GTK_WIDGET(main_send_hbox), (pageNum_in != 0));
  } // end lock scope
}
#ifdef __cplusplus
}
#endif /* __cplusplus */

IRC_Client_GUI_Connection_Handler::IRC_Client_GUI_Connection_Handler(GtkBuilder* builder_in,
                                                                     RPG_Net_Protocol_IIRCControl* controller_in,
                                                                     ACE_Thread_Mutex* lock_in,
                                                                     connections_t* connections_in,
                                                                     const std::string& label_in,
                                                                     const std::string& UIFileDirectory_in,
                                                                     GtkNotebook* notebook_in)
 : myUIFileDirectory(),
   myParent(notebook_in),
   myContextID(0)
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::IRC_Client_GUI_Connection_Handler"));

  // sanity check(s)
  ACE_ASSERT(builder_in);
  ACE_ASSERT(notebook_in);
  ACE_ASSERT(controller_in);
  ACE_ASSERT(lock_in);
  ACE_ASSERT(connections_in);
  if (!RPG_Common_File_Tools::isDirectory(UIFileDirectory_in))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid argument (was: \"%s\"): not a directory, aborting\n"),
               UIFileDirectory_in.c_str()));

    return;
  } // end IF

  myUIFileDirectory = UIFileDirectory_in;

  // init cb data
  myCBData.mainBuilder = builder_in;
  myCBData.builder = NULL;
  myCBData.controller = controller_in;
  myCBData.connectionsLock = lock_in;
  myCBData.connections = connections_in;

  // create new GtkBuilder
  myCBData.builder = gtk_builder_new();
  ACE_ASSERT(myCBData.builder);

  // init builder (load widget tree)
  std::string filename = myUIFileDirectory;
  filename += ACE_DIRECTORY_SEPARATOR_STR;
  filename += IRC_CLIENT_GUI_DEF_UI_SERVER_PAGE_FILE;
  if (!RPG_Common_File_Tools::isReadable(filename))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid UI file (was: \"%s\"): not readable, aborting\n"),
               filename.c_str()));

    return;
  } // end IF
  GError* error = NULL;
  gtk_builder_add_from_file(myCBData.builder,
                            filename.c_str(),
                            &error);
  if (error)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to gtk_builder_add_from_file(\"%s\"): \"%s\", aborting\n"),
               filename.c_str(),
               error->message));

    // clean up
    g_error_free(error);

    return;
  } // end IF

  // generate context ID
  // synch access
  {
    ACE_Guard<ACE_Thread_Mutex> aGuard(*myCBData.connectionsLock);

    // retrieve status bar
    GtkStatusbar* main_statusbar = GTK_STATUSBAR(gtk_builder_get_object(myCBData.mainBuilder,
                                                                        ACE_TEXT_ALWAYS_CHAR("main_statusbar")));
    ACE_ASSERT(main_statusbar);

    myContextID = gtk_statusbar_get_context_id(main_statusbar,
                                               IRC_CLIENT_GUI_DEF_CONTEXT_DESCRIPTION);
  } // end lock scope

  // add new server page to notebook
  // retrieve (dummy) parent window
  GtkWindow* parent = GTK_WINDOW(gtk_builder_get_object(myCBData.builder,
                                                        ACE_TEXT_ALWAYS_CHAR("server_tab_label_template")));
  ACE_ASSERT(parent);
  // retrieve server tab label
  GtkHBox* server_tab_label_hbox = GTK_HBOX(gtk_builder_get_object(myCBData.builder,
                                                                   ACE_TEXT_ALWAYS_CHAR("server_tab_label_hbox")));
  ACE_ASSERT(server_tab_label_hbox);
  g_object_ref(server_tab_label_hbox);
  gtk_container_remove(GTK_CONTAINER(parent), GTK_WIDGET(server_tab_label_hbox));
  // set tab label
  GtkLabel* server_tab_label = GTK_LABEL(gtk_builder_get_object(myCBData.builder,
                                                                ACE_TEXT_ALWAYS_CHAR("server_tab_label")));
  ACE_ASSERT(server_tab_label);
  // *TODO*: convert to UTF8 ?
  gtk_label_set_text(server_tab_label,
                     label_in.c_str());
  // retrieve (dummy) parent window
  parent = GTK_WINDOW(gtk_builder_get_object(myCBData.builder,
                                             ACE_TEXT_ALWAYS_CHAR("server_tab_template")));
  ACE_ASSERT(parent);
  // retrieve server tab
  GtkVBox* server_tab_vbox = GTK_VBOX(gtk_builder_get_object(myCBData.builder,
                                                             ACE_TEXT_ALWAYS_CHAR("server_tab_vbox")));
  ACE_ASSERT(server_tab_vbox);
  g_object_ref(server_tab_vbox);
  gtk_container_remove(GTK_CONTAINER(parent), GTK_WIDGET(server_tab_vbox));
  gint page_num = gtk_notebook_append_page(myParent,
                                           GTK_WIDGET(server_tab_vbox),
                                           GTK_WIDGET(server_tab_label_hbox));
  if (page_num == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to gtk_notebook_append_page(%@), aborting\n"),
               myParent));

    // clean up
    g_object_unref(server_tab_label_hbox);
    g_object_unref(server_tab_vbox);

    return;
  } // end IF
  // allow reordering
  gtk_notebook_set_tab_reorderable(myParent,
                                   GTK_WIDGET(server_tab_vbox),
                                   TRUE);

  // clean up
  g_object_unref(server_tab_label_hbox);
  g_object_unref(server_tab_vbox);

  // connect signal(s)
  GtkButton* button = GTK_BUTTON(gtk_builder_get_object(myCBData.builder,
                                                        ACE_TEXT_ALWAYS_CHAR("server_tab_label_button")));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(disconnect_clicked_cb),
                   &myCBData);
  button = GTK_BUTTON(gtk_builder_get_object(myCBData.builder,
                                             ACE_TEXT_ALWAYS_CHAR("server_tab_join_button")));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(join_clicked_cb),
                   &myCBData);
  // retrieve channel tabs
  GtkNotebook* server_tab_channel_tabs = GTK_NOTEBOOK(gtk_builder_get_object(myCBData.builder,
                                                                             ACE_TEXT_ALWAYS_CHAR("server_tab_channel_tabs")));
  ACE_ASSERT(server_tab_channel_tabs);
  g_signal_connect(server_tab_channel_tabs,
                   ACE_TEXT_ALWAYS_CHAR("switch-page"),
                   G_CALLBACK(switch_channel_cb),
                   &myCBData);

  // retrieve server log tab child
  GtkScrolledWindow* server_tab_log_scrolledwindow = GTK_SCROLLED_WINDOW(gtk_builder_get_object(myCBData.builder,
                                                                                                ACE_TEXT_ALWAYS_CHAR("server_tab_log_scrolledwindow")));
  ACE_ASSERT(server_tab_log_scrolledwindow);
  // disallow reordering the server log tab
  gtk_notebook_set_tab_reorderable(server_tab_channel_tabs,
                                   GTK_WIDGET(server_tab_log_scrolledwindow),
                                   FALSE);

  // create default IRC_Client_GUI_MessageHandler (== server log)
  // retrieve server log textview
  GtkTextView* server_tab_log_textview = GTK_TEXT_VIEW(gtk_builder_get_object(myCBData.builder,
                                                                              ACE_TEXT_ALWAYS_CHAR("server_tab_log_textview")));
  ACE_ASSERT(server_tab_log_textview);
  IRC_Client_GUI_MessageHandler* message_handler = NULL;
  try
  {
    message_handler = new IRC_Client_GUI_MessageHandler(server_tab_log_textview);
  }
  catch (const std::bad_alloc& exception)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught std::bad_alloc: \"%s\", aborting\n"),
               exception.what()));
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception, aborting\n")));
  }
  if (!message_handler)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to allocate IRC_Client_GUI_MessageHandler, aborting\n")));

    return;
  } // end IF

  // *NOTE*: the empty channel name string denotes the log handler !
  // *NOTE*: no updates yet --> no need for locking
  // *NOTE*: in theory, there is a race condition as the user may start
  // interacting with the new UI elements by now - as GTK will draw the new elements
  // only after we return, this is not really a problem...
  myMessageHandlers.insert(std::make_pair(std::string(), message_handler));

  // subscribe to updates from the controller
  try
  {
    myCBData.controller->subscribe(this);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::subscribe(%@), continuing\n"),
               this));
  }
}

IRC_Client_GUI_Connection_Handler::~IRC_Client_GUI_Connection_Handler()
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::~IRC_Client_GUI_Connection_Handler"));

  // unsubscribe to updates from the controller
  try
  {
    myCBData.controller->unsubscribe(this);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::unsubscribe(%@), continuing\n"),
               this));
  }

  GDK_THREADS_ENTER();

  std::string server_tab_label_text;
  // synch access
  {
    ACE_Guard<ACE_Thread_Mutex> aGuard(myLock);

    // clean up message handlers
    for (message_handlers_iterator_t iterator = myMessageHandlers.begin();
         iterator != myMessageHandlers.end();
         iterator++)
      delete (*iterator).second;
  } // end lock scope

  GtkLabel* server_tab_label = GTK_LABEL(gtk_builder_get_object(myCBData.builder,
                                                                ACE_TEXT_ALWAYS_CHAR("server_tab_label")));
  ACE_ASSERT(server_tab_label);
  // *TODO*: convert to locale ?
  server_tab_label_text = gtk_label_get_text(server_tab_label);

  // remove server page from parent notebook
  GtkVBox* server_tab_vbox = GTK_VBOX(gtk_builder_get_object(myCBData.builder,
                                                             ACE_TEXT_ALWAYS_CHAR("server_tab_vbox")));
  ACE_ASSERT(server_tab_vbox);
  gint page_num = gtk_notebook_page_num(myParent,
                                        GTK_WIDGET(server_tab_vbox));
  if (page_num >= 0)
    gtk_notebook_remove_page(myParent,
                             page_num);

  // clean up
  g_object_unref(myCBData.builder);

  GDK_THREADS_LEAVE();

  // remove ourselves from the connection list
  // synch access
  {
    ACE_Guard<ACE_Thread_Mutex> aGuard(*myCBData.connectionsLock);

    connections_iterator_t iterator = myCBData.connections->find(server_tab_label_text);
    if (iterator != myCBData.connections->end())
      myCBData.connections->erase(iterator);
  } // end lock scope
}

void
IRC_Client_GUI_Connection_Handler::start()
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::start"));

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("connected...\n")));
}

void
IRC_Client_GUI_Connection_Handler::notify(const RPG_Net_Protocol_IRCMessage& message_in)
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::notify"));

  // sanity check(s)
  ACE_ASSERT(myCBData.builder);

  switch (message_in.command.discriminator)
  {
    case RPG_Net_Protocol_IRCMessage::Command::NUMERIC:
    {
      switch (message_in.command.numeric)
      {
        case RPG_Net_Protocol_IRC_Codes::RPL_WELCOME:
        {
          GDK_THREADS_ENTER();

          // retrieve button handle
          GtkButton* button = NULL;
          button = GTK_BUTTON(gtk_builder_get_object(myCBData.builder,
                                                     ACE_TEXT_ALWAYS_CHAR("server_tab_join_button")));
          ACE_ASSERT(button);
          gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

          GDK_THREADS_LEAVE();

          // *WARNING*: falls through !
        }
        case RPG_Net_Protocol_IRC_Codes::RPL_YOURHOST:
        case RPG_Net_Protocol_IRC_Codes::RPL_CREATED:
        case RPG_Net_Protocol_IRC_Codes::RPL_MYINFO:
        case RPG_Net_Protocol_IRC_Codes::RPL_PROTOCTL:
        case RPG_Net_Protocol_IRC_Codes::RPL_YOURID:
        case RPG_Net_Protocol_IRC_Codes::RPL_STATSDLINE:
        case RPG_Net_Protocol_IRC_Codes::RPL_LUSERCLIENT:
        case RPG_Net_Protocol_IRC_Codes::RPL_LUSERCHANNELS:
        case RPG_Net_Protocol_IRC_Codes::RPL_LUSERME:
        case RPG_Net_Protocol_IRC_Codes::RPL_LOCALUSERS:
        case RPG_Net_Protocol_IRC_Codes::RPL_GLOBALUSERS:
          log(message_in); break;
        case RPG_Net_Protocol_IRC_Codes::RPL_NOTOPIC:
        case RPG_Net_Protocol_IRC_Codes::RPL_TOPIC:
        {
          // retrieve channel name
          RPG_Net_Protocol_ParametersIterator_t iterator = message_in.params.begin();
          iterator++;

          std::string topic_label = ((message_in.command.numeric == RPG_Net_Protocol_IRC_Codes::RPL_NOTOPIC) ? IRC_CLIENT_GUI_DEF_TOPIC_LABEL_TEXT
            : message_in.params.back());

          // retrieve message handler for this channel
          // synch access
          {
            ACE_Guard<ACE_Thread_Mutex> aGuard(myLock);

            message_handlers_iterator_t handler_iterator = myMessageHandlers.find(*iterator);
            if (handler_iterator != myMessageHandlers.end())
              (*handler_iterator).second->setTopic(topic_label);
          } // end lock scope

          break;
        }
        case RPG_Net_Protocol_IRC_Codes::RPL_NAMREPLY:
        {
          // re-retrieve channel name
          RPG_Net_Protocol_ParametersIterator_t iterator = message_in.params.end();
          iterator--; iterator--;

          // bisect (WS-separated) nicknames from the final parameter string
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("bisecting nicknames: \"%s\"...\n"),
//                      message_in.params.back().c_str()));

          std::string::size_type current_position = 0;
          std::string::size_type last_position = 0;
          std::string nick;
          string_list_t list;
          do
          {
            current_position = message_in.params.back().find(' ', last_position);

            nick = message_in.params.back().substr(last_position,
                                                   (((current_position == std::string::npos) ? message_in.params.back().size()
                                                                                             : current_position) - last_position));

            list.push_back(nick);

            // advance
            last_position = current_position + 1;
          } while (current_position != std::string::npos);

          // retrieve message handler for this channel
          // synch access
          {
            ACE_Guard<ACE_Thread_Mutex> aGuard(myLock);

            message_handlers_iterator_t handler_iterator = myMessageHandlers.find(*iterator);
            if (handler_iterator != myMessageHandlers.end())
              (*handler_iterator).second->appendMembers(list);
          } // end lock scope

          break;
        }
        case RPG_Net_Protocol_IRC_Codes::RPL_ENDOFNAMES:
        {
          // retrieve channel name
          RPG_Net_Protocol_ParametersIterator_t iterator = message_in.params.end();
          iterator--; iterator--;

          // retrieve message handler for this channel
          // synch access
          {
            ACE_Guard<ACE_Thread_Mutex> aGuard(myLock);

            message_handlers_iterator_t handler_iterator = myMessageHandlers.find(*iterator);
            if (handler_iterator != myMessageHandlers.end())
              (*handler_iterator).second->endMembers();
          } // end lock scope

          break;
        }
        case RPG_Net_Protocol_IRC_Codes::RPL_MOTDSTART:
        case RPG_Net_Protocol_IRC_Codes::RPL_MOTD:
        case RPG_Net_Protocol_IRC_Codes::RPL_ENDOFMOTD:
          log(message_in); break;
        default:
        {
//           ACE_DEBUG((LM_WARNING,
//                      ACE_TEXT("received unhandled (numeric) command/reply: \"%s\" (%u), continuing\n"),
//                      RPG_Net_Protocol_Tools::IRCCode2String(message_in.command.numeric).c_str(),
//                      message_in.command.numeric));

          // unhandled numeric reply/error --> print to statusbar
          // synch access
          {
            ACE_Guard<ACE_Thread_Mutex> aGuard(*myCBData.connectionsLock);

            GtkStatusbar* main_statusbar = GTK_STATUSBAR(gtk_builder_get_object(myCBData.mainBuilder,
                                                                                ACE_TEXT_ALWAYS_CHAR("main_statusbar")));
            ACE_ASSERT(main_statusbar);

            gtk_statusbar_push(main_statusbar,
                               myContextID,
                               RPG_Net_Protocol_Tools::IRCMessage2String(message_in).c_str());
          } // end lock scope

          message_in.dump_state();

          break;
        }
      } // end SWITCH

      break;
    }
    case RPG_Net_Protocol_IRCMessage::Command::STRING:
    {
      RPG_Net_Protocol_IRCMessage::CommandType command = RPG_Net_Protocol_Tools::IRCCommandString2Type(*message_in.command.string);
      switch (command)
      {
        case RPG_Net_Protocol_IRCMessage::JOIN:
        {
          GDK_THREADS_ENTER();

          // retrieve channel tabs
          GtkNotebook* server_tab_channel_tabs = GTK_NOTEBOOK(gtk_builder_get_object(myCBData.builder,
                                                                                     ACE_TEXT_ALWAYS_CHAR("server_tab_channel_tabs")));
          ACE_ASSERT(server_tab_channel_tabs);

          // create new IRC_Client_GUI_MessageHandler
          IRC_Client_GUI_MessageHandler* message_handler = NULL;
          try
          {
            message_handler = new IRC_Client_GUI_MessageHandler(myCBData.controller,
                                                                message_in.params.front(),
                                                                myUIFileDirectory,
                                                                server_tab_channel_tabs);
          }
          catch (const std::bad_alloc& exception)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("caught std::bad_alloc: \"%s\", aborting\n"),
                       exception.what()));
          }
          catch (...)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("caught exception, aborting\n")));
          }
          if (!message_handler)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("failed to allocate IRC_Client_GUI_MessageHandler, aborting\n")));

            break;
          } // end IF

          // synch access
          {
            ACE_Guard<ACE_Thread_Mutex> aGuard(myLock);

            myMessageHandlers.insert(std::make_pair(message_in.params.front(), message_handler));

            // check whether this is the first channel of the first connection
            // --> enable corresponding widgets in the main UI
            // synch access
            {
              ACE_Guard<ACE_Thread_Mutex> aGuard2(*myCBData.connectionsLock);

              if ((myCBData.connections->size() == 1) &&
                  (myMessageHandlers.size() == 2)) // server log + first channel
              {
                GtkHBox* main_send_hbox = GTK_HBOX(gtk_builder_get_object(myCBData.mainBuilder,
                                                                          ACE_TEXT_ALWAYS_CHAR("main_send_hbox")));
                ACE_ASSERT(main_send_hbox);
                gtk_widget_set_sensitive(GTK_WIDGET(main_send_hbox),
                                         TRUE);
              } // end IF
            } // end lock scope
          } // end lock scope

          GDK_THREADS_LEAVE();

          break;
        }
        case RPG_Net_Protocol_IRCMessage::PART:
        {
          // retrieve message handler
          // synch access
          {
            ACE_Guard<ACE_Thread_Mutex> aGuard(myLock);

            message_handlers_iterator_t iterator = myMessageHandlers.find(message_in.params.back());
            if (iterator != myMessageHandlers.end())
            {
              // activate another channel (page) ?
              GDK_THREADS_ENTER();

              // retrieve channel tabs
              GtkNotebook* server_tab_channel_tabs = GTK_NOTEBOOK(gtk_builder_get_object(myCBData.builder,
                                                                                         ACE_TEXT_ALWAYS_CHAR("server_tab_channel_tabs")));
              ACE_ASSERT(server_tab_channel_tabs);

              // clean up
              delete (*iterator).second;
              myMessageHandlers.erase(iterator);

              // check whether this was the last channel of the last connection
              // --> disable corresponding widgets in the main UI
              // synch access
              {
                ACE_Guard<ACE_Thread_Mutex> aGuard2(*myCBData.connectionsLock);

                if ((myCBData.connections->size() == 1) &&
                    (myMessageHandlers.size() == 1)) // server log
                {
                  GtkHBox* main_send_hbox = GTK_HBOX(gtk_builder_get_object(myCBData.mainBuilder,
                                                                            ACE_TEXT_ALWAYS_CHAR("main_send_hbox")));
                  ACE_ASSERT(main_send_hbox);
                  gtk_widget_set_sensitive(GTK_WIDGET(main_send_hbox),
                                           FALSE);
                } // end IF
              } // end lock scope

              GDK_THREADS_LEAVE();
            } // end IF
          } // end lock scope

          break;
        }
        case RPG_Net_Protocol_IRCMessage::PRIVMSG:
        case RPG_Net_Protocol_IRCMessage::NOTICE:
        case RPG_Net_Protocol_IRCMessage::ERROR:
        {
          // retrieve channel name
          // *TODO*: currently, this works for PRIVMSG...
          RPG_Net_Protocol_ParametersIterator_t iterator = message_in.params.begin();

          std::string message_text;
          if (!message_in.prefix.origin.empty())
          {
            message_text += ACE_TEXT("<");
            message_text += message_in.prefix.origin;
            message_text += ACE_TEXT("> ");
          } // end IF
          message_text += message_in.params.back();
          message_text += ACE_TEXT_ALWAYS_CHAR("\n");

          // retrieve message handler
          // synch access
          {
            ACE_Guard<ACE_Thread_Mutex> aGuard(myLock);

            // *NOTE*: the empty string denotes the server log handler
            message_handlers_iterator_t handler_iterator = myMessageHandlers.find(((command == RPG_Net_Protocol_IRCMessage::NOTICE) ||
                                                                                   (command == RPG_Net_Protocol_IRCMessage::ERROR)) ? std::string()
                                                                                                                        : *iterator);
            if (handler_iterator != myMessageHandlers.end())
              (*handler_iterator).second->queueForDisplay(message_text);
          } // end lock scope

          break;
        }
        case RPG_Net_Protocol_IRCMessage::MODE:
        case RPG_Net_Protocol_IRCMessage::PING:
        {

          break;
        }
        default:
        {
//           ACE_DEBUG((LM_WARNING,
//                      ACE_TEXT("received unhandled command (was: \"%s\"), continuing\n"),
//                      message_in.command.string->c_str()));

          // unhandled command --> print to statusbar
          // synch access
          {
            ACE_Guard<ACE_Thread_Mutex> aGuard(*myCBData.connectionsLock);

            GtkStatusbar* main_statusbar = GTK_STATUSBAR(gtk_builder_get_object(myCBData.mainBuilder,
                                                                                ACE_TEXT_ALWAYS_CHAR("main_statusbar")));
            ACE_ASSERT(main_statusbar);

            gtk_statusbar_push(main_statusbar,
                               myContextID,
                               RPG_Net_Protocol_Tools::IRCMessage2String(message_in).c_str());
          } // end lock scope

          message_in.dump_state();

          break;
        }
      } // end SWITCH

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid command type (was: %u), aborting\n"),
                 message_in.command.discriminator));

      break;
    }
  } // end SWITCH
}

void
IRC_Client_GUI_Connection_Handler::end()
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::end"));

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("connection lost...\n")));

  // commit suicide
  delete this;
}

RPG_Net_Protocol_IIRCControl*
IRC_Client_GUI_Connection_Handler::getController()
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::getController"));

  // sanity check(s)
  ACE_ASSERT(myCBData.controller);

  return myCBData.controller;
}

const std::string
IRC_Client_GUI_Connection_Handler::getActiveChannel()
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::getActiveChannel"));

  // sanity check(s)
  ACE_ASSERT(myCBData.builder);

  // init result
  std::string result;

  // retrieve server tab channel tabs handle
  GtkNotebook* server_tab_channel_tabs = GTK_NOTEBOOK(gtk_builder_get_object(myCBData.builder,
                                                                             ACE_TEXT_ALWAYS_CHAR("server_tab_channel_tabs")));
  ACE_ASSERT(server_tab_channel_tabs);
  gint page_num = gtk_notebook_get_current_page(server_tab_channel_tabs);
  if (page_num == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to gtk_notebook_get_current_page(%@): no pages, aborting\n"),
               server_tab_channel_tabs));

    return result;
  } // end IF

  // sanity check
  // server log ? --> no active channel --> return empty string
  if (page_num == 0)
  {
    ACE_DEBUG((LM_WARNING,
               ACE_TEXT("no active channel, returning\n")));

    return result;
  } // end IF

  GtkWidget* channel_tab = gtk_notebook_get_nth_page(server_tab_channel_tabs,
                                                     page_num);
  ACE_ASSERT(channel_tab);
  for (message_handlers_iterator_t iterator = myMessageHandlers.begin();
       iterator != myMessageHandlers.end();
       iterator++)
  {
    if ((*iterator).second->getTopLevel() == channel_tab)
    {
      result = (*iterator).first;

      break;
    } // end IF
  } // end FOR

  // sanity check
  if (result.empty())
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to lookup active channel, aborting\n")));

  return result;
}

IRC_Client_GUI_MessageHandler*
IRC_Client_GUI_Connection_Handler::getActiveHandler()
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::getActiveHandler"));

  // sanity check(s)
  ACE_ASSERT(myCBData.builder);

  // retrieve server tab channel tabs handle
  GtkNotebook* server_tab_channel_tabs = GTK_NOTEBOOK(gtk_builder_get_object(myCBData.builder,
                                                                             ACE_TEXT_ALWAYS_CHAR("server_tab_channel_tabs")));
  ACE_ASSERT(server_tab_channel_tabs);
  gint page_num = gtk_notebook_get_current_page(server_tab_channel_tabs);
  if (page_num == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to gtk_notebook_get_current_page(%@): no pages, aborting\n"),
               server_tab_channel_tabs));

    return NULL;
  } // end IF
  ACE_ASSERT(page_num >= 0);
  GtkWidget* channel_tab = gtk_notebook_get_nth_page(server_tab_channel_tabs,
                                                     page_num);
  ACE_ASSERT(channel_tab);
  for (message_handlers_iterator_t iterator = myMessageHandlers.begin();
       iterator != myMessageHandlers.end();
       iterator++)
  {
    if ((*iterator).second->getTopLevel() == channel_tab)
      return (*iterator).second;
  } // end FOR

  ACE_DEBUG((LM_ERROR,
             ACE_TEXT("failed to lookup active handler, aborting\n")));

  return NULL;
}

// IRC_Client_GUI_MessageHandler*
// IRC_Client_GUI_Connection_Handler::getHandler(const std::string& channelName_in)
// {
//   ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::getHandler"));
//
//   for (message_handlers_iterator_t iterator = myMessageHandlers.begin();
//        iterator != myMessageHandlers.end();
//        iterator++)
//   {
//     if ((*iterator).first == channelName_in)
//       return (*iterator).second;
//   } // end FOR
//
//   ACE_DEBUG((LM_ERROR,
//              ACE_TEXT("failed to lookup handler (channel: \"%s\"), aborting\n"),
//              channelName_in.c_str()));
//
//   return NULL;
// }

void
IRC_Client_GUI_Connection_Handler::log(const RPG_Net_Protocol_IRCMessage& message_in)
{
  ACE_TRACE(ACE_TEXT("IRC_Client_GUI_Connection_Handler::log"));

  // --> pass to server log
  std::string message_text = message_in.params.back();
  message_text += ACE_TEXT_ALWAYS_CHAR("\n");

  // retrieve message handler
  // synch access
  {
    ACE_Guard<ACE_Thread_Mutex> aGuard(myLock);

    message_handlers_iterator_t handler_iterator = myMessageHandlers.find(std::string());
    ACE_ASSERT(handler_iterator != myMessageHandlers.end());
    (*handler_iterator).second->queueForDisplay(message_text);
  } // end lock scope
}
