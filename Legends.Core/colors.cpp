const char* colors_vs =
"#version 410 core\n"

"layout(location = 0) in vec3 aPos;\n"
"layout(location = 1) in vec2 aUV;\n"
"layout(location = 2) in vec3 aNormal;\n"

"uniform vec3 lightPos;\n"

"uniform mat4 uMVP;\n"
"uniform mat4 model;\n"
"uniform mat4 view;\n"
"uniform mat4 projection;\n"

"out vec3 FragPos;\n"
"out vec3 Normal\n;"
"out vec3 LightPos\n;"

"void main(){\n"
"	gl_Position = uMVP * vec4(aPos, 1.0f);\n"
"   FragPos = vec3(view * model * vec4(aPos,1.0f));\n"
"   Normal = mat3(transpose(inverse(view * model))) * aNormal;\n"
"   LightPos = vec3(view * vec4(lightPos, 1.0f));\n"
"}\n";


const char* colors_fs =
"#version 410 core\n"

"in vec3 FragPos;\n"
"in vec3 Normal;\n"
"in vec3 LightPos;\n"

"uniform vec3 objectColor;\n"
"uniform vec3 lightColor;\n"

"out vec4 FragmentColor;\n"

"void main(){\n"
"   float ambientStrength = 0.1f;\n"
"   vec3 ambient = ambientStrength * lightColor;\n"

"   vec3 norm = normalize(Normal);\n"
"   vec3 lightDir = normalize(LightPos - FragPos);\n"
"   float diffuse = max(dot(norm,lightDir),0.0f);\n"


"   float specularStrength = 0.5;\n"
"   vec3 viewDir = normalize(-FragPos);\n"
"   vec3 reflectDir = reflect(-lightDir, norm);\n"
"   float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);\n"
"   vec3 specular = specularStrength * spec * lightColor;\n"

"   vec3 result = (ambient + diffuse + specular) * objectColor;\n"
"   FragmentColor = vec4(result, 1.0);\n"
"}\n";