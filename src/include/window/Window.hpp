#ifndef INCLUDE_WINDOW_WINDOW_HPP_
#define INCLUDE_WINDOW_WINDOW_HPP_

struct GLFWwindow;
struct GLFWvidmode;

namespace core
{
	class Event;
	class Cursor;
	class Monitor;

	namespace math
	{
		class Vector2;
	}

	struct windowInfo
	{
		const char* title = "CoreGL";
		const char* pathToIcon = nullptr;
		int width = 640;
		int height = 480;
		bool VerticalSynchronization = true;
		bool resizable = false;
		bool debugInfo = true;
		int posX = -1;
		int posY = -1;

		windowInfo();
	};

	class Window
	{
	private:
		GLFWwindow* window = nullptr;
		const GLFWvidmode* vidMode;

		static bool flagGLewInit;

		void Init();
		void getSizeWindow();

		bool VSfps = true;

		Window(int width, int height, const char* title = "", bool resizable = true);
		Window(const windowInfo& info);

	public:
		/// @brief ���������� ������ ����, ��� GLFWwindow
		GLFWwindow* getGLFWWindowObject();

		Event* event = nullptr;
		Cursor* cursor = nullptr;

		/// @brief ������� ������ ���� (����������� ��� ������ swapBuffers)
		int width;

		/// @brief ������� ������ ���� (����������� ��� ������ swapBuffers)
		int height;

		static Window create(const windowInfo& info);
		static Window create(int width, int height, const char* title = "", bool resizable = true);

		~Window();

		/// @brief ������� ������ �����.
		/// � openGL ��� ������ �� ����� �� ������, ������ ������������ �� ������.
		/// swapBuffers() - ������� ������ �������.
		/// ������ ������������ ���, �� ������� �� ��������,
		/// � ������ �� �� ���, ������� �����������.
		/// �������� ��� ��� : )
		void swapBuffers();

		/// @brief ������������� ������ ��� ����
		/// @param path ���� � png ��������
		void setIcon(const char* path);

		/// @brief �������� ������� �������� ����
		void close();

		/// @brief ������ ���� ���������� (�� ��� �� ������)
		void setContext();

		/// @brief ������������� ������ ������ �����
		/// @param width  
		/// @param height ������
		void setSizeBuffer(int width, int height);

		/// @brief ��������� �������� �� ���� ����������
		/// @return true - ���� ��������, false - ���� �� ��������
		bool isContext();

		void VerticalSynchronization(bool flag);

		void setPos(int posX, int posY);
		void setPos(const math::Vector2& pos);

		static GLFWwindow* getWindowContext();

		void setMonitor(Monitor monitor);
		void resetMonitor();
	};
}

#endif // !INCLUDE_WINDOW_WINDOW_HPP_
