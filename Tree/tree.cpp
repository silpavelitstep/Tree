#pragma warning(disable:4996)
#include "tree.h"
#include <iostream>
using namespace std;
void Inner::print() {
	cout << Name << Match << Opponent << endl;
}
bool Inner::operator!=(const Inner& right) {
	return strcmp(this->Name, right.Name);//strcmp==0 if equals, "!=" return true if this->Name != left.Name  
}
bool Inner::operator<(const Inner& right) {
	return strcmp(this->Name, right.Name) < 0;
}
Inner& Inner::operator=(const Inner& right) {
	strcpy(this->Match, right.Match);
	strcpy(this->Name, right.Name);
	strcpy(this->Opponent, right.Opponent);
	this->OwnerPoints = right.OwnerPoints;
	this->OppPoints = right.OppPoints;
	return *this;
}
Inner::Inner() {
	cout << "new Inner: " << (int)this << endl;
}
Inner::~Inner() {
	cout << "free Inner: " << (int)this << endl;
}
//////////////////////////////////////
Tree::Tree()
{
	root = 0;
	//cout << "new Tree: " << (int)this << endl;
}
Tree::~Tree()
{
	//cout << "del Tree: " << (int)this << endl;
	Del();

}
//Рекурсивный обход дерева
void Tree::Print(Elem* Node)
{
	if (Node != 0)
	{
		Print(Node->left);
		Node->inn->print();
		Print(Node->right);
	}
}
Elem* Tree::Search(Elem* Node, Inner *key)
{
	//Пока есть узлы и ключи не совпадают
	while (Node != 0 && *key != *(Node->inn) )
	{
		if (*key < *(Node->inn) )
			Node = Node->left;
		else
			Node = Node->right;
	}
	return Node;
}
Elem* Tree::Min(Elem* Node)
{
	//Поиск самого "левого" узла
	if (Node != 0)
		while (Node->left != 0)
			Node = Node->left;
	return Node;
}
Elem* Tree::Max(Elem* Node)
{
	//Поиск самого "правого" узла
	if (Node != 0)
		while (Node->right != 0)
			Node = Node->right;
	return Node;
}
Elem* Tree::Next(Elem* Node)
{
	Elem* y = 0;
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
Elem* Tree::Previous(Elem* Node)
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
Elem* Tree::GetRoot()
{
	return root;
}
bool Elem::operator<(const Elem& right) {
	return *(this->inn) < *(right.inn);
}
void Tree::Insert(Elem* z)
{
	//потомков нет
	z->left = NULL;
	z->right = NULL;
	Elem* y = NULL;
	Elem* Node = root;
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
void Tree::Del(Elem* z)
{
	//удаление куста
	if (z)
	{
		Elem *Node, *y;
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
			*(z->inn) = *(y->inn);
				
		delete y;
	}
	else //удаление всего дерева z=0
		while (root)
			Del(root);
}
Elem::Elem() {
	inn = new Inner;
	//cout << "new Elem: " << (int)this << endl;
}
Elem::~Elem() {
	//cout << "del Elem: " << (int)this << endl;
	delete inn;
}


