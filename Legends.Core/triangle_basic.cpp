const char* vertex_triangle_basic_src =
	"#version 410 core\n"
	"layout(location = 0) in vec3 aPos;\n"
	"layout(location = 1) in vec3 aColor;\n"
	"uniform mat4 uMVP;\n"
	"out vec3 vColor;\n"
	"void main(){\n"
	"   vColor = aColor;\n"
	"   gl_Position = uMVP * vec4(aPos, 1.0);\n"
	"}\n";

const char* fragment_triangle_basic_src = 
	"#version 410 core\n"

	"in vec3 vColor;\n"
	"out vec4 FragmentColor;\n"
	"void main() {\n"
	"   FragmentColor = vec4(vColor, 1.0);\n"
	"}\n";