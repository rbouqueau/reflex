#pragma once

#include "object.hpp"
#include "reflex.hpp"

struct Object1 : IObject {
	Object1(int a);

private:
	int a;
};
