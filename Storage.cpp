#include "class.h"
#include "Storage.h"

//字符串分类成员函数
int Storage::Classify(string str, Storage& s)
{
	string::iterator it = find_if(str.begin(), str.end(), [](char ch)
		{
			return ch >= 'A';
		});

	string sstr = str.substr(distance(str.begin(), it));
	string unit[24] = { "bit","Bit","BIT","byte","BYTE","Byte","KB","kb","Kb","MB","mb","Mb","GB","gb","Gb","TB","Tb","tb","PB","pb","Pb","EB","eb","Eb"};
	int res = 0;
	for (int i = 0; i < sizeof(unit) / sizeof(unit[0]); i++)
	{
		if (sstr == unit[i] || sstr == unit[++i] || sstr == unit[++i])
		{
			switch (i)
			{
			case 0:
			case 1:
			case 2:
				stringstream(str) >> s.bit;
				s.bit > 0 ? res = 1 : res = 0;
				s.count[0] = 1;
				break;
			case 3:
			case 4:
			case 5:
				stringstream(str) >> s.byte;
				s.byte > 0 ? res = 1 : res = 0;
				s.count[1] = 1;
				break;
			case 6:
			case 7:
			case 8:
				stringstream(str) >> s.KB;
				s.KB > 0 ? res = 1 : res = 0;
				s.count[2] = 1;
				break;
			case 9:
			case 10:
			case 11:
				stringstream(str) >> s.MB;
				s.MB > 0 ? res = 1 : res = 0;
				s.count[3] = 1;
				break;
			case 12:
			case 13:
			case 14:
				stringstream(str) >> s.GB;
				s.GB > 0 ? res = 1 : res = 0;
				s.count[4] = 1;
				break;
			case 15:
			case 16:
			case 17:
				stringstream(str) >> s.TB;
				s.TB > 0 ? res = 1 : res = 0;
				s.count[5] = 1;
				break;
			case 18:
			case 19:
			case 20:
				stringstream(str) >> s.PB;
				s.PB > 0 ? res = 1 : res = 0;
				s.count[6] = 1;
				break;
			case 21:
			case 22:
			case 23:
				stringstream(str.substr(0, distance(str.begin(), it))) >> s.EB;
				s.EB > 0 ? res = 1 : res = 0;
				s.count[7] = 1;
				break;
			}
		}
		if (res)
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

//数据转换成员函数
void Storage::Calcu(Storage& s)
{
	for (int i = 0; i < sizeof(s.count) / sizeof(s.count[0]); i++)
	{
		if (s.count[i])
		{
			switch (i)
			{
			case 0: //bit
				s.byte = s.bit / 8;
				s.KB = s.byte / 1024.0;
				s.MB = s.KB / 1024;
				s.GB = s.MB / 1024;
				s.TB = s.GB / 1024;
				s.PB = s.TB / 1024;
				s.EB = s.PB / 1024;
				break;
			case 1: //byte
				s.bit = s.byte * 8;

				s.KB = s.byte / 1024.0;
				s.MB = s.KB / 1024;
				s.GB = s.MB / 1024;
				s.TB = s.GB / 1024;
				s.PB = s.TB / 1024;
				s.EB = s.PB / 1024;
				break;
			case 2: //KB
				s.byte = s.KB * 1024;
				s.bit = s.byte * 8;

				s.MB = s.KB / 1024;
				s.GB = s.MB / 1024;
				s.TB = s.GB / 1024;
				s.PB = s.TB / 1024;
				s.EB = s.PB / 1024;
				break;
			case 3: //MB
				s.KB = s.MB * 1024;
				s.byte = s.KB * 1024;
				s.bit = s.byte * 8;

				s.GB = s.MB / 1024;
				s.TB = s.GB / 1024;
				s.PB = s.TB / 1024;
				s.EB = s.PB / 1024;
				break;
			case 4: //GB
				s.MB = s.GB * 1024;
				s.KB = s.MB * 1024;
				s.byte = s.KB * 1024;
				s.bit = s.byte * 8;

				s.TB = s.GB / 1024;
				s.PB = s.TB / 1024;
				s.EB = s.PB / 1024;
				break;
			case 5: //TB
				s.GB = s.TB * 1024;
				s.MB = s.GB * 1024;
				s.KB = s.MB * 1024;
				s.byte = s.KB * 1024;
				s.bit = s.byte * 8;

				s.PB = s.TB / 1024;
				s.EB = s.PB / 1024;
				break;
			case 6: //PB
				s.TB = s.PB * 1024;
				s.GB = s.TB * 1024;
				s.MB = s.GB * 1024;
				s.KB = s.MB * 1024;
				s.byte = s.KB * 1024;
				s.bit = s.byte * 8;

				s.EB = s.PB / 1024;
				break;
			case 7: //EB
				s.PB = s.EB * 1024;
				s.TB = s.PB * 1024;
				s.GB = s.TB * 1024;
				s.MB = s.GB * 1024;
				s.KB = s.MB * 1024;
				s.byte = s.KB * 1024;
				s.bit = s.byte * 8;
				break;
			}
			break;
		}
	}
}

//存储历史记录成员函数
void Storage::Save_history(Storage& s)
{
	s.Data.push_back(s);
}

//返回容器成员函数
vector<Storage> Storage::Return_Vector(Storage& s)
{
	return s.Data;
}

//显示历史记录成员函数
void Storage::Display_history(vector<Storage> p)
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

//计算机数据转换主函数
void Storage_Calcu(Storage& s)
{
	while (1)
	{
		string input;
		cout << "请输入一个计算机数据大小" << endl;
		cout << "最大支持到EB,例如:1TB/1Tb/1T(未实现)/1t(未实现)" << endl;
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