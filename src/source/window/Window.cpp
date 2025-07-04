#include "../../include/window/Window.hpp"
#include "../../include/window/Event.hpp"
#include "../../include/window/Cursor.hpp"
#include "../../include/window/Monitor.hpp"
#include "../../include/config.hpp"
#include "../../include/file/png.hpp"
#include "../../include/util/coders.hpp"
#include "../../include/math/Vectors.hpp"
#include "../../include/util/console.hpp"
#include "../../include/util/type.hpp"
#include "../../include/graphics/commons/fbo.hpp"
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

GLFWwindow* Window::getGLFWWindowObject()
{
	return this->window;
}

static void createWindow(
	GLFWwindow*& window, const GLFWvidmode*& vidMode, int width, int height,
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
		console::printTime();
		std::cout << "OK: to create GLFW Window" << std::endl;
	}

	//GLFWmonitor* monitor = glfwGetPrimaryMonitor();
	//if (monitor == nullptr) 
	//{

	//}

	//vidMode = glfwGetVideoMode(monitor);
	//if (vidMode == nullptr) 
	//{

	//}

	// std::cout << glfwGetMonitorName(monitor) << std::endl;
	
	// glfwSetWindowMonitor()
}

Window::Window(int width, int height, const char* title, bool resizable) :
	width(width), height(height), debugInfo(CORE_INFO)
{
	createWindow(
		this->window,
		this->vidMode,
		width, height,
		title,
		resizable,
		CORE_INFO
	);

	this->Init();
}

Window::Window(const windowInfo& info) : width(info.width), height(info.height), debugInfo(info.debugInfo)
{
	createWindow(
		this->window,
		this->vidMode,
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

	if (info.posX != -1 || info.posY != -1) 
	{
		glfwSetWindowPos(this->window, info.posX, info.posY);
	}
}

Window Window::create(const windowInfo& info)
{
	return Window(info);
}

Window Window::create(int width, int height, const char* title, bool resizable)
{
	windowInfo winInfo = {};
	winInfo.width = width;
	winInfo.height = height;
	winInfo.title = title;
	winInfo.resizable = resizable;
	return Window(winInfo);
}

Window::~Window()
{
	delete this->cursor;
	delete this->event;
	glfwDestroyWindow(this->window);
}

int Window::getWidth() const
{
	return this->width;
}

int Window::getHeight() const
{
	return this->height;
}

size2i Window::getSize()
{
	return size2i(this->width, this->height);
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
				throw coders(0x01, "Failed initializate GLEW error 240");
			}
			else
			{
				throw coders(0x01, "Failed initializate GLEW");
			}
			
		}

		if (this->debugInfo)
		{
			console::printTime();
			std::cout << "Ok: init glew" << std::endl;
		}

		Window::flagGLewInit = false;
	}

	glfwSwapInterval(0);
}

void Window::setSizeBuffer(int width, int height)
{
	if (!this->isContext())
	{
		this->setContext();
	}
	fbo::setSize(width, height);
}

void Window::setSizeBuffer(const size2i& size)
{
	if (!this->isContext())
	{
		this->setContext();
	}
	fbo::setSize(size);
}

void Window::setPosBuffer(int x, int y)
{
	if (!this->isContext())
	{
		this->setContext();
	}
	fbo::setPos(x, y);
}

void Window::setPosBuffer(const pos2i& pos)
{
	if (!this->isContext())
	{
		this->setContext();
	}
	fbo::setPos(pos);
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

void Window::setPos(int posX, int posY) 
{
	glfwSetWindowPos(this->window, posX, posY);
}

void Window::setPos(const pos2i& pos)
{
	this->setPos(pos.x, pos.y);
}

void Window::setSize(int width, int height)
{
	glfwSetWindowSize(this->window, width, height);
}

void Window::setSize(const size2i& size)
{
	glfwSetWindowSize(this->window, size.width, size.height);
}

GLFWwindow* Window::getWindowContext()
{
	return glfwGetCurrentContext();
}

void Window::setMonitor(Monitor monitor)
{
	glfwSetWindowMonitor(this->window, monitor.getGLFWObj(), 0, 0, this->width, this->height, 75);
}

void Window::resetMonitor()
{
	glfwSetWindowMonitor(this->window, nullptr, 0, 0, this->width, this->height, GLFW_DONT_CARE);
}
