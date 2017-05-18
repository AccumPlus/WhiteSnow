#include <vector>
#include <algorithm>
#include <iostream>

#include "Printer.h"
#include "Camera.h"
#include "Object.h"
#include "SpriteSegment.h"

Snow::Printer::Printer(const Snow::Camera &camera, const Snow::ObjectArray& objectArray):
	_camera{camera}, _objectArray{objectArray}
{
	std::cout << "Printer constructor" << "\n\r";
}

Snow::Printer::~Printer()
{
}

void Snow::Printer::work()
{
	std::cout << "Printer work" << "\n\r";

	// Получаем вектор объектов, отсортированный по слоям от нижнего к верхнему
	auto tObjects = _objectArray.getArray();
	std::sort(tObjects.begin(), tObjects.end(), compareLayers);

	std::cout << "SpriteSegment" << "\n\r";
	// Результирующий спрайт-сегмент
	Snow::SpriteSegment resultSpriteSegment;

	// Точки камеры
	Snow::Position camUpLeft = _camera.getPosition();
	Snow::Position camDownRight;
	camDownRight.setX(camUpLeft.getX() + _camera.getWidth() - 1);
	camDownRight.setY(camUpLeft.getY() + _camera.getHeight() - 1);

	std::cout << "Camera points:" << "\n\r";
	std::cout << "UL = " << camUpLeft.getX() << ' ' << camUpLeft.getY() << "\n\r";
	std::cout << "DR = " << camDownRight.getX() << ' ' << camDownRight.getY() << "\n\r";

	std::cout << "Complex part" << "\n\r";

	// Получаем результирующий спрайт-сегмент в абсолютных позициях
	for (auto object: tObjects)
	{
		object->lockFullMutex();
		SpriteSegment tSegment = object->getSpriteSegment(camUpLeft, camDownRight);
		std::cout << "SpriteSegment points:" << "\n\r";
		std::cout << "X = " << tSegment.getPosition().getX() << "\n\r";
		std::cout << "Y = " << tSegment.getPosition().getY() << "\n\r";
		std::cout << "W = " << tSegment.getSprite().getWidth() << "\n\r";
		std::cout << "H = " << tSegment.getSprite().getHeight() << "\n\r";
		object->unlockFullMutex();
		resultSpriteSegment.addAbove(tSegment);
	}

	// Так как все спрайты были предварительно обрезаны под камеру, можно просто выводить на экран результирующий как есть
	long row = 0;
	for (auto tStr: resultSpriteSegment.getSprite()._field)
	{
	//	std::cout << "Printing string" << "\n\r";
		printString(tStr, row++, 0, true);
	}
}

bool Snow::compareLayers(std::shared_ptr<Snow::Object> first, std::shared_ptr<Snow::Object> second)
{
	bool res;
	first->lockFullMutex();
	second->lockFullMutex();
	res = first->getLayerNumber() > second->getLayerNumber();
	first->unlockFullMutex();
	second->unlockFullMutex();
	return res;
}

void Snow::Printer::printString(std::string str, const long &row, const long &col, const bool &clear)
{
//	move(1, 0);
//	printw("0000000");
//	refresh();
//	getch();
//	return;

	// Отрезаем хвост строки, если длинее ширины камеры
	if (col + (signed long)str.length() > _camera.getWidth())
		str = str.substr(0, str.length() - (col + str.length() - _camera.getWidth()));

	// Добавляем слева и справа пробелы, если надо чистить всю строку
	if (clear)
	{
		if (col != 0)
			str = std::string(col, ' ') + str;
		if (col + (signed long)str.length() < _camera.getWidth())
			str += std::string(_camera.getWidth() - (col + str.length()), ' ');
	}

	move(row, col);
	printw(str.c_str());
	refresh();
}
