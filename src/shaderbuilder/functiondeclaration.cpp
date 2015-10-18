#include "functiondeclaration.h"

namespace shaderbuilder
{

void FunctionDeclaration::compile( strstream& stream ) const
{
	stream << type_name( m_ReturnType ) << " " << m_Name << "(";

	auto param_n = m_Parameters.size();
	if( param_n > 0 )
	{
		stream << " ";
	}

	for( auto param : m_Parameters )
	{
		stream << *param;
		if( --param_n > 0 )
		{
			stream << ", ";
		}
	}

	if( m_Parameters.size() > 0 )
	{
		stream << " ";
	}

	if( !m_bIsForwardDeclaration )
	{
		stream << ")\n{\n";

		std::size_t indent = stream.increaseIndent();

		for( auto statement : m_Statements )
		{
			stream << *statement << "\n";
		}

		stream.setIndent( indent );

		stream << "}";
	}
	else
	{
		stream << ");";
	}
}

}
