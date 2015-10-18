#pragma once

#include "compilable.h"
#include "collection.h"
#include "functiondeclaration.h"
#include "blockdeclaration.h"
#include "variabledeclaration.h"
#include "uniformvariabledeclaration.h"
#include <initializer_list>

namespace shaderbuilder
{

class CompileUnit : public Compilable
{
public:
	inline static ptr<CompileUnit> New(
		std::initializer_list<ptr<BlockDeclaration>> blocks,
		std::initializer_list<ptr<UniformVariableDeclaration>> uniforms,
		std::initializer_list<ptr<VariableDeclaration>> variables,
		std::initializer_list<ptr<FunctionDeclaration>> functions )
	{
		return make_ptr<CompileUnit>( blocks, uniforms, variables, functions );
	}

	virtual void compile( strstream& stream ) const override;

public://private:
	CompileUnit(
		std::initializer_list<ptr<BlockDeclaration>> blocks,
		std::initializer_list<ptr<UniformVariableDeclaration>> uniforms,
		std::initializer_list<ptr<VariableDeclaration>> variables,
		std::initializer_list<ptr<FunctionDeclaration>> functions ) :
		m_uiVersion( 420 ),
		m_Blocks( blocks ),
		m_Uniforms( uniforms ),
		m_Variables( variables ),
		m_Functions( functions ) { }
	~CompileUnit() { }

private:
	unsigned int                           m_uiVersion;
	Collection<BlockDeclaration>           m_Blocks;
	Collection<UniformVariableDeclaration> m_Uniforms;
	Collection<VariableDeclaration>        m_Variables;
	Collection<FunctionDeclaration>        m_Functions;
};

}
