#include "../../lib/Entities/EntityContainer.hpp"

#include <iostream>


void AlgaeContainer::Add(Algae&& algae) noexcept
{
    m_algae.push_back(std::move(algae));
}

Algae* AlgaeContainer::PickRandom() noexcept
{
    return &m_algae[RandomIndex(m_algae)];
}

void AlgaeContainer::Act(Aquarium& aquarium) noexcept
{
    for (std::size_t i{ 0 }; i < m_algae.size(); ++i)
    {
        m_algae[i].Act(aquarium);
    }
}

void AlgaeContainer::Clean() noexcept
{
    for (auto it{ std::begin(m_algae) }; it != std::end(m_algae);)
    {
        it = it->GetState() == Entity::State::Dead
            ? m_algae.erase(it)
            : it + 1;
    }
}

std::size_t AlgaeContainer::Size() const noexcept
{
    return m_algae.size();
}

void FishContainer::Add(Fish &&fish) noexcept
{
    m_fishes.push_back(std::make_unique<Fish>(std::move(fish)));
}

Fish* FishContainer::PickRandom() noexcept
{
    return m_fishes[RandomIndex(m_fishes)].get();
}

void FishContainer::Act(Aquarium &aquarium) noexcept
{
    for (std::size_t i{ 0 }; i < m_fishes.size(); ++i)
    {
        m_fishes[i]->Act(aquarium);
    }
}

void FishContainer::Clean() noexcept
{
    using UniqueFish = std::unique_ptr<Fish>;

    for (auto it{ std::begin(m_fishes) }; it != std::end(m_fishes);)
    {
        if (const UniqueFish& fish{ *it }; fish->GetState() == Entity::State::Dead)
        {
            std::cout << fish->GetName() << " est mort !\n";
            it = m_fishes.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

std::size_t FishContainer::Size() const noexcept
{
    return m_fishes.size();
}
