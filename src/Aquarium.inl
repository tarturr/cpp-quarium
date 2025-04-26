#ifndef AQUARIUM_INL
#define AQUARIUM_INL

#include <random>

template<class T>
std::size_t Aquarium::RandomIndex(const std::vector<T> &vector) const noexcept
{
    std::random_device device;
    std::mt19937 gen{ device() };
    std::uniform_int_distribution<std::size_t> random{ 0, vector.size() - 1 };

    return random(gen);
}

#endif // AQUARIUM_INL
