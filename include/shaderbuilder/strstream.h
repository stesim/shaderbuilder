#pragma once

#include <string>
#include <iostream>

namespace shaderbuilder
{

constexpr const char* endl = "\n";

class strstream
{
public:
	inline strstream& operator<<( const std::string& str )
	{
		append( str.c_str() );
		return *this;
	}

	inline strstream& operator<<( const char* str )
	{
		append( str );
		return *this;
	}

	std::string str() const
	{
		return m_Content;
	}

	inline std::size_t getIndent() const
	{
		return m_uiIndent;
	}

	inline void setIndent( std::size_t indent )
	{
		m_uiIndent = indent;
	}

	inline std::size_t increaseIndent()
	{
		return m_uiIndent++;
	}

	inline std::size_t decreaseIndent()
	{
		return m_uiIndent--;
	}

private:
	void append( const char* str );

private:
	std::string m_Content;
	std::size_t m_uiIndent;
	std::size_t m_uiLine;
	std::size_t m_uiLinePosition;
};

}
