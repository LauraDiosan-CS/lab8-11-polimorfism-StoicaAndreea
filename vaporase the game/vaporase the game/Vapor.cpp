#include"Vapor.h"

Vapor::Vapor() {
	//cout << "const implicit";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->orientareCoada = { '\0' };

}Vapor::Vapor(int x, int y, int len, string orientareCoada) {
	//cout << "constructor with param" << endl;
	this->x = x;
	this->y = y;
	this->len = len;
	this->orientareCoada = orientareCoada;
}
Vapor::Vapor(const Vapor& a) {
	//cout << "copy constructor" << endl;
	this->x = a.x;
	this->y = a.y;
	this->len = a.len;
	this->orientareCoada = a.orientareCoada;
}
Vapor::~Vapor() {
	//cout << "Destructor";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->orientareCoada = { '\0' };
}
int Vapor::getX() {

	return this->x;
}
int Vapor::getY() {

	return this->y;
}
int Vapor::getLen() {
	return this->len;
}
string Vapor::getOrientareCoada() {

	return this->orientareCoada;
}
void Vapor::setX(int x) {

	this->x = x;
}
void Vapor::setY(int y) {
	this->y = y;
}

void Vapor::setLen(int len) {
	this->len = len;
}
void Vapor::setOrientareCoada(string orientareCoada) {

	this->orientareCoada = orientareCoada;

}Vapor& Vapor::operator=(const Vapor& a) {

	this->setX(a.x);
	this->setY(a.y);
	this->setLen(a.len);
	this->setOrientareCoada(a.orientareCoada);
	return *this;
}
bool Vapor::operator==(const Vapor& a) {

	return (this->x == a.x) && (this->y == a.y) && (this->orientareCoada.compare(a.orientareCoada) == 0);
}
ostream& operator<<(ostream& os, const Vapor& a) {

	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y << "|" << " Orientare coada:" << a.orientareCoada;
	return os;
}