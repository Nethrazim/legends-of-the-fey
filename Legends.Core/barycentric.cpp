const char* vertex_triangle_barycentric_src =
"#version 410 core\n"

"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec3 aBarycentric;\n"

"uniform mat4 uMVP;\n"

"out vec3 vBary;\n"

"void main(){\n"
"   vBary = aBarycentric;\n"
"   gl_Position = uMVP * vec4(aPos, 1.0);\n"
"}\n";

const char* fragment_triangle_barycentric_src =
"#version 410 core\n"
"in vec3 vBary;\n"
"uniform float uEdgeWidth;\n"
"uniform vec3 edgeColor;\n"
"uniform vec3 fillColor;\n"
"out vec4 FragmentColor;\n"
"void main() {\n"
"   float d = min(vBary.x, min(vBary.y, vBary.z));\n"
"   if(d < uEdgeWidth) {\n"
"    FragmentColor= vec4(edgeColor, 1);\n"
"   } else {\n"
"    FragmentColor = vec4(fillColor, 1);\n"
"	}\n"
"}\n";