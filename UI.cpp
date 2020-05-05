#include "UI.h"
#include <iostream>
#include<string.h>
using namespace std;

void UI::addElem() {
	cout << "what yould you like to add? :"<<endl;
	cout << "	a. Phone" << endl;
	cout << "	b.Drone" << endl;
	try {
	string ras = "";
	cin >> ras;
	Serie* ser;
	if (ras == "a") {
		try {
			Phone p;
			cin >> p;
			s.validatePhone(p);
			ser = p.clone();
			s.addElem(ser);
		}
		catch (PhoneException e)
		{
			for (int i = 0; i < e.getErrors().size(); i++)
				cout << e.getErrors()[i];
		}
	}
	else {
		try {
			Drone p;
			cin >> p;
			ser = p.clone();
			s.addElem(ser);
		}
		catch (SerieException e) {
			for (int i = 0; i < e.getErrors().size(); i++)
				cout << e.getErrors()[i];
		}
	}

		//cout << "the seria has been successfully added" << endl;
	}
	catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}



//void UI::findProj() {
//	Car proj;
//	cout << "Give the Car:";
//	cin >> proj;
//	int rez = s.findElem(proj);
//	if (rez >= 0) cout << "The Car has been found!" << endl;
//	else cout << "The Car has not been found!" << endl;
//}

void UI::delElem() {
	cout << "what yould you like to delete? :" << endl;
	cout << "	a. Phone" << endl;
	cout << "	b.Drone" << endl;
	try {
		string ras = "";
		cin >> ras;
		Serie* ser;
		if (ras == "a") {
			Phone p;
			cin >> p;
			ser = p.clone();
		}
		else {
			Drone p;
			cin >> p;
			ser = p.clone();
		}
		s.deleteElem(ser);
		cout << "the seria has been successfully deleted" << endl;
	}
	catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
}
//	Car proj;
//	cout << "Give the Car:" << endl;;
//	cin >> proj;
//	try {
//		int rez = s.delCar(proj);
//		if (rez == 0) cout << "the Car has been deleted!" << endl;
//	}
//	catch (exception e) { cout << "exception occuredddd!" << "->"; cout << e.what(); }
//}


int UI::logIn() {
	cout << "Username: ";
	string user;
	cin >> user;
	cout << "Password: ";
	string pass;
	cin >> pass;
	return s.login(user, pass);
}

void UI::logOut() {
	s.logout();
}

void UI::showAll() {
	list <Serie*>::iterator it;
	for (int i = 0; i < s.getSize(); i++)
	{
		cout << (*s.getItemFromPos(i)).toString() << endl;
	}
}

//void UI::updateProj() {
//	Car proj;
//	cout << "Give the Car you want to update:";
//	cin >> proj;
//	cout << "Give the Car data:" << endl;
//	char* na = new char[10];
//	char* nr = new char[10];
//	char* st = new char[10];
//	int rez = s.findElem(proj);
//	if (rez >= 0) {
//		cout << "name: ";
//		cin >> na;
//		cout << "plate number: ";
//		cin >> nr;
//		int ok = 0;
//		while (ok == 0) {
//			cout << "status: " << endl;
//			cout << "			a. free" << endl;
//			cout << "			b.occupied" << endl;
//			cin >> st;
//			if ((strcmp(st, "free") == 0) or (strcmp(st, "occupied") == 0)) ok = 1;
//		}
//		s.updateCar(proj, na, nr, st);
//		cout << "The Car has been updated!";
//	}
//	else { cout << "The Car has not been found!"; }
//	delete[] na;
//	delete[] nr;
//	delete[] st;
//}

void UI::showUI()
{
	bool gata = false;
	bool stop = false;
	while (!gata) {
		cout << "would you like to log on? " << endl;
		cout << "		a.yes" << endl;
		cout << "		b.no" << endl;
		char r;
		cin >> r;
		if (r == 'a') {
			if (logIn()) {
				/*cout << "what format would you like? " << endl;
				cout << "		a. csv" << endl;
				cout << "		b.html" << endl;
				cin>> r;
				if (r == 'a') { s.loadFromFile("Tests.csv",','); }
				else { s.loadFromFile("Tests.html", '/'); }*/

				while (s.logedIn() and !gata) {
					cout << endl;
					cout << "#####################~~ MENU ~~###################" << endl;
					cout << endl;
					cout << "OPTIONS: " << endl;
					cout << "	1. Add " << endl;
					//cout << "	2. Search Car " << endl;
					cout << "	3. Delete Car " << endl;
					//cout << "	4. Update Car " << endl;
					cout << "	5. Show " << endl;
					cout << "	6. Log out" << endl;
					cout << "	0. EXIT!" << endl;
					cout << "option: (give the number):  ";
					int opt;
					cin >> opt;
					cout << endl;
					cout << endl;
					switch (opt) {
						case 1: {addElem(); break; }
						//case 2: {findProj(); break; }
						case 3: {delElem(); break; }
						//case 4: {updateProj(); break; }
					case 5: {showAll(); break; }
					case 6: {logOut(); cout << "you have been logged outtttt" << endl; break; }
					case 0: {gata = true; cout << "BYE BYE..." << endl; }
					}
				}
			} else{ cout << "incorrect username or password" << endl; }
		}
			else {
				/*cout << "would you like to try again? " << endl;
				cout << "		a. yes " << endl;
				cout << "		b.no" << endl;*/
				//string rasp;
				//cin >> rasp;
				if (r == 'b') gata = true;
			}
		}
	}

UI::~UI()
{

}
