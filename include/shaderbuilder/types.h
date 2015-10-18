#pragma once

namespace shaderbuilder
{

enum class Type
{
	// float vectors / matrices
	Float = 0,
	vec2,
	vec3,
	vec4,
	mat2,
	mat2x3,
	mat2x4,
	mat3x2,
	mat3,
	mat3x4,
	mat4x2,
	mat4x3,
	mat4,

	// int vectors
	Int,
	ivec2,
	ivec3,
	ivec4,

	// uint vectors
	UInt,
	uvec2,
	uvec3,
	uvec4,

	// bool vectors
	Bool,
	bvec2,
	bvec3,
	bvec4,

	// void
	Void,

	// number of types
	Count,
};

constexpr int TYPE_NAME_LEN = 7;

constexpr char TypeNames[][ TYPE_NAME_LEN ] = {
	// float vectors / matrices
	"float",
	"vec2",
	"vec3",
	"vec4",
	"mat2",
	"mat2x3",
	"mat2x4",
	"mat3x2",
	"mat3",
	"mat3x4",
	"mat4x2",
	"mat4x3",
	"mat4",

	// int vectors
	"int",
	"ivec2",
	"ivec3",
	"ivec4",

	// uint vectors
	"uint",
	"uvec2",
	"uvec3",
	"uvec4",

	// bool vectors
	"bool",
	"bvec2",
	"bvec3",
	"bvec4",

	// void
	"void",
};

inline constexpr const char* type_name( Type type )
{
	return TypeNames[ static_cast<int>( type ) ];
}

}
