#include<iostream>
#include"Singleton.h"
using namespace std;

int main() {
	Singleton::SL();
	Singleton::SL(); 
	Singleton::SL();
	Singleton::SL();
	Singleton::SL()->Print();
	return 0;
}
