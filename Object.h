#ifndef SNOW_OBJECT_H
#define SNOW_OBJECT_H

#include <string>
#include <mutex>

#include "Position.h"
#include "Sprite.h"
#include "SpriteSegment.h"

namespace Snow
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		void setPosition(const long &x, const long &y);
		void setSprite(const std::string &filename);
		void setLayerNumber(const long &layerNumber);

		Snow::Position getPosition() const;
		Snow::Sprite getSprite() const;
		long getLayerNumber() const;

		Snow::SpriteSegment getSpriteSegment(const Snow::Position &pointUpLeft, const Snow::Position &pointDownRight) const;
		void lockFullMutex();
		void unlockFullMutex();
		
	protected:
		Snow::Position _position;
		Snow::Sprite _sprite;
		long _layerNumber;
		std::mutex _fullMutex;

	};
}

#endif
