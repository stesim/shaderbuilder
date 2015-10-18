#pragma once

#include "statement.h"

namespace shaderbuilder
{

class ReturnStatement : public Statement
{
public:
	inline static ptr<ReturnStatement> New( ptr<Expression> expr )
	{
		return make_ptr<ReturnStatement>( expr );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << "return " << *m_Expression << ";";
	}

public://private:
	ReturnStatement( ptr<Expression> expr )
		: m_Expression( expr ) { }

private:
	ptr<Expression> m_Expression;
};

}
