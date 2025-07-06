#include "../../include/window/Monitor.hpp"
#include "../../include/util/coders.hpp"
#include "../../include/util/type.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace core;

GLFWmonitor* Monitor::getGLFWObj()
{
	return this->monitor;
}

Monitor::Monitor()
{
	this->monitor = glfwGetPrimaryMonitor();
	if (this->monitor == nullptr)
	{
		throw coders(0x11);
	}

	this->vidMode = glfwGetVideoMode(this->monitor);
	if (this->vidMode == nullptr)
	{
		throw coders(0x12);
	}
}

Monitor::~Monitor()
{
}

size2i Monitor::getPhysicalSize()
{
	int width;
	int height;

	glfwGetMonitorPhysicalSize(this->monitor, &width, &height);

	return size2i(width, height);
}

size2i Monitor::getSize()
{
	return size2i(
		this->vidMode->width,
		this->vidMode->height
	);
}

color::RGB Monitor::getBITS()
{
	return color::RGB(
		this->vidMode->redBits,
		this->vidMode->greenBits,
		this->vidMode->blueBits
	);
}

