#include "Dialog.h"

using namespace std;
Dialog::Dialog(void):Vector()
{
	EndState = 0;
}
Dialog:: ~Dialog()
{
}
void Dialog::GetEvent(TEvent& event)
{
	string OpInt = "+-szqm";
	string s;
	string param;
	char code;
	cout << "Формы команд: " << endl;
	cout << "m 'число'- резервирование памяти для элементов." << endl;
	cout << "+ - добавить элемент" << endl;
	cout << "- - удалить элемент" << endl;
	cout << "s - вывести информацию об элементах" << endl;
	cout << "z k - вывести информацию об элементе с номером k" << endl;
	cout << "q - конец работы" << endl;
	cout << '>';
	cin >> s;
	code = s[0];
	if (OpInt.find(code) >= 0)
	{
		event.what = evMessage;
		switch (code)
		{
		case 'm': event.command = cmMake; break;
		case '+': event.command = cmAdd; break;
		case '-': event.command = cmDel; break;
		case 's': event.command = cmShow; break;
		case 'z': event.command = cmGet; break;
		case 'q': event.command = cmQuit; break;
		}
		if (s.length() > 1)
		{
			param = s.substr(1, s.length() - 1);
			int A = atoi(param.c_str());
			event.a = A;
		}
	}
	else
	{
		event.what = evNothing;
	}
}
int Dialog::Execute()
{
	TEvent event;

	do
	{
		EndState = 0;
		GetEvent(event);
		HandleEvent(event);
	} while (!Valid());
	return EndState;
}
void Dialog::HandleEvent(TEvent& event)
{
	if (event.what == evMessage)
	{
		switch (event.command)
		{
		case cmMake:
			size = event.a;
			begin = new Obj * [size];
			ClearEvent(event);
			break;
		case cmAdd:
			Add();
			ClearEvent(event);
			break;
		case cmDel:
			Delete();
			ClearEvent(event);
			break;
		case cmShow:
			Show();
			ClearEvent(event);
			break;
		case cmGet:
			Show(event.a);
			ClearEvent(event);
			break;
		case cmQuit:
			EndExec();
			ClearEvent(event);
			break;
		default: Vector::HandeEvent(event);
		}
	}
}
void Dialog::ClearEvent(TEvent& event)
{
	event.what = evNothing;
}
int Dialog::Valid()
{
	if (EndState == 0)
	{
		return 0;
	}
	else return 1;
}
void Dialog::EndExec()
{
	EndState = 1;
}