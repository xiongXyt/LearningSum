#include<iostream>
#include"main.h"
using namespace std;

int main() {
	int num_10[10] = { 2 };
	int(*pnum[10][10][10][10])[10][10][10][10];
	cout << sizeof(pnum) << endl;
	cout << sizeof(*pnum) << endl;
	cout << sizeof(**pnum) << endl;
	cout << sizeof(***pnum) << endl;
	cout << sizeof(****pnum) << endl;
	cout << sizeof(*****pnum) << endl;
	cout << sizeof(******pnum) << endl;
	cout << sizeof(*******pnum) << endl;
	cout << sizeof(********pnum) << endl;
	cout << sizeof(*********pnum) << endl;
	return 0;
}

