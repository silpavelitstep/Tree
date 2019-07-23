#include "inner.h"
#include <iostream>
using namespace std;
#pragma warning(disable:4996)
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
ostream& operator<<(ostream& out, Inner& inn) {
	out<< inn.Name << inn.Match << inn.Opponent << endl;
	return out;
}