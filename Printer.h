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
		Printer(const Snow::ObjectArray &objectArray);
		~Printer();

		void work();
	private:
		std::shared_ptr<Camera> _camera;
		const ObjectArray &_objectArray;

		// clear - очистить строку, в которую производится вывод
		void printString(std::string str, const long &row, const long &col, const bool &clear = false);

	};

	bool compareLayers(std::shared_ptr<Snow::Object> first, std::shared_ptr<Snow::Object> second);
}

#endif
