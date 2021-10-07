#include "Point.h"

int main()
{
	Point point1(0.0, 0.0);
	Point point2(10.0, 10.0);

	point1.PrintPoint();
	point2.PrintPoint();

	point1.Move(1, 3);
	point1.PrintPoint();

	std::cout << point1.Distance(point2) << std::endl;
	point1.Middle(point2).PrintPoint();

	point2.SetPoint(5.0, 5.0);
	point2.PrintPoint();
	//Ex5 - OOP - OperatorOverload
	//Operator+ test
	Point point3 = point1 + point2;
	point3.PrintPoint();
	//Operator >,< test
	if (point2 > point1) 
	{
		std::cout << "is bigger" << std::endl;
	}
	if (point1 < point2) 
	{
		std::cout << "is smaller";
	}

}