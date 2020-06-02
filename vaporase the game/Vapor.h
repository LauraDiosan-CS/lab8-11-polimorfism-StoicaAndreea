#pragma once
#include<string>
#include<iostream>
using namespace std;

class Vaporas {
protected:
	int x;
	int y;
	int len;
	string orientareCoada;
public:
	Vaporas() {};
	//Vaporas(int x, int y, int len, string orientareCoada);
	//Vaporas(const Vaporas& a);
	~Vaporas() {};
	virtual string toString()=0;
	virtual Vaporas* clone() = 0;
	virtual int getX() = 0;
	virtual int getY() = 0;
	virtual int getLen() = 0;
	virtual string getOrientareCoada() = 0;
	virtual void setX(int x) = 0;
	virtual void setY(int y) = 0;
	virtual void setLen(int len) = 0;
	virtual void setOrientareCoada(string orientareCoada) = 0;
	//Vaporas& operator=(const Vaporas& a);
	//bool operator==(const Vaporas&);
	//friend ostream& operator<<(ostream& os, const Vaporas& c);
};

