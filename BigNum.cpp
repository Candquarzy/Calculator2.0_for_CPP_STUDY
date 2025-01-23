#include "class.h"

//测试用户输入是数是否为整数
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
		n.math += "元整";
		cout << n.math << endl;
		return 1;
	}

}

//整型转换成员函数
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
					str += "零";
					first = 1;
				}
			}
		}
		else
		{
			switch (sum)
			{
			case 1:
				str += "壹";
				break;
			case 2:
				str += "贰";
				break;
			case 3:
				str += "叁";
				break;
			case 4:
				str += "肆";
				break;
			case 5:
				str += "伍";
				break;
			case 6:
				str += "陆";
				break;
			case 7:
				str += "柒";
				break;
			case 8:
				str += "捌";
				break;
			case 9:
				str += "玖";
				break;
			}

			switch (res)
			{
			case 0:
				//str += "元";
				break;
			case 1:
				str += "拾";
				break;
			case 2:
				str += "佰";
				break;
			case 3:
				str += "仟";
				break;
			case 4:
				str += "万";
				break;
			case 5:
				str += "十万";
				break;
			case 6:
				str += "百万";
				break;
			case 7:
				str += "千万";
				break;
			case 8:
				str += "亿";
				break;
			case 9:
				str += "十亿";
				break;
			case 10:
				str += "百亿";
				break;
			case 11:
				str += "千亿";
				break;
			case 12:
				str += "兆";
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

//浮点型转换成员函数
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
			str += "零";
			break;
		case '1':
			str += "壹";
			break;
		case '2':
			str += "贰";
			break;
		case '3':
			str += "叁";
			break;
		case '4':
			str += "肆";
			break;
		case '5':
			str += "伍";
			break;
		case '6':
			str += "陆";
			break;
		case '7':
			str += "柒";
			break;
		case '8':
			str += "捌";
			break;
		case '9':
			str += "玖";
			break;
		}

		switch (res)
		{
		case 0:
			str += "分";
			break;
		case 1:
			str += "角";
			j = 0;
			break;
		}

		res++;
		ss.erase(ss.end() - 1, ss.end());
		n.math.insert(0, str);
		str.clear();
	}
	
	str += "元";
	if (j)
	{
		str += "零";

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
	//		str += "零";
	//		break;
	//	case 1:
	//		str += "壹";
	//		break;
	//	case 2:
	//		str += "贰";
	//		break;
	//	case 3:
	//		str += "叁";
	//		break;
	//	case 4:
	//		str += "肆";
	//		break;
	//	case 5:
	//		str += "伍";
	//		break;
	//	case 6:
	//		str += "陆";
	//		break;
	//	case 7:
	//		str += "柒";
	//		break;
	//	case 8:
	//		str += "捌";
	//		break;
	//	case 9:
	//		str += "玖";
	//		break;
	//	}

	//	switch (res)
	//	{
	//	case 0:
	//		str += "分";
	//		break;
	//	case 1:
	//		str += "角";
	//		break;
	//	}

	//	res++;
	//	num /= 10;
	//	n.math.insert(0, str);
	//	str.clear();
	//}
}

//大写转换函数
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
//			n.math += "角";
//			point++;
//			break;
//		}
//
//		switch (*(ps++))
//		{
//		case '1':
//			n.math += "壹";
//			break;
//		case '2':
//			n.math += "贰";
//			break;
//		case '3':
//			n.math += "叁";
//			break;
//		case '4':
//			n.math += "肆";
//			break;
//		case '5':
//			n.math += "伍";
//			break;
//		case '6':
//			n.math += "陆";
//			break;
//		case '7':
//			n.math += "柒";
//			break;
//		case '8':
//			n.math += "捌";
//			break;
//		case '9':
//			n.math += "玖";
//			break;
//		case '0':
//			if (!(*ps == '.' || *ps == NULL))
//			{
//				n.math += "零";
//			}
//			break;
//		case '.':
//			n.math += "元";
//			point++;
//			break;
//		}
//
//		switch (--len)
//		{
//		case 0:
//			break;
//		case 1:
//			n.math += "拾";
//			break;
//		case 2:
//			n.math += "佰";
//			break;
//		case 3:
//			n.math += "仟";
//			break;
//		case 4:
//			n.math += "万";
//			break;
//		case 5:
//			n.math += "十万";
//			break;
//		case 6:
//			n.math += "百万";
//			break;
//		case 7:
//			n.math += "千万";
//			break;
//		case 8:
//			n.math += "亿";
//			break;
//		case 9:
//			n.math += "十亿";
//			break;
//		case 10:
//			n.math += "百亿";
//			break;
//		case 11:
//			n.math += "千亿";
//			break;
//		case 12:
//			n.math += "兆";
//			break;
//		}
//	}
//
//	if (point == 3 && num.at(num.size() - 1) != '0')
//	{
//		n.math += "分";
//	}
//
//	if (!res)
//	{
//		n.math += "元整";
//	}
//
//	cout << n.math << endl;
//}

//大写转换主函数
void BigNum_Trans(BigNum& n)
{
	cout << "请输入一个数字,仅支持两位小数,超出部分将舍去" << endl;
	double input;
	cin >> input;
	//n.Transfrom(input, n);
	n.Check_Float(input, n);
}