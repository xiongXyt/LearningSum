#ifndef _SINGLELISTTABLE_H_
#define _SINGLELISTTABLE_H_

/***************************************************
*
*	类    名：SingleListTable
*
*	功    能：int 类型单链表  （ 详细见下方草稿 ）
*
*	修改记录：
*
*		修改时间：【 2023-05-11 中午 】
*		修改内容：【 项目启动，类的数据成员定义、构造析构 】
*
*		修改时间：【 2023-05-11 下午 】
*		修改内容：【 完成所有的预定功能 】
* 
*	作    者：【 xyt 】
*	联系方式：3124725835@qq.com
*
*	其    他：
*
***************************************************/

#include<iostream>
using namespace std;

/***************************************************
* 节点结构体，节点能指向下一个节点
***************************************************/
struct Node {
	// 数据域
	int number;
	// 指针域
	Node* NextNode;
};

/***************************************************
*	说明：使用空的头节点，里面的数据域用来保存链表的长度
* 
*	草    稿    [ SingleListTable ]
*
*	类的功能：自己写的单链表数组
*
*	描    述：使用空的头节点，里面的头结点的数据域用来保存链表的长度
*			  头结点的下一个节点表示第一个节点
*			  一个节点只能指向下一个节点
*
*	历史任务：
*		项目启动，类的数据成员定义、构造析构（还没有做测试）
*		创建、遍历、插入、删除、排序
*
*	本次任务：
*		运算符重载，（ + - ）
*
***************************************************/
class SingleListTable {
public:
	SingleListTable();
	SingleListTable(int n);
	SingleListTable(int n, int num);
	SingleListTable(int* Begin, int* End);
	SingleListTable(const SingleListTable& other);
	~SingleListTable();

	void PrintList()const;     // 打印链表

	void AddHeadNum(int num);  // 头插入
	void AddEndNum(int num);  // 尾插入
	void AddIndexNum(int index, int num);  // 按照指定位置插入

	void DeleteHeadNum();  // 头删除
	void DeleteEndNum();  // 尾删除
	void DeleteIndexNum(int index);  // 按照指定位置删除
	void DeleteNum(int num, bool flag = false);     // 删除含有 num 数据的第一个节点

	void Sort();           // 排序

private:
	Node* m_pHead;  // 头指针
	int m_Len;      // 节点的长度
};

#endif // !_SINGLELISTTABLE_H_
