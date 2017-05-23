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

	bool dir = true;
	
	while (true)
	{
		usleep(100000);
		if (dir)
		{
			_position.setX(_position.getX() + 1);
			if (_position.getX() + _sprite.getWidth() == camera->getPosition().getX() + camera->getWidth())
			{
				dir = false;
			}
		}
		else
		{
			_position.setX(_position.getX() - 1);
			if (_position.getX() == camera->getPosition().getX())
			{
				dir = true;
			}

		}
	}
}
