#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, BMI& b)
{
	cout << fixed << setprecision(2);

	cout << "姓名:" << b.name << " 年龄:" << b.age << endl;
	cout << "体重:" << b.weight << "kg 身高:" << b.height << "m " << endl;
	cout << "您的BMI是" << b.bmi << endl;
	cout << b.results << endl;
	cout << "你应该把你的体重控制在" << b.left << "kg~" << b.right << "kg范围内" << endl;

	return cout;
}