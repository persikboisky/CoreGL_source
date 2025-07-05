#include "../../include/util/console.hpp"
#include <iostream>
#include <Windows.h>
#include <cstdlib>

using namespace core;

void core::console::printTime()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	std::cout << '[';
	std::cout << st.wHour << ':';
	std::cout << st.wMinute << ':';
	std::cout << st.wSecond << "] -> ";
}
