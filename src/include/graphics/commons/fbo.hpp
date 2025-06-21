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
		/// @brief включает Z-буфер
		/// @param flag состояние(true - включенно, false - выключенно)
		static void DepthTest(bool flag);

		/// @brief устанавливает размер буфера кадра для текущего контекста
		/// @param width ширина
		/// @param height высота
		static void setSize(int width, int height);
		static void setSize(math::Vector2 size);

		static void setColor(color::RGB color, bool normilize = true);
		static void setColor(color::RGBA color, bool normilize = true);
		static void setColor(float red, float green, float blue, float alpha, bool normilize = true);
		static void setColor(const color::COLOR& color);

		/// @brief чистит указанный(ные) буфер(ы)
		/// @param buffer1 буфер
		/// @param beffer2 буфер (необязательно)
		/// @param buffer3 буфер (необязательно)
		static void clearBuffers(Buffer buffer1, Buffer beffer2 = NONE, Buffer buffer3 = NONE);

		static unsigned int create(unsigned int idT);
		static unsigned int create();

	};
}

#endif // !INCLUDE_GRAPHICS_COMMONS_FBO_HPP_
