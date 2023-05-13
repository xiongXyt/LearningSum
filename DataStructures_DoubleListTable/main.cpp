#include"DoubleListTable.h"
#include<iostream>
using namespace std;

int main() {
	/*
	* 无参构造函数测试
	*/
	//DoubleListTable doublelisttable;
	//doublelisttable.PrintTable();

	/*
	* 有参构造函数测试
	*/
	DoubleListTable doublelisttable(10);
	doublelisttable.PrintTable();

	/*
	* 头部插入测试
	*/
	//DoubleListTable doublelisttable(2);
	//doublelisttable.PrintTable();
	//doublelisttable.AddHeadNum(100);
	//doublelisttable.PrintTable();

	/*
	* 尾部插入测试
	*/
	//DoubleListTable doublelisttable(3);
	//doublelisttable.PrintTable();
	//doublelisttable.AddEndNum(100);
	//doublelisttable.PrintTable();

	/*
	* 索引插入测试
	*/
	//DoubleListTable doublelisttable(3);
	//doublelisttable.PrintTable();
	//doublelisttable.AddIndexNum(4,100);
	//doublelisttable.PrintTable();

	/*
	* 头删除测试
	*/
	//DoubleListTable doublelisttable(10);
	//doublelisttable.PrintTable();
	//doublelisttable.DeleteHeadNum();
	//doublelisttable.PrintTable();

	/*
	* 尾删除测试
	*/
	//DoubleListTable doublelisttable(10);
	//doublelisttable.PrintTable();
	//doublelisttable.DeleteEndNum();
	//doublelisttable.PrintTable();

	/*
	* 删除数据测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//DoubleListTable doublelisttable(n, n + 5);
	//doublelisttable.PrintTable();
	//doublelisttable.DeleteNum(2, true);
	//doublelisttable.PrintTable();

	/*
	* 数据排序测试
	*/
	//int n[5] = { 1,2,2,1,2 };
	//DoubleListTable doublelisttable(n, n + 5);
	//doublelisttable.PrintTable();
	//doublelisttable.Sort();
	//doublelisttable.PrintTable();
	return 0;
}