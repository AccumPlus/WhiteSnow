/* Класс Sprite.
 * Представляет из себя класс, обрабатывающий "изображение" объекта.
 * Изображение загружается в класс через простой текстовый файл.
 * Изображение - прямоугольник, состоящий из символов.
 *
 * Пример содержимого файла:
 * +----------+
 * |    |\    |
 * |    | \   |
 * |}===+  ==\|
 * |}===+  ==/|
 * |    | /   |
 * |    |/    |
 * +----------+
 *
 * */

#ifndef SNOW_SPRITE_H
#define SNOW_SPRITE_H

#include <string>
#include <vector>
#include <mutex>

namespace Snow
{
	class Printer;
	class SpriteObject;

	class Sprite
	{
	public:
		// Принтер работает на низком уровне. Даём ему достум к private переменным
		friend Snow::Printer;
		// При склеивании спрайтов Спрайт-сегменту нужен доступ к массиву
		friend Snow::SpriteObject;

		Sprite();
		Sprite(const Sprite&);
		Sprite(const std::string &filename);
		~Sprite();

		Sprite& operator = (const Sprite&);

		void setFilename(const std::string &filename);
		void setSprite(std::vector<std::string> field);

		std::string getFilename() const;
		long getWidth() const;
		long getHeight() const;

		char getSymbol(const long &x, const long &y) const;
		Snow::Sprite getCut(const long &startCol, const long &startRow, const long &endCol, const long &endRow) const;
	private:
		std::string _filename;
		std::vector<std::string> _field;
		long _width;
		long _height;
		mutable std::mutex _mut;
	};
}

#endif
