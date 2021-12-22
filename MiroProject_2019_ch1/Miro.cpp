#include <iostream>
#include "Miro.h"
void main() {
	Miro m;


	m.load("test.txt");
	m.print();
	Sleep(1500);
	system("cls");
	m.searchExit();
}