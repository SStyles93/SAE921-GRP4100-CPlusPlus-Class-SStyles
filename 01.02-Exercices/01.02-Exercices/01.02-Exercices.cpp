#include <iostream>
#include <string>

enum class animals
{
    CAT,
    DOG,
    COW,
};

std::string getAnimalsNoise(animals animal) 
{
    switch (animal)
    {
    case animals::CAT:
        return "Meow";
        break;
    case animals::DOG:
        return "Woof";
        break;
    case animals::COW:
        return "Moo";
        break;
    default:
        return "-";
        break;
    }
}
std::string getAnimalsName(animals animal) 
{
    switch (animal) 
    {
    case animals::CAT:
        return "Cat";
        break;

    case animals::DOG:
        return "Dog";
        break;

    case animals::COW:
        return "Cow";
        break;
    default:
        return "-";
        break;
    }
}



int main()
{
    std::cout << "Welcome to the animal noise dictionnary" << std::endl;
    std::cout << "There are currently : " << sizeof(animals)-1 << " in the dictionnary" << std::endl;
    std::cout << "Those are : " << std::endl;

    int len = sizeof(animals);
    for (int i = 0; i < len-1; i++)
    {
        std::cout << "[" << i << "]" << getAnimalsName(animals(i)) <<std::endl;
    }

    std::cout << "Select the animal you want to hear the noise from" << std::endl;
    int wantedAnimalIdx;
    do
    {
        std::cin >> wantedAnimalIdx;
        if (wantedAnimalIdx > sizeof((animals)-1))
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout << "Enter a valid index" << std::endl;
            continue;
        }
        else if (wantedAnimalIdx < sizeof(animals))
        {
            std::cin.clear();
            std::cin.ignore();
            continue;
        }
        else 
        {
            std::cout << "The " << getAnimalsName(animals(wantedAnimalIdx)) << "\'s noise is: "
                << getAnimalsNoise(animals(wantedAnimalIdx)) << std::endl;
        }
    } while (wantedAnimalIdx > sizeof((animals)-1) || wantedAnimalIdx < 0);

    }
