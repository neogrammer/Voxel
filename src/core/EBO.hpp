#ifndef EBO_HPP__
#define EBO_HPP__

#include <glad/glad.h>
#include <vector>

class EBO
{
public:
	// ID reference of Elements Buffer Object
	unsigned int ID;
	// Constructor that generates a Elements Buffer Object and links it to indices
	EBO(unsigned int* indices, GLsizeiptr size);
	EBO(std::vector<unsigned int>& indices);
	// Binds the EBO
	void bind();
	// Unbinds the EBO
	void unbind();
	// Deletes the EBO
	void destroy();
};

#endif