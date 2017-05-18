#include <iostream>

#include "Camera.h"

Snow::Camera::Camera()
{
}

Snow::Camera::~Camera()
{
}

void Snow::Camera::setWidth(const long &width)
{
	_width = width;
}

void Snow::Camera::setHeight(const long &height)
{
	_height = height;
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
