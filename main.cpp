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
	camera->setWidth(20);
	camera->setHeight(40);
	camera->setPosition(0, 0);
	camera->setLayerNumber(-1);
	camera->setName("__camera__");
	
	objectArray.addObject(camera);

	{
		auto obj = std::make_shared<MyObject>();
		obj->setSprite("../etc/example.sprite");
		obj->setPosition(5, 0);
		obj->setLayerNumber(1);
		obj->setName("FirstObject");

		objectArray.addObject(obj);
	}

//	{
//		auto obj = std::make_shared<MyObject2>();
//		obj->setSprite("../etc/example2.sprite");
//		obj->setPosition(5, 0);
//		obj->setLayerNumber(0);
//		obj->setName("SecondObject");
//
//		objectArray.addObject(obj);
//	}

	Snow::Printer pr(objectArray);
	Snow::Controller cr(objectArray);

	initscr();
//	cbreak();
//	noecho();
//	keypad(stdscr, TRUE);
	curs_set(0);
//
	std::thread thr(&Snow::Printer::work, pr);
////	pr.work();
//
	cr.work();
//
//	int a = getch();
//
//	move(1, 1);
//	printw(std::to_string(a).c_str());

	getch();

	endwin();

	return 0;
}
