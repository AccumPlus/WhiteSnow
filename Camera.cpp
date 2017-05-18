#include <iostream>

#include "Camera.h"

Snow::Camera::Camera()
{
	std::cout << "Camera constructor" << std::endl;
}

Snow::Camera::~Camera()
{
}

void Snow::Camera::setPosition(const long &x, const long &y)
{
	std::cout << "Camera set position" << std::endl;
	_position.setX(x);
	_position.setY(y);
}

void Snow::Camera::setWidth(const long &width)
{
	std::cout << "Camera set width" << std::endl;
	_width = width;
}

void Snow::Camera::setHeight(const long &height)
{
	std::cout << "Camera set height" << std::endl;
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

void Snow::Camera::work()
{
}
