#include "registry.hpp"
#include "object1.hpp"
#include "object2.hpp"
#include <stdexcept>

static std::map<const std::string, CreationFunc> g_registry;

std::unique_ptr<IObject> createObject(const std::string &name, IConfig &config) {
	auto i_func = g_registry.find(name);
	if (i_func == g_registry.end())
		throw std::runtime_error("unknown object type: '" + name + "'");

	return (*i_func).second(config);
}

void registerFormat(const std::string &format, CreationFunc func) {
	g_registry[format] = func;
}

const std::map<const std::string, CreationFunc> getRegistry() {
	return g_registry;
}
