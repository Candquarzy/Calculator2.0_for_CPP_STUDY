#pragma once

#include "class.h"

ostream& operator<<(ostream& cout, Time& t)
{
	cout << "ת��ǰ: " << t.input_data.back() << endl;
	cout << "ת����: " << t.output_data.back() << endl;
	
	return cout;
}


