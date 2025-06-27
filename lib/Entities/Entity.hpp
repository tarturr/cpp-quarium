#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>


class Aquarium;


class Entity
{
public:
	enum class State { Alive, Dead };

	Entity() noexcept;
	Entity(int health) noexcept;

	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	Entity(Entity&&) = default;
	Entity& operator=(Entity&&) = default;

	void Act(Aquarium& aquarium) noexcept;
	void Bite(Entity* entity) noexcept;

	State GetState() const noexcept;
	int GetHealth() const noexcept;
	int GetAge() const noexcept;

	virtual ~Entity() noexcept = default;
protected:
	void LoseHealth(int points) noexcept;
	void Heal(int points) noexcept;
private:
	virtual void MakeTurn(Aquarium& aquarium) noexcept = 0;
	virtual void GetBitten() noexcept = 0;

	State m_state;
	int m_health;
	int m_age;
};


class Algae final : public Entity
{
public:
	using Entity::Entity;

	Algae(const Algae&) = delete;
	Algae& operator=(const Algae&) = delete;
	Algae(Algae&&) = default;
	Algae& operator=(Algae&&) = default;

	~Algae() noexcept override = default;
private:
	void MakeTurn(Aquarium& aquarium) noexcept override;
	void GetBitten() noexcept override;
};


class Fish : public Entity
{
public:
	enum class Gender
	{
		Male,
		Female
	};

	enum class Breed
	{
		Grouper,
		Tuna,
		Clownfish,
		Sole,
		SeaBass,
		Carp
	};

	Fish(std::string name, Gender gender, Breed breed) noexcept;

	Fish(const Fish &other) = delete;
	Fish& operator=(const Fish &other) = delete;
	Fish(Fish &&other) noexcept = default;
	Fish& operator=(Fish &&other) noexcept = default;

	Fish* FindOtherFish(Aquarium& aquarium) const noexcept;
	std::string_view GetName() const noexcept;
	bool IsCarnivorous() const noexcept;
	bool IsHungry() const noexcept;

	~Fish() noexcept override = default;
private:
	void MakeTurn(Aquarium& aquarium) noexcept override;
	void GetBitten() noexcept override;

	std::string m_name;
	Gender m_gender;
	Breed m_breed;
};

#endif