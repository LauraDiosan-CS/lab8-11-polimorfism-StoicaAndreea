#pragma once
#include<iterator>
#include <list>
#include <algorithm>
#include <iostream>
using namespace std;

template <class T>class RepositoryPointers {
protected:
	list<T> elem;
public:
	RepositoryPointers<T>() {}
	virtual int addElem(T);
	virtual int deleteElem(T);
	T getItemFromPoint(int, int);
	int findElem(T);
	int getSize();
	virtual void updateElem(T s, T nou);
	list<T> getAll();
	T getItemFromPos(int);
	void clearElem();
	~RepositoryPointers();
};





template<class T>
int RepositoryPointers<T>::addElem(T e)
{
	/*typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it == elem.end())
	{
		elem.push_back(e);
		return 0;
	}
	return -1;*/

	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == e->toString())
		{
			return -1;
		}
	}
	elem.push_back(e->clone());
	return 0;
}

template<class T>
int RepositoryPointers<T>::deleteElem(T e)
{
	/*typename list<T>::iterator it;
	it = find(elem.begin(), elem.end(), e);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	return -1;*/
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		if ((*it)->toString() == e->toString())
		{
			elem.erase(it);
			return 0;
		}
	}
	return -1;
}

template<class T>
int RepositoryPointers<T>::findElem(T e)
{
	typename list<T>::iterator it;
	int i = 0;
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		//if(*it ==e)
		if ((*it)->toString() == e->toString())
		{
			return i;
		}
		i++;
	}
	return -1;
}

template<class T>
int RepositoryPointers<T>::getSize()
{
	return elem.size();
	return 0;
}

template<class T>
void RepositoryPointers<T>::updateElem(T vechi, T nou)
{
	//replace(elem.begin(), elem.end(), vechi, nou);
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); ++it)
	{

		if ((*it)->toString() == vechi->toString())
		{
			*it = nou->clone();
		}
	}

}

template<class T>
list<T> RepositoryPointers<T>::getAll()
{
	return elem;
	return list<T>();
}

template<class T>
T RepositoryPointers<T>::getItemFromPos(int i) {
	typename list<T>::iterator it;
	int k = 0;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if (k == i)
			return *it;
		k++;

	}
}

template<class T>
T RepositoryPointers<T>::getItemFromPoint(int x, int y) {
	typename list<T>::iterator it;
	for (it = elem.begin(); it != elem.end(); it++)
	{
		if ((**it).getX() == x && (**it).getY() == y)
			return *it;

	}
}
template<class T> void RepositoryPointers<T>::clearElem() {
	elem.clear();
}
template <class T> RepositoryPointers<T>::~RepositoryPointers()
{
}
