#include <iostream>
#include <vector>
#include "include/core.hpp"

using namespace core;

int main()
{
	Core::Init();

	Monitor mon = Monitor();

	windowInfo winInfo = { };
	winInfo.width = 1280;
	winInfo.height = 720;
	winInfo.debugInfo = true;
	winInfo.title = "test";
	winInfo.VerticalSynchronization = true;
	winInfo.posX = 500;
	winInfo.posY = 100;

	Window win = Window::create(winInfo);
	win.setContext();

	while (!win.event->close())
	{
		win.event->update();
	}

	Core::Terminate();
	return 0;
}