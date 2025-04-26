#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include <memory>
#include <vector>

#include "Entities/Entity.hpp"


class Aquarium
{
public:
	using AlgaeBox = std::vector<Algae>;
	using UniqueFish = std::unique_ptr<Fish>;
	using FishBox = std::vector<UniqueFish>;

	Aquarium() noexcept = default;

	Aquarium(const Aquarium&) = delete;
	Aquarium& operator=(const Aquarium&) = delete;
	Aquarium(Aquarium&&) = default;
	Aquarium& operator=(Aquarium&&) = default;

	void MakeTurn() noexcept;
	void AddAlgae() noexcept;
	void AddFish(UniqueFish&& fish) noexcept;
	Algae* RandomAlgae() noexcept;
	Fish* RandomFish() const noexcept;
	std::size_t AlgaeCount() const noexcept;
	std::size_t FishCount() const noexcept;
private:
	template<class T>
	std::size_t RandomIndex(const std::vector<T>& vector) const noexcept;

	void Clean() noexcept;

	AlgaeBox m_algae;
	FishBox m_fishes;
	int m_turn = 0;
};

#include "../src/Aquarium.inl"

#endif
