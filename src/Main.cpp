#include <iostream>

#include "../lib/Aquarium.hpp"

int main()
{
    Aquarium aquarium{};
    aquarium.AddAlgae();
    aquarium.AddAlgae();
    aquarium.AddAlgae();
    aquarium.AddAlgae();
    aquarium.AddFish({ "Nemo1", Fish::Gender::Male, Fish::FoodType::Carnivorous });
    aquarium.AddFish({ "Nemo2", Fish::Gender::Male, Fish::FoodType::Carnivorous });
    aquarium.AddFish({ "Nemo3", Fish::Gender::Male, Fish::FoodType::Carnivorous });
    aquarium.AddFish({ "Dori1", Fish::Gender::Female, Fish::FoodType::Herbivorous });
    aquarium.AddFish({ "Dori2", Fish::Gender::Female, Fish::FoodType::Herbivorous });
    aquarium.AddFish({ "Dori3", Fish::Gender::Female, Fish::FoodType::Herbivorous });

    for (int i{ 0 }; i < 21; ++i)
    {
        aquarium.MakeTurn();
    }

    return EXIT_SUCCESS;
}
