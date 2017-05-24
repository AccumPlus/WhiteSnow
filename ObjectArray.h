#ifndef SNOW_OBJECT_ARRAY
#define SNOW_OBJECT_ARRAY

#include <list>
#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <condition_variable>

namespace Snow
{
	class Object;
	class SpriteObject;
	class Event;

	class ObjectArray
	{
	public:
		ObjectArray();
		~ObjectArray();

		void addObject(const std::shared_ptr<Snow::Object> &object);
		void removeObject(const std::string &name);
		void waitForEvents();
		void removeFromArray(const std::string &name);

		std::shared_ptr<Snow::Object> getObject(const std::string &name) const;
		std::vector<Snow::SpriteObject> getSnapshot() const;
		std::vector<std::shared_ptr<Snow::Object> > getArray() const;
		std::list<Snow::Event> getEventList();
	private:
		std::list<std::shared_ptr<Snow::Object> > _objects;
		std::list<Snow::Event> _eventList;

		mutable std::mutex _mut;

		std::condition_variable _cVar;
		std::mutex _cMut;
		bool _eventReady;
	};
}

#endif
