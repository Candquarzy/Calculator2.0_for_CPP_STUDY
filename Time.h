#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Time& t)
{
	cout << "ת����:" << endl;
	cout << "��: " << t.sencond << endl;
	cout << "��: " << fixed << t.minute << endl;
	cout << "ʱ: " << t.hour << endl;
	cout << "��: " << t.day << endl;
	cout << "��: " << t.week << endl;
	cout << "��: " << t.month << endl;
	cout << "��: " << t.year << endl;

	cout << "Լ: " << t.times << endl;

	return cout;
}