#include "Tests.h"
#include "assert.h"
#include<iostream>
#include<string.h>
#include <vector>
#include <list>
using namespace std;
Tests::Tests() {
}

void Tests::testDomainPhone() {
	vector<string> v;
	string c;
	c = "orange";
	v.push_back(c);
	Phone e1("pppp", "MS 74 SSC", 1, v);
	Phone e2(e1);
	Phone e3;
	Phone e4("eee eee 1 orange-cosmote",' ');
	assert(e4.getOperators()[0]== "orange");
	assert(e3.getProducer() == NULL);
	assert(e3.getModel() == NULL);
	assert(e3.getUnits() == 0);
	e3 = e2;
	assert(strcmp(e3.getProducer(), "pppp") == 0);
	assert(strcmp(e2.getProducer(), "pppp") == 0);
	assert(e1 == e2);
	e2.setModel("MS 74 AAA");
	assert(strcmp(e2.getModel(), "MS 74 AAA") == 0);
	cout << "super"<<endl;
}

void Tests::testDomainDrone() {
	Drone e1("pppp", "MS 74 SSC", 1, 1);
	Drone e2(e1);
	Drone e3;
	Drone e4("pp aa 1 1",' ');
	assert(e4.getRotors() == 1);
	assert(e3.getProducer() == NULL);
	assert(e3.getModel() == NULL);
	assert(e3.getUnits() == 0);
	e3 = e2;
	assert(strcmp(e3.getProducer(), "pppp") == 0);
	assert(strcmp(e2.getProducer(), "pppp") == 0);
	assert(e1 == e2);
	e2.setModel("MS 74 AAA");
	assert(strcmp(e2.getModel(), "MS 74 AAA") == 0);
}


void Tests::testRepoTemplate() {
	vector<string> v;
	string c;
	c ="orange";
	v.push_back(c);
	Serie *e1= new Phone("aaa", "MS 74 SSC", 1,v);
	Serie *e2=new Phone("bbb", "MS 75 SSC", 1,v);
	Serie *e3= new Phone("ccc", "MS 76 SSC", 1,v);
	Serie *e4= new Phone("ddd", "MS 77 SSC", 1,v);
	RepositoryTemplate<Serie*> rep;
	rep.addElem(e1);
	rep.addElem(e2);
	rep.addElem(e3);
	rep.addElem(e4);
	assert(rep.getSize() == 4);
	assert(*rep.getAll().front() == *e1);
	assert(*rep.getAll().back() == *e4);
	assert(*rep.getItemFromPos(0) == *e1);
	Serie *e0=new Phone("eee", "MS 77 SSA", 1,v);
	Serie *e01= new Phone("bbb", "aaa", 1,v);
	assert(rep.findElem(e4) == 3);
	assert(rep.findElem(e0) == -1);
	rep.deleteElem(e3);
	assert(rep.findElem(e3) == -1);
	assert(rep.getSize() == 3);
	Serie *e= new Phone("bbb", "aaa", 1,v);
	rep.updateElem(e1->clone(), e->clone());
	assert(*rep.getItemFromPos(0) == *e01);
}


void Tests::testRepoFileCSV() {
	SerializerSerie* s = new SerializerSerie();
	RepositoryFileCSV<Serie*> repof("Tests.csv", s);
	vector<string> v;
	string c;
	c = "orange";
	v.push_back(c);
	c = "cosmote";
	v.push_back(c);
	assert(repof.getSize() == 4);
	Serie* p = new Phone("aaa", "bbb", 1, v);
	repof.addElem(p);
	assert(repof.getSize() == 5);
	assert(repof.findElem(p) == 4);
	Serie* p1 = new Phone("abc", "aaa", 1, v);
	assert(repof.findElem(p1) == -1);
	repof.deleteElem(p);
	assert(repof.getSize() == 4);
	assert(repof.findElem(p) == -1);
	list<Serie*> rez = repof.getAll();
	assert(rez.size() == 4);
	Serie* p2 = new Phone("bbb", "aaa", 1, v);
	//	repof.updateElem(p2, p1);
	//	assert(repof.findElem(p1) == 0);
	//	assert(repof.getItemFromPos(0) == p1);
	assert(repof.getSize() == 4);
}

void Tests::testRepoFileHTML() {
	SerializerSerie* s = new SerializerSerie();
	RepositoryFileHTML<Serie*> repof("Tests.html", s);
	vector<string> v;
	string c;
	c = "orange";
	v.push_back(c);
	c = "cosmote";
	v.push_back(c);
	assert(repof.getSize() == 4);
	Serie* p = new Phone("aaa", "bbb", 1, v);
	repof.addElem(p);
	assert(repof.getSize() == 5);
	assert(repof.findElem(p) == 4);
	Serie* p1 = new Phone("abc", "aaa", 1, v);
	assert(repof.findElem(p1) == -1);
	repof.deleteElem(p);
	assert(repof.getSize() == 4);
	assert(repof.findElem(p) == -1);
	list<Serie*> rez = repof.getAll();
	assert(rez.size() == 4);
	Serie* p2 = new Phone("bbb", "aaa", 1, v);
	//	repof.updateElem(p2, p1);
	//	assert(repof.findElem(p1) == 0);
	//	assert(repof.getItemFromPos(0) == p1);
	assert(repof.getSize() == 4);
}
void Tests::testRepoFileSerie() {
	SerializerSerie* s = new SerializerSerie();
	RepositoryFile<Serie*> repof("Tests.txt", ' ', s);
	vector<string> v;
	string c;
	c = "orange";
	v.push_back(c);
	c = "cosmote";
	v.push_back(c);
	assert(repof.getSize() == 4);
	Serie* p = new Phone("aaa", "bbb", 1, v);
	repof.addElem(p);
	assert(repof.getSize() == 5);
	assert(repof.findElem(p) == 4);
	Serie* p1 = new Phone("abc", "aaa", 1, v);
	assert(repof.findElem(p1) == -1);
	repof.deleteElem(p);
	assert(repof.getSize() == 4);
	assert(repof.findElem(p) == -1);
	list<Serie*> rez = repof.getAll();
	assert(rez.size() == 4);
	
	/*Serie* p2 = new Phone("bbb", "aaa", 1, v);
	repof.updateElem(p2, p1);
	assert(repof.findElem(p1) == 0);
	assert(*repof.getItemFromPos(0) == *p1);*/
	assert(repof.getSize() == 4);
	Phone l("ioi", "ioi", 2, v);
	repof.addElem(l.clone());
	repof.deleteElem(l.clone());
}
Tests::~Tests() {}

void Tests::testService() {
	SerializerSerie* s = new SerializerSerie();
	SerializerUser* u = new SerializerUser();
	RepositoryFile<Serie*> repof("Tests.txt", ' ',s);
	RepositoryFile<User*> repo("Users.txt",' ',u);
	Service serv(repof, repo);
	User *u1=new User("ana", "1234");
	User *u2=new User("maria", "0000");
	User *u3= new User("cristina", "1414");
	repo.addElem(u1);
	assert(serv.login("cristina", "1414") == 0);
	assert(serv.login("ana", "1234") == 1);
	assert(serv.login("maria", "1234") == 0);
}
	//Phone e1("aaa", "MS 74 SSC", "free");
	//Phone e2("bbb", "MS 75 SSC", "occupied");
	//Phone e3("ccc", "MS 76 SSC", "free");
	//Phone e4("ddd", "MS 77 SSC", "free");
	//Phone e0("eee", "MS 77 SSA", "free");
	//Phone e01("bbb", "aaa", "free");
	//serv.addEntity(e1);
	//serv.addEntity(e2);
	//serv.addEntity(e3);
	//serv.addEntity(e4);
	//serv.addEntity(e0);
	//assert(serv.getSize() == 5);
	//assert(serv.getItemFromPos(0) == e1);
	//assert(serv.findElem(e2) == 1);
	//int n = serv.delEntity(e0);
	//assert(serv.findElem(e0) == -1);
//	//serv.updateEntity(e1, "aha", "aaa", "free");
//	//assert(strcmp(serv.getItemFromPos(0).getUnits(), "free") == 0);
