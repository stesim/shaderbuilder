#pragma once

#include "expression.h"

namespace shaderbuilder
{

class MemberReferenceExpression : public Expression
{
public:
	inline static ptr<MemberReferenceExpression> New(
		ptr<Expression> object, string field )
	{
		return make_ptr<MemberReferenceExpression>( object, field );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << *m_Object << "." << m_Field;
	}

public://private:
	MemberReferenceExpression( ptr<Expression> object, string field )
		: m_Object( object ), m_Field( field ) { }

private:
	ptr<Expression> m_Object;
	string          m_Field;
};

}
