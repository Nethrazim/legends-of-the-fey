#include "shader.h"
#include <iostream>
#include <vector>

namespace ShaderSystem {
	std::map<std::string, Shader*> Shader::glPrograms;

	GLuint Shader::getProgramId()
	{
		return glProgramId;
	}

	Shader* Shader::createGLProgram(const char* name,const char* vsSrc, const char* fsSrc) {
		Shader* shader = new Shader();

		shader->vertexShaderId = glCreateShader(GL_VERTEX_SHADER);
		if (!compileShader(shader->vertexShaderId, vsSrc)) {
			std::cerr << "Failed to compile vertex shader." << std::endl;
			delete shader;
			return nullptr;
		}

		shader->fragmentShaderId = glCreateShader(GL_FRAGMENT_SHADER);
		if (!compileShader(shader->fragmentShaderId, fsSrc)) {
			std::cerr << "Failed to compile fragment shader." << std::endl;
			delete shader;
			return nullptr;
		}

		shader->glProgramId = glCreateProgram();

		if (!composeGLProgram(shader->glProgramId, shader->vertexShaderId, shader->fragmentShaderId)) {
			std::cerr << "Failed to create GL Program" << std::endl;
			delete shader;
			return nullptr;
		}

		glPrograms.emplace(name, shader);
		
		return shader;
	}

	bool Shader::composeGLProgram(const GLuint program, const GLuint vertexShaderId, const GLuint fragmentShaderId)
	{
		glAttachShader(program, vertexShaderId);
		glAttachShader(program, fragmentShaderId);

		if (!linkProgram(program))
		{
			glDeleteShader(vertexShaderId);
			glDeleteShader(fragmentShaderId);
			glDeleteProgram(program);
			return false;
		}

		glDetachShader(program, vertexShaderId);
		glDetachShader(program, fragmentShaderId);

		glDeleteShader(vertexShaderId);
		glDeleteShader(fragmentShaderId);

		return true;
	}


	bool Shader::compileShader(GLuint shader, const char* src)
	{
		
		glShaderSource(shader, 1, &src, nullptr);
		glCompileShader(shader);
		GLint ok = 0;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &ok);
		if (!ok)
		{
			GLint len = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
			std::vector<char> log(len ? len : 1);
			glGetShaderInfoLog(shader, (GLsizei)log.size(), nullptr, log.data());
			std::cerr << "Shader compile error:" << log.data() << std::endl;
			return false;
		}
		return true;
	}

	bool Shader::linkProgram(const GLuint program)
	{
		glLinkProgram(program);
		GLint ok = 0;
		glGetProgramiv(program, GL_LINK_STATUS, &ok);
		if (!ok) {
			GLint len = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
			std::vector<char> log(len ? len : 1);
			glGetProgramInfoLog(program, (GLsizei)log.size(), nullptr, log.data());
			std::cerr << "Program link error: " << log.data() << std::endl;
			return false;
		}
		return true;
	}
}

