#pragma once

#include "object.hpp"
#include "di/di.hpp"
#include "reflex/serialize.hpp"
#include <memory>
#include <string>

int registerObject(const char *name, std::unique_ptr<IObject>(*func)(IConfig &config));
std::unique_ptr<IObject> createObject(const std::string &name, IConfig &config);
void registryListAll();

#define REGISTER(T) \
	static std::unique_ptr<IObject> g_ctor_##T(IConfig &config) { return di::make_injector<serializable_policy>().create<std::unique_ptr<T>>(); } \
	static auto g_object_##T = registerObject(#T, g_ctor_##T);
