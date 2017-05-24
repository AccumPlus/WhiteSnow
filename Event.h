#ifndef SNOW_EVENT_H
#define SNOW_EVENT_H

#include <string>

namespace Snow
{
	enum class EventType {
		StartObject = 0,
		StopObject
	};

	class Event
	{
	public:
		Event(const std::string &name, EventType type);
		~Event();

		std::string getName() const;
		EventType getType() const;

	private:
		std::string _name;
		EventType _type;
	};
}

#endif
