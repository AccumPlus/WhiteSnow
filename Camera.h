#ifndef SNOW_CAMERA_H
#define SNOW_CAMERA_H

#include <mutex>

#include "Position.h"
#include "Object.h"

namespace Snow
{
	class Camera: public Object
	{
	public:
		Camera();
		virtual ~Camera();

		void setWidth(const long &width);
		void setHeight(const long &height);

		long getWidth() const;
		long getHeight() const;

		virtual void work() override;
	protected:
		long _width, _height;
		mutable std::mutex _mut;

	};
}

#endif
