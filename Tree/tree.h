#pragma once
#ifndef TREE_H
#define TREE_H
struct Inner {
	//data
	int OwnerPoints; //Очки хозяина
	int OppPoints; //Очки соперника
	char Match[10]; //Счет
	char Name[20]; //Команда
	char Opponent[20]; //Соперник
	//methods
	void print();
	Inner();
	~Inner();
	bool operator!=(const Inner&);
	bool operator<(const Inner&);
	Inner& operator=(const Inner&);
};
struct Elem
{
	Inner* inn;
	Elem* left, * right, * parent;
	bool operator<(const Elem &);
	Elem();
	~Elem();
};
class Tree
{
	//корень
	Elem* root;
public:
	Tree();
	~Tree();
	//печать от указанного узла
	void Print(Elem* Node);
	//поиск от указанного узла
	Elem* Search(Elem* Node, Inner *key);
	//min от указанного узла
	Elem* Min(Elem* Node);
	//max от указанного узла
	Elem* Max(Elem* Node);
	//следующий для указанного узла
	Elem* Next(Elem* Node);
	//предыдущий для указанного узла
	Elem* Previous(Elem* Node);
	//вставка узла
	void Insert(Elem* z);
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(Elem* z = 0);
	//получить корень
	Elem* GetRoot();
};
#endif // !TREE_H
