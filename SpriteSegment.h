#ifndef SNOW_SPRITE_SEGMENT
#define SNOW_SPRITE_SEGMENT

#include "Position.h"
#include "Sprite.h"

namespace Snow
{
	class SpriteSegment
	{
	public:
		SpriteSegment();
		~SpriteSegment();

		void setPosition(const long &x, const long &y);
		void setSprite(const Snow::Sprite &sprite);
		
		Snow::Position getPosition() const;
		Snow::Sprite getSprite() const;

		void addAbove(const SpriteSegment &spriteSegment);

	private:
		Snow::Position _position;
		Snow::Sprite _sprite;
	};
}

#endif
