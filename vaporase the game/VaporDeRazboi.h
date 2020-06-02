#pragma once
#include "Vapor.h"
#include<string>
#include<iostream>
using namespace std;

class VaporDeRazboi: public Vaporas {
//private:
//	int x;
//	int y;
//	int len;
//	string orientareCoada;
public:
	VaporDeRazboi();
	VaporDeRazboi(int x, int y, string orientareCoada);
	VaporDeRazboi(const VaporDeRazboi& a);
	~VaporDeRazboi();
	string toString();
	VaporDeRazboi* clone();
	int getX();
	int getY();
	int getLen();
	string getOrientareCoada();
	void setX(int x);
	void setY(int y);
	void setLen(int len);
	void setOrientareCoada(string orientareCoada);
	VaporDeRazboi& operator=(const VaporDeRazboi& a);
	bool operator==(const VaporDeRazboi&);
	friend ostream& operator<<(ostream& os, const VaporDeRazboi& c);
};

