#include "class.h"

//�����û����������Ƿ�Ϊ����
int BigNum::Check_Float(double count, BigNum& n) 
{
	if (count - (int)count != 0) 
	{
		n.sum = ((int)(count * 100)) / 100.0;
		cout << "sum: " << n.sum << endl;
		n.Float_Transfrom(n.sum, n);
		n.Int_Transfrom((int)n.sum, n);
		cout << n.math << endl;

		return 0;
	}
	else
	{
		n.count = (int)count;
		n.Int_Transfrom(n.count, n);
		n.math += "Ԫ��";
		cout << n.math << endl;
		return 1;
	}

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
				//str += "Ԫ";
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
	//else
	//{
	//	num += 1;
	//}
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
	//count -= (int)count;
	//int num = count * 100;
	//int res = 0;
	//int sum;
	//if (!(num % 10))
	//{
	//	num /= 10;
	//	res++;
	//}
	//else
	//{
	//	num += 1;
	//}
	//
	//string str;

	//while (num)
	//{
	//	sum = num % 10;
	//	switch (sum)
	//	{
	//	case 0:
	//		str += "��";
	//		break;
	//	case 1:
	//		str += "Ҽ";
	//		break;
	//	case 2:
	//		str += "��";
	//		break;
	//	case 3:
	//		str += "��";
	//		break;
	//	case 4:
	//		str += "��";
	//		break;
	//	case 5:
	//		str += "��";
	//		break;
	//	case 6:
	//		str += "½";
	//		break;
	//	case 7:
	//		str += "��";
	//		break;
	//	case 8:
	//		str += "��";
	//		break;
	//	case 9:
	//		str += "��";
	//		break;
	//	}

	//	switch (res)
	//	{
	//	case 0:
	//		str += "��";
	//		break;
	//	case 1:
	//		str += "��";
	//		break;
	//	}

	//	res++;
	//	num /= 10;
	//	n.math.insert(0, str);
	//	str.clear();
	//}
}

//��дת������
//void BigNum::Transfrom(double count, BigNum& n)
//{
//	int res;
//	string num;
//
//	if (int(count) == count)
//	{
//		res = 0;
//		n.sum = count;
//		ostringstream oss;
//		oss << fixed << setprecision(0) << n.sum;
//		num = oss.str();
//	}
//	else
//	{
//		res = 1;
//		n.sum = floor(count * 100) / 100;
//		ostringstream oss;
//		oss << fixed << setprecision(2) << n.sum;
//		num = oss.str();
//	}
//
//	const char* s = num.c_str();
//	const char* ps = s;
//	int len = 0;
//	int point = 0;
//
//	while (*s != '.' && *s)
//	{
//		len++;
//		s++;
//	}
//
//	while (*ps)
//	{
//		switch (point)
//		{
//		case 1:
//			point++;
//			break;
//		case 2:
//			n.math += "��";
//			point++;
//			break;
//		}
//
//		switch (*(ps++))
//		{
//		case '1':
//			n.math += "Ҽ";
//			break;
//		case '2':
//			n.math += "��";
//			break;
//		case '3':
//			n.math += "��";
//			break;
//		case '4':
//			n.math += "��";
//			break;
//		case '5':
//			n.math += "��";
//			break;
//		case '6':
//			n.math += "½";
//			break;
//		case '7':
//			n.math += "��";
//			break;
//		case '8':
//			n.math += "��";
//			break;
//		case '9':
//			n.math += "��";
//			break;
//		case '0':
//			if (!(*ps == '.' || *ps == NULL))
//			{
//				n.math += "��";
//			}
//			break;
//		case '.':
//			n.math += "Ԫ";
//			point++;
//			break;
//		}
//
//		switch (--len)
//		{
//		case 0:
//			break;
//		case 1:
//			n.math += "ʰ";
//			break;
//		case 2:
//			n.math += "��";
//			break;
//		case 3:
//			n.math += "Ǫ";
//			break;
//		case 4:
//			n.math += "��";
//			break;
//		case 5:
//			n.math += "ʮ��";
//			break;
//		case 6:
//			n.math += "����";
//			break;
//		case 7:
//			n.math += "ǧ��";
//			break;
//		case 8:
//			n.math += "��";
//			break;
//		case 9:
//			n.math += "ʮ��";
//			break;
//		case 10:
//			n.math += "����";
//			break;
//		case 11:
//			n.math += "ǧ��";
//			break;
//		case 12:
//			n.math += "��";
//			break;
//		}
//	}
//
//	if (point == 3 && num.at(num.size() - 1) != '0')
//	{
//		n.math += "��";
//	}
//
//	if (!res)
//	{
//		n.math += "Ԫ��";
//	}
//
//	cout << n.math << endl;
//}

//��дת��������
void BigNum_Trans(BigNum& n)
{
	cout << "������һ������,��֧����λС��,�������ֽ���ȥ" << endl;
	double input;
	cin >> input;
	//n.Transfrom(input, n);
	n.Check_Float(input, n);
}