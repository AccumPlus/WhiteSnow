#ifndef SNOW_CAMERA_H
#define SNOW_CAMERA_H

#include "Position.h"

namespace Snow
{
	class Camera
	{
	public:
		Camera();
		virtual ~Camera();

		void setPosition(const long &x, const long &y);
		void setWidth(const long &width);
		void setHeight(const long &height);

		Snow::Position getPosition() const;
		long getWidth() const;
		long getHeight() const;

		void work();
	protected:
		Snow::Position _position;
		long _width, _height;

	};
}

#endif
