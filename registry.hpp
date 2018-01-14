#pragma once

#include "object.hpp"
#include <functional>
#include <map>
#include <memory>
#include <string>

int registerObject(const char *format, std::unique_ptr<IObject>(*func)(IConfig &config));
void registryListAll();

struct EntityType {
	const char *name;
	std::unique_ptr<IObject>(*func)(IConfig &config);
};

#define REGISTER(T) \
	static std::unique_ptr<IObject> g_ctor_##T(IConfig &config) { \
		return std::make_unique<T>(0); \
	} \
	static auto g_registered_##T = registerObject(#T, &g_ctor_##T);
