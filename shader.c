#include "shader.h"

Shader shader_create(const char *vertex_path, const char *fragment_path)
{   
    char* vertex_source = parse_shader(vertex_path);
    char* fragment_source = parse_shader(fragment_path);
    GLuint vertex_shader = shader_compile(vertex_source, GL_VERTEX_SHADER);
    GLuint fragment_shader = shader_compile(fragment_source, GL_FRAGMENT_SHADER);

    GLuint program = glCreateProgram();
    glAttachShader(program, vertex_shader);
    glAttachShader(program, fragment_shader);
    glLinkProgram(program);
    glValidateProgram(program);

    Shader shader = {
        .id = program
    };
    return shader;
}

GLuint shader_compile(const char *source, GLenum type)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, NULL);
    glCompileShader(shader);

    int result;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &result);
    if (result != GL_TRUE)
    {
        int length;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
        char *message = (char *)alloca(length * sizeof(char));
        glGetShaderInfoLog(shader, length, &length, message);
        printf("Failed to compile shader: %s\n", message);
    }

    return shader;
}

void shader_bind(Shader *shader)
{
    glUseProgram(shader->id);
}
