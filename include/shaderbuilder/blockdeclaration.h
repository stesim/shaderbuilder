#pragma once

#include "compilable.h"
#include "collection.h"
#include "memberfield.h"
#include <initializer_list>

namespace shaderbuilder
{

class BlockDeclaration : public Compilable
{
public:
	enum class Layout
	{
		Shared,
		Packed,
		Std140
	};

	enum class Type
	{
		In,
		Out,
		Uniform
	};

public:
	inline static ptr<BlockDeclaration> New( Type type, string blockName )
	{
		return make_ptr<BlockDeclaration>( type, blockName );
	}

	inline static ptr<BlockDeclaration> New(
			Type type,
			string blockName,
			std::initializer_list<ptr<MemberField>> fields )
	{
		return New( type, blockName, fields, "", Layout::Shared );
	}

	inline static ptr<BlockDeclaration> New(
			Type type,
			string blockName,
			std::initializer_list<ptr<MemberField>> fields,
			string instanceName )
	{
		return New( type, blockName, fields, instanceName, Layout::Shared );
	}

	inline static ptr<BlockDeclaration> New(
			Type type,
			string blockName,
			std::initializer_list<ptr<MemberField>> fields,
			Layout layout )
	{
		return New( type, blockName, fields, "", layout );
	}

	inline static ptr<BlockDeclaration> New(
			Type type,
			string blockName,
			std::initializer_list<ptr<MemberField>> fields,
			string instanceName,
			Layout layout )
	{
		return make_ptr<BlockDeclaration>(
			type,
			blockName,
			fields,
			instanceName,
			layout );
	}

	virtual void compile( strstream& stream ) const override;

public://private:
	BlockDeclaration( Type type, string blockName ) :
		m_Type( type ), m_BlockName( blockName ), m_Layout( Layout::Shared ) { }

	BlockDeclaration(
		Type type,
		string blockName,
		std::initializer_list<ptr<MemberField>> fields,
		string instanceName,
		Layout layout ) :
		m_Type( type ),
		m_BlockName( blockName ),
		m_Fields( fields ),
		m_InstanceName( instanceName ),
		m_Layout( layout )
	{
	}

private:
	Type                    m_Type;
	string                  m_BlockName;
	Collection<MemberField> m_Fields;
	string                  m_InstanceName;
	Layout                  m_Layout;
};

}
