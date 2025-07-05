#include "../include/core.hpp"
#include "../include/config.hpp"
#include "../include/graphics/commons/vao.hpp"
#include "../include/graphics/commons/shader.hpp"
#include "../include/graphics/commons/texture.hpp"
#include "../include/util/coders.hpp"
#include "../include/util/console.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

void core::Core::Init()
{
	//core::date = new Time::Date();

	if (!glfwInit())
	{
		throw core::coders(0x00);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, VERSION_MAJOR);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, VERSION_MINOR);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, WINDOW_RESIZABLE);

	if (CORE_INFO)
	{
		console::printTime();
		std::cout << "OK: init glfw" << std::endl;
	}
}

double core::Core::GetTime()
{
	return glfwGetTime();
}

void core::Core::Terminate()
{
	shader::DeleteALL();
	vao::DeleteALL();
	ebo::DeleteALL();
	//fbo::DeleteALL();
	////mtl::Delete();
	texture::DeleteALL();
	////fonts::Text2D::DeleteALL();

	glfwTerminate();
}