#include "linkedlist.h"
#include <iostream>
#include <fstream>




/************************
private:
node * head;
************************/
LinkedList::LinkedList() 
{

}

LinkedList::LinkedList() :node(NULL), 
{
	if (aList.head == NULL) //or if(!aList.head)
		head = NULL;
	else
	{
		//copy first node
		head = new node;
		assert(head != NULL); //check allocation
		head->item = aList.head->item;

		//copy the rest of the list
		node * destNode = head;				//points to the last node in new list
		node * srcNode = aList.head->next;  //points to node in aList
		while (srcNode != NULL) //or while (srcNode)
		{
			destNode->next = new node;
			assert(destNode->next != NULL); //check allocation
			destNode = destNode->next;
			destNode->item = srcNode->item;

			srcNode = srcNode->next;
		}
		destNode->next = NULL;
	}
}

const list& list::operator= (const list& aList)
{
	if (this == &aList)
		return *this;
	else
	{
		//release dynamically allocated memory held by current object
		node * curr = head;
		while (head)
		{
			curr = head->next;
			delete head;
			head = curr;
		}

		//make *this a deep copy of "aList"
		if (!aList.head)
			head = NULL;
		else
		{
			//copy the first node
			head = new node;
			assert(head != NULL);
			head->item = aList.head->item;

			//copy the rest of the list
			node * destNode = head;
			node * srcNode = aList.head->next;

			while (srcNode)
			{
				destNode->next = new node;
				assert(destNode->next);
				destNode = destNode->next;
				destNode->item = srcNode->item;

				srcNode = srcNode->next;
			}
			destNode->next = NULL;
		}

		return *this;
	}
}

LinkedList::~LinkedList()
{
	node * curr = head;
	while (head)
	{
		curr = head->next;
		delete head;		//the constructor for individual data (item) is invoked
		head = curr;
	}
}

bool LinkedList:: add(char)
{
	node * prev = NULL;
	node * curr = head;

	//traverse to find the position to insert
	while (curr != NULL && curr->item < aData)
	{
		prev = curr;
		curr = curr->next;
	}

	//the data already exists
	if (curr && curr->item == aData)
		return false;
	//insert the data here
	else
	{
		//create new node to contain the data
		node * newNode = new node;
		newNode->item = aData;
		newNode->next = NULL;

		//link the newNode into the linked list
		newNode->next = curr;
		if (prev == NULL)
			head = newNode;
		else
			prev->next = newNode;
		size++;
		return true;
	}
}

bool LinkedList::del (char)
{
	char ch[100];

	//search for the data to be removed
	node * prev = NULL;
	node * curr = head;
	while (curr)
	{
		curr->item.getPccId(id);
		if (strcmp(key, id) == 0)
		{
			//remove the data
			if (!prev)
				head = curr->next;
			else
				prev->next = curr->next;
			delete curr;
			size--;
			return true;
		}

		prev = curr;
		curr = curr->next;
	}
	//data is not in the list
	return false;
}

bool LinkedList::find(char ch, data & aData)const
{
	//search for the data to be retrieved
	node * curr;
	char id[100];
	for (curr = head; curr; curr = curr->next)
	{
		curr->item.getPccId(id);
		if (strcmp(key, id) == 0)
		{
			aData = curr->item;
			return true;
		}
	}

	//data is not in the list
	return false;
}

void list::display(void)const
{
	node * curr;

	cout << "Data in the list: " << endl << endl;
	for (curr = head; curr; curr = curr->next)
	{
		//we can use << on data object because we overload << in the data class
		cout << '\t' << curr->item << endl;
	}
}

int list::getSize() const
{
	return size;
}