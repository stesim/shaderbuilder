#pragma once

#include "expression.h"

namespace shaderbuilder
{

class ArrayIndexerExpression : public Expression
{
public:
	inline static ptr<ArrayIndexerExpression> New(
		ptr<Expression> array, ptr<Expression> index )
	{
		return make_ptr<ArrayIndexerExpression>( array, index );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << *m_Array << "[ " << *m_Index << " ]";
	}

public://private:
	ArrayIndexerExpression( ptr<Expression> array, ptr<Expression> index )
		: m_Array( array ), m_Index( index ) { }

private:
	ptr<Expression> m_Array;
	ptr<Expression> m_Index;
};

}
