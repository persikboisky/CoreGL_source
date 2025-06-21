#include <iostream>
#include "include/core.hpp"

float vertexes[] = {
	//   x  y  z  r  g  b  u  v
	-1,
	1,
	1,
	1,
	1,
	1,
	0,
	1,
	-1,
	-1,
	1,
	1,
	1,
	1,
	0,
	0,
	1,
	-1,
	1,
	1,
	1,
	1,
	1,
	0,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,

	1,
	1,
	-1,
	1,
	1,
	1,
	1,
	1,
	1,
	-1,
	-1,
	1,
	1,
	1,
	1,
	0,
	-1,
	-1,
	-1,
	1,
	1,
	1,
	0,
	0,
	-1,
	1,
	-1,
	1,
	1,
	1,
	0,
	1,

	-1,
	1,
	1,
	1,
	1,
	1,
	0,
	1,
	-1,
	-1,
	1,
	1,
	1,
	1,
	0,
	0,
	-1,
	-1,
	-1,
	1,
	1,
	1,
	1,
	0,
	-1,
	1,
	-1,
	1,
	1,
	1,
	1,
	1,

	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	-1,
	1,
	1,
	1,
	1,
	1,
	0,
	1,
	-1,
	-1,
	1,
	1,
	1,
	0,
	0,
	1,
	1,
	-1,
	1,
	1,
	1,
	0,
	1,
};

unsigned int indexes[] = {
	0, 1, 2, 0, 2, 3,
	4, 5, 6, 4, 6, 7,
	8, 9, 10, 8, 10, 11,
	12, 13, 14, 12, 14, 15};

int main()
{
	core::Core::Init();

	core::windowInfo winInfo = {};
	winInfo.height = 720;
	winInfo.width = 1280;

	core::Window window = core::Window(winInfo);
	window.setContext();

	core::VAO vaoTriangle = core::VAO(vertexes, sizeof(vertexes), 8);
	vaoTriangle.addAttribute(0, 3, 0);
	vaoTriangle.addAttribute(1, 3, 3);
	vaoTriangle.addAttribute(2, 2, 6);

	core::EBO eboTriangle = core::EBO(indexes, sizeof(indexes));
	eboTriangle.linkVAO(vaoTriangle);

	core::Shader program = core::Shader();
	program.add(core::VERTEX, "./r/main.vert");
	program.add(core::FRAGMENT, "./r/main.frag");
	program.create();

	core::Texture texture = core::Texture("./r/box.png");
	texture.bind(0);

	core::cameraInfo camInfo = {};
	core::Camera cam = core::Camera(camInfo);

	core::fbo::DepthTest(true);

	while (!window.event->close())
	{
		core::math::Matrix4 model = {1.0f};
		model = core::math::Matrix4::getRotate(core::math::radians(core::Core::GetTime() * 30.0f), {1, 0, 0}, model);
		// model = core::math::Matrix4::getTranslate({ 1, 0, 0 }, model);
		// model = core::math::Matrix4::getRotate(core::math::radians(core::Core::GetTime() * 30.0f), { 1, 0, 0 }, model);

		program.use();
		program.UniformMat4(model, "uModel");
		program.UniformCamMat4(cam, window, "uCamMat");
		eboTriangle.draw(core::TRIANGLES);

		window.event->update();
		window.swapBuffers();

		core::fbo::setColor(core::color::BEIGE);
		core::fbo::clearBuffers(core::COLOR_BUFFER, core::DEPTH_BUFFER);
	}

	core::Core::Terminate();
	return 0;
}