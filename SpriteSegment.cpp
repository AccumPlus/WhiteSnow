#include "SpriteSegment.h"

Snow::SpriteSegment::SpriteSegment()
{
}

Snow::SpriteSegment::~SpriteSegment()
{
}

void Snow::SpriteSegment::setPosition(const long &x, const long &y)
{
	_position.setX(x);
	_position.setY(y);
}

void Snow::SpriteSegment::setSprite(const Snow::Sprite &sprite)
{
	_sprite = sprite;
}

Snow::Position Snow::SpriteSegment::getPosition() const
{
	return _position;
}

void Snow::SpriteSegment::addAbove(const SpriteSegment &spriteSegment)
{
	Snow::Position tPosition;

	tPosition.setX(_position.getX() < spriteSegment.getPosition().getX() ? _position.getX() : spriteSegment.getPosition().getX());
	tPosition.setY(_position.getY() < spriteSegment.getPosition().getY() ? _position.getY() : spriteSegment.getPosition().getY());

	
}

Snow::Sprite Snow::SpriteSegment::getSprite() const
{
	return _sprite;
}
