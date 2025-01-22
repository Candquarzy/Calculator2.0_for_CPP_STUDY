#include "class.h"

//用户输入分类成员函数
double Weight::Classify(string str, Weight& w)
{
	string::iterator letter = find_if(str.begin(), str.end(), [](char ch)
		{
			return ch >= 'A';
		});
	string::iterator symbols = find(str.begin(), str.end(), '-');

	if (letter == str.end() || symbols == str.end())
	{
		cout << "数据输入都输不明白?" << endl;
		return 0;
	}

	string str_arr[9] = { "ug","mg","g","kg","t","lb","oz","jn","la" };
	string Old = str.substr(distance(str.begin(), letter), distance(letter, symbols));
	string New = str.substr(distance(str.begin(), symbols) + 1, distance(symbols, str.end()));
	for (int i = 0; i < sizeof(str_arr) / sizeof(str_arr[0]); i++)
	{
		if (!Old.compare(str_arr[i]))
		{
			w.old_count[i] = 1;
		}
		if (!New.compare(str_arr[i]))
		{
			w.new_count[i] = 1;
		}
	}

	double sum;
	stringstream(str) >> sum;
	return sum;
}

//重量转换计算器成员函数
void Weight::Calcu(double sum, Weight& w)
{
	string str_arr[9] = { "ug","mg","g","kg","t","磅","盎司","斤","两" };

	stringstream ss;
	ss << fixed << setprecision(3) << sum;
	for (int i = 0; i < sizeof(w.old_count) / sizeof(w.old_count[0]); i++)
	{
		if (w.old_count[i])
		{
			cout << sum << str_arr[i] << " = ";
			w.Data.push_back(ss.str());
			w.Data.back() += str_arr[i];
			w.Data.back() += " = ";
			switch (i)
			{
			case 0: //微克
				w.ug = sum;
				w.mg = w.ug / 1000;
				w.g = w.mg / 1000.0;
				w.kg = w.g / 1000;
				break;
			case 1: //毫克
				w.mg = sum;
				w.g = w.mg / 1000.0;
				w.kg = w.g / 1000;
				break;
			case 2: //克
				w.g = sum;
				w.kg = w.g / 1000;
				break;
			case 3: //千克
				w.kg = sum;
				break;
			case 4: //吨
				w.t = sum;
				w.kg = w.t * 1000;
				break;
			case 5: //磅
				w.lb = sum;
				w.kg = w.lb * 0.453592;
				break;
			case 6: //盎司
				w.oz = sum;
				w.lb = w.oz / 16;
				w.kg = w.lb * 0.453592;
				break;
			case 7: //斤
				w.jin = sum;
				w.kg = w.jin / 2;
				break;
			case 8: //两
				w.liang = sum;
				w.kg = w.liang / 20;
				break;
			}
			w.old_count[i] = 0;
			break;
		}
	}

	ss.str("");
	ss.clear();
	for (int i = 0; i < sizeof(w.new_count) / sizeof(w.new_count[0]); i++)
	{
		if (w.new_count[i])
		{
			switch (i)
			{
			case 0:
				w.g = w.kg * 1000;
				w.mg = w.g * 1000;
				w.ug = w.mg * 1000;
				cout << w.ug;
				ss << fixed << setprecision(3) << w.ug;
				w.Data.back() += ss.str();
				break;
			case 1:
				w.g = w.kg * 1000;
				w.mg = w.g * 1000;
				cout << w.mg;
				ss << fixed << setprecision(3) << w.mg;
				w.Data.back() += ss.str();
				break;
			case 2:
				w.g = w.kg * 1000;
				cout << w.g;
				ss << fixed << setprecision(3) << w.g;
				w.Data.back() += ss.str();
				break;
			case 3:
				cout << w.kg;
				ss << fixed << setprecision(3) << w.kg;
				w.Data.back() += ss.str();
				break;
			case 4:
				w.t = w.kg / 1000;
				cout << w.t;
				ss << fixed << setprecision(3) << w.t;
				w.Data.back() += ss.str();
				break;
			case 5:
				w.lb = w.kg / 0.453592;
				cout << w.lb;
				ss << fixed << setprecision(3) << w.lb;
				w.Data.back() += ss.str();
				break;
			case 6:
				w.lb = w.kg / 0.453592;
				w.oz = w.lb * 16;
				cout << w.oz;
				ss << fixed << setprecision(3) << w.oz;
				w.Data.back() += ss.str();
				break;
			case 7:
				w.jin = w.kg * 2;
				cout << w.jin;
				ss << fixed << setprecision(3) << w.jin;
				w.Data.back() += ss.str();
				break;
			case 8:
				w.g = w.kg * 1000;
				w.liang = w.g / 50;
				cout << w.liang;
				ss << fixed << setprecision(3) << w.liang;
				w.Data.back() += ss.str();
				break;
			}
			cout << str_arr[i] << endl;
			w.Data.back() += str_arr[i];
			w.new_count[i] = 0;
			break;
		}
	}
	cout << endl;
}

//返回容器成员函数
vector<string> Weight::Return_Vector(Weight& w)
{
	return w.Data;
}

//显示历史记录成员函数
void Weight::Display_history(vector<string> p)
{
	if (!p.size())
	{
		cout << "历史记录为空" << endl;
		cout << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << i + 1 << ". " << p[i] << endl;
	}
	cout << endl;
}

//重量转换计算器主函数
void Weight_Calcu(Weight& w)
{
	while (1)
	{
		string input;
		cout << "请输入你要转换的数据,并附带单位再使用-链接你要转换后的单位" << endl;
		cout << "例:1024kg-t 其中1024kg为你要转换的数据,t为你要转换后的单位" << endl;
		cout << "支持ug微克 mg毫克 g克 kg千克 t吨 lb磅 oz盎司 jn斤 la两" << endl;
		cout << "(*输入磅和盎司可能会丢失转换精度) 	输入s查看历史记录 输入e返回主菜单" << endl;
		cin >> input;
		cout << endl;

		if (input.length() == 1)
		{
			const char* s = input.c_str();
			switch (*s)
			{
			case 's':
				w.Display_history(w.Return_Vector(w));
				break;
			case 'e':
				return;
				break;
			}
		}
		else
		{
			double sum = w.Classify(input, w);
			if (sum)
			{
				w.Calcu(sum, w);
			}
		}
	}
}