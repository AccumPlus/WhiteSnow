#include <ncurses.h>
#include <unistd.h>

#include <thread>
#include <iostream>

#include "Input.h"

std::map<int, unsigned long> Snow::Input::_pressedChars;
std::mutex Snow::Input::_mut;

Snow::Input::Input()
{
}

Snow::Input::~Input()
{
}

bool Snow::Input::isPressed(const Keys &key)
{
	std::lock_guard<std::mutex> lg(_mut);

	if (_pressedChars.find((int)key) != _pressedChars.end())
		return true;
	else
		return false;
}

void Snow::Input::checkKeys()
{
	while (true)
	{
		int key = getch();

		std::lock_guard<std::mutex> lg(_mut);
		_pressedChars[key] = 1000000;
	}

}

void Snow::Input::holdKeys()
{
	while (true)
	{
		std::lock_guard<std::mutex> lg(_mut);
		for (auto &key: _pressedChars)
		{
//			move (1, 1);
//			printw("%lu\n", key.second);
//			refresh();

			if (--key.second == 0)
			{
				_pressedChars.erase(key.first);
			}
		}
	}
}

void Snow::Input::work()
{
	std::thread holdThread(&Snow::Input::holdKeys, this);
	std::thread checkThread(&Snow::Input::checkKeys, this);

	checkThread.join();
	holdThread.join();
}
