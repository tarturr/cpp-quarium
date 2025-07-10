#include "../../lib/Entities/Entity.hpp"

#include "../../lib/Aquarium.hpp"
#include "../../lib/Random.hpp"
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

Fish::Fish(std::string name, Gender gender, Breed breed) noexcept
	: m_name(std::move(name)), m_gender(gender), m_breed(breed)
{
	switch (m_breed)
	{
		case Breed::Carp:
		case Breed::Tuna:
			m_sexuality = Sexuality::MonoSexual;
			break;

		case Breed::SeaBass:
		case Breed::Grouper:
			m_sexuality = Sexuality::AgeHermaphrodite;
			break;

		case Breed::Clownfish:
		case Breed::Sole:
			m_sexuality = Sexuality::OpportunisticHermaphrodite;
			break;
	}
}

void Fish::MakeTurn(Aquarium &aquarium) noexcept
{
	LoseHealth(1);

	if (GetState() == State::Dead)
	{
		return;
	}

	if (!IsHungry())
	{
		if (Fish* partner = FindOtherFish(aquarium); partner->m_breed == m_breed && partner->m_gender != m_gender)
		{
			std::string childName{ m_name + " Jr." };
			std::cout << childName << " est né !" << std::endl;
			aquarium.AddFish({ std::move(childName), static_cast<Gender>(RandomNumber(0, 1)), m_breed });
		}
	}
	else if (IsCarnivorous() && aquarium.FishCount() > 1)
	{
		Fish* target = FindOtherFish(aquarium);

		Bite(target);
		Heal(5);
	}
	else if (!IsCarnivorous() && aquarium.AlgaeCount() > 0)
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

Fish* Fish::FindOtherFish(Aquarium& aquarium) const noexcept
{
	Fish* target;

	do
	{
		target = aquarium.RandomFish();
	} while (target == this);

	return target;
}

std::string_view Fish::GetName() const noexcept
{
	return m_name;
}

bool Fish::IsCarnivorous() const noexcept
{
	switch (m_breed)
	{
		case Breed::Grouper:
		case Breed::Tuna:
		case Breed::Clownfish:
			return true;
		default:
			return false;
	}
}

bool Fish::IsHungry() const noexcept
{
	return GetHealth() <= 5;
}
