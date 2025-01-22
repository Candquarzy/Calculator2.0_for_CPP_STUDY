#include "class.h"

//将用户输入的数字存储到类成员内
void Calcu::user_Input_0(double m1)
{
	maths.push_back(m1);
}

void Calcu::user_Input(double m2, char c)
{
	//maths.push_back(m1);
	maths.push_back(m2);
	symbols.push_back(c);
	symbols.push_back('=');
}

//重置容器
void Calcu::reset(Calcu& p)
{
	p.maths.clear();
	p.symbols.clear();
	p.count.clear();
}

//计算 成员函数实现
void Calcu::Add(Calcu& p)
{
	if (p.count.size())
	{
		p.count.push_back(p.count.back() + p.maths.back());
	}
	else
	{
		p.count.push_back(p.maths[p.maths.size() - 2] + p.maths.back());
	}
	cout << p.count.back() << endl;
}
void Calcu::Sub(Calcu& p)
{
	if (p.count.size())
	{
		p.count.push_back(p.count.back() - p.maths.back());
	}
	else
	{
		p.count.push_back(p.maths[p.maths.size() - 2] - p.maths.back());
	}
	cout << p.count.back() << endl;
}
void Calcu::Mul(Calcu& p)
{
	if (p.count.size())
	{
		p.count.push_back(p.count.back() * p.maths.back());
	}
	else
	{
		p.count.push_back(p.maths[p.maths.size() - 2] * p.maths.back());
	}
	cout << p.count.back() << endl;
}
void Calcu::Div(Calcu& p)
{	
	if (p.count.size())
	{
		p.count.push_back(p.count.back() / p.maths.back());
	}
	else
	{
		p.count.push_back(p.maths[p.maths.size() - 2] / p.maths.back());
	}
	cout << p.count.back() << endl;
}
void Calcu::Sur(Calcu& p)
{
	if (p.count.size())
	{
		p.count.push_back(int(p.count.back()) % int(p.maths.back()));
	}
	else
	{
		p.count.push_back(int(p.maths[p.maths.size() - 2]) % int(p.maths.back()));
	}
	cout << p.count.back() << endl;
}
void Calcu::Pow(Calcu& p)
{
	if (!p.maths.back())
	{
		if (!p.maths[p.maths.size() - 2])
		{
			p.count.push_back(0);
		}
		else
		{
			p.count.push_back(1);
		}
	}
	else if (p.count.size())
	{
		if (p.maths.back() == 1)
		{
			p.count.push_back(p.count.back());
		}
		else
		{
			double count = p.count.back();
			for (int i = 0; i < p.maths.back() - 1; i++)
			{
				count *= p.count.back();
			}
			p.count.push_back(count);
		}
	}
	else
	{
		if (p.maths.back() == 1)
		{
			p.count.push_back(p.maths[p.maths.size() - 2]);
		}
		else
		{
			double count = p.maths[p.maths.size() - 2];
			for (int i = 0; i < p.maths.back() - 1; i++)
			{
				count *= p.maths[p.maths.size() - 2];
			}
			p.count.push_back(count);
		}
	}
	cout << p.count.back() << endl;
}

//成员函数 显示历史记录
void Calcu::History(Calcu& p)
{
	int i = 0;
	int j = 0;
	int k = 0;

	while (1)
	{
		if (i < 1)
		{			
			cout << p.maths[i];
			cout << p.symbols[j];
			cout << p.maths[++i];
			cout << p.symbols[++j];
			cout << p.count[k] << endl;
		}
		else
		{
			cout << p.count[k];
			cout << p.symbols[++j];
			cout << p.maths[++i];
			cout << p.symbols[++j];
			cout << p.count[++k] << endl;
		}
		if (i >= p.maths.size() - 1 || j >= p.symbols.size() - 1 || k >= p.count.size() - 1)
		{
			cout << "历史记录显示完成" << endl;
			break;
		}
	}
}

//计算器主函数
void Calcu_fun(Calcu& p)
{
	double num;
	double num2;
	char ch;
	
error:
	p.reset(p);
	cout << "请输入一个数字:(输入-1退出)" << endl;
	cin >> num;
	if (num == -1)
	{
		return;
	}
	p.user_Input_0(num);

	int j = 0;

reset:
	while (1)
	{
		cout << "请输入你要运算的符号(输入e退出,输入c清除数据,输入s查看历史记录)" << endl;
		cout << "+加法 -减法 *乘法 /除法 %求余 ^幂" << endl;
		cin >> ch;
		int i = 0;
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^' && ch != 'c' && ch != 'e' && ch != 's')
		{
			i++;
			cout << "符号输入有误,请你重新输入" << endl;
		}

		while (i)
		{
			cout << "请输入你要运算的符号(输入e退出,输入c清除数据,输入s查看历史记录)" << endl;
			cout << "+加法 -减法 *乘法 /除法 %求余 ^幂" << endl;
			cin >> ch;
			if (i == 2)
			{
				cout << "捏妈妈滴,不看提示乱输是吧?" << endl;
				return;
			}
			if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^' && ch != 'c' && ch != 'e' && ch != 's')
			{
				i++;
				cout << "符号输入有误,请你重新输入" << endl;
			}
			else
			{
				i = 0;
			}
		}

		if (ch == 'c')
		{
			cout << "历史记录已清空" << endl;
			goto error;
		}
		else if (ch == 'e')
		{
			return;
		}
		else if (ch == 's')
		{
			if (!j)
			{
				cout << "当前无历史记录" << endl;
				goto reset;
			}
			p.History(p);
			goto reset;
		}

		cout << "请输入一个数字:" << endl;
		cin >> num2;
		p.user_Input(num2, ch);
		j++;

		switch (ch)
		{
		case '+':
			p.Add(p);
			break;
		case '-':
			p.Sub(p);
			break;
		case '*':
			p.Mul(p);
			break;
		case '/':
			if (!num2)
			{
				cout << "被除数不能为0,计算器重置" << endl;
				goto error;
			}
			p.Div(p);
			break;
		case '%':
			p.Sur(p);
			break;
		case '^':
			p.Pow(p);
			break;
		}
	}

}