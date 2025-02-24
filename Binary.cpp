#include "class.h"
#include "Binary.h"

//������ԭ��ת��Ϊ�����Ա����
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

//������ԭ��ת��Ϊ�����ݷ���
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

//�����Ʋ���ת��Ϊ����
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

//ʮ����ת��������ԭ���Ա����
void Binary::DEC_To_BIN_O(Binary& b)
{
	//������������
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

	//��ǰ�油0/1
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

	//��ӿո�
	int length = b.BIN_O.length();
	while (length > 4)
	{
		length -= 4;
		b.BIN_O.insert(length, " ");
	}

	//����С������
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

//ʮ����ת�����Ƴ�Ա����
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

//�û�����ʮ���ƴ洢��Ա����
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

//���ó�Ա������Ա����
void Binary::Reset_Class(Binary& b)
{
	b.BIN_O = "";
	b.BIN_F = "";
	b.BIN_B = "";
	b.BIN_Y = "";
}

//������ת����
void Binary_Trans(Binary& b)
{
	while (1)
	{
		double count;
		cout << "������һ����,����Ǹ��������'-'�� ����0�������˵�" << endl;
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