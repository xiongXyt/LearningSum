#include"SingleListTable.h"
#include<iostream>
using namespace std;

int main() {
	/*
	* �޲ι��캯������
	*/
	//SingleListTable singlelisttable;
	//singlelisttable.PrintList();

	/*
	* �вι��캯������
	*/
	SingleListTable singlelisttable(10);
	singlelisttable.PrintList();

	/*
	* ͷ���������
	*/
	//SingleListTable singlelisttable(2);
	//singlelisttable.PrintList();
	//singlelisttable.AddHeadNum(100);
	//singlelisttable.PrintList();

	/*
	* β���������
	*/
	//SingleListTable singlelisttable(3);
	//singlelisttable.PrintList();
	//singlelisttable.AddEndNum(100);
	//singlelisttable.PrintList();

	/*
	* �����������
	*/
	//SingleListTable singlelisttable(3);
	//singlelisttable.PrintList();
	//singlelisttable.AddIndexNum(4,100);
	//singlelisttable.PrintList();

	/*
	* ͷɾ������
	*/
	//SingleListTable singlelisttable(10);
	//singlelisttable.PrintList();
	//singlelisttable.DeleteHeadNum();
	//singlelisttable.PrintList();

	/*
	* βɾ������
	*/
	//SingleListTable singlelisttable(10);
	//singlelisttable.PrintList();
	//singlelisttable.DeleteEndNum();
	//singlelisttable.PrintList();

	/*
	* ɾ�����ݲ���
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//singlelisttable.DeleteNum(2, true);
	//singlelisttable.PrintList();

	/*
	* �����������
	*/
	//int n[5] = { 1,2,2,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//singlelisttable.Sort();
	//singlelisttable.PrintList();
	return 0;
}