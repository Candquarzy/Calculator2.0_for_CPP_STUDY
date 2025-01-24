#include "class.h"
#include "BigNum.h"

//�����û����������Ƿ�Ϊ����
void BigNum::Check_Float(double count, BigNum& n) 
{
	if (n.math.size())
	{
		n.math = " ";
	}

	if (count - (int)count != 0) 
	{
		n.sum = ((int)(count * 100)) / 100.0;
		n.Float_Transfrom(n.sum, n);
		n.Int_Transfrom((int)n.sum, n);
	}
	else
	{
		n.count = (int)count;
		n.Int_Transfrom(n.count, n);
		n.math += "Ԫ��";
	}

	n.Save_history(n);
	n.sum = 0;
	n.count = 0;
}

//����ת����Ա����
void BigNum::Int_Transfrom(int count, BigNum& n)
{
	int res = 0;
	int first = 0;
	int zero = 0;
	int sum;
	string str;

	if (!(count % 10))
	{
		zero = 1;
	}

	while (count)
	{
		sum = count % 10;
		if (sum == 0)
		{
			if (!zero)
			{
				if (!first)
				{
					str += "��";
					first = 1;
				}
			}
		}
		else
		{
			switch (sum)
			{
			case 1:
				str += "Ҽ";
				break;
			case 2:
				str += "��";
				break;
			case 3:
				str += "��";
				break;
			case 4:
				str += "��";
				break;
			case 5:
				str += "��";
				break;
			case 6:
				str += "½";
				break;
			case 7:
				str += "��";
				break;
			case 8:
				str += "��";
				break;
			case 9:
				str += "��";
				break;
			}

			switch (res)
			{
			case 0:
				break;
			case 1:
				str += "ʰ";
				break;
			case 2:
				str += "��";
				break;
			case 3:
				str += "Ǫ";
				break;
			case 4:
				str += "��";
				break;
			case 5:
				str += "ʮ��";
				break;
			case 6:
				str += "����";
				break;
			case 7:
				str += "ǧ��";
				break;
			case 8:
				str += "��";
				break;
			case 9:
				str += "ʮ��";
				break;
			case 10:
				str += "����";
				break;
			case 11:
				str += "ǧ��";
				break;
			case 12:
				str += "��";
				break;
			}
			first = 0;
			zero = 0;
		}
		res++;
		count /= 10;
		n.math.insert(0,str);
		str.clear();
	}
	cout << n.math << endl;
}

//������ת����Ա����
void BigNum::Float_Transfrom(double count, BigNum& n)
{
	count -= (int)count;
	int num = count * 100;
	if ((int)(count * 1000) % 10)
	{
		num++;
	}
	int res = 0;
	int sum;
	int j = 1;
	if (!(num % 10))
	{
		num /= 10;
		res++;
	}
	string ss = to_string(num);
	string str;

	while (ss.size())
	{
		char s = ss.back();
		switch (s)
		{
		case '0':
			str += "��";
			break;
		case '1':
			str += "Ҽ";
			break;
		case '2':
			str += "��";
			break;
		case '3':
			str += "��";
			break;
		case '4':
			str += "��";
			break;
		case '5':
			str += "��";
			break;
		case '6':
			str += "½";
			break;
		case '7':
			str += "��";
			break;
		case '8':
			str += "��";
			break;
		case '9':
			str += "��";
			break;
		}

		switch (res)
		{
		case 0:
			str += "��";
			break;
		case 1:
			str += "��";
			j = 0;
			break;
		}

		res++;
		ss.erase(ss.end() - 1, ss.end());
		n.math.insert(0, str);
		str.clear();
	}
	
	str += "Ԫ";
	if (j)
	{
		str += "��";

	}
	n.math.insert(0, str);
	str.clear();
}

//������ʷ��¼��Ա����
void BigNum::Save_history(BigNum& n)
{
	n.Data.push_back(n);
}

//���ش洢������Ա����
vector<BigNum> BigNum::Return_Vector(BigNum& n)
{
	return n.Data;
}

//��ʾ��ʷ��¼��Ա����
void BigNum::Display_history(vector<BigNum> p)
{
	if (!p.size())
	{
		cout << "��ʷ��¼Ϊ��" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << "���" << i + 1 << endl;
		cout << p[i] << endl;
	}
	cout << "\n";
}

//��дת��������
void BigNum_Trans(BigNum& n)
{
	while (1)
	{
		cout << "������һ������,��֧����λС��,�������ֽ���ȥ" << endl;
		cout << "����-1�鿴��ʷ��¼ ����0�������˵�" << endl;
		double input;
		cin >> input;

		if (input < 0 && input != -1)
		{
			cout << "��֧�ָ���,����������" << endl;
			continue;
		}

		if (input == -1)
		{
			n.Display_history(n.Return_Vector(n));
		}
		else if (!input)
		{
			return;
			break;
		}
		else
		{
			n.Check_Float(input, n);
		}
	}
}