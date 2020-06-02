#pragma once
#include<vector>
#include "Vapor.h"
#include"Bomba.h"
using namespace std;
#include"RepositoryPointers.h"


class Tabla {

private:
	vector<vector<char> > mat;
	vector<vector<char>> bmat;
	RepositoryPointers<Vaporas*>* repo;
	//RepositoryPointers<Bomba*>* bomb;
public:
	Tabla(RepositoryPointers<Vaporas*>* rep /*,RepositoryPointers<Bomba*>* b*/) :repo(rep)/*, bomb(b)*/ {
		repo = rep;
		//bomb = b;
		vector < vector<char> > Matr(10, vector<char>(10));
		mat = Matr;
		bmat = Matr;
		/*for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				mat[i][j] = '0';
			}
		}*/
	};
	int getSize() { return repo->getSize(); }
	~Tabla() {};

	vector < vector<char> >getTabla() {
		return this->mat;
	};
	vector < vector<char> >getLoviri() {
		return this->bmat;
	};

	char getItemFromPos(int x, int y) {
		return mat[x][y];
	};
	char getLovireFromPos(int x, int y) {
		return bmat[x][y];
	};
	void newGame() {
		repo->clearElem();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				mat[i][j] = ' ';
				bmat[i][j] = ' ';
			}
		}
	}
	int addBomb(Bomba& b) {
		if ((b.getX() >= 0) && (b.getX() < 10) && (b.getY() >= 0) && (b.getY() < 10)) {
			if (mat[b.getY()][b.getX()] == '@') {
				Vaporas* a= (repo->getItemFromPoint(b.getX(), b.getY()));
				mat[b.getY()][b.getX()] = 'd';
				bmat[b.getY()][b.getX()] = 'd';
				repo->deleteElem(a);
				delete a;
			}
			else if (mat[b.getY()][b.getX()] == '#') { mat[b.getY()][b.getX()] = 'h'; bmat[b.getY()][b.getX()] = 'h'; }
			else { mat[b.getY()][b.getX()] = 'a'; bmat[b.getY()][b.getX()] = 'a'; }
			return 0;
		}
		return -1;
	};

	int addVaporas(Vaporas *a)
	{
		vector < vector<char> >m = mat;
		if (a->getOrientareCoada() == "nord")
		{
			if ((a->getX() >= 0) && (a->getY() >= 0) && (a->getY() + a->getLen() <= 10))
			{
				for (int i = a->getY(); i < (a->getY() + a->getLen()); i++) {
					if (m[i][a->getX()] == '#') { return -1; }
					m[i][a->getX()] = '#';

				}
				m[a->getY()][a->getX()] = '@';
				mat = m;
				repo->addElem(a);
			}
			else { return-2; }
		}
		else
			if (a->getOrientareCoada() == "vest") {
				if ((a->getX() >= 0) && (a->getX() + a->getLen() - 1 < 10) && (a->getY() >= 0)) {
					for (int i = a->getX(); i < (a->getX() + a->getLen()); i++) {
						if (m[a->getY()][i] == '#') { return -1; }
						m[a->getY()][i] = '#';
					}
					m[a->getY()][a->getX()] = '@';
					mat = m;
					repo->addElem(a);
				}
				else { return-1; }
			}
			else
				if (a->getOrientareCoada() == "est") {
					if ((a->getX() <10) && (a->getX() - a->getLen() + 1 >= 0) && (a->getY() < 10)) {
						for (int i = a->getX() - a->getLen() + 1; i <= a->getX(); i++) {
							if (m[a->getY()][i] == '#') { return -1; }
							m[a->getY()][i] = '#';
						}
						m[a->getY()][a->getX()] = '@';
						mat = m;
						repo->addElem(a);
					}
					else { return-2; }
				}
				else
					if (a->getOrientareCoada() == "sud")
					{
						if ((a->getX() < 10) && (a->getY() - a->getLen() + 1 >= 0) && (a->getY() <= 10))
						{
							//mat[a->getY()][a->getX()] = '@';
							for (int i = a->getY() - a->getLen() + 1; i <= a->getY(); i++) {
								if (m[i][a->getX()] == '#') { return -1; }
								m[i][a->getX()] = '#';
							}
							m[a->getY()][a->getX()] = '@';
							mat = m;
							repo->addElem(a);
						}
						else { return -2; }
					}
					else { return -3; }
		return 0;
	};

};