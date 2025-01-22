#include "class.h"
//#include "Length.h"

//�û����������㺯��
double Length::Classify(string str, Length& l)
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

	string str_arr[11] = { "um","mm","cm","fm","m","chi","cun","km","in","ft","mi" };
	string Old = str.substr(distance(str.begin(), letter), distance(letter, symbols));
	string New = str.substr(distance(str.begin(), symbols) + 1, distance(symbols, str.end()));
	for (int i = 0; i < sizeof(str_arr) / sizeof(str_arr[0]); i++)
	{
		if (!Old.compare(str_arr[i]))
		{
			l.old_count[i] = 1;
		}
		if (!New.compare(str_arr[i]))
		{
			l.new_count[i] = 1;
		}
	}

	double sum;
	stringstream(str) >> sum;
	return sum;
}

//���ȼ����Ա����
void Length::Calcu(double sum, Length& l)
{
	string str_arr[11] = { "um","mm","cm","fm","m","chi","cun","km","in","ft","mi" };

	stringstream ss;
	ss << fixed << setprecision(3) << sum;
	for (int i = 0; i < sizeof(l.old_count) / sizeof(l.old_count[0]); i++)
	{
		if (l.old_count[i])
		{
			cout << sum << str_arr[i] << " = ";
			l.Data.push_back(ss.str());
			l.Data.back() += str_arr[i];
			l.Data.back() += " = ";
			switch (i)
			{
			case 0: //΢��
				l.um = sum;
				l.mm = l.um / 1000.0;
				l.cm = l.mm / 10;
				l.fm = l.cm / 10;
				l.m = l.fm / 10;
				break;
			case 1: //����
				l.mm = sum;
				l.cm = l.mm / 10;
				l.fm = l.cm / 10;
				l.m = l.fm / 10;
				break;
			case 2: //����
				l.cm = sum;
				l.fm = l.cm / 10;
				l.m = l.fm / 10;
				break;
			case 3: //����
				l.fm = sum;
				l.m = l.fm / 10;
				break;
			case 4: //��
				l.m = sum;
				break; 
			case 5: //��
				l.chi = sum;
				l.m = l.chi / 3;
				break;
			case 6: //��
				l.cun = sum;
				l.chi = l.cun * 10;
				l.m = l.chi / 3;
				break;
			case 7: //ǧ��
				l.km = sum;
				l.m = l.km * 1000;
				break;
			case 8: //Ӣ��
				l.in = sum;
				l.cm = l.in * 2.54;
				l.fm = l.cm / 10;
				l.m = l.fm / 10;
				break;
			case 9: //Ӣ��
				l.ft = sum;
				l.in = l.ft * 12;
				l.cm = l.in * 2.54;
				l.fm = l.cm / 10;
				l.m = l.fm / 10;
				break;
			case 10: //Ӣ��
				l.mi = sum;
				l.ft = l.mi * 5280;
				l.in = l.ft * 12;
				l.cm = l.in * 2.54;
				l.fm = l.cm / 10;
				l.m = l.fm / 10;
				break;
			}
			l.old_count[i] = 0;
			break;
		}
	}

	ss.str("");
	ss.clear();
	for (int i = 0; i < sizeof(l.new_count) / sizeof(l.new_count[0]); i++)
	{
		if (l.new_count[i])
		{
			switch (i)
			{
			case 0:
				l.fm = l.m * 10;
				l.cm = l.fm * 10;
				l.mm = l.cm * 10;
				l.um = l.mm * 1000;
				cout << l.um;
				ss << fixed << setprecision(3) << l.um;
				l.Data.back() += ss.str();
				break;
			case 1:
				l.fm = l.m * 10;
				l.cm = l.fm * 10;
				l.mm = l.cm * 10;
				cout << l.mm;
				ss << fixed << setprecision(3) << l.mm;
				l.Data.back() += ss.str();
				break;
			case 2:
				l.fm = l.m * 10;
				l.cm = l.fm * 10;
				cout << l.cm;
				ss << fixed << setprecision(3) << l.cm;
				l.Data.back() += ss.str();
				break;
			case 3:				
				l.fm = l.m * 10;
				cout << l.fm;
				ss << fixed << setprecision(3) << l.fm;
				l.Data.back() += ss.str();
				break;
			case 4:
				cout << l.m;
				ss << fixed << setprecision(3) << l.m;
				l.Data.back() += ss.str();
				break;
			case 5: //?
				l.chi = l.m * 3;
				cout << l.chi;
				ss << fixed << setprecision(3) << l.chi;
				l.Data.back() += ss.str();
				break;
			case 6: //?
				l.chi = l.m * 3;
				l.cun = l.chi * 10;
				cout << l.cun;
				ss << fixed << setprecision(3) << l.cun;
				l.Data.back() += ss.str();
				break;
			case 7:
				l.km = l.m / 1000;
				cout << l.km;
				ss << fixed << setprecision(3) << l.km;
				l.Data.back() += ss.str();
				break;
			case 8: 
				l.cm = l.m * 100;
				l.in = l.cm / 2.54;
				cout << l.in;
				ss << fixed << setprecision(3) << l.in;
				l.Data.back() += ss.str();
				break;
			case 9: 
				l.cm = l.m * 100;
				l.in = l.cm / 2.54;
				l.ft = l.in / 12;
				cout << l.ft;
				ss << fixed << setprecision(3) << l.ft;
				l.Data.back() += ss.str();
				break;
			case 10: 
				l.cm = l.m * 100;
				l.in = l.cm / 2.54;
				l.ft = l.in / 12;
				l.mi = l.ft / 5280;
				cout << l.mi;
				ss << fixed << setprecision(3) << l.mi;
				l.Data.back() += ss.str();
				break;
			}
			cout << str_arr[i] << endl;
			l.Data.back() += str_arr[i];
			l.new_count[i] = 0;
			break;
		}
	}
	cout << endl;
}

//����������Ա����
vector<string> Length::Return_Vector(Length& l)
{
	return l.Data;
}

//��ʾ��ʷ��¼��Ա����
void Length::Display_history(vector<string> p)
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

//���ȼ�����������
void Length_Calcu(Length& l)
{
	while (1)
	{
		string input;
		cout << "��������Ҫת��������,��������λ��ʹ��-������Ҫת����ĵ�λ" << endl;
		cout << "��:100cm-mm ����100cmΪ��Ҫת��������,mmΪ��Ҫת����ĵ�λ" << endl;
		cout << "֧��um΢�� mm���� cm���� fm���� m�� chi�� cun�� kmǧ�� inӢ�� ftӢ�� miӢ��" << endl;
		cout << "(*����ߺʹ���ܶ�ʧת������)	����s�鿴��ʷ��¼ ����e�������˵�" << endl;
		cin >> input;
		cout << endl;

		if (input.length() == 1)
		{
			const char* s = input.c_str();
			switch (*s)
			{
			case 's':
				l.Display_history(l.Return_Vector(l));
				break;
			case 'e':
				return;
				break;
			}
		}
		else
		{
			double sum = l.Classify(input, l);
			if (sum)
			{
				l.Calcu(sum, l);
			}
		}
	}
}