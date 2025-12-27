const char* cube_vertex_shader =
"#version 410 core\n"

"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec2 aUV;\n"

"uniform mat4 uMVP;\n"

"out vec2 vUV;\n"

"void main(){\n"
"   vUV = aUV;\n"
"   gl_Position = uMVP * vec4(aPos, 1.0);\n"
"}\n";

const char* cube_fragment_shader =
"#version 410 core\n"

"out vec4 FragmentColor;\n"

"in vec2 vUV;\n"
"uniform sampler2D uTex;\n"

"void main() {\n"
"	FragmentColor = texture(uTex, vUV);\n"
"}\n";