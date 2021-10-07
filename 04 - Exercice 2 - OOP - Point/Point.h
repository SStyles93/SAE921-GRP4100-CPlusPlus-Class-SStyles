#pragma once
#include <vector>
#include <iostream>

class Point
{
private:
	double m_x;
	double m_y;

public:
	//consructors
	Point();
	Point(double x, double y);
	//operators
	Point operator+(Point &point);
	bool operator>(Point &point);
	bool operator<(Point& point);
	//Methods
	void Move(double dx, double dy);
	void PrintPoint();
	void SetPoint(double x, double y);
	double Distance(Point point);
	Point Middle(Point point);
};