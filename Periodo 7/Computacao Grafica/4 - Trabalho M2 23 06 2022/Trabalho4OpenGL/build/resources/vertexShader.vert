#version 330 core

layout (location = 0) in vec3 inPosition;
layout (location = 1) in vec2 inUv;
layout (location = 2) in vec3 inNormal;

out vec3 position;
out vec2 uv;
out vec3 normal;

void main() {
    position = inPosition;
    uv = inUv;
    normal = inNormal;

    gl_Position = vec4(inPosition, 2.0f);
}
