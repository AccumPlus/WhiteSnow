#ifndef SNOW_OBJECT_ARRAY
#define SNOW_OBJECT_ARRAY

#include <map>
#include <string>
#include <vector>

namespace Snow
{
	class Object;

	class ObjectArray
	{
	public:
		ObjectArray();
		~ObjectArray();

		void addObject(std::string name, Snow::Object *object);
		void removeObject(const std::string &name);
		void changeName(const std::string &from, const std::string &to);

		Snow::Object* getObject(const std::string &name) const;
		std::vector<Object*> getArray() const;
	private:
		std::map<std::string, Snow::Object*> _objects;
	};
}

#endif
