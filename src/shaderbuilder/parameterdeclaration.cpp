#include "parameterdeclaration.h"

namespace shaderbuilder
{

void ParameterDeclaration::compile( strstream& stream ) const
{
	switch( m_Direction )
	{
		case Direction::in:
			//stream << "in ";
			break;
		case Direction::out:
			stream << "out ";
			break;
		case Direction::inout:
			stream << "inout ";
			break;
	}

	stream << TypeNames[ static_cast<int>( m_Type ) ]
		   << " " << m_Name;
}

}
