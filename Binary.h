#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Binary& b)
{
	cout << "�����ʮ������Ϊ: " << b.DEC << endl;
	cout << "������ԭ��: " << b.BIN_O << endl;
	cout << "�����Ʒ���: " << b.BIN_F << endl;
	cout << "�����Ʋ���: " << b.BIN_B << endl;
	if (!b.Decimals)
	{
		cout << "����������: " << b.BIN_Y << endl;
	}

	return cout;
}