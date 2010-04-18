#!/bin/sh
#//%%%FILE%%%////////////////////////////////////////////////////////////////////
#// File Name: scanner.sh
#//
#// History:
#//   Date   |Name | Description of modification
#// ---------|-----|-------------------------------------------------------------
#// 20/02/06 | soh | Creation.
#//%%%FILE%%%////////////////////////////////////////////////////////////////////

# remember where we are
pushd . >/dev/null 2>&1

cd ${HOME}/Projects/RPG/net/protocol/scripts
# generate a scanner for bisecting IRC messages from the input stream
/usr/bin/flex -L --never-interactive -d --header=rpg_net_protocol_IRCbisect.h -o rpg_net_protocol_IRCbisect.cpp ./IRCbisect.l
# move the file into our project directory
mv -f rpg_net_protocol_IRCbisect.h ./..
mv -f rpg_net_protocol_IRCbisect.cpp ./..

# generate a scanner for use by our IRC message parser
/usr/bin/flex -L --never-interactive -d --header=rpg_net_protocol_IRCscanner.h -o rpg_net_protocol_IRCscanner.cpp ./IRCscanner.l
# move the file into the project directory
mv -f rpg_net_protocol_IRCscanner.h ./..
mv -f rpg_net_protocol_IRCscanner.cpp ./..

# go back
popd >/dev/null 2>&1
