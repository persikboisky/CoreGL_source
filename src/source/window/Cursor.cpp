#include "../../include/window/Cursor.hpp"
#include "../../include/window/Window.hpp"
#include "../../include/config.hpp"
#include "../../include/file/png.hpp"
#include "../../include/util/coders.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

using namespace core;

double cursor::getCordCursorX(GLFWwindow* window)
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	return x;
}

double cursor::getCordCursorY(GLFWwindow* window)
{
	double x, y;
	glfwGetCursorPos(window, &x, &y);
	return y;
}

void cursor::getCordCursor(GLFWwindow* window, double& x, double& y)
{
	glfwGetCursorPos(window, &x, &y);
}

Cursor::Cursor(GLFWwindow& addrWindow) : window(&addrWindow)
{
}

Cursor::Cursor(Window& window) : window(window.getGLFWWindowObject())
{
}

Cursor::~Cursor()
{
	glfwSetCursor(this->window, nullptr);
	//this->DeleteALL();
}

void Cursor::setCursorMode(int mode)
{
	glfwSetInputMode(this->window, GLFW_CURSOR, mode);
}

void Cursor::showCursor(bool flag)
{
	if (!flag) setCursorMode(GLFW_CURSOR_HIDDEN);
	else setCursorMode(GLFW_CURSOR_NORMAL);
}

void Cursor::disableCursor(bool flag)
{
	if (flag) setCursorMode(GLFW_CURSOR_DISABLED);
	else setCursorMode(GLFW_CURSOR_NORMAL);
}

void Cursor::setPosition(double x, double y)
{
	glfwSetCursorPos(this->window, x, y);
}

double Cursor::getCordCursorX()
{
	double x, y;
	glfwGetCursorPos(this->window, &x, &y);
	return x;
}

double Cursor::getCordCursorY()
{
	double x, y;
	glfwGetCursorPos(this->window, &x, &y);
	return y;
}

void Cursor::getCordCursor(double& x, double& y)
{
	glfwGetCursorPos(this->window, &x, &y);
}

Cursor::custom_cursor::custom_cursor(const char* pathToPng, int x, int y, GLFWwindow* window) : addrWindow(*window)
{
	unsigned char* png = png::load(pathToPng);

	GLFWimage* img = new GLFWimage;
	img->height = png::height;
	img->width = png::width;
	img->pixels = &png[0];

	this->cursor_objs = glfwCreateCursor(img, x, y);

	if (this->cursor_objs == nullptr)
	{
		std::cerr << "Failed: create cursor obj";

		throw coders(0x03);
	}

	if (CORE_INFO) std::cout << "OK: created cursor > " << pathToPng << std::endl;
}

Cursor::custom_cursor::~custom_cursor()
{
	this->unUse();
	glfwDestroyCursor(this->cursor_objs);
}

Cursor::custom_cursor Cursor::create(const char* path, int x, int y)
{
	return Cursor::custom_cursor(path, x, y, this->window);
}

void Cursor::custom_cursor::use()
{
	glfwSetCursor(&this->addrWindow, this->cursor_objs);
}

void Cursor::custom_cursor::unUse()
{
	glfwSetCursor(&this->addrWindow, nullptr);
}