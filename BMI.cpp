#include "class.h"
#include "BMI.h"

//BMI����¼�뺯��
void BMI::Classify(string str, BMI& b)
{
	const char* s = str.c_str();
	int i = 0;
	int j = 0;
	int count = 4;

	while (count)
	{
		if (*s != ' ' && *s != '\0')
		{
			s++;
			j++;
			continue;
		}

		switch (count--)
		{
		case 4:
			b.name = str.substr(i++, j);
			i = ++j;
			break;
		case 3:
			int age;
			stringstream(str.substr(i++, ++j)) >> age;

			if (age > 120)
			{
				cout << "����ʲô����?" << endl;
				return;
			}
			else if (age <= 120)
			{
				b.age = age;
			}

			i = j;
			break;
		case 2:
		{
			int pos = str.substr(i++, ++j).find('/');

			stringstream(str.substr(--i, j)) >> b.weight;
			if (!(pos == EOF))
			{
				b.weight /= 2;
			}
			i = j;
			break;
		}
		case 1:
			double height;
			stringstream(str.substr(i++, ++j)) >> height;

			if (height > 20)
			{
				b.height = height * 0.01;
			}
			else if (height <= 2.8)
			{
				b.height = height;
			}
			else
			{
				cout << "����ʲô����?��ô��ֵ����" << endl;
				return;
			}

			i = j;
			break;
		}
		s++;
	}
}

//BMI���㺯��
void BMI::Calcu(BMI& b)
{
	b.bmi = b.weight / (b.height * b.height);
	
	if (b.bmi < 18.5)
	{
		b.results = "������Ҫ���������?��Ե�";
	}
	else if (b.bmi >= 18.5 && b.bmi < 24)
	{
		b.results = "��ϲ��,���BMI�ǳ�����";
	}
	else if (b.bmi >= 24 && b.bmi < 28)
	{
		b.results = "Ŷ��,�㳬����,�ٳԵ��";
	}
	else if (b.bmi >= 28)
	{
		b.results = "�����ӹ���������(�Ҳ���������)";
	}

	b.left = 18.5 * (b.height * b.height);
	b.right = 24 * (b.height * b.height);
}

//������ʷ��¼����
vector<BMI> BMI::Return_Vector(BMI& b)
{
	return b.Data;
}

//�洢BMI����
void BMI::Save_history(BMI& b)
{
	b.Data.push_back(b);
}

//��ʾ��ʷ����
void BMI::Display_history(vector<BMI> p)
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

//BMI��������
void BMI_Calcu(BMI& b)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (1)
	{
		cout << "�������������,����,����,��� �м��ÿո����" << endl;
		cout << "������Ϊ��,�������غ�������/2 ����:150/2 ���Զ�����" << endl;
		cout << "��߿���������/����,���Զ�ʶ��" << endl;
		cout << "����s�鿴��ʷ��¼ ����e�������˵�" << endl;
		string input;

		getline(cin, input);
		if (input.length() == 1)
		{
			const char* s = input.c_str();
			switch (*s)
			{
			case 's':
			{
				//�Ǻ���д��
				//if (!b.Return_Vector(b).size())
				//{
				//	cout << "��ʷ��¼Ϊ��" << endl;
				//	continue;
				//}
				// 
				//for (int i = 0; i < b.Return_Vector(b).size(); i++)
				//{
				//	cout << "���:" << i + 1 << endl;
				//	cout << b.Return_Vector(b)[i] << endl;
				//}

				b.Display_history(b.Return_Vector(b));
				break;
			}
			case 'e':
				return;
				break;
			}
		}
		else
		{
			b.Classify(input, b);
			b.Calcu(b);
			cout << b << endl;
			b.Save_history(b);
		}
	}
}