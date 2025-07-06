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

constexpr int HEIGHT_HEAD_WINDOW = 30;

windowInfo::windowInfo()
{
	this->debugInfo = CORE_INFO;
}

bool Window::flagGLewInit = true;

void Window::Init()
{
	this->event = new Event(*this->window);
	this->cursor = new Cursor(*this->window);
	this->monitor = new Monitor();
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
	GLFWwindow*& window, int width, int height,
	const char* title, bool resizable, bool debugInfo
)
{
	glfwWindowHint(GLFW_RESIZABLE, resizable);
	window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (window == nullptr)
	{
		glfwTerminate();
		throw coders(0x02);
	}

	if (debugInfo)
	{
		console::printTime();
		std::cout << "OK: to create GLFW Window" << std::endl;
	}
}

Window::Window(int width, int height, const char* title, bool resizable) :
	width(width), height(height), debugInfo(CORE_INFO), saveWidth(width), saveHeight(height)
{
	createWindow(
		this->window,
		width, height,
		title,
		resizable,
		CORE_INFO
	);

	glfwGetWindowPos(this->window, &this->width, &this->height);

	this->Init();
}

Window::Window(const windowInfo& info) : width(info.width), height(info.height), debugInfo(info.debugInfo),
	saveWidth(info.width), saveHeight(info.height)
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

	if (info.posX != -1 || info.posY != -1) 
	{
		glfwSetWindowPos(this->window, info.posX, info.posY);
	}

	glfwGetWindowPos(this->window, &this->posX, &this->posY);
}

Window Window::create(const windowInfo& info)
{
	return Window(info);
}

Window Window::create(int width, int height, const char* title, bool resizable)
{
	return Window(width, height, title, resizable);
}

Window::~Window()
{
	delete this->cursor;
	delete this->event;
	delete this->monitor;
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
	this->posX = posX;
	this->posY = posY;
	glfwSetWindowPos(this->window, posX, posY);
}

void Window::setPos(const pos2i& pos)
{
	this->setPos(pos.x, pos.y);
}

void Window::setPos(const POSITION& pos)
{
	switch (pos)
	{
	case CENTER:
		this->setPos(
			this->monitor->getSize().width / 2 - this->width / 2,
			this->monitor->getSize().height / 2 - this->height / 2 + HEIGHT_HEAD_WINDOW
		);
		break;

	case UP_CENTER_SIDE:
		this->setPos(
			this->monitor->getSize().width / 2 - this->width / 2,
			HEIGHT_HEAD_WINDOW
		);
		break;

	case DOWN_CENTER_SIDE:
		this->setPos(
			this->monitor->getSize().width / 2 - this->width / 2,
			this->monitor->getSize().height - HEIGHT_HEAD_WINDOW - this->height
		);
		break;

	case LEFT_UP_CORNER:
		this->setPos(
			0,
			HEIGHT_HEAD_WINDOW
		);
		break;

	case LEFT_CENTER_SIDE:
		this->setPos(
			0,
			this->monitor->getSize().height / 2 - this->height / 2 + HEIGHT_HEAD_WINDOW
		);
		break;

	case LEFT_DOWN_CORNER:
		this->setPos(
			0,
			this->monitor->getSize().height - HEIGHT_HEAD_WINDOW - this->height
		);
		break;

	case RIGHT_UP_CORNER:
		this->setPos(
			this->monitor->getSize().width - this->width,
			HEIGHT_HEAD_WINDOW
		);
		break;

	case RIGHT_CENTER_SIDE:
		this->setPos(
			this->monitor->getSize().width - this->width,
			this->monitor->getSize().height / 2 - this->height / 2 + HEIGHT_HEAD_WINDOW
		);
		break;

	case RIGHT_DOWN_CORNER:
		this->setPos(
			this->monitor->getSize().width - this->width,
			this->monitor->getSize().height - HEIGHT_HEAD_WINDOW - this->height
		);
		break;
	}
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
	glfwSetWindowMonitor(this->window, monitor.getGLFWObj(), 0, 0, monitor.getSize().width, monitor.getSize().height, 75);
}

void Window::resetMonitor()
{
	glfwSetWindowMonitor(this->window, nullptr, 0, 0, this->width, this->height, GLFW_DONT_CARE);
}

void Window::fullScreen(bool flag)
{
	if (flag)
	{
		this->saveWidth = this->width;
		this->saveHeight = this->height;
		this->setMonitor(*this->monitor);
		this->setPosBuffer(0, 0);
	}
	else
	{
		this->width = this->saveWidth;
		this->height = this->saveHeight;
		this->resetMonitor();
		this->setPos(this->posX, this->posY);
		this->setPosBuffer(0, 0);
	}
}
