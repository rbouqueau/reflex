#include "registry.hpp"
#include "object1.hpp"
#include "object2.hpp"
#include <cassert>
#include <iostream>

struct RegistryEntry {
	const char *name;
	std::unique_ptr<IObject>(*func)(IConfig &config);
};

#define MAX_OBJECT_TYPES 2048
static RegistryEntry g_registry[MAX_OBJECT_TYPES];
static int g_registrySize;

int registerObject(const char *name, std::unique_ptr<IObject>(*func)(IConfig &config)) {
	assert(g_registrySize < sizeof(g_registry) / sizeof(g_registry[0]));
	g_registry[g_registrySize++] = RegistryEntry{ name, func };
	return 0;
}

void registryListAll() {
	for (int i = 0; i < g_registrySize; ++i) {
		std::cout << "Object #" << i << ": " << g_registry[i].name << std::endl;
	}
}

std::unique_ptr<IObject> createObject(const std::string &name, IConfig &config) {
	for (int i = 0; i < g_registrySize; ++i) {
		if (name == g_registry[i].name) {
			return g_registry[i].func(config);
		}
	}

	return nullptr;
}