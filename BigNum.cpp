#include "class.h"
#include "BigNum.h"

//测试用户输入是数是否为整数
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
		n.math += "元整";
	}

	n.Save_history(n);
	n.sum = 0;
	n.count = 0;
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
	cout << n.math << endl;
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
}

//保存历史记录成员函数
void BigNum::Save_history(BigNum& n)
{
	n.Data.push_back(n);
}

//返回存储容器成员函数
vector<BigNum> BigNum::Return_Vector(BigNum& n)
{
	return n.Data;
}

//显示历史记录成员函数
void BigNum::Display_history(vector<BigNum> p)
{
	if (!p.size())
	{
		cout << "历史记录为空" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << "编号" << i + 1 << endl;
		cout << p[i] << endl;
	}
	cout << "\n";
}

//大写转换主函数
void BigNum_Trans(BigNum& n)
{
	while (1)
	{
		cout << "请输入一个数字,仅支持两位小数,超出部分将舍去" << endl;
		cout << "输入-1查看历史记录 输入0返回主菜单" << endl;
		double input;
		cin >> input;

		if (input < 0 && input != -1)
		{
			cout << "不支持负数,请重新输入" << endl;
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