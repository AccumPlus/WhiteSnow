#ifndef SNOW_SPRITE_OBJECT_H
#define SNOW_SPRITE_OBJECT_H

#include <mutex>

#include "Position.h"
#include "Sprite.h"

namespace Snow
{
	class SpriteObject
	{
	public:
		SpriteObject();
		SpriteObject(const SpriteObject &rhs);
		~SpriteObject();

		SpriteObject& operator = (const SpriteObject&);

		void setSprite(const std::string &filename);
		void setLayerNumber(const long &layerNumber);
		void setPosition(const long &x, const long &y);

		Snow::Position getPosition() const;
		Snow::Sprite getSprite() const;
		long getLayerNumber() const;

		Snow::SpriteObject getCut(const Snow::Position &pointUpLeft, const Snow::Position &pointDownRight) const;
		void addAbove(const SpriteObject &spriteObject);

	protected:
		Snow::Position _position;
		Snow::Sprite _sprite;
		long _layerNumber;
		mutable std::mutex _mut;

	};
}

#endif

