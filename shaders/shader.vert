# version 410 core

layout (location = 0) in vec3 aPos;
out vec3 texCoordV;

void main() {
    texCoordV = aPos;
    gl_Position = vec4(aPos, 1.0);
}