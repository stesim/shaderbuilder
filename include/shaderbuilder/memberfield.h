#pragma once

#include "compilable.h"
#include "types.h"
#include "expression.h"

namespace shaderbuilder
{

class MemberField : public Compilable
{
public:
	inline static ptr<MemberField> New( Type type, string name )
	{
		return make_ptr<MemberField>( type, name );
	}

	inline static ptr<MemberField> New(
		Type type,
		string name,
		ptr<Expression> defaultValue )
	{
		return make_ptr<MemberField>( type, name, defaultValue );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << type_name( m_Type ) << " " << m_Name;
		if( m_DefaultValue != nullptr )
		{
			stream << " = ";
			m_DefaultValue->compile( stream );
		}
		stream << ";";
	}

public://private:
	MemberField( Type type, string name ) :
		m_Type( type ), m_Name( name ), m_DefaultValue() { }

	MemberField( Type type, string name, ptr<Expression> defaultValue ) :
		m_Type( type ), m_Name( name ), m_DefaultValue( defaultValue ) { }

private:
	Type            m_Type;
	string          m_Name;
	ptr<Expression> m_DefaultValue;
};

}
