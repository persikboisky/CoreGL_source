#include "../../../include/graphics/commons/fbo.hpp"
#include "../../../include/util/type.hpp"
#include "../../../include/math/Vectors.hpp"
#define GLEW_STATIC
#include <GL/glew.h>

using namespace core;

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

void fbo::setSize(int width, int height)
{
	glViewport(0, 0, width, height);
}

void core::fbo::setSize(math::Vector2 size)
{
	fbo::setSize(size.x, size.y);
}

void fbo::setColor(color::RGB color, bool normilize)
{
	if (normilize)
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

void fbo::setColor(color::RGBA color, bool normilize)
{
	if (normilize)
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
