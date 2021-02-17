#pragma once
#include "Items.h"

__interface IGUIFactory // abstract factory
{
	Button* createButton(const string & title="  ") = 0;
	CheckBox* createCheckBox(const string& title=" ") = 0;
};

class MacFactory : public IGUIFactory
{
	Button* createButton(const string& title = "  ") override
	{
		return new MacButton(title);
	}
	CheckBox* createCheckBox(const string& title = " ") override
	{
		return new MacCheckBox(title);
	}
};
class WinFactory : public IGUIFactory
{
	Button* createButton(const string& title = "  ") override
	{
		return new WinButton(title);
	}
	CheckBox* createCheckBox(const string& title = " ") override
	{
		return new WinCheckBox(title);
	}
};