#include <iostream>
#include "Ship.h"
int main()
{
	IShip* shipA = new Ship("Ship Army", 50);
	IShip* shipD = new Ship("Ship Builder", 30);
	Fleet* fleet = new  Fleet(1, shipA);
	fleet->add(shipD);
	fleet->print();
}