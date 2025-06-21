#ifndef INCLUDE_GRAPHICS_COMMONS_EBO_HPP_
#define INCLUDE_GRAPHICS_COMMONS_EBO_HPP_

#include <vector>

namespace core
{
	enum PRIMITIVE;

	class VAO;

	/// @brief структура дл€ работы с ebo
	struct ebo
	{
	private:
		[[maybe_unused]] static std::vector<unsigned int> id;
		[[maybe_unused]] static unsigned int SelectID;

		[[maybe_unused]] static unsigned int SelectVAO;

	public:
		/// @brief включает ebo по его дескриптору
		/// @param id дескриптор
		static void bind(unsigned int id);

		/// @brief создаЄт ebo
		/// @param indexes массив индексов
		/// @param sizeOfByte размер массива в байтах
		/// @return дескриптор
		static unsigned int create(unsigned int* indexes, unsigned int sizeOfByte);

		/// @brief создаЄт ebo
		/// @param indexes вектор индексов
		/// @return дескриптор
		static unsigned int create(std::vector<unsigned int> indexes);

		/// @brief рисует примитив, использу€ данные из включенного vao
		/// @param Primitive название примитива
		/// @param nVert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int nVert);

		/// @brief рисует примитив, использу€ данные из включенного vao
		/// @param Primitive название примитива
		/// @param ebo дескриптор ebo
		/// @param nVert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int nVert);

		/// @brief рисует примитив
		/// @param Primitive название примитива
		/// @param ebo дескриптор ebo
		/// @param vao дескриптор vao
		/// @param nVert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int vao, unsigned int nVert);

		/// @brief рисует примитив
		/// @param Primitive название примитива
		/// @param ebo дескриптор ebo
		/// @param vao объект vao
		/// @param nVert кол-во вершин
		static void draw(PRIMITIVE Primitive, unsigned int ebo, VAO& vao, unsigned int nVert);

		/// @brief удал€ет ebo по его дескриптору
		/// @param id дескриптор
		static void Delete(unsigned int id);

		/// @brief удал€ет все ebo
		static void DeleteALL();

		/// @brief устанавливает размер точки, если в качестве примитива точка
		/// @param sizePixel размер в пиксел€х
		static void setSizePoints(float sizePixel);

		/// @brief устанавливает ширину линии, если в качестве примитива лини€(ии)
		/// @param width ширина в пиксел€х
		static void setWidthLine(float width);
	};

	/// @brief класс дл€ работы с ebo
	class EBO
	{
	private:
		unsigned int vao;
		VAO* Vao;

		unsigned int id;
		unsigned int nVert;

		char typeVao = ' ';

		float widthLine = 1.0f;
		float sizePoint = 1.0f;

	public:
		/// @brief конструктор создаЄт ebo и его объект
		/// @param indexes массив индексов
		/// @param sizeOfByte размер массива в байтах
		EBO(unsigned int* indexes, unsigned int sizeOfByte);

		/// @brief конструктор создаЄт ebo и его объект
		/// @param indexes вектор индексов
		EBO(std::vector<unsigned int> indexes);

		/// @brief дескриптор удал€ет ebo и его объект
		~EBO();

		/// @brief прив€зывает vao к ebo
		/// @param vao дескриптор vao
		void linkVAO(unsigned int vao);

		/// @brief прив€зывает vao к ebo
		/// @param vao объект vao
		void linkVAO(VAO& vao);

		/// @brief рисует примитив
		/// @param Primitive название примитива
		/// @param nVert кол-во вершин (если не указать, рисует все)
		void draw(PRIMITIVE Primitive, unsigned int nVert = 0);

		/// @brief устанавливает размер точки, если в качестве примитива точка
		/// @param sizePixel размер в пиксел€х
		void setSizePoints(float sizePixel);

		/// @brief устанавливает ширину линии, если в качестве примитива лини€(ии)
		/// @param width ширина в пиксел€х
		void setWidthLine(float width);
	};
}

#endif // !INCLUDE_GRAPHICS_COMMONS_EBO_HPP_
