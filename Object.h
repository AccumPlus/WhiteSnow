#ifndef SNOW_OBJECT_H
#define SNOW_OBJECT_H

#include <string>
#include <mutex>

#include "Position.h"
#include "Sprite.h"
#include "SpriteObject.h"

namespace Snow
{
	class ObjectArray;

	class Object: public Snow::SpriteObject
	{
	public:
		Object();
		virtual ~Object();

		void setParent(Snow::ObjectArray *parent);

		Snow::SpriteObject getSpriteObject();

		// Основная функция логики работы объекта
		virtual void work() = 0;
		
	protected:
		mutable std::mutex _mut;
		ObjectArray *_parent;
	};
}

#endif
