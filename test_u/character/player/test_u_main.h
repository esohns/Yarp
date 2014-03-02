/***************************************************************************
 *   Copyright (C) 2014 by Erik Sohns   *
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

#ifndef TEST_U_MAIN_H
#define TEST_U_MAIN_H
#pragma once

#include "character_generator_gui_common.h"

#include <ace/OS.h>

#include <string>

class test_u_main
 : public ACE_Main_Base
{
 public:
	test_u_main(void);
	virtual ~test_u_main(void);

	virtual int run_i(int,      // argc
		                char*[]); // argv

 private:
	// helper methods
  void print_usage(const std::string&);
	bool process_arguments(const int,     // argc
												 ACE_TCHAR*[],  // argv (*NOTE*: cannot be const)...
												 std::string&,  // graphics dictionary
												 std::string&,  // item dictionary,
												 bool&,         // log to file ?
												 std::string&,  // magic dictionary,
												 bool&,         // trace information ?,
												 std::string&,  // UI definition file,
												 std::string&,  // graphics directory,
												 bool&);        // print program version only ?
	bool init_GUI(const std::string&, // graphics directory
		            const std::string&, // UI definition file
								GTK_cb_data_t&);    // callback user data
	void do_work(const std::string&,  // schema directory
		           const std::string&,  // magic dictionary
							 const std::string&,  // item dictionary
							 const std::string&,  // graphics dictionary
							 const std::string&,  // graphics directory
							 const std::string&); // UI definition file
	void print_version(const std::string&); // program name
};

#endif
