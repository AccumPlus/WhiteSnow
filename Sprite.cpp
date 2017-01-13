#include <fstream>

#include "Sprite.h"

Snow::Sprite::Sprite():
	_filename(""), _width(0), _height(0)
{
}

Snow::Sprite::Sprite(const std::string &filename)
{
	this->setFilename(filename);
}

Snow::Sprite::~Sprite()
{
}

void Snow::Sprite::setFilename(const std::string &filename)
{
	_width = 0;
	_height = 0;
	_field.clear();

	std::fstream spriteStream;
	spriteStream.open(filename.c_str(), std::ios_base::in);

	while(!spriteStream.eof())
	{
		std::string tStr;

		getline(spriteStream, tStr);
		_field.push_back(tStr);

		if ((signed long)tStr.length() > _width)
			_width = tStr.length();

		++_height;
	}

	spriteStream.close();

	// Дополнение пробелами
	for (std::string tStr: _field)
		if ((signed long)tStr.length() < _width)
			tStr += std::string(_width - tStr.length(), ' ');
}

void Snow::Sprite::setSprite(std::vector<std::string> field)
{
	long _width = 0;
	long _height = 0;
	_field.clear();

	for (std::string tStr: field)
	{
		_field.push_back(tStr);

		++_height;
		if ((signed long)tStr.length() > _width)
			_width = tStr.length();
	}

	// Дополнение пробелами
	for (std::string tStr: _field)
		if ((signed long)tStr.length() < _width)
			tStr += std::string(_width - tStr.length(), ' ');
}

std::string Snow::Sprite::getFilename() const
{
	return _filename;
}

char Snow::Sprite::getSymbol(const long &x, const long &y) const
{
	return _field.at(y).at(x);
}

long Snow::Sprite::getWidth() const
{
	return _width;
}

long Snow::Sprite::getHeight() const
{
	return _height;
}

Snow::Sprite Snow::Sprite::getCut(const long &startCol, const long &startRow, const long &endCol, const long &endRow) const
{
	std::vector<std::string> newField;
	for (long i = startRow; i <= endRow; ++i)
	{
		std::string tStr = _field.at(i).substr(startCol, endCol - startCol);
		newField.push_back(tStr);
	}

	Snow::Sprite newSprite;
	newSprite.setSprite(newField);

	return newSprite;
}
