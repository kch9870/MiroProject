#include <cstdlib>
#include "Node.h"

class LinkedQueue
{
	Node* front;
	Node* rear;

public:
	LinkedQueue() { front = rear = NULL; }
	~LinkedQueue() {};

	bool isEmpty()
	{
		return front == NULL;
	}
	void enqueue(Node* p)
	{
		if (isEmpty())
		{
			front = rear = p;
		}
		else
		{
			rear->setLink(p);
			rear = p;
		}
	}
	Node* dequeue()
	{
		if (isEmpty())
		{
			return NULL;
		}
		if (front == NULL)
		{
			rear = NULL;
		}
		else
		{
			Node* p = front;
			front = front->getLink();
			return p;
		}
	}
	Node* peek()
	{
		return front;
	}
};