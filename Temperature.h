#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Temp& t)
{
	cout << t.C << "摄氏度" << endl;
	cout << t.F << "华氏度" << endl;
	if (t.K <= 0.00001 && t.K)
	{
		cout << "<0.00001开尔文" << endl;
	}
	else
	{
		cout << t.K << "开尔文" << endl;
	}
	if (t.R <= 0.00001 && t.R)
	{
		cout << "<0.00001兰氏度" << endl;
	}
	else
	{
		cout << t.R << "兰氏度" << endl;
	}

	return cout;
}