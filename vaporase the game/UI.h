#pragma once
#include"Service.h"
#include "Vapor.h"
#include "VaporDeRazboi.h"
#include "Yacht.h"
#include "Submarin.h"
class UI {
private:
	Service s;
public:
	UI(Service& serv) :s(serv) {};
	void showUI();
	void showTabla();
	void showTablaBot();
	void showTablaLovire();
	void addVapor();
	void addBomba();
	void game();
	int transform(char);
	~UI() {};
};