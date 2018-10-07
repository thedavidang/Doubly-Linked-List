// David Ang
// 9-28-2018
// CSC2431
// Lab 1

//Create a sorted doubly linked list with the base code of a sorted linked list edited to make a doubly linked list
//the list can be added or deleted as well a pinpoint a certain value within the list
//methods of reverse and printN are added to reverse the list and print out the elements

typedef int listItemType;

class doublyLinkedList
{
public:
	//CONSTRUCTORS and DESTRUCTOR

	//Default constructor, creates an empty list
	doublyLinkedList();

	//Copy constructor, makes this a copy of list original
	doublyLinkedList(const doublyLinkedList& original);

	//Destructor, free memory for list
	~doublyLinkedList();

	//ACCESSORS

	//Accessor to check if list is empty
	//Parameters: none
	//Returns: true if list is empty, false otherwise (a bool)
	bool isEmpty() const;

	//Accessor to retrieve length of list
	//Parameters: none
	//Returns: length of list (an int)
	int getLength() const;

	//Locate an element in the list.
	//Parameters: the element (key) to locate (listItemType)
	//Returns: the position of the key in the list (an int, -1 if does not exist)
	void locateElement(listItemType key, int& position);

	//Prints the requested number of elements in the list
	//Parameters: the maximum amount of elements to print
	//Retruns: nothing
	void printN(int size);

	//MUTATORS

	//Mutator to insert element into sorted list.  Automatically inserts at correct position.
	//Parameters: the element to insert into the list (listItemType)
	//Returns: nothing
	void insertElement(listItemType newItem);

	//Mutator to delete element from list by position (starting at 1)
	//Parameters: the position (int) at which to delete 
	//Returns: true if successful, false otherwise (a bool)
	bool deleteElement(int position);

	//Mutator to retrieve an element from list by position (starting at 1)
	//Parameters: the position (int) from which to retrieve an element
	//Returns: true if successful (element is stored in dataItem), false otherwise (a bool)
	bool retrieveElement(int position, listItemType& dataItem) const;

	//Mutator to reverse the order of the list
	//Parameters: None
	//Returns: Nothing
	void reverse();

	//OVERLOADED OPERATORS

	//Overloaded equality operator
	//Parameters: the list to compare to this (sortedList)
	//Returns: If lengths match, all elements match (in order), return true
	bool operator== (const doublyLinkedList& right);

	//Overloaded inequality operator
	//Parameters: the list to compare to this (sortedList)
	//Returns: If length mismatch, or all elements do not match (in order), return true
	bool operator!= (const doublyLinkedList& right);

	

private:
	struct listNode
	{
		listItemType  item;
		listNode     *next;
		listNode     *prev; // pointer to the previous node
	};

	int       size;  // number of items in list

	listNode *head;  // pointer to linked list of items (front of the list)
	listNode *tail;  // pointer to the end of the list
					 // Private member function that returns a pointer to the position-th node in the linked list.
					 // (Private since client should only be able to access by position.)
	listNode *ptrTo(int position) const;

};
