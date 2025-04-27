#include "../../lib/Entities/Entity.hpp"

#include "../../lib/Aquarium.hpp"
#include <iostream>

Entity::Entity() noexcept : Entity(10)
{
}

Entity::Entity(int health) noexcept
	: m_state(State::Alive), m_health(health), m_age(0)
{
}

void Entity::Act(Aquarium &aquarium) noexcept
{
	if (++m_age >= 20)
	{
		m_state = State::Dead;
	}

	if (m_state == State::Alive)
	{
		MakeTurn(aquarium);
	}
}

void Entity::Bite(Entity* entity) noexcept
{
	entity->GetBitten();
}

Entity::State Entity::GetState() const noexcept
{
	return m_state;
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
		m_state = State::Dead;
	}
	else
	{
		m_health -= points;
	}
}

void Entity::Heal(int points) noexcept
{
	m_health += points;
}

void Algae::MakeTurn(Aquarium& aquarium) noexcept
{
	Heal(1);

	if (int health = GetHealth(); health >= 10)
	{
		int half = health / 2;
		LoseHealth(half);
		aquarium.AddAlgae(half);
	}
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
	LoseHealth(1);

	if (GetHealth() > 5 || GetState() == State::Dead) return;

	if (m_foodType == FoodType::Carnivorous && aquarium.FishCount() > 1)
	{
		Fish* target;

		do
		{
			target = aquarium.RandomFish();
		} while (target == this);

		Bite(target);
		Heal(5);
	}
	else if (m_foodType == FoodType::Herbivorous && aquarium.AlgaeCount() > 0)
	{
		Bite(aquarium.RandomAlgae());
		Heal(3);
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
