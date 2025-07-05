#include "../../../include/graphics/commons/fbo.hpp"
#include "../../../include/util/type.hpp"
#include "../../../include/math/Vectors.hpp"
#define GLEW_STATIC
#include <GL/glew.h>

using namespace core;

int fbo::x = 0;
int fbo::y = 0;
int fbo::width = 600;
int fbo::height = 600;

void fbo::DepthTest(bool flag)
{
	if (flag)
	{
		glEnable(GL_DEPTH_TEST);
	}
	else
	{
		glDisable(GL_DEPTH_TEST);
	}
}

void fbo::update()
{
	glViewport(fbo::x, fbo::y, fbo::width, fbo::height);
}

void fbo::setSize(int width, int height)
{
	fbo::width = width;
	fbo::height = height;
	fbo::update();
}

void fbo::setSize(const size2i& size)
{
	fbo::setSize(size.width, size.height);
}

void fbo::setPos(int x, int y)
{
	fbo::x = x;
	fbo::y = y;
	fbo::update();
}

void fbo::setPos(const pos2i& pos)
{
	fbo::setPos(pos.x, pos.y);
}

void fbo::setColor(color::RGB color, bool normalize)
{
	if (normalize)
	{
		color.red /= 255.0f;
		color.green /= 255.0f;
		color.blue /= 255.0f;
	}

	glClearColor(
		color.red,
		color.green,
		color.blue,
		1.0f
	);
}

void fbo::setColor(color::RGBA color, bool normalize)
{
	if (normalize)
	{
		color.red /= 255.0f;
		color.green /= 255.0f;
		color.blue /= 255.0f;
		color.alpha /= 255.0f;
	}

	glClearColor(
		color.red,
		color.green,
		color.blue,
		color.alpha
	);
}

void fbo::setColor(float red, float green, float blue, float alpha, bool normilize)
{
	if (normilize)
	{
		red /= 255.0f;
		green /= 255.0f;
		blue /= 255.0f;
		alpha /= 255.0f;
	}

	glClearColor(
		red,
		green,
		blue,
		alpha
	);
}

void fbo::setColor(const color::COLOR& color)
{
	fbo::setColor(color::RGBA(color));
}

void fbo::clearBuffers(Buffer buffer1, Buffer buffer2, Buffer buffer3)
{
	Buffer array[3] = { buffer1, buffer2, buffer3 };
	for (unsigned int index = 0; index < 3; index++)
	{
		switch (array[index])
		{
		case COLOR_BUFFER:
			glClear(GL_COLOR_BUFFER_BIT);
			break;

		case DEPTH_BUFFER:
			glClear(GL_DEPTH_BUFFER_BIT);
			break;

		default:
			break;
		}
	}
}
