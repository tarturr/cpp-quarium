#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>


class Aquarium;


class Entity
{
public:
	Entity() noexcept;
	explicit Entity(int health) noexcept;

	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	Entity(Entity&&) = default;
	Entity& operator=(Entity&&) = default;

	virtual void MakeTurn(Aquarium& aquarium) noexcept = 0;
	virtual void GetBitten() noexcept = 0;

	int GetHealth() const noexcept;
	int GetAge() const noexcept;

	virtual ~Entity() noexcept = default;
protected:
	void LoseHealth(int points) noexcept;
private:
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

	void MakeTurn(Aquarium& aquarium) noexcept override;
	void GetBitten() noexcept override;

	~Algae() noexcept override = default;
};


class Fish : public Entity
{
public:
	enum class Gender{ Female, Male };
	enum class FoodType{ Herbivorous, Carnivorous };

	Fish(std::string name, Gender gender, FoodType foodType) noexcept;

	void MakeTurn(Aquarium& aquarium) noexcept override;
	void GetBitten() noexcept override;

	std::string_view GetName() const noexcept;

	~Fish() noexcept override = default;
private:
	std::string m_name;
	Gender m_gender;
	FoodType m_foodType;
};

#endif