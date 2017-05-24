#include <thread>

#include "Input.h"

Snow::Input::Input()
{
}

Snow::Input::~Input()
{
}

bool Snow::Input::isPressed(const Keys &key)
{
	return key == Snow::Keys::ArrowRight;
}

void Snow::Input::checkKeys()
{

}

void Snow::Input::holdKeys()
{

}

void Snow::Input::work()
{
	std::thread checkThread(&Snow::Input::checkKeys, this);
	std::thread holdThread(&Snow::Input::holdKeys, this);

	checkThread.join();
	holdThread.join();
}
