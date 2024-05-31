#ifndef VAO_HPP__
#define VAO_HPP__
#include <glad/glad.h>

#include "VBO.hpp"
class VAO
{
	
public:
	unsigned int ID;
	
	VAO();
	void linkAttrib(VBO& l_VBO, unsigned int l_layout, unsigned int l_numComponents, GLenum l_type, GLsizei l_stride, void* l_offset);

	void bind();
	void unbind();
	void destroy();
};

#endif