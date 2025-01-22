#include "class.h"
#include "Sys.h"

//数据归类成员函数
int Sys_Carry::Classify(string str, Sys_Carry& s)
{
	//判断字符串内是否有字母,如果有,那就是十六进制
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

	//判断是否有大于8的字符,如果有,那就是十进制或十六进制
	string::iterator oct = find_if(str.begin(), str.end(), [](char c)
		{
			return c >= '8';
		});
	if (oct != str.end())
	{
		cout << "自动分辨程序识别错误, 请问你输入的是十进制还是十六进制?" << endl;
		cout << "十进制请输入0,十六进制请输入1" << endl;
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
			cout << "你输入的什么勾巴?我让你输入1和0你输入的是什么" << endl;
			return 0;
		}
		return 1;
	}
	//判断是否有大于2的字符,如果有,那就是八进制或者十进制或者十六进制
	string::iterator bin = find_if(str.begin(), str.end(), [](char c)
		{
			return c >= '2';
		});
	//如果找到大于2的字符,但是没有找到大于8的字符,那就是八进制或者十进制或者十六进制
	if (bin != str.end() && oct == str.end())
	{
		int sum;
		cout << "自动分辨程序识别错误,请问你输入的是八进制,十进制还是十六进制?" << endl;
		cout << "八进制请输入0,十进制请输入1,十六进制请输入2" << endl;
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
			cout << "你输入的什么勾巴?我让你输入1和0你输入的是什么" << endl;
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
		//	cout << "你输入的什么勾巴?我让你输入1和0你输入的是什么" << endl;
		//}
		return 1;
	}
	//如果没有找到大于2的字符,那么有可能是二进制,有可能是八进制,有可能是十进制,也有可能是十六进制*
	if (bin == str.end())
	{
		int sum;
		cout << "自动分辨程序识别错误,请问你输入的是二进制,八进制,十进制还是十六进制?" << endl;
		cout << "二进制请输入0,八进制请输入1,十进制请输入2,十六进制请输入3" << endl;
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
			cout << "你输入的什么勾巴?我让你输入1和0你输入的是什么" << endl;
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
		//	cout << "你输入的什么勾巴?我让你输入0,1和2你输入的是什么" << endl;
		//}
		return 1;
	}
}

//进制转换计算器
void Sys_Carry::Sys_Transfrom(Sys_Carry& s)
{
	for (int i = 0; i < (sizeof(s.count) / sizeof(s.count[0])); i++)
	{
		if (s.count[i])
		{
			switch (i)
			{
			case 0: //二进制转十进制
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
			case 1: //八进制转十进制
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
	//将十进制转换为别的进制
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

//返回历史记录容器
vector<Sys_Carry> Sys_Carry::Return_Vector(Sys_Carry& s)
{
	return s.Data;
}


//存储进制转换历史记录
void Sys_Carry::Save_history(Sys_Carry& s)
{
	s.Data.push_back(s);
}

//显示历史数据
void Sys_Carry::Display_history(vector<Sys_Carry> p)
{
	if (!p.size())
	{
		cout << "历史记录为空" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << p[i] << endl;
	}
	cout << '\n';
}

//进制转换主函数
void Sys_Calcu(Sys_Carry& s)
{
	while (1)
	{
		cout << "请输入一串字符(支持二进制 八进制 十进制 十六进制)" << endl;
		cout << "输入s查看历史记录 输入e返回主菜单" << endl;
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