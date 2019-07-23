#pragma once
#include <iostream>
using namespace std;
#ifndef INNER_H
#define INNER_H
struct Inner {
	//data
	int OwnerPoints; //Очки хозяина
	int OppPoints; //Очки соперника
	char Match[10]; //Счет
	char Name[20]; //Команда
	char Opponent[20]; //Соперник
	//methods
	Inner();
	~Inner();
	bool operator!=(const Inner&);
	bool operator<(const Inner&);
	Inner& operator=(const Inner&);
	friend ostream& operator<<(ostream&, Inner&);
};
#endif INNER_H