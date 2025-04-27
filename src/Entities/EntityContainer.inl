#ifndef ENTITY_CONTAINER_INL
#define ENTITY_CONTAINER_INL

#include <random>


template<class T>
template<class U>
std::size_t EntityContainer<T>::RandomIndex(const std::vector<U>& vector) noexcept
{
    std::random_device device;
    std::mt19937 gen{ device() };
    std::uniform_int_distribution<std::size_t> random{ 0, vector.size() - 1 };

    return random(gen);
}


#endif // ENTITY_CONTAINER_INL
