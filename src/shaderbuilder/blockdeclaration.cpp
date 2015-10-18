#include "blockdeclaration.h"

namespace shaderbuilder
{

void BlockDeclaration::compile( strstream& stream ) const
{
	switch( m_Layout )
	{
		case Layout::Shared:
			break;
		case Layout::Packed:
			stream << "layout( packed ) ";
			break;
		case Layout::Std140:
			stream << "layout( std140 ) ";
			break;
	}

	switch( m_Type )
	{
		case Type::In:
			stream << "in ";
			break;
		case Type::Out:
			stream << "out ";
		case Type::Uniform:
			stream << "uniform ";
			break;
	}

	stream << m_BlockName << "\n{\n";

	std::size_t indent = stream.increaseIndent();

	for( auto field : m_Fields )
	{
		stream << *field << "\n";
	}

	stream.setIndent( indent );

	stream << "}";

	if( !m_InstanceName.empty() )
	{
		stream << " " << m_InstanceName;
	}

	stream << ";";
}

}
