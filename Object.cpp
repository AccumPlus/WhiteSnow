#include <iostream>

#include "Object.h"

Snow::Object::Object()
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
	Snow::SpriteObject *tSpriteObject = this;
	return *tSpriteObject;
}
