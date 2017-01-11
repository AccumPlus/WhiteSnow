#include "Position.h"

Snow::Position::Position():
	_x(0), _y(0)
{
}

Snow::Position::Position(const long &x, const long &y):
	_x(x), _y(y)
{
}

Snow::Position::~Position()
{
}

void Snow::Position::setX(const long &x)
{
	_x = x;
}

void Snow::Position::setY(const long &y)
{
	_y = y;
}

long Snow::Position::getX() const
{
	return _x;
}

long Snow::Position::getY() const
{
	return _y;
}
