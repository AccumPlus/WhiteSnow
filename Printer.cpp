#include <vector>
#include <algorithm>

#include "Printer.h"
#include "Camera.h"
#include "Object.h"
#include "SpriteSegment.h"

Snow::Printer::Printer(Snow::Camera *camera, const Snow::ObjectArray& objectArray)
{
	_camera = camera;
	_objectArray = objectArray;
}

Snow::Printer::~Printer()
{
}

void Snow::Printer::work()
{
	// Получаем вектор объектов, отсортированный по слоям от нижнего к верхнему
	std::vector<Object*> tObjects = _objectArray.getArray();
	std::sort(tObjects.begin(), tObjects.end(), compareLayers);

	// Результирующий спрайт-сегмент
	Snow::SpriteSegment resultSpriteSegment;

	// Точки камеры
	Snow::Position camUpLeft = _camera->getPosition();
	Snow::Position camDownRight;
	camDownRight.setX(camUpLeft.getX() + _camera->getWidth());
	camDownRight.setY(camUpLeft.getY() + _camera->getHeight());

	// Получаем результирующий спрайт-сегмент в абсолютных позициях
	for (Object* object: tObjects)
	{
		object->lockFullMutex();
		SpriteSegment tSegment = object->getSpriteSegment(camUpLeft, camDownRight);
		object->unlockFullMutex();
		resultSpriteSegment.addAbove(tSegment);
	}

	// Так как все спрайты были предварительно обрезаны под камеру, можно просто выводить на экран результирующий как есть
	long row = 0;
	for (auto tStr: resultSpriteSegment.getSprite()._field)
		printString(tStr, row++, 0, true);
}

bool Snow::compareLayers(Snow::Object* first, Snow::Object *second)
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
	// Отрезаем хваост строки, если длинее ширины камеры
	if (col + (signed long)str.length() > _camera->getWidth())
		str = str.substr(0, str.length() - (col + str.length() - _camera->getWidth()));

	// Добавляем слева и справа пробелы, если надо чистить всю строку
	if (clear)
	{
		if (col != 0)
			str = std::string(col, ' ') + str;
		if (col + (signed long)str.length() < _camera->getWidth())
			str += std::string(_camera->getWidth() - (col + str.length()), ' ');
	}

	move(row, col);
	printw(str.c_str());
	refresh();
}
