#ifndef SNOW_CONTROLLER_H
#define SNOW_CONTROLLER_H

#include <map>
#include <thread>

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
		std::map<std::string, std::thread> _threads;

	};
}

#endif
