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
//	std::cout << "Woirk" << "\n\r";
	auto camera = std::static_pointer_cast<Snow::Camera>(_parent->getObject("__camera__"));

	bool dir = true;
	// 0 - left, 1 - up, 2 - right, 3- down
	
	while (true)
	{
		usleep(100000);
//		std::cout << "Cicle" << "\n\r";
		_position.setY(_position.getY() + 1);
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

		if (_position.getY() == camera->getPosition().getY() + camera->getHeight() - 10)
		{
//			_parent->removeObject(_name);
			break;
		}
	}
}
