#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Storage& s)
{
	cout << s.bit << " bit" << endl;
	cout << s.byte << " byte" << endl;
	cout << fixed << setprecision(5) << s.KB << " KB" << endl;
	cout << fixed << setprecision(5) << s.MB << " MB" << endl;
	if (s.GB > 0.00001)
	{
		cout << fixed << setprecision(5) << s.GB << " GB" << endl;
	}
	else if (s.TB > 0.00001)
	{
		cout << fixed << setprecision(5) << s.TB << " TB" << endl;
	}
	else if (s.PB > 0.001)
	{
		cout << fixed << setprecision(5) << s.PB << " PB" << endl;
	}
	else if(s.EB > 0.001)
	{
		cout << fixed << setprecision(5) << s.EB << " EB" << endl;
	}

	return cout;
}