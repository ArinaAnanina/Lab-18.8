#pragma once
#include "Person.h"
#include <iostream>
#include <string>
using namespace std;
class Employee :
    public Person
{
protected:
    float salary;
    string position;
public:
    Employee(void);
    ~Employee(void);
    void Show();
    void Input();
    Employee(float Salary, string Position, string Name, int Age);
    Employee(const Employee& emp);
    float GetSalary()
    {
        return salary;
    }
    string GetPosition()
    {
        return position;
    }
    void SetSalary(float Salary);
    void SetPosition(string Position);
    Employee& operator= (const Employee & emp);
};

