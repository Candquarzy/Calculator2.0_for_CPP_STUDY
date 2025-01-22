#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Time& t)
{
	cout << "转换后:" << endl;
	cout << "秒: " << t.sencond << endl;
	cout << "分: " << fixed << t.minute << endl;
	cout << "时: " << t.hour << endl;
	cout << "天: " << t.day << endl;
	cout << "周: " << t.week << endl;
	cout << "月: " << t.month << endl;
	cout << "年: " << t.year << endl;

	cout << "约: " << t.times << endl;

	return cout;
}