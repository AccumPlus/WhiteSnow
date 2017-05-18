#include <curses.h>

#include <memory>

#include "Printer.h"
#include "Camera.h"
#include "ObjectArray.h"
#include "Object.h"

int main()
{
	Snow::Camera camera;
	camera.setWidth(30);
	camera.setHeight(15);
	camera.setPosition(0, 0);
	
	Snow::ObjectArray objectArray;

	auto obj = std::make_shared<Snow::Object>();
//	Snow::Object *obj = new Snow::Object();
	obj->setSprite("../etc/example.sprite");
	obj->setPosition(0, 0);
	obj->setLayerNumber(0);

	objectArray.addObject("FirstObject", obj);

	obj.reset();

	Snow::Printer pr(camera, objectArray);

	initscr();

	pr.work();

	getch();

	endwin();

	return 0;
}
