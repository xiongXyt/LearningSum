#include"OperatorOverload.h"
#include<iostream>
using namespace std;

int main() {
	OperatorOverload<int>opov1(10);
	OperatorOverload<int>opov2(20);
	cout << "opov1 : "; opov1.Print();
	cout << "opov2 : "; opov2.Print();
	cout << "***********" << endl;

	opov2 = opov1 + opov2;
	cout << "opov1 : "; opov1.Print();
	cout << "opov2 : "; opov2.Print();
	cout << "***********" << endl;

	opov2 = opov2 - opov1;
	cout << "opov1 : "; opov1.Print();
	cout << "opov2 : "; opov2.Print();
	cout << "***********" << endl;

	++opov2;
	cout << "opov1 : "; opov1.Print();
	cout << "opov2 : "; opov2.Print();
	cout << "***********" << endl;

	opov2++;
	cout << "opov1 : "; opov1.Print();
	cout << "opov2 : "; opov2.Print();
	cout << "***********" << endl;

	opov2 = opov1;
	cout << "opov1 : "; opov1.Print();
	cout << "opov2 : "; opov2.Print();
	cout << "***********" << endl;

	if (opov1!=opov2) {
		cout << "!=" << endl;
	}
	else {
		cout << "==" << endl;
	}

	if (opov1 == opov2) {
		cout << "==" << endl;
	}
	else {
		cout << "!=" << endl;
	}

	opov1 == opov2 ? cout << "==" << endl : cout << "!=" << endl;

	cout << opov1 << endl;
	return 0;
}