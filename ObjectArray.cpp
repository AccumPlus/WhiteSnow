#include <iostream>

#include "ObjectArray.h"
#include "Object.h"

Snow::ObjectArray::ObjectArray()
{
}

Snow::ObjectArray::~ObjectArray()
{
}

void Snow::ObjectArray::addObject(const std::string &name, const std::shared_ptr<Snow::Object> &object)
{
	{
		std::lock_guard<std::mutex> lg(_mut);
		auto it = _objects.find(name);
		if (it == _objects.end())
		{
			_objects[name] = object;
		}
	}

	object->setParent(this);
}

void Snow::ObjectArray::removeObject(const std::string &name)
{
	std::lock_guard<std::mutex> lg(_mut);
	auto it = _objects.find(name);
	if (it != _objects.end())
		_objects.erase(it);
}

void Snow::ObjectArray::changeName(const std::string &from, const std::string &to)
{
	std::lock_guard<std::mutex> lg(_mut);
	auto it = _objects.find(to);
	if (it != _objects.end())
	{
		return;
	}

	it = _objects.find(from);
	if (it != _objects.end())
	{
		auto object = it->second;
		_objects.erase(it);
		_objects[to] = object;
	}
}

std::shared_ptr<Snow::Object> Snow::ObjectArray::getObject(const std::string &name) const
{
	std::lock_guard<std::mutex> lg(this->_mut);
	auto it = _objects.find(name);
	if (it != _objects.end())
		return it->second;
	else
		return nullptr;
}

// TODO разобраться, что лучше - снимок или по ссылке
std::vector<std::shared_ptr<Snow::Object> > Snow::ObjectArray::getArray() const
{
	std::lock_guard<std::mutex> lg(this->_mut);
	std::vector<std::shared_ptr<Snow::Object> > tArray;
	for (auto obj: _objects)
		tArray.push_back(obj.second);
	return tArray;
}
