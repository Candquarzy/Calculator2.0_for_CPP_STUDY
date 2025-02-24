#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, BigNum& n)
{
	cout << "Сд: ";
	if (n.count)
	{
		cout << n.count << endl;
	}
	else
	{
		cout << n.sum << endl;
	}

	cout << "��д: " << n.math << endl;

	return cout;
}