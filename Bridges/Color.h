#pragma once
#include <iostream>
using namespace std;


__interface IColor
{
	void paint() const;
};

class Red : public IColor
{
public:
	void paint() const override
	{
		cout << "Color red" << endl;
	}
};

class Blue : public IColor
{
public:
	void paint() const override
	{
		cout << "Color is blue" << endl;
	}
};
class Yellow : public IColor
{
public:
	void paint() const override
	{
		cout << "Color is yellow" << endl;
	}
};