#ifndef TEXTURE_HPP__
#define TEXTURE_HPP__

#include <glad/glad.h>

#include <stb_image.h>

#include "Shader.hpp"

class Texture
{
public:
	unsigned int ID;
	const char* type;
	unsigned int unit;

	Texture(const char* image, const char* texType, unsigned int slot, GLenum format, GLenum pixelType);

	void texUnit(Shader& shader, const char* uniform, unsigned int unit);
	void bind();
	void unbind();
	void destroy();
};

#endif