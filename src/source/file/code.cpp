#include "../../include/file/code.hpp"
#include "../../include/config.hpp"
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::string core::code::load(const char* path)
{
    std::string text = "";
    std::ifstream file(path, std::ios::in);
    if (file.is_open())
    {
        std::stringstream sstr;
        sstr << file.rdbuf();
        text = sstr.str();
        file.close();
    }
    else
    {
        std::cerr << "Failed read file: " << path << std::endl;
        throw "FAILED_READ_FILE";
    }

    if (CORE_INFO) std::cout << "[" << glfwGetTime() << "] "
        << "OK: read file: " << path << std::endl;

    return text;
}

void core::code::write(const char* path, const std::string& code)
{
    std::ofstream file(path, std::ios::out);
    if (file.is_open())
    {
        file << code;
    }
    else
    {
        throw "failed";
    }
    file.close();
}
