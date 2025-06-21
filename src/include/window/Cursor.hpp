#ifndef INCLUDE_WINDOW_CURSOR_HPP_
#define INCLUDE_WINDOW_CURSOR_HPP_

#include <vector>

enum Cursor_mode;
struct GLFWwindow;
struct GLFWcursor;

namespace core
{
	class Window;

	struct cursor
	{
		static double getCordCursorX(GLFWwindow* window);
		static double getCordCursorY(GLFWwindow* window);
		static void getCordCursor(GLFWwindow* window, double& x, double& y);
	};

	class Cursor
	{
	private:
		GLFWwindow* window;

	public:
		static class custom_cursor
		{
		private:
			GLFWcursor* cursor_objs = nullptr;
			GLFWwindow& addrWindow;

		public:
			custom_cursor(const char* pathToPng, int x, int y, GLFWwindow* window);
			~custom_cursor();

			/// @brief �������� ��������� ������
			void use();

			/// @brief ���������� ������
			void unUse();
		};

		Cursor(GLFWwindow& addrWindow);
		Cursor(Window& window);
		~Cursor();

		/// @brief ������������� ����� �������
		/// @param mode ����� ������� ������������ ��������� ���������� GLFW 
		void setCursorMode(int mode);

		/// @brief ��������� �������� ������
		/// @param flag true - ��������� �������� false - ��������� ��������
		void showCursor(bool flag);

		/// @brief ��������� ������
		/// @param flag true - ��������, false - �������
		void disableCursor(bool flag);

		/// @brief ������������� ������ �� ��������� ����������
		/// @param x ��� x (�� 0 �� ������ ����)
		/// @param y ��� y (�� 0 �� ������ ����)
		void setPosition(double x, double y);

		/// @brief ���������� ���������� ������� �� ��� x
		double getCordCursorX();

		/// @brief ���������� ���������� ������� �� ��� y
		double getCordCursorY();

		/// @brief ������� ���������� ������� � ��������� ����������
		/// @param x ����� �� ���������� ��� x
		/// @param y ����� �� ���������� ��� y
		void getCordCursor(double& x, double& y);

		/// @brief ������ ��������� ������
		/// @brief ������: 
		/// @brief Cursor::custom_cursor cursor = ������_����.cursor->create("./res/aim.png", 0, 0);
		///	@brief cursor.use();
		/// @param path ���� � png ��������
		/// @param x ���������� �� x
		/// @param y ���������� �� y
		/// @return ���������� ������ �������
		custom_cursor create(const char* path, int x = 0, int y = 0);

		/*void setCursor(custom_cursor cursor);*/
	};
}

#endif // !INCLUDE_WINDOW_CURSOR_HPP_