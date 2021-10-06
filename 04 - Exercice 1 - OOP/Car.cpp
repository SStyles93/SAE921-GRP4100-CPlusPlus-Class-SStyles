#include "Car.h"

std::string Car::GetCar() 
{
	return m_brand + " " + m_model + " " + m_year + " " + std::to_string(m_power);
}
void Car::SetCar(std::string brand, std::string model, std::string year, int power)
{
	Car::m_brand = brand;
	Car::m_model = model;
	Car::m_year = year;
	Car::m_power = power;
}
void Car::Print() 
{
	std::cout << m_brand << " " << m_model << " " << m_year << std::endl;
}