#include "Vector.h"
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

Vector::Vector()
{
	begin = new Obj* [1];
	current = 0;
	size = 1;
}
Vector::Vector(int n)
{
	begin = new Obj* [n];
	current = 0;
	size = n;
}
Vector::~Vector(void)
{
	if (begin != 0)
	{
		delete[] begin;
	}
	begin = 0;
}
void Vector::Add()
{
	Obj* p;
	cout << "1 - Person" << endl;
	cout << "2 - Employee" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Person* person = new Person;
		person->Input();
		p = person;
		if (current < size)
		{
			begin[current] = p;
			current++;
			size++;
		}
	}
	else
	{
		if (y == 2)
		{
			Employee* emp = new Employee;
			emp->Input();
			if (current < size)
			{
				begin[current] = emp;
				current++;
				size++;
			}
		}
		else return;
	}
}
void Vector::Delete()
{
	if (current == 0)
	{
		return;
	}
	current--;
	size--;
}
void Vector::Show(int number)
{
	if (number >= size || number <=0)
	{
		return;
	}
	begin[number]->Show();
}
void Vector::Show()
{
	if (current == 0)
	{
		cout << "Пусто" << endl;
	}
	Obj** p = begin;
	for (int i = 0; i < current; i++)
	{
		(*p)->Show();
		p++;
	}
}
int Vector::operator()()
{
	return current;
}
void Vector::HandeEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Obj** p = begin;
		for (int i = 0; i < current; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}
