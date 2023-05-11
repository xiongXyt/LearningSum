#ifndef _ARRAY_H_
#define _ARRAY_H_

/***************************************************
*
*	类    名：Array
*
*	功    能：int 类型数组的线性初始化  （ 详细见下方草稿 ）
*
*	修改记录：
*
*		修改时间：【 2023-05-09 】
*		修改内容：【 添加成员函数 】
*
*		修改时间：【 2023-05-09 】
*		修改内容：【 添加成员函数 】
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
*	草    稿    [ Array ]
*
*	数据成员：
*		public:
*			int num;        作用描述
*		protected:
*			int num;        作用描述
*		private:
*			int num;        作用描述
*
*	成员函数：
*		public:
*			bool IsEmptyArray();      // 数组是否为空
*		protected:
*			int num();        作用描述
*		private:
*			int num();        作用描述
*
*	上次任务：
*		1. 判断顺序表是否为空;
*		2. 末尾添加元素;
*		3. 删除末尾元素;
*		4. 任意位置添加元素
*
*	本次任务：
*		5. 删除满足条件的第一个元素;
*		6. 删除满足条件的所有元素;
*		7. 排序
*		8. 排序后的元素，相同值的元素保留一个;
*		9. 合并两个相同排序准则的顺序表(排序)
*
***************************************************/
class Array {

public:
	Array();
	Array(int n, int num);
	Array(int* Begin, int* End);
	Array(const Array& other);

	~Array();

	void ClearArray();       // 清空数组，释放内存，指针置空

	void PintArray();        // 打印数组内容

	bool IsEmptyArray();     // 数组是否为空

	void EndAddArray(int num);   // 末尾添加元素

	bool EndDeleteArray();   // 末尾删除元素

	void AddArrayIndex(int num, int index);    // 任意位置添加元素

	void DeleteNumArray(int num);   // 删除满足条件的第一个元素

	void DeletrAllNumArray(int num);  // 删除满足条件的所有元素

	void SortArray(int num = 1);    // 正排序

private:
	int* m_p;
	int m_MaxSize;
	int m_size;
};

#endif // !_ARRAY_H_
