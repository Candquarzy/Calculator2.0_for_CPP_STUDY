#include "class.h"
#include "Temperature.h"

//�û���������Ա����
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
		cout << "�������ʲô����?" << endl;
		cout << "������������в���?����~" << endl;
		cout << endl;
		return 0;
	}

	return 1;
}

//�¶�ת����������Ա����
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

//�洢��ʷ��¼��Ա����
void Temp::Save_history(Temp& t)
{
	t.Data.push_back(t);
}

//������ʷ��¼������Ա����
vector<Temp> Temp::Return_Vector(Temp& t)
{
	return t.Data;
}

//��ʾ��ʷ��¼��Ա����
void Temp::Display_history(vector<Temp> p)
{
	if (!p.size())
	{
		cout << "��ʷ��¼Ϊ��" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << "���:" << i + 1 << endl;
		cout << p[i] << endl;
	}
}

//�¶�ת��������
void Temp_Calcu(Temp& t)
{
	while (1)
	{
		string input;
		cout << "������һ���¶����� ����:28C/28c(��28���϶�)" << endl;
		cout << "֧��C���϶� F���϶� K������ R���϶�" << endl;
		cout << "����s�鿴��ʷ��¼ ����e�������˵�" << endl;
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