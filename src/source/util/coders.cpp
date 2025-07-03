#include "../../include/util/coders.hpp"
#include <string>

const std::string INFO_CODERS[] = {
	"FAILED_INIT_GLFW",		   	// 0x00
	"FAILED_INIT_GLEW"		   	// 0x01
	"FAILED_CREATE_WINDOW"	   	// 0x02
	"FAILED_CREATE_CURSOR_OBJ" 	// 0x03
	"FAILED_CREATE_VAO"		   	// 0x04
	"FAILED_CREATE_VBO_FOR_VAO"	// 0x05
	"FAILED_BIND_VAO"			// 0x06
	"FAILED_ADD_VAO_ATTRIBUTE"	// 0x07
	"FAILED_CREATE_TEXTURE"		// 0x08
	"FAILED_BIND_TEXTURE" 		// 0x09
	"FAILED_INIT_MONITOR"		// 0x0A
};

using namespace core;

coders::coders(int code, const std::string& text) : code(code), text(text)
{
}

int coders::getCode() const
{
	return this->code;
}

std::string coders::getInfo()
{
	return INFO_CODERS[this->code] + "\n" + text;
}
