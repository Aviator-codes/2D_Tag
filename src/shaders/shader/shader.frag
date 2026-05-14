#version 330 core
out vec4 FragColor;

in vec2 UV;

uniform sampler2D texture_img;

void main()
{
    FragColor = texture(texture_img, UV);
}