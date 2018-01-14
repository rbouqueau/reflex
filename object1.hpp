#pragma once

#include "object.hpp"
#include "reflex.hpp"

struct Object1 : IObject {
	BOOST_DI_INJECT(Object1, int a);

private:
	int a;
};
