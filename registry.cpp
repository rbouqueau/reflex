#include "registry.hpp"
#include "object1.hpp"
#include "object2.hpp"
#include <cassert>
#include <iostream>

#define MAX_ENTITY_TYPES 2048
static EntityType g_registry[MAX_ENTITY_TYPES];
static int g_registrySize;

int registerObject(const char *format, std::unique_ptr<IObject>(*func)(IConfig &config)) {
	assert(g_registrySize < sizeof(g_registry) / sizeof(g_registry[0]));
	g_registry[g_registrySize++] = EntityType{ format, func };
	return g_registrySize;
}

void registryListAll() {
	for (int i = 0; i < g_registrySize; ++i) {
		std::cout << "Object #" << i << ": " << g_registry[i].name << std::endl;
	}
}
