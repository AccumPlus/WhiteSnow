#ifndef SNOW_PRINTER_H
#define SNOW_PRINTER_H

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
	};

	bool compareLayers(Object* first, Object *second);
}

#endif
