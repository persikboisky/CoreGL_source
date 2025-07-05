#include <iostream>
#include <vector>
#include "include/core.hpp"

using namespace core;

std::vector<float> vertexes;

int main()
{
	int  count = 0;
	const float Z = 0.0;
	for (float a = 0; a < math::PI * 2.0f; a += 1)
	{

		if (count % 2 == 0)
		{
			// центр
			vertexes.push_back(0.0f);
			vertexes.push_back(0.0f);
			vertexes.push_back(Z);

			vertexes.push_back(1.0f);
			vertexes.push_back(1.0f);
			vertexes.push_back(1.0f);
		}

		vertexes.push_back((float)sin(a));
		vertexes.push_back((float)cos(a));
		vertexes.push_back(Z);

		vertexes.push_back(1.0f);
		vertexes.push_back(1.0f);
		vertexes.push_back(1.0f);

		count++;
	}

	Core::Init();

	windowInfo winInfo = { };
	winInfo.width = 1280;
	winInfo.height = 720;
	winInfo.debugInfo = true;
	winInfo.title = "test";
	winInfo.VerticalSynchronization = true;
	winInfo.posX = 500;
	winInfo.posY = 100;
	winInfo.resizable = false;

	Window win = Window::create(winInfo);
	win.setContext();
	
	fbo::DepthTest(true);
	fbo::setColor(color::BLACK);

	VAO triangle = VAO(vertexes, 6);
	triangle.addAttribute(0, 3, 0);
	triangle.addAttribute(1, 3, 3);

	Shader program = Shader();
	program.add(VERTEX, "./main.vert");
	program.add(FRAGMENT, "./main.frag");
	program.create();

	cameraInfo camInfo = {};
	camInfo.mode = CAM_DYNAMIC;
	camInfo.position = math::Vector3{ 0, 0, -4 };
	camInfo.target = math::Vector3{ 0, 0, -5 };
	Camera cam = Camera(camInfo);

	while (!win.event->close())
	{
		math::Matrix4 model = math::Matrix4(1.0f);

		program.use();
		program.UniformMat4(model, "model");
		program.Uniform1F((float)Core::GetTime(), "uTime");
		program.UniformCamMat4(cam, win, "cam");
		triangle.draw(TRIANGLES);

		win.event->update();
		win.swapBuffers();
		win.setSizeBuffer(win.getSize());
		fbo::clearBuffers(COLOR_BUFFER, DEPTH_BUFFER);

		cam.move({ -0.001, 0.001, 0.001 });
	}

	Core::Terminate();
	return 0;
}