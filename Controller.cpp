#include <iostream>

#include "ObjectArray.h"
#include "Camera.h"
#include "Controller.h"
#include "Event.h"

Snow::Controller::Controller(Snow::ObjectArray &objectArray):
	_objectArray(objectArray)
{
}

Snow::Controller::~Controller()
{
}

void Snow::Controller::work()
{
	while (true)
	{
		_objectArray.waitForEvents();

		auto eventList = _objectArray.getEventList();

		for (auto &event: eventList)
		{
			switch (event.getType())
			{
			case Snow::EventType::StopObject:
				if (_threads.find(event.getName()) != _threads.end())
				{
					// Завершаем поток
					_threads[event.getName()].join();

					// Удаляем объект потока
					_threads.erase(event.getName());
				}

				if (_objectArray.getObject(event.getName()) != nullptr)
				{
					// Удалить объект из списка
					_objectArray.removeFromArray(event.getName());
				}

				break;

			case Snow::EventType::StartObject:
				auto object = _objectArray.getObject(event.getName());
				if (object != nullptr)
				{
//					std::thread thr = std::thread(&Snow::Object::work, object);
					// Запускаем поток
//					_threads.insert(std::pair<std::string, std::thread>(object->getName(), std::move(thr)));
					_threads.insert(std::pair<std::string, std::thread>(object->getName(), std::thread(&Snow::Object::startJob, object)));
				}

				break;
			}
		}

	}



//	std::vector<std::thread> threads;
//
//	for (auto &object: _objectArray.getArray())
//	{
//		threads.emplace_back(&Snow::Object::work, object);
//	}
//
//	for (auto &thr: threads)
//	{
//		thr.join();
//	}
}
