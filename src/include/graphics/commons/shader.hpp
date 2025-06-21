#ifndef INCLUDE_GRAPHICS_COMMONS_SHADER_HPP_
#define INCLUDE_GRAPHICS_COMMONS_SHADER_HPP_

#include "../../util/type.hpp"
#include <vector>

namespace core
{
	namespace math
	{
		class Matrix4;
		class Vector2;
		class Vector3;
		class Vector4;
	}

	class Camera;
	class Window;

	/// @brief структура для работы с шейдерами
	struct shader
	{
	private:
		static std::vector<unsigned int> id;
		static unsigned int SelectID;

		static unsigned int vID;
		static unsigned int gID;
		static unsigned int fID;

	protected:
		static unsigned int getSelectID();

	public:
		/// @brief создаёт шейдерную программу
		/// @param codeVert код вершинного шейдера
		/// @param codeFrag код фрагментного шейдера
		/// @return возвращает дескриптор шейдерной программы
		[[nodiscard]] static unsigned int createProgramFromCode(const char* codeVert, const char* codeFrag);

		/// @brief создаёт шейдерную программу
		/// @param pathToVert путь к вршинному шейдеру
		/// @param pathToFrag путь к вршинному шейдеру
		/// @return возвращает дескриптор шейдерной программы
		[[nodiscard]] static unsigned int createProgramFromFile(const char* pathToVert, const char* pathToFrag);

		/// @brief компилирует шейдер во временное хранилище
		/// @param type тип шейдера (FRAGMENT, GEOMETRY, VERTEX)
		/// @param code код шейдера
		static void compileFromCode(TYPE_SHADER type, const char* code);

		/// @brief компилирует шейдер во временное хранилище
		/// @param type тип шейдера (FRAGMENT, GEOMETRY, VERTEX)
		/// @param path путь к шейдеру
		static void compileFromFile(TYPE_SHADER type, const char* path);

		/// @brief создаёт шейдерную программу, из шейдеров записанных во временное хранилище
		/// @return возвращает дескриптор шейдерной программы
		[[nodiscard]] static unsigned int createProgram();

		/// @brief активирует шейдерную программу
		/// @param id дескриптор шейдерной программы
		static void use(unsigned int id);

		/// @brief передаёт матрицу в юниформ переменную шейдера
		/// @param matrix 
		/// @param name 
		static void UniformMat4(math::Matrix4 matrix, const char* name);

		static void UniformCamMat4(Camera camera, int windowWidth, int windowHeight, const char* name);

		/// @brief ������� �������� ���� float � ������� ���������� �������
		/// @param value �������� ���� float 
		/// @param name �������� ������� ����������
		static void Uniform1F(const float value, const char* name);

		/// @brief ������� math::Vector2 � ������� ���������� ����������� �������
		/// @param vec2 ������
		/// @param name �������� ������� ����������
		static void Uniform2F(core::math::Vector2 vec2, const char* name);

		/// @brief ������� math::Vector3 � ������� ���������� ����������� �������
		/// @param vec3 ������
		/// @param name �������� ������� ����������
		static void Uniform3F(core::math::Vector3 vec3, const char* name);

		/// @brief ������� math::Vector4 � ������� ���������� ����������� �������
		/// @param vec4 ������
		/// @param name �������� ������� ����������
		static void Uniform4F(core::math::Vector4 vec4, const char* name);

		/// @brief ������� �������� ���� Sampler2D � ������� ���������� �������
		/// @param value �������� ���� Sampler2D
		/// @param name �������� ������� ����������
		static void UniformSample2D(int value, const char* name);

		static void UniformRGBA(const color::RGBA& color, const char* name);

		static void UniformRGB(const color::RGB& color, const char* name);

		/// @brief ������� ������ �� ��� �����������
		/// @param id ����������
		static void Delete(unsigned int id);

		/// @brief ������� ��� �������
		static void DeleteALL();
	};

	/// @brief ����� ��� ������ � ���������
	class Shader : private shader
	{
	private:
		unsigned int id;

	public:
		/// @brief �����������, ������ ������
		/// @param pathVert ���� � ���������� �������
		/// @param pathFrag ���� � ������������ �������
		Shader(const char* pathVert, const char* pathFrag);

		Shader();

		void add(TYPE_SHADER type, const char* path);
		void create();

		/// @brief ������� ������ � ��� ������
		~Shader();

		/// @brief �������� ���������� �������
		/// @return ����������
		unsigned int getID() const;

		/// @brief �������� ������
		void use() const;

		/// @brief ������� ������� � ������� ���������� �������
		/// @param matrix �������
		/// @param name �������� ������� ����������
		void UniformMat4(math::Matrix4 matrix, const char* name) const;

		void UniformCamMat4(const Camera& camera, int windowWidth, int windowHeight, const char* name) const;

		void UniformCamMat4(const Camera& camera, const Window& window, const char* name) const;

		/// @brief ������� �������� ���� float � ������� ���������� �������
		/// @param value �������� ���� float 
		/// @param name �������� ������� ����������
		void Uniform1F(const float value, const char* name) const;

		/// @brief ������� math::Vector2 � ������� ���������� �������
		/// @param vec2 ������
		/// @param name �������� ������� ����������
		void Uniform2F(core::math::Vector2 vec2, const char* name) const;

		/// @brief ������� math::Vector3 � ������� ���������� �������
		/// @param vec3 ������
		/// @param name �������� ������� ����������
		void Uniform3F(core::math::Vector3 vec3, const char* name) const;

		/// @brief ������� math::Vector4 � ������� ���������� �������
		/// @param vec4 ������
		/// @param name �������� ������� ����������
		void Uniform4F(core::math::Vector4 vec4, const char* name) const;

		/*void Uniform1I(glm::ivec1 value, const char* name) const;
		void Uniform2I(glm::ivec2 value, const char* name) const;*/

		/// @brief ������� �������� ���� Sampler2D � ������� ���������� �������
		/// @param value �������� ���� Sampler2D
		/// @param name �������� ������� ����������		
		void UniformSample2D(int value, const char* name) const;

		void UniformRGBA(const color::RGBA& color, const char* name) const;

		void UniformRGB(const color::RGB& color, const char* name) const;
	};
}

#endif // !INCLUDE_GRAPHICS_COMMONS_SHADER_HPP_
