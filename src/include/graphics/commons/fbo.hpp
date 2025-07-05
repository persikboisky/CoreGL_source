#ifndef INCLUDE_GRAPHICS_COMMONS_FBO_HPP_
#define INCLUDE_GRAPHICS_COMMONS_FBO_HPP_

#include "../../util/type.hpp"

namespace core
{

	struct size2i;
	struct pos2i;

	struct fbo
	{
	private:
		static int x;
		static int y;
		static int width;
		static int height;

		static void update();

	public:

		/// @brief включает Z-буфер
		/// @param flag состояние(true - включенно, false - выключенно)
		static void DepthTest(bool flag);

		/// @brief устанавливает размер буфера кадра для текущего контекста
		/// @param width ширина
		/// @param height высота
		static void setSize(int width, int height);
		static void setSize(const size2i& size);

		static void setPos(int x, int y);
		static void setPos(const pos2i& pos);

		static void setColor(color::RGB color, bool normalize = true);
		static void setColor(color::RGBA color, bool normalize = true);
		static void setColor(float red, float green, float blue, float alpha, bool normalize = true);
		static void setColor(const color::COLOR& color);

		/// @brief чистит указанный(ные) буфер(ы)
		/// @param buffer1 буфер
		/// @param beffer2 буфер (необязательно)
		/// @param buffer3 буфер (необязательно)
		static void clearBuffers(Buffer buffer1, Buffer beffer2 = NONE, Buffer buffer3 = NONE);

		//static unsigned int create(unsigned int idT);
		//static unsigned int create();

	};
}

#endif // !INCLUDE_GRAPHICS_COMMONS_FBO_HPP_
