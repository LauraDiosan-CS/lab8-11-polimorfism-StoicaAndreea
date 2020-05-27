#pragma once
#include "Tabla.h"
#include "Vapor.h"
class Service {
private:
	Tabla* tabla;
	Tabla* bot;
public:
	Service(Tabla* t, Tabla* b) { tabla = t; bot = b; };
	~Service() {};
	vector<vector<char>> getTabla() { return tabla->getTabla(); };
	char getLovireFromPos(int x, int y) { return bot->getLovireFromPos(x, y); };
	char getItemFromPos(int x, int y) { return tabla->getItemFromPos(x, y); };
	char getItemFromPosBot(int x, int y) { return bot->getItemFromPos(x, y); };
	int addVapor(Vaporas& a) { int i = tabla->addVaporas(a); return i; };
	void addVaporBot(int);
	int addBomb(Bomba& b) { int i = bot->addBomb(b); return i; };
	void addBombBot();
	void newGame() { tabla->newGame(); bot->newGame(); };
	int endOfGame();
};