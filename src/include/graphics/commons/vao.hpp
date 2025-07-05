#ifndef INCLUDE_GRAPHICS_VAO_HPP_
#define INCLUDE_GRAPHICS_VAO_HPP_

#include <vector>

namespace core
{
	enum PRIMITIVE;
	class VAO;

	/// @brief ��������� ��� ������ � vao
	struct vao
	{
	private:
		static std::vector<unsigned int> idVAO;
		static std::vector<unsigned int> idVBO;
		static unsigned int selectID;

	protected:
		static unsigned int getSelectId();

	public:
		/// @brief �������� VAO �� ��� �����������
		/// @param id ���������� VAO
		static void bind(unsigned int id);

		/// @brief ������ vao
		/// @param data ������ ������
		/// @param sizeOfByte ������ ������� � ������
		/// @return ���������� ���������� vao
		[[nodiscard]] static unsigned int create(float* data, int sizeOfByte);

		/// @brief ������ vao
		/// @param data ������ ������
		/// @return ���������� ���������� vao
		[[nodiscard]] static unsigned int create(std::vector<float> data);

		/// @brief ��������� ��������� �������
		/// @param id ���������� vao
		/// @param index ����� ��������
		/// @param n ���-�� ��������� �� ���� �������
		/// @param size ���-�� ��������� �� ���� �������
		/// @param indentation � ������ �������� �������� ������
		static void addAttribute(unsigned int id, int index, int n, int size, int indentation);

		/// @brief ������� vao �� ��� �����������
		/// @param id ����������
		static void Delete(unsigned int id);

		/// @brief ������� ��� vao
		static void DeleteALL();

		/// @brief ������ �������� �������� ����������� vao
		/// @param Primitive �������� ���������
		/// @param first_vert ����� ������ �������
		/// @param count_vert ���-�� ������
		static void draw(PRIMITIVE Primitive, int first_vert, int count_vert);

		/// @brief ������ ��������
		/// @param Primitive �������� ���������
		/// @param VAO ���������� vao
		/// @param first_vert ����� ������ �������
		/// @param count_vert ���-�� ������
		static void draw(PRIMITIVE Primitive, unsigned int VAO, int first_vert, int count_vert);

		/// @brief ������������� ������ �����, ���� � �������� ��������� �����
		/// @param sizePixel ������ � ��������
		static void setSizePoints(float sizePixel);

		/// @brief ������������� ������ �����, ���� � �������� ��������� �����(��)
		/// @param width ������ � ��������
		static void setWidthLine(float width);
	};

	/// @brief ����� ��� �������� �������� VAO
	class VAO : private vao
	{
	private:
		unsigned int id = 0;
		unsigned int elementToVert;
		int size;

		float widthLine = 1.0f;
		float sizePoint = 1.0f;

	public:
		/// @brief ����������� ������ vao � ��� ������
		/// @param data ������ ������
		/// @param sizeOfByte ������ ������� � ������
		/// @param elementToVert ���-�� ��������� �� ���� �������
		VAO(float* data, int sizeOfByte, int elementToVert);

		/// @brief ����������� ������ vao � ��� ������
		/// @param data ������ ������
		/// @param elementToVert ���-�� ��������� �� ���� �������
		VAO(std::vector<float> data, int elementToVert);

		/// @brief ���������� ���������� vao � ��� ������
		~VAO();

		/// @brief �������� vao
		void bind() const;

		/// @brief ��������� ��������� �������
		/// @param index ����� ��������
		/// @param n ���-�� ��������� �� ���� ��������
		/// @param indentation � ������ �������� �������� ������
		void addAttribute(int index, int n, int indentation) const;

		/// @brief ������ ��������
		/// @param Primitive �������� ���������
		/// @param first_vert ����� ������ ������� (���� �� �������, ������ ���)
		/// @param count_vert ���-�� ������ (���� �� �������, ������ ���)
		void draw(PRIMITIVE Primitive, int first_vert = 0, int count_vert = 0) const;

		/// @brief ������������� ������ �����, ���� � �������� ��������� �����
		/// @param sizePixel ������ � ��������
		void setSizePoints(float sizePixel);

		/// @brief ������������� ������ �����, ���� � �������� ��������� �����(��)
		/// @param width ������ � ��������
		void setWidthLine(float width);
	};
}

#endif // !INCLUDE_GRAPHICS_VAO_HPP_
