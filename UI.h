#pragma once
#include "Service.h"
class UI {
private:
	Service s;
public:
	UI(Service& serv) : s(serv) {};
	int logIn();
	void logOut();
	void addElem();
	void findElem();
	void showUI();
	void delElem();
	void showAll();
	~UI();
};