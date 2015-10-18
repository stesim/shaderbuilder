#pragma once

#include "statement.h"

namespace shaderbuilder
{

class CommentStatement : public Statement
{
public:
	inline static ptr<CommentStatement> New( string comment )
	{
		return make_ptr<CommentStatement>( comment );
	}

	virtual void compile( strstream& stream ) const override
	{
		stream << "/* " << m_Comment << " */";
	}

public://private:
	CommentStatement( string comment )
		: m_Comment( comment ) { }

private:
	string m_Comment;
};

}
