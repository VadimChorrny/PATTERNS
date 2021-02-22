#include <iostream>
using namespace std;
#include "TreeType.h"
int main()
{
	//TreeFactory factory;
	//TreeType* tt = factory.getTreeType("oak", "green");
	//tt->draw(1, 1);

	Forest forest;
	forest.plantTree(3, 4, "oak", "green");
	forest.plantTree(10, 5, "birch", "light green ");
	forest.draw();
}
