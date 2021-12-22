#include <cstdlib>
#include <iostream>
#include "Node.h"

using namespace std;
class LinkedList
{
	Node *head;
	Node *tail;
	int size;
public:
	LinkedList() { head = tail = NULL; size = 0; }
	bool isEmpty() {
		if (head == NULL) return true;
		return false;
	}
	void addList(Node *n) {
		if (isEmpty()) {
			head = tail = n;
		}
		else {
			tail->setLink(n);
			tail = n;
			size++;
		}
	}
	void display() {
		Node *tmp = head;
		for (int i = 0; i < size; i++) {
			tmp->print();
			tmp = tmp->getLink();
		}
		printf("ÃÑ %dÈ¸ Å½»ö Çß´Ù", size);
	}
};
