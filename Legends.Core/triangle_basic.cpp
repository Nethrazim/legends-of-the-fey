const char* vertex_triangle_basic_src =
	"#version 410 core\n"
	"layout(location = 0) in vec3 aPos;\n"
	"layout(location = 1) in vec3 aColor;\n"
	"uniform mat4 uMVP;\n"
	"out vec3 vColor;\n"
	"out vec3 vPos;\n"
	"void main(){\n"
	"   vColor = aColor;\n"
	"   vPos = aPos;\n"
	"   gl_Position = uMVP * vec4(aPos, 1.0);\n"
	"}\n";

const char* fragment_triangle_basic_src = 
	"#version 410 core\n"
	"uniform float uTime;\n"
	"uniform float cTime;\n"
	"in vec3 vColor;\n"
	"in vec3 vPos;\n"
	"out vec4 FragmentColor;\n"
	"void main() {\n"
	"	float m = mod(vPos.x, 2.0);\n"
	"	if (m <= 0.5f) {\n"
	"		FragmentColor = vec4(1.0, 0.0, abs(cos(vPos.y)), 1.0);\n"
	"	}\n"
	"	else {\n"
	"		FragmentColor = vec4(1.0, abs(sin(vPos.y)), 1.0, 1.0);\n"
	"	}\n"
	"}\n";