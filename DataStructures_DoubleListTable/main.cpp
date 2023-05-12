#include"DoubleListTable.h"
#include<iostream>
using namespace std;

int main() {
	DoubleListTable doublelisttable1(2);
	DoubleListTable doublelisttable2(3);
	DoubleListTable doublelisttable3;
	doublelisttable1.PrintTable();
	doublelisttable2.PrintTable();
	doublelisttable3.PrintTable();

	cout << endl << "***********************" << endl << endl;
	doublelisttable3 = doublelisttable1 + doublelisttable2;


	doublelisttable1.PrintTable();
	doublelisttable2.PrintTable();
	doublelisttable3.PrintTable();
	return 0;
}