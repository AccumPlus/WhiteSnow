#ifndef SNOW_CONTROLLER_H
#define SNOW_CONTROLLER_H

namespace Snow
{
	/*
	 * Класс Controller предназначен для обработки логики взаимодействия объектов сцены
	 * Его метод work просто запускает потоки работы всех объектов
	 * */

	class Camera;
	class ObjectArray;

	class Controller
	{
	public:
		Controller(Snow::ObjectArray &objectArray);
		~Controller();

		void work();
	private:
		ObjectArray &_objectArray;

	};
}

#endif
