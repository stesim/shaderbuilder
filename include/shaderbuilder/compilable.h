#pragma once

#include "common.h"
#include "strstream.h"

namespace shaderbuilder
{

class Compilable
{
public:
	virtual void compile( strstream& stream ) const = 0;
};

inline strstream& operator<<( strstream& str, const Compilable& comp )
{
	comp.compile( str );
	return str;
}

}
