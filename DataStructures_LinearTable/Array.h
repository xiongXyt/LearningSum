#ifndef _ARRAY_H_
#define _ARRAY_H_

/***************************************************
*
*	��    ����Array
*
*	��    �ܣ�int ������������Գ�ʼ��  �� ��ϸ���·��ݸ� ��
*
*	�޸ļ�¼��
*
*		�޸�ʱ�䣺�� 2023-05-09 ��
*		�޸����ݣ��� ��ӳ�Ա���� ��
*
*		�޸�ʱ�䣺�� 2023-05-09 ��
*		�޸����ݣ��� ��ӳ�Ա���� ��
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
*	��    ��    [ Array ]
*
*	���ݳ�Ա��
*		public:
*			int num;        ��������
*		protected:
*			int num;        ��������
*		private:
*			int num;        ��������
*
*	��Ա������
*		public:
*			bool IsEmptyArray();      // �����Ƿ�Ϊ��
*		protected:
*			int num();        ��������
*		private:
*			int num();        ��������
*
*	�ϴ�����
*		1. �ж�˳����Ƿ�Ϊ��;
*		2. ĩβ���Ԫ��;
*		3. ɾ��ĩβԪ��;
*		4. ����λ�����Ԫ��
*
*	��������
*		5. ɾ�����������ĵ�һ��Ԫ��;
*		6. ɾ����������������Ԫ��;
*		7. ����
*		8. ������Ԫ�أ���ֵͬ��Ԫ�ر���һ��;
*		9. �ϲ�������ͬ����׼���˳���(����)
*
***************************************************/
class Array {

public:
	Array();
	Array(int n, int num);
	Array(int* Begin, int* End);
	Array(const Array& other);

	~Array();

	void ClearArray();       // ������飬�ͷ��ڴ棬ָ���ÿ�

	void PintArray();        // ��ӡ��������

	bool IsEmptyArray();     // �����Ƿ�Ϊ��

	void EndAddArray(int num);   // ĩβ���Ԫ��

	bool EndDeleteArray();   // ĩβɾ��Ԫ��

	void AddArrayIndex(int num, int index);    // ����λ�����Ԫ��

	void DeleteNumArray(int num);   // ɾ�����������ĵ�һ��Ԫ��

	void DeletrAllNumArray(int num);  // ɾ����������������Ԫ��

	void SortArray(int num = 1);    // ������

private:
	int* m_p;
	int m_MaxSize;
	int m_size;
};

#endif // !_ARRAY_H_
