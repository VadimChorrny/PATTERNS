#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

__interface IShip
{
	void print() const;
};

class Ship : public IShip // leaf
{
public:
	Ship(const string& name = "noname",const size_t& speed = 0)
		:name(name),speed(speed)
	{}
	void print() const override
	{
		cout << "Ship " << name << "\tSpeed " << speed << endl;
	}
private:
	size_t speed;
	string name;
};

class Fleet : public IShip
{
public:
	Fleet(const size_t& id, IShip* item = nullptr)
		:id(id)
	{
		if (item != nullptr)
		{
			children.push_back(item);
		}
	}
	void add(IShip* item)
	{
		if (item != nullptr)
		{
			children.push_back(item);
		}
	}

	void remove(IShip* item)
	{
		auto it = find(begin(children), end(children), item);
		if (it != end(children))
		{
			delete *it;
			children.erase(it); // for ~dtor
		}
	}

	void print() const override
	{
		cout << "FLEET #" << id << endl;
		for (auto& i : children)
		{
			cout << i << endl;
		}
	}
private:
	size_t id;
	string name;
	vector<IShip*>children;
};

