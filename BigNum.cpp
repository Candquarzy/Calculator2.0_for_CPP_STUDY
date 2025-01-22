#include "class.h"

//��дת������
void BigNum::Transfrom(double count, BigNum& n)
{
	int res;
	string num;

	if (int(count) == count)
	{
		res = 0;
		n.sum = count;
		ostringstream oss;
		oss << fixed << setprecision(0) << n.sum;
		num = oss.str();
	}
	else
	{
		res = 1;
		n.sum = floor(count * 100) / 100;
		ostringstream oss;
		oss << fixed << setprecision(2) << n.sum;
		num = oss.str();
	}

	const char* s = num.c_str();
	const char* ps = s;
	int len = 0;
	int point = 0;

	while (*s != '.' && *s)
	{
		len++;
		s++;
	}

	while (*ps)
	{
		switch (point)
		{
		case 1:
			point++;
			break;
		case 2:
			n.math += "��";
			point++;
			break;
		}

		switch (*(ps++))
		{
		case '1':
			n.math += "Ҽ";
			break;
		case '2':
			n.math += "��";
			break;
		case '3':
			n.math += "��";
			break;
		case '4':
			n.math += "��";
			break;
		case '5':
			n.math += "��";
			break;
		case '6':
			n.math += "½";
			break;
		case '7':
			n.math += "��";
			break;
		case '8':
			n.math += "��";
			break;
		case '9':
			n.math += "��";
			break;
		case '0':
			if (!(*ps == '.' || *ps == NULL))
			{
				n.math += "��";
			}
			break;
		case '.':
			n.math += "Ԫ";
			point++;
			break;
		}

		switch (--len)
		{
		case 0:
			break;
		case 1:
			n.math += "ʰ";
			break;
		case 2:
			n.math += "��";
			break;
		case 3:
			n.math += "Ǫ";
			break;
		case 4:
			n.math += "��";
			break;
		case 5:
			n.math += "ʮ��";
			break;
		case 6:
			n.math += "����";
			break;
		case 7:
			n.math += "ǧ��";
			break;
		case 8:
			n.math += "��";
			break;
		case 9:
			n.math += "ʮ��";
			break;
		case 10:
			n.math += "����";
			break;
		case 11:
			n.math += "ǧ��";
			break;
		case 12:
			n.math += "��";
			break;
		}
	}

	if (point == 3 && num.at(num.size() - 1) != '0')
	{
		n.math += "��";
	}

	if (!res)
	{
		n.math += "Ԫ��";
	}

	cout << n.math << endl;
}

//��дת��������
void BigNum_Trans(BigNum& n)
{
	cout << "������һ������,��֧����λС��,�������ֽ���ȥ" << endl;
	double input;
	cin >> input;
	n.Transfrom(input, n);
}