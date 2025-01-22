#include "class.h"

//用户输入分类成员函数
double Area::Classify(string str, Area& a)
{
	string::iterator letter = find_if(str.begin(), str.end(), [](char ch)
		{
			return ch >= 'A';
		});
	string::iterator symbols = find(str.begin(), str.end(), '-');

	if (letter == str.end() || symbols == str.end())
	{
		cout << "数据输入都输不明白?" << endl;
		return 0;
	}

	string str_arr[6] = { "mm","cm","m","ha","km","mu" };
	string Old = str.substr(distance(str.begin(), letter), distance(letter, symbols));
	string New = str.substr(distance(str.begin(), symbols) + 1, distance(symbols, str.end()));
	for (int i = 0; i < sizeof(str_arr) / sizeof(str_arr[0]); i++)
	{
		if (!Old.compare(str_arr[i]))
		{
			a.old_count[i] = 1;
		}
		if (!New.compare(str_arr[i]))
		{
			a.new_count[i] = 1;
		}
	}

	double sum;
	stringstream(str) >> sum;
	return sum;
}

//面积计算成员函数
void Area::Calcu(double sum, Area& a)
{
	string str_arr[6] = { "平方毫米","平方厘米","平米","公顷","平方千米","亩" };

	stringstream ss;
	ss << fixed << setprecision(3) << sum;
	for (int i = 0; i < sizeof(a.old_count) / sizeof(a.old_count[0]); i++)
	{
		if (a.old_count[i])
		{
			cout << sum << str_arr[i] << " = ";
			a.Data.push_back(ss.str());
			a.Data.back() += str_arr[i];
			a.Data.back() += " = ";
			switch (i)
			{
			case 0: //毫米
				a.mm = sum;
				a.cm = a.mm / 100;
				a.m = a.cm / 100;
				break;
			case 1: //厘米
				a.cm = sum;
				a.m = a.cm / 100;
				break;
			case 2: //米
				a.m = sum;
				break;
			case 3: //公顷
				a.ha = sum;
				a.m = a.ha * 10000;
				break;
			case 4: //千米
				a.km = sum;
				a.m = a.km * 1000000;
				break;
			case 5: //亩
				a.mu = sum;
				a.m = a.mu * 2000 / 3; //?
				break;
			}
			a.old_count[i] = 0;
			break;
		}
	}

	ss.str("");
	ss.clear();
	for (int i = 0; i < sizeof(a.new_count) / sizeof(a.new_count[0]); i++)
	{
		if (a.new_count[i])
		{
			switch (i)
			{
			case 0:
				a.cm = a.m * 10000;
				a.mm = a.cm * 100;
				if (a.mm >= 100000)
				{
					cout << fixed << a.mm;
				}
				else
				{
					cout << a.mm;
				}
				ss << fixed << setprecision(3) << a.mm;
				a.Data.back() += ss.str();
				break;
			case 1:
				a.cm = a.m * 10000;
				if (a.cm >= 100000)
				{
					cout << fixed << a.cm;
				}
				else
				{
					cout << a.cm;
				}
				ss << fixed << setprecision(3) << a.cm;
				a.Data.back() += ss.str();
				break;
			case 2:
				if (a.m >= 100000)
				{
					cout << fixed << a.m;
				}
				else
				{
					cout << a.m;
				}
				ss << fixed << setprecision(3) << a.m;
				a.Data.back() += ss.str();
				break;
			case 3:
				a.ha = a.m / 10000;
				cout << a.ha;
				ss << fixed << setprecision(3) << a.ha;
				a.Data.back() += ss.str();
				break;
			case 4:
				a.km = a.m / 1000000;
				cout << a.km;
				ss << fixed << setprecision(3) << a.km;
				a.Data.back() += ss.str();
				break;
			case 5: //?
				a.mu = a.m * 3 / 2000;
				cout << a.mu;
				ss << fixed << setprecision(5) << a.mu;
				a.Data.back() += ss.str();
				break;
			}
			cout << str_arr[i] << endl;
			a.Data.back() += str_arr[i];
			a.new_count[i] = 0;
			break;
		}
	}
	cout << endl;
}

//返回容器成员函数
vector<string> Area::Return_Vector(Area& a)
{
	return a.Data;
}

//显示历史记录成员函数
void Area::Display_history(vector<string> p)
{
	if (!p.size())
	{
		cout << "历史记录为空" << endl;
		cout << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << i + 1 << ". " << p[i] << endl;
	}
	cout << endl;
}

//面积计算器主函数
void Area_Calcu(Area& a)
{
	while (1)
	{
		string input;
		cout << "请输入你要转换的数据,并附带单位再使用-链接你要转换后的单位" << endl;
		cout << "例:100cm-mm 其中100cm为你要转换的数据,mm为你要转换后的单位" << endl;
		cout << "支持mm平方毫米 cm平方厘米 m平方米 ha公顷 km平方千米 mu亩" << endl;
		cout << "(*输入亩可能丢失转换精度)	输入s查看历史记录 输入e返回主菜单" << endl;
		cin >> input;
		cout << endl;

		if (input.length() == 1)
		{
			const char* s = input.c_str();
			switch (*s)
			{
			case 's':
				a.Display_history(a.Return_Vector(a));
				break;
			case 'e':
				return;
				break;
			}
		}
		else
		{
			double sum = a.Classify(input, a);
			if (sum)
			{
				a.Calcu(sum, a);
			}
		}
	}
}