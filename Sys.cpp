#include "class.h"
#include "Sys.h"

//���ݹ����Ա����
int Sys_Carry::Classify(string str, Sys_Carry& s)
{
	//�ж��ַ������Ƿ�����ĸ,�����,�Ǿ���ʮ������
	const char* c = str.c_str();
	while (*c)
	{
		if (isalpha(*(c++)))
		{
			s.HEX = str;
			s.count[3] = 1;
			return 1;
		}
	}

	//string::iterator it = find_if(str.begin(), str.end(), [](char c)
	//	{
	//		return isalpha(static_cast<unsigned char>(c));
	//	});

	//�ж��Ƿ��д���8���ַ�,�����,�Ǿ���ʮ���ƻ�ʮ������
	string::iterator oct = find_if(str.begin(), str.end(), [](char c)
		{
			return c >= '8';
		});
	if (oct != str.end())
	{
		cout << "�Զ��ֱ����ʶ�����, �������������ʮ���ƻ���ʮ������?" << endl;
		cout << "ʮ����������0,ʮ������������1" << endl;
		int sum;
		cin >> sum;

		if (sum == 1)
		{
			s.HEX = str;
			s.count[3] = 1;
		}
		else if (!sum)
		{
			stringstream(str) >> s.DEC;
			s.count[2] = 1;
		}
		else
		{
			cout << "�������ʲô����?����������1��0���������ʲô" << endl;
			return 0;
		}
		return 1;
	}
	//�ж��Ƿ��д���2���ַ�,�����,�Ǿ��ǰ˽��ƻ���ʮ���ƻ���ʮ������
	string::iterator bin = find_if(str.begin(), str.end(), [](char c)
		{
			return c >= '2';
		});
	//����ҵ�����2���ַ�,����û���ҵ�����8���ַ�,�Ǿ��ǰ˽��ƻ���ʮ���ƻ���ʮ������
	if (bin != str.end() && oct == str.end())
	{
		int sum;
		cout << "�Զ��ֱ����ʶ�����,������������ǰ˽���,ʮ���ƻ���ʮ������?" << endl;
		cout << "�˽���������0,ʮ����������1,ʮ������������2" << endl;
		cin >> sum;

		switch (sum)
		{
		case 0:
			stringstream(str) >> s.OCT;
			s.count[1] = 1;
			break;
		case 1:
			stringstream(str) >> s.DEC;
			s.count[2] = 1;
			break;
		case 2:
			s.HEX = str;
			s.count[3] = 1;
			break;
		default:
			cout << "�������ʲô����?����������1��0���������ʲô" << endl;
			return 0;
			break;
		}

		//if (sum == 1)
		//{
		//	stringstream(str) >> s.DEC;
		//	s.count[2] = 1;
		//}
		//else if (sum == 2)
		//{
		//	s.HEX = str;
		//	s.count[3] = 1;
		//}
		//else if (!sum)
		//{
		//	stringstream(str) >> s.OCT;
		//	s.count[1] = 1;
		//}
		//else
		//{
		//	cout << "�������ʲô����?����������1��0���������ʲô" << endl;
		//}
		return 1;
	}
	//���û���ҵ�����2���ַ�,��ô�п����Ƕ�����,�п����ǰ˽���,�п�����ʮ����,Ҳ�п�����ʮ������*
	if (bin == str.end())
	{
		int sum;
		cout << "�Զ��ֱ����ʶ�����,������������Ƕ�����,�˽���,ʮ���ƻ���ʮ������?" << endl;
		cout << "������������0,�˽���������1,ʮ����������2,ʮ������������3" << endl;
		cin >> sum;

		switch (sum)
		{
		case 0:
			stringstream(str) >> s.BIN;
			s.count[0] = 1;
			break;
		case 1:
			stringstream(str) >> s.OCT;
			s.count[1] = 1;
			break;
		case 2:
			stringstream(str) >> s.DEC;
			s.count[2] = 1;
			break;
		case 3:
			s.HEX = str;
			s.count[3] = 1;
			break;
		default:
			cout << "�������ʲô����?����������1��0���������ʲô" << endl;
			return 0;
			break;
		}

		//if (sum)
		//{
		//	stringstream(str) >> s.OCT;
		//	s.count[1] = 1;
		//}
		//else if (!sum)
		//{
		//	stringstream(str) >> s.BIN;
		//	s.count[0] = 1;
		//}
		//else if (sum == 2)
		//{
		//	stringstream(str) >> s.DEC;
		//	s.count[2] = 1;
		//}
		//else
		//{
		//	cout << "�������ʲô����?����������0,1��2���������ʲô" << endl;
		//}
		return 1;
	}
}

//����ת��������
void Sys_Carry::Sys_Transfrom(Sys_Carry& s)
{
	for (int i = 0; i < (sizeof(s.count) / sizeof(s.count[0])); i++)
	{
		if (s.count[i])
		{
			switch (i)
			{
			case 0: //������תʮ����
			{
				s.DEC = 0;
				long long sum = s.BIN;
				int i = 0;
				do
				{
					int count = 1;
					if (sum % 10)
					{
						for (int j = 0; j < i; j++)
						{
							count *= 2;
						}
						s.DEC += count;
					}
					i++;
				} while (sum /= 10);
				break;
			}
			case 1: //�˽���תʮ����
			{
				s.DEC = 0;
				long long sum = s.OCT;
				int i = 0;
				do
				{
					int count = 0;
					if (sum % 10)
					{
						if (!i)
						{
							count = sum % 10;
						}
						else
						{
							for (int j = 1; j <= i; j++)
							{
								if (j == 1)
								{
									count = sum % 10;
								}
									count *= 8;
							}
						}
						s.DEC += count;
					}
					i++;
				} while (sum /= 10);
				break;
			}
			case 2:
				break;
			case 3:
			{
				stringstream ss;
				ss << hex << s.HEX;
				ss >> s.DEC;
				break;
			}
			default:
				return;
			}
		}
	}
	//��ʮ����ת��Ϊ��Ľ���
	int base = 1;
	int dec = s.DEC;
	s.BIN = 0;
	while (dec)
	{
		int sum = dec % 2;
		s.BIN += (sum *= base);
		base *= 10;
		dec /= 2;
	}

	base = 1;
	dec = s.DEC;
	s.OCT = 0;
	while (dec)
	{
		int sum = dec % 8;
		s.OCT += (sum *= base);
		base *= 10;
		dec /= 8;
	}

	stringstream ss;
	ss << hex << s.DEC;
	ss >> s.HEX;
}

//������ʷ��¼����
vector<Sys_Carry> Sys_Carry::Return_Vector(Sys_Carry& s)
{
	return s.Data;
}


//�洢����ת����ʷ��¼
void Sys_Carry::Save_history(Sys_Carry& s)
{
	s.Data.push_back(s);
}

//��ʾ��ʷ����
void Sys_Carry::Display_history(vector<Sys_Carry> p)
{
	if (!p.size())
	{
		cout << "��ʷ��¼Ϊ��" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << endl;
	}
	cout << '\n';
}

//����ת��������
void Sys_Calcu(Sys_Carry& s)
{
	while (1)
	{
		cout << "������һ���ַ�(֧�ֶ����� �˽��� ʮ���� ʮ������)" << endl;
		cout << "����s�鿴��ʷ��¼ ����e�������˵�" << endl;
		string input;
		cin >> input;

		if (input.length() == 1)
		{
			const char* c = input.c_str();
			switch (*c)
			{
			case 's':
			{
				s.Display_history(s.Return_Vector(s));
				break;
			}
			case 'e':
			{
				return;
				break;
			}
			}
		}
		else
		{
			if (s.Classify(input, s))
			{
				s.Sys_Transfrom(s);
				cout << s << endl;
				s.Save_history(s);
			}
		}
	}
}