#include <iostream>
#include<fstream>
#include "Location2D.h"
#include "Node.h"
#include "LinkedQueue.h"
#include "LinkedList.h"
#include <string>
#include <windows.h>

using namespace std;
class Miro {
private:
	int row;    //�̷��� �� (y��ǥ)
	int col;    //�̷��� �� (x��ǥ)
	char **map;    //�̷� ��
	Location2D now;	//Location2D �̿�(������ġ Ȯ�� �� Ž��)
	int exit[2];	//������
	LinkedQueue lqueue;	//LinkedQueue Ȱ��
	LinkedList llist; //����Ҷ� ���Ḯ��Ʈ
	Node *nnode;
	int x, y;
public:
	Miro() {
		init(0, 0);
	}
	void init(int w, int h)   //map ������ �迭�� �������� �Ҵ�
	{
		map = new char*[h];
		for (int i = 0; i < h; i++)
			map[i] = new char[w];
	}
	void reset()    //�̷� �� maze�� �������� ����
	{
		for (int i = 0; i < col; i++)
			delete[]map[i];
		delete[]map;
	}
	void load(const char *fname) //�̷� ������ �о��
	{
		int check = 1;
		char c;
		char temp;
		row = 1;
		col = 0;

		ifstream fin(fname, ios::in);    //fname������ �о����

		fin >> col >> row;
		init(col, row);   //row�� col�� 2���� �迭�� ����
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				fin >> temp;    // temp������
				map[i][j] = temp;     // map������
				//check�� 1 �̸� ����� 2�̸� ������ �̷��� ������ �־� �Ѵ�.
				if (map[i][j] == 'e')   //������� ��ǥ�� ���, (x,y) ��ǥ�� ������ ��� ����
				{
					now.setRow(i);
					now.setCol(j);
					Node start = Node(now.getRow(), now.getCol());
					Node *p = start.getLink();
					lqueue.enqueue(p);//�������带 ��ũť�� �״�
					printf("                                               <�����: (%d, %d)>", now.getRow(), now.getCol());
					map[i][j] = '5';    //������ ��� ���߿� �����ϱ� ���� '5'���� �ٲ۴�.
					printf("\n");
				}
				else if (map[i][j] == 'x')    //�������� ��ǥ�� ���, (x,y) ��ǥ�� ������ ��� ����
				{
					exit[0] = j;
					exit[1] = i;
					printf("                                               <������: (%d, %d)>", exit[0], exit[1]);
					map[i][j] = '9';
				}
			}

		}
		fin.close();
	}

	void print() //���� Maze�� ȭ�鿡 ���
	{
		int check = 1;
		cout << "\n--------��ü �̷��� ũ��---------  " << "----" << row << " *" << col << "----" << endl;
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (map[i][j] == '0' && ((i != 0 && i != row - 1) && (j != 0 && j != col - 1)))  // �̷��� ��
				{
					cout << "  ";
				}
				else if (map[i][j] == '1')
				{
					cout << "��";
				}
				else if (map[i][j] == '7')
				{
					cout << "��"; //Ž�� ��
				}
				else if (map[i][j] == '3') {
					cout << "��";	//������ ��(���� ���� ��ġ ����)
				}
				else if (map[i][j] == '9')
				{
					cout << "��";
				}
				else if (map[i][j] == '5') {
					cout << "��";
				}
			}
			cout << endl;
		}
	}
	void searchExit()        //���� �̷θ� Ž���ϴ� �Լ�
	{
		while (1) {


			x = now.getCol();
			y = now.getRow();

			// ������ ��ġ�� �ݺ��ϸ鼭 ����ش�.

			search(x, y - 1);
			search(x, y + 1);
			search(x - 1, y);
			search(x + 1, y);

			system("cls");
			Move();
			print();
			Sleep(200);
			map[y][x] = '3';
		}
		system("cls");
		print();
		llist.display();
	}
	void search(int x1, int y1) {
		if (row > y1&& y1 >= 0 && col > x1&&x1 > -1 && (map[y1][x1] == '0' || map[y1][x1] == '9')) {
			nnode = new Node(x1, y1);
			lqueue.enqueue(nnode);
			if (map[y1][x1] == '0') map[y1][x1] = '7';
		}
	}
	void Move() {
		Node *move = lqueue.dequeue();
		now.setRow(move->getY());
		now.setCol(move->getX());
		llist.addList(move);
	}

	void dfsMaze() {
		printf("---------------------------------\n");
		printf("---------------------------------               [�̿� ��ġ Ž�� ����]\n");
		printf("---------------------------------                      ���\n");
		printf("---------------------------------                    ���  ���\n");
		printf("---------------BFS---------------						 ���\n");
		printf("---------------------------------\n");
		printf("---------------------------------\n");
	}
};
