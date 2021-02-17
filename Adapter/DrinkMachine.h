#pragma once
#include <iostream>
using std::cout;
using std::endl;

class DrinkMachine // OLD CLASS with needed functionality
{
public:
	void makeTea()
	{
		cout << "Tea is make....\n";
	}
	void makeCoffee()
	{
		cout << "Coffee is make....\n";
	}
	void addMilk()
	{
		cout << "Milk is added....\n";
	}
};


__interface ICoffeMachine // new interface,which wont client
{
	void makeCoffee();
	void makeLate();
};
class CoffeMachine : public ICoffeMachine, protected DrinkMachine
{
public:
	void makeCoffee() 
	{
		machine.makeCoffee();
	}
	void makeLate() 
	{
		machine.makeCoffee();
		machine.addMilk();
	}
private:
	DrinkMachine machine;

};
