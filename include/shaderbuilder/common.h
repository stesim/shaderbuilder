#pragma once

#include <string>
#include <memory>

namespace shaderbuilder
{

using std::string;
using std::size_t;

template<typename T>
using ptr = std::shared_ptr<T>;

template<typename T, typename... U>
inline ptr<T> make_ptr( U... params )
{
	return std::make_shared<T>( std::forward<U>( params )... );
}

}
