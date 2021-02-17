#include <iostream>
#include "Items.h"
#include "AbstractFactory.h"
#include <vector>
using namespace std;

class Application
{
public:
	Application(IGUIFactory* factory)
		:factory(factory) {}
	void addButton(const string& title)
	{
		buttons.push_back(factory->createButton(title)); // check 	
	}

	void addCheckBox(const string& title)
	{
		check.push_back(factory->createCheckBox(title));
	}

	void paint()
	{
		for (auto& i : buttons)
		{
			i->paint();
		}
		cout << endl;
		for (auto& i : check)
		{
			i->paint();
		}
	}
	~Application()
	{
		for (auto& i : buttons)
		{
			delete i;
		}
		for (auto& i : check)
		{
			delete i;
		}
		buttons.clear();
		check.clear();
	}

private:
	vector<Button*> buttons;
	vector<CheckBox*> check;
	IGUIFactory* factory;
};


int main()
{

	//Button* button = new WinButton("Go");
	//button->paint();
	//button->onClick();
	//CheckBox* ch = new MacCheckBox("mac");
	//ch->paint();
	//ch->onClick();

	//IGUIFactory* factory = new WinFactory();
	//Button* btn = factory->createButton("Start");
	//btn->paint();
	//btn->onClick();

	//CheckBox* check = factory->createCheckBox("Ukrainian");
	//check->paint();
	//check->onClick();

	MacFactory macFactory;
	Application app(&macFactory);
	app.addButton("First");
	app.addCheckBox("Second");
	app.addCheckBox("Third");
	app.paint();

}