#include "Car.h"

std::string Car::GetCar() 
{
	return brand + " " + model + " " + year;
}

void Car::SetCar(std::string brand_, std::string model_, std::string year_)
{
	Car::brand = brand_;
	Car::model = model_;
	Car::year = year_;
}
void Car::Print() 
{
	std::cout << brand << " " << model << " " << year << std::endl;
}