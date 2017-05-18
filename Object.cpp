#include <iostream>

#include "Object.h"

Snow::Object::Object():
	_layerNumber(0)
{
	std::cout << "Object constructor" << std::endl;
}

Snow::Object::~Object()
{
}

void Snow::Object::setPosition(const long &x, const long &y)
{
	std::cout << "Object set position" << std::endl;
	_position.setX(x);
	_position.setY(y);
}

void Snow::Object::setSprite(const std::string &filename)
{
	std::cout << "Object set sprite" << std::endl;
	_sprite.setFilename(filename);
}

void Snow::Object::setLayerNumber(const long &layerNumber)
{
	std::cout << "Object set layer" << "\n\r";
	_layerNumber = layerNumber;
}

void Snow::Object::setParent(Snow::ObjectArray *parent)
{
	this->_parent = parent;
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
	std::cout << "Object get sprite segment" << "\n\r";

	Snow::SpriteSegment tSpriteSegment;

	Snow::Position objUpLeft, objDownRight;
	objUpLeft.setX(_position.getX());
	objUpLeft.setY(_position.getY());
	objDownRight.setX(_position.getX() + _sprite.getWidth() - 1);
	objDownRight.setY(_position.getY() + _sprite.getHeight() - 1);

	std::cout << "step 1" << "\n\r";

	if ( (objUpLeft.getX() < pointUpLeft.getX() && objDownRight.getX() < pointUpLeft.getX()) || 
			(objUpLeft.getX() > pointDownRight.getX() && objDownRight.getX() > pointDownRight.getX()) || 
			(objUpLeft.getY() < pointUpLeft.getY() && objDownRight.getY() < pointUpLeft.getY()) ||
		   	(objUpLeft.getY() > pointDownRight.getY() && objDownRight.getY() > pointDownRight.getY()))
		return tSpriteSegment;

	std::cout << "step 2" << "\n\r";

	Snow::Position newObjUpLeft, newObjDownRight;
	newObjUpLeft.setX(pointUpLeft.getX() < objUpLeft.getX() ? objUpLeft.getX() : pointUpLeft.getX());
	newObjUpLeft.setY(pointUpLeft.getY() < objUpLeft.getY() ? objUpLeft.getY() : pointUpLeft.getY());

	std::cout << "step 3" << "\n\r";
	newObjDownRight.setX(pointDownRight.getX() > objDownRight.getX() ? objDownRight.getX() : pointDownRight.getX());
	newObjDownRight.setY(pointDownRight.getY() > objDownRight.getY() ? objDownRight.getY() : pointDownRight.getY());

	std::cout << "step 4" << "\n\r";
	std::cout << "New object coords:" << "\n\r";
	std::cout << "UL: " << newObjUpLeft.getX() << ' ' << newObjUpLeft.getY() << "\n\r";
	std::cout << "DR: " << newObjDownRight.getX() << ' ' << newObjDownRight.getY() << "\n\r";

	std::cout << "Old sprite coords:" << "\n\r";
	std::cout << "W,H: " << _sprite.getWidth() << ' ' << _sprite.getHeight() << "\n\r";
	tSpriteSegment.setSprite(_sprite.getCut(newObjUpLeft.getX(), newObjUpLeft.getY(), newObjDownRight.getX(), newObjDownRight.getY()));
	tSpriteSegment.setPosition(newObjUpLeft.getX(), newObjUpLeft.getY());

	std::cout << "New W,H: " << tSpriteSegment.getSprite().getWidth() << ' ' << tSpriteSegment.getSprite().getHeight() << "\n\r";

	std::cout << "step 5" << "\n\r";
	return tSpriteSegment;
}

void Snow::Object::lockFullMutex()
{
	_fullMutex.lock();
}

void Snow::Object::unlockFullMutex()
{
	_fullMutex.unlock();
}

void Snow::Object::work()
{
}
