#ifndef INCLUDE_WINDOW_EVENT_HPP_
#define INCLUDE_WINDOW_EVENT_HPP_

#define MAX_KEY_CODE 360

struct GLFWwindow;
typedef void (*GLFWkeyfun)(GLFWwindow* window, int key, int scancode, int action, int mods);

namespace core
{
	enum KEY_CODE;
	class Window;
	class Event
	{
	private:
		GLFWwindow* window;
		//void key_callbac(GLFWwindow* window, int key, int scancode, int action, int mods);
		void setCallbackKey(GLFWkeyfun callback);
		bool* key = new bool[MAX_KEY_CODE];
		char* saveKey = new char[MAX_KEY_CODE];

	public:
		Event(GLFWwindow& addrWindow);
		Event(Window& window);

		~Event();

		/// @brief ��������� ������ �������
		void update();

		/// @brief ��������� ������� �������� ����
		/// @return true - ���� ��������� ������� �� �������� ����, ����� false
		[[nodiscard]] bool close();

		/// @brief ��������� ������ �� ���
		/// @return true - ������, false - ��������
		[[nodiscard]] bool GetMouseLeftButton();

		/// @brief ��������� ������ �� ���
		/// @return true - ������, false - ��������
		[[nodiscard]] bool GetMouseRightButton();

		/// @brief ��������� ��������� �������
		/// @param key ����� ������� ������������ ��������� ���������� GLFW
		/// @return true - ������, false - ��������
		[[nodiscard]] bool stateKey(int key);

		/// @brief ��������� ��������� �������
		/// @param key �������� ������� (������: K_ESCAPE, K_W, K_LEFT_SHIFT � �.�.)
		/// @return true - ������, false - ��������
		[[nodiscard]] bool stateKey(KEY_CODE key);

		[[nodiscard]] bool downKey(int key);
		[[nodiscard]] bool downKey(KEY_CODE key);

		[[nodiscard]] bool upKey(int key);
		[[nodiscard]] bool upKey(KEY_CODE key);
	};
}

#endif // !INCLUDE__WINDOW_EVENT_HPP_