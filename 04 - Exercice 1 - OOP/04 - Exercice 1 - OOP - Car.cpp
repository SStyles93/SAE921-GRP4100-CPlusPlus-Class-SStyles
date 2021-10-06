#include "Car.h"

int main()
{
    Car Ford;
    Car Fiat;

    Ford.SetCar("Ford", "Mustang", "1966", 300);
    Fiat.SetCar("Fiat", "Panda", "1982", 12);
    
    Ford.Print();
    Fiat.Print();
    //or
    std::cout << Ford.GetCar() << std::endl;;
    std::cout << Fiat.GetCar() << std::endl;
}