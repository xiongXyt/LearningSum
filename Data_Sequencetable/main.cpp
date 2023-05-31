#include<iostream>
#include"SList.h"
using namespace std;

int main() {
	SList myarr(10,100);
	myarr.PrintArr();
	myarr.Insert(1, 1000);
	myarr.RemoveAll(100);
	myarr.PrintArr();
	return 0;
}