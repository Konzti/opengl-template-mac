#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Vertex2D;

typedef struct {
    float x;
    float y;
    float z;
} Vertex3D;

char * parse_shader(const char * file_path);

#endif // COMMON_H

