#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Sys_Carry& s)
{
	cout << "二进制: " << s.BIN << endl;
	cout << "八进制: " << s.OCT << endl;
	cout << "十进制: " << s.DEC << endl;
	cout << "十六进制: " << s.HEX << endl;
	
	return cout;
}