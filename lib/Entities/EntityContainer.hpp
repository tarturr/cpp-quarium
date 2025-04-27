#ifndef ENTITY_CONTAINER_HPP
#define ENTITY_CONTAINER_HPP
#include <memory>
#include <vector>

#include "Entity.hpp"


class Aquarium;


template<class T>
struct EntityContainer
{
    virtual void Add(T&& t) noexcept = 0;
    virtual T* PickRandom() noexcept = 0;
    virtual void Act(Aquarium& aquarium) noexcept = 0;
    virtual void Clean() noexcept = 0;
    virtual std::size_t Size() const noexcept = 0;

    virtual ~EntityContainer() noexcept = default;
protected:
    template<class U>
    static std::size_t RandomIndex(const std::vector<U>& vector) noexcept;
};

struct AlgaeContainer : public EntityContainer<Algae>
{
public:
    AlgaeContainer() noexcept = default;

    void Add(Algae&& algae) noexcept override;
    Algae* PickRandom() noexcept override;
    void Act(Aquarium& aquarium) noexcept override;
    void Clean() noexcept override;
    std::size_t Size() const noexcept override;

    ~AlgaeContainer() noexcept override = default;
private:
    std::vector<Algae> m_algae;
};

struct FishContainer : public EntityContainer<Fish>
{
public:
    FishContainer() noexcept = default;

    void Add(Fish&& fish) noexcept override;
    Fish* PickRandom() noexcept override;
    void Act(Aquarium& aquarium) noexcept override;
    void Clean() noexcept override;
    std::size_t Size() const noexcept override;

    ~FishContainer() noexcept override = default;
private:
    std::vector<std::unique_ptr<Fish>> m_fishes;
};


#include "../../src/Entities/EntityContainer.inl"


#endif //ENTITY_CONTAINER_HPP