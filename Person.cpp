#include "Person.h"
#include <iostream>
#include <string>
using namespace std;
Person::Person(void)
{
    name = "";
    age = 0;
}
Person:: ~Person(void)
{
}
void Person::Show()
{
    cout << endl;
    cout << "Имя: " << name << endl;
    cout << "Возраст: " << age << endl;
    cout << endl;
}
void Person::Input()
{
    cout << "Введите Фамилию и Имя: "; 
    cin.ignore(1, '\n');
    getline(cin, name);
    cout << "Введите возраст: ";
    cin >> age;
}
Person::Person(string Name, int Age)
{
    this->name = Name;
    this->age = Age;
}
Person::Person(const Person& per)
{
    name = per.name;
    age = per.age;
}
void Person::SetName(string Name)
{
    name = Name;
}
void Person::SetAge(int Age)
{
    age = Age;
}
Person& Person::operator= (const Person& per)
{
    if (&per == this)
    {
        return *this;
    }
    name = per.name;
    age = per.age;
    return *this;
}
void Person::HandleEvent(const TEvent& e)
{
    if (e.what == evMessage)
    {
        switch (e.command)
        {
        case cmGet: cout << endl;
            break;
        }
    }
}
