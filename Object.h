#pragma once
#include "Event.h"
#include <iostream>
#include <string>

using namespace std;
class Obj
{
public:
	Obj(void);
	virtual void Show() = 0;
	virtual void Input() = 0;
	virtual ~Obj(void);

	virtual void HandleEvent(const TEvent& e) = 0;
};

