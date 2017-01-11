#ifndef SNOW_POSITION_H
#define SNOW_POSITION_H

namespace Snow
{
	class Position
	{
	public:
		Position();
		Position(const long &x, const long &y);
		~Position();

		void setX(const long &x);
		void setY(const long &y);

		long getX() const;
		long getY() const;
	private:
		long _x, _y;
	};
}

#endif
