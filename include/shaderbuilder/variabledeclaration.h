#pragma once

#include "statement.h"
#include "types.h"
#include "expression.h"

namespace shaderbuilder
{

class VariableDeclaration : public Statement
{
public:
	inline static ptr<VariableDeclaration> New( Type type, string name )
	{
		return make_ptr<VariableDeclaration>( type, name );
	}

	inline static ptr<VariableDeclaration> New(
		Type type,
		string name,
		ptr<Expression> defaultValue )
	{
		return make_ptr<VariableDeclaration>( type, name, defaultValue );
	}

	virtual void compile( strstream& stream ) const override
	{
		if( m_bIsConst )
		{
			stream << "const ";
		}
		stream << type_name( m_Type ) << " " << m_Name;
		if( m_DefaultValue != nullptr )
		{
			stream << " = ";
			m_DefaultValue->compile( stream );
		}
		stream << ";";
	}

public://private:
	VariableDeclaration( Type type, string name ) :
		m_Type( type ), m_Name( name ), m_DefaultValue() { }

	VariableDeclaration( Type type, string name, ptr<Expression> defaultValue ) :
		m_Type( type ), m_Name( name ), m_DefaultValue( defaultValue ) { }

private:
	Type            m_Type;
	bool            m_bIsConst;
	string          m_Name;
	ptr<Expression> m_DefaultValue;
};

}
