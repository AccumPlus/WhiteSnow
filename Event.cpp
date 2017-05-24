#include "Event.h"

Snow::Event::Event(const std::string &name, EventType type):
	_name(name), _type(type)
{
}

Snow::Event::~Event()
{
}

std::string Snow::Event::getName() const
{
	return _name;
}

Snow::EventType Snow::Event::getType() const
{
	return _type;
}
