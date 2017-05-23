#ifndef SNOW_INPUT_H
#define SNOW_INPUT_H

#include <map>

namespace Snow
{
	enum class Key {
		ArrowUp = 0,	ArrowDown = 1,	ArrowLeft = 2,	ArrowRight = 3,
		KeyW = 4,		KeyS = 5,		KeyA = 6,		KeyD = 7
	};

	class Input
	{
	public:
		Input();
		~Input();

		static bool isPressed(const Key &key);

	private:
		// Нажатые клавиши
		std::map<int, unsigned long> _pressedChars;

	};
}

#endif
