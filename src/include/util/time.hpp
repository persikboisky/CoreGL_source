#ifndef INCLUDE_UTIL_TIME_HPP_
#define INCLUDE_UTIL_TIME_HPP_

#include <string>

namespace core
{
    class Timer
    {
    private:
        double time;
        double interval;

        Timer();

    public:

        [[nodiscard]] static Timer create();
        ~Timer();

        void run();
        void stop();
        void reset();

        [[nodiscard]] double getTime();

        void setTime(double time);
        void addTime(double time);
        void difTime(double time);
    };

    namespace data 
    {
        [[nodiscard]] int getHours();
        [[nodiscard]] int getMinutes();
        [[nodiscard]] int getSeconds();
        [[nodiscard]] int getMDay();
        [[nodiscard]] int getYDay();
        [[nodiscard]] int getWDay();
        [[nodiscard]] std::string getWDayToSTR();
        [[nodiscard]] int getYear();
    }
}

#endif // !INCLUDE_UTIL_TIME_HPP_