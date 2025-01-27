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

class Calcu //标准计算器类
{
	vector<double> maths; //存储数字变量
	vector<char> symbols; //存储符号变量
	vector<double> count; //结果变量

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

class Four_fun //四则运算计算器类
{
	friend ostream& operator<<(ostream& cout, Four_fun& f);
	vector<double> maths; //存储数字变量
	vector<char> symbols; //存储符号变量
	vector<string> Formula; //将用户输入的每一个算式存入
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

class BMI //BMI计算器类
{
	friend ostream& operator<<(ostream& cout, BMI& b);
	string name; //存储姓名
	int age; //存储年龄
	double weight; //存储体重
	double height; //存储身高
	double bmi; //存储BMI值
	double left; //存储推荐最低体重
	double right; //存储推荐最高体重
	string results; //存储结果语句
	vector<BMI> Data; //历史记录存储

public:
	void Classify(string str, BMI& b);
	void Calcu(BMI& b);
	void Save_history(BMI& b);
	vector<BMI> Return_Vector(BMI& b);
	void Display_history(vector<BMI> p);
};
void BMI_Calcu(BMI& b);

class Sys_Carry //进制计算器类
{
	friend ostream& operator<<(ostream& cout, Sys_Carry& s);
	long long BIN; //二进制
	long long OCT; //八进制
	long int DEC; //十进制
	string HEX; //十六进制
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

class BigNum //大写转换类
{
	friend ostream& operator<<(ostream& cout, BigNum& n);
	double sum; //浮点型转换数
	int count; //整型转换数
	string math; //最终字符串结果
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

//class Time //时间类(旧)
//{
//	friend ostream& operator<< (ostream& cout, Time& t);
//	//long int timeStamp; //时间戳
//	int sencond = 0; //秒
//	long double minute = 0; //分
//	double hour = 0; //时
//	double day = 0; //天
//	double week = 0; //周
//	double month = 0; //月
//	double year = 0; //年
//	string times; //共多长时间
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

class Time //时间类
{
	friend ostream& operator<<(ostream& cout, Time& t);
	//long int timestamp; //时间戳
	int sencond = 0; //秒
	long double minute = 0; //分
	double hour = 0; //时
	double day = 0; //天
	double week = 0; //周
	double month = 0; //月
	double year = 0; //年
	//string times; //共多长时间
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

class Storage //计算机数据存储单位类
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

class Length //长度类
{
	//friend ostream& operator<<(ostream& cout, Length& l);
	double um; //微米
	double mm; //毫米
	double cm; //厘米
	double fm; //分米
	double m; //米
	double chi; //尺
	double cun; //寸
	double km; //千米
	double in; //英寸
	double ft; //英尺
	double mi; //英里
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

class Weight //重量类
{
	double ug; //微克
	double mg; //毫克
	double g; //克
	double kg; //千克
	double t; //吨
	double lb; //磅
	double oz; //盎司
	double jin; //斤
	double liang; //两
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

class Area //面积类
{
	double mm; //平方毫米
	double cm; //平方厘米
	double m; //平方米
	double ha; //公顷
	double km; //平方公里
	double mu; //亩
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

class Volume //体积类
{
	double mm; //立方毫米
	double cm; //立方厘米
	double dm; //立方分米
	double m; //立方米
	double L; //升
	double ml; //毫升
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

class Temp //温度类
{
	friend ostream& operator<<(ostream& cout, Temp& t);
	double C = 0; //摄氏度
	double F = 0; //华氏度
	double K = 0; //开尔文
	double R = 0; //兰氏度
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

class Speed //速度类
{
	friend ostream& operator<<(ostream& cout, Speed& s);
	double ms = 0; //米每秒
	double kmh = 0; //千米每小时
	double mph = 0; //英里每小时
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

class World //世界时间类
{
	//所有国家
	string country[10] = {"UTC+0 标准时间","UTC+1 柏林","UTC+3 圣彼得堡","UTC+7 曼谷","UTC+8 北京","UTC+9 东京","UTC+11 悉尼","UTC-5 纽约","UTC-6 芝加哥","UTC-8 洛杉矶"};
	//所有国家时差
	int time_count[10] = {0,1,3,7,8,9,11,-5,-6,-8};
	struct tm* t; //实例化time类
	vector<string> times;
	//time_t times[9];
public:
	void Time_Struct_New(World& w);
	void Time_Trans(World& w);
	void Display_Data(World& w);
};
void World_Time_Calcu(World& w);