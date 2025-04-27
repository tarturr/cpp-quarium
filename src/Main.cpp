#include <iostream>

#include "../lib/Aquarium.hpp"

int main()
{
    Aquarium aquarium{};
    aquarium.AddAlgae(Algae {});
    aquarium.AddAlgae(Algae {});
    aquarium.AddAlgae(Algae {});
    aquarium.AddAlgae(Algae {});
    aquarium.AddFish(std::make_unique<Fish>("Nemo1", Fish::Gender::Male, Fish::FoodType::Carnivorous));
    aquarium.AddFish(std::make_unique<Fish>("Nemo2", Fish::Gender::Male, Fish::FoodType::Carnivorous));
    aquarium.AddFish(std::make_unique<Fish>("Nemo3", Fish::Gender::Male, Fish::FoodType::Carnivorous));
    aquarium.AddFish(std::make_unique<Fish>("Dori1", Fish::Gender::Female, Fish::FoodType::Herbivorous));
    aquarium.AddFish(std::make_unique<Fish>("Dori2", Fish::Gender::Female, Fish::FoodType::Herbivorous));
    aquarium.AddFish(std::make_unique<Fish>("Dori3", Fish::Gender::Female, Fish::FoodType::Herbivorous));

    for (int i{ 0 }; i < 21; ++i)
    {
        aquarium.MakeTurn();
    }

    return EXIT_SUCCESS;
}
