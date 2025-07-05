#ifndef INCLUDE_GRAPHICS_VAO_HPP_
#define INCLUDE_GRAPHICS_VAO_HPP_

#include <vector>

namespace core
{
	enum PRIMITIVE;
	class VAO;

	/// @brief структура для работы с vao
	struct vao
	{
	private:
		static std::vector<unsigned int> idVAO;
		static std::vector<unsigned int> idVBO;
		static unsigned int selectID;

	protected:
		static unsigned int getSelectId();

	public:
		/// @brief включает VAO по его дескриптору
		/// @param id дескриптор VAO
		static void bind(unsigned int id);

		/// @brief создаёт vao
		/// @param data массив данных
		/// @param sizeOfByte размер массива в байтах
		/// @return дескриптор созданного vao
		[[nodiscard]] static unsigned int create(float* data, int sizeOfByte);

		/// @brief создаёт vao
		/// @param data вектор данных
		/// @return дескриптор созданного vao
		[[nodiscard]] static unsigned int create(std::vector<float> data);

		/// @brief добавляет вершинный атрибут
		/// @param id дескриптор vao
		/// @param index номер атрибута
		/// @param n кол-во элементов на один атрибут
		/// @param size кол-во элементов на одну вершину
		/// @param indentation с какого элемента начинать отсчёт
		static void addAttribute(unsigned int id, int index, int n, int size, int indentation);

		/// @brief удаляет vao по его дескриптору
		/// @param id дескриптор
		static void Delete(unsigned int id);

		/// @brief удаляет все vao
		static void DeleteALL();

		/// @brief рисует примитив согласто включенному vao
		/// @param Primitive название примитива
		/// @param first_vert номер первой вершины
		/// @param count_vert кол-во вершин
		static void draw(PRIMITIVE Primitive, int first_vert, int count_vert);

		/// @brief рисует примитив
		/// @param Primitive название примитива
		/// @param VAO дескриптор vao
		/// @param first_vert номер первой вершины
		/// @param count_vert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int VAO, int first_vert, int count_vert);

		/// @brief устанавливает размер точки, если в качестве примитива точка
		/// @param sizePixel размер в пикселях
		static void setSizePoints(float sizePixel);

		/// @brief устанавливает ширину линии, если в качестве примитива линия(ии)
		/// @param width ширина в пикселях
		static void setWidthLine(float width);
	};

	/// @brief класс для создания объектов VAO
	class VAO : private vao
	{
	private:
		unsigned int id = 0;
		unsigned int elementToVert;
		int size;

		float widthLine = 1.0f;
		float sizePoint = 1.0f;

	public:
		/// @brief конструктор создаёт vao и его объект
		/// @param data массив данных
		/// @param sizeOfByte размер массива в байтах
		/// @param elementToVert кол-во элементов на одну вершину
		VAO(float* data, int sizeOfByte, int elementToVert);

		/// @brief конструктор создаёт vao и его объект
		/// @param data вектор данных
		/// @param elementToVert кол-во элементов на одну вершину
		VAO(std::vector<float> data, int elementToVert);

		/// @brief дескриптор уничтожает vao и его объект
		~VAO();

		/// @brief включает vao
		void bind() const;

		/// @brief добавляет вершинный атрибут
		/// @param index номер атрибута
		/// @param n кол-во элементов на один атрибута
		/// @param indentation с какого элемента начинать отсчёт
		void addAttribute(int index, int n, int indentation) const;

		/// @brief рисует примитив
		/// @param Primitive название примитива
		/// @param first_vert номер первой вершины (если не указать, рисует все)
		/// @param count_vert кол-во вершин (если не указать, рисует все)
		void draw(PRIMITIVE Primitive, int first_vert = 0, int count_vert = 0) const;

		/// @brief устанавливает размер точки, если в качестве примитива точка
		/// @param sizePixel размер в пикселях
		void setSizePoints(float sizePixel);

		/// @brief устанавливает ширину линии, если в качестве примитива линия(ии)
		/// @param width ширина в пикселях
		void setWidthLine(float width);
	};
}

#endif // !INCLUDE_GRAPHICS_VAO_HPP_
