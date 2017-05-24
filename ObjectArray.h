#ifndef SNOW_OBJECT_ARRAY
#define SNOW_OBJECT_ARRAY

#include <list>
#include <string>
#include <vector>
#include <memory>
#include <mutex>

namespace Snow
{
	class Object;
	class SpriteObject;

	class ObjectArray
	{
	public:
		ObjectArray();
		~ObjectArray();

//		void addObject(const std::string &name, const std::shared_ptr<Snow::Object> &object);
		void addObject(const std::shared_ptr<Snow::Object> &object);
		void removeObject(const std::string &name);
//		void changeName(const std::string &from, const std::string &to);

		std::shared_ptr<Snow::Object> getObject(const std::string &name) const;
		std::vector<Snow::SpriteObject> getSnapshot() const;
		std::vector<std::shared_ptr<Snow::Object> > getArray() const;
	private:
//		std::map<std::string, std::shared_ptr<Snow::Object> > _objects;
		std::list<std::shared_ptr<Snow::Object> > _objects;
		mutable std::mutex _mut;
	};
}

#endif
