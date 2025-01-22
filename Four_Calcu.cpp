#include "class.h"
//#include "Four_fun.h"

//将用户输入的表达式分类输入到成员内
void Four_fun::Classify(const string str, Four_fun& f)
{
	const char* s = str.c_str();
	int i = 0;
	int j = 0;
	int k = 0;
	double sum;
	while (*s)
	{
		if (*s == '+' || *s == '-' || *s == '*' || *s == '/' || *s == '^')
		{
			f.symbols.push_back(*s);
			stringstream(str.substr(i, j)) >> sum;
			f.maths.push_back(sum);
			i = k + 1;
			j = 0;
		}
		s++;
		j++;
		k++;
	}
	stringstream(str.substr(i, j)) >> sum;
	f.maths.push_back(sum);
}

//处理括号(未实现)
void Four_fun::Parenth(Four_fun& f)
{
	vector<char>::iterator left = find_if(f.symbols.begin(), f.symbols.end(), [](char ch)
		{
			return ch == '(';
		});
	vector<char>::iterator right = find_if(f.symbols.begin(), f.symbols.end(), [](char ch)
		{
			return ch == ')';
		});

	if (right == f.symbols.end())
	{
		return;
	}
}

//四则计算器运算函数
void Four_fun::Calcu(Four_fun& f)
{	
	//^运算
	while (1)
	{
		vector<char>::iterator it = find_if(f.symbols.begin(), f.symbols.end(), [](char ch)
			{
				return ch == '^';
			});
		int i;
		double sum;
		if (it == f.symbols.end())
		{
			break;
		}
		else
		{
			i = distance(f.symbols.begin(), it);

			sum = f.maths[i];
			for (int j = 0; j < f.maths[i + 1] - 1; j++)
			{
				sum *= f.maths[i];
			}

			f.symbols.erase(f.symbols.begin() + i);
			f.maths.erase(f.maths.begin() + i, f.maths.begin() + i + 2);
			f.maths.insert(f.maths.begin() + i, sum);
		}
	}
	//* /二级运算
	while (1)
	{
		vector<char>::iterator it = find_if(f.symbols.begin(), f.symbols.end(), [](char ch) 
			{
				return ch == '*' || ch == '/';
			});
		int i;
		double sum;
		if (it == f.symbols.end())
		{
			break;
		}
		else
		{
			i = distance(f.symbols.begin(), it);
			switch (f.symbols[i])
			{
			case '*':
				sum = f.maths[i] * f.maths[i + 1];
				break;
			case '/':
				sum = f.maths[i] / f.maths[i + 1];
				break;
			}

			f.symbols.erase(f.symbols.begin() + i);
			f.maths.erase(f.maths.begin() + i, f.maths.begin() + i + 2);
			f.maths.insert(f.maths.begin() + i, sum);
		}
	}
	//+ -一级运算
	while (f.maths.size() > 1)
	{
		double sum;
		switch (f.symbols[0])
		{
		case '+':
			sum = f.maths[0] + f.maths[1];
			break;
		case '-':
			sum = f.maths[0] - f.maths[1];
			break;
		}

		f.symbols.erase(f.symbols.begin());
		f.maths.erase(f.maths.begin(), f.maths.begin() + 2);
		f.maths.insert(f.maths.begin(), sum);
	}
}

//返回最终结果
double Four_fun::Return_Save_count(string str, Four_fun& f)
{
	string str_n;
	ostringstream oss;
	oss << this->maths[0];
	
	str_n += str;
	str_n += " = ";
	str_n += oss.str();
	f.Formula.push_back(str_n);
	return this->maths[0];
}

//返回历史记录
void Four_fun::Return_history(Four_fun& f)
{
	if (f.Formula.size())
	{
		for (int i = 0; i < f.Formula.size(); i++)
		{
			cout << f.Formula[i] << endl;
		}
	}
	else
	{
		cout << "历史记录为空,快来填满我吧!" << endl;
	}
}

//重置容器
void Four_fun::Reset_vector(Four_fun& f)
{
	f.maths.clear();
	f.symbols.clear();
}

//四则计算器主函数
void Four_Calcu(Four_fun& f)
{
	string str;
	while (1)
	{
		cout << "请输入算式,以数字开始数字结束(输入e退出,输入s查看历史记录)" << endl;
		cout << "仅支持+ - * / ^运算,例如3.14+5.2*2-10/2+2^3" << endl;
		cin >> str;
		if (!str.compare("e"))
		{
			return;
		}
		else if (!str.compare("s"))
		{
			f.Return_history(f);
		}
		else
		{
			f.Classify(str, f);
			f.Calcu(f);

			cout << "计算中..." << endl;
			cout << str << " = " << f.Return_Save_count(str, f) << endl;
			f.Reset_vector(f);
		}
	}
}