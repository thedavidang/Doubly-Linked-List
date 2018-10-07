// David Ang
// 9-28-2018
// CSC2431
// Lab 1

//Create a sorted doubly linked list with the base code of a sorted linked list edited to make a doubly linked list
//the list can be added or deleted as well a pinpoint a certain value within the list
//methods of reverse and printN are added to reverse the list and print out the elements

// Implementation file for sortedList, a pointer-based by-position list of type
// specified in header.

#include "doublyLinkedList.h"     // header file
#include <cstddef>		// for NULL
#include <cassert>     // for assert()
#include <iostream>   // for cout and endl


doublyLinkedList::doublyLinkedList()	// Default Constructor
	: size(0), head(NULL), tail(NULL)
{
}


doublyLinkedList::~doublyLinkedList()	// Destructor
{
	bool success;

	while (!isEmpty())
	{
		success = deleteElement(1);  // Repeatedly delete item 1
	}
}


bool doublyLinkedList::isEmpty() const
{
	return (size == 0);
}


int doublyLinkedList::getLength() const
{
	return size;
}


// Copy Constructor
doublyLinkedList::doublyLinkedList(const doublyLinkedList& original)
	: size(original.size)
{
	if (original.head == NULL)
	{
		head = NULL;  // original list is empty
		
	}
	else if (original.tail == NULL) //is list empty?
	{
		tail = NULL;
	}

	else
	{
		// copy first node
		head = new listNode;
		
		assert(head != NULL);  // check allocation

		head->item = original.head->item;

		

		// copy rest of list
		listNode *newPtr = head;  // new list pointer
							
		tail = head; //For the first node, the tail and head are the same

								  // newPtr points to last node in new list 
								  // origPtr points to nodes in original list

		for (listNode *origPtr = original.head->next; origPtr != NULL; origPtr = origPtr->next)
		{
		
				newPtr->next = new listNode;
				assert(newPtr->next != NULL);

				newPtr->next->prev = newPtr; //makes it a doubled linked list (points back)

				newPtr = newPtr->next;

				newPtr->item = origPtr->item;
			
		}

		tail = newPtr; //set tail to the very end
		newPtr->next = NULL;
		
	}

}


// Locates a specified node in a linked list
// Parameters: the number of the desired node (starting at 1, an int)
// Returns: Returns a pointer to the desired node, or NULL if position out of range.
doublyLinkedList::listNode *doublyLinkedList::ptrTo(int position) const
{
	if ((position < 1) || (position > getLength()))
		return NULL;

	else  // count from the beginning of the list
	{
		listNode *cur = head;

		for (int skip = 1; skip < position; ++skip)
			cur = cur->next;

		return cur;
	}
}
// Code stays the same

bool doublyLinkedList::retrieveElement(int position, listItemType& dataItem) const
{
	bool success = ((position >= 1) && (position <= getLength()));

	if (success)
	{
		// get pointer to node, then data in node
		listNode *cur = ptrTo(position);

		dataItem = cur->item;
	}

	return success;
}
// Code stays the same


// Iterative SortedList Insert
void doublyLinkedList::insertElement(listItemType newItem)
{


	listNode *cur = head;
	 

	

	listNode *newPtr = new listNode;
	newPtr->item = newItem;
	
	if (cur == NULL) //checks to see if the entire list is empty
	{
		cur = newPtr;
		head = cur;
		tail = cur;
		cur->prev = NULL;
		cur->next = NULL;
	}

	if ((cur != NULL) && newItem < cur->item) // checks to see if inserted item goes to the beginning
	{
		newPtr->prev = NULL;
		newPtr->next = cur; // puts the node before the current node
		cur->prev = newPtr; // the current node points back to the new node
		head = newPtr; // makes the new node the head

	}
	else if ((cur != NULL) && newItem > tail->item) // checks to see if the inserted item goes to the end
	{
		newPtr->next = NULL;
		newPtr->prev = tail; // points the new node to the previous node
		tail->next = newPtr; // points back to the
		tail = newPtr; // makes the new node the tail
	}
	//if (prev == NULL)
	//	head = newPtr; //part of orignal code
	else
	{
		while ((cur != NULL) && (newItem > cur->item))
		{	
			cur = cur->next;
			
			//prev = cur;
			//cur = cur->next;
			//prev->next = newPtr;
			//newPtr->prev = prev; // points back to the previous node
		}
		newPtr->prev = cur->prev;
		newPtr->next = cur;
		cur->prev = newPtr;
		newPtr->prev->next = newPtr;

	}
	size++;
}


void doublyLinkedList::locateElement(listItemType key, int& position)
{
	listNode *cur = head;

	position = 1;

	while (cur != NULL && cur->item != key)
	{
		cur = cur->next;
		position++;
	}

	if (cur == NULL)
		position = -1;
}


bool doublyLinkedList::deleteElement(int position)
{

	listNode *cur;

	bool success = ((position >= 1) && (position <= getLength()));

	if (success)
	{
		--size;

		if (position == 1)
		{
			// delete the first node from the list
			cur = head;  // save pointer to node
			head = head->next;
		}
		else if (position == size + 1) //delete the last node from the list
		{
			cur = tail;	// saves the pointer to node
			tail = tail->prev; // sets the tail equal to the previous node
			tail->next = NULL; //the next pointer should be null at the end
		}
		else
		{
			listNode *prev = ptrTo(position - 1);

			// delete the node after the node 
			//    to which Prev points

			cur = prev->next;  // save pointer to node
			prev->next = cur->next;
			cur->next->prev = prev;
		}

		// return node to system
		cur->prev = NULL;
		cur->next = NULL;
		delete cur;
		cur = NULL;
	}

	return success;
}

void doublyLinkedList::reverse()
{
	if (size <= 1) //if the size is one or zero do nothing
	{
		return;
	}
	listNode *cur = head;
	
	//swapping head with tail
	head = tail;	
	tail = cur;	

	cur = head;
	
	while (cur->prev != NULL) //sets all of the node's "next" pointer to the previous one
	{
		cur->next = cur->prev;
		if (cur->prev != NULL)
		{
			cur = cur->prev;
		}
	}
	head->prev = NULL; 
	cur = head;
	for (int i = 0; i < size - 1; i++)
	{
		cur->next->prev = cur;
		cur = cur->next;
	}
	
	tail->next = NULL;
}

void doublyLinkedList::printN(int elements)
{
	listNode *cur = head;
	//postion should start at 1 because size is at starts at 1
	if (elements >= 1 && elements <= size) //Checks to see what user wants to print between 0-size
	{
		for (int i = 0; i < elements; i++) 
		{

			std::cout << cur->item << std::endl;
			cur = cur->next;
		}
	}
	else if (elements <= 0) //special case if user wants anything less than or equal to 0 which prints out a blank
	{
		std::cout <<" "<< std::endl;
	}
	else 
	{
		for (int i = 0; i < size; i++) //for anything greater than the size it the size is just printed out
		{

			std::cout << cur->item << std::endl;
			cur = cur->next;
		}
	}
}

bool doublyLinkedList::operator== (const doublyLinkedList& right)
{
	//shortcut in case comparing same two sortedLists
	if (&right == this)
		return true;

	//check sizes are the same
	if (getLength() != right.getLength())
		return false;

	//temporary variables for comparison
	listItemType mine;
	listItemType theirs;

	//compare each element
	for (int i = 1; i <= getLength(); i++)
	{
		//use public methods to get each element
		retrieveElement(i, mine);
		right.retrieveElement(i, theirs);

		//return false after any mismatch
		if (mine != theirs)
			return false;
	}

	//if code gets here, all elements must be the same
	return true;
}

bool doublyLinkedList::operator!= (const doublyLinkedList& right)
{
	return !(*this == right);

}
