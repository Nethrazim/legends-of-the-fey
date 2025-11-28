#pragma once
#include <SDL2/SDL.h>
#include "glad.h"

bool CompileShader(const GLuint shader, const char* src);
bool CreateProgram(const GLuint program, const GLuint vs, const GLuint fs);
