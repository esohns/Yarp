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

#ifndef RPG_NET_STREAM_MESSAGEALLOCATOR_H
#define RPG_NET_STREAM_MESSAGEALLOCATOR_H

#include "rpg_net_message.h"
#include "rpg_net_sessionmessage.h"

#include <stream_messageallocatorheap_base.h>
#include <stream_datablockallocatorheap.h>

// forward declarations
class Stream_AllocatorHeap;

class RPG_Net_StreamMessageAllocator
 : public Stream_MessageAllocatorHeapBase<RPG_Net_Message,
                                          RPG_Net_SessionMessage>
{
 public:
  RPG_Net_StreamMessageAllocator(const unsigned long&,   // total number of concurrent messages
                                 Stream_AllocatorHeap*); // (heap) memory allocator...
  virtual ~RPG_Net_StreamMessageAllocator();

 private:
  typedef Stream_MessageAllocatorHeapBase<RPG_Net_Message,
                                          RPG_Net_SessionMessage> inherited;

  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Net_StreamMessageAllocator(const RPG_Net_StreamMessageAllocator&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Net_StreamMessageAllocator& operator=(const RPG_Net_StreamMessageAllocator&));
};

#endif