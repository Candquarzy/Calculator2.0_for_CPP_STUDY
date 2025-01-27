#pragma once

using namespace std;

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>
#include <cctype>
#include <ctime>

class Calcu //��׼��������
{
	vector<double> maths; //�洢���ֱ���
	vector<char> symbols; //�洢���ű���
	vector<double> count; //�������

public:
	void reset(Calcu& p);
	void user_Input_0(double m1);
	void user_Input(double m2, char c);
	void Add(Calcu& p);
	void Sub(Calcu& p);
	void Mul(Calcu& p);
	void Div(Calcu& p);
	void Sur(Calcu& p);
	void Pow(Calcu& p);
	void History(Calcu& p);
};
void Calcu_fun(Calcu& p);

class Four_fun //���������������
{
	friend ostream& operator<<(ostream& cout, Four_fun& f);
	vector<double> maths; //�洢���ֱ���
	vector<char> symbols; //�洢���ű���
	vector<string> Formula; //���û������ÿһ����ʽ����
	double count;

public:
	void Classify(string str, Four_fun& f);
	void Parenth(Four_fun& f);
	void Calcu(Four_fun& f);
	double Return_Save_count(string str, Four_fun& f);
	void Return_history(Four_fun& f);
	void Reset_vector(Four_fun& f);
};
void Four_Calcu(Four_fun& f);

class BMI //BMI��������
{
	friend ostream& operator<<(ostream& cout, BMI& b);
	string name; //�洢����
	int age; //�洢����
	double weight; //�洢����
	double height; //�洢���
	double bmi; //�洢BMIֵ
	double left; //�洢�Ƽ��������
	double right; //�洢�Ƽ��������
	string results; //�洢������
	vector<BMI> Data; //��ʷ��¼�洢

public:
	void Classify(string str, BMI& b);
	void Calcu(BMI& b);
	void Save_history(BMI& b);
	vector<BMI> Return_Vector(BMI& b);
	void Display_history(vector<BMI> p);
};
void BMI_Calcu(BMI& b);

class Sys_Carry //���Ƽ�������
{
	friend ostream& operator<<(ostream& cout, Sys_Carry& s);
	long long BIN; //������
	long long OCT; //�˽���
	long int DEC; //ʮ����
	string HEX; //ʮ������
	vector<Sys_Carry> Data;
	int count[4] = { 0,0,0,0 };

public:
	int Classify(string str, Sys_Carry& s);
	void Sys_Transfrom(Sys_Carry& s);
	void Save_history(Sys_Carry& s);
	vector<Sys_Carry> Return_Vector(Sys_Carry& s);
	void Display_history(vector<Sys_Carry> p);
};
void Sys_Calcu(Sys_Carry& s);

class BigNum //��дת����
{
	friend ostream& operator<<(ostream& cout, BigNum& n);
	double sum; //������ת����
	int count; //����ת����
	string math; //�����ַ������
	vector<BigNum> Data;

public:
	void Check_Float(double count, BigNum& n);
	void Float_Transfrom(double count, BigNum& n);
	void Int_Transfrom(int count, BigNum& n);
	void Save_history(BigNum& n);
	vector<BigNum> Return_Vector(BigNum& n);
	void Display_history(vector<BigNum> p);
};
void BigNum_Trans(BigNum& n);

//class Time //ʱ����(��)
//{
//	friend ostream& operator<< (ostream& cout, Time& t);
//	//long int timeStamp; //ʱ���
//	int sencond = 0; //��
//	long double minute = 0; //��
//	double hour = 0; //ʱ
//	double day = 0; //��
//	double week = 0; //��
//	double month = 0; //��
//	double year = 0; //��
//	string times; //���೤ʱ��
//	int count[7] = { 0 };
//
//public:
//	void Classify(string str, Time& t);
//	void Times_Transfrom(Time& t);
//	void Time_Transfrom(Time& t);
//	void All_Times(Time& t);
//	void Times_String(Time& t1, Time& t);
//};
//void Time_Calcu(Time& t);

class Time //ʱ����
{
	friend ostream& operator<<(ostream& cout, Time& t);
	//long int timestamp; //ʱ���
	int sencond = 0; //��
	long double minute = 0; //��
	double hour = 0; //ʱ
	double day = 0; //��
	double week = 0; //��
	double month = 0; //��
	double year = 0; //��
	//string times; //���೤ʱ��
	int sum[7] = { 0 };
	int count[7] = { 0 };
	vector<string> input_data;
	vector<string> output_data;
public:
	int Classify(string str, Time& t);
	void Time_Transfrom(Time& t);
	void Input_Tostring(string str, Time& t, int count);
	vector<string> Return_Input_Vector(Time& t);
	vector<string> Return_Output_Vector(Time& t);
	void Display_history(vector<string>istr, vector<string>ostr);
	void Reset_Data(Time& t);
};
void Time_Calcu(Time& t);

class Storage //��������ݴ洢��λ��
{
	friend ostream& operator<<(ostream& cout, Storage& s);
	long long bit = 0;
	long long byte = 0;
	long double KB = 0;
	long double MB = 0;
	double GB = 0;
	double TB = 0;
	double PB = 0;
	double EB = 0;
	int count[8] = { 0 };
	vector<Storage> Data;

public:
	int Classify(string str, Storage& s);
	void Calcu(Storage& s);
	void Save_history(Storage& s);
	vector<Storage> Return_Vector(Storage& s);
	void Display_history(vector<Storage> p);
};
void Storage_Calcu(Storage& s);

class Length //������
{
	//friend ostream& operator<<(ostream& cout, Length& l);
	double um; //΢��
	double mm; //����
	double cm; //����
	double fm; //����
	double m; //��
	double chi; //��
	double cun; //��
	double km; //ǧ��
	double in; //Ӣ��
	double ft; //Ӣ��
	double mi; //Ӣ��
	int old_count[9] = { 0 };
	int new_count[11] = { 0 };
	vector<string> Data;

public:
	double Classify(string str, Length& l);
	void Calcu(double sum, Length& l);
	vector<string> Return_Vector(Length& l);
	void Display_history(vector<string> p);
};
void Length_Calcu(Length& l);

class Weight //������
{
	double ug; //΢��
	double mg; //����
	double g; //��
	double kg; //ǧ��
	double t; //��
	double lb; //��
	double oz; //��˾
	double jin; //��
	double liang; //��
	int old_count[9] = { 0 };
	int new_count[9] = { 0 };
	vector<string> Data;

public:
	double Classify(string str, Weight& w);
	void Calcu(double sum, Weight& w);
	vector<string> Return_Vector(Weight& w);
	void Display_history(vector<string> p);
};
void Weight_Calcu(Weight& w);

class Area //�����
{
	double mm; //ƽ������
	double cm; //ƽ������
	double m; //ƽ����
	double ha; //����
	double km; //ƽ������
	double mu; //Ķ
	int old_count[6] = { 0 };
	int new_count[6] = { 0 };
	vector<string> Data;

public:
	double Classify(string str, Area& a);
	void Calcu(double sum, Area& a);
	vector<string> Return_Vector(Area& a);
	void Display_history(vector<string> p);
};
void Area_Calcu(Area& a);

class Volume //�����
{
	double mm; //��������
	double cm; //��������
	double dm; //��������
	double m; //������
	double L; //��
	double ml; //����
	int old_count[6] = { 0 };
	int new_count[6] = { 0 };
	vector<string> Data;

public:
	double Classify(string str, Volume& v);
	void Calcu(double sum, Volume& v);
	vector<string> Return_Vector(Volume& a);
	void Display_history(vector<string> p);
};
void Volume_Calcu(Volume& v);

class Temp //�¶���
{
	friend ostream& operator<<(ostream& cout, Temp& t);
	double C = 0; //���϶�
	double F = 0; //���϶�
	double K = 0; //������
	double R = 0; //���϶�
	int count[4] = { 0 };
	vector<Temp> Data;

public:
	int Classify(string str, Temp& t);
	void Calcu(Temp& t);
	void Save_history(Temp& t);
	vector<Temp> Return_Vector(Temp& t);
	void Display_history(vector<Temp> p);
};
void Temp_Calcu(Temp& t);

class Speed //�ٶ���
{
	friend ostream& operator<<(ostream& cout, Speed& s);
	double ms = 0; //��ÿ��
	double kmh = 0; //ǧ��ÿСʱ
	double mph = 0; //Ӣ��ÿСʱ
	int count[3] = { 0 };
	vector<Speed> Data;
	
public:
	int Classify(string str, Speed& s);
	void Calcu(Speed& s);
	void Save_history(Speed& s);
	vector<Speed> Return_Vector(Speed& s);
	void Display_history(vector<Speed> p);
};
void Speed_Calcu(Speed& s);

class World //����ʱ����
{
	//���й���
	string country[10] = {"UTC+0 ��׼ʱ��","UTC+1 ����","UTC+3 ʥ�˵ñ�","UTC+7 ����","UTC+8 ����","UTC+9 ����","UTC+11 Ϥ��","UTC-5 ŦԼ","UTC-6 ֥�Ӹ�","UTC-8 ��ɼ�"};
	//���й���ʱ��
	int time_count[10] = {0,1,3,7,8,9,11,-5,-6,-8};
	struct tm* t; //ʵ����time��
	vector<string> times;
	//time_t times[9];
public:
	void Time_Struct_New(World& w);
	void Time_Trans(World& w);
	void Display_Data(World& w);
};
void World_Time_Calcu(World& w);