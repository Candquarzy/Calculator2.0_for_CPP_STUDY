#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Temp& t)
{
	cout << t.C << "���϶�" << endl;
	cout << t.F << "���϶�" << endl;
	if (t.K <= 0.00001 && t.K)
	{
		cout << "<0.00001������" << endl;
	}
	else
	{
		cout << t.K << "������" << endl;
	}
	if (t.R <= 0.00001 && t.R)
	{
		cout << "<0.00001���϶�" << endl;
	}
	else
	{
		cout << t.R << "���϶�" << endl;
	}

	return cout;
}