#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Length& l)
{
	cout << l.um << "΢��" << endl;
	cout << l.mm << "����" << endl;
	cout << l.cm << "����" << endl;
	cout << l.fm << "����" << endl;
	cout << l.m << "��" << endl;
	cout << l.chi << "��" << endl;
	cout << l.cun << "��" << endl;
	cout << l.km << "ǧ��" << endl;
	cout << l.in << "Ӣ��" << endl;
	cout << l.ft << "Ӣ��" << endl;
	cout << l.mi << "Ӣ��" << endl;

	return cout;
}