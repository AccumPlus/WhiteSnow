#include "Object.h"

Snow::Object::Object():
	_layerNumber(0)
{
}

Snow::Object::~Object()
{
}

void Snow::Object::setPosition(const long &x, const long &y)
{
	_position.setX(x);
	_position.setY(y);
}

void Snow::Object::setSprite(const std::string &filename)
{
	_sprite.setFilename(filename);
}

void Snow::Object::setLayerNumber(const long &layerNumber)
{
	_layerNumber = layerNumber;
}

Snow::Position Snow::Object::getPosition() const
{
	return _position;
}

Snow::Sprite Snow::Object::getSprite() const
{
	return _sprite;
}

long Snow::Object::getLayerNumber() const
{
	return _layerNumber;
}

Snow::SpriteSegment Snow::Object::getSpriteSegment(const Snow::Position &pointUpLeft, const Snow::Position &pointDownRight) const
{
	Snow::SpriteSegment tSpriteSegment;

	Snow::Position objUpLeft, objDownRight;
	objUpLeft.setX(_position.getX());
	objUpLeft.setY(_position.getY());
	objDownRight.setX(_position.getX() + _sprite.getWidth());
	objDownRight.setY(_position.getY() + _sprite.getHeight());


	if ( (objUpLeft.getX() < pointUpLeft.getX() && objDownRight.getX() < pointUpLeft.getX()) || 
			(objUpLeft.getX() > pointDownRight.getX() && objDownRight.getX() > pointDownRight.getX()) || 
			(objUpLeft.getY() < pointUpLeft.getY() && objDownRight.getY() < pointUpLeft.getY()) ||
		   	(objUpLeft.getY() > pointDownRight.getY() && objDownRight.getY() > pointDownRight.getY()))
		return tSpriteSegment;

	Snow::Position newObjUpLeft, newObjDownRight;
	newObjUpLeft.setX(pointUpLeft.getX() < objUpLeft.getX() ? objUpLeft.getX() : pointUpLeft.getX());
	newObjUpLeft.setY(pointUpLeft.getY() < objUpLeft.getY() ? objUpLeft.getY() : pointUpLeft.getY());

	newObjDownRight.setX(pointDownRight.getX() > objDownRight.getX() ? objDownRight.getX() : pointDownRight.getX());
	newObjDownRight.setY(pointDownRight.getY() > objDownRight.getY() ? objDownRight.getY() : pointDownRight.getY());

	tSpriteSegment.setSprite(_sprite.getCut(newObjUpLeft.getX(), newObjUpLeft.getY(), newObjDownRight.getX(), newObjDownRight.getY()));
	tSpriteSegment.setPosition(newObjUpLeft.getX(), newObjUpLeft.getY());

	return tSpriteSegment;
}

