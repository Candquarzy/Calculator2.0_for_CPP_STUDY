#include "class.h"
#include "Time.h"

//分类整理成员函数
int Time::Classify(string str, Time& t)
{
	string::iterator it = find(str.begin(), str.end(), '-');
	if (it == str.end())
	{
		cout << "输入有误,请添加要转换后的单位" << endl;
		return 0;
	}
	int start = distance(str.begin(), it);
	char s = str.c_str()[start + 1];
	switch (s)
	{
	case 's':
		t.count[0] = 1;
		break;
	case 'f':
		t.count[1] = 1;
		break;
	case 'h':
		t.count[2] = 1;
		break;
	case 'd':
		t.count[3] = 1;
		break;
	case 'w':
		t.count[4] = 1;
		break;
	case 'm':
		t.count[5] = 1;
		break;
	case 'y':
		t.count[6] = 1;
		break;
	}
	str.erase(start, str.size());
	t.Input_Tostring(str, t, 0);

	while (str.length())
	{
		double sum = stod(str);
		string::iterator it = find_if(str.begin(), str.end(), [](char ch)
			{
				return ch >= 'a';
			});
		int last = distance(str.begin(), it);
		char s = str.c_str()[last];

		switch (s)
		{
		case 's':
			t.sencond = sum;
			t.sum[0] = 1;
			break;
		default:
		case 'f':
			t.minute = sum;
			t.sum[1] = 1;
			break;
		case 'h':
			t.hour = sum;
			t.sum[2] = 1;
			break;
		case 'd':
			t.day = sum;
			t.sum[3] = 1;
			break;
		case 'w':
			t.week = sum;
			t.sum[4] = 1;
			break;
		case 'm':
			t.month = sum;
			t.sum[5] = 1;
			break;
		case 'y':
			t.year = sum;
			t.sum[6] = 1;
			break;

		}
		str.erase(0, last + 1);
	}
	return 1;
}

//输入分类整理成员函数
void Time::Input_Tostring(string str, Time& t, int count)
{
	string sstr;
	while (str.length())
	{
		string::iterator it = find_if(str.begin(), str.end(), [](char ch)
			{
				return ch >= 'a';
			});
		int last = distance(str.begin(), it);
		char s = str.c_str()[last];
		sstr += str.substr(0, last);

		switch (s)
		{
		case 's':
			sstr += "秒";
			break;
		default:
		case 'f':
			sstr += "分";
			break;
		case 'h':
			sstr += "时";
			break;
		case 'd':
			sstr += "天";
			break;
		case 'w':
			sstr += "周";
			break;
		case 'm':
			sstr += "月";
			break;
		case 'y':
			sstr += "年";
			break;
		}

		if (count)
		{
			t.output_data.push_back(sstr);
		}
		else
		{
			t.input_data.push_back(sstr);
		}
		str.erase(0, last + 1);
	}
}

//时间转换器成员函数
void Time::Time_Transfrom(Time& t)
{
	int last; //转换前
	int num; //转换后
	string str;
	for (int i = 0; i <= sizeof(t.sum) / sizeof(t.sum[0]); i++)
	{
		if (t.sum[i])
		{
			last = i;
		}
	}
	for (int i = 0; i <= sizeof(t.count) / sizeof(t.count[0]); i++)
	{
		if (t.count[i])
		{
			num = i;
			break;
		}
	}
	//int power[7] = { 12,4,7,24,60,60,60 };
	if (last >= num)
	{
		switch (num)
		{
		case 0:
			t.day += t.year * 365 + t.month * 30 + t.week * 7;
			t.hour += t.day * 24;
			t.minute += t.hour * 60;
			t.sencond += t.minute * 60;
			str += to_string(t.sencond) += 's';
			break;
		case 1:
			t.day += t.year * 365 + t.month * 30 + t.week * 7;
			t.hour += t.day * 24;
			t.minute += t.hour * 60;
			str += to_string(t.minute) += 'f';
			break;
		case 2:
			t.day += t.year * 365 + t.month * 30 + t.week * 7;
			t.hour += t.day * 24;
			str += to_string(t.hour) += 'h';
			break;
		case 3:
			t.day += t.year * 365 + t.month * 30 + t.week * 7;
			str += to_string(t.day) += 'd';
			break;
		case 4:
			t.month += t.year * 12;
			t.week += t.month * 4;
			str += to_string(t.week) += 'w';
			break;
		case 5:
			t.month += t.year * 12;
			str += to_string(t.month) += 'm';
			break;
		case 6:
			str += to_string(t.year) += 'y';
			break;
		}
	}
	else if (last < num)
	{
		switch (num)
		{
		case 0:
			str += to_string(t.sencond) += 's';
			break;
		case 1:
			t.minute += t.sencond / 60.0;
			str += to_string(t.minute) += 'f';
			break;
		case 2:
			t.minute += t.sencond / 60.0;
			t.hour += t.minute / 60.0;
			str += to_string(t.hour) += 'h';
			break;
		case 3:
			t.minute += t.sencond / 60.0;
			t.hour += t.minute / 60.0;
			t.day += t.hour / 24.0;
			str += to_string(t.day) += 'd';
			break;
		case 4:
			t.minute += t.sencond / 60.0;
			t.hour += t.minute / 60.0;
			t.day += t.hour / 24.0;
			t.week += t.day / 7.0;
			str += to_string(t.week) += 'w';
			break;
		case 5:
			t.minute += t.sencond / 60.0;
			t.hour += t.minute / 60.0;
			t.day += t.hour / 24.0;
			t.week += t.day / 7.0;
			t.month += t.week / 4.0;
			str += to_string(t.month) += 'm';
			break;
		case 6:
			t.minute += t.sencond / 60.0;
			t.hour += t.minute / 60.0;
			t.day += t.hour / 24.0;
			t.week += t.day / 7.0;
			t.month += t.week / 4.0;
			t.year += t.month / 12.0;
			str += to_string(t.year) += 'y';
			break;
		}
	}
	t.Input_Tostring(str, t, 1);
}

//时间转换计算器主函数
void Time_Calcu(Time& t)
{
	string input;
	cout << "请输入你哟啊转换数据，并附带单位再使用-链接你要转换后的单位" << endl;
	cout << "单位: s:秒 f:分 h:时 d:天 w:周 m:月 y:年 (默认为分钟)" << endl;
	cout << "也可以输入xx年xx月xx周xx天 如:4m3w10d20h" << endl;
	cin >> input;
	if (t.Classify(input, t))
	{
		t.Time_Transfrom(t);
		cout << t << endl;
	}
	//未写放入output_data的代码
}