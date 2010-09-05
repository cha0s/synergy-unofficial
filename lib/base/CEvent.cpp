/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2004 Chris Schoeneman
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file COPYING that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "CEvent.h"
#include "CEventQueue.h"

//
// CEvent
//

CEvent::CEvent() :
	m_type(kUnknown),
	m_target(NULL),
	m_data(NULL),
	m_flags(0)
{
	// do nothing
}

CEvent::CEvent(Type type, void* target, void* data, Flags flags) :
	m_type(type),
	m_target(target),
	m_data(data),
	m_flags(flags)
{
	// do nothing
}

CEvent::Type
CEvent::getType() const
{
	return m_type;
}

void*
CEvent::getTarget() const
{
	return m_target;
}

void*
CEvent::getData() const
{
	return m_data;
}

CEvent::Flags
CEvent::getFlags() const
{
	return m_flags;
}

CEvent::Type
CEvent::registerType(const char* name)
{
	return EVENTQUEUE->registerType(name);
}

CEvent::Type
CEvent::registerTypeOnce(Type& type, const char* name)
{
	return EVENTQUEUE->registerTypeOnce(type, name);
}

const char*
CEvent::getTypeName(Type type)
{
	return EVENTQUEUE->getTypeName(type);
}

void
CEvent::deleteData(const CEvent& event)
{
	switch (event.getType()) {
	case kUnknown:
	case kQuit:
	case kSystem:
	case kTimer:
		break;

	default:
		if ((event.getFlags() & kDontFreeData) == 0) {
			free(event.getData());
		}
		break;
	}
}
