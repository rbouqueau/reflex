#include "registry.hpp"
#include <iostream>

int main(int argc, char const* argv[]) {
	//Registry: list all existing modules
	for (auto const &o : getRegistry()) {
		std::cout << o.first << std::endl;
	}

	//Serialize;
	//createObject("Object1", );

	//StaticSerialize;

	return 0;
}
