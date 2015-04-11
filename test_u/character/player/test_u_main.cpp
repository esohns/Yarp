#include "stdafx.h"
#include "test_u_main.h"

#include <string>

#include "ace/ACE.h"
#if defined(ACE_WIN32) || defined(ACE_WIN64)
#include "ace/Init_ACE.h"
#endif
#include "ace/Get_Opt.h"
#include "ace/Global_Macros.h"
#include "ace/High_Res_Timer.h"

#include "gtk/gtk.h"

#include "common_file_tools.h"
#include "common_tools.h"

// *NOTE*: need this to import correct PACKAGE_STRING/VERSION/... !
#ifdef HAVE_CONFIG_H
#include "rpg_config.h"
#endif

#include "rpg_common_defines.h"
#include "rpg_common_file_tools.h"
#include "rpg_common_macros.h"

#include "rpg_magic_defines.h"

#include "rpg_item_defines.h"

#include "rpg_player_common_tools.h"
#include "rpg_player_defines.h"

#include "rpg_engine_common_tools.h"

#include "rpg_sound_defines.h"

#include "rpg_graphics_defines.h"

#include "rpg_client_callbacks.h"
#include "rpg_client_common.h"
#include "rpg_client_common_tools.h"
#include "rpg_client_defines.h"

#include "character_generator_gui_callbacks.h"

#define CHARACTER_GENERATOR_GUI_GNOME_APPLICATION_ID "character generator"

test_u_main::test_u_main (void)
{
  RPG_TRACE (ACE_TEXT ("test_u_main::test_u_main"));

}

test_u_main::~test_u_main (void)
{
  RPG_TRACE (ACE_TEXT ("test_u_main::~test_u_main"));

}

void
test_u_main::print_usage(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("test_u_main::print_usage"));

  // enable verbatim boolean output
  std::cout.setf(ios::boolalpha);

  std::string configuration_path =
    RPG_Common_File_Tools::getConfigurationDataDirectory (ACE_TEXT_ALWAYS_CHAR (BASEDIR),
                                                          true);
  std::string data_path =
    RPG_Common_File_Tools::getConfigurationDataDirectory (ACE_TEXT_ALWAYS_CHAR (BASEDIR),
                                                          false);
#if defined (DEBUG_DEBUGGER)
  configuration_path = Common_File_Tools::getWorkingDirectory ();
  data_path = Common_File_Tools::getWorkingDirectory ();
#endif

  std::cout << ACE_TEXT("usage: ")
            << programName_in
            << ACE_TEXT(" [OPTIONS]")
            << std::endl
            << std::endl;
  std::cout << ACE_TEXT("currently available options:") << std::endl;
  std::string path = configuration_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  path += ACE_TEXT_ALWAYS_CHAR ("client");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  path += ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_UI_FILE);
  std::cout << ACE_TEXT ("-c [FILE]   : client UI file")
    << ACE_TEXT (" [\"")
    << path
    << ACE_TEXT ("\"]")
    << std::endl;
  path = data_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  path += ACE_TEXT_ALWAYS_CHAR("graphics");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  path += ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DATA_SUB);
#else
  path += ACE_TEXT_ALWAYS_CHAR(RPG_GRAPHICS_DATA_SUB);
#endif
  std::cout << ACE_TEXT("-d [DIR]    : graphics directory")
            << ACE_TEXT(" [\"")
            << path
            << ACE_TEXT("\"]")
            << std::endl;
  path = configuration_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  path += ACE_TEXT_ALWAYS_CHAR("graphics");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  path += ACE_TEXT_ALWAYS_CHAR(RPG_GRAPHICS_DICTIONARY_FILE);
  std::cout << ACE_TEXT("-g [FILE]   : graphics dictionary (*.xml)")
            << ACE_TEXT(" [\"")
            << path
            << ACE_TEXT("\"]")
            << std::endl;
  path = configuration_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  path += ACE_TEXT_ALWAYS_CHAR("item");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  path += ACE_TEXT_ALWAYS_CHAR(RPG_ITEM_DICTIONARY_FILE);
  std::cout << ACE_TEXT("-i [FILE]   : item dictionary (*.xml)")
            << ACE_TEXT(" [\"")
            << path
            << ACE_TEXT("\"]")
            << std::endl;
  std::cout << ACE_TEXT("-l          : log to a file")
            << ACE_TEXT(" [")
            << false
            << ACE_TEXT("]")
            << std::endl;
  path = configuration_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  path += ACE_TEXT_ALWAYS_CHAR("magic");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  path += ACE_TEXT_ALWAYS_CHAR(RPG_MAGIC_DICTIONARY_FILE);
  std::cout << ACE_TEXT("-m [FILE]   : magic dictionary (*.xml)")
            << ACE_TEXT(" [\"")
            << path
            << ACE_TEXT("\"]")
            << std::endl;
  std::cout << ACE_TEXT("-t          : trace information")
            << ACE_TEXT(" [")
            << false
            << ACE_TEXT("]")
            << std::endl;
  path = configuration_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  path += ACE_TEXT_ALWAYS_CHAR("test_u");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  path += ACE_TEXT_ALWAYS_CHAR("character");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  path += ACE_TEXT_ALWAYS_CHAR("player");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  path += ACE_TEXT_ALWAYS_CHAR(CHARACTER_GENERATOR_GTK_GLADE_FILE);
  std::cout << ACE_TEXT("-u [FILE]   : UI file")
            << ACE_TEXT(" [\"")
            << path
            << ACE_TEXT("\"]")
            << std::endl;
  std::cout << ACE_TEXT("-v          : print version information and exit")
            << ACE_TEXT(" [")
            << false
            << ACE_TEXT("]")
            << std::endl;
} // end print_usage

bool
test_u_main::process_arguments (const int& argc_in,
                                ACE_TCHAR** argv_in, // cannot be const...
                                std::string& clientUIFile_out,
                                std::string& graphicsDictionary_out,
                                std::string& itemDictionary_out,
                                bool& logToFile_out,
                                std::string& magicDictionary_out,
                                bool& traceInformation_out,
                                std::string& UIFile_out,
                                std::string& graphicsDirectory_out,
                                bool& printVersionAndExit_out)
{
  RPG_TRACE (ACE_TEXT ("test_u_main::process_arguments"));

  // init configuration
  std::string configuration_path =
    RPG_Common_File_Tools::getConfigurationDataDirectory (ACE_TEXT_ALWAYS_CHAR (BASEDIR),
                                                          true);
  std::string data_path =
    RPG_Common_File_Tools::getConfigurationDataDirectory (ACE_TEXT_ALWAYS_CHAR (BASEDIR),
                                                          false);
#if defined (DEBUG_DEBUGGER)
  configuration_path = Common_File_Tools::getWorkingDirectory ();
  data_path = Common_File_Tools::getWorkingDirectory ();
#endif

  clientUIFile_out = configuration_path;
  clientUIFile_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  clientUIFile_out += ACE_TEXT_ALWAYS_CHAR ("client");
  clientUIFile_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  clientUIFile_out += ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_UI_FILE);

  graphicsDictionary_out  = configuration_path;
  graphicsDictionary_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  graphicsDictionary_out += ACE_TEXT_ALWAYS_CHAR ("graphics");
  graphicsDictionary_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  graphicsDictionary_out +=
    ACE_TEXT_ALWAYS_CHAR (RPG_GRAPHICS_DICTIONARY_FILE);

  itemDictionary_out      = configuration_path;
  itemDictionary_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  itemDictionary_out += ACE_TEXT_ALWAYS_CHAR ("item");
  itemDictionary_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  itemDictionary_out += ACE_TEXT_ALWAYS_CHAR (RPG_ITEM_DICTIONARY_FILE);

  logToFile_out = false;

  magicDictionary_out = configuration_path;
  magicDictionary_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  magicDictionary_out += ACE_TEXT_ALWAYS_CHAR ("magic");
  magicDictionary_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  magicDictionary_out += ACE_TEXT_ALWAYS_CHAR (RPG_MAGIC_DICTIONARY_FILE);

  traceInformation_out = false;

  UIFile_out = configuration_path;
  UIFile_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  UIFile_out += ACE_TEXT_ALWAYS_CHAR ("test_u");
  UIFile_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  UIFile_out += ACE_TEXT_ALWAYS_CHAR ("character");
  UIFile_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  UIFile_out += ACE_TEXT_ALWAYS_CHAR ("player");
  UIFile_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  UIFile_out += CHARACTER_GENERATOR_GTK_GLADE_FILE;

  graphicsDirectory_out   = data_path;
  graphicsDirectory_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  graphicsDirectory_out += ACE_TEXT_ALWAYS_CHAR ("graphics");
  graphicsDirectory_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  graphicsDirectory_out += ACE_TEXT_ALWAYS_CHAR (RPG_COMMON_DATA_SUB);
#else
  graphicsDirectory_out += ACE_TEXT_ALWAYS_CHAR(RPG_GRAPHICS_DATA_SUB);
#endif

  printVersionAndExit_out = false;

  ACE_Get_Opt argumentParser(argc_in,
                             argv_in,
                             ACE_TEXT("c:d:g:i:lm:tu:v"),
                             1,                         // skip command name
                             1,                         // report parsing errors
                             ACE_Get_Opt::PERMUTE_ARGS, // ordering
                             0);                        // don't use long options

  int option = 0;
  while ((option = argumentParser()) != EOF)
  {
    switch (option)
    {
      case 'c':
      {
        clientUIFile_out = ACE_TEXT_ALWAYS_CHAR (argumentParser.opt_arg ());

        break;
      }
      case 'd':
      {
        graphicsDirectory_out = ACE_TEXT_ALWAYS_CHAR (argumentParser.opt_arg ());

        break;
      }
      case 'g':
      {
        graphicsDictionary_out = ACE_TEXT_ALWAYS_CHAR (argumentParser.opt_arg ());

        break;
      }
      case 'i':
      {
        itemDictionary_out = ACE_TEXT_ALWAYS_CHAR (argumentParser.opt_arg ());

        break;
      }
      case 'l':
      {
        logToFile_out = true;

        break;
      }
      case 'm':
      {
        magicDictionary_out = ACE_TEXT_ALWAYS_CHAR (argumentParser.opt_arg ());

        break;
      }
      case 't':
      {
        traceInformation_out = true;

        break;
      }
      case 'u':
      {
        UIFile_out = ACE_TEXT_ALWAYS_CHAR (argumentParser.opt_arg ());

        break;
      }
      case 'v':
      {
        printVersionAndExit_out = true;

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
                   ACE_TEXT(argumentParser.last_option())));

        return false;
      }
      case 0:
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("found long option \"%s\", aborting\n"),
                   ACE_TEXT(argumentParser.long_option())));

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

bool
test_u_main::init_GUI (const std::string& graphics_directory_in,
                       const Character_Generator_XMLFiles_t& files_in,
                       GTK_cb_data_t& userData_in)
{
  RPG_TRACE (ACE_TEXT ("test_u_main::init_GUI"));

  // sanity check(s)
  if (!Common_File_Tools::isDirectory (graphics_directory_in))
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("invalid directory \"%s\", aborting\n"),
                ACE_TEXT (graphics_directory_in.c_str ())));
    return false;
  } // end IF

  // step1: load XML
  GladeXML* XML_tree = NULL;
  for (Character_Generator_XMLFilesConstIterator_t iterator = files_in.begin ();
       iterator != files_in.end ();
       iterator++)
  {
    // sanity check
    if (!Common_File_Tools::isReadable (*iterator))
    {
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("UI definition file \"%s\" not readable, aborting\n"),
                  ACE_TEXT ((*iterator).c_str ())));

      //// *TODO*: clean up ?
      //// --> iterate over all widgets and release references for any toplevel windows
      //GList* list = NULL;
      //for (Character_Generator_XMLPoolIterator_t iterator_2 = userData_in.XML_pool.begin();
      //		 iterator_2 != userData_in.XML_pool.end();
      //		 iterator_2++)
      //{
      //	list = glade_xml_get_widget_prefix((*iterator_2).second,
      //																		 ACE_TEXT_ALWAYS_CHAR(""));
      //	ACE_ASSERT(list);
      // 	g_object_unref(G_OBJECT((*iterator_2).second->parent));
      //	g_list_free_full(list, (GDestroyNotify)g_free);
      //	//g_list_foreach(list, (GFunc)g_free, NULL);
      //	//g_list_free(list);
      //} // end FOR

      return false;
    } // end IF

    // load widget tree
    XML_tree = glade_xml_new ((*iterator).c_str (), // definition file
                              NULL,                // root widget --> construct all
                              NULL);               // (translation) domain
    if (!XML_tree)
    {
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("failed to glade_xml_new(\"%s\"), aborting\n"),
                  ACE_TEXT ((*iterator).c_str ())));

      // *TODO*: clean up ? (see above)

      return false;
    } // end IF

    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("loaded UI file \"%s\"...\n"),
                ACE_TEXT ((*iterator).c_str ())));

    userData_in.XML_pool[ACE_TEXT_ALWAYS_CHAR (ACE::basename (ACE_TEXT ((*iterator).c_str ())))] = XML_tree;
  } // end FOR

  // step2: retrieve dialog handles
  Character_Generator_XMLPoolIterator_t iterator =
    userData_in.XML_pool.find (ACE_TEXT_ALWAYS_CHAR (CHARACTER_GENERATOR_GTK_GLADE_FILE));
  if (iterator == userData_in.XML_pool.end ())
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("XML tree for \"%s\"not available, aborting\n"),
                ACE_TEXT (CHARACTER_GENERATOR_GTK_GLADE_FILE)));

    // *TODO*: clean up ? (see above)

    return false;
  } // end IF

  GtkWidget* main_dialog = NULL;
  main_dialog =
    GTK_WIDGET (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_DIALOG_MAIN_NAME)));
  ACE_ASSERT (main_dialog);

  GtkWidget* about_dialog =
    GTK_WIDGET (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_DIALOG_ABOUT_NAME)));
  ACE_ASSERT (about_dialog);

  // step3: populate combobox
  GtkComboBox* combobox =
    GTK_COMBO_BOX (glade_xml_get_widget ((*iterator).second,
                                         ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_COMBOBOX_CHARACTER_NAME)));
  ACE_ASSERT (combobox);
  gtk_cell_layout_clear (GTK_CELL_LAYOUT (combobox));
  GtkCellRenderer* renderer = gtk_cell_renderer_text_new ();
  ACE_ASSERT (renderer);
  gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer,
                              TRUE); // expand ?
  //   gtk_cell_layout_add_attribute(GTK_CELL_LAYOUT(combobox), renderer,
//                                 ACE_TEXT_ALWAYS_CHAR("text"), 0);
  gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer,
                                  ACE_TEXT_ALWAYS_CHAR ("text"), 0,
                                  NULL);
  GtkListStore* list = gtk_list_store_new (1,
                                           G_TYPE_STRING);
  ACE_ASSERT (list);
  gtk_tree_sortable_set_sort_func (GTK_TREE_SORTABLE (list),
                                   0,
                                   (GtkTreeIterCompareFunc)combobox_sort_function,
                                   GINT_TO_POINTER (0),
                                   (GDestroyNotify)NULL);
  gtk_tree_sortable_set_sort_column_id (GTK_TREE_SORTABLE (list),
                                        0,
                                        GTK_SORT_ASCENDING);
  gtk_combo_box_set_model (combobox,
                           GTK_TREE_MODEL (list));
  g_object_unref (G_OBJECT (list));
  unsigned int num_entries = ::load_files (REPOSITORY_PROFILES,
                                           list);

  Character_Generator_XMLPoolIterator_t iterator_2 =
    userData_in.XML_pool.find (ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_UI_FILE));
  if (iterator_2 == userData_in.XML_pool.end ())
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("XML tree for \"%s\"not available, aborting\n"),
                ACE_TEXT (RPG_CLIENT_GTK_UI_FILE)));

    // *TODO*: clean up ? (see above)

    return false;
  } // end IF
  GtkHBox* hbox =
    GTK_HBOX (glade_xml_get_widget ((*iterator).second,
                                    ACE_TEXT_ALWAYS_CHAR (CHARACTER_GENERATOR_GTK_HBOX_NAME)));
  ACE_ASSERT (hbox);
  GtkFrame* frame =
    GTK_FRAME (glade_xml_get_widget ((*iterator_2).second,
                                     ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_FRAME_CHARACTER_NAME)));
  ACE_ASSERT (frame);
  gtk_widget_ref (GTK_WIDGET (frame));
  gtk_widget_unparent (GTK_WIDGET (frame));
  gtk_box_pack_start (GTK_BOX (hbox),
                      GTK_WIDGET (frame),
                      FALSE, // expand
                      FALSE, // fill
                      0);    // padding

  // step4a: connect default signals
  gpointer userData_p = const_cast<GTK_cb_data_t*>(&userData_in);
  g_signal_connect(main_dialog,
                   ACE_TEXT_ALWAYS_CHAR("destroy"),
                   G_CALLBACK(quit_clicked_GTK_cb),
//                    G_CALLBACK(gtk_widget_destroyed),
//                    &main_dialog,
                   userData_p);
  g_signal_connect(about_dialog,
                   ACE_TEXT_ALWAYS_CHAR("response"),
                   G_CALLBACK(gtk_widget_hide),
                   &about_dialog);

   // step4b: connect custom signals
  GtkButton* button = NULL;
  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_BUTTON_CREATE_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(create_character_clicked_GTK_cb),
                   userData_p);

  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_BUTTON_DROP_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(drop_character_clicked_GTK_cb),
                   userData_p);

  GtkFileChooserDialog* filechooser_dialog =
    GTK_FILE_CHOOSER_DIALOG (glade_xml_get_widget ((*iterator).second,
                                                   ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_DIALOG_FILECHOOSER_NAME)));
  ACE_ASSERT(filechooser_dialog);
  GtkFileFilter* file_filter = gtk_file_filter_new ();
  ACE_ASSERT(file_filter);
  if (!file_filter)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to gtk_file_filter_new(): \"%m\", aborting\n")));

  //  // clean up
    //g_object_unref(G_OBJECT((*iterator).second->parent));

    return false;
  } // end IF
  gtk_file_filter_set_name(file_filter,
                           ACE_TEXT(RPG_PLAYER_PROFILE_EXT));
  std::string pattern = ACE_TEXT_ALWAYS_CHAR("*");
  pattern += ACE_TEXT_ALWAYS_CHAR(RPG_PLAYER_PROFILE_EXT);
  gtk_file_filter_add_pattern(file_filter, ACE_TEXT(pattern.c_str()));
  gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(filechooser_dialog),
                              file_filter);
  //gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(filechooser_dialog),
  //                                    ACE_TEXT(profiles_directory.c_str()));
  g_signal_connect(filechooser_dialog,
                   ACE_TEXT_ALWAYS_CHAR("file-activated"),
                   G_CALLBACK(character_file_activated_GTK_cb),
                   userData_p);

  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_BUTTON_LOAD_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(load_character_clicked_GTK_cb),
                   userData_p);

  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_BUTTON_STORE_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(store_character_clicked_GTK_cb),
                   userData_p);

  combobox =
    GTK_COMBO_BOX (glade_xml_get_widget ((*iterator).second,
                                         ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_COMBOBOX_CHARACTER_NAME)));
  ACE_ASSERT(combobox);
  g_signal_connect(combobox,
                   ACE_TEXT_ALWAYS_CHAR("changed"),
                   G_CALLBACK(character_repository_combobox_changed_GTK_cb),
                   userData_p);

  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_BUTTON_REFRESH_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(character_repository_button_clicked_GTK_cb),
                   userData_p);

  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR(CHARACTER_GENERATOR_GTK_BUTTON_IMAGEPREV_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(prev_image_clicked_GTK_cb),
                   userData_p);

  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR(CHARACTER_GENERATOR_GTK_BUTTON_IMAGENEXT_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(next_image_clicked_GTK_cb),
                   userData_p);

  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_BUTTON_QUIT_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(quit_clicked_GTK_cb),
                   userData_p);

  button =
    GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                      ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_BUTTON_ABOUT_NAME)));
  ACE_ASSERT(button);
  g_signal_connect(button,
                   ACE_TEXT_ALWAYS_CHAR("clicked"),
                   G_CALLBACK(about_clicked_GTK_cb),
                   userData_p);

  // step5: auto-connect signals/slots
//   glade_xml_signal_autoconnect(xml);

//   // step6: use correct screen
//   if (parentWidget_in)
//     gtk_window_set_screen(GTK_WINDOW(dialog),
//                           gtk_widget_get_screen(const_cast<GtkWidget*> (//                                                                parentWidget_in)));

  // step6: draw it
  gtk_widget_show_all(main_dialog);

  // step7: activate first repository entry (if any)
  gtk_widget_set_sensitive (GTK_WIDGET (combobox), (num_entries > 0));
  if (num_entries > 0)
    gtk_combo_box_set_active(combobox, 0);
  else
  {
    // make create button sensitive (if it's not already)
    button =
      GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                        ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_BUTTON_CREATE_NAME)));
    ACE_ASSERT(button);
    gtk_widget_set_sensitive(GTK_WIDGET(button), TRUE);

    // make load button sensitive (if it's not already)
    button =
      GTK_BUTTON (glade_xml_get_widget ((*iterator).second,
                                        ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_GTK_BUTTON_LOAD_NAME)));
    ACE_ASSERT (button);
    gtk_widget_set_sensitive (GTK_WIDGET (button), TRUE);
  } // end ELSE

  return true;
}

void
test_u_main::do_work(const std::string& schemaDirectory_in,
                     const std::string& clientUIFile_in,
                     const std::string& magicDictionary_in,
                     const std::string& itemDictionary_in,
                     const std::string& graphicsDictionary_in,
                     const std::string& graphicsDirectory_in,
                     const std::string& UIFile_in)
{
  RPG_TRACE (ACE_TEXT ("test_u_main::do_work"));

  //// step0a: init XML parsing
  //RPG_Common_XML_Tools::init(schemaDirectory_in);
  // step0b: init RPG engine
  std::string empty;
  RPG_Engine_Common_Tools::init(schemaDirectory_in,
                                magicDictionary_in,
                                itemDictionary_in,
                                empty);
  RPG_Client_SDL_InputConfiguration_t input_configuration;
  input_configuration.key_repeat_initial_delay = SDL_DEFAULT_REPEAT_DELAY;
  input_configuration.key_repeat_interval = SDL_DEFAULT_REPEAT_INTERVAL;
  input_configuration.use_UNICODE = true;
  RPG_Sound_SDLConfiguration_t sound_configuration;
  sound_configuration.frequency = RPG_SOUND_AUDIO_DEF_FREQUENCY;
  sound_configuration.format = RPG_SOUND_AUDIO_DEF_FORMAT;
  sound_configuration.channels = RPG_SOUND_AUDIO_DEF_CHANNELS;
  sound_configuration.chunksize = RPG_SOUND_AUDIO_DEF_CHUNKSIZE;
  RPG_Client_Common_Tools::init(input_configuration,
                                sound_configuration,
                                empty,
                                RPG_SOUND_AMBIENT_DEF_USE_CD,
                                RPG_SOUND_DEF_CACHESIZE,
                                false,
                                empty,
                                //
                                graphicsDirectory_in,
                                RPG_GRAPHICS_DEF_CACHESIZE,
                                graphicsDictionary_in,
                                false); // don't init SDL

  GTK_cb_data_t user_data;
  //user_data.XML_pool();
  user_data.schema_repository = schemaDirectory_in;
  user_data.entity.character  = NULL;
  user_data.entity.position   =
      std::make_pair(std::numeric_limits<unsigned int>::max(),
                     std::numeric_limits<unsigned int>::max());
  user_data.entity.modes.clear();
  user_data.entity.actions.clear();
  user_data.entity.is_spawned = false;
  // init sprite gallery
  for (int index = 0;
       index < RPG_GRAPHICS_SPRITE_MAX;
       index++)
    user_data.sprite_gallery.push_back(static_cast<RPG_Graphics_Sprite>(index));
  user_data.sprite_gallery_iterator = user_data.sprite_gallery.begin();
  user_data.current_sprite = RPG_GRAPHICS_SPRITE_INVALID;
  user_data.is_transient = false;

  Character_Generator_XMLFiles_t ui_files;
  ui_files.push_back (UIFile_in);
  ui_files.push_back (clientUIFile_in);
  if (!init_GUI (graphicsDirectory_in, // graphics directory
                 ui_files,             // UI definition files
                 user_data))           // GTK cb data
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to initialize UI, aborting\n")));
    return;
  } // end IF

  // step2: setup event loops
  // - UI events --> GTK main loop
  gtk_main();

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished working...\n")));
}

void
test_u_main::print_version (const std::string& programName_in)
{
  RPG_TRACE (ACE_TEXT ("test_u_main::print_version"));

  std::cout << programName_in
#ifdef HAVE_CONFIG_H
            << ACE_TEXT(" : ")
            << RPG_VERSION
#endif
            << std::endl;

  // create version string...
  // *NOTE*: cannot use ACE_VERSION, as it doesn't contain the (potential) beta
  // version number... We need this, as the library soname is compared to this
  // string
  std::ostringstream version_number;
  version_number << ACE::major_version();
  version_number << ACE_TEXT(".");
  version_number << ACE::minor_version();
  if (ACE::beta_version())
  {
    version_number << ACE_TEXT(".");
    version_number << ACE::beta_version();
  } // end IF

  std::cout << ACE_TEXT("ACE: ") << version_number.str() << std::endl;
//   std::cout << "ACE: "
//             << ACE_VERSION
//             << std::endl;
}

int
test_u_main::run_i (int argc_in,
                    char* argv_in[])
{
  RPG_TRACE (ACE_TEXT ("test_u_main::run_i"));

  // *PORTABILITY*: on Windows, need to init ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
  if (ACE::init () == -1)
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to ACE::init(): \"%m\", aborting\n")));
    return EXIT_FAILURE;
  } // end IF
#endif

  // step1 init/validate configuration
  std::string configuration_path =
    RPG_Common_File_Tools::getConfigurationDataDirectory (ACE_TEXT_ALWAYS_CHAR (BASEDIR),
                                                          true);
  std::string data_path =
    RPG_Common_File_Tools::getConfigurationDataDirectory (ACE_TEXT_ALWAYS_CHAR (BASEDIR),
                                                          false);
#if defined(DEBUG_DEBUGGER)
  configuration_path = Common_File_Tools::getWorkingDirectory ();
  data_path = Common_File_Tools::getWorkingDirectory ();
#endif

  // step1a: process commandline arguments
  std::string client_ui_file = configuration_path;
  client_ui_file += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  client_ui_file += ACE_TEXT_ALWAYS_CHAR ("client");
  client_ui_file += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  client_ui_file += ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_GTK_UI_FILE);;

  std::string graphics_dictionary = configuration_path;
  graphics_dictionary += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  graphics_dictionary += ACE_TEXT_ALWAYS_CHAR("graphics");
  graphics_dictionary += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  graphics_dictionary += ACE_TEXT_ALWAYS_CHAR(RPG_GRAPHICS_DICTIONARY_FILE);

  std::string item_dictionary     = configuration_path;
  item_dictionary += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  item_dictionary += ACE_TEXT_ALWAYS_CHAR("item");
  item_dictionary += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  item_dictionary += ACE_TEXT_ALWAYS_CHAR(RPG_ITEM_DICTIONARY_FILE);

  std::string magic_dictionary    = configuration_path;
  magic_dictionary += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  magic_dictionary += ACE_TEXT_ALWAYS_CHAR("magic");
  magic_dictionary += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  magic_dictionary += ACE_TEXT_ALWAYS_CHAR(RPG_MAGIC_DICTIONARY_FILE);

  std::string ui_file             = configuration_path;
  ui_file += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  ui_file += ACE_TEXT_ALWAYS_CHAR ("test_u");
  ui_file += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  ui_file += ACE_TEXT_ALWAYS_CHAR ("character");
  ui_file += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  ui_file += ACE_TEXT_ALWAYS_CHAR ("player");
  ui_file += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif
  ui_file += ACE_TEXT_ALWAYS_CHAR (CHARACTER_GENERATOR_GTK_GLADE_FILE);

  std::string schema_repository   = configuration_path;
#if defined (DEBUG_DEBUGGER)
  schema_repository += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  schema_repository += ACE_TEXT_ALWAYS_CHAR("engine");
#endif

  std::string graphics_directory  = data_path;
  graphics_directory += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined (DEBUG_DEBUGGER)
  graphics_directory += ACE_TEXT_ALWAYS_CHAR("graphics");
  graphics_directory += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  graphics_directory += ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DATA_SUB);
#else
  graphics_directory += ACE_TEXT_ALWAYS_CHAR(RPG_GRAPHICS_DATA_SUB);
#endif

  // sanity check
  if (!Common_File_Tools::isDirectory (schema_repository))
  {
    ACE_DEBUG ((LM_WARNING,
                ACE_TEXT ("invalid XML schema repository (was: \"%s\"), continuing\n"),
                ACE_TEXT (schema_repository.c_str ())));

    // try fallback
    schema_repository.clear();
  } // end IF

  bool log_to_file = false;
  bool trace_information = false;
  bool print_version_and_exit = false;
  if (!process_arguments (argc_in,
                          argv_in,
                          client_ui_file,
                          graphics_dictionary,
                          item_dictionary,
                          log_to_file,
                          magic_dictionary,
                          trace_information,
                          ui_file,
                          graphics_directory,
                          print_version_and_exit))
  {
    // make 'em learn...
    print_usage (ACE::basename (argv_in[0]));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini () == -1)
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF

  // validate argument(s)
  if (!Common_File_Tools::isReadable (client_ui_file)      ||
      !Common_File_Tools::isReadable (graphics_dictionary) ||
      !Common_File_Tools::isReadable (item_dictionary)     ||
      !Common_File_Tools::isReadable (magic_dictionary)    ||
      !Common_File_Tools::isReadable (ui_file)             ||
      !Common_File_Tools::isDirectory (graphics_directory))
  {
    // make 'em learn...
    print_usage(ACE::basename(argv_in[0]));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini () == -1)
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF

  // step1b: handle specific program modes
  if (print_version_and_exit)
  {
    print_version(ACE::basename(argv_in[0]));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini () == -1)
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_SUCCESS;
  } // end IF

  // step1c: initialize logging and/or tracing
  std::string log_file;
  if (!Common_Tools::initializeLogging (ACE::basename (argv_in[0]), // program name
                                        log_file,                  // logfile
                                        false,                     // log to syslog ?
                                        false,                     // trace messages ?
                                        trace_information,         // debug messages ?
                                        NULL))                     // logger
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to Common_Tools::initializeLogging(), aborting\n")));

    // *PORTABILITY*: on Windows, need to fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini () == -1)
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF

  // step2b: init GLIB / G(D|T)K[+] / GNOME
#if defined (ACE_WIN32) || defined (ACE_WIN64)
  g_thread_init (NULL);
#endif
  gdk_threads_init ();
  gtk_init (&argc_in,
            &argv_in);
//   GnomeClient* gnomeSession = NULL;
//   gnomeSession = gnome_client_new();
//   ACE_ASSERT(gnomeSession);
//   gnome_client_set_program(gnomeSession, ACE::basename(argv_in[0]));
//  GnomeProgram* gnomeProgram = NULL;
//  gnomeProgram = gnome_program_init(RPG_CHARACTER_GENERATOR_GUI_DEF_GNOME_APPLICATION_ID, // app ID
//#ifdef HAVE_CONFIG_H
////                                     ACE_TEXT_ALWAYS_CHAR(VERSION),     // version
//                                    ACE_TEXT_ALWAYS_CHAR(RPG_VERSION),    // version
//#else
//	                                NULL,
//#endif
//                                    LIBGNOMEUI_MODULE,                    // module info
//                                    argc_in,                              // cmdline
//                                    argv_in,                              // cmdline
//                                    NULL);                                // property name(s)
//  ACE_ASSERT(gnomeProgram);

  ACE_High_Res_Timer timer;
  timer.start ();
  // step3: do actual work
  do_work (schema_repository,
           client_ui_file,
           magic_dictionary,
           item_dictionary,
           graphics_dictionary,
           graphics_directory,
           ui_file);
  timer.stop ();
  // debug info
  std::string working_time_string;
  ACE_Time_Value working_time;
  timer.elapsed_time (working_time);
  Common_Tools::period2String (working_time,
                               working_time_string);

  ACE_DEBUG ((LM_DEBUG,
              ACE_TEXT ("total working time (h:m:s.us): \"%s\"...\n"),
              ACE_TEXT (working_time_string.c_str ())));

  // *PORTABILITY*: on Windows, fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
  if (ACE::fini () == -1)
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to ACE::fini(): \"%m\", aborting\n")));
    return EXIT_FAILURE;
  } // end IF
#endif

  return EXIT_SUCCESS;
}
