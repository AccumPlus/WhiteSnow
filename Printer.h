#ifndef SNOW_PRINTER_H
#define SNOW_PRINTER_H

#include <ncurses.h>

#include "ObjectArray.h"

namespace Snow
{
	class Camera;

	class Printer
	{
	public:
		Printer(Snow::Camera *camera, const Snow::ObjectArray& objectArray);
		~Printer();

		void work();
	private:
		Camera *_camera;
		ObjectArray _objectArray;

		// clear - очистить строку, в которую производится вывод
		void printString(std::string str, const long &row, const long &col, const bool &clear = false);

	};

	bool compareLayers(Object* first, Object *second);
}

#endif
