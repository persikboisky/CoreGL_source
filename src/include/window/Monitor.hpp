#ifndef INCLUDE_WINDOW_MONITOR_HPP_
#define INCLUDE_WINDOW_MONITOR_HPP_

#include "Window.hpp"
#include <vector>

struct GLFWmonitor;
struct GLFWvidmode;

namespace core
{

	struct size2f;
	namespace color
	{
		struct RGB;
	}

	class Monitor
	{
	private:
		int count;
		int primaryCount;

		GLFWmonitor** monitors;
		std::vector<const GLFWvidmode*> vidModes;

		GLFWmonitor* getGLFWObj();

		friend void Window::setMonitor(Monitor monitor);

	public:
		Monitor();
		~Monitor();

		size2f getPhysicalSize();
		size2f getSize();
		color::RGB getBITS();

	};
}

#endif // !INCLUDE_WINDOW_MONITOR_HPP_
