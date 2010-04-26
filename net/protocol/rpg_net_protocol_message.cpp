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

#include "rpg_net_protocol_message.h"

#include <ace/Message_Block.h>
#include <ace/Malloc_Base.h>

RPG_Net_Protocol_Message::RPG_Net_Protocol_Message(const RPG_Net_Protocol_Message& message_in)
 : inherited(message_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Message::RPG_Net_Protocol_Message"));

}

RPG_Net_Protocol_Message::RPG_Net_Protocol_Message(ACE_Data_Block* dataBlock_in,
                                                   ACE_Allocator* messageAllocator_in)
 : inherited(dataBlock_in,        // use (don't own !) this data block
             messageAllocator_in) // use this when destruction is imminent...
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Message::RPG_Net_Protocol_Message"));

}

// RPG_Net_Protocol_Message::RPG_Net_Protocol_Message(ACE_Allocator* messageAllocator_in)
//  : inherited(messageAllocator_in,
//              true), // usually, we want to increment the running message counter...
//    myIsInitialized(false) // not initialized --> call init() !
// {
//   ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Message::RPG_Net_Protocol_Message"));
//
// }

RPG_Net_Protocol_Message::~RPG_Net_Protocol_Message()
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Message::~RPG_Net_Protocol_Message"));

  // *NOTE*: will be called just BEFORE we're passed back to the allocator
}

void
RPG_Net_Protocol_Message::dump_state() const
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Message::dump_state"));

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("***** Message (ID: %u) *****\n"),
             getID()));
  // delegate to base
  inherited::dump_state();
}

void
RPG_Net_Protocol_Message::crunch()
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Message::crunch"));

  // sanity check
  // *WARNING*: this is NOT enough, it's a race.
  // Anyway, there may be trailing messages and/or pieces referencing the same
  // buffer...
  // --> in fact, that should be the norm
//   ACE_ASSERT(reference_count() == 1);
  // ... assuming stream processing is indeed single-threaded, then the
  // reference count at this stage SHOULD be 2: us, and the next,
  // trailing "message head". Off course, it COULD be just "us"...
  if (reference_count() <= 2)
  {  // step1: align rd_ptr() with base()
    if (inherited::crunch())
    {
      ACE_DEBUG((LM_ERROR,
                ACE_TEXT("failed to ACE_Message_Block::crunch(): \"%m\", aborting\n")));

      // what can we do ?
      return;
    } // end IF
  } // end IF

  // step2: copy the data
  ACE_Message_Block* source = NULL;
  size_t amount = 0;
  for (source = cont();
       source != NULL;
       source = source->cont())
  {
    amount = (space() < source->length() ? space()
                                         : source->length());
    if (copy(source->rd_ptr(), amount))
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE_Message_Block::copy(): \"%m\", aborting\n")));

      // what can we do ?
      return;
    } // end IF

    // adjust read pointer accordingly
    source->rd_ptr(amount);
  } // end FOR

  // step3: release any thus obsoleted continuations
  source = cont();
  ACE_Message_Block* prev = this;
  ACE_Message_Block* obsolete = NULL;
  do
  {
    // finished ?
    if (source == NULL)
      break;

    if (source->length() == 0)
    {
      obsolete = source;
      source = source->cont();
      prev->cont(source);
      obsolete->release();
    } // end IF
  } while (true);
}

ACE_Message_Block*
RPG_Net_Protocol_Message::duplicate(void) const
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Message::duplicate"));

  RPG_Net_Protocol_Message* nb = NULL;

  // create a new RPG_Net_Protocol_Message that contains unique copies of
  // the message block fields, but a (reference counted) shallow duplicate of
  // the ACE_Data_Block.

  // if there is no allocator, use the standard new and delete calls.
  if (message_block_allocator_ == NULL)
  {
    ACE_NEW_RETURN(nb,
                   RPG_Net_Protocol_Message(*this), // invoke copy ctor
                   NULL);
  } // end IF
  else // otherwise, use the existing message_block_allocator
  {
    // *NOTE*: the argument to malloc SHOULDN'T really matter, as this will be
    // a "shallow" copy which just references our data block...
    // *TODO*: (depending on the allocator) we senselessly allocate a datablock
    // anyway, only to immediately release it again...
    ACE_NEW_MALLOC_RETURN(nb,
                          ACE_static_cast(RPG_Net_Protocol_Message*,
                                          message_block_allocator_->malloc(capacity())),
                          RPG_Net_Protocol_Message(*this),
                          NULL);
  } // end ELSE

  // increment the reference counts of all the continuation messages
  if (cont_)
  {
    nb->cont_ = cont_->duplicate();

    // If things go wrong, release all of our resources and return
    if (nb->cont_ == 0)
    {
      nb->release();
      nb = NULL;
    } // end IF
  } // end IF

  // *NOTE*: the "clone" always starts un-initialized --> use inherited::init()

  return nb;
}

const std::string
RPG_Net_Protocol_Message::messageType2String(const RPG_Net_Protocol_CommandType_t& messageType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Net_Protocol_Message::messageType2String"));

  std::string result = ACE_TEXT("RPG_NET_PROTOCOL_COMMANDTYPE_INVALID");

  switch (messageType_in)
  {
    case RPG_Net_Protocol_IRCMessage::NOTICE:
    {
      result = ACE_TEXT("NOTICE");

      break;
    }
    case RPG_Net_Protocol_IRCMessage::PING:
    {
      result = ACE_TEXT("PING");

      break;
    }
    case RPG_Net_Protocol_IRCMessage::PONG:
    {
      result = ACE_TEXT("PONG");

      break;
    }
    default:
    {
      // debug info
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid message type (was: %d), aborting\n"),
                 messageType_in));

      break;
    }
  } // end SWITCH

  return result;
}
