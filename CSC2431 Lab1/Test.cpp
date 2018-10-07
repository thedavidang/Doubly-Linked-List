//Test client for CSC 2431 Lab 1.
//DO NOT MODIFY

#include <iostream>
using namespace std;

#include "doublyLinkedList.h"

//prototypes
void print(doublyLinkedList list);

int main()
{
	doublyLinkedList first;

	//create a list with 4 elements for testing
	first.insertElement(20);
	first.insertElement(10);
	first.insertElement(50);
	first.insertElement(30);

	int pos;

	first.locateElement(50, pos);

	first.deleteElement(pos);

	cout << "first list:  " << endl;
	print(first);

	//create a copy of 3-element list
	doublyLinkedList second(first);

	cout << "\nsecond list (copy of first):  " << endl;
	print(second);

	//test delete
	second.deleteElement(1); //delete first element
	second.deleteElement(2); //delete last element
	second.deleteElement(1); //delete when only 1 element left

	cout << "\nsecond list (now empty):  " << endl;
	print(second);

	//test copy constructor
	doublyLinkedList third(first);

	//test == and !=
	cout << boolalpha;
	cout << "\ntesting == " << endl;
	cout << (first == first) << endl;
	cout << (first == second) << endl;
	cout << (first == third) << endl;

	cout << "\ntesting != " << endl;
	cout << (first != first) << endl;
	cout << (first != second) << endl;
	cout << (first != third) << endl;

	//test reverse
	first.reverse();

	cout << "\nprint first after reverse: " << endl;
	print(first);

	//testing printN with various arguments
	first.printN(0);
	first.printN(2);
	first.printN(4);
	first.printN(-1);

	return 0;
}


//Client function to print a list of listItemType
//Parameters: the list to print (posList)
//Returns: nothing
void print(doublyLinkedList list)
{
	for (int i = 1; i <= list.getLength(); i++)
	{
		listItemType x;
		list.retrieveElement(i, x);
		cout << x << endl;
	}
}



//#include <iostream>
//using namespace std;
//
//#include "doublyLinkedList.h"
//
////prototypes
//void print(doublyLinkedList list);
//
//int main()
//{
//	doublyLinkedList first;
//
//	first.insertElement(20);
//	first.insertElement(10);
//	first.insertElement(30);
//	first.insertElement(40);
//
//	int pos;
//	first.locateElement(10, pos);
//	cout << pos << endl;
//
//	first.locateElement(20, pos);
//	cout << pos << endl;
//
//	first.locateElement(30, pos);
//	cout << pos << endl;
//
//	first.locateElement(40, pos);
//	cout << pos << endl;
//
//	first.locateElement(50, pos);
//	cout << pos << endl;
//
//	first.insertElement(25);
//	first.locateElement(25, pos);
//	cout << pos << endl;
//
//	first.locateElement(30, pos);
//	cout << pos << endl;
//
//	cout << "first:  " << endl;
//	print(first);
//
//	cout << endl;
//
//	doublyLinkedList second(first);
//	second.deleteElement(3);
//	cout << "second:  " << endl;
//	print(second);
//	cout << endl;
//
//	doublyLinkedList third(first);
//
//	cout << boolalpha;
//	cout << "testing == " << endl;
//	cout << (first == first) << endl;
//	cout << (first == second) << endl;
//	cout << (first == third) << endl;
//	cout << endl;
//
//	cout << "testing != " << endl;
//	cout << (first != first) << endl;
//	cout << (first != second) << endl;
//	cout << (first != third) << endl;
//
//	return 0;
//}
//
//
////Client function to print a list of integers
////Parameters: the list to print (posList)
////Returns: nothing
//void print(doublyLinkedList list)
//{
//	for (int i = 1; i <= list.getLength(); i++)
//	{
//		listItemType x;
//		list.retrieveElement(i, x);
//		cout << x << endl;
//	}
//}