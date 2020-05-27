#pragma once
#include<string>
#include<iostream>
using namespace std;

class Vaporas {
private:
	int x;
	int y;
	int len;
	string orientareCoada;
public:
	Vaporas();
	Vaporas(int x, int y, int len, string orientareCoada);
	Vaporas(const Vaporas& a);
	~Vaporas();
	int getX();
	int getY();
	int getLen();
	string getOrientareCoada();
	void setX(int x);
	void setY(int y);
	void setLen(int len);
	void setOrientareCoada(string orientareCoada);
	Vaporas& operator=(const Vaporas& a);
	bool operator==(const Vaporas&);
	friend ostream& operator<<(ostream& os, const Vaporas& c);
};

