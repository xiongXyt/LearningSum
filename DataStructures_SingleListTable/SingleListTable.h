#ifndef _SINGLELISTTABLE_H_
#define _SINGLELISTTABLE_H_

/***************************************************
*
*	��    ����SingleListTable
*
*	��    �ܣ�int ���͵�����  �� ��ϸ���·��ݸ� ��
*
*	�޸ļ�¼��
*
*		�޸�ʱ�䣺�� 2023-05-11 ���� ��
*		�޸����ݣ��� ��Ŀ������������ݳ�Ա���塢�������� ��
*
*		�޸�ʱ�䣺�� 2023-05-11 ���� ��
*		�޸����ݣ��� ������е�Ԥ������ ��
*
*		�޸�ʱ�䣺�� 2023-06-1 ��
*		�޸����ݣ��� ���C++�ο��ֲᵥ����ĺ��� ��
*
*	��    �ߣ��� xyt ��
*	��ϵ��ʽ��3124725835@qq.com
*
*	��    ����
*
***************************************************/

#include<iostream>
using namespace std;

#define MAXSIZE 200

/***************************************************
* �ڵ�ṹ�壬�ڵ���ָ����һ���ڵ�
***************************************************/
struct Node {
	// ������
	int number;
	// ָ����
	Node* NextNode;
};

/***************************************************
*	˵����ʹ�ÿյ�ͷ�ڵ㣬�����������������������ĳ���
*
*	��    ��    [ SingleListTable ]
*
*	��Ĺ��ܣ��Լ�д�ĵ���������
*
*	��    ����ʹ�ÿյ�ͷ�ڵ㣬�����ͷ����������������������ĳ���
*			  ͷ������һ���ڵ��ʾ��һ���ڵ�
*			  һ���ڵ�ֻ��ָ����һ���ڵ�
*
*	��ʷ����
*		��Ŀ������������ݳ�Ա���塢������������û�������ԣ�
*		���������������롢ɾ��������
*		��������أ��� + = ��
*		��������Ŀ����򻯡�ע�͡��������еĲ��԰�����
*
*	��������
*		ʵ��C++�ο��ֲᵥ����ĺ���
*
***************************************************/
class SingleListTable {
private:
	Node* m_pHead;  // ͷָ��
	int m_Len;      // �ڵ�ĳ���

	void __InitList();  // ��ʼ������

public:
	SingleListTable();
	SingleListTable(int count);
	SingleListTable(int count, int value);
	SingleListTable(int* Begin, int* End);
	SingleListTable(const SingleListTable& other);
	~SingleListTable();

	// ��������أ� + - ��
	SingleListTable operator+(const SingleListTable& other);  // �ӷ����������
	SingleListTable operator=(const SingleListTable& other);  // �������������

	void PrintList()const;     // ��ӡ����
	void Clear();  // �����������ͷָ��
	bool IsEmpty();  // �ж�����Ϊ��
	int MaxSize();  // �������������������Ĭ��Ϊ200���ڵ�

	void AddHeadNum(int value);  // ͷ����
	void AddEndNum(int value);  // β����
	void AddIndexNum(int pos, int value);  // ����ָ��λ�ò���

	void DeleteHeadNum();  // ͷɾ��
	void DeleteEndNum();  // βɾ��
	void DeleteIndexNum(int pos);  // ����ָ��λ��ɾ��
	void DeleteNum(int value, bool flag = false);     // ɾ������ value ���ݵĵ�һ���ڵ�

	int& Front();  // ������Ԫ�ص�����
	void Assign(int count, int value);  // �� count �� value �ĸ����滻���ݡ�

	void Swap(SingleListTable& other); // �������� other �Ľ���
	void Merge(const SingleListTable& other);  //�鲢��������������,����Ӧ����������

	void Sort();           // ����

};

#endif // !_SINGLELISTTABLE_H_
