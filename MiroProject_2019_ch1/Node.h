#pragma once
#include <cstdlib>

class Node
{
	int pos[2];		//LinkedQueue에 들어가는 노드 x,y좌표 (탐색이 지낫으며 Location2D 와 다른 의미)
	Node* link;

public:
	Node(int x, int y)
	{
		pos[0] = x;
		pos[1] = y;
		link = NULL;
	}
	int getX() { return pos[0]; }
	int getY() { return pos[1]; }
	void print() { printf("(%d, %d)  ",pos[0],pos[1]); }
	Node* getLink() { return link; }
	void setLink(Node* next) { link = next; }
};