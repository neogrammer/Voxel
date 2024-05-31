#ifndef VBO_HPP__
#define VBO_HPP__
#include <glm.hpp>
#include <glad/glad.h>
#include <vector>
struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};

class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	unsigned int ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(float* vertices, GLsizeiptr size);

	VBO(std::vector<Vertex>& vertices);


	void bind();
	void unbind();
	void destroy();
};

#endif