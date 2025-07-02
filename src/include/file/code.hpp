#ifndef INCLUDE_FILE_CODE_HPP_
#define INCLUDE_FILE_CODE_HPP_

#include <string>

namespace core
{
	/// @brief ��������� ��� ������ � �������
	namespace code
	{
		/// @brief ������ ����
		/// @param path ���� � �����
		/// @return ����� �����
		std::string load(const char* path);

		void write(const char* path, const std::string& code);
	}
}

#endif // !INCLUDE_FILE_CODE_HPP_