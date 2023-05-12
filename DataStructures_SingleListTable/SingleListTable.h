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
*	��    �ߣ��� xyt ��
*	��ϵ��ʽ��3124725835@qq.com
*
*	��    ����
*
***************************************************/

#include<iostream>
using namespace std;

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
*
*	��������
*		��������أ��� + - ��
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

	void PrintList()const;     // ��ӡ����

	void AddHeadNum(int num);  // ͷ����
	void AddEndNum(int num);  // β����
	void AddIndexNum(int index, int num);  // ����ָ��λ�ò���

	void DeleteHeadNum();  // ͷɾ��
	void DeleteEndNum();  // βɾ��
	void DeleteIndexNum(int index);  // ����ָ��λ��ɾ��
	void DeleteNum(int num, bool flag = false);     // ɾ������ num ���ݵĵ�һ���ڵ�

	void Sort();           // ����

private:
	Node* m_pHead;  // ͷָ��
	int m_Len;      // �ڵ�ĳ���
};

#endif // !_SINGLELISTTABLE_H_
