/***************************************************************************
 *   Copyright (C) 2010 by Erik Sohns   *
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

#include "character_generator_gui_callbacks.h"

#include "character_generator_gui_common.h"

#include <rpg_client_defines.h>
#include <rpg_client_callbacks.h>

#include <rpg_engine_common.h>
#include <rpg_engine_common_tools.h>

#include <rpg_graphics_defines.h>
#include <rpg_graphics_surface.h>
#include <rpg_graphics_cursor.h>
#include <rpg_graphics_dictionary.h>
#include <rpg_graphics_common_tools.h>

#include <rpg_map_defines.h>
#include <rpg_map_common_tools.h>

#include <rpg_player_defines.h>
#include <rpg_player_common_tools.h>

#include <rpg_item_instance_manager.h>
#include <rpg_item_weapon.h>
#include <rpg_item_armor.h>

#include <rpg_common_macros.h>
#include <rpg_common_defines.h>
#include <rpg_common_tools.h>
#include <rpg_common_file_tools.h>

#include <gmodule.h>

#include <ace/Log_Msg.h>

#include <sstream>

void
update_sprite_gallery(GTK_cb_data_t& CBData_in)
{
  RPG_TRACE(ACE_TEXT("::update_sprite_gallery"));

  RPG_Graphics_GraphicTypeUnion type;
  type.discriminator = RPG_Graphics_GraphicTypeUnion::SPRITE;
  RPG_Graphics_t graphic;
  std::string filename;
  for (CBData_in.current_sprite = CBData_in.sprite_gallery.begin();
       CBData_in.current_sprite != CBData_in.sprite_gallery.end();
       CBData_in.current_sprite++)
  {
    type.sprite = *CBData_in.current_sprite;
    graphic = RPG_GRAPHICS_DICTIONARY_SINGLETON::instance()->get(type);
    ACE_ASSERT((graphic.type.discriminator == type.discriminator) &&
               (graphic.type.sprite == type.sprite));
    // assemble path
    RPG_Graphics_Common_Tools::graphicToFile(graphic, filename);
    if (filename == CBData_in.entity.sprite)
      break;
  } // end FOR

  // sanity check
  if (filename != CBData_in.entity.sprite)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("sprite (was: \"%s\") not in gallery (%u entries), aborting\n"),
               CBData_in.entity.sprite.c_str(),
               CBData_in.sprite_gallery.size()));
}

void
set_current_image(const std::string& filename_in,
                  GladeXML* xml_in)
{
  RPG_TRACE(ACE_TEXT("::set_current_image"));

  GtkImage* image = GTK_IMAGE(glade_xml_get_widget(xml_in,
                                                   ACE_TEXT_ALWAYS_CHAR("image_sprite")));
  ACE_ASSERT(image);
  gtk_image_clear(image);

  if (!filename_in.empty())
    gtk_image_set_from_file(image, filename_in.c_str());
  else
    gtk_image_clear(image);
}

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */
G_MODULE_EXPORT gint
about_clicked_GTK_cb(GtkWidget* widget_in,
                       gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::about_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*> (userData_in);
  ACE_ASSERT(data);

  // sanity check(s)
  ACE_ASSERT(data->xml);

  // retrieve about dialog handle
  GtkWidget* about_dialog = GTK_WIDGET(glade_xml_get_widget(data->xml,
                                                            ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_ABOUTDIALOG_NAME)));
  ACE_ASSERT(about_dialog);

  // draw it
  if (!GTK_WIDGET_VISIBLE(about_dialog))
    gtk_widget_show_all(about_dialog);

  return FALSE;
}

G_MODULE_EXPORT gint
quit_clicked_GTK_cb(GtkWidget* widget_in,
                      gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::quit_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  ACE_UNUSED_ARG(userData_in);

  // leave GTK
  gtk_main_quit();

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("leaving GTK...\n")));

  // this is the "delete-event" handler
  // --> destroy the main dialog widget
  return TRUE; // --> propagate
}

G_MODULE_EXPORT gint
create_character_clicked_GTK_cb(GtkWidget* widget_in,
                                  gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::create_character_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  //   ACE_UNUSED_ARG(userData_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);
  ACE_ASSERT(data->entity.character == NULL);

  data->entity = RPG_Engine_Common_Tools::createEntity();
  ACE_ASSERT(data->entity.character);

  // update entity profile widgets
  ::update_entity_profile(data->entity,
                          data->xml);

  // make character display frame sensitive (if it's not already)
  GtkFrame* character_frame = GTK_FRAME(glade_xml_get_widget(data->xml,
                                                             ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_CHARFRAME_NAME)));
  ACE_ASSERT(character_frame);
  gtk_widget_set_sensitive(GTK_WIDGET(character_frame), TRUE);

  // make drop button sensitive (if it's not already)
  GtkButton* button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                                      ACE_TEXT_ALWAYS_CHAR("drop")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

  // make save button sensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("save")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

  // make load button insensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("load")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  // make this insensitive
  gtk_widget_set_sensitive(widget_in, FALSE);

  return FALSE;
}

G_MODULE_EXPORT gint
drop_character_clicked_GTK_cb(GtkWidget* widget_in,
                              gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::drop_character_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  //   ACE_UNUSED_ARG(userData_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);

  // clean up
  if (data->entity.character)
  {
    delete data->entity.character;
    data->entity.character = NULL;
    data->entity.position = std::make_pair(std::numeric_limits<unsigned int>::max(),
                                           std::numeric_limits<unsigned int>::max());
    data->entity.modes.clear();
    data->entity.actions.clear();
    data->entity.sprite.clear();
    data->entity.is_spawned = false;
  } // end IF

  // reset profile widgets
  ::reset_entity_profile(data->xml);
  data->entity.sprite = RPG_GRAPHICS_DEF_SPRITE;
  ::update_sprite_gallery(*data);
  ::set_current_image(data->entity.sprite,
                      data->xml);

  // make character display frame insensitive (if it's not already)
  GtkFrame* character_frame = GTK_FRAME(glade_xml_get_widget(data->xml,
                                                             ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_CHARFRAME_NAME)));
  ACE_ASSERT(character_frame);
  gtk_widget_set_sensitive(GTK_WIDGET(character_frame), FALSE);

  // make create button sensitive (if it's not already)
  GtkButton* button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                                      ACE_TEXT_ALWAYS_CHAR("create")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

  // make save button insensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("save")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  // make load button sensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("load")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

  // make this insensitive
  gtk_widget_set_sensitive(widget_in, FALSE);

  return FALSE;
}

G_MODULE_EXPORT gint
load_character_clicked_GTK_cb(GtkWidget* widget_in,
                              gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::load_character_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);

  // sanity check(s)
  ACE_ASSERT(data->xml);

  // *NOTE*: this callback just presents the file picker
  // --> business logic happens in character_file_actived_GTK_cb

  // retrieve file chooser dialog handle
  GtkFileChooserDialog* filechooser_dialog = GTK_FILE_CHOOSER_DIALOG(glade_xml_get_widget(data->xml,
                                                                                          ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_FILECHOOSERDIALOG_NAME)));
  ACE_ASSERT(filechooser_dialog);
  if (!filechooser_dialog)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to glade_xml_get_widget(\"%s\"): \"%m\", aborting\n"),
               ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_FILECHOOSERDIALOG_NAME)));

    return FALSE;
  } // end IF

  // draw it
  if (!GTK_WIDGET_VISIBLE(filechooser_dialog))
    gtk_widget_show_all(GTK_WIDGET(filechooser_dialog));

  return FALSE;
}

G_MODULE_EXPORT gint
character_file_activated_GTK_cb(GtkWidget* widget_in,
                                gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::character_file_activated_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);

  // sanity check(s)
  ACE_ASSERT(data->xml);

  // retrieve file chooser dialog handle
  GtkFileChooserDialog* filechooser_dialog = GTK_FILE_CHOOSER_DIALOG(glade_xml_get_widget(data->xml,
                                                                                          ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_FILECHOOSERDIALOG_NAME)));
  ACE_ASSERT(filechooser_dialog);

  // hide widget
  gtk_widget_hide(GTK_WIDGET(filechooser_dialog));

  // clean up
  if (data->entity.character)
  {
    delete data->entity.character;
    data->entity.character = NULL;
    data->entity.position = std::make_pair(std::numeric_limits<unsigned int>::max(),
                                           std::numeric_limits<unsigned int>::max());
    data->entity.modes.clear();
    data->entity.actions.clear();
    data->entity.sprite.clear();
    data->entity.is_spawned = false;
  } // end IF

  // retrieve selected filename
  std::string filename(gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooser_dialog)));

  data->entity = RPG_Engine_Common_Tools::loadEntity(filename,
                                                     data->schemaRepository);
  ACE_ASSERT(data->entity.character);

  // update entity profile widgets
  ::update_entity_profile(data->entity,
                          data->xml);
  ::update_sprite_gallery(*data);

  // make character display frame sensitive (if it's not already)
  GtkFrame* character_frame = GTK_FRAME(glade_xml_get_widget(data->xml,
                                                             ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_CHARFRAME_NAME)));
  ACE_ASSERT(character_frame);
  gtk_widget_set_sensitive(GTK_WIDGET(character_frame), TRUE);

  // make create button insensitive (if it's not already)
  GtkButton* button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                                      ACE_TEXT_ALWAYS_CHAR("create")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  // make drop button sensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("drop")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

  // make save button insensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("save")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  // make load button insensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("load")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  return FALSE;
}

G_MODULE_EXPORT gint
save_character_clicked_GTK_cb(GtkWidget* widget_in,
                              gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::save_character_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);

  // sanity check(s)
  ACE_ASSERT(data->entity.character);

  // set active sprite
  data->entity.sprite = *(data->current_sprite);

  // assemble target filename
#if !defined (ACE_WIN32) && !defined (ACE_WIN64)
  std::string filename = ACE_TEXT(RPG_PLAYER_DEF_ENTITY_REPOSITORY);
#else
  std::string filename = ACE_OS::getenv(ACE_TEXT(RPG_PLAYER_DEF_ENTITY_REPOSITORY));
#endif
  filename += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  filename += data->entity.character->getName();
  filename += ACE_TEXT_ALWAYS_CHAR(RPG_PLAYER_PROFILE_EXT);

  if (!RPG_Engine_Common_Tools::saveEntity(data->entity,
                                           filename))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Engine_Common_Tools::saveEntity(\"%s\"), continuing\n"),
               filename.c_str()));

  // make save button INsensitive
  gtk_widget_set_sensitive(widget_in, FALSE);

  return FALSE;
}

G_MODULE_EXPORT gint
character_repository_combobox_changed_GTK_cb(GtkWidget* widget_in,
                                             gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::character_repository_combobox_changed_GTK_cb"));

  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);

  // sanity check(s)
  ACE_ASSERT(widget_in);
  ACE_ASSERT(data->xml);

  // retrieve active item
  std::string active_item;
  GtkTreeIter selected;
  GtkTreeModel* model = NULL;
  GValue value;
  const gchar* text = NULL;
  if (!gtk_combo_box_get_active_iter(GTK_COMBO_BOX(widget_in), &selected))
  {
    // *WARNING*: refreshing the combobox triggers removal of items
    // which also generates this signal...
    return FALSE;
  } // end IF
  model = gtk_combo_box_get_model(GTK_COMBO_BOX(widget_in));
  ACE_ASSERT(model);
  ACE_OS::memset(&value,
                 0,
                 sizeof(value));
  gtk_tree_model_get_value(model, &selected,
                           0, &value);
  text = g_value_get_string(&value);
  // sanity check
  ACE_ASSERT(text);
  active_item = text;
  g_value_unset(&value);

  // clean up
  if (data->entity.character)
  {
    delete data->entity.character;
    data->entity.character = NULL;
    data->entity.position = std::make_pair(std::numeric_limits<unsigned int>::max(),
                                           std::numeric_limits<unsigned int>::max());
    data->entity.modes.clear();
    data->entity.actions.clear();
    data->entity.sprite.clear();
    data->entity.is_spawned = false;
  } // end IF

  // construct filename
#if !defined (ACE_WIN32) && !defined (ACE_WIN64)
  std::string filename = ACE_TEXT(RPG_PLAYER_DEF_ENTITY_REPOSITORY);
#else
  std::string filename = ACE_OS::getenv(ACE_TEXT(RPG_PLAYER_DEF_ENTITY_REPOSITORY));
#endif
  filename += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  filename += active_item;
  filename += ACE_TEXT_ALWAYS_CHAR(RPG_PLAYER_PROFILE_EXT);

  // load entity profile
  data->entity = RPG_Engine_Common_Tools::loadEntity(filename,
                                                     data->schemaRepository);
  ACE_ASSERT(data->entity.character);

  // update entity profile widgets
  ::update_entity_profile(data->entity,
                          data->xml);
  ::update_sprite_gallery(*data);

  // make character display frame sensitive (if it's not already)
  GtkFrame* character_frame = GTK_FRAME(glade_xml_get_widget(data->xml,
                                                             ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_CHARFRAME_NAME)));
  ACE_ASSERT(character_frame);
  gtk_widget_set_sensitive(GTK_WIDGET(character_frame), TRUE);

  // make create button insensitive (if it's not already)
  GtkButton* button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                                      ACE_TEXT_ALWAYS_CHAR("create")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  // make drop button sensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("drop")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

  // make save button insensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("save")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  // make load button insensitive (if it's not already)
  button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                           ACE_TEXT_ALWAYS_CHAR("load")));
  ACE_ASSERT(button);
  gtk_widget_set_sensitive(GTK_WIDGET(button), FALSE);

  return FALSE;
}

G_MODULE_EXPORT gint
character_repository_button_clicked_GTK_cb(GtkWidget* widget_in,
                                           gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::character_repository_button_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);

  // sanity check(s)
  ACE_ASSERT(data->xml);

  // retrieve tree model
  GtkComboBox* repository_combobox = GTK_COMBO_BOX(glade_xml_get_widget(data->xml,
                                                                        ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_CHARBOX_NAME)));
  ACE_ASSERT(repository_combobox);
  GtkTreeModel* model = gtk_combo_box_get_model(repository_combobox);
  ACE_ASSERT(model);

  // re-load profile data
#if !defined (ACE_WIN32) && !defined (ACE_WIN64)
  unsigned long num_entries = ::load_files(ACE_TEXT(RPG_PLAYER_DEF_ENTITY_REPOSITORY),
#else
  unsigned long num_entries = ::load_files(ACE_OS::getenv(ACE_TEXT(RPG_PLAYER_DEF_ENTITY_REPOSITORY)),
#endif
                                           true,
                                           GTK_LIST_STORE(model));

  // set sensitive as appropriate
  GtkFrame* character_frame = GTK_FRAME(glade_xml_get_widget(data->xml,
                                                             ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_DEF_GNOME_CHARFRAME_NAME)));
  ACE_ASSERT(character_frame);

  // ... sensitize/activate widgets as appropriate
  if (num_entries)
  {
    gtk_widget_set_sensitive(GTK_WIDGET(repository_combobox), TRUE);
    gtk_combo_box_set_active(repository_combobox, 0);
  } // end IF
  else
  {
    gtk_widget_set_sensitive(GTK_WIDGET(repository_combobox), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(character_frame), FALSE);

    // make create button sensitive (if it's not already)
    GtkButton* button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                                        ACE_TEXT_ALWAYS_CHAR("create")));
    ACE_ASSERT(button);
    gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

    // make load button sensitive (if it's not already)
    button = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                             ACE_TEXT_ALWAYS_CHAR("load")));
    ACE_ASSERT(button);
    gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);
  } // end ELSE

  return FALSE;
}

G_MODULE_EXPORT gint
prev_image_clicked_GTK_cb(GtkWidget* widget_in,
                          gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::prev_image_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);
  ACE_ASSERT(data->xml);
  ACE_ASSERT(!data->sprite_gallery.empty());

  // update image
  if (data->current_sprite == data->sprite_gallery.begin())
    data->current_sprite = data->sprite_gallery.end();
  data->current_sprite--;

  RPG_Graphics_GraphicTypeUnion type;
  type.discriminator = RPG_Graphics_GraphicTypeUnion::SPRITE;
  type.sprite = *(data->current_sprite);
  RPG_Graphics_t graphic;
  // retrieve properties from the dictionary
  graphic = RPG_GRAPHICS_DICTIONARY_SINGLETON::instance()->get(type);
  // assemble path
  std::string filename;
  RPG_Graphics_Common_Tools::graphicToFile(graphic, filename);
  ::set_current_image(filename,
                      data->xml);

  // make character save button sensitive (if it's not already)
  GtkButton* save = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                                    ACE_TEXT_ALWAYS_CHAR("save")));
  ACE_ASSERT(save);
  gtk_widget_set_sensitive(GTK_WIDGET(save), TRUE);

  return FALSE;
}

G_MODULE_EXPORT gint
next_image_clicked_GTK_cb(GtkWidget* widget_in,
                          gpointer userData_in)
{
  RPG_TRACE(ACE_TEXT("::next_image_clicked_GTK_cb"));

  ACE_UNUSED_ARG(widget_in);
  GTK_cb_data_t* data = static_cast<GTK_cb_data_t*>(userData_in);
  ACE_ASSERT(data);
  ACE_ASSERT(data->xml);
  ACE_ASSERT(!data->sprite_gallery.empty());

  // update image
  data->current_sprite++;
  if (data->current_sprite == data->sprite_gallery.end())
    data->current_sprite = data->sprite_gallery.begin();

  RPG_Graphics_GraphicTypeUnion type;
  type.discriminator = RPG_Graphics_GraphicTypeUnion::SPRITE;
  type.sprite = *(data->current_sprite);
  RPG_Graphics_t graphic;
  // retrieve properties from the dictionary
  graphic = RPG_GRAPHICS_DICTIONARY_SINGLETON::instance()->get(type);
  // assemble path
  std::string filename;
  RPG_Graphics_Common_Tools::graphicToFile(graphic, filename);
  ::set_current_image(filename,
                      data->xml);

  // make character save button sensitive (if it's not already)
  GtkButton* save = GTK_BUTTON(glade_xml_get_widget(data->xml,
                                                    ACE_TEXT_ALWAYS_CHAR("save")));
  ACE_ASSERT(save);
  gtk_widget_set_sensitive(GTK_WIDGET(save), TRUE);

  return FALSE;
}
#ifdef __cplusplus
}
#endif /* __cplusplus */
