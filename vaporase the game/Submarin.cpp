#include"Submarin.h"

Submarin::Submarin() {
	//cout << "const implicit";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->orientareCoada = { '\0' };

}Submarin::Submarin(int x, int y, string orientareCoada) {
	//cout << "constructor with param" << endl;
	this->x = x;
	this->y = y;
	this->len = 2;
	this->orientareCoada = orientareCoada;
}
Submarin::Submarin(const Submarin& a) {
	//cout << "copy constructor" << endl;
	this->x = a.x;
	this->y = a.y;
	this->len = a.len;
	this->orientareCoada = a.orientareCoada;
}
Submarin::~Submarin() {
	//cout << "Destructor";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->orientareCoada = { '\0' };
}
Submarin* Submarin::clone() {
	Submarin* newSubmarin = new Submarin();
	newSubmarin->setX(this->x);
	newSubmarin->setY(this->y);
	newSubmarin->setLen(this->len);
	newSubmarin->setOrientareCoada(this->orientareCoada);
	return newSubmarin;
}
string Submarin::toString() {
	string x, y, l, s;
	x = this->x;
	y = this->y;
	l = this->len;
	return  x + " " + y + " " + l + " " + this->orientareCoada;
}
int Submarin::getX() {

	return this->x;
}
int Submarin::getY() {

	return this->y;
}
int Submarin::getLen() {
	return this->len;
}
string Submarin::getOrientareCoada() {

	return this->orientareCoada;
}
void Submarin::setX(int x) {

	this->x = x;
}
void Submarin::setY(int y) {
	this->y = y;
}

void Submarin::setLen(int len) {
	this->len = len;
}
void Submarin::setOrientareCoada(string orientareCoada) {

	this->orientareCoada = orientareCoada;

}Submarin& Submarin::operator=(const Submarin& a) {

	this->setX(a.x);
	this->setY(a.y);
	this->setLen(a.len);
	this->setOrientareCoada(a.orientareCoada);
	return *this;
}
bool Submarin::operator==(const Submarin& a) {

	return (this->x == a.x) && (this->y == a.y) && (this->orientareCoada.compare(a.orientareCoada) == 0);
}
ostream& operator<<(ostream& os, const Submarin& a) {

	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y << "|" << " Orientare coada:" << a.orientareCoada;
	return os;
}