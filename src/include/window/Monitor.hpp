#ifndef INCLUDE_WINDOW_MONITOR_HPP_
#define INCLUDE_WINDOW_MONITOR_HPP_

#include <vector>

struct GLFWmonitor;
struct GLFWvidmode;

namespace core
{

	struct size2i;
	namespace color
	{
		struct RGB;
	}

	class Monitor
	{
	private:
		GLFWmonitor* monitor;
		const GLFWvidmode* vidMode;

	public:
		Monitor();
		~Monitor();

		size2i getPhysicalSize();
		size2i getSize();
		color::RGB getBITS();

		GLFWmonitor* getGLFWObj();

	};
}

#endif // !INCLUDE_WINDOW_MONITOR_HPP_
