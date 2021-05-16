#pragma once
#include <iostream>
#include <string>

#include "Object.h"

using namespace std;

class Person :
    public Obj
{
protected:
    string name;
    int age;
public:
    Person(void);
    virtual ~Person(void);
    void Show();
    void Input();
    Person (string Name, int Age);
    Person(const Person&);

    string GetName() {
        return name;
    }
    int GetAge()
    {
        return age;
    }
    void SetName(string Name);
    void SetAge(int Age);
    Person& operator= (const Person& per);

    void HandleEvent(const TEvent& e);
};

