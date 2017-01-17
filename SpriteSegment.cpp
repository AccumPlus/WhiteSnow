#include <string>
#include <iostream>

#include "SpriteSegment.h"

Snow::SpriteSegment::SpriteSegment()
{
	std::cout << "SpriteSegment constructor" << "\n\r";
}

Snow::SpriteSegment::~SpriteSegment()
{
}

void Snow::SpriteSegment::setPosition(const long &x, const long &y)
{
	_position.setX(x);
	_position.setY(y);
}

void Snow::SpriteSegment::setSprite(const Snow::Sprite &sprite)
{
	_sprite = sprite;
}

Snow::Position Snow::SpriteSegment::getPosition() const
{
	return _position;
}

void Snow::SpriteSegment::addAbove(const SpriteSegment &spriteSegment)
{
	// Получаем новые точки
	Snow::Position newUpLeft;
	Snow::Position newDownRight;

	newUpLeft.setX(_position.getX() < spriteSegment.getPosition().getX() ? _position.getX() : spriteSegment.getPosition().getX());
	newUpLeft.setY(_position.getY() < spriteSegment.getPosition().getY() ? _position.getY() : spriteSegment.getPosition().getY());

	{
		Snow::Position t1, t2;
		t1.setX(_position.getX() + _sprite.getWidth());
		t1.setY(_position.getY() + _sprite.getHeight());
		t2.setX(spriteSegment.getPosition().getX() + spriteSegment.getSprite().getWidth());
		t2.setY(spriteSegment.getPosition().getY() + spriteSegment.getSprite().getHeight());

		newDownRight.setX(t1.getX() > t2.getX() ? t1.getX() : t2.getX());
		newDownRight.setY(t1.getY() > t2.getY() ? t1.getY() : t2.getY());
	}

	long newWidth = newDownRight.getX() - newUpLeft.getX();
	long newHeight = newDownRight.getY() - newUpLeft.getY();

	// Добавляем к спрайту текущего сегмента недостающие строки/столбцы
	// Слева
	if (newUpLeft.getX() < _position.getX())
		for (std::string tStr: _sprite._field)
			tStr.insert(tStr.begin(), _position.getX() - newUpLeft.getX(), ' ');
	// Справа
	if (newDownRight.getX() > _position.getX() + _sprite.getWidth())
		for (std::string tStr: _sprite._field)
			tStr.insert(tStr.end(), newDownRight.getX() - (_position.getX() + _sprite.getWidth()), ' ');
	// Сверху
	for (long i = 0; i < newUpLeft.getY() - _position.getY(); ++i)
		_sprite._field.insert(_sprite._field.begin(), std::string(newWidth, ' '));
	// Снизу
	for (long i = 0; i < newDownRight.getY() - (_position.getY() + _sprite.getHeight()); ++i)
		_sprite._field.insert(_sprite._field.end(), std::string(newWidth, ' '));

	_sprite._width = newWidth;
	_sprite._height = newHeight;

	// Накладываем новый спрайт на него
	for (unsigned long i = 0; i < _sprite._field.size(); ++i)
		for (unsigned long j = 0; j < _sprite._field[i].length(); ++j)
			_sprite._field[i + spriteSegment._position.getY()][j + spriteSegment._position.getX()] = spriteSegment._sprite._field[i][j];
}

Snow::Sprite Snow::SpriteSegment::getSprite() const
{
	return _sprite;
}
