#ifndef RANDOM_HPP
#define RANDOM_HPP


#include <vector>

template<class T>
T RandomNumber(T min, T max);

template<class U>
std::size_t RandomIndex(const std::vector<U>& vector) noexcept;

#include "../src/Random.inl"


#endif //RANDOM_HPP
