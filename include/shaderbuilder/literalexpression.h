#pragma once

#include "expression.h"

namespace shaderbuilder
{

template<typename T>
class TypedLiteralExpression;

class LiteralExpression : public Expression
{
public:
	template<typename T>
	inline static ptr<LiteralExpression> New( T val )
	{
		return TypedLiteralExpression<T>::New( val );
	}
};

template<typename T>
class TypedLiteralExpression : public LiteralExpression
{
public:
	inline static ptr<TypedLiteralExpression<T>> New( T val )
	{
		return make_ptr<TypedLiteralExpression<T>>( val );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << std::to_string( m_Value );
	}

public://private:
	TypedLiteralExpression( T val )
		: m_Value( val ) { }

private:
	T m_Value;
};

}
