#include "../../include/file/bin.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

void core::bin::write(const char* path, const char* value, long long size)
{
	std::ofstream file(path, std::ios::binary);
	if (file.is_open())
	{
		file.write(value, size);
	}
	else
	{
		throw "faiflffl";
	}
	file.close();
}

