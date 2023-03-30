#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "include/glad/gl.h"
#include "common.h"

typedef struct
{   
    GLuint id;
    GLuint vao;
    GLuint num_indices;

} VertexBuffer;

void bind_vertex_buffer(VertexBuffer* buffer) {
    glBindVertexArray(buffer->vao);
}

void unbind_vertex_buffer() {
    glBindVertexArray(0);
}

VertexBuffer create_vertex_buffer(Vertex3D * vertices, int num_vertices, GLuint * indices, int num_indices) {
    VertexBuffer buffer;
    buffer.num_indices = num_indices;

    glGenBuffers(1, &buffer.id);
    glBindBuffer(GL_ARRAY_BUFFER, buffer.id);
    glBufferData(GL_ARRAY_BUFFER, num_vertices * (sizeof(Vertex3D)), vertices, GL_STATIC_DRAW);
    
    glGenVertexArrays(1, &buffer.vao);
    glBindVertexArray(buffer.vao);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex3D), (void *)offsetof(Vertex3D, x));

    return buffer;
}


#endif // VERTEX_BUFFER_H