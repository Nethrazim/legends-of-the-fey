#pragma once
#include <map>
#include <string>


#include "glad.h"

namespace ShaderSystem
{
	class Shader
	{
	public:
		std::string name;
		GLuint getProgramId();

	public:
		static std::map<std::string, Shader*> glPrograms;
		static Shader* createGLProgram(const char* shaderName, const char* vsSrc, const char* fsSrc);

	private:
		GLuint vertexShaderId;
		
		GLuint fragmentShaderId;

		GLuint glProgramId;

		static bool compileShader(GLuint shader, const char* src);

		static bool composeGLProgram(const GLuint program, const GLuint vs, const GLuint fs);
		
		static bool linkProgram(const GLuint program);
	
	};
};
