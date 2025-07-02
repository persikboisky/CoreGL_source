#ifndef INCLUDE_UTIL_CODERS_HPP
#define INCLUDE_UTIL_CODERS_HPP

#include <string>

namespace core
{
	class coders
	{
	private:
		int code = 0;
		std::string text = "";

	public:
		coders(int code, const std::string& text = "");

		int getCode() const;
		std::string getInfo();
	};
}

#endif // !INCLUDE_UTIL_CODERS_HPP