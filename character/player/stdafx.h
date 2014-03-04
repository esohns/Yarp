// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//
#if defined _MSC_VER
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

// *NOTE*: workaround quirky MSVC...
#define NOMINMAX

// Windows Header Files
#include <windows.h>
#endif

// System Library Header Files
#include <ace/OS.h>
#include <ace/ACE.h>
#include <ace/Log_Msg.h>
#include <ace/Assert.h>
#include <ace/Synch.h>
#include <ace/Atomic_Op.h>
#include <ace/CDR_Stream.h>

// C RunTime Header Files
#include <string>
#include <map>
#include <vector>
#include <set>
#include <bitset>
#include <iostream>
#include <sstream>
#include <algorithm>

// Local Library Header Files
#include <xsd/cxx/pre.hxx>
#include <xsd/cxx/config.hxx>
#include <xsd/cxx/xml/error-handler.hxx>

// Local Header Files
#include <rpg_dice_incl.h>
#include <rpg_common_macros.h>
#include <rpg_common_incl.h>
#include <rpg_common_environment_incl.h>
#include <rpg_character_incl.h>
#include <rpg_magic_incl.h>
#include <rpg_item_incl.h>
#include <rpg_combat_incl.h>
