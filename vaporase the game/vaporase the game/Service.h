#pragma once
#include "Tabla.h"

class Service {
private:
	Tabla* tabla;
	Tabla* bot;
public:
	Service(Tabla* t, Tabla* b) { tabla = t; bot = b; };
	~Service() {};
	vector<vector<char>> getTabla() { return tabla->getTabla(); };
	char getItemFromPos(int x, int y) { return tabla->getItemFromPos(x, y); };
	char getItemFromPosBot(int x, int y) { return bot->getItemFromPos(x, y); };
	void addVapor(Vapor& a) { tabla->addElem(a); };
	void addVaporBot(Vapor& a) { bot->addElem(a); };
};