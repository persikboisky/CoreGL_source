#ifndef INCLUDE_MATH_MATRIX4_HPP_
#define INCLUDE_MATH_MATRIX4_HPP_

namespace core
{
	namespace math
	{
		class Vector4;
		class Vector3;

		/// @brief ����� ��� ������ � ��������� 4x4
		class Matrix4 final
		{
		private:
			float mat[16];

		public:
			/// @brief ����������� �������, ������ �������
			/// @param diagonal ��������, ������� ����������� �� ��������� �������
			Matrix4(float diagonal = 1.0f);

			/// @brief ����������� �������, ������ �������
			/// @param mat4 ������[16], � ���� �������
			Matrix4(float mat4[16]);

			/// @brief ���������� ������ �������
			/// @return float[16]
			[[nodiscard]] float* getArray();

			/// @brief ����������� �������
			/// @param mat1 ������ ������ �������
			/// @param mat2 ������ ������ �������
			/// @return float[16] 
			[[nodiscard]] static float* multiply(float mat1[16], float mat2[16]);

			/// @brief �������� ������ �� �������
			/// @param vec ������������ ������ (����������)
			/// @param mat �������
			/// @return ������������ ������ (����������)
			[[nodiscard]] static Vector4 multiply(Vector4 vec, float mat[16]);

			[[nodiscard]] auto operator * (Matrix4 mat4) -> Matrix4;
			[[nodiscard]] auto operator * (Vector4 vec4) -> Vector4;

			[[nodiscard]] void operator *= (Matrix4 mat4);
			[[nodiscard]] void operator = (Matrix4 mat4);
			[[nodiscard]] void operator = (float mat4[16]);

			/// @brief ������ ������� ���������������
			/// @param vecScale ������ ������������� ��������������� 
			/// @return ������� ���������������
			[[nodiscard]] static Matrix4 getScale(const Vector3& vecScale, const Matrix4& mat4 = Matrix4(1.0f));

			/// @brief ������ ������� �����������
			/// @param vecTranslate ������ �����������
			/// @return ������� �����������
			[[nodiscard]] static Matrix4 getTranslate(const Vector3& vecTranslate, const Matrix4& mat4 = Matrix4(1.0f));

			/// @brief ������ ������� ��������
			/// @param angle ���� �������� � ��������
			/// @param axises ������ ���� �������� (������: math::vector3(1, 0, 0) - �������� ������� �� ��� x � z);
			/// @return ������� ��������
			[[nodiscard]] static Matrix4 getRotate(float angle, const Vector3& axises, const Matrix4& mat4 = Matrix4(1.0f));

			/// @brief ������ ������������� �������
			/// @param fovToRadians ���� ������ � ��������
			/// @param aspect ����������� ������ (������ ���� / ������ ����)
			/// @param near ������� ��������� ����� (������ 0.01)
			/// @param far ������� ��������� ����� (��� ��������� ����������)
			/// @return ������������� �������
			[[nodiscard]] static Matrix4 getPerspective(float fovToRadians, float aspect, float near, float far);

			/// @brief ������ ������� �������
			/// @param pos ������� (�������� �������)
			/// @param target ���� (���� �������)
			/// @param up ���� (������: math::Vector3(0, 1, 0) - �������� ��� ���� ��������� � ���� Y)
			/// @return ������� �������
			[[nodiscard]] static Matrix4 getLookAt(Vector3 pos, Vector3 target, Vector3 up);
		};
	}
}
#endif // !INCLUDE_MATH_MATRIX4_HPP_