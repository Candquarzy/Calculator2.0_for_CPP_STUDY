#pragma once

ostream& operator<<(ostream& cout, Four_fun& f)
{
	int i = 0;
	int j = 0;
	//if (i >= f.maths.size() || j >= f.symbols.size())
	//{
	//	break;
	//}
	//cout << f.maths[i];
	//cout << f.symbols[j++];
	//cout << f.maths[++i] << endl;
	for (int i = 0; i < f.maths.size(); i++)
	{
		cout << f.maths[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < f.symbols.size(); i++)
	{
		cout << f.symbols[i] << " ";
	}
	return cout;
}