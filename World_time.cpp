#define _CRT_SECURE_NO_WARNINGS

#include "class.h"

//ʵ����time����
void World::Time_Struct_New(World& w)
{
	time_t now = time(0);
	w.t = gmtime(&now);
}

//ʱ��ת������
void World::Time_Trans(World& w)
{
	for (int i = 0; i <= sizeof(w.time_count) / sizeof(w.time_count[0]); i++)
	{
		if (!i)
		{
			w.Time_Struct_New(w);
			if (w.time_count[i] > 0)
			{
				w.t->tm_hour += w.time_count[i];
				w.t->tm_hour >= 24 ? w.t->tm_mday++, w.t->tm_hour -= 24 : w.t->tm_hour += 0;
			}
			else
			{
				w.t->tm_hour += w.time_count[i];
				w.t->tm_hour < 0 ? w.t->tm_mday--, w.t->tm_hour += 24 : w.t->tm_hour += 0;
			}
		}
		mktime(w.t);
		char str[80];
		strftime(str, sizeof(str), "%Y-%m-%d %H:%M:%S", w.t);
		w.times.push_back(str);
	}
}

//��ʾ���������ݺ���
void World::Display_Data(World& w)
{
	//cout << "UTC+0 ��׼ʱ��Ϊ" << " " << w.t << endl;
	for (int i = 0; i < w.times.size(); i++)
	{
		cout << w.country[i] << " " << w.times[i] << endl;
	}
}

//����ʱ��ת��������
void World_Time_Calcu(World& w)
{
	w.Time_Struct_New(w);
	w.Time_Trans(w);
	w.Display_Data(w);
}