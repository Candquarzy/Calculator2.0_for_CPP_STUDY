#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Speed& s)
{
	cout << s.ms << "m/s" << endl;
	cout << s.kmh << "km/h" << endl;
	cout << s.mph << "mph" << endl;

	return cout;
}