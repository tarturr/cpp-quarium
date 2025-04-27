#include "../lib/Aquarium.hpp"

#include <iostream>


void Aquarium::MakeTurn() noexcept
{
    std::cout << "====== Turn " << m_turn << " ======" << std::endl;

    m_algae.Act(*this);
    m_fishes.Act(*this);

    m_algae.Clean();
    m_fishes.Clean();

    std::cout << "Poissons restants : " << m_fishes.Size()
            << "\nAlgues restantes : " << m_algae.Size() << "\n" << std::endl;
    ++m_turn;
}

void Aquarium::AddAlgae(Algae&& algae) noexcept
{
    m_algae.Add(std::move(algae));
}

void Aquarium::AddFish(Fish&& fish) noexcept
{
    m_fishes.Add(std::move(fish));
}

std::size_t Aquarium::AlgaeCount() const noexcept
{
    return m_algae.Size();
}

std::size_t Aquarium::FishCount() const noexcept
{
    return m_fishes.Size();
}

Algae* Aquarium::RandomAlgae() noexcept
{
    return m_algae.PickRandom();
}

Fish* Aquarium::RandomFish() noexcept
{
    return m_fishes.PickRandom();
}
