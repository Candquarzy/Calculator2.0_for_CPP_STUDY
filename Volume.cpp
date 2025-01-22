#include "class.h"

//用户输入分类成员函数
double Volume::Classify(string str, Volume& v)
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

	string str_arr[6] = { "mm","cm","dm","m","L","ml"};
	string Old = str.substr(distance(str.begin(), letter), distance(letter, symbols));
	string New = str.substr(distance(str.begin(), symbols) + 1, distance(symbols, str.end()));
	for (int i = 0; i < sizeof(str_arr) / sizeof(str_arr[0]); i++)
	{
		if (!Old.compare(str_arr[i]))
		{
			v.old_count[i] = 1;
		}
		if (!New.compare(str_arr[i]))
		{
			v.new_count[i] = 1;
		}
	}

	double sum;
	stringstream(str) >> sum;
	return sum;
}

//体积计算器成员函数
void Volume::Calcu(double sum, Volume& v)
{
	string str_arr[6] = { "立方毫米","立方厘米","立方分米","立方米","升","毫升" };

	stringstream ss;
	ss << fixed << setprecision(3) << sum;
	for (int i = 0; i < sizeof(v.old_count) / sizeof(v.old_count[0]); i++)
	{
		if (v.old_count[i])
		{
			cout << sum << str_arr[i] << " = ";
			v.Data.push_back(ss.str());
			v.Data.back() += str_arr[i];
			v.Data.back() += " = ";
			switch (i)
			{
			case 0: //毫米
				v.mm = sum;
				v.cm = v.mm / 1000;
				break;
			case 1: //厘米
				v.cm = sum;
				break;
			case 2: //分米
				v.dm = sum;
				v.cm = v.dm * 1000;
				break;
			case 3: //米
				v.m = sum;
				v.dm = v.m * 1000;
				v.cm = v.dm * 1000;
				break;
			case 4: //升
				v.L = sum;
				v.cm = v.L * 1000;
				break;
			case 5: //毫升
				v.ml = sum;
				v.cm = v.ml;
				break;
			}
			v.old_count[i] = 0;
			break;
		}
	}

	ss.str("");
	ss.clear();
	for (int i = 0; i < sizeof(v.new_count) / sizeof(v.new_count[0]); i++)
	{
		if (v.new_count[i])
		{
			switch (i)
			{
			case 0:
				v.mm = v.cm * 1000;
				if (v.mm >= 100000)
				{
					cout << fixed << v.mm;
				}
				else
				{
					cout << v.mm;
				}
				ss << fixed << setprecision(3) << v.mm;
				v.Data.back() += ss.str();
				break;
			case 1:
				if (v.cm >= 100000)
				{
					cout << fixed << v.cm;
				}
				else
				{
					cout << v.cm;
				}
				ss << fixed << setprecision(3) << v.cm;
				break;
			case 2:
				v.dm = v.cm / 1000;
				if (v.dm >= 100000)
				{
					cout << fixed << v.dm;
				}
				else
				{
					cout << v.dm;
				}
				ss << fixed << setprecision(3) << v.dm;
				v.Data.back() += ss.str();
				break;
			case 3:
				v.dm = v.cm / 1000;
				v.m = v.dm / 1000;
				cout << v.m;
				ss << fixed << setprecision(3) << v.m;
				v.Data.back() += ss.str();
				break;
			case 4:
				v.L = v.cm / 1000;
				cout << v.L;
				ss << fixed << setprecision(3) << v.L;
				v.Data.back() += ss.str();
				break;
			case 5:
				v.ml = v.cm;
				cout << v.ml;
				ss << fixed << setprecision(3) << v.ml;
				v.Data.back() += ss.str();
				break;
			}
			cout << str_arr[i] << endl;
			v.Data.back() += str_arr[i];
			v.new_count[i] = 0;
			break;
		}
	}
	cout << endl;
}

//返回容器成员函数
vector<string> Volume::Return_Vector(Volume& v)
{
	return v.Data;
}

//显示历史记录成员函数
void Volume::Display_history(vector<string> p)
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

//体积转换计算器主函数
void Volume_Calcu(Volume& v)
{
	while (1)
	{
		string input;
		cout << "请输入你要转换的数据,并附带单位再使用-链接你要转换后的单位" << endl;
		cout << "例:10L-ml 其中100cm为你要转换的数据,mm为你要转换后的单位" << endl;
		cout << "支持mm立方毫米 cm立方厘米 dm立方分米 m立方米 L升 ml毫升" << endl;
		cout << "(*输入?????可能丢失转换精度)	输入s查看历史记录 输入e返回主菜单" << endl;
		cin >> input;
		cout << endl;

		if (input.length() == 1)
		{
			const char* s = input.c_str();
			switch (*s)
			{
			case 's':
				v.Display_history(v.Return_Vector(v));
				break;
			case 'e':
				return;
				break;
			}
		}
		else
		{
			double sum = v.Classify(input, v);
			if (sum)
			{
				v.Calcu(sum, v);
			}
		}
	}
}