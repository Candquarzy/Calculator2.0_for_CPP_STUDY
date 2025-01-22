#pragma once

#include "class.h"
#include <iostream>
#include <vector>

template<typename C>
//�����¼����
void Save_history(C& p)
{
	p.Data.push_back(p);
}

template<typename V>
//������������
vector<V> Return_vector(V& p)
{
	return p.Data;
}

template<typename V>
//��ʾ��ʷ��¼����
void Display_history(const vector<V> p)
{
	if (!p.size())
	{
		cout << "��ʷ��¼Ϊ��" << endl;
		return;
	}

	for (int i = 0; i < p.size(); i++)
	{
		cout << "���:" << i + 1 << endl;
		cout << p[i] << endl;
	}
}