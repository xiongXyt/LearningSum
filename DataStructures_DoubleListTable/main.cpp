#include"DoubleListTable.h"
#include<iostream>
using namespace std;

int main() {
	/*
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
	*/

	/*
	* ͷ���������
	*/
	// DoubleListTable doublelisttable(2);
	// doublelisttable.PrintTable();
	// doublelisttable.AddHeadNum(100);
	// doublelisttable.PrintTable();

	/*
	* β���������
	*/
	// DoubleListTable doublelisttable(3);
	// doublelisttable.PrintTable();
	// doublelisttable.AddEndNum(100);
	// doublelisttable.PrintTable();

	/*
	* �����������
	*/
	// DoubleListTable doublelisttable(3);
	// doublelisttable.PrintTable();
	// doublelisttable.AddIndexNum(4,100);
	// doublelisttable.PrintTable();

	/*
	* ͷɾ������
	*/
	// DoubleListTable doublelisttable(10);
	// doublelisttable.PrintTable();
	// doublelisttable.DeleteHeadNum();
	// doublelisttable.PrintTable();

	/*
	* βɾ������
	*/
	// DoubleListTable doublelisttable(10);
	// doublelisttable.PrintTable();
	// doublelisttable.DeleteEndNum();
	// doublelisttable.PrintTable();

	/*
	* ɾ�����ݲ���
	*/
	// int n[5] = { 1,2,1,1,2 };
	// DoubleListTable doublelisttable(n, n + 5);
	// doublelisttable.PrintTable();
	// doublelisttable.DeleteNum(2, true);
	// doublelisttable.PrintTable();

	/*
	* �����������
	*/
	int n[5] = { 1,2,1,1,2 };
	DoubleListTable doublelisttable(n, n + 5);
	doublelisttable.PrintTable();
	doublelisttable.DeleteNum(2, true);
	doublelisttable.PrintTable();
	return 0;
}