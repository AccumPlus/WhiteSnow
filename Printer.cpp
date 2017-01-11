#include <vector>
#include <algorithm>

#include "Printer.h"
#include "Camera.h"
#include "Object.h"

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
	std::vector<Object*> tObjects = _objectArray.getArray();
	std::sort(tObjects.begin(), tObjects.end(), compareLayers);

	// Получаем результирующий спрайт в абсолютных позициях
	for (Object* object: tObjects)
	{
		object->getSpriteSegment
	}
}

bool compareLayers(Snow::Object* first, Snow::Object *second)
{
	return first->getLayerNumber() > second->getLayerNumber();
}
