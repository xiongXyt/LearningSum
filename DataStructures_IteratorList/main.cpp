#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
#include"MyList.h"

int main() {
	//beatles::test_list1();
	//beatles::test_list2();
	//beatles::test_list3();
	//beatles::test_list4();
	//beatles::test_list5();
	MyList::MyList<int> mylist;
	mylist.push_back(1);
	mylist.push_back(10);
	mylist.push_back(100);
	mylist.push_back(1000);
	//mylist.PrintList();

	MyList::MyList<int>::iterator it = mylist.begin();
	for (; it != mylist.end(); ++it) {
		cout << it.m_Node->data << endl;
	}
	return 0;
}
