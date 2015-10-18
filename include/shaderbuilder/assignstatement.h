#pragma once

#include "statement.h"

namespace shaderbuilder
{

class AssignStatement : public Statement
{
public:
	inline static ptr<AssignStatement> New(
		ptr<Expression> lhs, ptr<Expression> rhs )
	{
		return make_ptr<AssignStatement>( lhs, rhs );
	}

	virtual void compile( strstream& str ) const override
	{
		str << *m_LeftHandSide << " = " << *m_RightHandSide << ";";
	}

public://private:
	AssignStatement( ptr<Expression> lhs, ptr<Expression> rhs )
		: m_LeftHandSide( lhs ), m_RightHandSide( rhs ) { }

private:
	ptr<Expression> m_LeftHandSide;
	ptr<Expression> m_RightHandSide;
};

}
