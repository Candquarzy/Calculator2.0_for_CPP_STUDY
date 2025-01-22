#include "class.h"

//���û���������ִ洢�����Ա��
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

//��������
void Calcu::reset(Calcu& p)
{
	p.maths.clear();
	p.symbols.clear();
	p.count.clear();
}

//���� ��Ա����ʵ��
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

//��Ա���� ��ʾ��ʷ��¼
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
			cout << "��ʷ��¼��ʾ���" << endl;
			break;
		}
	}
}

//������������
void Calcu_fun(Calcu& p)
{
	double num;
	double num2;
	char ch;
	
error:
	p.reset(p);
	cout << "������һ������:(����-1�˳�)" << endl;
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
		cout << "��������Ҫ����ķ���(����e�˳�,����c�������,����s�鿴��ʷ��¼)" << endl;
		cout << "+�ӷ� -���� *�˷� /���� %���� ^��" << endl;
		cin >> ch;
		int i = 0;
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^' && ch != 'c' && ch != 'e' && ch != 's')
		{
			i++;
			cout << "������������,������������" << endl;
		}

		while (i)
		{
			cout << "��������Ҫ����ķ���(����e�˳�,����c�������,����s�鿴��ʷ��¼)" << endl;
			cout << "+�ӷ� -���� *�˷� /���� %���� ^��" << endl;
			cin >> ch;
			if (i == 2)
			{
				cout << "�������,������ʾ�����ǰ�?" << endl;
				return;
			}
			if (ch != '+' && ch != '-' && ch != '*' && ch != '/' && ch != '%' && ch != '^' && ch != 'c' && ch != 'e' && ch != 's')
			{
				i++;
				cout << "������������,������������" << endl;
			}
			else
			{
				i = 0;
			}
		}

		if (ch == 'c')
		{
			cout << "��ʷ��¼�����" << endl;
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
				cout << "��ǰ����ʷ��¼" << endl;
				goto reset;
			}
			p.History(p);
			goto reset;
		}

		cout << "������һ������:" << endl;
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
				cout << "����������Ϊ0,����������" << endl;
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