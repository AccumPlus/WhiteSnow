#include <thread>

#include "ObjectArray.h"
#include "Camera.h"
#include "Controller.h"

Snow::Controller::Controller(Snow::ObjectArray &objectArray):
	_objectArray(objectArray)
{
}

Snow::Controller::~Controller()
{
}

void Snow::Controller::work()
{
	std::vector<std::thread> threads;

	for (auto &object: _objectArray.getArray())
	{
		threads.emplace_back(&Snow::Object::work, object);
	}

	for (auto &thr: threads)
	{
		thr.join();
	}
}
