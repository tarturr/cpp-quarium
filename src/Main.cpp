#include <iostream>

#include "../lib/Aquarium.hpp"

int main()
{
    using Gender = Fish::Gender;
    using Breed = Fish::Breed;

    Aquarium aquarium{};
    aquarium.AddAlgae();
    aquarium.AddAlgae();
    aquarium.AddAlgae();
    aquarium.AddAlgae();
    aquarium.AddFish({ "Poisson-Clown", Gender::Male, Breed::Clownfish });
    aquarium.AddFish({ "Poisson-Clown", Gender::Female, Breed::Clownfish });
    aquarium.AddFish({ "Bar", Gender::Male, Breed::SeaBass });
    aquarium.AddFish({ "Bar", Gender::Female, Breed::SeaBass });
    aquarium.AddFish({ "Merou", Gender::Male, Breed::Grouper });
    aquarium.AddFish({ "Merou", Gender::Female, Breed::Grouper });
    aquarium.AddFish({ "Carpe", Gender::Male, Breed::Carp });
    aquarium.AddFish({ "Carpe", Gender::Female, Breed::Carp });
    aquarium.AddFish({ "Sole", Gender::Male, Breed::Sole });
    aquarium.AddFish({ "Sole", Gender::Female, Breed::Sole });
    aquarium.AddFish({ "Thon", Gender::Male, Breed::Tuna });
    aquarium.AddFish({ "Thon", Gender::Female, Breed::Tuna });

    for (int i{ 0 }; i < 21; ++i)
    {
        aquarium.MakeTurn();
    }

    return EXIT_SUCCESS;
}
