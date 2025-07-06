#ifndef INCLUDE_WINDOW_WINDOW_HPP_
#define INCLUDE_WINDOW_WINDOW_HPP_

struct GLFWwindow;
struct GLFWvidmode;

namespace core
{
	class Event;
	class Cursor;
	class Monitor;

	struct size2i;
	struct pos2i;

	enum POSITION;

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

		static bool flagGLewInit;

		int width;
		int height;

		int saveWidth;
		int saveHeight;

		int posX;
		int posY;

		void Init();
		void getSizeWindow();

		bool VSfps = true;
		bool debugInfo = true;

		Window(int width, int height, const char* title = "", bool resizable = true);
		Window(const windowInfo& info);

		void setMonitor(Monitor monitor);
		void resetMonitor();

	public:
		/// @brief ���������� ������ ����, ��� GLFWwindow
		GLFWwindow* getGLFWWindowObject();

		Event* event = nullptr;
		Cursor* cursor = nullptr;
		Monitor* monitor = nullptr;

		static Window create(const windowInfo& info);
		static Window create(int width, int height, const char* title = "", bool resizable = true);

		~Window();

		int getWidth() const;
		int getHeight() const;
		size2i getSize();

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
		void setSizeBuffer(const size2i& size);

		void setPosBuffer(int x, int y);
		void setPosBuffer(const pos2i& pos);

		/// @brief ��������� �������� �� ���� ����������
		/// @return true - ���� ��������, false - ���� �� ��������
		bool isContext();

		void VerticalSynchronization(bool flag);

		void setPos(int posX, int posY);
		void setPos(const pos2i& pos);
		void setPos(const POSITION& pos);

		void setSize(int wisth, int height);
		void setSize(const size2i& size);

		static GLFWwindow* getWindowContext();

		void fullScreen(bool flag = true);
	};
}

#endif // !INCLUDE_WINDOW_WINDOW_HPP_
