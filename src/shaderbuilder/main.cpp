#include "compileunit.h"
#include "uniformvariabledeclaration.h"
#include "ifstatement.h"
#include "variablereference.h"
#include "assignstatement.h"
#include "literalexpression.h"
#include "returnstatement.h"
#include "functioncallexpression.h"
#include "expressionstatement.h"
#include "binaryoperatorexpression.h"
#include "memberreferenceexpression.h"
#include "arrayindexerexpression.h"
#include "commentstatement.h"

#include <iostream>

using namespace shaderbuilder;

int main( int argc, char* argv[] )
{
	strstream stream;

	ptr<CompileUnit> cu = CompileUnit::New(
	{
		BlockDeclaration::New( BlockDeclaration::Type::In, "InstanceData",
		{
			MemberField::New( Type::Int, "instanceIndex" ),
			MemberField::New( Type::Int, "numInstances" )
		}, "instance_data_in" ),
		BlockDeclaration::New( BlockDeclaration::Type::Uniform, "Camera",
		{
			MemberField::New( Type::mat4, "mat_view" ),
			MemberField::New( Type::mat3, "mat_view_normal" )
		}, BlockDeclaration::Layout::Std140 )
	},
	{
		UniformVariableDeclaration::New( VariableDeclaration::New( Type::Float, "f_time" ) ),
	},
	{
		VariableDeclaration::New( Type::Float, "M_PI" )
	},
	{
		FunctionDeclaration::New( Type::vec4, "computeColor",
		{
			ParameterDeclaration::New( Type::Float, "x" ),
			ParameterDeclaration::New( Type::Float, "y", ParameterDeclaration::Direction::out )
		},
		{
		ExpressionStatement::New( FunctionCallExpression::New( "computeNormal", { VariableReference::New( "x" ) } ) )
		} ),
		FunctionDeclaration::New( Type::vec3, "computeNormal",
		{
			CommentStatement::New( "compute normals if necessary" ),
			IfStatement::New( BinaryOperatorExpression::New( MemberReferenceExpression::New( ArrayIndexerExpression::New( VariableReference::New( "instance_data_in" ), LiteralExpression::New( 0 ) ), "instanceIndex" ), BinaryOperatorExpression::Operator::Equal, LiteralExpression::New( 0 ) ),
			{
				VariableDeclaration::New( Type::vec3, "position" )
			},
			{
				//VariableDeclaration::New( Type::vec3, "normal", VariableReference::New( "vec_defaultNormal" ) )
				AssignStatement::New( VariableReference::New( "normal" ), LiteralExpression::New( 0 ) )
			} ),
			ReturnStatement::New( VariableReference::New( "normal" ) )
		} )
	} );

	stream << *cu;
	std::cout << stream.str() << std::endl;

	return 0;
}
