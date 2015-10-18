#include "strstream.h"

namespace shaderbuilder
{

void strstream::append( const char* str )
{
	while( true )
	{
		if( str[ 0 ] == '\0' )
		{
			break;
		}
		else if( str[ 0 ] == '\n' )
		{
			m_Content += '\n';

			// increment current line, reset current line position
			++m_uiLine;
			m_uiLinePosition = 0;

			// move str pointer to next line
			++str;
		}
		else
		{
			const char* c = str;
			while( *c != '\n' && *c != '\0' )
			{
				++c;
			}

			std::size_t indent = ( m_uiLinePosition == 0 ? m_uiIndent : 0 );
			std::size_t length;

			switch( *c )
			{
				case '\n':
					length = ( c - str ) + 1;
					m_Content.reserve(
						m_Content.size() + indent + length );
					if( indent > 0 )
					{
						m_Content.append( m_uiIndent, '\t' );
					}
					m_Content.append( str, length );

					// increment current line, reset current line position
					++m_uiLine;
					m_uiLinePosition = 0;

					// move str pointer to next line
					str = c + 1;
					break;
				case '\0':
					length = ( c - str );
					m_Content.reserve(
						m_Content.size() + indent + length );
					if( indent > 0 )
					{
						m_Content.append( m_uiIndent, '\t' );
					}
					m_Content.append( str, length );

					// update line position
					m_uiLinePosition += length;
					return;
			}
		}
	}
}

}
