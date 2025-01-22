#include "class.h"

//�û���������Ա����
double Weight::Classify(string str, Weight& w)
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

	string str_arr[9] = { "ug","mg","g","kg","t","lb","oz","jn","la" };
	string Old = str.substr(distance(str.begin(), letter), distance(letter, symbols));
	string New = str.substr(distance(str.begin(), symbols) + 1, distance(symbols, str.end()));
	for (int i = 0; i < sizeof(str_arr) / sizeof(str_arr[0]); i++)
	{
		if (!Old.compare(str_arr[i]))
		{
			w.old_count[i] = 1;
		}
		if (!New.compare(str_arr[i]))
		{
			w.new_count[i] = 1;
		}
	}

	double sum;
	stringstream(str) >> sum;
	return sum;
}

//����ת����������Ա����
void Weight::Calcu(double sum, Weight& w)
{
	string str_arr[9] = { "ug","mg","g","kg","t","��","��˾","��","��" };

	stringstream ss;
	ss << fixed << setprecision(3) << sum;
	for (int i = 0; i < sizeof(w.old_count) / sizeof(w.old_count[0]); i++)
	{
		if (w.old_count[i])
		{
			cout << sum << str_arr[i] << " = ";
			w.Data.push_back(ss.str());
			w.Data.back() += str_arr[i];
			w.Data.back() += " = ";
			switch (i)
			{
			case 0: //΢��
				w.ug = sum;
				w.mg = w.ug / 1000;
				w.g = w.mg / 1000.0;
				w.kg = w.g / 1000;
				break;
			case 1: //����
				w.mg = sum;
				w.g = w.mg / 1000.0;
				w.kg = w.g / 1000;
				break;
			case 2: //��
				w.g = sum;
				w.kg = w.g / 1000;
				break;
			case 3: //ǧ��
				w.kg = sum;
				break;
			case 4: //��
				w.t = sum;
				w.kg = w.t * 1000;
				break;
			case 5: //��
				w.lb = sum;
				w.kg = w.lb * 0.453592;
				break;
			case 6: //��˾
				w.oz = sum;
				w.lb = w.oz / 16;
				w.kg = w.lb * 0.453592;
				break;
			case 7: //��
				w.jin = sum;
				w.kg = w.jin / 2;
				break;
			case 8: //��
				w.liang = sum;
				w.kg = w.liang / 20;
				break;
			}
			w.old_count[i] = 0;
			break;
		}
	}

	ss.str("");
	ss.clear();
	for (int i = 0; i < sizeof(w.new_count) / sizeof(w.new_count[0]); i++)
	{
		if (w.new_count[i])
		{
			switch (i)
			{
			case 0:
				w.g = w.kg * 1000;
				w.mg = w.g * 1000;
				w.ug = w.mg * 1000;
				cout << w.ug;
				ss << fixed << setprecision(3) << w.ug;
				w.Data.back() += ss.str();
				break;
			case 1:
				w.g = w.kg * 1000;
				w.mg = w.g * 1000;
				cout << w.mg;
				ss << fixed << setprecision(3) << w.mg;
				w.Data.back() += ss.str();
				break;
			case 2:
				w.g = w.kg * 1000;
				cout << w.g;
				ss << fixed << setprecision(3) << w.g;
				w.Data.back() += ss.str();
				break;
			case 3:
				cout << w.kg;
				ss << fixed << setprecision(3) << w.kg;
				w.Data.back() += ss.str();
				break;
			case 4:
				w.t = w.kg / 1000;
				cout << w.t;
				ss << fixed << setprecision(3) << w.t;
				w.Data.back() += ss.str();
				break;
			case 5:
				w.lb = w.kg / 0.453592;
				cout << w.lb;
				ss << fixed << setprecision(3) << w.lb;
				w.Data.back() += ss.str();
				break;
			case 6:
				w.lb = w.kg / 0.453592;
				w.oz = w.lb * 16;
				cout << w.oz;
				ss << fixed << setprecision(3) << w.oz;
				w.Data.back() += ss.str();
				break;
			case 7:
				w.jin = w.kg * 2;
				cout << w.jin;
				ss << fixed << setprecision(3) << w.jin;
				w.Data.back() += ss.str();
				break;
			case 8:
				w.g = w.kg * 1000;
				w.liang = w.g / 50;
				cout << w.liang;
				ss << fixed << setprecision(3) << w.liang;
				w.Data.back() += ss.str();
				break;
			}
			cout << str_arr[i] << endl;
			w.Data.back() += str_arr[i];
			w.new_count[i] = 0;
			break;
		}
	}
	cout << endl;
}

//����������Ա����
vector<string> Weight::Return_Vector(Weight& w)
{
	return w.Data;
}

//��ʾ��ʷ��¼��Ա����
void Weight::Display_history(vector<string> p)
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

//����ת��������������
void Weight_Calcu(Weight& w)
{
	while (1)
	{
		string input;
		cout << "��������Ҫת��������,��������λ��ʹ��-������Ҫת����ĵ�λ" << endl;
		cout << "��:1024kg-t ����1024kgΪ��Ҫת��������,tΪ��Ҫת����ĵ�λ" << endl;
		cout << "֧��ug΢�� mg���� g�� kgǧ�� t�� lb�� oz��˾ jn�� la��" << endl;
		cout << "(*������Ͱ�˾���ܻᶪʧת������) 	����s�鿴��ʷ��¼ ����e�������˵�" << endl;
		cin >> input;
		cout << endl;

		if (input.length() == 1)
		{
			const char* s = input.c_str();
			switch (*s)
			{
			case 's':
				w.Display_history(w.Return_Vector(w));
				break;
			case 'e':
				return;
				break;
			}
		}
		else
		{
			double sum = w.Classify(input, w);
			if (sum)
			{
				w.Calcu(sum, w);
			}
		}
	}
}