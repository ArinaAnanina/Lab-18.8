#pragma once
#include "Object.h"
#include <map>
class Tree
{
protected:
	Object** begin;
	int size;
	int current;
public:
	Tree(int n);
	~Tree(void);
	void Add();
	void Delete();
	void Show();
	int operator()();
};

