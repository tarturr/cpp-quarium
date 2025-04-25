#include "../lib/Aquarium.hpp"

Aquarium::Aquarium() noexcept : m_algaes(), m_fishes()
{
}

void Aquarium::AddAlgae() noexcept
{
    m_algaes.emplace_back();
}