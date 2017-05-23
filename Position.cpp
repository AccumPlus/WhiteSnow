#include "Position.h"

Snow::Position::Position():
	_x(0), _y(0)
{
}

Snow::Position::Position(const Position &rhs):
	_x(rhs.getX()), _y(rhs.getY())
{
}

Snow::Position::Position(const long &x, const long &y):
	_x(x), _y(y)
{
}

Snow::Position::~Position()
{
}

Snow::Position& Snow::Position::operator = (const Position &rhs)
{
	_x = rhs._x;
	_y = rhs._y;
	return *this;
}

void Snow::Position::setX(const long &x)
{
	std::lock_guard<std::mutex> lg(_mut);
	_x = x;
}

void Snow::Position::setY(const long &y)
{
	std::lock_guard<std::mutex> lg(_mut);
	_y = y;
}

long Snow::Position::getX() const
{
	std::lock_guard<std::mutex> lg(_mut);
	return _x;
}

long Snow::Position::getY() const
{
	std::lock_guard<std::mutex> lg(_mut);
	return _y;
}
