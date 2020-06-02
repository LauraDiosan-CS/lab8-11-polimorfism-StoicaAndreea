#pragma once
#include<string>
#include<iostream>
#include "Vapor.h"
using namespace std;

class Submarin: public Vaporas {
//private:
//	int x;
//	int y;
//	int len;
//	string orientareCoada;
public:
	Submarin();
	Submarin(int x, int y, string orientareCoada);
	Submarin(const Submarin& a);
	~Submarin();
	string toString();
	Submarin* clone();
	int getX();
	int getY();
	int getLen();
	string getOrientareCoada();
	void setX(int x);
	void setY(int y);
	void setLen(int len);
	void setOrientareCoada(string orientareCoada);
	Submarin& operator=(const Submarin& a);
	bool operator==(const Submarin&);
	friend ostream& operator<<(ostream& os, const Submarin& c);
};

