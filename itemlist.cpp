/*
 * Name: Van Hua
 * ItemList Member Function Definitions
 * Course: CSI218 (Spring 2020)
 * Date: May 14th, 2020
 * Description: ItemList member function definitions.
 */

#ifndef ITEMLIST_CPP
#define ITEMLIST_CPP

#include <iostream>
#include <algorithm>
#include "itemlist.h"
using namespace std;

// ItemList member function definitions.

// Constructors

// Default constructor.
template<class T>
ItemList<T>::ItemList()
{
	// Initially empty.
	firstP = NULL;
	lastP = NULL;
	currP = NULL;
}

// Copy constructor.
template<class T>
ItemList<T>::ItemList(const ItemList<T> &otherList)
{
	// Initially empty.
	firstP = NULL;
	lastP = NULL;
	currP = NULL;

	// Copy linked list from other list object.
	append(otherList);
}

// Destructor.
template<class T>
ItemList<T>::~ItemList()
{
	clear();  
}

// Assignment operator.
template<class T>
ItemList<T> &ItemList<T>::operator =(const ItemList<T> &otherList)
{
	// Avoid copying if assigning object to self.
	if (this != &otherList)
	{
		// Copy non-dynamic array members (none here).

		// Empty current list.
		clear();

		// Copy linked list from other list object.
		append(otherList);
	}

	// Return self.
	return *this;
}

// Accessors

// Get the value that is at current position (default value if none).
template<class T>
T ItemList<T>::getValue() const
{
	if (currP == NULL)
		return T();
	return currP->info;
}

// Mutators
template<class T>
void ItemList<T>::add(const T &val)
{
	//Allocate new node and store data.
	Node *newNodeP = new Node;
	newNodeP->info = val;
	newNodeP->nextP = NULL;

	//At at end.
	if (firstP == NULL)
	{
		firstP = newNodeP;
		newNodeP->prevP = NULL;
		currP = firstP;
	}
	else
	{
		newNodeP->prevP = lastP;
		lastP->nextP = newNodeP;
	}
	lastP = newNodeP;

}

//Moving the current node.
template<class T>
bool ItemList<T>::forward()
{
	if (currP->nextP != NULL)
	{
		//Move forward.
		currP = currP->nextP;
		return true;
	}

	else
		return false;

}

template<class T>
bool ItemList<T>::backward()
{

	if (currP->prevP != NULL)
	{
		//Move backward.
		currP = currP->prevP;
		return true;
	}
	else
		return false;

}
// Remove all values from list.
template<class T>
void ItemList<T>::clear()
{
	while (firstP != NULL)
	{
		Node *deleteP = firstP;
		firstP = firstP->nextP;
		delete deleteP;
	}

	// After loop, firstP will be NULL.
	// Also set reset other pointers.
	lastP = NULL;
	currP = NULL;
}

// Insert all items from other list in order.
template<class T>
void ItemList<T>::append(const ItemList<T> &otherList)
{
	for (Node *traverseP = otherList.firstP;
		traverseP != NULL;
		traverseP = traverseP->nextP)
		add(traverseP->info);
}

#endif