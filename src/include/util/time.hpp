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

        /// @brief создаёт таймер, и возвращает его объект
        /// @return объект таймера (Timer)
        static Timer create();

        ~Timer();

        /// @brief запускает таймер
        void start();

        /// @brief останавливает таймер
        void stop();

        /// @brief сбрасывает таймер
        void reset();

        /// @brief возвращает время в секундах
        /// @return время
        [[nodiscard]] double getTime() const;

        void setTime(double time);
        void addTime(double time);
        void difTime(double time);
    };
}

#endif // !INCLUDE_UTIL_TIME_HPP_