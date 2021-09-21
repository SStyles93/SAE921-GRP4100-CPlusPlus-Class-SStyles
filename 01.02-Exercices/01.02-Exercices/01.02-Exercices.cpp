#include <iostream>
#include <string>

enum class animals
{
    CAT,
    DOG,
    COW,
    HORSE
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
    case animals::HORSE:
        return "?";
        break;
    default:
        return "None";
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
    case animals::HORSE:
        return "Horse";
        break;
    default:
        return "-";
        break;
    }
}



int main()
{
    // Access enum and print animals list
    std::cout << "Welcome to the animal noise dictionnary" << std::endl;
    std::cout << "There are currently : " << sizeof(animals)-1 << " in the dictionnary" << std::endl;
    std::cout << "Those are : " << std::endl;

    int len = sizeof(animals)-1;
    for (int i = 0; i < len; i++)
    {
        std::cout << "[" << i << "]" << getAnimalsName(animals(i)) <<std::endl;
    }

    std::string yesOrNo;
    do
    {
        std::cout << "Select the animal you want to \"hear\" the noise from" << std::endl;
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
            else if (!std::cin)
            {
                //Ignore anything that isn't a number
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "That is not a number...\n" << "Enter a valid index" << std::endl;
                wantedAnimalIdx = (sizeof(animals) + 1);
                continue;
            }
            else
            {
                std::cout << "The " << getAnimalsName(animals(wantedAnimalIdx)) << "\'s noise is: "
                    << getAnimalsNoise(animals(wantedAnimalIdx)) << std::endl;
            }
        } while (wantedAnimalIdx > sizeof((animals)-1));
        //Exit?
        std::cout << "Do you want to exit? [y/n]" << std::endl;
        std::cin >> yesOrNo;
    } while (yesOrNo != "y" && yesOrNo != "Y");

    std::cout << "Ok, see you another time" << std::endl;
    return EXIT_SUCCESS;
}
