#include "../../include/window/Window.hpp"
#include "../../include/window/Event.hpp"
#include "../../include/window/Cursor.hpp"
#include "../../include/config.hpp"
#include "../../include/file/png.hpp"
#include "../../include/util/coders.hpp"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
using namespace core;

windowInfo::windowInfo()
{
	this->debugInfo = CORE_INFO;
}

bool Window::flagGLewInit = true;

void Window::Init()
{
	this->event = new Event(*this->window);
	this->cursor = new Cursor(*this->window);
}

inline void Window::getSizeWindow()
{
	glfwGetWindowSize(this->window, &this->width, &this->height);
}

GLFWwindow* Window::getGlfwWindowObject()
{
	return this->window;
}

static void createWindow(
	GLFWwindow*& window, int width, int height,
	const char* title, bool resizable, bool debuginfo
)
{
	glfwWindowHint(GLFW_RESIZABLE, resizable);
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		throw coders(0x02);
	}

	if (debuginfo)
	{
		std::cout << "[" << glfwGetTime() << "] " << "OK: to create GLFW Window" << std::endl;
	}
}

Window::Window(int width, int height, const char* title, bool resizable) :
	width(width), height(height)
{
	createWindow(
		this->window,
		width, height,
		title,
		resizable,
		CORE_INFO
	);
	this->Init();
}

Window::Window(const windowInfo& info) : width(info.width), height(info.height)
{
	createWindow(
		this->window,
		info.width,
		info.height,
		info.title,
		info.resizable,
		info.debugInfo
	);
	this->Init();
	if (info.pathToIcon != nullptr)
	{
		this->setIcon(info.pathToIcon);
	}
	this->VerticalSynchronization(info.VerticalSynchronization);
}

Window::~Window()
{
	delete this->cursor;
	delete this->event;
	glfwDestroyWindow(this->window);
}

void Window::swapBuffers()
{
	if (this->VSfps)
	{
		glfwSwapInterval(1);
	}
	else
	{
		glfwSwapInterval(0);
	}

	glfwSwapBuffers(this->window);
	this->getSizeWindow();
}

void Window::setIcon(const char* path)
{
	GLFWimage images[1] = { };

	unsigned char* img = png::load(path);

	images[0].width = png::width;
	images[0].height = png::height;
	images[0].pixels = img;

	glfwSetWindowIcon(this->window, 1, images);
	free(images[0].pixels);
}

void Window::close()
{
	glfwSetWindowShouldClose(this->window, true);
}

void Window::setContext()
{
	glfwMakeContextCurrent(this->window);

	if (Window::flagGLewInit)
	{
		glewExperimental = GL_TRUE;
		GLenum glewErr = glewInit();
		if (glewErr != GLEW_OK)
		{
			if (glewErr == GLEW_ERROR_NO_GLX_DISPLAY)
			{
				std::cerr << "Failed initializate GLEW error 240" << std::endl;
			}
			else
			{
				std::cerr << "Failed initializate GLEW" << std::endl;
			}
			throw coders(0x01);
		}

		Window::flagGLewInit = false;
	}

	glfwSwapInterval(0);
}

void Window::setSizeBuffer(int width, int height)
{
	glViewport(0, 0, width, height);
}

bool Window::isContext()
{
	if (this->window == glfwGetCurrentContext())
	{
		return true;
	}
	return false;
}

void Window::VerticalSynchronization(bool flag)
{
	this->VSfps = flag;
}