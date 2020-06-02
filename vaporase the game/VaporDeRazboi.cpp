#include"VaporDeRazboi.h"

VaporDeRazboi::VaporDeRazboi() {
	//cout << "const implicit";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->orientareCoada = { '\0' };

}VaporDeRazboi::VaporDeRazboi(int x, int y, string orientareCoada) {
	//cout << "constructor with param" << endl;
	this->x = x;
	this->y = y;
	this->len = 5;
	this->orientareCoada = orientareCoada;
}
VaporDeRazboi::VaporDeRazboi(const VaporDeRazboi& a) {
	//cout << "copy constructor" << endl;
	this->x = a.x;
	this->y = a.y;
	this->len = a.len;
	this->orientareCoada = a.orientareCoada;
}
VaporDeRazboi::~VaporDeRazboi() {
	//cout << "Destructor";
	this->x = 0;
	this->y = 0;
	this->len = 0;
	this->orientareCoada = { '\0' };
}
VaporDeRazboi* VaporDeRazboi::clone() {
	VaporDeRazboi* newVaporDeRazboi = new VaporDeRazboi();
	newVaporDeRazboi->setX(this->x);
	newVaporDeRazboi->setY(this->y);
	newVaporDeRazboi->setLen(this->len);
	newVaporDeRazboi->setOrientareCoada(this->orientareCoada);
	return newVaporDeRazboi;
}
string VaporDeRazboi::toString() {
	string x, y, l, s;
	x = this->x;
	y = this->y;
	l = this->len;
	return  x + " " + y + " " + l + " " + this->orientareCoada;
}
int VaporDeRazboi::getX() {

	return this->x;
}
int VaporDeRazboi::getY() {

	return this->y;
}
int VaporDeRazboi::getLen() {
	return this->len;
}
string VaporDeRazboi::getOrientareCoada() {

	return this->orientareCoada;
}
void VaporDeRazboi::setX(int x) {

	this->x = x;
}
void VaporDeRazboi::setY(int y) {
	this->y = y;
}

void VaporDeRazboi::setLen(int len) {
	this->len = len;
}
void VaporDeRazboi::setOrientareCoada(string orientareCoada) {

	this->orientareCoada = orientareCoada;

}VaporDeRazboi& VaporDeRazboi::operator=(const VaporDeRazboi& a) {

	this->setX(a.x);
	this->setY(a.y);
	this->setLen(a.len);
	this->setOrientareCoada(a.orientareCoada);
	return *this;
}
bool VaporDeRazboi::operator==(const VaporDeRazboi& a) {

	return (this->x == a.x) && (this->y == a.y) && (this->orientareCoada.compare(a.orientareCoada) == 0);
}
ostream& operator<<(ostream& os, const VaporDeRazboi& a) {

	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y << "|" << " Orientare coada:" << a.orientareCoada;
	return os;
}