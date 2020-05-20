#pragma once
#include<vector>
#include "Vapor.h"
using namespace std;


class Tabla {
private:
	vector<vector<char> > mat;
public:
	Tabla() {
		vector < vector<char> > Matr(10, vector<char>(10));
		mat = Matr;
		/*for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				mat[i][j] = '0';
			}
		}*/
	};

	~Tabla() {};

	vector < vector<char> >getTabla() {
		return this->mat;
	};

	char getItemFromPos(int x, int y) {
		return mat[x][y];
	};
	void addElem(Vapor& a)
	{
		if (a.getOrientareCoada() == "nord")
		{
			if ((a.getX() >= 0) /*&& (a.getX() + a.getLen() <= 10) */ && (a.getY() >= 0) && (a.getY() + a.getLen() <= 10))
			{
				//mat[a.getY()][a.getX()] = '@';
				for (int i = a.getY(); i < a.getLen() ; i++) {
					mat[i][a.getX()] = '#';
				}

			}
		}
		if (a.getOrientareCoada() == "vest") {
			if ((a.getX() >= 0) && (a.getX() + a.getLen() <= 10) && (a.getY() >= 0) /*&& (a.getY() + 2 <= 10)*/) {
				for (int i = a.getX(); i < a.getLen(); i++) {
					mat[a.getY()][i] = '#';
				}
			}
		}
		if (a.getOrientareCoada() == "est") {
			if ((a.getX() <= 10) && (a.getX() - a.getLen() + 1 >= 0) /*&& (a.getY() - 2 >= 0)*/ && (a.getY() <= 10)) {
				for (int i = a.getX() - a.getLen() + 1; i <= a.getX(); i++) {
					mat[a.getY()][i] = '#';
				}
			}
		}
		if (a.getOrientareCoada() == "sud")
		{
			if (/*(a.getX() - a.getLen() >= 0) &&*/ (a.getX() <= 10) && (a.getY()-a.getLen() >= 0) && (a.getY() <= 10))
			{
				//mat[a.getY()][a.getX()] = '@';
				for (int i = a.getY() - a.getLen() + 1; i <= a.getY(); i++) {
					mat[i][a.getX()] = '#';
				}

			}
		}
	};
};