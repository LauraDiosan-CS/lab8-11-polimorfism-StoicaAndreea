#include<random>
#include<iostream>
#include"Service.h"
void Service::addVaporBot(int nr) {
	vector<string>s = { "nord","sud","est","vest" };
	vector<int>len = { 5,3,2 };
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 9);
	std::uniform_int_distribution<>dis(0, 3);
	std::uniform_int_distribution<>dist(0, 2);
	int i = 0;
	while(i<nr) {
		if (len[dist(eng)] == 5)
		{
			Vaporas* a = new VaporDeRazboi(distr(eng), distr(eng), s[dis(eng)]);
			int r = bot->addVaporas(a);
			if (r == -1) { nr++; }
			delete a;
			i++;
		}
		else
		{
			if (len[dist(eng)] == 3)
			{
				Vaporas* a = new Yacht(distr(eng), distr(eng), s[dis(eng)]);
				int r = bot->addVaporas(a);
				if (r == -1) { nr++; }
				delete a;
				i++;
			}
			else
				if (len[dist(eng)] == 2)
				{
					Vaporas* a = new Submarin(distr(eng), distr(eng), s[dis(eng)]);
					int r = bot->addVaporas(a);
					if (r == -1) { nr++; }
					delete a;
					i++;
				}
		}
	}
}

void Service::addBombBot() {
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, 9);
	int nr = 1;
	int i = 0;
	while (i < nr) {
		Bomba b(distr(eng), distr(eng));
		int r = tabla->addBomb(b);
		if (r == -1) { nr++; }
		i++;
	}
}
int Service::endOfGame() { 
	if (tabla->getSize() == 0) return 0;
	else if (bot->getSize() == 0) return 1;
	return -1;
}
//void Service::Game() {
//	newGame();
//	int e = endOfGame();
//	while (e == -1) {
//
//	}
//
//}