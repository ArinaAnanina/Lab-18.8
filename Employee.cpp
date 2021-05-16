#include <iostream>
#include <string>

#include "Employee.h"

using namespace std;
Employee::Employee(void) :Person()
{
	salary = 0;
	position = "no";
}
Employee::~Employee(void)
{
}
void Employee::Show()
{
	cout << endl;
	cout << "���: " << name << endl;
	cout << "�������: " << age << endl;
	cout << "��������: " << salary << endl;
	cout << "���������: " << position << endl;
	cout << endl;
}
void Employee::Input() 
{
	cout << "������� ������� � ���: ";
	cin.ignore(1, '\n');
	getline(cin, name);
	cout << "�������: ";
	cin >> age;
	cout << "��������: ";
	cin >> salary;
	cout << "���������: ";
	cin >> position;
}
Employee::Employee(float Salary, string Position, string Name, int Age) : Person (Name, Age)
{
	salary = Salary;
	position = Position;
}
Employee::Employee(const Employee& emp)
{
	name = emp.name;
	age = emp.age;
	salary = emp.salary;
	position = emp.position;
}
void Employee::SetSalary(float Salary)
{
	salary = Salary;
}
void Employee::SetPosition(string Position)
{
	position = Position;
}
Employee& Employee:: operator= (const Employee & emp)
{
	if (&emp == this)
	{
		return *this;
	}
	name = emp.name;
	age = emp.age;
	salary = emp.salary;
	position = emp.position;
	return *this;
}
