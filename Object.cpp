#include <iostream>

#include "Object.h"

Snow::Object::Object():
	_parent(nullptr)
{
}

Snow::Object::~Object()
{
}

void Snow::Object::setParent(Snow::ObjectArray *parent)
{
	std::lock_guard<std::mutex> lg(_mut);
	this->_parent = parent;
}

Snow::SpriteObject Snow::Object::getSpriteObject()
{
	std::lock_guard<std::mutex> lg(_mut);
	Snow::SpriteObject *tSpriteObject = this;
	return *tSpriteObject;
}

void Snow::Object::startJob()
{
	work();
	endJob();
}

void Snow::Object::endJob()
{
	if (_parent)
	{
		
	}
}

void Snow::Object::setName(const std::string &name)
{
	std::lock_guard<std::mutex> lg(_mut);
	_name = name;
}

std::string Snow::Object::getName() const
{
	std::lock_guard<std::mutex> lg(_mut);
	return _name;
}
