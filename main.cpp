#include <curses.h>

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

	Snow::Object *obj = new Snow::Object();
	obj->setSprite("../etc/example.sprite");
	obj->setPosition(0, 0);
	obj->setLayerNumber(0);

	objectArray.addObject("FirstObject", obj);

	Snow::Printer pr(&camera, objectArray);

	initscr();

	pr.work();

	getch();

	endwin();

	delete obj;

	return 0;
}
