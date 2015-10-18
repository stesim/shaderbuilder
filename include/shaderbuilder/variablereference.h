#pragma once

#include "expression.h"

namespace shaderbuilder
{

class VariableReference : public Expression
{
public:
	inline static ptr<VariableReference> New( string name )
	{
		return make_ptr<VariableReference>( name );
	}

public://private:
	VariableReference( string name )
		: m_Name( name ) { }

	virtual void compile( strstream& stream ) const override
	{
		stream << m_Name;
	}

private:
	string m_Name;
};

}
