#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Time& t)
{
	cout << "转换前: " << t.input_data.back() << endl;
	cout << "转换后: " << t.output_data.back() << endl;
	
	return cout;
}


