#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Sys_Carry& s)
{
	cout << "������: " << s.BIN << endl;
	cout << "�˽���: " << s.OCT << endl;
	cout << "ʮ����: " << s.DEC << endl;
	cout << "ʮ������: " << s.HEX << endl;
	
	return cout;
}