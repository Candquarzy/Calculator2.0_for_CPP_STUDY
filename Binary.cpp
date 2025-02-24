#include "class.h"
#include "Binary.h"

//二进制原码转换为反码成员函数
void Binary::BIN_O_To_F(Binary& b)
{
	b.BIN_F.append("1");
	for (int i = 1; i < b.BIN_O.size(); i++)
	{
		switch (b.BIN_O[i])
		{
		case '.':
			b.BIN_F.append(".");
			break;
		case '0':
			b.BIN_F.append("1");
			break;
		case '1':
			b.BIN_F.append("0");
			break;
		case ' ':
			b.BIN_F.append(" ");
			break;
		}
	}
}

//二进制原码转换为补码快捷方法
void Binary::BIN_O_To_B(Binary& b)
{
	b.BIN_B = b.BIN_O;
	int pos = b.BIN_O.rfind("1") - 1;
	while (pos >= 1)
	{
		switch (b.BIN_O[pos])
		{
		case '.':
			b.BIN_B.replace(pos, 1, ".");
			break;
		case '0':
			b.BIN_B.replace(pos, 1, "1");
			break;
		case '1':
			b.BIN_B.replace(pos, 1, "0");
			break;
		}
		pos--;
	}
}

//二进制补码转换为移码
void Binary::BIN_B_To_Y(Binary& b)
{
	b.BIN_Y = b.BIN_B;
	switch (b.BIN_Y[0])
	{
	case '0':
		b.BIN_Y.replace(0, 1, "1");
		break;
	case '1':
		b.BIN_Y.replace(0, 1, "0");
		break;
	}
}

//十进制转换二进制原码成员函数
void Binary::DEC_To_BIN_O(Binary& b)
{
	//处理整数部分
	int DEC = b.DEC >= 0 ? b.DEC : -b.DEC;
	int sum = 1;
	while ((DEC - sum) >= sum)
	{
		sum *= 2;
	}

	if (DEC - sum > 0)
	{
		DEC -= sum;
		b.BIN_O.append("1");
	}

	while (sum > 1)
	{
		sum /= 2;
		if (DEC < sum)
		{
			b.BIN_O.append("0");
		}
		else
		{
			b.BIN_O.append("1");
			DEC -= sum;
		}
	}

	//最前面补0/1
	int count = b.BIN_O.length() % 4;
	if (count)
	{
		int pos = 4 - count;
		if (b.DEC < 0)
		{
			b.BIN_O.insert(0, pos, '1');
		}
		else
		{
			b.BIN_O.insert(0, pos, '0');
		}
	}

	//添加空格
	int length = b.BIN_O.length();
	while (length > 4)
	{
		length -= 4;
		b.BIN_O.insert(length, " ");
	}

	//处理小数部分
	if (b.Decimals)
	{
		b.BIN_O.append(".");
		double sum = b.Decimals;
		int count = 5;
		while (count-- && sum)
		{
			sum *= 2;
			if (sum >= 1)
			{
				b.BIN_O.append("1");
				sum -= 1;
			}
			else
			{
				b.BIN_O.append("0");
			}
		}
	}
}

//十进制转二进制成员函数
void Binary::DEC_To_BIN(Binary& b)
{
	int count = 0;
	if (!b.DEC)
	{
		b.BIN_O = '0';
		b.BIN_F = '0';
		b.BIN_B = '0';
		b.BIN_Y = '0';
		return;
	}
	if (b.DEC > 0)
	{
		b.BIN_O.append("0");
	}
	if (b.DEC < 0)
	{
		count = 1;
		b.BIN_O.append("1");
	}
	b.DEC_To_BIN_O(b);

	if (count)
	{
		b.BIN_O_To_F(b);
		b.BIN_O_To_B(b);
	}
	else
	{
		b.BIN_F = b.BIN_O;
		b.BIN_B = b.BIN_O;
	}

	if (!b.Decimals)
	{
		b.BIN_B_To_Y(b);
	}
}

//用户输入十进制存储成员函数
void Binary::Input_DEC(Binary& b, double count)
{
	if (count - (int)count)
	{
		double sum;
		if (count > 0)
		{
			sum = count - (int)count;
		}
		else
		{
			sum = -(count - (int)count);
		}
		b.Decimals = sum;
	}
	else
	{
		b.Decimals = 0;
	}
	b.DEC = count;
}

//重置成员变量成员函数
void Binary::Reset_Class(Binary& b)
{
	b.BIN_O = "";
	b.BIN_F = "";
	b.BIN_B = "";
	b.BIN_Y = "";
}

//二进制转换器
void Binary_Trans(Binary& b)
{
	while (1)
	{
		double count;
		cout << "请输入一个数,如果是负数请带上'-'号 输入0返回主菜单" << endl;
		cin >> count;
		if (!count)
		{
			return;
		}
		b.Reset_Class(b);
		b.Input_DEC(b, count);
		b.DEC_To_BIN(b);

		cout << b << endl;
	}
}