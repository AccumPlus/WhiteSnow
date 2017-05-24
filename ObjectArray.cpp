#include <iostream>
#include <algorithm>

#include "ObjectArray.h"
#include "Object.h"
#include "SpriteObject.h"
#include "Event.h"

Snow::ObjectArray::ObjectArray()
{
}

Snow::ObjectArray::~ObjectArray()
{
}

void Snow::ObjectArray::addObject(const std::shared_ptr<Snow::Object> &object)
{
	std::lock_guard<std::mutex> lg(_mut);
	for (auto it = _objects.begin(); it != _objects.end(); ++it)
	{
		if ((*it)->getName() == object->getName())
		{
			return;
		}
	}

	object->setParent(this);

	_objects.push_back(object);

	_eventList.emplace_back(object->getName(), Snow::EventType::StartObject);

	std::unique_lock<std::mutex> ul(_cMut);
	_eventReady = true;
	_cVar.notify_all();
}

void Snow::ObjectArray::removeObject(const std::string &name)
{
	std::lock_guard<std::mutex> lg(_mut);
	auto it = _objects.begin();
	for (; ; )
	{
		if ((*it)->getName() == name)
		{
			_eventList.push_back(Snow::Event(name, Snow::EventType::StopObject));
			break;
		}
		++it;
		if (it == _objects.end())
			break;
	}

	std::unique_lock<std::mutex> ul(_cMut);
	_eventReady = true;
	_cVar.notify_all();
}

void Snow::ObjectArray::waitForEvents()
{
	std::unique_lock<std::mutex> ul(_cMut);
	while (!_eventReady)
	{
		_cVar.wait(ul);
	}
}

void Snow::ObjectArray::removeFromArray(const std::string &name)
{
	std::lock_guard<std::mutex> lg(_mut);

	for (auto it = _objects.begin(); it != _objects.end(); ++it)
	{
		if ((*it)->getName() == name)
		{
			_objects.erase(it);
			break;
		}
	}
}

//void Snow::ObjectArray::changeName(const std::string &from, const std::string &to)
//{
//	std::lock_guard<std::mutex> lg(_mut);
//	auto it = _objects.find(to);
//	if (it != _objects.end())
//	{
//		return;
//	}
//
//	it = _objects.find(from);
//	if (it != _objects.end())
//	{
//		auto object = it->second;
//		_objects.erase(it);
//		_objects[to] = object;
//	}
//}

std::shared_ptr<Snow::Object> Snow::ObjectArray::getObject(const std::string &name) const
{
	std::lock_guard<std::mutex> lg(_mut);

	auto it = _objects.begin();
	for (; it != _objects.end(); ++it)
	{
		if ((*it)->getName() == name)
		{
			break;
		}
	}

	if (it == _objects.end())
		return nullptr;

	return (*it);
}

std::vector<Snow::SpriteObject> Snow::ObjectArray::getSnapshot() const
{
	std::lock_guard<std::mutex> lg(_mut);
	std::vector<Snow::SpriteObject> tArray;
	for (auto &obj: _objects)
	{
		tArray.push_back(obj->getSpriteObject());
	}
	return tArray;
}

std::vector<std::shared_ptr<Snow::Object> > Snow::ObjectArray::getArray() const
{
	std::lock_guard<std::mutex> lg(_mut);
	std::vector<std::shared_ptr<Snow::Object> > tArray;
	for (auto &obj: _objects)
	{
		tArray.push_back(obj);
	}
	return tArray;
}

std::list<Snow::Event> Snow::ObjectArray::getEventList()
{
	std::lock_guard<std::mutex> lg(_mut);

	auto tList = _eventList;
	_eventList.clear();

	std::unique_lock<std::mutex> ul(_cMut);
	_eventReady = false;
	
	return tList;
}
