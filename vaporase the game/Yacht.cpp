#include"Yacht.h"

Yacht::Yacht() {
	//cout << "const implicit";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->orientareCoada = { '\0' };

}Yacht::Yacht(int x, int y, string orientareCoada) {
	//cout << "constructor with param" << endl;
	this->x = x;
	this->y = y;
	this->len = 3;
	this->orientareCoada = orientareCoada;
}
Yacht::Yacht(const Yacht& a) {
	//cout << "copy constructor" << endl;
	this->x = a.x;
	this->y = a.y;
	this->len = a.len;
	this->orientareCoada = a.orientareCoada;
}
Yacht::~Yacht() {
	//cout << "Destructor";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->orientareCoada = { '\0' };
}
Yacht* Yacht::clone() {
	Yacht* newYacht = new Yacht();
	newYacht->setX(this->x);
	newYacht->setY(this->y);
	newYacht->setLen(this->len);
	newYacht->setOrientareCoada(this->orientareCoada);
	return newYacht;
}
string Yacht::toString() {
	string x, y, l, s;
	x = this->x;
	y = this->y;
	l = this->len;
	return  x + " " + y + " " + l + " " + this->orientareCoada;
}
int Yacht::getX() {

	return this->x;
}
int Yacht::getY() {

	return this->y;
}
int Yacht::getLen() {
	return this->len;
}
string Yacht::getOrientareCoada() {

	return this->orientareCoada;
}
void Yacht::setX(int x) {

	this->x = x;
}
void Yacht::setY(int y) {
	this->y = y;
}

void Yacht::setLen(int len) {
	this->len = len;
}
void Yacht::setOrientareCoada(string orientareCoada) {

	this->orientareCoada = orientareCoada;

}Yacht& Yacht::operator=(const Yacht& a) {

	this->setX(a.x);
	this->setY(a.y);
	this->setLen(a.len);
	this->setOrientareCoada(a.orientareCoada);
	return *this;
}
bool Yacht::operator==(const Yacht& a) {

	return (this->x == a.x) && (this->y == a.y) && (this->orientareCoada.compare(a.orientareCoada) == 0);
}
ostream& operator<<(ostream& os, const Yacht& a) {

	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y << "|" << " Orientare coada:" << a.orientareCoada;
	return os;
}