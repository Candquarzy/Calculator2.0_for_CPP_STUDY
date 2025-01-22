#pragma once

#include "class.h"
#include <iostream>
#include <vector>

template<typename C>
//保存记录函数
void Save_history(C& p)
{
	p.Data.push_back(p);
}

template<typename V>
//返回容器函数
vector<V> Return_vector(V& p)
{
	return p.Data;
}

template<typename V>
//显示历史记录函数
void Display_history(const vector<V> p)
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