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

}