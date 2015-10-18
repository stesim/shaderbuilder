#pragma once

#include "statement.h"
#include "expression.h"

namespace shaderbuilder
{

class ExpressionStatement : public Statement
{
public:
	inline static ptr<ExpressionStatement> New( ptr<Expression> expr )
	{
		return make_ptr<ExpressionStatement>( expr );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << *m_Expression << ";";
	}

public://private:
	ExpressionStatement( ptr<Expression> expr )
		: m_Expression( expr ) { }

private:
	ptr<Expression> m_Expression;
};

}
