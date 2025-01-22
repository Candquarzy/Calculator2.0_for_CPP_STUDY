#include "class.h"
#include "Storage.h"

//�ַ��������Ա����
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
		cout << "�������ʲô����?" << endl;
		cout << "������������в���?����~" << endl;
		cout << endl;
		return 0;
	}
	return 1;
}

//����ת����Ա����
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

//�洢��ʷ��¼��Ա����
void Storage::Save_history(Storage& s)
{
	s.Data.push_back(s);
}

//����������Ա����
vector<Storage> Storage::Return_Vector(Storage& s)
{
	return s.Data;
}

//��ʾ��ʷ��¼��Ա����
void Storage::Display_history(vector<Storage> p)
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

//���������ת��������
void Storage_Calcu(Storage& s)
{
	while (1)
	{
		string input;
		cout << "������һ����������ݴ�С" << endl;
		cout << "���֧�ֵ�EB,����:1TB/1Tb/1T(δʵ��)/1t(δʵ��)" << endl;
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