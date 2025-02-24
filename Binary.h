#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Binary& b)
{
	cout << "输入的十进制数为: " << b.DEC << endl;
	cout << "二进制原码: " << b.BIN_O << endl;
	cout << "二进制反码: " << b.BIN_F << endl;
	cout << "二进制补码: " << b.BIN_B << endl;
	if (!b.Decimals)
	{
		cout << "二进制移码: " << b.BIN_Y << endl;
	}

	return cout;
}