#pragma once
#include <vector>
#include <iostream>

class Point
{
private:
	double m_x;
	double m_y;

public:
	Point(double x, double y);
	void Move(double dx, double dy);
	void PrintPoint();
	void SetPoint(double x, double y);
	double Distance(Point point);
	Point Middle(Point point);

};