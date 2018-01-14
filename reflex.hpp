#pragma once 

#include "registry.hpp"
#include "di/di.hpp"

#define REFLEX_CTOR(T, ...) \
	REGISTER(T) \
	BOOST_DI_INJECT(T::T, __VA_ARGS__)
