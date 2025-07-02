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
		/// @brief возвращает объект окна, тип GLFWwindow
		GLFWwindow* getGlfwWindowObject();

		Event* event = nullptr;
		Cursor* cursor = nullptr;

		/// @brief текуща€ ширина окна (обновл€етс€ при вызове swapBuffers)
		int width;

		/// @brief текуща€ высота окна (обновл€етс€ при вызове swapBuffers)
		int height;

		/// @brief конструктор окна (создаЄт окно и его объект)
		/// @param width     ширина 
		/// @param height    высота 
		/// @param title     заголовок
		/// @param resizable разрешение на изменение размера окна
		Window(int width, int height, const char* title = "", bool resizable = true);
		Window(const windowInfo& info);

		~Window();

		/// @brief смен€ет буферы кадра.
		/// ¬ openGL два буфера на одном мы рисуем, другой отображаетс€ на экране.
		/// swapBuffers() - мен€€ет буферы местами.
		/// “еперь отображаетс€ тот, на котором мы рисовали,
		/// а рисуем мы на том, который отображалс€.
		/// –асписал как мог : )
		void swapBuffers();

		/// @brief устанавливает иконку дл€ окна
		/// @param path путь к png картинке
		void setIcon(const char* path);

		/// @brief вызывает событие закрыти€ окна
		void close();

		/// @brief делает окна контекстом (“о где мы рисуем)
		void setContext();

		/// @brief устанавливает размер буфера кадра
		/// @param width  ширина
		/// @param height высота
		void setSizeBuffer(int width, int height);

		/// @brief провер€ет €вл€етс€ ли окно контекстом
		/// @return true - если €вл€етс€, false - если не €вл€етс€
		bool isContext();

		void VerticalSynchronization(bool flag);
	};
}

#endif // !INCLUDE_WINDOW_WINDOW_HPP_
