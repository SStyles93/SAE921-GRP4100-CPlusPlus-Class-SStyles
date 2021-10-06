#include "Car.h"

int main()
{
    Car Ford;
    Car Fiat;

    Ford.SetCar("Ford", "Mustang", "1966");
    Fiat.SetCar("Fiat", "Panda", "1982");
    
    Ford.Print();
    Fiat.Print();
    //or
    std::cout << Ford.GetCar();
    std::cout << Fiat.GetCar();
}