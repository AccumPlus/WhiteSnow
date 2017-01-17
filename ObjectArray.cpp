#include <iostream>

#include "ObjectArray.h"
#include "Object.h"

Snow::ObjectArray::ObjectArray()
{
	std::cout << "ObjectArray constructor" << std::endl;
}

Snow::ObjectArray::~ObjectArray()
{
}

void Snow::ObjectArray::addObject(std::string name, Snow::Object *object)
{
	std::cout << "ObjectArray add object" << std::endl;

	auto it = _objects.find(name);
	if (it == _objects.end())
		_objects[name] = object;
}

void Snow::ObjectArray::removeObject(const std::string &name)
{
	auto it = _objects.find(name);
	if (it != _objects.end())
		_objects.erase(it);
	
}

void Snow::ObjectArray::changeName(const std::string &from, const std::string &to)
{
	auto it = _objects.find(to);
	if (it != _objects.end())
		return;

	it = _objects.find(from);
	if (it != _objects.end())
	{
		Snow::Object *object = it->second;
		_objects.erase(it);
		_objects[to] = object;
	}

}

Snow::Object* Snow::ObjectArray::getObject(const std::string &name) const
{
	auto it = _objects.find(name);
	if (it != _objects.end())
		return it->second;
	else
		return nullptr;
}

std::vector<Snow::Object*> Snow::ObjectArray::getArray() const
{
	std::vector<Snow::Object*> tArray;
	for (auto obj: _objects)
		tArray.push_back(obj.second);
	return tArray;
}
