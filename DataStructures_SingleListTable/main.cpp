#include"SingleListTable.h"
#include<iostream>
using namespace std;

int main() {
	/*
	* 无参构造函数测试
	*/
	//SingleListTable singlelisttable;
	//singlelisttable.PrintList();

	/*
	* 有参构造函数测试
	*/
	SingleListTable singlelisttable(10);
	singlelisttable.PrintList();

	/*
	* 头部插入测试
	*/
	//SingleListTable singlelisttable(2);
	//singlelisttable.PrintList();
	//singlelisttable.AddHeadNum(100);
	//singlelisttable.PrintList();

	/*
	* 尾部插入测试
	*/
	//SingleListTable singlelisttable(3);
	//singlelisttable.PrintList();
	//singlelisttable.AddEndNum(100);
	//singlelisttable.PrintList();

	/*
	* 索引插入测试
	*/
	//SingleListTable singlelisttable(3);
	//singlelisttable.PrintList();
	//singlelisttable.AddIndexNum(4,100);
	//singlelisttable.PrintList();

	/*
	* 头删除测试
	*/
	//SingleListTable singlelisttable(10);
	//singlelisttable.PrintList();
	//singlelisttable.DeleteHeadNum();
	//singlelisttable.PrintList();

	/*
	* 尾删除测试
	*/
	//SingleListTable singlelisttable(10);
	//singlelisttable.PrintList();
	//singlelisttable.DeleteEndNum();
	//singlelisttable.PrintList();

	/*
	* 删除数据测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//singlelisttable.DeleteNum(2, true);
	//singlelisttable.PrintList();

	/*
	* 数据排序测试
	*/
	//int n[5] = { 1,2,2,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//singlelisttable.Sort();
	//singlelisttable.PrintList();
	return 0;
}