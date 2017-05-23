#ifndef MY_OBJECT2_H
#define MY_OBJECT2_H

#include "../Object.h"

class MyObject2: public Snow::Object
{
public:
	MyObject2();
	~MyObject2();

	void work() override;
private:
};

#endif
