#include <unistd.h>
#include <iostream>
#include <memory>

#include "myObject.h"
#include "../ObjectArray.h"
#include "../Position.h"
#include "../Camera.h"

MyObject::MyObject():
	Object()
{
}

MyObject::~MyObject()
{
}

void MyObject::work()
{
	auto camera = std::static_pointer_cast<Snow::Camera>(_parent->getObject("__camera__"));

	Snow::Position tDownRight;
	tDownRight.setX(_position.getX() + _sprite.getWidth());
	tDownRight.setY(_position.getY() + _sprite.getHeight());

	bool dir = true;
	
	while (true)
	{
		sleep(1);
		if (dir)
			_position.setX(_position.getX() + 1);
		else
			_position.setX(_position.getX() - 1);

		if (tDownRight.getX() == camera->getWidth() - 1)
			dir = false;

		if (tDownRight.getX() == camera->getPosition().getX())
			dir = true;
	}
}
