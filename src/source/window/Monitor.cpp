#include "../../include/window/Monitor.hpp"
#include "../../include/util/coders.hpp"
#include "../../include/util/type.hpp"
#include <GLFW/glfw3.h>

using namespace core;

GLFWmonitor* Monitor::getGLFWObj()
{
	return this->monitors[this->primaryCount];
}

Monitor::Monitor() : count(0), primaryCount(-1)
{
	this->monitors = glfwGetMonitors(&this->count);
	if (this->count == 0)
	{
		throw coders(0x0A);
	}

	for (int iter = 0; iter < this->count; iter++)
	{
		if (this->monitors[iter] == nullptr)
		{
			throw coders(0x0A);
		}

		this->vidModes.push_back(glfwGetVideoMode(this->monitors[iter]));
	}

	GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	for (int iter = 0; iter < this->count; iter++) 
	{
		if (monitor == this->monitors[iter])
		{
			this->primaryCount = iter;
			break;
		}
	}
}

Monitor::~Monitor()
{
	this->vidModes.clear();
}

size2f Monitor::getPhysicalSize()
{
	int width;
	int height;

	glfwGetMonitorPhysicalSize(this->monitors[this->primaryCount], &width, &height);

	return size2f(width, height);
}

size2f Monitor::getSize()
{
	return size2f(
		this->vidModes[this->primaryCount]->width,
		this->vidModes[this->primaryCount]->height
	);
}

color::RGB Monitor::getBITS()
{
	return color::RGB(
		this->vidModes[this->primaryCount]->redBits,
		this->vidModes[this->primaryCount]->greenBits,
		this->vidModes[this->primaryCount]->blueBits
	);
}

