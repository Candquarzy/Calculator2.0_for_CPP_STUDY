#include "class.h"
#include "Temperature.h"

//用户输入分类成员函数
int Temp::Classify(string str, Temp& t)
{
	char s = str[str.size() - 1];

	switch (s)
	{
	case 'C':
	case 'c':
		stringstream(str) >> t.C;
		t.count[0] = 1;
		break;
	case 'F':
	case 'f':
		stringstream(str) >> t.F;
		t.count[1] = 1;
		break;
	case 'K':
	case 'k':
		stringstream(str) >> t.K;
		t.count[2] = 1;
		break;
	case 'R':
	case 'r':
		stringstream(str) >> t.R;
		t.count[3] = 1;
		break;
	default:
		cout << "你输入的什么勾巴?" << endl;
		cout << "看清楚再输入行不行?杂鱼~" << endl;
		cout << endl;
		return 0;
	}

	return 1;
}

//温度转换计算器成员函数
void Temp::Calcu(Temp& t)
{
	for (int i = 0; i < sizeof(t.count) / sizeof(t.count[0]); i++)
	{
		if (t.count[i])
		{
			switch (i)
			{
			case 0:
				t.F = t.C * 9 / 5.0 + 32;
				t.K = t.C + 273.15;
				t.R = t.F + 459.67;
				break;
			case 1:
				t.C = (t.F - 32) * 5 / 9.0;
				t.K = t.C + 273.15;
				t.R = t.F + 459.67;
				break;
			case 2:
				t.C = t.K - 273.15;
				t.F = t.C * 9 / 5.0 + 32;
				t.R = t.F + 459.67;
				break;
			case 3:
				t.F = t.R - 459.67;
				t.C = (t.F - 32) * 5 / 9.0;
				t.K = t.C + 273.15;
				break;
			}
			break;
		}
	}
}

//存储历史记录成员函数
void Temp::Save_history(Temp& t)
{
	t.Data.push_back(t);
}

//返回历史记录容器成员函数
vector<Temp> Temp::Return_Vector(Temp& t)
{
	return t.Data;
}

//显示历史记录成员函数
void Temp::Display_history(vector<Temp> p)
{
	if (!p.size())
	{
		cout << "历史记录为空" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << "编号:" << i + 1 << endl;
		cout << p[i] << endl;
	}
}

//温度转换主函数
void Temp_Calcu(Temp& t)
{
	while (1)
	{
		string input;
		cout << "请输入一个温度数据 例如:28C/28c(即28摄氏度)" << endl;
		cout << "支持C摄氏度 F华氏度 K开尔文 R兰氏度" << endl;
		cout << "输入s查看历史记录 输入e返回主菜单" << endl;
		cin >> input;
		cout << endl;
		if (input.length() == 1)
		{
			const char* s = input.c_str();
			switch (*s)
			{
			case 's':
				t.Display_history(t.Return_Vector(t));
				break;
			case 'e':
				return;
			}
		}
		else
		{
			if (t.Classify(input, t))
			{
				t.Calcu(t);
				cout << t << endl;
				t.Save_history(t);

			}
		}
	}
}