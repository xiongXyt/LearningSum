#ifndef _SLIST_H_
#define _SLIST_H_

#include<iostream>
using namespace std;

#define SNUM short

#define MAXSIZE 10
#define ADDSIZE 10

/*
* 数据成员：最大长度，被使用的长度，内置数组
*/

class SList {
private:
	SNUM m_MaxSize;
	SNUM m_Usedsize;
	SNUM* m_Array;

private:
	bool IsFull();
	void AddLen();

public:
	SList();
	SList(SNUM len, SNUM num);
	~SList();

	bool IsEmpty();
	void Push_Back(SNUM num);
	void Pop_Back();
	void Insert(SNUM pos,SNUM num);
	void Remove(SNUM num);
	void RemoveAll(SNUM num);

	void PrintArr();

};

#endif // !_SLIST_H_
