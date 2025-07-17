#version 460 core

layout(location = 0) in vec3 pos;
layout(location = 2) in vec3 inColor;

uniform mat4 u_MVP;

out vec4 outColor;

void main () {
	gl_Position = u_MVP * vec4(pos, 1);
	outColor = vec4(inColor, 1);
}