#include "../../lib/Entities/Entity.hpp"

#include "../../lib/Aquarium.hpp"

Entity::Entity() noexcept : m_health(10), m_age(0)
{
}

void Entity::MakeTurn(Aquarium& aquarium) noexcept
{
	if (++m_age >= 20)
	{
		m_health = 0;
	}
}

void Entity::LoseHealth(int points) noexcept
{
	if (m_health - points <= 0)
	{
		m_health = 0;
	}
	else
	{
		m_health -= points;
	}
}

void Algae::MakeTurn(Aquarium& aquarium) noexcept
{
	aquarium.AddAlgae();
}

void Algae::GetBitten() noexcept
{
	LoseHealth(2);
}

Fish::Fish(std::string name) noexcept : Entity(), m_name(std::move(name))
{
}

void Fish::MakeTurn(Aquarium &aquarium) noexcept
{
}

void Fish::GetBitten() noexcept
{
}
