#include "class.h"

//�û���������Ա����
double Volume::Classify(string str, Volume& v)
{
	string::iterator letter = find_if(str.begin(), str.end(), [](char ch)
		{
			return ch >= 'A';
		});
	string::iterator symbols = find(str.begin(), str.end(), '-');

	if (letter == str.end() || symbols == str.end())
	{
		cout << "�������붼�䲻����?" << endl;
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

//�����������Ա����
void Volume::Calcu(double sum, Volume& v)
{
	string str_arr[6] = { "��������","��������","��������","������","��","����" };

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
			case 0: //����
				v.mm = sum;
				v.cm = v.mm / 1000;
				break;
			case 1: //����
				v.cm = sum;
				break;
			case 2: //����
				v.dm = sum;
				v.cm = v.dm * 1000;
				break;
			case 3: //��
				v.m = sum;
				v.dm = v.m * 1000;
				v.cm = v.dm * 1000;
				break;
			case 4: //��
				v.L = sum;
				v.cm = v.L * 1000;
				break;
			case 5: //����
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

//����������Ա����
vector<string> Volume::Return_Vector(Volume& v)
{
	return v.Data;
}

//��ʾ��ʷ��¼��Ա����
void Volume::Display_history(vector<string> p)
{
	if (!p.size())
	{
		cout << "��ʷ��¼Ϊ��" << endl;
		cout << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << i + 1 << ". " << p[i] << endl;
	}
	cout << endl;
}

//���ת��������������
void Volume_Calcu(Volume& v)
{
	while (1)
	{
		string input;
		cout << "��������Ҫת��������,��������λ��ʹ��-������Ҫת����ĵ�λ" << endl;
		cout << "��:10L-ml ����100cmΪ��Ҫת��������,mmΪ��Ҫת����ĵ�λ" << endl;
		cout << "֧��mm�������� cm�������� dm�������� m������ L�� ml����" << endl;
		cout << "(*����?????���ܶ�ʧת������)	����s�鿴��ʷ��¼ ����e�������˵�" << endl;
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