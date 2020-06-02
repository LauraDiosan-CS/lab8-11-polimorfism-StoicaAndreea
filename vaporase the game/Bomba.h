#pragma once
#include<string>
#include<iostream>
using namespace std;

class Bomba {
private:
	int x;
	int y;

public:
	Bomba();
	Bomba(int x, int y);
	Bomba(const Bomba& a);
	~Bomba();
	string toString();
	Bomba* clone();
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	Bomba& operator=(const Bomba& a);
	bool operator==(const Bomba&);
	friend ostream& operator<<(ostream& os, const Bomba& c);
};

