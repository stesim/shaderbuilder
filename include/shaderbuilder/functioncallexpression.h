#pragma once

#include "expression.h"
#include "collection.h"

namespace shaderbuilder
{

class FunctionCallExpression : public Expression
{
public:
	inline static ptr<FunctionCallExpression> New( string name )
	{
		return make_ptr<FunctionCallExpression>( name );
	}

	inline static ptr<FunctionCallExpression> New(
		string name, std::initializer_list<ptr<Expression>> args )
	{
		return make_ptr<FunctionCallExpression>( name, args );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << m_Name;
		if( m_Arguments.size() > 0 )
		{
			stream << "( ";

			auto argc = m_Arguments.size();
			for( auto arg : m_Arguments )
			{
				stream << *arg;
				if( --argc > 0 )
				{
					stream << ", ";
				}
			}

			stream << " )";
		}
		else
		{
			stream << "()";
		}
	}

public://private:
	FunctionCallExpression( string name )
		: m_Name( name ) { }

	FunctionCallExpression(
		string name,
		std::initializer_list<ptr<Expression>> args )
		: m_Name( name ),
		  m_Arguments( args ) { }

private:
	string                 m_Name;
	Collection<Expression> m_Arguments;
};

}
