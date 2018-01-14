#pragma once

#include "object.hpp"
#include <functional>
#include <map>
#include <memory>
#include <string>

typedef std::function<std::unique_ptr<IObject>(IConfig &config)> CreationFunc;

void registerFormat(const std::string &format, CreationFunc func);
const std::map<const std::string, CreationFunc> getRegistry();

template<typename T>
int registerObject(const std::string &name) {
	registerFormat(name, [](IConfig &config) {
		return std::make_unique<T>(0);
	});
	return 0;
};

#define REGISTER(T) \
	static auto g_registered_##T = registerObject<T>(#T);
