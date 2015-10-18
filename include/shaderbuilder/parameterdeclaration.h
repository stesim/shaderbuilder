#pragma once

#include "compilable.h"
#include "types.h"

namespace shaderbuilder
{

class ParameterDeclaration : public Compilable
{
public:
	enum class Direction
	{
		in = 0,
		out,
		inout
	};

public:
	inline static ptr<ParameterDeclaration> New(
			Type type, string name, Direction dir )
	{
		return make_ptr<ParameterDeclaration>( dir, type, name );
	}

	inline static ptr<ParameterDeclaration> New(
			Type type, string name )
	{
		return New( type, name, Direction::in );
	}

	virtual void compile( strstream& stream ) const override;

public://private:
	ParameterDeclaration( Direction dir, Type type, string name ) :
		m_Direction( dir ), m_Type( type ), m_Name( name ) { }

private:
	Direction m_Direction;
	Type      m_Type;
	string    m_Name;
};

}
