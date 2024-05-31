#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "G.hpp"

void input(GLFWwindow* window);
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);

bool firstMouse{ true };
double lastX{};
double lastY{};
double elapsed{ 0.0 };


int main()
{
	glfwInit();
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Get the primary monitor
	GLFWmonitor* monitor = glfwGetPrimaryMonitor();

	// Get the video mode for the monitor
	const GLFWvidmode* mode = glfwGetVideoMode(monitor);

	double ratioX = G::WND_WIDTH / 1920.0;
	double ratioY = G::WND_HEIGHT / 1080.0;

	double newWindowSizeX = ratioX * mode->width;
	double newWindowSizeY = ratioY * mode->height;

	lastX = newWindowSizeX / 2.0;
	lastY = newWindowSizeY / 2.0;
	
	G::WND_WIDTH = (int)newWindowSizeX;
	G::WND_HEIGHT = (int)newWindowSizeY;

	GLFWwindow* window = glfwCreateWindow((int)newWindowSizeX, (int)newWindowSizeY, "Voxel", NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Unable to create the GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);

	gladLoadGL();

	glViewport(0, 0, G::WND_WIDTH, G::WND_HEIGHT);
	
	glfwSetWindowPos(window, int((mode->width / 2.0) - (G::WND_WIDTH / 2.0)), int((mode->height / 2.0) - (G::WND_HEIGHT / 2.0)));

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.6f, 0.95f, 1.0f);

	double start = glfwGetTime();

	while (!glfwWindowShouldClose(window))
	{
		elapsed = glfwGetTime() - start;
		start = glfwGetTime();

		input(window);
		glfwPollEvents();


		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}

void input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
		return;
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	return;
}

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{

	if (firstMouse)
	{
		lastX = xposIn;
		lastY = yposIn;
		firstMouse = false;
	}

	double xoffset = xposIn - lastX;
	double yoffset = lastY - yposIn; // reversed since y-coordinates go from bottom to top

	lastX = xposIn;
	lastY = yposIn;

	// update camera or something based on xposIn and lastX here

	return;
}


