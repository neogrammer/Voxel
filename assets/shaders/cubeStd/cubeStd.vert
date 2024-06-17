#version 410 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aColor;

out vec4 Color;

uniform mat4 matrix;

void main()
{
	Color = aColor;
	gl_Position = matrix * vec4(aPos.x, aPos.y, aPos.z, 1.0);
}