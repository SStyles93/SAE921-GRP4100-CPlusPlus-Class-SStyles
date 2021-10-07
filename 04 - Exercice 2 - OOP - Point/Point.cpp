#include "Point.h"


Point::Point() {};
Point::Point(double x, double y)
{
	m_x = x;
	m_y = y;
}
void Point::Move(double dx, double dy) 
{
	while (m_x != dx) 
	{
		m_x++;
	}
	while (m_y != dy) 
	{
		m_y++;
	}
};
void Point::PrintPoint() 
{
	std::cout << m_x << " " << m_y << std::endl;
};
void Point::SetPoint(double x, double y)
{
	m_x = x;
	m_y = y;
};
double Point::Distance(Point destination) 
{
	long long sqrDistance;
	sqrDistance = ((destination.m_x - this->m_x) * (destination.m_x - this->m_x)) + ((destination.m_y - this->m_y) * (destination.m_y - this->m_y));
	double distance = sqrt(sqrDistance);
	return distance;
};
Point Point::Middle(Point point) 
{
	double xCoordinates = (point.m_x - this->m_x) / 2;
	double yCoordinates = (point.m_y - this->m_y) / 2;
	Point middlePoint(xCoordinates, yCoordinates);
	return middlePoint;
}
//Ex5 - Operator overload
Point Point::operator+(Point& point) 
{
	double xCoordinates = (point.m_x - this->m_x) / 2;
	double yCoordinates = (point.m_y - this->m_y) / 2;
	Point result(xCoordinates, yCoordinates);
	return result;
}
bool Point::operator>(Point& point)
{
	if (this->Distance(Point(0, 0)) > point.Distance(Point(0, 0))) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Point::operator<(Point& point) 
{
	if (this->Distance(Point(0, 0)) < point.Distance(Point(0, 0)))
	{
		return true;
	}
	else
	{
		return false;
	}
}