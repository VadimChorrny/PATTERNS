#pragma once
#include "Color.h"
class Shape abstract
{
	IColor* color;
public:
	Shape(IColor* color) : color(color){}
	virtual void draw() const
	{
		color->paint();
	}
};

class Circle : public Shape
{
	size_t radius;
public:
	Circle(const size_t& radius,IColor*color)
		:Shape(color),radius(radius)
	{}
	void draw() const override
	{
		Shape::draw();
		cout << "Its circle with radius" << radius << endl;
	}
	
};

class Square : public Shape
{
	size_t side;
public:
	Square(const size_t& side,IColor*color)
		:Shape(color),side(side)
	{}
	void draw() const override
	{
		Shape::draw();
		cout << "Its circle with radius" << side << endl;
	}
	
};

