#ifndef INCLUDE_FILE_CODE_HPP_
#define INCLUDE_FILE_CODE_HPP_

#include <string>

namespace core
{
	/// @brief ��������� ��� ������ � �������
	struct code
	{
		/// @brief ������ ����
		/// @param path ���� � �����
		/// @return ����� �����
		static std::string load(const char* path);
	};
}

#endif // !INCLUDE_FILE_CODE_HPP_