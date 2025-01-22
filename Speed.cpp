#include "class.h"
#include "speed.h"

//�û���������Ա����
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
		cout << "�������ʲô����?" << endl;
		cout << "������������в���?����~" << endl;
		cout << endl;
		return 0;
	}
	return 1;
}

//�ٶ�ת�������Ա����
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

//�洢��ʷ��¼��Ա����
void Speed::Save_history(Speed& s)
{
	s.Data.push_back(s);
}

//����������Ա����
vector<Speed> Speed::Return_Vector(Speed& s)
{
	return s.Data;
}

//��ʾ��ʷ��¼��Ա����
void Speed::Display_history(vector<Speed> p)
{
	if (!p.size())
	{
		cout << "��ʷ��¼Ϊ��" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << i + 1 << endl;
		cout << p[i] << endl;
	}
}

//�ٶ�ת��������������
void Speed_Calcu(Speed& s)
{
	while (1)
	{
		string input;
		cout << "������һ���ٶ����� (����Ӣ����������������ת�����Ӣ����ֵ���ܴ��ھ�������)" << endl;
		cout << "֧��ms��/�� kmhǧ��/Сʱ mphӢ��/Сʱ" << endl;
		cout << "����s�鿴��ʷ��¼ ����e�������˵�" << endl;
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