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
#include "IRC_client_gui_callbacks.h"

#include "IRC_client_defines.h"
#include "IRC_client_gui_defines.h"
#include "IRC_client_gui_common.h"
#include "IRC_client_gui_connection.h"
#include "IRC_client_gui_messagehandler.h"
#include "IRC_client_tools.h"

#include <rpg_net_protocol_defines.h>
#include <rpg_net_protocol_module_IRChandler.h>
#include <rpg_net_protocol_tools.h>

#include <rpg_net_defines.h>

#include <rpg_common_macros.h>

#include <ace/OS.h>

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
void
connect_clicked_cb(GtkWidget* button_in,
                   gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::connect_clicked_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("connect_clicked_cb...\n")));

  GtkButton* button = GTK_BUTTON(button_in);
  main_cb_data_t* data = ACE_static_cast(main_cb_data_t*,
                                         userData_in);

  // sanity check(s)
  ACE_ASSERT(button);
  ACE_ASSERT(data);
  ACE_ASSERT(data->allocator);
  ACE_ASSERT(data->builder);

  // step1: retrieve active phonebook entry
  // retrieve serverlist handle
  GtkComboBox* main_servers_combobox = GTK_COMBO_BOX(gtk_builder_get_object(data->builder,
                                                                            ACE_TEXT_ALWAYS_CHAR("main_servers_combobox")));
  ACE_ASSERT(main_servers_combobox);
  GtkTreeIter active_iter;
  //   GValue active_value;
  gchar* active_value = NULL;
  std::string entry_name;
  if (!gtk_combo_box_get_active_iter(main_servers_combobox,
                                     &active_iter))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to gtk_combo_box_get_active_iter(%@), aborting\n"),
               main_servers_combobox));

    return;
  } // end IF
  //   gtk_tree_model_get_value(gtk_combo_box_get_model(serverlist),
  //                            &active_iter,
  //                            0, &active_value);
  gtk_tree_model_get(gtk_combo_box_get_model(main_servers_combobox),
                     &active_iter,
                     0, &active_value,
                     -1);
  //   ACE_ASSERT(G_VALUE_HOLDS_STRING(&active_value));
  ACE_ASSERT(active_value);
  // *TODO*: convert UTF8 to locale ?
  entry_name = active_value;
  //   entry_name = g_value_get_string(&active_value);

  // clean up
  //   g_value_unset(&active_value);
  g_free(active_value);

  RPG_Net_Protocol_ServersIterator_t phonebook_iter = data->phoneBook.servers.find(entry_name);
  if (phonebook_iter == data->phoneBook.servers.end())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to lookup active phonebook entry (was: \"%s\"), aborting\n"),
               entry_name.c_str()));

    return;
  } // end IF

  RPG_Net_Protocol_IRCLoginOptions loginOptions = data->loginOptions;
  // step2: get nickname...
  GtkEntry* main_entry_entry = GTK_ENTRY(gtk_builder_get_object(data->builder,
                                                                ACE_TEXT_ALWAYS_CHAR("main_entry_entry")));
  ACE_ASSERT(main_entry_entry);
  gtk_entry_set_text(main_entry_entry,
                     data->loginOptions.nick.c_str());
  gtk_editable_select_region(GTK_EDITABLE(main_entry_entry),
                             0, -1);
  // retrieve entry dialog handle
  GtkDialog* main_entry_dialog = GTK_DIALOG(gtk_builder_get_object(data->builder,
                                                                   ACE_TEXT_ALWAYS_CHAR("main_entry_dialog")));
  ACE_ASSERT(main_entry_dialog);
  gtk_window_set_title(GTK_WINDOW(main_entry_dialog),
                        IRC_CLIENT_GUI_DEF_NICK_DIALOG_TITLE);
  if (gtk_dialog_run(main_entry_dialog))
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("connection cancelled...\n")));

    // clean up
    gtk_entry_buffer_delete_text(gtk_entry_get_buffer(main_entry_entry),
                                 0, -1);

    gtk_widget_hide(GTK_WIDGET(main_entry_dialog));

    return;
  } // end IF
  gtk_widget_hide(GTK_WIDGET(main_entry_dialog));
  loginOptions.nick = gtk_entry_get_text(main_entry_entry);
  // clean up
  gtk_entry_buffer_delete_text(gtk_entry_get_buffer(main_entry_entry),
                               0, -1);

  // step3: create/init new final module
  std::string module_name = ACE_TEXT_ALWAYS_CHAR("IRCHandler");
  RPG_Net_Protocol_Module_IRCHandler_Module* module = NULL;
  try
  {
    module = new RPG_Net_Protocol_Module_IRCHandler_Module(module_name,
                                                           NULL);
  }
  catch (const std::bad_alloc& exception)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught std::bad_alloc: \"%s\", aborting\n"),
               exception.what()));

    return;
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to allocate RPG_Net_Protocol_Module_IRCHandler_Module, aborting\n")));

    return;
  }
  if (!module)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to allocate RPG_Net_Protocol_Module_IRCHandler_Module, aborting\n")));

    return;
  } // end IF

  RPG_Net_Protocol_Module_IRCHandler* IRChandler_impl = NULL;
  IRChandler_impl = ACE_dynamic_cast(RPG_Net_Protocol_Module_IRCHandler*,
                                     module->writer());
  if (!IRChandler_impl)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("ACE_dynamic_cast(RPG_Net_Protocol_Module_IRCHandler) failed, aborting\n")));

    // clean up
    delete module;

    return;
  } // end IF
  if (!IRChandler_impl->init(data->allocator,              // message allocator
                             RPG_NET_PROTOCOL_DEF_NETWORK_BUFFER_SIZE,
                             RPG_NET_DEF_CLIENT_PING_PONG, // auto-answer "ping" as a client ?...
                             false))                       // clients print ('.') dots for received "pings"...
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to initialize module: \"%s\", aborting\n"),
               module->name()));

    // clean up
    delete module;

    return;
  } // end IF

  // step4: create/init new connection handler
  // retrieve server tabs handle
  GtkNotebook* main_server_tabs = GTK_NOTEBOOK(gtk_builder_get_object(data->builder,
                                                                      ACE_TEXT_ALWAYS_CHAR("main_server_tabs")));
  ACE_ASSERT(main_server_tabs);
  IRC_Client_GUI_Connection* connection = NULL;
  try
  {
    connection = new IRC_Client_GUI_Connection(data->builder,
                                               IRChandler_impl,
                                               &data->connectionsLock,
                                               &data->connections,
                                               entry_name,
                                               data->UIFileDirectory,
                                               main_server_tabs);
  }
  catch (const std::bad_alloc& exception)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught std::bad_alloc: \"%s\", aborting\n"),
               exception.what()));

    // clean up
    delete module;

    return;
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to allocate IRC_Client_GUI_Connection, aborting\n")));

    // clean up
    delete module;

    return;
  }
  if (!connection)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to allocate IRC_Client_GUI_Connection, aborting\n")));

    // clean up
    delete module;

    return;
  } // end IF

  // step5: connect to the server
  bool connected = false;
  for (RPG_Net_Protocol_PortRangesIterator_t port_range_iter = (*phonebook_iter).second.listeningPorts.begin();
       port_range_iter != (*phonebook_iter).second.listeningPorts.end();
       port_range_iter++)
  {
    // port range ?
    if ((*port_range_iter).first < (*port_range_iter).second)
      for (unsigned short current_port = (*port_range_iter).first;
           current_port <= (*port_range_iter).second;
           current_port++)
    {
      if (IRC_Client_Tools::connect(data->allocator,                   // message allocator
                                    loginOptions,                      // login options
                                    data->debugScanner,                // debug scanner ?
                                    data->debugParser,                 // debug parser ?
                                    data->statisticsReportingInterval, // statistics reporting interval [seconds: 0 --> OFF]
                                    (*phonebook_iter).second.hostName, // server hostname
                                    current_port,                      // server listening port
                                    module))                           // final module handle
      {
        connected = true;

        break;
      } // end IF
    } // end FOR
    else
      if (IRC_Client_Tools::connect(data->allocator,                   // message allocator
                                    loginOptions,                      // login options
                                    data->debugScanner,                // debug scanner ?
                                    data->debugParser,                 // debug parser ?
                                    data->statisticsReportingInterval, // statistics reporting interval [seconds: 0 --> OFF]
                                    (*phonebook_iter).second.hostName, // server hostname
                                    (*port_range_iter).first,          // server listening port
                                    module))                           // final module handle
        connected = true;

    if (connected)
      break;

    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("failed to connect to server(\"%s\"), retrying\n"),
               (*phonebook_iter).second.hostName.c_str()));
  } // end FOR
  if (!connected)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to connect to server(\"%s\"), aborting\n"),
               (*phonebook_iter).second.hostName.c_str()));

    // clean up
    delete module;
    delete connection;

    return;
  } // end IF

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("registering...\n")));

  // step6: register our connection with the server
  try
  {
    // *NOTE*: this entails a little delay waiting for the welcome notice...
    IRChandler_impl->registerConnection(loginOptions);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::registerConnection(), continuing\n")));
  }

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("registering...DONE\n")));

  // step7: remember this connection
  // synch access
  {
    ACE_Guard<ACE_Thread_Mutex> aGuard(data->connectionsLock);

    // *TODO*: who deletes the module ? (the stream won't do it !)
    data->connections.insert(std::make_pair(entry_name, connection));
  } // end lock scope
}

gboolean
send_entry_kb_focused_cb(GtkWidget* widget_in,
                         GdkEventFocus* event_in,
                         gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::send_entry_kb_focused_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("send_entry_kb_focused_cb...\n")));

  ACE_UNUSED_ARG(widget_in);
  ACE_UNUSED_ARG(event_in);
  main_cb_data_t* data = ACE_static_cast(main_cb_data_t*,
                                         userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);

  // make the "change" button the default widget...
  GtkButton* main_send_button = GTK_BUTTON(gtk_builder_get_object(data->builder,
                                                                  ACE_TEXT_ALWAYS_CHAR("main_send_button")));
  ACE_ASSERT(main_send_button);
  gtk_widget_grab_default(GTK_WIDGET(main_send_button));

  // propagate the event further...
  return FALSE;
}

void
send_clicked_cb(GtkWidget* button_in,
                gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::send_clicked_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("send_clicked_cb...\n")));

  ACE_UNUSED_ARG(button_in);
  main_cb_data_t* data = ACE_static_cast(main_cb_data_t*,
                                         userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);

  // step0: retrieve active connection
  GtkNotebook* main_server_tabs = NULL;
  main_server_tabs = GTK_NOTEBOOK(gtk_builder_get_object(data->builder,
                                                         ACE_TEXT_ALWAYS_CHAR("main_server_tabs")));
  ACE_ASSERT(main_server_tabs);
  gint server_tab_num = gtk_notebook_get_current_page(main_server_tabs);
  ACE_ASSERT(server_tab_num >= 0);
  GtkWidget* server_tab_child = gtk_notebook_get_nth_page(main_server_tabs,
                                                          server_tab_num);
  ACE_ASSERT(server_tab_child);
  // *TODO*: the structure of the tab label is an implementation detail
  // --> should be encapsulated by the connection somehow...
  GtkHBox* server_tab_label_hbox = GTK_HBOX(gtk_notebook_get_tab_label(main_server_tabs,
                                                                       server_tab_child));
  ACE_ASSERT(server_tab_label_hbox);
  GList* server_tab_label_children = gtk_container_get_children(GTK_CONTAINER(server_tab_label_hbox));
  ACE_ASSERT(server_tab_label_children);
  GtkLabel* server_tab_label = GTK_LABEL(g_list_first(server_tab_label_children)->data);
  ACE_ASSERT(server_tab_label);
  std::string connection = gtk_label_get_text(server_tab_label);
  connections_iterator_t connections_iterator = data->connections.find(connection);
  if (connections_iterator == data->connections.end())
  {
    ACE_DEBUG((LM_ERROR,
              ACE_TEXT("failed to lookup active connection (was: \"%s\"), aborting\n"),
              connection.c_str()));

    return;
  } // end IF

  // step1: retrieve available data
  // retrieve buffer handle
  GtkEntryBuffer* buffer = NULL;
  GtkEntry* main_send_entry = NULL;
  main_send_entry = GTK_ENTRY(gtk_builder_get_object(data->builder,
                                                     ACE_TEXT_ALWAYS_CHAR("main_send_entry")));
  ACE_ASSERT(main_send_entry);
  buffer = gtk_entry_get_buffer(main_send_entry);
  ACE_ASSERT(buffer);

  // sanity check
  if (gtk_entry_buffer_get_length(buffer) == 0)
    return; // nothing to do...

  // retrieve textbuffer data
  std::string message_string = IRC_Client_Tools::UTF82Locale(gtk_entry_buffer_get_text(buffer),    // text
                                                             gtk_entry_buffer_get_length(buffer)); // number of bytes
  if (message_string.empty())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert message text: \"%s\", aborting\n")));

    // clean up
    gtk_entry_buffer_delete_text(buffer, // buffer
                                 0,      // start at position 0
                                 -1);    // delete everything

    return;
  } // end IF

  // step2: retrieve active handler (channel/nick)
  std::string active_id = (*connections_iterator).second->getActiveID();
  // sanity check
  if (active_id.empty())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("no active handler, aborting\n")));

    return;
  } // end IF

  // step3: pass data to controller
  // *TODO*: allow multicast ?
  string_list_t receivers;
  receivers.push_back(active_id);
  try
  {
    (*connections_iterator).second->getController()->send(receivers,
                                                          message_string);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::send(), continuing\n")));
  }

  // step4: echo data locally...
  message_string.insert(0, ACE_TEXT("<me> "));
  message_string += ACE_TEXT_ALWAYS_CHAR("\n");
  IRC_Client_GUI_MessageHandler* message_handler = (*connections_iterator).second->getActiveHandler();
  ACE_ASSERT(message_handler);
  try
  {
    message_handler->queueForDisplay(message_string);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in IRC_Client_GUI_MessageHandler::queueForDisplay(), continuing\n")));
  }

  // clear buffer
  gtk_entry_buffer_delete_text(buffer, // buffer
                               0,      // start at position 0
                               -1);    // delete everything
}

gint
quit_activated_cb(GtkWidget* widget_in,
                  GdkEvent* event_in,
                  gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::quit_activated_cb"));

  ACE_UNUSED_ARG(widget_in);
  ACE_UNUSED_ARG(event_in);
  ACE_UNUSED_ARG(userData_in);

// leave GTK
  gtk_main_quit();

// destroy the toplevel widget
  return TRUE;
}

void
disconnect_clicked_cb(GtkWidget* button_in,
                      gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::disconnect_clicked_cb"));

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
    data->controller->quit(std::string(IRC_CLIENT_DEF_IRC_LEAVE_REASON));
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
              ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::quit(), continuing\n")));
  }

  // *NOTE*: the server should close the connection after this...
}

gboolean
nick_entry_kb_focused_cb(GtkWidget* widget_in,
                         GdkEventFocus* event_in,
                         gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::nick_entry_kb_focused_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("nick_entry_kb_focused_cb...\n")));

  ACE_UNUSED_ARG(widget_in);
  ACE_UNUSED_ARG(event_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);

  // make the "change" button the default widget...
  GtkButton* server_tab_nick_button = GTK_BUTTON(gtk_builder_get_object(data->builder,
                                                                        ACE_TEXT_ALWAYS_CHAR("server_tab_nick_button")));
  ACE_ASSERT(server_tab_nick_button);
  gtk_widget_grab_default(GTK_WIDGET(server_tab_nick_button));

  // propagate the event further...
  return FALSE;
}

void
change_clicked_cb(GtkWidget* button_in,
                  gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::change_clicked_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("change_clicked_cb...\n")));

  ACE_UNUSED_ARG(button_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);

  // step1: retrieve available data
  // retrieve buffer handle
  GtkEntry* server_tab_nick_entry = GTK_ENTRY(gtk_builder_get_object(data->builder,
                                                                     ACE_TEXT_ALWAYS_CHAR("server_tab_nick_entry")));
  ACE_ASSERT(server_tab_nick_entry);
  GtkEntryBuffer* buffer = gtk_entry_get_buffer(server_tab_nick_entry);
  ACE_ASSERT(buffer);

  // sanity check
  if (gtk_entry_buffer_get_length(buffer) == 0)
    return; // nothing to do...

  // retrieve textbuffer data
  std::string nick_string = IRC_Client_Tools::UTF82Locale(gtk_entry_buffer_get_text(buffer),    // text
                                                          gtk_entry_buffer_get_length(buffer)); // number of bytes
  if (nick_string.empty())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert nickname: \"%s\", aborting\n")));

    // clean up
    gtk_entry_buffer_delete_text(buffer, // buffer
                                 0,      // start at position 0
                                 -1);    // delete everything

    return;
  } // end IF

  // sanity check: <= IRC_CLIENT_CNF_IRC_MAX_NICK_LENGTH characters ?
  // *TODO*: support the NICKLEN=xxx "feature" of the server...
  if (nick_string.size() > IRC_CLIENT_CNF_IRC_MAX_NICK_LENGTH);
    nick_string.resize(IRC_CLIENT_CNF_IRC_MAX_NICK_LENGTH);

  try
  {
    data->controller->nick(nick_string);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::nick(), continuing\n")));
  }

  // clear buffer
  gtk_entry_buffer_delete_text(buffer, // buffer
                               0,      // start at position 0
                               -1);    // delete everything
}


void
usersbox_changed_cb(GtkWidget* combobox_in,
                    gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::usersbox_changed_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("usersbox_changed_cb...\n")));

  ACE_UNUSED_ARG(combobox_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(combobox_in);
  ACE_ASSERT(data);
  ACE_ASSERT(data->connection);

  // step1: retrieve active users entry
  // retrieve server tab users combobox handle
  GtkComboBox* server_tab_users_combobox = GTK_COMBO_BOX(combobox_in);
  ACE_ASSERT(server_tab_users_combobox);
  GtkTreeIter active_iter;
  //   GValue active_value;
  gchar* user_value = NULL;
  if (!gtk_combo_box_get_active_iter(server_tab_users_combobox,
                                     &active_iter))
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("failed to gtk_combo_box_get_active_iter(%@), aborting\n"),
//                server_tab_users_combobox));

    return;
  } // end IF
//   gtk_tree_model_get_value(gtk_combo_box_get_model(serverlist),
//                            &active_iter,
//                            0, &active_value);
  gtk_tree_model_get(gtk_combo_box_get_model(server_tab_users_combobox),
                     &active_iter,
                     0, &user_value, // just retrieve the first column...
                     -1);
//   ACE_ASSERT(G_VALUE_HOLDS_STRING(&active_value));
  ACE_ASSERT(user_value);

  // convert UTF8 to locale
//   user_string = g_value_get_string(&active_value);
  std::string user_string = IRC_Client_Tools::UTF82Locale(user_value,
                                                          g_utf8_strlen(user_value, -1));
  if (user_string.empty())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert user name, aborting\n")));

    // clean up
    g_free(user_value);

    return;
  } // end IF

  // clean up
  g_free(user_value);

  // sanity check(s): larger than IRC_CLIENT_CNF_IRC_MAX_NICK_LENGTH characters ?
  // *TODO*: support the NICKLEN=xxx "feature" of the server...
  if (user_string.size() > IRC_CLIENT_CNF_IRC_MAX_NICK_LENGTH)
    user_string.resize(IRC_CLIENT_CNF_IRC_MAX_NICK_LENGTH);

  // *TODO*: if a conversation exists, simply activate the corresponding page
  data->connection->createMessageHandler(user_string);
}

void
refresh_users_clicked_cb(GtkWidget* button_in,
                         gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::refresh_users_clicked_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("refresh_users_clicked_cb...\n")));

  ACE_UNUSED_ARG(button_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->controller);

//   // *NOTE*: empty parameter --> current server
//   std::string servername;
//   try
//   {
//     data->controller->users(servername);
//   }
//   catch (...)
//   {
//     ACE_DEBUG((LM_ERROR,
//                ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::users(), continuing\n")));
//   }

  // *NOTE*: empty parameter (or "0") --> ALL users
  // (see RFC1459 section 4.5.1)
  std::string name(ACE_TEXT_ALWAYS_CHAR("0"));
  try
  {
    data->controller->who(name, false);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::who(), continuing\n")));
  }
}

gboolean
channel_entry_kb_focused_cb(GtkWidget* widget_in,
                            GdkEventFocus* event_in,
                            gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::channel_entry_kb_focused_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("channel_entry_kb_focused_cb...\n")));

  ACE_UNUSED_ARG(widget_in);
  ACE_UNUSED_ARG(event_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);

  // make the "change" button the default widget...
  GtkButton* server_tab_join_button = GTK_BUTTON(gtk_builder_get_object(data->builder,
                                                                        ACE_TEXT_ALWAYS_CHAR("server_tab_join_button")));
  ACE_ASSERT(server_tab_join_button);
  gtk_widget_grab_default(GTK_WIDGET(server_tab_join_button));

  // propagate the event further...
  return FALSE;
}

void
join_clicked_cb(GtkWidget* button_in,
                gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::join_clicked_cb"));

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
  GtkEntry* server_tab_channel_entry = GTK_ENTRY(gtk_builder_get_object(data->builder,
                                                                        ACE_TEXT_ALWAYS_CHAR("server_tab_channel_entry")));
  ACE_ASSERT(server_tab_channel_entry);
  GtkEntryBuffer* buffer = gtk_entry_get_buffer(server_tab_channel_entry);
  ACE_ASSERT(buffer);

  // sanity check
  if (gtk_entry_buffer_get_length(buffer) == 0)
    return; // nothing to do...

  // retrieve textbuffer data
  std::string channel_string = IRC_Client_Tools::UTF82Locale(gtk_entry_buffer_get_text(buffer),    // text
                                                             gtk_entry_buffer_get_length(buffer)); // number of bytes
  if (channel_string.empty())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert channel: \"%s\", aborting\n")));

    // clean up
    gtk_entry_buffer_delete_text(buffer, // buffer
                                 0,      // start at position 0
                                 -1);    // delete everything

    return;
  } // end IF

  // sanity check(s): has '#' prefix ?
  if (channel_string.find('#', 0) != 0)
    channel_string.insert(channel_string.begin(), '#');
  // sanity check(s): larger than IRC_CLIENT_CNF_IRC_MAX_CHANNEL_LENGTH characters ?
  // *TODO*: support the CHANNELLEN=xxx "feature" of the server...
  if (channel_string.size() > IRC_CLIENT_CNF_IRC_MAX_CHANNEL_LENGTH)
    channel_string.resize(IRC_CLIENT_CNF_IRC_MAX_CHANNEL_LENGTH);

  // *TODO*: support channel keys/multi-join ?
  string_list_t channels;
  channels.push_back(channel_string);
  string_list_t keys;
  try
  {
    data->controller->join(channels, keys);
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
channelbox_changed_cb(GtkWidget* combobox_in,
                      gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::channelbox_changed_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("channelbox_changed_cb...\n")));

  ACE_UNUSED_ARG(combobox_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(combobox_in);
  ACE_ASSERT(data);

  // step1: retrieve active channel entry
  // retrieve server tab channels combobox handle
  GtkComboBox* server_tab_channels_combobox = GTK_COMBO_BOX(combobox_in);
  ACE_ASSERT(server_tab_channels_combobox);
  GtkTreeIter active_iter;
  //   GValue active_value;
  gchar* channel_value = NULL;
  if (!gtk_combo_box_get_active_iter(server_tab_channels_combobox,
                                     &active_iter))
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("failed to gtk_combo_box_get_active_iter(%@), aborting\n"),
//                server_tab_channels_combobox));

    return;
  } // end IF
//   gtk_tree_model_get_value(gtk_combo_box_get_model(serverlist),
//                            &active_iter,
//                            0, &active_value);
  gtk_tree_model_get(gtk_combo_box_get_model(server_tab_channels_combobox),
                     &active_iter,
                     0, &channel_value, // just retrieve the first column...
                     -1);
//   ACE_ASSERT(G_VALUE_HOLDS_STRING(&active_value));
  ACE_ASSERT(channel_value);

  // convert UTF8 to locale
//   channel_string = g_value_get_string(&active_value);
  std::string channel_string = IRC_Client_Tools::UTF82Locale(channel_value,
                                                             g_utf8_strlen(channel_value, -1));
  if (channel_string.empty())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert channel name, aborting\n")));

    // clean up
    g_free(channel_value);

    return;
  } // end IF

  // clean up
  g_free(channel_value);

  // sanity check(s): has '#' prefix ?
  if (channel_string.find('#', 0) != 0)
    channel_string.insert(channel_string.begin(), '#');
  // sanity check(s): larger than IRC_CLIENT_CNF_IRC_MAX_CHANNEL_LENGTH characters ?
  // *TODO*: support the CHANNELLEN=xxx "feature" of the server...
  if (channel_string.size() > IRC_CLIENT_CNF_IRC_MAX_CHANNEL_LENGTH)
    channel_string.resize(IRC_CLIENT_CNF_IRC_MAX_CHANNEL_LENGTH);

  // *TODO*: support channel key ?
  string_list_t channels;
  channels.push_back(channel_string);
  string_list_t keys;
  try
  {
    data->controller->join(channels, keys);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::join(), continuing\n")));
  }
}

void
refresh_channels_clicked_cb(GtkWidget* button_in,
                            gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::refresh_channels_clicked_cb"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("refresh_channels_clicked_cb...\n")));

  ACE_UNUSED_ARG(button_in);
  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);

  // *NOTE*: empty list --> list them all !
  string_list_t channel_list;
  try
  {
    data->controller->list(channel_list);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::list(), continuing\n")));
  }
}

void
user_mode_toggled_cb(GtkToggleButton* toggleButton_in,
                     gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::user_mode_toggled_cb"));

  //   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("user_mode_toggled_cb...\n")));

  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(toggleButton_in);
  ACE_ASSERT(data);
  ACE_ASSERT(data->mainBuilder);
  ACE_ASSERT(!data->nickname.empty());

  RPG_Net_Protocol_UserMode mode = USERMODE_INVALID;
  // find out which button toggled...
  GtkToggleButton* button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                                                     ACE_TEXT_ALWAYS_CHAR("mode_operator_togglebutton")));
  ACE_ASSERT(button);
  if (button == toggleButton_in)
    mode = USERMODE_OPERATOR;
  else
  {
    button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                                      ACE_TEXT_ALWAYS_CHAR("mode_localoperator_togglebutton")));
    ACE_ASSERT(button);
    if (button == toggleButton_in)
      mode = USERMODE_LOCALOPERATOR;
    else
    {
      button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                                        ACE_TEXT_ALWAYS_CHAR("mode_restricted_togglebutton")));
      ACE_ASSERT(button);
      if (button == toggleButton_in)
        mode = USERMODE_RESTRICTEDCONN;
      else
      {
        button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                                          ACE_TEXT_ALWAYS_CHAR("mode_away_togglebutton")));
        ACE_ASSERT(button);
        if (button == toggleButton_in)
          mode = USERMODE_AWAY;
        else
        {
          button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                                            ACE_TEXT_ALWAYS_CHAR("mode_wallops_togglebutton")));
          ACE_ASSERT(button);
          if (button == toggleButton_in)
            mode = USERMODE_RECVWALLOPS;
          else
          {
            button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                                              ACE_TEXT_ALWAYS_CHAR("mode_notices_togglebutton")));
            ACE_ASSERT(button);
            if (button == toggleButton_in)
              mode = USERMODE_RECVNOTICES;
            else
            {
              button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                                                ACE_TEXT_ALWAYS_CHAR("mode_invisible_togglebutton")));
              ACE_ASSERT(button);
              if (button == toggleButton_in)
                mode = USERMODE_INVISIBLE;
              else
              {
                ACE_DEBUG((LM_ERROR,
                           ACE_TEXT("invalid user mode toggled (was: %@), aborting\n"),
                           toggleButton_in));

                return;
              } // end ELSE
            } // end ELSE
          } // end ELSE
        } // end ELSE
      } // end ELSE
    } // end ELSE
  } // end ELSE

  // check if the state is inconsistent --> submit change request, else do nothing
  // i.e. state is off and widget is "on" (or vice-versa)
  // *NOTE*: avoid recursion
  if (data->userModes.test(mode) == toggleButton_in->active)
    return;
  // re-toggle button for now...
  // *NOTE*: will be auto-toggled according to the outcome of the change request
  gtk_toggle_button_set_active(toggleButton_in, data->userModes.test(mode));

  string_list_t parameters;
  try
  {
    data->controller->mode(data->nickname,                                 // user mode
                           RPG_Net_Protocol_Tools::IRCUserMode2Char(mode), // corresponding mode char
                           !data->userModes.test(mode),                    // enable ?
                           parameters);                                    // parameters
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::mode(\"%s\"), continuing\n"),
               RPG_Net_Protocol_Tools::IRCUserMode2String(mode).c_str()));
  }
}

void
switch_channel_cb(GtkNotebook* notebook_in,
                  GtkNotebookPage* page_in,
                  guint pageNum_in,
                  gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::switch_channel_cb"));

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

void
action_away_cb(GtkAction* action_in,
               gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::action_away_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("action_away_cb...\n")));

  connection_cb_data_t* data = ACE_static_cast(connection_cb_data_t*,
                                               userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);
  ACE_ASSERT(data->controller);

  GtkToggleButton* server_tab_tools_togglebutton = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                                                                            ACE_TEXT_ALWAYS_CHAR("server_tab_tools_togglebutton")));
  ACE_ASSERT(server_tab_tools_togglebutton);

  bool activating = gtk_toggle_button_get_active(server_tab_tools_togglebutton);

  // check if the state is inconsistent --> submit change request, else do nothing
  // i.e. state is off and widget is "on" or vice-versa
  // *NOTE*: avoid recursion
  if (data->away == activating)
    return;
  // re-toggle button for now...
  // *NOTE*: will be auto-toggled according to the outcome of the change request
  gtk_toggle_button_set_active(server_tab_tools_togglebutton, data->away);

  // activating ? --> retrieve away message
  std::string away_message;
  if (activating)
  {
    GtkEntry* server_tab_entry_dialog_entry = GTK_ENTRY(gtk_builder_get_object(data->builder,
                                                                               ACE_TEXT_ALWAYS_CHAR("server_tab_entry_dialog_entry")));
    ACE_ASSERT(server_tab_entry_dialog_entry);
    // clean up
    gtk_entry_buffer_delete_text(gtk_entry_get_buffer(server_tab_entry_dialog_entry),
                                 0, -1);
  //   gtk_entry_set_max_length(server_tab_entry_dialog_entry,
  //                            0); // no limit
  //   gtk_entry_set_width_chars(server_tab_entry_dialog_entry,
  //                             -1); // reset to default

    GtkDialog* server_tab_entry_dialog = GTK_DIALOG(gtk_builder_get_object(data->builder,
                                                                           ACE_TEXT_ALWAYS_CHAR("server_tab_entry_dialog")));
    ACE_ASSERT(server_tab_entry_dialog);
    gtk_window_set_title(GTK_WINDOW(server_tab_entry_dialog),
                         IRC_CLIENT_GUI_DEF_AWAY_DIALOG_TITLE);
    if (gtk_dialog_run(server_tab_entry_dialog))
    {
  //     ACE_DEBUG((LM_DEBUG,
  //                ACE_TEXT("away cancelled...\n")));

      // clean up
      gtk_entry_buffer_delete_text(gtk_entry_get_buffer(server_tab_entry_dialog_entry),
                                   0, -1);

      gtk_widget_hide(GTK_WIDGET(server_tab_entry_dialog));

      return;
    } // end IF
    gtk_widget_hide(GTK_WIDGET(server_tab_entry_dialog));

    away_message = IRC_Client_Tools::UTF82Locale(gtk_entry_get_text(server_tab_entry_dialog_entry), -1);
    // clean up
    gtk_entry_buffer_delete_text(gtk_entry_get_buffer(server_tab_entry_dialog_entry),
                                 0, -1);

    if (away_message.empty())
    {
      // *NOTE*: need to set SOME value, as an AWAY-message with no parameter will
      // actually "un-away" the user (see RFC1459 Section 5.1)...
      away_message = IRC_CLIENT_DEF_IRC_AWAY_MESSAGE;
    } // end IF
  } // end IF

  try
  {
    data->controller->away(away_message);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::away(\"%s\"), continuing\n"),
               away_message.c_str()));
  }
}

void
channel_mode_toggled_cb(GtkToggleButton* toggleButton_in,
                        gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::channel_mode_toggled_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("channel_mode_toggled_cb...\n")));

  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);

  // sanity check(s)
  ACE_ASSERT(toggleButton_in);
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);
  ACE_ASSERT(!data->id.empty());

  RPG_Net_Protocol_ChannelMode mode           = CHANNELMODE_INVALID;
  bool                         need_parameter = false;
  std::string                  entry_label;
  // find out which button toggled...
  GtkToggleButton* button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                              ACE_TEXT_ALWAYS_CHAR("mode_key_togglebutton")));
  ACE_ASSERT(button);
  if (button == toggleButton_in)
  {
    mode = CHANNELMODE_PASSWORD;
    need_parameter = true;
    entry_label = IRC_CLIENT_GUI_DEF_MODE_PASSWORD_DIALOG_TITLE;
  } // end IF
  else
  {
    button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                               ACE_TEXT_ALWAYS_CHAR("mode_voice_togglebutton")));
    ACE_ASSERT(button);
    if (button == toggleButton_in)
    {
      mode = CHANNELMODE_VOICE;
      need_parameter = true;
      entry_label = IRC_CLIENT_GUI_DEF_MODE_VOICE_DIALOG_TITLE;
    } // end IF
    else
    {
      button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                 ACE_TEXT_ALWAYS_CHAR("mode_ban_togglebutton")));
      ACE_ASSERT(button);
      if (button == toggleButton_in)
      {
        mode = CHANNELMODE_BAN;
        need_parameter = true;
        entry_label = IRC_CLIENT_GUI_DEF_MODE_BAN_DIALOG_TITLE;
      } // end IF
      else
      {
        button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                   ACE_TEXT_ALWAYS_CHAR("mode_userlimit_togglebutton")));
        ACE_ASSERT(button);
        if (button == toggleButton_in)
        {
          mode = CHANNELMODE_USERLIMIT;
          need_parameter = true;
          entry_label = IRC_CLIENT_GUI_DEF_MODE_USERLIMIT_DIALOG_TITLE;
        }
        else
        {
          button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                     ACE_TEXT_ALWAYS_CHAR("mode_moderated_togglebutton")));
          ACE_ASSERT(button);
          if (button == toggleButton_in)
            mode = CHANNELMODE_MODERATED;
          else
          {
            button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                       ACE_TEXT_ALWAYS_CHAR("mode_blockforeign_togglebutton")));
            ACE_ASSERT(button);
            if (button == toggleButton_in)
              mode = CHANNELMODE_BLOCKFOREIGNMSGS;
            else
            {
              button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                         ACE_TEXT_ALWAYS_CHAR("mode_restricttopic_togglebutton")));
              ACE_ASSERT(button);
              if (button == toggleButton_in)
                mode = CHANNELMODE_RESTRICTEDTOPIC;
              else
              {
                button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                           ACE_TEXT_ALWAYS_CHAR("mode_inviteonly_togglebutton")));
                ACE_ASSERT(button);
                if (button == toggleButton_in)
                  mode = CHANNELMODE_INVITEONLY;
                else
                {
                  button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                             ACE_TEXT_ALWAYS_CHAR("mode_secret_togglebutton")));
                  ACE_ASSERT(button);
                  if (button == toggleButton_in)
                    mode = CHANNELMODE_SECRET;
                  else
                  {
                    button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                                               ACE_TEXT_ALWAYS_CHAR("mode_private_togglebutton")));
                    ACE_ASSERT(button);
                    if (button == toggleButton_in)
                      mode = CHANNELMODE_PRIVATE;
                    else
                    {
                      button = GTK_TOGGLE_BUTTON(gtk_builder_get_object(data->builder,
                          ACE_TEXT_ALWAYS_CHAR("mode_operator_togglebutton")));
                      ACE_ASSERT(button);
                      if (button == toggleButton_in)
                        mode = CHANNELMODE_OPERATOR;
                      else
                      {
                        ACE_DEBUG((LM_ERROR,
                                   ACE_TEXT("invalid channel mode toggled (was: %@), aborting\n"),
                                   toggleButton_in));

                        return;
                      } // end ELSE
                    } // end ELSE
                  } // end ELSE
                } // end ELSE
              } // end ELSE
            } // end ELSE
          } // end ELSE
        } // end ELSE
      } // end ELSE
    } // end ELSE
  } // end ELSE

  // check if the state is inconsistent --> submit change request, else do nothing
  // i.e. state is off and widget is "on" or vice-versa
  // *NOTE*: avoid recursion
  if (data->channelModes.test(mode) == toggleButton_in->active)
    return;
  // re-toggle button for now...
  // *NOTE*: will be auto-toggled according to the outcome of the change request
  gtk_toggle_button_set_active(toggleButton_in, data->channelModes.test(mode));

  std::string value;
  string_list_t parameters;
  if (need_parameter &&
      !gtk_toggle_button_get_active(toggleButton_in)) // no need when switching mode off...
  {
    GtkEntry* channel_tab_entry_dialog_entry = GTK_ENTRY(gtk_builder_get_object(data->builder,
        ACE_TEXT_ALWAYS_CHAR("channel_tab_entry_dialog_entry")));
    ACE_ASSERT(channel_tab_entry_dialog_entry);
    // clean up
    gtk_entry_buffer_delete_text(gtk_entry_get_buffer(channel_tab_entry_dialog_entry),
                                 0, -1);
//   gtk_entry_set_max_length(channel_tab_entry_dialog_entry,
//                            0); // no limit
//   gtk_entry_set_width_chars(channel_tab_entry_dialog_entry,
//                             -1); // reset to default

    // retrieve entry dialog handle
    GtkDialog* channel_tab_entry_dialog = GTK_DIALOG(gtk_builder_get_object(data->builder,
                                                                            ACE_TEXT_ALWAYS_CHAR("channel_tab_entry_dialog")));
    ACE_ASSERT(channel_tab_entry_dialog);
    gtk_window_set_title(GTK_WINDOW(channel_tab_entry_dialog),
                         entry_label.c_str());
    if (gtk_dialog_run(channel_tab_entry_dialog))
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("channel mode cancelled...\n")));

      // clean up
      gtk_entry_buffer_delete_text(gtk_entry_get_buffer(channel_tab_entry_dialog_entry),
                                   0, -1);

      gtk_widget_hide(GTK_WIDGET(channel_tab_entry_dialog));

      return;
    } // end IF
    gtk_widget_hide(GTK_WIDGET(channel_tab_entry_dialog));

    value = gtk_entry_get_text(channel_tab_entry_dialog_entry);
    // clean up
    gtk_entry_buffer_delete_text(gtk_entry_get_buffer(channel_tab_entry_dialog_entry),
                                 0, -1);

    if (value.empty())
    {
    //     ACE_DEBUG((LM_DEBUG,
    //                ACE_TEXT("channel mode cancelled...\n")));
      return;
    } // end IF

    parameters.push_back(value);
  } // end IF
  try
  {
    data->controller->mode(data->id,                                          // channel name
                           RPG_Net_Protocol_Tools::IRCChannelMode2Char(mode), // corresponding mode char
                           !data->channelModes.test(mode),                    // enable ?
                           parameters);                                       // parameters
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::mode(\"%s\"), continuing\n"),
               RPG_Net_Protocol_Tools::IRCChannelMode2String(mode).c_str()));
  }
}

void
topic_clicked_cb(GtkWidget* eventBox_in,
                 GdkEventButton* event_in,
                 gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::topic_clicked_cb"));

  ACE_UNUSED_ARG(eventBox_in);
  ACE_UNUSED_ARG(event_in);

  // sanity check(s)
  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);
  ACE_ASSERT(data);
  ACE_ASSERT(!data->id.empty());
  ACE_ASSERT(RPG_Net_Protocol_Tools::isValidIRCChannelName(data->id));
  ACE_ASSERT(data->connection);

  // retrieve entry handle
  GtkEntry* channel_tab_entry_dialog_entry = GTK_ENTRY(gtk_builder_get_object(data->builder,
                                                                              ACE_TEXT_ALWAYS_CHAR("channel_tab_entry_dialog_entry")));
  ACE_ASSERT(channel_tab_entry_dialog_entry);
//   gtk_entry_set_max_length(channel_tab_entry_dialog_entry,
//                            0); // no limit
//   gtk_entry_set_width_chars(channel_tab_entry_dialog_entry,
//                             -1); // reset to default
  // retrieve label handle
  GtkLabel* channel_tab_topic_label = GTK_LABEL(gtk_builder_get_object(data->builder,
                                                                       ACE_TEXT_ALWAYS_CHAR("channel_tab_topic_label")));
  ACE_ASSERT(channel_tab_topic_label);
  gtk_entry_buffer_set_text(gtk_entry_get_buffer(channel_tab_entry_dialog_entry),
                            gtk_label_get_text(channel_tab_topic_label),
                            ACE_OS::strlen(gtk_label_get_text(channel_tab_topic_label)));
  gtk_editable_select_region(GTK_EDITABLE(channel_tab_entry_dialog_entry),
                             0, -1);

  // retrieve entry dialog handle
  GtkDialog* channel_tab_entry_dialog = GTK_DIALOG(gtk_builder_get_object(data->builder,
                                                                          ACE_TEXT_ALWAYS_CHAR("channel_tab_entry_dialog")));
  ACE_ASSERT(channel_tab_entry_dialog);
  gtk_window_set_title(GTK_WINDOW(channel_tab_entry_dialog),
                       IRC_CLIENT_GUI_DEF_TOPIC_DIALOG_TITLE);
  if (gtk_dialog_run(channel_tab_entry_dialog))
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("channel topic cancelled...\n")));

    // clean up
    gtk_entry_buffer_delete_text(gtk_entry_get_buffer(channel_tab_entry_dialog_entry),
                                 0, -1);

    gtk_widget_hide(GTK_WIDGET(channel_tab_entry_dialog));

    return;
  } // end IF
  gtk_widget_hide(GTK_WIDGET(channel_tab_entry_dialog));

  std::string topic_string = gtk_entry_get_text(channel_tab_entry_dialog_entry);
  try
  {
    data->controller->topic(data->id,
                            topic_string);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::topic(), continuing\n")));
  }

  // clean up
  gtk_entry_buffer_delete_text(gtk_entry_get_buffer(channel_tab_entry_dialog_entry),
                               0, -1);
}

void
part_clicked_cb(GtkWidget* button_in,
                gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::part_clicked_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("part_clicked_cb...\n")));

  ACE_UNUSED_ARG(button_in);
  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(!data->id.empty());
  ACE_ASSERT(data->connection);

  // *NOTE*: if 'this' is not a channel handler, just close then page tab
  if (!RPG_Net_Protocol_Tools::isValidIRCChannelName(data->id))
  {
    // *WARNING*: this will delete 'this' !
    data->connection->terminateMessageHandler(data->id);

    // done
    return;
  } // end IF

  string_list_t channels;
  channels.push_back(data->id);
  try
  {
    data->controller->part(channels);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::part(), continuing\n")));
  }
}

gboolean
members_clicked_cb(GtkWidget* widget_in,
                   GdkEventButton* event_in,
                   gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::members_clicked_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("members_clicked_cb...\n")));

  // supposed to be a context menu -> right-clicked ?
  if (event_in->button != 3)
    return FALSE; // --> propagate event

  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);

  // sanity check(s)
  ACE_ASSERT(GTK_TREE_VIEW(widget_in));
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);
  ACE_ASSERT(data->connection);

  // find out which row was actually clicked
  GtkTreePath* path = NULL;
  if (!gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(widget_in),
                                     event_in->x, event_in->y,
                                     &path, NULL,
                                     NULL, NULL))
    return FALSE; // no row at this position --> propagate event
  ACE_ASSERT(path);

  // retrieve current selection
  GtkTreeSelection* selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(widget_in));
  ACE_ASSERT(selection);
  // nothing selected ? --> nothing to do
  if (gtk_tree_selection_count_selected_rows(selection) == 0)
  {
    // clean up
    gtk_tree_path_free(path);

    return TRUE; // done
  } // end IF

  // path part of the selection ? --> keep selection : new selection
  if (!gtk_tree_selection_path_is_selected(selection, path))
  {
    gtk_tree_selection_unselect_all(selection);
    gtk_tree_selection_select_path(selection, path);
  } // end IF

  // clean up
  gtk_tree_path_free(path);

  GList* selected_rows = NULL;
  GtkTreeModel* model = NULL;
  selected_rows = gtk_tree_selection_get_selected_rows(selection,
                                                       &model);
  ACE_ASSERT(selected_rows);
  ACE_ASSERT(model);
  data->parameters.clear();
  GtkTreePath* current_path = NULL;
  GtkTreeIter current_iter;
//   GValue current_value;
  gchar* current_value = NULL;
  for (GList* iterator = g_list_first(selected_rows);
       iterator != NULL;
       iterator = g_list_next(iterator))
  {
    current_path = ACE_static_cast(GtkTreePath*, iterator->data);
    ACE_ASSERT(current_path);

    // path --> iter
    if (!gtk_tree_model_get_iter(model,
                                 &current_iter,
                                 current_path))
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to gtk_tree_model_get_iter, continuing\n")));

      continue;
    } // end IF
    // iter --> value
//     gtk_tree_model_get_value(model,
//                              current_iter,
//                              0, &current_value);
    gtk_tree_model_get(model,
                       &current_iter,
                       0, &current_value,
                       -1);
    // *TODO*: check if these
    data->parameters.push_back(IRC_Client_Tools::UTF82Locale(current_value,
                                                             g_utf8_strlen(current_value, -1)));

    // clean up
    g_free(current_value);
    gtk_tree_path_free(current_path);
  } // end FOR

  // clean up
  g_list_free(selected_rows);

  // remove ourselves from any selection...
  string_list_iterator_t iterator = data->parameters.begin();
  string_list_iterator_t self = data->parameters.end();
  std::string nickname = data->connection->getNickname();
  for (;
       iterator != data->parameters.end();
       iterator++)
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("selected: \"%s\"\n"),
//                (*iterator).c_str()));

    if (*iterator == nickname)
    {
      self = iterator;
      continue;
    } // end IF
    // *NOTE*: ignore leading '@'
    if ((*iterator).find('@', 0) == 0)
      if (((*iterator).find(nickname, 1) == 1) &&
          ((*iterator).size() == (nickname.size() + 1)))
      {
        self = iterator;
        continue;
      } // end IF
  } // end FOR
  if (self != data->parameters.end())
    data->parameters.erase(self);
  // no selection ? --> nothing to do
  if (data->parameters.empty())
    return TRUE; // done

  // init popup menu
  GtkMenu* channel_tab_treeview_menu = GTK_MENU(gtk_builder_get_object(data->builder,
                                                                       ACE_TEXT_ALWAYS_CHAR("channel_tab_treeview_menu")));
  ACE_ASSERT(channel_tab_treeview_menu);

  // init active_channels submenu
  GtkMenuItem* menu_item = NULL;
  // --> retrieve list of active channels
  // *TODO*: for invite-only channels, only operators are allowed to invite
  // strangers --> remove those channels where this condition doesn't apply
  string_list_t active_channels;
  data->connection->channels(active_channels);
  if (active_channels.size() > 1)
  {
    // clear popup menu
    GtkMenu* invite_channel_members_menu = GTK_MENU(gtk_builder_get_object(data->builder,
                                                                           ACE_TEXT_ALWAYS_CHAR("invite_channel_members_menu")));
    ACE_ASSERT(invite_channel_members_menu);
    GList* children = gtk_container_get_children(GTK_CONTAINER(invite_channel_members_menu));
    if (children)
    {
      for (GList* current_child = g_list_first(children);
           current_child != NULL;
           current_child = g_list_next(current_child))
        gtk_container_remove(GTK_CONTAINER(invite_channel_members_menu),
                             GTK_WIDGET(current_child->data));
      // clean up
      g_list_free(children);
    } // end IF

    // populate popup menu
    GtkAction* action_invite = GTK_ACTION(gtk_builder_get_object(data->builder,
                                                                 ACE_TEXT_ALWAYS_CHAR("action_invite")));
    ACE_ASSERT(action_invite);
    GtkMenuItem* menu_item = NULL;
    for (string_list_const_iterator_t iterator = active_channels.begin();
         iterator != active_channels.end();
         iterator++)
    {
      // skip current channel
      if (*iterator == data->id)
        continue;

      menu_item = GTK_MENU_ITEM(gtk_action_create_menu_item(action_invite));
      ACE_ASSERT(menu_item);
      gtk_menu_item_set_label(menu_item,
                              (*iterator).c_str());
      gtk_menu_shell_append(GTK_MENU_SHELL(invite_channel_members_menu),
                            GTK_WIDGET(menu_item));
    } // end FOR
    gtk_widget_show_all(GTK_WIDGET(invite_channel_members_menu));

    menu_item = GTK_MENU_ITEM(gtk_builder_get_object(data->builder,
                                                     ACE_TEXT_ALWAYS_CHAR("menuitem_invite")));
    ACE_ASSERT(menu_item);
    gtk_widget_set_sensitive(GTK_WIDGET(menu_item), TRUE);
  } // end IF
  else
  {
    menu_item = GTK_MENU_ITEM(gtk_builder_get_object(data->builder,
                                                     ACE_TEXT_ALWAYS_CHAR("menuitem_invite")));
    ACE_ASSERT(menu_item);
    gtk_widget_set_sensitive(GTK_WIDGET(menu_item), FALSE);
  } // end ELSE

  // en-/disable some entries...
  menu_item = GTK_MENU_ITEM(gtk_builder_get_object(data->builder,
                                                   ACE_TEXT_ALWAYS_CHAR("menuitem_kick")));
  ACE_ASSERT(menu_item);
  gtk_widget_set_sensitive(GTK_WIDGET(menu_item), data->channelModes.test(CHANNELMODE_OPERATOR));
  menu_item = GTK_MENU_ITEM(gtk_builder_get_object(data->builder,
                                                   ACE_TEXT_ALWAYS_CHAR("menuitem_ban")));
  ACE_ASSERT(menu_item);
  gtk_widget_set_sensitive(GTK_WIDGET(menu_item), data->channelModes.test(CHANNELMODE_OPERATOR));

  gtk_menu_popup(channel_tab_treeview_menu,
                 NULL, NULL,
                 NULL, NULL,
                 event_in->button,
                 event_in->time);

  return TRUE;
}

void
action_msg_cb(GtkAction* action_in,
              gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::action_msg_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("action_msg_cb...\n")));

  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->connection);
  ACE_ASSERT(!data->parameters.empty());

  gint page_num = -1;
  for (string_list_const_iterator_t iterator = data->parameters.begin();
       iterator != data->parameters.end();
       iterator++)
  {
    page_num = data->connection->exists(*iterator);
    if (page_num == -1)
      data->connection->createMessageHandler(*iterator);
  } // end FOR
}

void
action_invite_cb(GtkAction* action_in,
                 gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::action_invite_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("action_invite_cb...\n")));

  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->builder);
  ACE_ASSERT(data->controller);
  ACE_ASSERT(!data->parameters.empty());

  // retrieve the channel
  // --> currently active menuitem of the invite_channel_members_menu
  GtkMenu* invite_channel_members_menu = GTK_MENU(gtk_builder_get_object(data->builder,
                                                                         ACE_TEXT_ALWAYS_CHAR("invite_channel_members_menu")));
  ACE_ASSERT(invite_channel_members_menu);
  GtkMenuItem* active_item = GTK_MENU_ITEM(gtk_menu_get_active(invite_channel_members_menu));
  ACE_ASSERT(active_item);
  std::string channel_string = IRC_Client_Tools::UTF82Locale(gtk_menu_item_get_label(active_item), -1);
  ACE_ASSERT(!channel_string.empty());

  for (string_list_const_iterator_t iterator = data->parameters.begin();
       iterator != data->parameters.end();
       iterator++)
  {
    try
    {
      data->controller->invite(*iterator,
                               channel_string);
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::invite(), continuing\n")));
    }
  } // end FOR
}

void
action_info_cb(GtkAction* action_in,
               gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::action_info_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("action_info_cb...\n")));

  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(data->controller);
  ACE_ASSERT(!data->parameters.empty());

  try
  {
    data->controller->userhost(data->parameters);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::userhost(), continuing\n")));
  }
}

void
action_kick_cb(GtkAction* action_in,
               gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::action_kick_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("action_kick_cb...\n")));

  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(!data->id.empty());
  ACE_ASSERT(data->controller);
  ACE_ASSERT(!data->parameters.empty());

  for (string_list_const_iterator_t iterator = data->parameters.begin();
       iterator != data->parameters.end();
       iterator++)
  {
    try
    {
      data->controller->kick(data->id,
                             *iterator,
                             std::string(IRC_CLIENT_DEF_IRC_KICK_REASON));
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::kick(), continuing\n")));
    }
  } // end FOR
}

void
action_ban_cb(GtkAction* action_in,
              gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::action_ban_cb"));

  //   ACE_DEBUG((LM_DEBUG,
  //              ACE_TEXT("action_ban_cb...\n")));

  handler_cb_data_t* data = ACE_static_cast(handler_cb_data_t*,
                                            userData_in);

  // sanity check(s)
  ACE_ASSERT(data);
  ACE_ASSERT(!data->id.empty());
  ACE_ASSERT(data->controller);
  ACE_ASSERT(!data->parameters.empty());

  string_list_t parameters;
  std::string ban_mask_string;
  for (string_list_const_iterator_t iterator = data->parameters.begin();
       iterator != data->parameters.end();
       iterator++)
  {
    parameters.clear();
    // *TODO*: this probably needs some refinement --> users can just change
    // nicks and rejoin... should cover at least the user/hostnames as well ?
    ban_mask_string = *iterator;
    ban_mask_string += ACE_TEXT_ALWAYS_CHAR("!*@*");
    parameters.push_back(ban_mask_string);

    try
    {
      data->controller->mode(data->id,
                             RPG_Net_Protocol_Tools::IRCChannelMode2Char(CHANNELMODE_BAN),
                             true,
                             parameters);
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("caught exception in RPG_Net_Protocol_IIRCControl::mode(), continuing\n")));
    }
  } // end FOR
}
#ifdef __cplusplus
}
#endif /* __cplusplus */