const char* colors_vs =
"#version 410 core\n"

"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec2 aUV;\n"

"uniform mat4 uMVP;\n"

"void main(){\n"
"	gl_Position = uMVP * vec4(aPos, 1.0);\n"
"}\n";


const char* colors_fs =
"#version 410 core\n"
"uniform vec3 objectColor;\n"
"uniform vec3 lightColor;\n"

"out vec4 FragmentColor;\n"

"void main(){\n"
"	FragmentColor = vec4(lightColor * objectColor, 1.0);\n"
"}\n";