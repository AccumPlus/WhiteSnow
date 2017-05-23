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
	std::lock_guard<std::mutex> lg(_mut);
	_width = width;
	if (_height != 0)
	{
		std::vector<std::string> field(_height, std::string(_width, ' '));
		_sprite.setSprite(field);
	}
}

void Snow::Camera::setHeight(const long &height)
{
	std::lock_guard<std::mutex> lg(_mut);
	_height = height;
	if (_width != 0)
	{
		std::vector<std::string> field(_height, std::string(_width, ' '));
		_sprite.setSprite(field);
	}
}

long Snow::Camera::getWidth() const
{
	std::lock_guard<std::mutex> lg(_mut);
	return _width;
}

long Snow::Camera::getHeight() const
{
	std::lock_guard<std::mutex> lg(_mut);
	return _height;
}

void Snow::Camera::work()
{
}
