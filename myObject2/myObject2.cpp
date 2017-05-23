#include <unistd.h>
#include <iostream>
#include <memory>

#include "myObject2.h"
#include "../ObjectArray.h"
#include "../Position.h"
#include "../Camera.h"

MyObject2::MyObject2():
	Object()
{
}

MyObject2::~MyObject2()
{
}

void MyObject2::work()
{
	auto camera = std::static_pointer_cast<Snow::Camera>(_parent->getObject("__camera__"));

	bool dir = true;
	
	while (true)
	{
		usleep(10000);
		if (dir)
		{
			_position.setY(_position.getY() + 1);
			if (_position.getY() + _sprite.getHeight() == camera->getPosition().getY() + camera->getHeight())
			{
				dir = false;
			}
		}
		else
		{
			_position.setY(_position.getY() - 1);
			if (_position.getY() == camera->getPosition().getY())
			{
				dir = true;
			}

		}
	}
}
