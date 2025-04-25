#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>


class Aquarium;


class Entity
{
public:
	Entity() noexcept;

	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	Entity(Entity&&) = default;
	Entity& operator=(Entity&&) = default;

	virtual void MakeTurn(Aquarium& aquarium) noexcept = 0;
	virtual void GetBitten() noexcept = 0;

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

	void MakeTurn(Aquarium& aquarium) noexcept override;
	void GetBitten() noexcept override;

	~Algae() noexcept override = default;
};


class Fish : public Entity
{
public:
	explicit Fish(std::string name) noexcept;

	void MakeTurn(Aquarium& aquarium) noexcept override;
	void GetBitten() noexcept override;

	~Fish() noexcept override = default;
private:
	std::string m_name;
	bool m_gender;
};

#endif