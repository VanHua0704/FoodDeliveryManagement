/*
 * Name: Van Hua
 * Order Class Definition
 * Course: CSI218 (Spring 2020)
 * Date: May 14th, 2020
 * Description: Order class definition declaring
 *				data members and member functions.
 */

#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "itemlist.cpp"
using namespace std;

// Order class definition with data members and
// prototypes for member functions.

class Order
{
public:
	// Constructors
	Order();  // default constructor
	Order(const int &newOrderNum,
		string newName,
		string newAddress,
		string newPhoneNum,
		int newTimeRecieved,
		string newItemOrdered,
		double price,
		bool newDiscount);

	// Accessors

	int getTimeRecieved() const;

	void output() const;

	double totalPay(double price, bool discount) const;
	

	// Mutators
	void set(const int &newOrderNum,
		string newName,
		string newAddress,
		string newPhoneNum,
		int newTimeRecieved,
		string newItemOrdered,
		double newPrice,
		bool newDiscount);
	
	void setPrice(double newPrice);


private:
	int orderNum;
	string name;
	string address;
	string phoneNum;
	int timeRecieved;
	string itemOrdered;
	double price;
	bool discount;
};

//Overloaded operator to compare each order.
bool operator >(const Order &order1,
	const Order &order2);


#endif
