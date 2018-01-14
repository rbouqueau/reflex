#include "reflex.hpp"
#include <iostream>

struct Config : public IConfig {};

int main(int argc, char const* argv[]) {
	//Registry: list all existing modules
	registryListAll();

	Config config;
	auto object1 = createObject("Object1", config);
	auto object2 = createObject("Object2", config);

#if 0
	//Serialize;
	std::stringstream str;
	serialize(injector, str);
	std::cout << str.str() << std::endl;
#endif

	return 0;
}
