#include "class.h"

int main()
{			
	while (1)
	{
		int user_input;
		cout << "���������ѡ��:" << endl;
		cout << "1.��ͨ������(�Ӽ��˳�ģ��)" << endl;
		cout << "2.�������������(�Ӽ��˳�ģ��)" << endl;
		cout << "3.��ѧ������(δʵ��)" << endl;
 		cout << "4.BMI������" << endl;
		cout << "5.���Ƽ�����" << endl;
		cout << "6.��д����ת��" << endl;
		cout << "7.ʱ��ת��������(BUG)" << endl;
		cout << "8.���������ת��������" << endl;
		cout << "9.����ת��" << endl;
		cout << "10.����ת��" << endl;
		cout << "11.���ת��" << endl;
		cout << "12.���ת��" << endl;
		cout << "13.�¶�ת��" << endl;
		cout << "14.�ٶ�ת��" << endl;
		cout << "15.�ƺ�������(û���Ҫ��ôд)" << endl;
		cout << "16.����ʱ�������(δ��������ʱ,BUG)" << endl;
		cout << "0.�˳�������(Ĭ��)" << endl;

		cin >> user_input;
		//cin �����������ֿյ� ��Ҫ����û����������
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
			cout << "��лʹ��,�˳���..." << endl;
			return 0;
			break;
		default:
			cout << "�������,����������" << endl;
			cout << "\n" << endl;
			break;
		}
	}

	return 0;
}