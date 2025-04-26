#include "../lib/Aquarium.hpp"

#include <algorithm>
#include <iostream>
#include <random>


void Aquarium::MakeTurn() noexcept
{
    std::cout << "====== Turn " << m_turn << " ======" << std::endl;

    for (auto& algae : m_algae)
    {
        algae.MakeTurn(*this);
    }

    for (const auto& fish : m_fishes)
    {
        fish->MakeTurn(*this);
    }

    this->Clean();

    ++m_turn;
    std::cout << "\n";
}

void Aquarium::AddAlgae() noexcept
{
    m_algae.emplace_back();
}

void Aquarium::AddFish(UniqueFish&& fish) noexcept
{
    m_fishes.emplace_back(std::move(fish));
}

Algae* Aquarium::RandomAlgae() noexcept
{
    return &m_algae[RandomIndex(m_algae)];
}

Fish* Aquarium::RandomFish() const noexcept
{
    return m_fishes[RandomIndex(m_fishes)].get();
}

std::size_t Aquarium::AlgaeCount() const noexcept
{
    return m_algae.size();
}

std::size_t Aquarium::FishCount() const noexcept
{
    return m_fishes.size();
}

void Aquarium::Clean() noexcept
{
    for (auto algaeIt{ std::begin(m_algae) }; algaeIt != std::end(m_algae);)
    {
        algaeIt = algaeIt->GetHealth() == 0 || algaeIt->GetAge() == 20
            ? m_algae.erase(algaeIt)
            : algaeIt + 1;
    }

    for (auto fishIt{ std::begin(m_fishes) }; fishIt != std::end(m_fishes);)
    {
        if (const UniqueFish& fish{ *fishIt }; fish->GetHealth() == 0 || fish->GetAge() == 20)
        {
            std::cout << fish->GetName() << " est mort !\n";
            fishIt = m_fishes.erase(fishIt);
            std::cout << "Poissons restants : " << m_fishes.size() << std::endl;
        }
        else
        {
            ++fishIt;
        }
    }
}
