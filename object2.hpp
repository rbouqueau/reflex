#pragma once

#include "object.hpp"
#include "reflex.hpp"

struct Object2 : IObject {
	Object2(int a, int b);

private:
	int a, b;
};
