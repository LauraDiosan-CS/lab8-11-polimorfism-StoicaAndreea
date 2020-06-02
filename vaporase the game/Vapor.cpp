//#include"Vapor.h"
//
//Vaporas::Vaporas() {
//	//cout << "const implicit";
//	this->x = 0;
//	this->y = 0;
//	this->len = 0;
//	this->orientareCoada = { '\0' };
//
//}Vaporas::Vaporas(int x, int y, int len, string orientareCoada) {
//	//cout << "constructor with param" << endl;
//	this->x = x;
//	this->y = y;
//	this->len = len;
//	this->orientareCoada = orientareCoada;
//}
//Vaporas::Vaporas(const Vaporas& a) {
//	//cout << "copy constructor" << endl;
//	this->x = a.x;
//	this->y = a.y;
//	this->len = a.len;
//	this->orientareCoada = a.orientareCoada;
//}
//Vaporas::~Vaporas() {
//	//cout << "Destructor";
//	this->x = 0;
//	this->y = 0;
//	this->len = 0;
//	this->orientareCoada = { '\0' };
//}
//Vaporas* Vaporas::clone() {
//	Vaporas* newVaporas = new Vaporas();
//	newVaporas->setX(this->x);
//	newVaporas->setY(this->y);
//	newVaporas->setLen(this->len);
//	newVaporas->setOrientareCoada(this->orientareCoada);
//	return newVaporas;
//}
//string Vaporas::toString() {
//		string x, y,l, s;
//		x = this->x;
//		y = this->y;
//		l = this->len;
//		return  x + " " + y + " " + l + " " + this->orientareCoada;
//}
//int Vaporas::getX() {
//
//	return this->x;
//}
//int Vaporas::getY() {
//
//	return this->y;
//}
//int Vaporas::getLen() {
//	return this->len;
//}
//string Vaporas::getOrientareCoada() {
//
//	return this->orientareCoada;
//}
//void Vaporas::setX(int x) {
//
//	this->x = x;
//}
//void Vaporas::setY(int y) {
//	this->y = y;
//}
//
//void Vaporas::setLen(int len) {
//	this->len = len;
//}
//void Vaporas::setOrientareCoada(string orientareCoada) {
//
//	this->orientareCoada = orientareCoada;
//
//}Vaporas& Vaporas::operator=(const Vaporas& a) {
//
//	this->setX(a.x);
//	this->setY(a.y);
//	this->setLen(a.len);
//	this->setOrientareCoada(a.orientareCoada);
//	return *this;
//}
//bool Vaporas::operator==(const Vaporas& a) {
//
//	return (this->x == a.x) && (this->y == a.y) && (this->orientareCoada.compare(a.orientareCoada) == 0);
//}
//ostream& operator<<(ostream& os, const Vaporas& a) {
//
//	os << "Coordonata X: " << a.x << "|" << " Coordonata Y: " << a.y << "|" << " Orientare coada:" << a.orientareCoada;
//	return os;
//}