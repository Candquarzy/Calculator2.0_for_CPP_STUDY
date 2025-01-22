#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Length& l)
{
	cout << l.um << "微米" << endl;
	cout << l.mm << "毫米" << endl;
	cout << l.cm << "厘米" << endl;
	cout << l.fm << "分米" << endl;
	cout << l.m << "米" << endl;
	cout << l.chi << "尺" << endl;
	cout << l.cun << "寸" << endl;
	cout << l.km << "千米" << endl;
	cout << l.in << "英寸" << endl;
	cout << l.ft << "英尺" << endl;
	cout << l.mi << "英里" << endl;

	return cout;
}