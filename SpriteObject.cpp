#include "SpriteObject.h"

Snow::SpriteObject::SpriteObject()
{
}

Snow::SpriteObject::SpriteObject(const SpriteObject &rhs):
	_position(rhs._position), _sprite(rhs._sprite), _layerNumber(rhs._layerNumber)
{
}

Snow::SpriteObject::~SpriteObject()
{
}

Snow::SpriteObject& Snow::SpriteObject::operator = (const SpriteObject &rhs)
{
	_position = rhs._position;
	_sprite = rhs._sprite;
	_layerNumber = rhs._layerNumber;

	return *this;
}

void Snow::SpriteObject::setSprite(const std::string &filename)
{
	std::lock_guard<std::mutex> lg(_mut);
	_sprite.setFilename(filename);
}

void Snow::SpriteObject::setLayerNumber(const long &layerNumber)
{
	std::lock_guard<std::mutex> lg(_mut);
	_layerNumber = layerNumber;
}

void Snow::SpriteObject::setPosition(const long &x, const long &y)
{
	std::lock_guard<std::mutex> lg(_mut);
	_position.setX(x);
	_position.setY(y);
}


Snow::Position Snow::SpriteObject::getPosition() const
{
	std::lock_guard<std::mutex> lg(_mut);
	return _position;
}

Snow::Sprite Snow::SpriteObject::getSprite() const
{
	std::lock_guard<std::mutex> lg(_mut);
	return _sprite;
}

long Snow::SpriteObject::getLayerNumber() const
{
	std::lock_guard<std::mutex> lg(_mut);
	return _layerNumber;
}

Snow::SpriteObject Snow::SpriteObject::getCut(const Snow::Position &pointUpLeft, const Snow::Position &pointDownRight) const
{
	std::lock_guard<std::mutex> lg(_mut);

	Snow::SpriteObject tSpriteObject;

	Snow::Position objUpLeft, objDownRight;
	objUpLeft.setX(_position.getX());
	objUpLeft.setY(_position.getY());
	objDownRight.setX(_position.getX() + _sprite.getWidth() - 1);
	objDownRight.setY(_position.getY() + _sprite.getHeight() - 1);

	// Условия непопадания в желаемый прямоугольник
	if ( (objUpLeft.getX() < pointUpLeft.getX() && objDownRight.getX() < pointUpLeft.getX()) || 
			(objUpLeft.getX() > pointDownRight.getX() && objDownRight.getX() > pointDownRight.getX()) || 
			(objUpLeft.getY() < pointUpLeft.getY() && objDownRight.getY() < pointUpLeft.getY()) ||
		   	(objUpLeft.getY() > pointDownRight.getY() && objDownRight.getY() > pointDownRight.getY()))
		return tSpriteObject;

	Snow::Position newObjUpLeft, newObjDownRight;
	newObjUpLeft.setX(pointUpLeft.getX() < objUpLeft.getX() ? objUpLeft.getX() : pointUpLeft.getX());
	newObjUpLeft.setY(pointUpLeft.getY() < objUpLeft.getY() ? objUpLeft.getY() : pointUpLeft.getY());

	newObjDownRight.setX(pointDownRight.getX() > objDownRight.getX() ? objDownRight.getX() : pointDownRight.getX());
	newObjDownRight.setY(pointDownRight.getY() > objDownRight.getY() ? objDownRight.getY() : pointDownRight.getY());

	tSpriteObject._sprite = _sprite.getCut(newObjUpLeft.getX() - objUpLeft.getX(), newObjUpLeft.getY() - objUpLeft.getY(), newObjDownRight.getX() - objUpLeft.getX(), newObjDownRight.getY() - objUpLeft.getY());

	tSpriteObject.setPosition(newObjUpLeft.getX(), newObjUpLeft.getY());

	return tSpriteObject;
}

void Snow::SpriteObject::addAbove(const SpriteObject &spriteObject)
{
	std::lock_guard<std::mutex> lg(_mut);

	// Получаем новые точки
	Snow::Position newUpLeft;
	Snow::Position newDownRight;

	newUpLeft.setX(_position.getX() < spriteObject.getPosition().getX() ? _position.getX() : spriteObject.getPosition().getX());
	newUpLeft.setY(_position.getY() < spriteObject.getPosition().getY() ? _position.getY() : spriteObject.getPosition().getY());

	{
		Snow::Position t1, t2;
		t1.setX(_position.getX() + _sprite.getWidth() - 1);
		t1.setY(_position.getY() + _sprite.getHeight() - 1);
		t2.setX(spriteObject.getPosition().getX() + spriteObject.getSprite().getWidth() - 1);
		t2.setY(spriteObject.getPosition().getY() + spriteObject.getSprite().getHeight() - 1);
		
		newDownRight.setX(t1.getX() > t2.getX() ? t1.getX() : t2.getX());
		newDownRight.setY(t1.getY() > t2.getY() ? t1.getY() : t2.getY());
	}

	long newWidth = newDownRight.getX() - newUpLeft.getX() + 1;
	long newHeight = newDownRight.getY() - newUpLeft.getY() + 1;

//	std::cout << "newUL: " << newUpLeft.getX() << ' ' << newUpLeft.getY() << "\n\r";
//	std::cout << "newDR: " << newDownRight.getX() << ' ' << newDownRight.getY() << "\n\r";
//
//	std::cout << "newWidth = " << newWidth << "\n\r";
//	std::cout << "newHeight = " << newHeight << "\n\r";

	// Добавляем к спрайту текущего сегмента недостающие строки/столбцы
	// Слева
	if (newUpLeft.getX() < _position.getX())
	{
//		std::cout << "Inserting left..." << "\n\r";
		for (std::string &tStr: _sprite._field)
		{
			tStr.insert(tStr.begin(), _position.getX() - newUpLeft.getX(), ' ');
		}
	}

	// Справа
	if (newDownRight.getX() > _position.getX() + _sprite.getWidth() - 1)
	{
//		std::cout << "Inserting right..." << "\n\r";
		for (std::string &tStr: _sprite._field)
		{
			tStr.insert(tStr.end(), newDownRight.getX() - (_position.getX() + _sprite.getWidth() - 1), ' ');
		}
	}

	// Сверху
	for (long i = 0; i < _position.getY() - newUpLeft.getY(); ++i)
	{
//		std::cout << "Inserting up... " << i << "\n\r";
		_sprite._field.insert(_sprite._field.begin(), std::string(newWidth, ' '));
	}

	// Снизу
	for (long i = 0; i < newDownRight.getY() - (_position.getY() + _sprite.getHeight() - 1); ++i)
	{
//		std::cout << "Inserting down... " << i << "\n\r";
		_sprite._field.insert(_sprite._field.end(), std::string(newWidth, ' '));
	}

	_sprite._width = newWidth;
	_sprite._height = newHeight;

	// Накладываем новый спрайт на него
	for (unsigned long i = 0; i < spriteObject._sprite._field.size(); ++i)
	{
		for (unsigned long j = 0; j < spriteObject._sprite._field[i].length(); ++j)
		{
			_sprite._field[i + spriteObject._position.getY()][j + spriteObject._position.getX()] = spriteObject._sprite._field[i][j];
		}
	}
}
