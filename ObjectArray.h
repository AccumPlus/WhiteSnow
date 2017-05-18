#ifndef SNOW_OBJECT_ARRAY
#define SNOW_OBJECT_ARRAY

#include <map>
#include <string>
#include <vector>
#include <memory>

namespace Snow
{
	class Object;

	class ObjectArray
	{
	public:
		ObjectArray();
		~ObjectArray();

		void addObject(const std::string &name, const std::shared_ptr<Snow::Object> &object);
		void removeObject(const std::string &name);
		void changeName(const std::string &from, const std::string &to);

		std::shared_ptr<Snow::Object> getObject(const std::string &name) const;
		std::vector<std::shared_ptr<Snow::Object> > getArray() const;
	private:
		std::map<std::string, std::shared_ptr<Snow::Object> > _objects;
	};
}

#endif
