#ifndef SHADER_H
#define SHADER_H

#include "include/glad/gl.h"
#include "common.h"

typedef struct {
    GLuint id;
} Shader;

Shader shader_create(const char* vertex_path, const char* fragment_path);

GLuint shader_compile(const char* source, GLenum type);

void shader_bind(Shader* shader);



#endif // SHADER_H