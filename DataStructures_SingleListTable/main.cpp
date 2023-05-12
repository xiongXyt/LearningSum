#include"SingleListTable.h"
#include<iostream>
using namespace std;

int main() {
	int n[2] = { 1,1 };
	int m[2] = { 2,2 };
	SingleListTable singlelisttable1(n, n + 2);
	SingleListTable singlelisttable2(m, m + 2);
	SingleListTable singlelisttable3;
	singlelisttable1.PrintList();
	singlelisttable2.PrintList();
	cout << "*************" << endl;
	singlelisttable3 = singlelisttable1 + singlelisttable2;
	singlelisttable3.PrintList();
	return 0;
}