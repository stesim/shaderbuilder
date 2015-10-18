#include "ifstatement.h"

namespace shaderbuilder
{

void IfStatement::compile( strstream& stream ) const
{
	stream << "if( " << *m_Condition << " )";

	if( m_TrueStatements.size() > 0 || m_FalseStatements.size() > 0 )
	{
		stream << "\n{\n";
		std::size_t indent = stream.increaseIndent();
		for( auto statements : m_TrueStatements )
		{
			stream << *statements << "\n";
		}
		stream.setIndent( indent );
		stream << "}";
	}
	else
	{
		stream << ";";
	}

	if( m_FalseStatements.size() > 0 )
	{
		stream << "\nelse\n{\n";
		std::size_t indent = stream.increaseIndent();
		for( auto statements : m_FalseStatements )
		{
			stream << *statements << "\n";
		}
		stream.setIndent( indent );
		stream << "}";
	}
}

}
