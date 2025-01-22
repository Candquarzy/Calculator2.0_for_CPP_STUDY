#include "class.h"
#include "BMI.h"

//BMI数据录入函数
void BMI::Classify(string str, BMI& b)
{
	const char* s = str.c_str();
	int i = 0;
	int j = 0;
	int count = 4;

	while (count)
	{
		if (*s != ' ' && *s != '\0')
		{
			s++;
			j++;
			continue;
		}

		switch (count--)
		{
		case 4:
			b.name = str.substr(i++, j);
			i = ++j;
			break;
		case 3:
			int age;
			stringstream(str.substr(i++, ++j)) >> age;

			if (age > 120)
			{
				cout << "你是什么神仙?" << endl;
				return;
			}
			else if (age <= 120)
			{
				b.age = age;
			}

			i = j;
			break;
		case 2:
		{
			int pos = str.substr(i++, ++j).find('/');

			stringstream(str.substr(--i, j)) >> b.weight;
			if (!(pos == EOF))
			{
				b.weight /= 2;
			}
			i = j;
			break;
		}
		case 1:
			double height;
			stringstream(str.substr(i++, ++j)) >> height;

			if (height > 20)
			{
				b.height = height * 0.01;
			}
			else if (height <= 2.8)
			{
				b.height = height;
			}
			else
			{
				cout << "你是什么勾巴?这么奇怪的身高" << endl;
				return;
			}

			i = j;
			break;
		}
		s++;
	}
}

//BMI计算函数
void BMI::Calcu(BMI& b)
{
	b.bmi = b.weight / (b.height * b.height);
	
	if (b.bmi < 18.5)
	{
		b.results = "你是想要被风刮跑吗?多吃点";
	}
	else if (b.bmi >= 18.5 && b.bmi < 24)
	{
		b.results = "恭喜你,你的BMI非常正常";
	}
	else if (b.bmi >= 24 && b.bmi < 28)
	{
		b.results = "哦吼,你超重了,少吃点吧";
	}
	else if (b.bmi >= 28)
	{
		b.results = "大胖子哈哈哈哈哈(我不歧视胖子)";
	}

	b.left = 18.5 * (b.height * b.height);
	b.right = 24 * (b.height * b.height);
}

//返回历史记录容器
vector<BMI> BMI::Return_Vector(BMI& b)
{
	return b.Data;
}

//存储BMI数据
void BMI::Save_history(BMI& b)
{
	b.Data.push_back(b);
}

//显示历史数据
void BMI::Display_history(vector<BMI> p)
{
	if (!p.size())
	{
		cout << "历史记录为空" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << "编号:" << i + 1 << endl;
		cout << p[i] << endl;
	}
}

//BMI计算器类
void BMI_Calcu(BMI& b)
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	while (1)
	{
		cout << "请输入你的姓名,年龄,体重,身高 中间用空格隔开" << endl;
		cout << "体重若为斤,请在体重后面输入/2 例如:150/2 会自动计算" << endl;
		cout << "身高可以输入米/厘米,可自动识别" << endl;
		cout << "输入s查看历史记录 输入e返回主菜单" << endl;
		string input;

		getline(cin, input);
		if (input.length() == 1)
		{
			const char* s = input.c_str();
			switch (*s)
			{
			case 's':
			{
				//非函数写法
				//if (!b.Return_Vector(b).size())
				//{
				//	cout << "历史记录为空" << endl;
				//	continue;
				//}
				// 
				//for (int i = 0; i < b.Return_Vector(b).size(); i++)
				//{
				//	cout << "编号:" << i + 1 << endl;
				//	cout << b.Return_Vector(b)[i] << endl;
				//}

				b.Display_history(b.Return_Vector(b));
				break;
			}
			case 'e':
				return;
				break;
			}
		}
		else
		{
			b.Classify(input, b);
			b.Calcu(b);
			cout << b << endl;
			b.Save_history(b);
		}
	}
}