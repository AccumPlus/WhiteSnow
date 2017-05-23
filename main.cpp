#include <curses.h>
#include <unistd.h>

#include <memory>
#include <thread>
#include <iostream>

#include "Printer.h"
#include "Camera.h"
#include "ObjectArray.h"
#include "Object.h"
#include "Controller.h"
#include "myObject/myObject.h"
#include "myObject2/myObject2.h"

int main()
{
	Snow::ObjectArray objectArray;

	auto camera = std::make_shared<Snow::Camera>();
	camera->setWidth(40);
	camera->setHeight(20);
	camera->setPosition(0, 0);
	camera->setLayerNumber(-1);
	
	objectArray.addObject("__camera__", camera);

	{
		auto obj = std::make_shared<MyObject>();
		obj->setSprite("../etc/example.sprite");
		obj->setPosition(1, 1);
		obj->setLayerNumber(1);

		objectArray.addObject("FirstObject", obj);
	}

	{
		auto obj = std::make_shared<MyObject2>();
		obj->setSprite("../etc/example2.sprite");
		obj->setPosition(5, 1);
		obj->setLayerNumber(0);

		objectArray.addObject("SecondObject", obj);
	}

	Snow::Printer pr(objectArray);
	Snow::Controller cr(objectArray);

	initscr();
	curs_set(0);

	std::thread thr(&Snow::Printer::work, pr);
//	pr.work();

	cr.work();

	getch();

	endwin();

	return 0;
}
