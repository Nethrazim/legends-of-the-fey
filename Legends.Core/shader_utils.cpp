#include "shader_utils.h"

#include <iostream>
#include <vector>

#include "glad.h"

bool CompileShader(const GLuint shader, const char* src)
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

bool LinkProgram(const GLuint prog)
{
	glLinkProgram(prog);
	GLint ok = 0;
	glGetProgramiv(prog, GL_LINK_STATUS, &ok);
	if (!ok) {
		GLint len = 0;
		glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &len);
		std::vector<char> log(len ? len : 1);
		glGetProgramInfoLog(prog, (GLsizei)log.size(), nullptr, log.data());
		std::cerr << "Program link error: " << log.data() << std::endl;
		return false;
	}
	return true;
}

bool CreateProgram(const GLuint program, const GLuint vs, const GLuint fs)
{
	glAttachShader(program, vs);
	glAttachShader(program, fs);

	if (!LinkProgram(program))
	{
		glDeleteShader(vs);
		glDeleteShader(fs);
		glDeleteProgram(program);
		return false;
	}

	glDetachShader(program, vs);
	glDetachShader(program, fs);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return true;
}