#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    FragColor = mix(texture(texture1,vec2(TexCoord.x/2.0, TexCoord.y/2.0)), texture(texture2, vec2(1 - TexCoord.x, TexCoord.y)), 0.2);
}