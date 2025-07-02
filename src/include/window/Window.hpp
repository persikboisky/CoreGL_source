#ifndef INCLUDE_WINDOW_WINDOW_HPP_
#define INCLUDE_WINDOW_WINDOW_HPP_

struct GLFWwindow;

namespace core
{
	class Event;
	class Cursor;

	struct windowInfo
	{
		const char* title = "CoreGL";
		const char* pathToIcon = nullptr;
		int width = 640;
		int height = 480;
		bool VerticalSynchronization = true;
		bool resizable = false;
		bool debugInfo = true;

		windowInfo();
	};

	class Window
	{
	private:
		GLFWwindow* window = nullptr;

		static bool flagGLewInit;

		void Init();
		void getSizeWindow();

		bool VSfps = true;

	public:
		/// @brief ���������� ������ ����, ��� GLFWwindow
		GLFWwindow* getGlfwWindowObject();

		Event* event = nullptr;
		Cursor* cursor = nullptr;

		/// @brief ������� ������ ���� (����������� ��� ������ swapBuffers)
		int width;

		/// @brief ������� ������ ���� (����������� ��� ������ swapBuffers)
		int height;

		/// @brief ����������� ���� (������ ���� � ��� ������)
		/// @param width     ������ 
		/// @param height    ������ 
		/// @param title     ���������
		/// @param resizable ���������� �� ��������� ������� ����
		Window(int width, int height, const char* title = "", bool resizable = true);
		Window(const windowInfo& info);

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
		/// @param width  ������
		/// @param height ������
		void setSizeBuffer(int width, int height);

		/// @brief ��������� �������� �� ���� ����������
		/// @return true - ���� ��������, false - ���� �� ��������
		bool isContext();

		void VerticalSynchronization(bool flag);
	};
}

#endif // !INCLUDE_WINDOW_WINDOW_HPP_
