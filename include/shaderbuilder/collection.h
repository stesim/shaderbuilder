#pragma once

#include "common.h"
#include <list>

namespace shaderbuilder
{

template<typename T>
using Collection = std::list<ptr<T>>;

}
