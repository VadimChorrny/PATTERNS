#include <iostream>
using std::cout;
using std::endl;
#include "DrinkMachine.h"

int main()
{
	DrinkMachine d_machine;
	ICoffeMachine* c_machine = new CoffeMachine();
	c_machine->makeLate();
}