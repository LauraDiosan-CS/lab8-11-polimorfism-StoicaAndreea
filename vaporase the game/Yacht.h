#pragma once
#include<string>
#include<iostream>
#include "Vapor.h"
using namespace std;

class Yacht: public Vaporas {
//private:
//	int x;
//	int y;
//	int len;
//	string orientareCoada;
public:
	Yacht();
	Yacht(int x, int y, string orientareCoada);
	Yacht(const Yacht& a);
	~Yacht();
	string toString();
	Yacht* clone();
	int getX();
	int getY();
	int getLen();
	string getOrientareCoada();
	void setX(int x);
	void setY(int y);
	void setLen(int len);
	void setOrientareCoada(string orientareCoada);
	Yacht& operator=(const Yacht& a);
	bool operator==(const Yacht&);
	friend ostream& operator<<(ostream& os, const Yacht& c);
};

