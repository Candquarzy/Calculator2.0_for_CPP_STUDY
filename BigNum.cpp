#include "class.h"

//大写转换函数
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
			n.math += "角";
			point++;
			break;
		}

		switch (*(ps++))
		{
		case '1':
			n.math += "壹";
			break;
		case '2':
			n.math += "贰";
			break;
		case '3':
			n.math += "叁";
			break;
		case '4':
			n.math += "肆";
			break;
		case '5':
			n.math += "伍";
			break;
		case '6':
			n.math += "陆";
			break;
		case '7':
			n.math += "柒";
			break;
		case '8':
			n.math += "捌";
			break;
		case '9':
			n.math += "玖";
			break;
		case '0':
			if (!(*ps == '.' || *ps == NULL))
			{
				n.math += "零";
			}
			break;
		case '.':
			n.math += "元";
			point++;
			break;
		}

		switch (--len)
		{
		case 0:
			break;
		case 1:
			n.math += "拾";
			break;
		case 2:
			n.math += "佰";
			break;
		case 3:
			n.math += "仟";
			break;
		case 4:
			n.math += "万";
			break;
		case 5:
			n.math += "十万";
			break;
		case 6:
			n.math += "百万";
			break;
		case 7:
			n.math += "千万";
			break;
		case 8:
			n.math += "亿";
			break;
		case 9:
			n.math += "十亿";
			break;
		case 10:
			n.math += "百亿";
			break;
		case 11:
			n.math += "千亿";
			break;
		case 12:
			n.math += "兆";
			break;
		}
	}

	if (point == 3 && num.at(num.size() - 1) != '0')
	{
		n.math += "分";
	}

	if (!res)
	{
		n.math += "元整";
	}

	cout << n.math << endl;
}

//大写转换主函数
void BigNum_Trans(BigNum& n)
{
	cout << "请输入一个数字,仅支持两位小数,超出部分将舍去" << endl;
	double input;
	cin >> input;
	n.Transfrom(input, n);
}