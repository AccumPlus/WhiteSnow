#include "Camera.h"

Snow::Camera::Camera()
{
}

Snow::Camera::~Camera()
{
}

void Snow::Camera::setPosition(const long &x, const long &y)
{
	_position.setX(x);
	_position.setY(y);
}

void Snow::Camera::setWidth(const long &width)
{
	_width = width;
}

void Snow::Camera::setHeight(const long &height)
{
	_height = height;
}

Snow::Position Snow::Camera::getPosition() const
{
	return _position;
}

long Snow::Camera::getWidth() const
{
	return _width;
}

long Snow::Camera::getHeight() const
{
	return _height;
}
