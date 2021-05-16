#pragma once
#include "Event.h"
#include "Vector.h"
using namespace std;

class Dialog : public Vector
{
protected:
	int EndState;
public:
	Dialog(void);
	virtual ~Dialog();
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
};
