#include <iostream>
#include "Dialog.h"
#include <string>

using namespace std;
int main()
{
	system("color F0");
	setlocale(LC_ALL, "rus");
	Dialog D;
	D.Execute();
	return 0;
}