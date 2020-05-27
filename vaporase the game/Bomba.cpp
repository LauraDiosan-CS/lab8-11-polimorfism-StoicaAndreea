#include"Bomba.h"

Bomba::Bomba() {
	//cout << "const implicit";
	this->x = 0;
	this->y = 0;


}Bomba::Bomba(int x, int y) {
	//cout << "constructor with param" << endl;
	this->x = x;
	this->y = y;

}
Bomba::Bomba(const Bomba& a) {
	//cout << "copy constructor" << endl;
	this->x = a.x;
	this->y = a.y;
}
Bomba::~Bomba() {
	//cout << "Destructor";
	this->x = 0;
	this->y = 0;
}
int Bomba::getX() {

	return this->x;
}
int Bomba::getY() {

	return this->y;
}

void Bomba::setX(int x) {

	this->x = x;
}
void Bomba::setY(int y) {
	this->y = y;
}

Bomba& Bomba::operator=(const Bomba& a) {

	this->setX(a.x);
	this->setY(a.y);
	return *this;
}
bool Bomba::operator==(const Bomba& a) {

	return (this->x == a.x) && (this->y == a.y);
}
ostream& operator<<(ostream& os, const Bomba& a) {

	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y;
	return os;
}