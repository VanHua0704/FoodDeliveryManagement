/*
 * Name: Van Hua
 * Final Project
 * Course: CSI218 (Spring 2020)
 * Date: May 14th, 2020
 * Description: Using class to represent breakfast odrders delivery management.
 * Requirements met:
 * 1. order class.
 * 2. itemlist template class.
 * 3. Storing oders in dynamic array and menu in doubly linked-list.
 * 4. Using priority-queue.
 * 5. Using pair container from STL.
 * 6. Using swap function from <algorithm> class.
 * 7. Using bubble sort and linear search. 
 */


#include <iostream>
#include <iomanip>  // for manipulators with arguments
#include <sstream>  // for stringstream
#include <algorithm> //for template function (swap).
#include <queue>  //STL queue class
#include "order.h"
using namespace std;

//Using linear search to find an order by its time.
//Function prototypes.
int findLinear(Order orders[],
	int numOrder,
	const int &hr);

//Using bubble sort to organize the order by time.
//Reference: https://www.geeksforgeeks.org/bubble-sort/
void bubbleSort(Order orders[], int numOrder);

int main()
{
	const int MIN_TIME = 6;
	const int MAX_TIME = 12;

	//Dynamic array to store orders.
	Order *orders;
	int numOrder;

	//Using  STL container to store menu. 
	ItemList<pair<double, string>> menu;
	pair<double, string> food;
	menu.add(make_pair(2.50, "Bagels"));
	menu.add(make_pair(3.50, "Muffin"));
	menu.add(make_pair(6.50, "Quiche"));
	menu.add(make_pair(8.50, "Enchiladas"));
	menu.add(make_pair(4.50, "Biscuits"));
	menu.add(make_pair(5.50, "Salad"));
	menu.add(make_pair(3.50, "Smoothie"));

	//Using priority queue to show the special dish.
	//Reference:https://www.geeksforgeeks.org/priority-queue-of-pairs-in-c-ordered-by-first/
	priority_queue<pair<double, string>, vector<pair<double, string>>, 
			less<pair<double, string>>> priorQueue;
	do 
	{
		priorQueue.push(menu.getValue());
	} while (menu.forward());

	cout << "*****Today's special food: " << priorQueue.top().second << ": $"
		<< priorQueue.top().first << "*****" << endl << endl;

	//Back to the beginning
	while (menu.backward());

	//Output menu.
	cout << "---------------Today's Menu---------------" << endl << endl;
	
	do
	{
		food = menu.getValue();
		cout << food.second << ": " << "$" << food.first << endl << endl;
	} while (menu.forward());

	//Back to the beginning.
	while (menu.backward());

	//Store customer data.
	cout << "How many customer order for tomorrow morning? ";
	cin >> numOrder;
	cin.get(); //eat newline.

	//Allocate dynamic array.
	orders = new Order[numOrder];
	//Store customer data and compute the bill.
	int count = numOrder;
	int i = 0;
	while (count != 0)
	{
		int orderNo;
		string customerName;
		string customerAddr;
		string phoneNo;
		int timeDelivered;
		string item;
		double amountPay;
		double cost;
		string membership;
		bool hasDiscount = false;

		orderNo = i + 1;
		cout << endl;
		cout << "Name: ";
		getline(cin, customerName);

		cout << "Address: ";
		getline(cin,customerAddr);

		do
		{
			cout << "Time to recieve the order (Available time are 6h, 7h, 8h, 9h, 10h, 11h and 12h): ";
			cin >> timeDelivered;
			cin.get();
		} while (timeDelivered < MIN_TIME || timeDelivered > MAX_TIME);
		
		cout << "Telephone number: ";
		cin >> phoneNo;
		cin.ignore();

		cout << "What does she/he order? ";
		cin >> item;
		cin.ignore();

		cout << "Does she/he have membership of our store? (y/n): ";
		cin >> membership;
		cin.ignore();
		if ((tolower(membership[0]) == 'y'))
			hasDiscount = true;
	
		//Find the cost of picked item.
		do
		{
			food = menu.getValue();
			if (food.second == item)
				break;	
		} while (menu.forward());
		
		cost = food.first;

		//Return to the beginning.
		while (menu.backward());

		//Compute the total price.
		amountPay = orders[i].totalPay(cost, hasDiscount);

		orders[i].set(orderNo, customerName, customerAddr, phoneNo, 
					timeDelivered, item, amountPay, hasDiscount);
		i++;
		count--;
	}

	//Output orders.
	for (int i = 0; i < numOrder; i++)
	{
		orders[i].output();
		cout << endl << endl;
	}

	bubbleSort(orders, numOrder);
	cout << "Sort orders by its time: " << endl;
	for (int i = 0; i < numOrder; i++)
	{
		orders[i].output();
		cout << endl << endl;
	}
	//Using linear search to find an order by its time.
	int timing;

	do
	{
		cout << "\nFind order by its time ";
		cin >>timing; 
		cin.get();

		if (timing < MIN_TIME || timing > MAX_TIME)
			cout << "Unavailable time." << endl;

		
		int index = findLinear(orders, numOrder, timing);

		if (index == -1)
			cout << "No order at \"" << timing << "h\"" << endl;
		else
		{
			cout << "Found order:" << endl;
			orders[index].output();
			cout << endl << endl;
		}
	} while (true);




	// Deallocate.
	delete[] orders;
	orders = NULL;  // avoid dangling ptr
	numOrder = 0;	// reset variable


	return 0;
}

//Function definition.
//Using linear search to find an order by its time.
int findLinear(Order orders[],
	int numOrder,
	const int &hr)
{
	for (int i = 0; i < numOrder; i++)
		if (orders[i].getTimeRecieved() == hr)
			return i;
	return -1;
}

//Using bubble sort to organize the order by time.
void bubbleSort(Order orders[], int numOrder)
{
	int i, j;
	for(i = 0; i < numOrder - 1; i++)
		for (j = 0; j < numOrder - i - 1; j++)
		{
			if (orders[j] > orders[j + 1])
				swap(orders[j], orders[j + 1]);
		}
}