#pragma once
#include <iostream>
#include <string>
class Car 
{
private:
	std::string m_brand;
	std::string m_model;
	std::string m_year;
	int m_power;
public:
	std::string GetCar();
	void SetCar(std::string brand, std::string model, std::string year, int power);
	void Print();
};
