#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, BMI& b)
{
	cout << fixed << setprecision(2);

	cout << "����:" << b.name << " ����:" << b.age << endl;
	cout << "����:" << b.weight << "kg ���:" << b.height << "m " << endl;
	cout << "����BMI��" << b.bmi << endl;
	cout << b.results << endl;
	cout << "��Ӧ�ð�������ؿ�����" << b.left << "kg~" << b.right << "kg��Χ��" << endl;

	return cout;
}