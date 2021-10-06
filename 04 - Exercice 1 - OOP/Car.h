#pragma once
#include <iostream>
#include <string>
class Car 
{
private:
	std::string brand;
	std::string model;
	std::string year;
public:
	std::string GetCar();
	void SetCar(std::string brand_, std::string model_, std::string year_);
	void Print();
};
