#pragma once
#pragma warning(disable:4996)
#include <iostream>
using namespace std;
#ifndef TREE_H
#define TREE_H
template<class T>
struct Elem
{
	T* inn;
	Elem* left, * right, * parent;
	bool operator<(const Elem &);
	Elem();
	~Elem();
};
template<class T>
class Tree
{
	//корень
	Elem<T>* root;
public:
	Tree();
	~Tree();
	//печать от указанного узла
	void Print(Elem<T>* Node);
	//поиск от указанного узла
	Elem<T>* Search(Elem<T>* Node, T *key);
	//min от указанного узла
	Elem<T>* Min(Elem<T>* Node);
	//max от указанного узла
	Elem<T>* Max(Elem<T>* Node);
	//следующий для указанного узла
	Elem<T>* Next(Elem<T>* Node);
	//предыдущий для указанного узла
	Elem<T>* Previous(Elem<T>* Node);
	//вставка узла
	void Insert(Elem<T>* z);
	//удаление ветки для указанного узла,
	//0 - удаление всего дерева
	void Del(Elem<T>* z = 0);
	//получить корень
	Elem<T>* GetRoot();
};

using namespace std;
template<class T>
Tree<T>::Tree()
{
	root = 0;
	cout << "new Tree: " << (int)this << endl;
}
template<class T>
Tree<T>::~Tree()
{
	cout << "del Tree: " << (int)this << endl;
	Del();
}
//Рекурсивный обход дерева
template<class T>
void Tree<T>::Print(Elem<T>* Node)
{
	if (Node != 0)
	{
		Print(Node->left);
		cout << (*(Node->inn));
		Print(Node->right);
	}
}
template<class T>
Elem<T>* Tree<T>::Search(Elem<T>* Node, T* key)
{
	//Пока есть узлы и ключи не совпадают
	while (Node != 0 && *key != *(Node->inn))
	{
		if (*key < *(Node->inn))
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}
template<class T>
Elem<T>* Tree<T>::Min(Elem<T>* Node)
{
	//Поиск самого "левого" узла
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
template<class T>
Elem<T>* Tree<T>::Max(Elem<T>* Node)
{
	//Поиск самого "правого" узла
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}
template<class T>
Elem<T>* Tree<T>::Next(Elem<T>* Node)
{
	Elem<T>* y = 0;
	if (Node)
	{
		//если есть правый потомок
		if (Node->right != 0)
			return Min(Node->right);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node справа
		while (y != 0 && Node == y->right)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
template<class T>
Elem<T>* Tree<T>::Previous(Elem<T>* Node)
{
	Elem* y = 0;
	if (Node != 0)
	{
		//если есть левый потомок
		if (Node->left != 0)
			return Max(Node->left);
		//родитель узла
		y = Node->parent;
		//если Node не корень и Node слева
		while (y != 0 && Node == y->left)
		{
			//Движемся вверх
			Node = y;
			y = y->parent;
		}
	}
	return y;
}
template<class T>
Elem<T>* Tree<T>::GetRoot()
{
	return root;
}
template<class T>
bool Elem<T>::operator<(const Elem<T>& right) {
	return *(this->inn) < *(right.inn);
}
template<class T>
void Tree<T>::Insert(Elem<T>* z)
{
	//потомков нет
	z->left = NULL;
	z->right = NULL;
	Elem<T>* y = NULL;
	Elem<T>* Node = root;
	//поиск места
	while (Node != 0)
	{
		//будущий родитель
		y = Node;
		if (*z < *Node)//*(this->inn) < *(right.inn)
			Node = Node->left;
		else
			Node = Node->right;
	}
	//заполняем родителя
	z->parent = y;
	if (y == 0) //элемент первый (единственный)
		root = z;
	//чей ключ больше?
	else if (*z < *y)
		y->left = z;
	else
		y->right = z;
}
template<class T>
void Tree<T>::Del(Elem<T>* z)
{
	//удаление куста
	if (z)
	{
		Elem<T> *Node, *y;
		//не 2 ребенка
		if (z->left == 0 || z->right == 0)//one child or nobody
			y = z;
		else
			y = Next(z);//two children/////////////////
		if (y->left)
			Node = y->left;
		else
			Node = y->right;
		if (Node)
			Node->parent = y->parent;
		//Удаляется корневой узел?
		if (y->parent == 0)
			root = Node;
		else if (y == y->parent->left)
			y->parent->left = Node;
		else
			//справа от родителя?
			y->parent->right = Node;
		//Копирование данных узла
		if (y != z)
			* (z->inn) = *(y->inn);

		delete y;
	}
	else //удаление всего дерева z=0
		while (root)
			Del(root);
}
template<class T>
Elem<T>::Elem() {
	inn = new T;
	cout << "new Elem: " << (int)this << endl;
}
template<class T>
Elem<T>::~Elem() {
	cout << "del Elem: " << (int)this << endl;
	delete inn;
}



#endif // !TREE_H
