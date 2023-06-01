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
	//SingleListTable singlelisttable(10);
	//singlelisttable.PrintList();

	/*
	* 清空链表测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//singlelisttable.Clear();
	//singlelisttable.PrintList();

	/*
	* 判断链表为空测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//singlelisttable.Clear();
	//singlelisttable.PrintList();
	//cout << "singlelisttable.IsEmpty() : " << singlelisttable.IsEmpty() << endl;

	/*
	* 返回链表最大容量测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//cout << "singlelisttable.MaxSize() : " << singlelisttable.MaxSize() << endl;

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
	* 返回首元素的引用测试
	*/
	//int n[5] = { 1,2,2,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//cout << "singlelisttable.front() : " << singlelisttable.front() << endl;
	//singlelisttable.front() = 10;
	//cout << "singlelisttable.front() : " << singlelisttable.front() << endl;
	//singlelisttable.PrintList();

	/*
	* 指定重置链表数据测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleListTable singlelisttable(n, n + 5);
	//singlelisttable.PrintList();
	//singlelisttable.Assign(10, 100);
	//singlelisttable.PrintList();

	/*
	* 链表交换数据测试
	*/
	//int n[5] = { 1,2,1,1,2 };
	//SingleListTable singlelisttable1(n, n + 5);
	//SingleListTable singlelisttable2(10, 100);
	//singlelisttable1.PrintList();
	//singlelisttable2.PrintList();
	//singlelisttable1.Swap(singlelisttable2);
	//singlelisttable1.PrintList();
	//singlelisttable2.PrintList();
	//singlelisttable1.AddHeadNum(10000);
	//singlelisttable1.PrintList();
	//singlelisttable2.PrintList();

	/*
	* 归并二个已排序链表测试
	*/
	//int num1[5] = { 1,3,5,7,9 };
	//int num2[5] = { 2,4,6,8,10 };
	//SingleListTable singlelisttable1(num1, num1 + 5);
	//SingleListTable singlelisttable2(num2, num2 + 5);
	//singlelisttable1.PrintList();
	//singlelisttable2.PrintList();
	//singlelisttable1.Merge(singlelisttable2);
	//singlelisttable1.PrintList();
	//singlelisttable2.PrintList();

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