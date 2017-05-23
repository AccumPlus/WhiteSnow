#ifndef SNOW_POSITION_H
#define SNOW_POSITION_H

#include <mutex>

namespace Snow
{
	class Position
	{
	public:
		Position();
		Position(const Position&);
		Position(const long &x, const long &y);
		~Position();

		Position& operator = (const Position &rhs);

		void setX(const long &x);
		void setY(const long &y);

		long getX() const;
		long getY() const;
	private:
		long _x, _y;
		mutable std::mutex _mut;
	};
}

#endif
