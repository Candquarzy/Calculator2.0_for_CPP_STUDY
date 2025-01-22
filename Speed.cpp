#include "class.h"
#include "speed.h"

//用户输入分类成员函数
int Speed::Classify(string str, Speed& s)
{
	string::iterator it = find_if(str.begin(), str.end(), [](char ch)
		{
			return ch >= 'A';
		});

	string sstr = str.substr(distance(str.begin(), it), str.size() - 1);
	string unit[3] = { "ms","kmh","mph" };
	int res = 0;
	for (int i = 0; i < sizeof(unit) / sizeof(unit[0]); i++)
	{
		if (sstr == unit[i])
		{
			switch (i)
			{
			case 0:
				stringstream(str) >> s.ms;
				s.ms > 0 ? res = 1 : res = 0;
				s.count[0] = 1;
				break;
			case 1:
				stringstream(str) >> s.kmh;
				s.kmh > 0 ? res = 1 : res = 0;
				s.count[1] = 1;
				break;
			case 2:
				stringstream(str) >> s.mph;
				s.mph > 0 ? res = 1 : res = 0;
				s.count[2] = 1;
				break;
			}
		}
		if(res)
		{
			break;
		}
	}
	if (!res)
	{
		cout << "你输入的什么勾巴?" << endl;
		cout << "看清楚再输入行不行?杂鱼~" << endl;
		cout << endl;
		return 0;
	}
	return 1;
}

//速度转换计算成员函数
void Speed::Calcu(Speed& s)
{
	for (int i = 0; i < sizeof(s.count) / sizeof(s.count[0]); i++)
	{
		if (s.count[i])
		{
			switch (i)
			{
			case 0:
				s.kmh = s.ms * 3.6;
				s.mph = s.ms * 2.237;
				break;
			case 1:
				s.ms = s.kmh * 1000 / 3600;
				s.mph = s.kmh * 0.621;
				break;
			case 2:
				s.ms = s.mph * 0.447;
				s.kmh = s.mph * 1.60934;
				break;
			}
			break;
		}
	}
}

//存储历史记录成员函数
void Speed::Save_history(Speed& s)
{
	s.Data.push_back(s);
}

//返回容器成员函数
vector<Speed> Speed::Return_Vector(Speed& s)
{
	return s.Data;
}

//显示历史记录成员函数
void Speed::Display_history(vector<Speed> p)
{
	if (!p.size())
	{
		cout << "历史记录为空" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << i + 1 << endl;
		cout << p[i] << endl;
	}
}

//速度转换计算器主函数
void Speed_Calcu(Speed& s)
{
	while (1)
	{
		string input;
		cout << "请输入一个速度数据 (输入英里与输入其他数据转换后的英里数值可能存在精度问题)" << endl;
		cout << "支持ms米/秒 kmh千米/小时 mph英里/小时" << endl;
		cout << "输入s查看历史记录 输入e返回主菜单" << endl;
		cin >> input;
		cout << endl;
		if (input.length() == 1)
		{
			const char* c = input.c_str();
			switch (*c)
			{
			case 's':
				s.Display_history(s.Return_Vector(s));
				break;
			case 'e':
				return;
			}
		}
		else
		{
			if (s.Classify(input, s))
			{
				s.Calcu(s);
				cout << s << endl;
				s.Save_history(s);
			}
		}
	}
}