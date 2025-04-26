#include "../../lib/Entities/Entity.hpp"

#include "../../lib/Aquarium.hpp"
#include <iostream>

Entity::Entity() noexcept
	: m_health(10), m_age(0)
{
}

void Entity::MakeTurn(Aquarium& aquarium) noexcept
{
	if (++m_age >= 20)
	{
		m_health = 0;
	}
}

int Entity::GetHealth() const noexcept
{
	return m_health;
}

int Entity::GetAge() const noexcept
{
	return m_age;
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
	Entity::MakeTurn(aquarium);
	aquarium.AddAlgae();
}

void Algae::GetBitten() noexcept
{
	LoseHealth(2);
	std::cout << "Une algue s'est faite mordre ! PV restants : " << GetHealth() << std::endl;
}

Fish::Fish(std::string name, Gender gender, FoodType foodType) noexcept
	: m_name(std::move(name)), m_gender(gender), m_foodType(foodType)
{
}

void Fish::MakeTurn(Aquarium &aquarium) noexcept
{
	Entity::MakeTurn(aquarium);

	if (m_foodType == FoodType::Carnivorous)
	{
		if (aquarium.FishCount() > 1)
		{
			Fish* target;

			do
			{
				target = aquarium.RandomFish();
			} while (target == this);

			target->GetBitten();
		}
	}
	else if (aquarium.AlgaeCount() > 0)
	{
		aquarium.RandomAlgae()->GetBitten();
	}
}

void Fish::GetBitten() noexcept
{
	LoseHealth(4);
	std::cout << m_name << " s'est fait mordre ! PV restants : " << GetHealth() << std::endl;
}

std::string_view Fish::GetName() const noexcept
{
	return m_name;
}
