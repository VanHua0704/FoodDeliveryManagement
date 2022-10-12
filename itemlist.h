/*
 * Name: Van Hua
 * ItemList Class Definition
 * Course: CSI218 (Spring 2020)
 * Date: May 14th, 2020
 * Description: ItemList template class definition declaring
 *				data members and member functions for type "T".
 */

#ifndef ITEMLIST_H
#define ITEMLIST_H

 // ItemList template class definition with data members and
 // prototypes for member functions.
template<class T>
class ItemList
{
public:
	// Default constructor.
	ItemList(); 

	// Copy constructor.
	ItemList(const ItemList<T> &otherList);

	// Assignment operator.
	ItemList<T> &operator =(const ItemList<T> &otherList);

	// Destructor.
	~ItemList();

	// Accessors

	// Get the value that is at current position (default value if none).
	T getValue() const;

	// Mutators
	void add(const T &val);

	//Moving the current node.
	bool forward();

	bool backward();

	// Remove all values from list.
	void clear();

private:
	struct Node
	{
		T info;
		Node *prevP;
		Node *nextP;
	};
	Node *firstP;	// pointer to first node
	Node *lastP;	// pointer to last node
	Node *currP;	// pointer to "current" node (can be moved forward/backward)

	// Insert all items from other list in order.
	void append(const ItemList<T> &otherList);
};

#endif