#include <iostream>
#include "Shape.h"
int main()
{
	IColor* red = new Red();
	IColor* yellow = new Yellow();
	IColor* blue = new Blue();

	Shape* redCircle = new Circle(50, red);
	redCircle->draw();

	Shape* yellowCircle = new Circle(30, yellow);
	redCircle->draw();

	Shape* blueCircle = new Circle(50, blue);
	redCircle->draw();
 
}