#include <iostream>
#include <string>

enum class animals
{
    CAT,
    DOG,
    COW,
    HORSE,
    /* Count has to be the last item to get count from
            static_cast<int>(animals::Count);
    /!\ DOES NOT WORK IF ENUMS VALUES ARE CHANGED /!\ */
    Count
};


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



int main()
{
    //Variables
    int animalsCount = static_cast<int>(animals::Count);
    std::string yesOrNo;

    //Print animals list "[index] Name"
    std::cout << "Welcome to the animal noise dictionnary" << std::endl;
    std::cout << "There are currently : " << animalsCount << " in the dictionnary" << std::endl;
    std::cout << "Those are : " << std::endl;
   
    for (int i = 0; i < animalsCount; i++)
    {
        std::cout << "[" << i << "]" << getAnimalsName(animals(i)) <<std::endl;
    }

    //List selection
    do
    {
        std::cout << "Select the animal you want to \"hear\" the noise from" << std::endl;
        int wantedAnimalIdx;
        do
        {   //PlayerInput
            std::cin >> wantedAnimalIdx;
            //If not a number
            if (!std::cin)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "That is not a number...\n" << "Enter a valid index" << std::endl;
            }
            //Correct case
            else if (wantedAnimalIdx < animalsCount && wantedAnimalIdx >= 0)
            {   
                std::cout << "The " << getAnimalsName(animals(wantedAnimalIdx)) << "\'s noise is: "
                    << getAnimalsNoise(animals(wantedAnimalIdx)) << std::endl;
            }
            //Incorrect cases
            else
            {
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Out of range...\n" << "Enter a valid index" << std::endl;  
            }
        } while (wantedAnimalIdx > animalsCount && wantedAnimalIdx < 0);
        
        //Continue?
        std::cout << "Do you want try again? [y/n]" << std::endl;
        //Can be anything except N or n to continue
        std::cin >> yesOrNo;
    } while (yesOrNo != "N" && yesOrNo != "n");

    std::cout << "Ok, see you another time" << std::endl;
    return EXIT_SUCCESS;
}
