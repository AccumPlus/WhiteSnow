#ifndef SNOW_INPUT_H
#define SNOW_INPUT_H

#include <map>

namespace Snow
{
	enum class Keys {
		ArrowDown = 258,	ArrowUp = 259,	ArrowLeft = 260,	ArrowRight = 261,
		KeyW = 119,			KeyS = 115,		KeyA = 97,			KeyD = 100
	};

	class Input
	{
	public:
		Input();
		~Input();

		static bool isPressed(const Keys &key);

		void work();

	private:
		// Нажатые клавиши
		static std::map<int, unsigned long> _pressedChars;

		void checkKeys();
		void holdKeys();

	};
}

#endif
