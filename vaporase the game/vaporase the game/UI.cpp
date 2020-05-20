using namespace std;
#include"UI.h"
#include <iostream>
#include <windows.h>
void changeColor(int desiredColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), desiredColor);
}
void UI::showUI() {
	bool gata = false;
	bool stop = false;
	while (!gata) {
		cout << endl;
		cout << "#####################~~ MENU ~~###############";
		cout << endl;
		cout << "OPTIONS: " << endl;
		cout << "	1. Add " << endl;
		cout << "	5. Show " << endl;
		cout << "option: (give the number):  ";
		int opt;
		cin >> opt;
		cout << endl;
		cout << endl;
		switch (opt) {
		case 1: {addEl(); break; }
		case 5: {showTabla(); /*showTablaBot();*/ break; }
		case 0: {gata = true; cout << "BYE BYE..." << endl; }
		}
	}
}

int UI::transform(char c) {
	switch (c) {
	case 'A': {return 1; }
	case 'B': {return 2; }
	case 'C': {return 3; }
	case 'D': {return 4; }
	case 'E': {return 5; }
	case 'F': {return 6; }
	case 'G': {return 7; }
	case 'H': {return 8; }
	case 'I': {return 9; }
	case 'J': {return 10; }
	case 'a': {return 1; }
	case 'b': {return 2; }
	case 'c': {return 3; }
	case 'd': {return 4; }
	case 'e': {return 5; }
	case 'f': {return 6; }
	case 'g': {return 7; }
	case 'h': {return 8; }
	case 'i': {return 9; }
	case 'j': {return 10; }

	}
}
void UI::showTabla() {
	//system("Color 1");
	changeColor(12);
	int x = 1;
	char y = 'A';
	cout << "   ! ";
	for (int j = 0; j < 10; j++) {
		cout << y << " ! ";
		y += 1;
	}
	cout << endl;
	cout << "============================================" << endl;
	for (int i = 0; i < 10; i++) {
		changeColor(12);
		if (x == 10) cout << x << " ! ";
		else cout << " " << x << " ! ";
		x++;
		changeColor(3);
		for (int j = 0; j < 10; j++) {
			changeColor(7);
			cout << s.getItemFromPos(i, j);
			changeColor(3);
			cout << " | ";
		}
		cout << endl;
		changeColor(12);
		cout << "====";
		changeColor(3);
		cout << "========================================" << endl;
	}
	cout << endl;
	cout << endl;
	changeColor(7);
}


void UI::showTablaBot() {
	//system("Color 1");
	changeColor(12);
	int x = 1;
	char y = 'A';
	cout << "   ! ";
	for (int j = 0; j < 10; j++) {
		cout << y << " ! ";
		y += 1;
	}
	cout << endl;
	cout << "============================================" << endl;
	for (int i = 0; i < 10; i++) {
		changeColor(12);
		if (x == 10) cout << x << " ! ";
		else cout << " " << x << " ! ";
		x++;
		changeColor(3);
		for (int j = 0; j < 10; j++) {
			changeColor(7);
			cout << s.getItemFromPosBot(i, j);
			changeColor(3);
			cout << " | ";
		}
		cout << endl;
		changeColor(12);
		cout << "====";
		changeColor(3);
		cout << "========================================" << endl;
	}
	changeColor(7);
}
void UI::addEl() {
	char x;
	char r;
	int y;
	int l;
	string o;
	cout << "column: ";
	cin >> x;
	cout << "line: ";
	cin >> y;
	cout << "length: ";
	//cin >> l;
	cout << "ce ati dori?    a. Vas de razboi|  b. Yacht| c.Submarin: ";
	cin >> r;
	switch (r) {
	case'a': {l = 5; break; }
		case 'b': {l=3; break; }
		case 'c': {l=2; break; }
	default:
		l = 2;
		break;
	}
	cout << "orientation: ";
	cin >> o;
	int xx = transform(x);
	Vapor a(xx - 1, y - 1,l, o);
	s.addVapor(a);
}