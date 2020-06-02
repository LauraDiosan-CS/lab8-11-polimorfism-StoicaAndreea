// avioane the game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Tabla.h"
#include"Service.h"
#include "Vapor.h"
#include "VaporDeRazboi.h"
#include "Yacht.h"
#include "Submarin.h"
#include"UI.h"
#include "RepositoryPointers.h"
int main()
{
    std::cout << "Hello World!\n";
    RepositoryPointers<Vaporas*>* rp = new RepositoryPointers<Vaporas*>();
    RepositoryPointers<Vaporas*>* rc = new RepositoryPointers<Vaporas*>();
    RepositoryPointers<Bomba*>* rb = new RepositoryPointers<Bomba*>();
    Tabla* t = new Tabla(rp/*,rb*/);
    Tabla* b = new Tabla(rc/*,rb*/);
    Service s(t, b);
    UI ui(s);
    ui.showUI();
    delete t;
    delete b;
    delete rp;
    delete rc;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
