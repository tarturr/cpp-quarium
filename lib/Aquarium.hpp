#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include <memory>
#include <vector>

#include "Entities/Entity.hpp"


class Aquarium
{
public:
	Aquarium() noexcept;

	Aquarium(const Aquarium&) = delete;
	Aquarium& operator=(const Aquarium&) = delete;
	Aquarium(Aquarium&&) = default;
	Aquarium& operator=(Aquarium&&) = default;

	void AddAlgae() noexcept;
private:
	std::vector<Algae> m_algaes;
	std::vector<std::unique_ptr<Fish>> m_fishes;
};

#endif