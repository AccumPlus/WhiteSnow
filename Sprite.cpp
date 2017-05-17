#include <fstream>
#include <iostream>

#include "Sprite.h"

Snow::Sprite::Sprite():
	_filename(""), _width(0), _height(0)
{
	std::cout << "Sprite constructor" << "\n\r";
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
	std::cout << "Sprite setfilename" << "\n\r";

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
	_field.pop_back();
	--_height;

	spriteStream.close();

	// Дополнение пробелами
	for (std::string tStr: _field)
		if ((signed long)tStr.length() < _width)
			tStr += std::string(_width - tStr.length(), ' ');
}

void Snow::Sprite::setSprite(std::vector<std::string> field)
{
	_width = 0;
	_height = 0;
	_field.clear();

	for (std::string tStr: field)
	{
		std::cout << tStr << "\n\r";
		_field.push_back(tStr);

		++_height;
		if ((signed long)tStr.length() > _width)
			_width = tStr.length();

		std::cout << "Height = " << _height << "\n\r";
		std::cout << "Width = " << _width << "\n\r";
	}

	// Дополнение пробелами
	for (std::string tStr: _field)
		if ((signed long)tStr.length() < _width)
			tStr += std::string(_width - tStr.length(), ' ');

		std::cout << "!!!Height = " << _height << "\n\r";
		std::cout << "!!!Width = " << _width << "\n\r";
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
	std::cout << "Sprite getCut" << "\n\r";
	std::cout << "Col = " << startCol << ' ' << endCol << "\n\r";
	std::cout << "Row = " << startRow << ' ' << endRow << "\n\r";

	std::cout << "\n\r";

	std::vector<std::string> newField;
	for (long i = startRow; i <= endRow; ++i)
	{
		std::cout << _field.at(i) << "\n\r";
		std::string tStr = _field.at(i).substr(startCol, endCol - startCol);
		std::cout << tStr << "\n\r";
		newField.push_back(tStr);
	}

	std::cout << "Before setting sprite" << "\n\r";

	Snow::Sprite newSprite;
	newSprite.setSprite(newField);

	std::cout << "newSprite W,H = " << newSprite.getWidth() << ' ' << newSprite.getHeight() << "\n\r";


	std::cout << "Sprite getCut end" << "\n\r";

	return newSprite;
}
