#include <unistd.h>
#include <iostream>
#include <memory>

#include "myObject.h"
#include "../ObjectArray.h"
#include "../Position.h"
#include "../Camera.h"
#include "../myObject2/myObject2.h"

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

//	bool dir = true;
	unsigned short cnt = 0;
	
	while (true)
	{
		usleep(1000000);

		auto obj = std::make_shared<MyObject2>();
		obj->setSprite("../etc/example2.sprite");
		obj->setPosition(camera->getWidth() / 2, 0);
		obj->setLayerNumber(0);
		obj->setName(std::to_string(cnt++));

		_parent->addObject(obj);

//		if (dir)
//		{
//			_position.setX(_position.getX() + 1);
//			if (_position.getX() + _sprite.getWidth() == camera->getPosition().getX() + camera->getWidth())
//			{
//				dir = false;
//			}
//		}
//		else
//		{
//			_position.setX(_position.getX() - 1);
//			if (_position.getX() == camera->getPosition().getX())
//			{
//				dir = true;
//			}

		}
//	}
}
