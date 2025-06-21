#ifndef INCLUDE_GRAPHICS_COMMONS_FBO_HPP_
#define INCLUDE_GRAPHICS_COMMONS_FBO_HPP_

#include "../../util/type.hpp"

namespace core
{

	namespace math
	{
		class Vector2;
	}

	struct fbo
	{
		/// @brief �������� Z-�����
		/// @param flag ���������(true - ���������, false - ����������)
		static void DepthTest(bool flag);

		/// @brief ������������� ������ ������ ����� ��� �������� ���������
		/// @param width ������
		/// @param height ������
		static void setSize(int width, int height);
		static void setSize(math::Vector2 size);

		static void setColor(color::RGB color, bool normilize = true);
		static void setColor(color::RGBA color, bool normilize = true);
		static void setColor(float red, float green, float blue, float alpha, bool normilize = true);
		static void setColor(const color::COLOR& color);

		/// @brief ������ ���������(���) �����(�)
		/// @param buffer1 �����
		/// @param beffer2 ����� (�������������)
		/// @param buffer3 ����� (�������������)
		static void clearBuffers(Buffer buffer1, Buffer beffer2 = NONE, Buffer buffer3 = NONE);

		static unsigned int create(unsigned int idT);
		static unsigned int create();

	};
}

#endif // !INCLUDE_GRAPHICS_COMMONS_FBO_HPP_
