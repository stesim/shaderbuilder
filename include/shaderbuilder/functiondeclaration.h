#pragma once

#include "common.h"
#include "compilable.h"
#include "types.h"
#include "collection.h"
#include "parameterdeclaration.h"
#include "statement.h"
#include <initializer_list>

namespace shaderbuilder
{

class FunctionDeclaration : public Compilable
{
public:
	inline static ptr<FunctionDeclaration> New( Type returnType, string name )
	{
		return make_ptr<FunctionDeclaration>( returnType, name );
	}

	inline static ptr<FunctionDeclaration> New(
		Type returnType,
		string name,
		std::initializer_list<ptr<ParameterDeclaration>> params )
	{
		return make_ptr<FunctionDeclaration>( returnType, name, params );
	}

	inline static ptr<FunctionDeclaration> New(
		Type returnType,
		string name,
		std::initializer_list<ptr<Statement>> statements )
	{
		return make_ptr<FunctionDeclaration>( returnType, name, statements );
	}

	inline static ptr<FunctionDeclaration> New(
		Type returnType,
		string name,
		std::initializer_list<ptr<ParameterDeclaration>> params,
		std::initializer_list<ptr<Statement>> statements )
	{
		return make_ptr<FunctionDeclaration>(
				returnType, name, params, statements );
	}

	virtual void compile( strstream& stream ) const override;
	
	inline bool isForwardDeclaration() const
	{
		return m_bIsForwardDeclaration;
	}

	inline void setIsForwardDeclaration( bool value )
	{
		m_bIsForwardDeclaration = value;
	}

public://private:
	FunctionDeclaration( Type returnType, string name ) :
		m_ReturnType( returnType ),
		m_Name( name ) {}

	FunctionDeclaration(
		Type returnType,
		string name,
		std::initializer_list<ptr<ParameterDeclaration>> params ) :
		m_ReturnType( returnType ),
		m_Name( name ),
		m_Parameters( params ) { }

	FunctionDeclaration(
		Type returnType,
		string name,
		std::initializer_list<ptr<Statement>> statements ) :
		m_ReturnType( returnType ),
		m_Name( name ),
		m_Statements( statements ) { }

	FunctionDeclaration(
		Type returnType,
		string name,
		std::initializer_list<ptr<ParameterDeclaration>> params,
		std::initializer_list<ptr<Statement>> statements ) :
		m_ReturnType( returnType ),
		m_Name( name ),
		m_Parameters( params ),
		m_Statements( statements ) { }

private:
	Type                             m_ReturnType;
	string                           m_Name;
	Collection<ParameterDeclaration> m_Parameters;
	Collection<Statement>            m_Statements;
	bool                             m_bIsForwardDeclaration;
};

}
