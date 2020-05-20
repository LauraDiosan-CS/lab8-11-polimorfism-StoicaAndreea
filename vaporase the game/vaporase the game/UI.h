#pragma once
#include"Service.h"

class UI {
private:
	Service s;
public:
	UI(Service& serv) :s(serv) {};
	void showUI();
	void showTabla();
	void showTablaBot();
	void addEl();
	int transform(char);
	~UI() {};
};