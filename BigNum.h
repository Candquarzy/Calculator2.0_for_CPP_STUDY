#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, BigNum& n)
{
	cout << "ะกะด: ";
	if (n.count)
	{
		cout << n.count << endl;
	}
	else
	{
		cout << n.sum << endl;
	}

	cout << "ด๓ะด: " << n.math << endl;

	return cout;
}