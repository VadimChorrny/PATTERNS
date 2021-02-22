#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;
class TreeType
{
public:
	string name;
	string color;
	TreeType(const string& name, const string& color)
		:name(name), color(color)
	{}
	void draw(int x, int y)// canvas);
	{
		cout << "Draw on canvas tree with " << name 
			<< " and color " << color << " x = " << x 
			<< " y = " << y <<endl;
	}
};

class Tree
{
public:
	int x, y;
	TreeType& type;
	Tree(int x, int y, TreeType & type)
		:x(x), y(y), type(type)
	{}
	void draw()// canvas
	{
		type.draw(x, y);// canvas
	}
};

class TreeFactory
{
	deque<TreeType*> treeType;
public:
	TreeType* getTreeType(const string& name, const string& color)
	{
		auto it = find_if(
			begin(treeType),
			end(treeType),
			[&](TreeType* t) {return t->name == name and t->color == color; }
		);
		if (it != end(treeType))
		{
			return *it;
		}
		auto treeTypes = new TreeType(name, color);
		treeType.push_back(treeTypes);
		return treeTypes;
	}
	
};

class Forest
{
	TreeFactory factory;
	deque<Tree*> forest;
public:
	Tree * plantTree(int x, int y, const string name, const string color)
	{
		Tree * tree = new Tree (x, y, *factory.getTreeType(name, color));
		forest.push_back(tree);
		return tree;
	}
	void draw()// canvas
	{
		for (auto& i : forest)
		{
			i->draw();
		}
	}
};