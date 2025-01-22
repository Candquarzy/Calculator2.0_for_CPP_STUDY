#include "class.h"
#include "Time.h"

//分类整理成员函数
void Time::Classify(string str, Time& t)
{
	double sum = stod(str);

	string::iterator it = find_if(str.begin(), str.end(), [](char ch)
		{
			return ch >= 'a';
		});
	string sstr = str.substr(0, distance(str.begin(), it));

	//if ((to_string(sum).compare(str.substr(0, str.size() - 1))))
	if (sstr.compare(str.substr(0, str.size() - 1)))
	{
		t.times = str;
		t.Times_Transfrom(t);
		//t.All_Times(t);
	}
	else
	{
		switch (str[str.size() - 1])
		{
		case 's':
			t.sencond = sum;
			t.count[0] = 1;
			break;
		default:
		case 'f':
			t.minute = sum;
			t.count[1] = 1;
			break;
		case 'h':
			t.hour = sum;
			t.count[2] = 1;
			break;
		case 'd':
			t.day = sum;
			t.count[3] = 1;
			break;
		case 'w':
			t.week = sum;
			t.count[4] = 1;
			break;
		case 'm':
			t.month = sum;
			t.count[5] = 1;
			break;
		case 'y':
			t.year = sum;
			t.count[6] = 1;
			break;
		}
		t.All_Times(t);
		t.Time_Transfrom(t);
	}
}

//计算总时间函数
void Time::All_Times(Time& t)
{
	//判断总共时长多久
	Time t1 = t;
	for (int i = 0; i < sizeof(t.count) / sizeof(t.count[0]); i++)
	{
		if (t.count[i])
		{
			switch (i)
			{
			case 0:
				while (t1.sencond > 60)
				{
					t1.minute++;
					t1.sencond -= 60;
				}
			case 1:
				while (t1.minute > 60)
				{
					t1.hour++;
					t1.minute -= 60;
				}
			case 2:
				while (t1.hour > 24)
				{
					t1.day++;
					t1.hour -= 24;
				}
			case 3:
				while (t1.day >= 365)
				{
					t1.year++;
					t1.day -= 365;
				}
				while (t1.day >= 30)
				{
					t1.month++;
					t1.day -= 30;
				}
				while (t1.day >= 7)
				{
					t1.week++;
					t1.day -= 7;
				}
			case 4:
				while (t1.week >= 48)
				{
					t1.year++;
					t1.week -= 48;
				}
				while (t1.week >= 4)
				{
					t1.month++;
					t1.week -= 4;
				}
			case 5:
				while (t1.month >= 12)
				{
					t1.year++;
					t1.month -= 12;
				}
				break;
			case 6:
				break;
			}
			break;
		}
	}
	t.Times_String(t1, t);
}

//时间转换成员函数
void Time::Time_Transfrom(Time& t)
{
	int res = 0;
	for (int i = 0; i < sizeof(t.count) / sizeof(t.count[0]); i++)
	{
		if (t.count[i])
		{
			double sum;
			switch (i)
			{
			case 0:
				t.minute = t.sencond / 60.0;
				res = 0;
				break;
			case 1:
				res = 0;
				break;
			case 2:
				t.minute = t.hour * 60;
				res = 0;
				break;
			case 3:
				if (!((int)t.day % 365))
				{
					t.year = t.day / 365;
				}
				else
				{
					t.year = t.day / 365.0;
				}
				//sum = t.day;
				//while (sum >= 365)
				//{
				//	t.year++;
				//	sum -= 365;
				//}
				//if (sum < 365)
				//{
				//	t.year += (sum / 365);
				//}

				//t.month = t.year * 12;
				//t.week = t.month * 4;
				
				//sum = t.day;
				//while (sum >= 30)
				//{
				//	t.month++;
				//	sum -= 30;
				//}
				//if (sum < 30)
				//{
				//	t.month += (sum / 30);
				//}
				//t.week = t.month * 4;
				//t.year = t.month / 12;
				//sum = t.day;
				//while (sum >= 7)
				//{
				//	t.week++;
				//	sum -= 7;
				//}
				//if (sum < 7)
				//{
				//	t.week += (sum / 7);
				//}
				res = 1;
				break;
			case 4:
				sum = t.week;
				while (sum >= 48)
				{
					t.year++;
					sum -= 48;
				}
				if (sum < 48)
				{
					t.year += (sum / 48);
				}
				sum = t.week;
				while (sum >= 4)
				{
					t.month++;
					sum -= 4;
				}
				if (sum < 4)
				{
					t.month += (sum / 4);
				}
				t.day = t.week * 7;
				res = 1;
				break;
			case 5:
				sum = t.month;
				while (sum >= 12)
				{
					t.year++;
					sum -= 12;
				}
				if (sum < 12)
				{
					t.year += (sum / 12);
				}
				t.week = t.month * 4;
				t.day = t.month * 30;
				res = 1;
				break;
			case 6:
				t.month = t.year * 12;
				t.week = t.year * 48;
				t.day = t.year * 365;
				res = 1;
				break;
			}
		}
	}

	if (res)
	{
		t.hour = t.day * 24;
		t.minute = t.hour * 60;
		t.sencond = t.minute * 60;
	}
	else
	{
		t.sencond = t.minute * 60;
		t.hour = t.minute / 60.0;
		t.day = t.hour / 24.0;
		t.week = t.day / 7.0;
		t.month = t.week / 4.0;
		t.year = t.month / 12.0;
	}
}

//长时间转换成员函数
void Time::Times_Transfrom(Time& t)
{
	Time t1 = t;

	const char* s = t1.times.c_str();
	int i = 0;
	int j = 0; //i字符串起始位置 j中止位置
	while (*s)
	{
		if (*(s++) >= 'a')
		{
			j++;
			switch (*(s - 1))
			{
			case 'y':
				stringstream(t1.times.substr(i, j)) >> t1.year;
				break;
			case 'm':
				stringstream(t1.times.substr(i, j)) >> t1.month;
				break;
			case 'w':
				stringstream(t1.times.substr(i, j)) >> t1.week;
				break;
			case 'd':
				stringstream(t1.times.substr(i, j)) >> t1.day;
				break;
			case 'h':
				stringstream(t1.times.substr(i, j)) >> t1.hour;
				break;
			case 'f':
				stringstream(t1.times.substr(i, j)) >> t1.minute;
				break;
			case 's':
				stringstream(t1.times.substr(i, j)) >> t1.sencond;
				break;
			}
			i = j;
		}
		j++;
	}

	t.day = t1.day;
	t.count[3] = 1;
	if (t1.year)
	{
		t.day += (t1.year * 365);
	}
	if (t1.month)
	{
		t.day += (t1.month * 30);
	}
	if (t1.week)
	{
		t.day += (t1.week * 7);
	}
	if (t1.hour)
	{
		t.day += (t1.hour / 24.0);
	}
	if (t1.minute)
	{
		t.day += (t1.minute / 60.0 / 24.0);
	}
	if (t1.sencond)
	{
		t.day += (t1.sencond / 60.0 / 60.0 / 24.0);
	}

	t.All_Times(t);
	t.Time_Transfrom(t);
}

//times导入函数
void Time::Times_String(Time& t1, Time& t)
{
	double num;
	t.times = '\0';
	if (num = t1.year - (int)t1.year)
	{
		t1.month = num * 12;
	}
	if (num = t1.month - (int)t1.month)
	{
		t1.week = num * 4;
	}
	if (num = t1.week - (int)t1.week)
	{
		t1.day = num * 7;
	}
	if (num = t1.day - (int)t1.day)
	{
		t1.hour = num * 24;
	}
	if (num = t1.hour - (int)t1.hour)
	{
		t1.minute = num * 60;
	}
	if (num = t1.minute - (int)t1.minute)
	{
		t1.sencond = num * 60;
	}

	if (t1.year)
	{
		t.times += to_string((int)t1.year) += "年";
	}
	if (t1.month)
	{
		t.times += to_string((int)t1.month) += "月";
	}
	if (t1.week)
	{
		t.times += to_string((int)t1.week) += "周";
	}
	if (t1.day)
	{
		t.times += to_string((int)t1.day) += "天";
	}
	if (t1.hour)
	{
		t.times += to_string((int)t1.hour) += "小时";
	}
	if (t1.minute)
	{
		t.times += to_string((int)t1.minute) += "分";
	}
	if (t1.sencond)
	{
		t.times += to_string(t1.sencond) += "秒";
	}
}

//时间转换计算器主函数
void Time_Calcu(Time& t)
{
	string input;
	cout << "请输入你要转换的时间 可以带入单位(默认为分钟)" << endl;
	cout << "单位: s:秒 f:分 h:时 d:天 w:周 m:月 y:年" << endl;
	cout << "也可以输入xx年xx月xx周xx天 如:4m3w10d20h" << endl;
	cin >> input;
	t.Classify(input, t);
	cout << t << endl;
}