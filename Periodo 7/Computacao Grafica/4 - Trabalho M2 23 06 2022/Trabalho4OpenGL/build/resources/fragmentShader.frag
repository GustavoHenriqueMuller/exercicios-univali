#version 330 core

uniform sampler2D uniTexture;
uniform sampler2D uniTextureNormal;

uniform float lightAmbientIntensity;
uniform float lightDiffuseIntensity;
uniform vec3 lightColor;
uniform vec3 lightPosition;

out vec4 outColor;

in vec3 position;
in vec3 normal;
in vec2 uv;

void main (void) {
    vec3 n = texture(uniTextureNormal, uv).xyz;
    n.y = 1 - n.y;
    n = n * 2 - 1;

    vec3 norm = normalize(n);
    vec3 dirLuz = normalize(lightPosition - position);

    float diff = max(dot(norm, dirLuz), 0.0);

    vec3 resultado_luz_dif = diff * lightDiffuseIntensity * lightColor;
    vec3 resultado_luz = lightAmbientIntensity * lightColor + resultado_luz_dif;

    outColor = texture(uniTexture, uv) * vec4(resultado_luz, 1.0);
}
