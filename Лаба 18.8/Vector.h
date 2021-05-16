#pragma once
#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class Vector
{
protected:
	Obj** begin;
	int size;
	int current;
public:
	Vector(void);
	Vector(int n);
	~Vector(void);
	void Add();
	void Delete();
	void Show();
	void Show(int number);
	int operator()();

	void HandeEvent(const TEvent& e);
};

