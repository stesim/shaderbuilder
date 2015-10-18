#pragma once

#include "statement.h"
#include "expression.h"
#include "collection.h"

namespace shaderbuilder
{

class IfStatement : public Statement
{
public:
	inline static ptr<IfStatement> New(
		ptr<Expression> condition,
		std::initializer_list<ptr<Statement>> trueStatements )
	{
		return make_ptr<IfStatement>( condition, trueStatements );
	}

	inline static ptr<IfStatement> New(
		ptr<Expression> condition,
		std::initializer_list<ptr<Statement>> trueStatements,
		std::initializer_list<ptr<Statement>> falseStatements )
	{
		return make_ptr<IfStatement>(
				condition, trueStatements, falseStatements );
	}

	virtual void compile( strstream& stream ) const override;

public://private:
	IfStatement(
		ptr<Expression> condition,
		std::initializer_list<ptr<Statement>> trueStatements ) :
		m_Condition( condition ), m_TrueStatements( trueStatements ) { }

	IfStatement(
		ptr<Expression> condition,
		std::initializer_list<ptr<Statement>> trueStatements,
		std::initializer_list<ptr<Statement>> falseStatements ) :
		m_Condition( condition ),
		m_TrueStatements( trueStatements ),
		m_FalseStatements( falseStatements ) { }

private:
	ptr<Expression>       m_Condition;
	Collection<Statement> m_TrueStatements;
	Collection<Statement> m_FalseStatements;
};

}
