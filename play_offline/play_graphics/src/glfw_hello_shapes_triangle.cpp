/*
 * gfw_hello_shapes.cpp
 *
 *  Created on: 02-Apr-2021
 *      Author: kk
 *
 *  description :
 *  	http://www.opengl-tutorial.org/beginners-tutorials/tutorial-1-opening-a-window/#introduction
 */

#include <iostream>
#include <cstdlib>

#ifdef __APPLE__
#  include <OpenGL/gl3.h>
#else /// your stuff for linux
#	include <GL/glew.h>
#endif

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "shader.h"
#include "fs_utils.h"

int main(void)
{

	if (!glfwInit())
	{
		std::cerr << " Failed to initialize GLFW\n";
		return -1;
	}

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x anti aliasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // We don't want the old OpenGL

	// Open a window and create its OpenGL context
	GLFWwindow *window;
	window = glfwCreateWindow(1024, 768, "Hello Shapes", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cerr << "Failed to open GLFW window. ";
		std::cerr << "If you have an Intel GPU, they are not 3.3 compatible.";
		std::cerr << " Try the 2.1 version of the tutorials.\n";
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);


#ifndef __APPLE__
	// Initialize GLEW
	glewExperimental = true; // Needed in core profile
	if (glewInit() )
	{
		std::cerr << "Failed to initialize GLEW\n";
		return -1;
	}
#endif

	// Ensure we can capture the escape key being pressed below
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Create and compile our GLSL program from the shaders


	std::string baseDir = playground::utils::getExecutableDir();
	std::string vertexShader = baseDir + "/" + "SimpleVertexShader.vertexshader";
	std::string fragmentShader = baseDir + "/" + "SimpleFragmentShader.fragmentshader";

	std::cout << "vertexShader " << vertexShader << "\n";
	std::cout << "fragmentShader " << fragmentShader << "\n";

	GLuint programID = LoadShaders( vertexShader.c_str(), fragmentShader.c_str() );

	// BackGround colour it seems - Dark blue ?
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	//Vertex Access Object VAO
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	GLfloat g_vertex_buffer_data[] =
	{
			-1.0f, -1.0f, 0.0f,
			 1.0f, -1.0f, 0.0f,
			 0.0f,  1.0f, 0.0f,
	};

	GLuint vertexbuffer;
	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data),
			g_vertex_buffer_data,
			GL_STATIC_DRAW);

	do
	{
		// Clear the screen. It's not mentioned before Tutorial 02,
		// but it can cause flickering, so it's there nonetheless.
		glClear( GL_COLOR_BUFFER_BIT);

		// Use our shader
		glUseProgram(programID);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		//glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(0, // attribute 0. No particular reason for 0, but must match the layout in the shader.
				3,                  // size
				GL_FLOAT,           // type
				GL_FALSE,           // normalized?
				0,                  // stride
				(void*) 0            // array buffer offset
				);

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, 3); // 3 indices starting at 0 -> 1 triangle
		glDisableVertexAttribArray(0);


		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS
			&& glfwWindowShouldClose(window) == 0);

	// Cleanup VBO
	glDeleteBuffers(1, &vertexbuffer);
	glDeleteVertexArrays(1, &VertexArrayID);
	glDeleteProgram(programID);

	return 0;
}
