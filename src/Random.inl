#ifndef RANDOM_INL
#define RANDOM_INL


#include <random>
#include <type_traits>

template<class T>
T RandomNumber(T min, T max)
{
    static_assert(std::is_arithmetic_v<T> && "The provided type is not valid for the generator");
    std::random_device device;
    std::mt19937 gen{ device() };
    std::uniform_int_distribution random{ min, max };

    return random(gen);
}

template<class U>
std::size_t RandomIndex(const std::vector<U>& vector) noexcept
{
    return RandomNumber<std::size_t>(0, vector.size() - 1);
}

#endif //RANDOM_INL