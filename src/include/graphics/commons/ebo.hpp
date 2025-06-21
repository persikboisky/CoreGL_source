#ifndef INCLUDE_GRAPHICS_COMMONS_EBO_HPP_
#define INCLUDE_GRAPHICS_COMMONS_EBO_HPP_

#include <vector>

namespace core
{
	enum PRIMITIVE;

	class VAO;

	/// @brief ��������� ��� ������ � ebo
	struct ebo
	{
	private:
		[[maybe_unused]] static std::vector<unsigned int> id;
		[[maybe_unused]] static unsigned int SelectID;

		[[maybe_unused]] static unsigned int SelectVAO;

	public:
		/// @brief �������� ebo �� ��� �����������
		/// @param id ����������
		static void bind(unsigned int id);

		/// @brief ������ ebo
		/// @param indexes ������ ��������
		/// @param sizeOfByte ������ ������� � ������
		/// @return ����������
		static unsigned int create(unsigned int* indexes, unsigned int sizeOfByte);

		/// @brief ������ ebo
		/// @param indexes ������ ��������
		/// @return ����������
		static unsigned int create(std::vector<unsigned int> indexes);

		/// @brief ������ ��������, ��������� ������ �� ����������� vao
		/// @param Primitive �������� ���������
		/// @param nVert ���-�� ������
		static void draw(PRIMITIVE Primitive, unsigned int nVert);

		/// @brief ������ ��������, ��������� ������ �� ����������� vao
		/// @param Primitive �������� ���������
		/// @param ebo ���������� ebo
		/// @param nVert ���-�� ������
		static void draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int nVert);

		/// @brief ������ ��������
		/// @param Primitive �������� ���������
		/// @param ebo ���������� ebo
		/// @param vao ���������� vao
		/// @param nVert ���-�� ������
		static void draw(PRIMITIVE Primitive, unsigned int ebo, unsigned int vao, unsigned int nVert);

		/// @brief ������ ��������
		/// @param Primitive �������� ���������
		/// @param ebo ���������� ebo
		/// @param vao ������ vao
		/// @param nVert ���-�� ������
		static void draw(PRIMITIVE Primitive, unsigned int ebo, VAO& vao, unsigned int nVert);

		/// @brief ������� ebo �� ��� �����������
		/// @param id ����������
		static void Delete(unsigned int id);

		/// @brief ������� ��� ebo
		static void DeleteALL();

		/// @brief ������������� ������ �����, ���� � �������� ��������� �����
		/// @param sizePixel ������ � ��������
		static void setSizePoints(float sizePixel);

		/// @brief ������������� ������ �����, ���� � �������� ��������� �����(��)
		/// @param width ������ � ��������
		static void setWidthLine(float width);
	};

	/// @brief ����� ��� ������ � ebo
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
		/// @brief ����������� ������ ebo � ��� ������
		/// @param indexes ������ ��������
		/// @param sizeOfByte ������ ������� � ������
		EBO(unsigned int* indexes, unsigned int sizeOfByte);

		/// @brief ����������� ������ ebo � ��� ������
		/// @param indexes ������ ��������
		EBO(std::vector<unsigned int> indexes);

		/// @brief ���������� ������� ebo � ��� ������
		~EBO();

		/// @brief ����������� vao � ebo
		/// @param vao ���������� vao
		void linkVAO(unsigned int vao);

		/// @brief ����������� vao � ebo
		/// @param vao ������ vao
		void linkVAO(VAO& vao);

		/// @brief ������ ��������
		/// @param Primitive �������� ���������
		/// @param nVert ���-�� ������ (���� �� �������, ������ ���)
		void draw(PRIMITIVE Primitive, unsigned int nVert = 0);

		/// @brief ������������� ������ �����, ���� � �������� ��������� �����
		/// @param sizePixel ������ � ��������
		void setSizePoints(float sizePixel);

		/// @brief ������������� ������ �����, ���� � �������� ��������� �����(��)
		/// @param width ������ � ��������
		void setWidthLine(float width);
	};
}

#endif // !INCLUDE_GRAPHICS_COMMONS_EBO_HPP_
