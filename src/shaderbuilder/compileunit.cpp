#include "compileunit.h"

namespace shaderbuilder
{

void CompileUnit::compile( strstream& stream ) const
{
	char buffer[ 128 ];
	sprintf( buffer, "%u", m_uiVersion );

	stream << "#version " << buffer << "\n\n";

	for( auto block : m_Blocks )
	{
		stream << *block << "\n\n";
	}

	for( auto uniforms : m_Uniforms )
	{
		stream << *uniforms << "\n\n";
	}

	for( auto variable : m_Variables )
	{
		stream << *variable << "\n\n";
	}

	for( auto func : m_Functions )
	{
		stream << *func << "\n\n";
	}
}

}
