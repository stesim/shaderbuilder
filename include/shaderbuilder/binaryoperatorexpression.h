#pragma once

#include "expression.h"

namespace shaderbuilder
{

class BinaryOperatorExpression : public Expression
{
public:
	enum class Operator
	{
		Add,
		Subtract,
		Multiply,
		Divide,
		Modulo,
		Equal,
		NotEqual,
		LessThan,
		LessThanEqual,
		GreaterThan,
		GreaterThanEqual,
		BooleanOr,
		BooleanAnd,
		BitwiseOr,
		BitwiseAnd,
		BitwiseXor,
		ShiftLeft,
		ShiftRight
	};

public:
	inline static ptr<BinaryOperatorExpression> New(
		ptr<Expression> lhs, Operator op, ptr<Expression> rhs )
	{
		return make_ptr<BinaryOperatorExpression>( lhs, op, rhs );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << "( " << *m_LeftHandSide << " "
			<< OperatorStrings[ static_cast<int>( m_Operator ) ]
			<< " " << *m_RightHandSide << " )";
	}

public://private:
	BinaryOperatorExpression(
		ptr<Expression> lhs, Operator op, ptr<Expression> rhs )
		: m_Operator( op ), m_LeftHandSide( lhs ), m_RightHandSide( rhs ) { }

private:
	static constexpr char OperatorStrings[][ 3 ] =
	{
		"+",
		"-",
		"*",
		"/",
		"%",
		"==",
		"!=",
		"<",
		"<=",
		">",
		">=",
		"||",
		"&&",
		"|",
		"&",
		"^",
		"<<",
		">>"
	};

	Operator        m_Operator;
	ptr<Expression> m_LeftHandSide;
	ptr<Expression> m_RightHandSide;
};

}
