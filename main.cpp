#include "class.h"

int main()
{			
	while (1)
	{
		int user_input;
		cout << "请输入你的选择:" << endl;
		cout << "1.普通计算器(加减乘除模幂)" << endl;
		cout << "2.四则运算计算器(加减乘除模幂)" << endl;
		cout << "3.科学计算器(未实现)" << endl;
 		cout << "4.BMI计算器" << endl;
		cout << "5.进制计算器" << endl;
		cout << "6.大写数字转换" << endl;
		cout << "7.时间转换计算器(BUG)" << endl;
		cout << "8.计算机数据转换计算器" << endl;
		cout << "9.长度转换" << endl;
		cout << "10.重量转换" << endl;
		cout << "11.面积转换" << endl;
		cout << "12.体积转换" << endl;
		cout << "13.温度转换" << endl;
		cout << "14.速度转换" << endl;
		cout << "15.称呼计算器(没想好要怎么写)" << endl;
		cout << "16.世界时间计算器(未考虑夏令时,BUG)" << endl;
		cout << "0.退出计算器(默认)" << endl;

		cin >> user_input;
		//cin 输入错误后会出现空淡 需要清除用户输入的内容
		switch (user_input)
		{
		case 1:
		{
			Calcu C1;
			Calcu_fun(C1);
			break;
		}
		case 2:
		{
			Four_fun F1;
			Four_Calcu(F1);
			break;
		}
		case 3:
		{
			break;
		}
		case 4:
		{
			BMI B1;
			BMI_Calcu(B1);
			break;
		}
		case 5:
		{
			Sys_Carry S1;
			Sys_Calcu(S1);
			break;
		}
		case 6:
		{
			BigNum N1;
			BigNum_Trans(N1);
			break;
		}
		case 7:
		{
			Time T1;
			Time_Calcu(T1);
			break;
		}
		case 8:
		{
			Storage S1;
			Storage_Calcu(S1);
			break;
		}
		case 9:
		{
			Length L1;
			Length_Calcu(L1);
			break;
		}
		case 10:
		{
			Weight W1;
			Weight_Calcu(W1);
			break;
		}
		case 11:
		{
			Area A1;
			Area_Calcu(A1);
			break;
		}
		case 12:
		{
			Volume V1;
			Volume_Calcu(V1);
			break;
		}
		case 13:
		{
			Temp T1;
			Temp_Calcu(T1);
			break;
		}
		case 14:
		{
			Speed S1;
			Speed_Calcu(S1);
			break;
		}
		case 16:
		{
			World W1;
			World_Time_Calcu(W1);
			break;
		}
		case 0:
			cout << "感谢使用,退出中..." << endl;
			return 0;
			break;
		default:
			cout << "输入错误,请重新输入" << endl;
			cout << "\n" << endl;
			break;
		}
	}

	return 0;
}