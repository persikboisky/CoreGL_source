#include "../../include/util/time.hpp"
#include <GLFW/glfw3.h>
#include <ctime>
#include <string>

using namespace core;

const std::string dateList[7] = {
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday",
    "Sunday"};

Timer::Timer() : time(0.0), interval(0.0)
{
}

[[nodiscard]] Timer Timer::create()
{
    return Timer::Timer();
}

Timer::~Timer()
{
}

void Timer::run()
{
    this->time = glfwGetTime();
}

void Timer::stop()
{
    this->interval += glfwGetTime() - this->time;
}

void Timer::reset()
{
    this->interval = 0.0;
}

[[nodiscard]] double core::Timer::getTime()
{
    return this->interval;
}

void Timer::setTime(double time)
{
    this->interval = time;
}

void Timer::addTime(double time)
{
    this->interval += time;
}

void Timer::difTime(double time)
{
    this->interval -= time;
}

static inline tm getObjTime()
{
    time_t now = time(0);
    return *localtime(&now);
}

[[nodiscard]] int data::getHours()
{
    return getObjTime().tm_hour;
}

[[nodiscard]] int data::getMinutes()
{
    time_t now = time(0);
    tm ltm = *localtime(&now);
    return ltm.tm_min;
}

[[nodiscard]] int data::getSeconds()
{
    time_t now = time(0);
    tm ltm = *localtime(&now);
    return ltm.tm_sec;
}

[[nodiscard]] int data::getMDay()
{
    return getObjTime().tm_mday;
}

[[nodiscard]] int data::getYDay()
{
    return getObjTime().tm_yday;
}

[[nodiscard]] int data::getWDay()
{
    return getObjTime().tm_wday;
}

[[nodiscard]] std::string data::getWDayToSTR()
{
    return dateList[data::getWDay()];
}

[[nodiscard]] int data::getYear()
{
    return getObjTime().tm_year;
}