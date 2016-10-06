#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(char ch);
	bool find(char ch);
	bool del(char ch);

	friend std::ostream& operator<<(std::ostream& out, LinkedList& list);

private:
	//linera single linked list.. for doubly threded you need two next pointer
	struct node
	{
		char data;
		//pointer to next node
		node * next;
	};
	//Keep track of head pointer not a node just a pointer to first node
	node * head;
	//Size of the list
	int size;
};

#endif // _LINKED_LIST_
