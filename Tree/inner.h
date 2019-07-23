#pragma once
#include <iostream>
using namespace std;
#ifndef INNER_H
#define INNER_H
struct Inner {
	//data
	int OwnerPoints; //���� �������
	int OppPoints; //���� ���������
	char Match[10]; //����
	char Name[20]; //�������
	char Opponent[20]; //��������
	//methods
	Inner();
	~Inner();
	bool operator!=(const Inner&);
	bool operator<(const Inner&);
	Inner& operator=(const Inner&);
	friend ostream& operator<<(ostream&, Inner&);
};
#endif INNER_H