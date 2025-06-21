#ifndef INCLUDE_MATH_MATH_HPP_
#define INCLUDE_MATH_MATH_HPP_

namespace core
{
	namespace math
	{
		const double PI = 3.141592653589;

		template <class T>
		T degrees(T radians)
		{
			return T(180) / T(PI) * radians;
		}

		template <class T>
		T radians(T degrees)
		{
			return T(PI) / T(180) * degrees;
		}
	}
}

#endif // !INCLUDE_MATH_MATH_HPP_
