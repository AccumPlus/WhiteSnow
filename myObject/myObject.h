#ifndef MY_OBJECT_H
#define MY_OBJECT_H

#include "../Object.h"

class MyObject: public Snow::Object
{
public:
	MyObject();
	~MyObject();

	void work() override;
private:
};

#endif
