#ifndef _LINKED_LIST_
#define _LINKED_LIST_

#include <ostream>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	const LinkedList& operator= (const LinkedList& aList);

	void add(char ch);
	bool find(char ch);
	bool del(char ch);


private:
	struct node
	{
		data item;
		node * next;
	};
	node * head;
	int size;
};


#endif // _LINKED_LIST_
