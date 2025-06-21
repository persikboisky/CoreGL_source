#ifndef INCLUDE_MATH_VECTORS_HPP_
#define INCLUDE_MATH_VECTORS_HPP_

namespace core
{
	namespace math
	{
		class Vector2;
		class Vector3;
		class Vector4;
		class Matrix4;

		class Vector2 final
		{
		public:
			float x;
			float y;

			Vector2();
			Vector2(float x, float y = 0);
			Vector2(const Vector2& vec2);

			Vector2 operator+(const Vector2& vec2);
			Vector2 operator-(const Vector2& vec2);
			Vector2 operator*(const Vector2& vec2);
			Vector2 operator/(const Vector2& vec2);

			Vector2 operator*(const float& value);
			Vector2 operator/(const float& value);

			void operator+=(const Vector2& vec2);
			void operator-=(const Vector2& vec2);
			void operator*=(const Vector2& vec2);
			void operator/=(const Vector2& vec2);

			bool operator==(const Vector2& vec2);
			bool operator>(const Vector2& vec2);
			bool operator<(const Vector2& vec2);
			bool operator>=(const Vector2& vec2);
			bool operator<=(const Vector2& vec2);

			void operator=(const Vector2& vec2);

			/// @brief ������� ����������������� ������
			/// @param vec2 ������
			/// @return ����������������� ������
			static Vector2 normalize(const Vector2& vec2);

			/// @brief ������� ����� �������
			/// @param vec2 ������
			/// @return ����� �������
			static float length(const Vector2& vec2);

			/// @brief ������� ��������� ������������ ��������
			/// @param vec2_1 ������ ������
			/// @param vec2_2 ������ ������
			/// @return ��������� ������������ ��������
			static float dot(const Vector2& vec2_1, const Vector2& vec2_2);

			/// @brief ������� ��������� ����� ����� �������
			/// @param vec2_1 ������ ������
			/// @param vec2_2 ������ ������
			/// @return ��������� ����� ����� �������
			static float distance(const Vector2& vec2_1, const Vector2& vec2_2);

			/// @brief ������� ����������������� ������
			/// @return ����������������� ������
			Vector2 normalize();

			/// @brief ������������� ������
			void normal();

			/// @brief ������� ����� �������
			/// @return ����� �������
			float length() const;

			/// @brief ������� ��������� ������������ ��������
			/// @param vec2 ������
			/// @return ��������� ������������ ��������
			float dot(const Vector2& vec2) const;

			/// @brief ������� ��������� ����� ����� �������
			/// @param vec2 ������
			/// @return ��������� ����� ����� �������
			float distance(const Vector2& vec2) const;

			static bool sloped(const Vector2& vec2_1, const Vector2& vec2);
			bool sloped(const Vector2& vec2) const;
		};

		class Vector3 final
		{
		public:
			float x;
			float y;
			float z;

			Vector3();
			Vector3(float x, float y = 0.0f, float z = 0.0f);
			Vector3(const Vector4& vec4);

			Vector3 operator+(const Vector3& vec3);
			Vector3 operator-(const Vector3& vec3);
			Vector3 operator*(const Vector3& vec3);
			Vector3 operator/(const Vector3& vec3);

			Vector3 operator*(const float& value);
			Vector3 operator/(const float& value);

			void operator+=(const Vector3& vec3);
			void operator-=(const Vector3& vec3);
			void operator*=(const Vector3& vec3);
			void operator/=(const Vector3& vec3);

			bool operator==(const Vector3& vec3);
			bool operator>(const Vector3& vec3);
			bool operator<(const Vector3& vec3);
			bool operator>=(const Vector3& vec3);
			bool operator<=(const Vector3& vec3);

			void operator=(const Vector3& vec3);

			/// @brief ������� ����������������� ������
			/// @param vec3 ������
			/// @return ����������������� ������
			static Vector3 normalize(const Vector3& vec3);

			/// @brief ������� ��������� ������������
			/// @param vec3_1 ������ ������
			/// @param vec3_2 ������ ������
			/// @return ��������� ������������
			static Vector3 cross(const Vector3& vec3_1, const Vector3& vec3_2);

			/// @brief ������� ����� �������
			/// @param vec3 ������
			/// @return ����� �������
			static float length(const Vector3& vec3);

			/// @brief ������� ��������� ������������ ��������
			/// @param vec3_1 ������ ������
			/// @param vec3_2 ������ ������
			/// @return ��������� ������������ ��������
			static float dot(const Vector3& vec3_1, const Vector3& vec3_2);

			/// @brief ������� ��������� ����� ����� �������
			/// @param vec3_1 ������ ������
			/// @param vec3_2 ������ ������
			/// @return ��������� ����� ����� �������
			static float distance(const Vector3& vec3_1, const Vector3& vec3_2);

			/// @brief ������� ����������������� ������
			/// @return ����������������� ������
			Vector3 normalize();

			/// @brief ������������� ������
			void normal();

			/// @brief ������� ����� �������
			/// @return ����� �������
			float length() const;

			/// @brief ������� ��������� ������������ ��������
			/// @param vec3 ������
			/// @return ��������� ������������ ��������
			float dot(const Vector3& vec3) const;

			/// @brief ������� ��������� ����� ����� �������
			/// @param vec3 ������
			/// @return ��������� ����� ����� �������
			float distance(const Vector3& vec3) const;
		};

		class Vector4 final
		{
		public:
			float x;
			float y;
			float z;
			float w;

			Vector4();
			Vector4(const Vector4& vec4);
			Vector4(float x, float y = 0.0f, float z = 0.0f, float w = 1.0f);
			Vector4(const Vector3& vec3, float w = 1.0f);

			Vector4 operator+(const Vector4& vec4);
			Vector4 operator-(const Vector4& vec4);
			Vector4 operator*(const Vector4& vec4);
			Vector4 operator/(const Vector4& vec4);

			Vector4 operator*(const float& value);
			Vector4 operator/(const float& value);

			void operator+=(const Vector4& vec4);
			void operator-=(const Vector4& vec4);
			void operator*=(const Vector4& vec4);
			void operator/=(const Vector4& vec4);

			bool operator==(const Vector4& vec4);
			bool operator>(const Vector4& vec4);
			bool operator<(const Vector4& vec4);
			bool operator>=(const Vector4& vec4);
			bool operator<=(const Vector4& vec4);

			void operator=(const Vector4& vec4);

			/// @brief ������� ����������������� ������
			/// @param vec4 ������
			/// @return ����������������� ������
			static Vector4 normalize(const Vector4& vec4);

			/// @brief ������� ����� �������
			/// @param vec4 ������
			/// @return ����� �������
			static float length(const Vector4& vec4);

			/// @brief ������� ��������� ������������ ��������
			/// @param vec4_1 ������ ������
			/// @param vec4_2 ������ ������
			/// @return ��������� ������������ ��������
			static float dot(const Vector4& vec4_1, const Vector4& vec4_2);

			/// @brief ������� ��������� ����� ����� �������
			/// @param vec4_1 ������ ������
			/// @param vec4_2 ������ ������
			/// @return ��������� ����� ����� �������
			static float distance(const Vector4& vec4_1, const Vector4& vec4_2);

			/// @brief ������� ����������������� ������
			/// @return ����������������� ������
			Vector4 normalize();

			/// @brief ������������� ������
			void normal();

			/// @brief ������� ����� �������
			/// @return ����� �������
			float length() const;

			/// @brief ������� ��������� ������������ ��������
			/// @param vec4 ������
			/// @return ��������� ������������ ��������
			float dot(const Vector4& vec4) const;

			/// @brief ������� ��������� ����� ����� �������
			/// @param vec4 ������
			/// @return ��������� ����� ����� �������
			float distance(const Vector4& vec4) const;

			auto operator*(Matrix4 mat4) -> Vector4;
		};
	}
}

#endif // !INCLUDE_MATH_VECTORS_HPP_
