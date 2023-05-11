#include"SingleListTable.h"
#include<iostream>
using namespace std;

int main() {
	int n[10] = { 1,1,1,4,1,6,1,8,1,1 };
	SingleListTable singlelisttable(n, n + 10);
	singlelisttable.PrintList();

	singlelisttable.Sort();

	singlelisttable.PrintList();
	return 0;
}