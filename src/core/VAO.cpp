#include "VAO.hpp"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::linkAttrib(VBO& l_VBO, unsigned int l_layout, unsigned int l_numComponents, GLenum l_type, GLsizei l_stride, void* l_offset)
{
	l_VBO.bind();
	glVertexAttribPointer(l_layout, l_numComponents, l_type, GL_FALSE, l_stride, l_offset);
	glEnableVertexAttribArray(l_layout);
	l_VBO.unbind();
}

void VAO::bind()
{
	glBindVertexArray(ID);
}

void VAO::unbind()
{
	glBindVertexArray(0);
}

void VAO::destroy()
{
	glDeleteVertexArrays(1, &ID);
}
