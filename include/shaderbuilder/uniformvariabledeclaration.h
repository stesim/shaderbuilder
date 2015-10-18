#pragma once

#include "compilable.h"
#include "variabledeclaration.h"

namespace shaderbuilder
{

class UniformVariableDeclaration : public Compilable
{
public:
	inline static ptr<UniformVariableDeclaration> New(
		ptr<VariableDeclaration> var )
	{
		return make_ptr<UniformVariableDeclaration>( var );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << "uniform " << *m_Variable;
	}

public://private:
	UniformVariableDeclaration( ptr<VariableDeclaration> var ) :
		m_Variable( var ) { }

private:
	ptr<VariableDeclaration> m_Variable;
};

}
