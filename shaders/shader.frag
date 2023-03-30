# version 410 core

layout (location = 0) out vec4 color;
in vec3 texCoordV;

void main() {
    color = vec4(texCoordV + 0.5, 1.0);
}