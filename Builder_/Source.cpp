#include <iostream>
#include "Builder.h"
using namespace std;

int main()
{
	// WITHOUT PATTERN

	//Car car;
	//car.engineVolume = 20;
	//car.amount = 4;
	//car.print();

	// BUILDER

	//CarBuilder car;
	//car.reset();
	//car.setGPS(true);
	//car.setSeats(3);

	//Car* cars = car.getResult();
	//cars->print();

	CarBuilder carBuilder;
	Director director(&carBuilder);
	director.make(CarType::ORDINARY);

	Car* car = carBuilder.getResult();
	car->print();
	
	director.make(CarType::SPORT);

	Car* car2 = carBuilder.getResult();
	car2->print();

	delete car;


}