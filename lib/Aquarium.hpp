#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "Entities/Entity.hpp"
#include "Entities/EntityContainer.hpp"


class Aquarium
{
public:
	Aquarium() noexcept = default;

	Aquarium(const Aquarium&) = delete;
	Aquarium& operator=(const Aquarium&) = delete;
	Aquarium(Aquarium&&) = default;
	Aquarium& operator=(Aquarium&&) = default;

	void MakeTurn() noexcept;
	void AddAlgae(Algae&& algae = 10) noexcept;
	void AddFish(Fish&& fish) noexcept;
	std::size_t AlgaeCount() const noexcept;
	std::size_t FishCount() const noexcept;
	Algae* RandomAlgae() noexcept;
	Fish* RandomFish() noexcept;
private:
	AlgaeContainer m_algae;
	FishContainer m_fishes;
	int m_turn = 0;
};


#endif
