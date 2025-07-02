#ifndef INCLUDE_CORE_HPP_
#define INCLUDE_CORE_HPP_

#include "window/Window.hpp"
#include "window/Event.hpp"
#include "window/Cursor.hpp"
#include "util/type.hpp"
#include "util/vector.hpp"
#include "util/time.hpp"
#include "util/coders.hpp"
#include "file/png.hpp"
#include "file/code.hpp"
#include "file/bin.hpp"
#include "math/math.hpp"
#include "math/Vectors.hpp"
#include "math/Matrix4.hpp"
#include "graphics/commons/vao.hpp"
#include "graphics/commons/shader.hpp"
#include "graphics/commons/fbo.hpp"
#include "graphics/commons/Camera.hpp"
#include "graphics/commons/ebo.hpp"
#include "graphics/commons/texture.hpp"

namespace core 
{
	struct Core
	{

		/// Инициализирует ядра
		static void Init();

		/// Выключает ядро
		static void Terminate();

		/// @brief Находит время с момента инициализации
		/// @return время с момента инициализации в секундах
		static double GetTime();

	};
}

#endif // !INCLUDE_CORE_HPP_
