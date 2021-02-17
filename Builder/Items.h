#pragma once
#include <iostream>
#include <string>
using namespace std;


class Item abstract
{
public:
	Item(const string& title = "empty title") : title(title){}
	virtual void paint() = 0;
	virtual void onClick() = 0;
	void setTitle(const string& title) { this->title = title; }
	const string& getTitle() const { return title; }
private:
	string title;

};

class Button : public Item
{
public:
	Button(const string& title = "empty title") : Item(title){}
};

class MacButton : public Button
{
public:
	MacButton(const string& title = "MacBatton") : Button(title){}
	virtual void paint() { cout << "Paint mac button " << getTitle() << endl; }
	virtual void onClick() { cout << "Clicked mac button " << endl; }

};

class WinButton : public Button
{
public:
	WinButton(const string& title = "WinBatton") : Button(title){}
	virtual void paint() { cout << "Paint win button " << getTitle() << endl; }
	virtual void onClick() { cout << "Clicked win button " << endl; }

};

class CheckBox : public Item
{
public:
	CheckBox(const string& title = " ", bool checked = false)
		: Item(title), checked(checked)
	{}
	void onClick() override
	{
		checked = !checked;
	}
	bool getCheck() const
	{
		return checked;
	}
private:
	bool checked = false;
};

class MacCheckBox : public CheckBox
{
public:
	MacCheckBox(const string& title = " Mac cheked ",bool checked = false)
		:CheckBox(title)
	{}
	void paint() override
	{
		cout << "Mac Check box " << getTitle() << " paints\n ";
	}
	void onClick() override
	{
		CheckBox::onClick();
		cout << "Mac checkbox " << getTitle() << " changed its check " << getCheck() << endl;
	}
};

class WinCheckBox : public CheckBox
{
public:
	WinCheckBox(const string& title = " Win cheked ",bool checked = false)
		:CheckBox(title)
	{}
	void paint() override
	{
		cout << "Win Check box " << getTitle() << " paints\n ";
	}
	void onClick() override
	{
		CheckBox::onClick();
		cout << "Win checkbox " << getTitle() << " changed its check " << getCheck() << endl;
	}
};

