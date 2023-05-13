#include"SingleListTable.h"

/***********************************************************************
* �� �� ����__InitList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����ʼ�������ͷ�ڵ�
*			-- 2 -- ��������Ϊ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����д����
***********************************************************************/
void SingleListTable::__InitList() {
	// ��ʼ�������ͷ�ڵ�
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;
	this->m_pHead->number = this->m_Len = 0;  // ����ĳ���Ϊ ��
}

/***********************************************************************
* �� �� ����SingleListTable()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����ʼ�������ͷ�ڵ�
*			-- 2 -- ��������Ϊ��
*			-- 3 -- ���޲�������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
***********************************************************************/
SingleListTable::SingleListTable() {
	this->__InitList();  // ��ʼ������
}

/***********************************************************************
* �� �� ����SingleListTable(int n)
* �� �� ��
*			1 ) n -->( int ) : ��Ҫ��ʼ������Ľڵ����
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ�������ͷ�ڵ�
*			-- 3 -- ������ 1~n ����������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
*					2 ��β�巨�����ɵ� AddEndNum(int num) ����
***********************************************************************/
SingleListTable::SingleListTable(int n) {
	this->__InitList();  // ��ʼ������

	for (int i = 0; i < n; i++) {
		this->AddEndNum(i + 1);  // β�巨
	}
}

/***********************************************************************
* �� �� ����SingleListTable(int n, int num)
* �� �� ��
*			1 ) n ---->( int ) : ��Ҫ��ʼ������Ľڵ����
*			2 ) num -->( int ) : ����ÿ���ڵ��������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ�������ͷ�ڵ�
*			-- 3 -- ������ֵ��Ϊ num ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
*					2 ��β�巨�����ɵ� AddEndNum(int num) ����
***********************************************************************/
SingleListTable::SingleListTable(int n, int num) {
	this->__InitList();  // ��ʼ������

	for (int i = 0; i < n; i++) {
		this->AddEndNum(num);  // β�巨
	}
}

/***********************************************************************
* �� �� ����DoubleListTable(int* Begin, int* End)
* �� �� ��
*			1 ) Begin --->( int* ) : �����ڴ�ĵ�һ����ַ
*			2 ) End   --->( int* ) : �����ڴ�����һ����ַ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ���вι���
*			-- 2 -- ����ʼ�������ͷ�ڵ�
*			-- 3 -- ������ֵΪһ�������ڴ��ڵ�ֵ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
*					2 ��β�巨�����ɵ� AddEndNum(int num) ����
***********************************************************************/
SingleListTable::SingleListTable(int* Begin, int* End) {
	this->__InitList();  // ��ʼ������

	for (int* num = Begin; num < End; ++num) {
		this->AddEndNum(*num);  // β�巨
	}
}

/***********************************************************************
* �� �� ����SingleListTable(const SingleListTable& other)
* �� �� ��
*			1 ) other -->( const SingleListTable& ) : ����һ����������
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- �����ƹ��캯��
*			-- 2 -- ����ʼ�������ͷ�ڵ�
*			-- 3 -- �����һ��ֻ��ֵ��ͬ������
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �����ȴӸ�ֵ��ʽ��Ϊ����
*					2 ����ʼ�������ͷ�ڵ㣬���ɵ� __InitList() ����
*					2 ��β�巨�����ɵ� AddEndNum(int num) ����
***********************************************************************/
SingleListTable::SingleListTable(const SingleListTable& other) {
	this->__InitList();  // ��ʼ������

	Node* pother = other.m_pHead;  // ��ʱ���洫�������ָ��

	// ��ͷ��ʼ����
	while (pother->NextNode != nullptr) {  // ��ʱ���洫�������ָ�벻Ϊ��
		this->AddEndNum(pother->NextNode->number);  // β�巨

		// �ڵ�ָ�����
		pother = pother->NextNode;
	}
}

/***********************************************************************
* �� �� ����~SingleListTable()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- �������������ֶ��ͷ�������ڴ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
SingleListTable::~SingleListTable() {
	Node* pTemp = nullptr;  // ��ʱ����ڵ�

	// ��ǰ�������ͷ�
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	// ������Ϊ��
	this->m_Len = 0;
}

/***********************************************************************
* �� �� ����operator+(const SingleListTable& other)
* �� �� ��
*			1 ) other -->( const SingleListTable& ) : ����һ����������
* �� �� ֵ��
*			1 ) SingleListTable : ���ص��������
* �������ܣ�
*			-- 1 -- ���ӷ����غ���
*			-- 2 -- ��β�巨
*			-- 3 -- ����ǰ��������һ�ڵ��һ�������ֵ
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
SingleListTable SingleListTable::operator+(const SingleListTable& other) {
	Node* pHead = this->m_pHead;  // ����ͷָ��

	// �ƶ������һ���ڵ�
	while (pHead->NextNode != nullptr) {
		pHead = pHead->NextNode;
	}

	// ���ؽڵ㵽���һ��
	for (Node* pOther = other.m_pHead->NextNode; pOther != nullptr; pOther=pOther->NextNode) {
		// ��ȡ�����������
		Node* pNum = new Node;
		pNum->number = pOther->number;
		pNum->NextNode = nullptr;

		//�����½ڵ㵽���ڵ�
		pHead->NextNode = pNum;
		pHead = pHead->NextNode;
	}
	return *this;
}

/***********************************************************************
* �� �� ����operator=(const SingleListTable& other)
* �� �� ��
*			1 ) other -->( const SingleListTable& ) : ����һ����������
* �� �� ֵ��
*			1 ) SingleListTable : ���ص�ǰ������
* �������ܣ�
*			-- 1 -- ���������غ���
*			-- 2 -- ��β�巨
*			-- 3 -- ����ǰ�����ֵΪ����һ�������ֵ�����
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��β�巨�����ɵ� AddEndNum(int num) ����
***********************************************************************/
SingleListTable SingleListTable::operator=(const SingleListTable& other) {
	this->__InitList();  // ��ʼ������

	Node* pother = other.m_pHead;  // ��ʱ���洫�������ָ��

	// ��ͷ��ʼ����
	while (pother->NextNode != nullptr) {  // ��ʱ���洫�������ָ�벻Ϊ��
		this->AddEndNum(pother->NextNode->number);  // β�巨

		// �ڵ�ָ�����
		pother = pother->NextNode;
	}
	return *this;
}

/***********************************************************************
* �� �� ����PrintList()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ����ͷ�ڵ���һ���ڵ��ӡȫ�������ֵ
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 �������������ȵĴ�ӡ
***********************************************************************/
void SingleListTable::PrintList() const {
	Node* pPint = this->m_pHead->NextNode;  // ��������ͷ�ڵ����һ���ڵ�

	// ��ӡ������
	cout << "m_Len : " << this->m_Len << endl;

	// ������ӡ����
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;
		pPint = pPint->NextNode; // ����
	}
	cout << endl << "--------------------" << endl << endl;
}

/***********************************************************************
* �� �� ����AddHeadNum(int num)
* �� �� ��
*			1 ) num -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ�������ͷ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void SingleListTable::AddHeadNum(int num) {
	// �½ڵ�
	Node* pNew = new Node;
	pNew->number = num;
	pNew->NextNode = nullptr;

	// ͷ�巨
	if (0 == this->m_Len) {  // ����Ϊ�㣬ֱ�ӹ��ڵ�һ��λ��

		// ָ��ı仯
		this->m_pHead->NextNode = pNew;  // ͷ������һ��Ϊ pNew

		// ���Ⱥ�ͷָ���������仯
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // ͷ����ͷָ���������޸�

		// ָ��ı仯
		pNew->NextNode = this->m_pHead->NextNode;  // pNew ��һ���ڵ�Ϊ��һ���ڵ�
		this->m_pHead->NextNode = pNew;            // ͷ������һ��Ϊ pNew

		// ���Ⱥ�ͷָ���������仯
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����AddEndNum(int num)
* �� �� ��
*			1 ) num -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ�������β��
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void SingleListTable::AddEndNum(int num) {
	// �½ڵ�
	Node* pNew = new Node;
	pNew->number = num;
	pNew->NextNode = nullptr;

	// β�巨
	if (0 == this->m_Len) {  // ����Ϊ�㣬ֱ�ӹ��ڵ�һ��λ��

		// ָ��ı仯
		this->m_pHead->NextNode = pNew;  // ͷ������һ��Ϊ pNew

		// ���Ⱥ�ͷָ���������仯
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // β�巨��βָ�����޸�
		Node* pTemp = this->m_pHead;

		// �ƶ����������Ľڵ�
		while (pTemp->NextNode != nullptr) {
			pTemp = pTemp->NextNode;  // ����
		}

		// ����
		pTemp->NextNode = pNew;

		// ���Ⱥ�ͷָ���������仯
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����AddIndexNum(int index, int num)
* �� �� ��
*			1 ) index -->( int ) : ���������λ��
*			2 ) num -->( int ) : ���������ֵ
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��������ֵ num ������� index λ��
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ������д��ע��
***********************************************************************/
void SingleListTable::AddIndexNum(int index, int num) {
	if (index<1 || index>this->m_Len) {  // ��������
		cout << "----- �������Ϸ� -----" << endl << endl;
	}
	else {
		Node* pTemp = this->m_pHead;  // ��ʱָ��

		// ��Ҫ����Ľڵ��ʼ��
		Node* pNum = new Node;
		pNum->number = num;
		pNum->NextNode = nullptr;

		// �ҵ���Ҫ�����ǰһ��λ��
		for (int i = 1; i < index; i++) {
			pTemp = pTemp->NextNode;  // ����
		}

		// ����
		pNum->NextNode = pTemp->NextNode; // �ȹ���ȥ
		pTemp->NextNode = pNum;           // ������

		// ���ȸ���
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

/***********************************************************************
* �� �� ����DeleteHeadNum()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ�������һ���ڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void SingleListTable::DeleteHeadNum() {
	if (this->m_Len != 0) {  // ���Ȳ�Ϊ�㣬ɾ����һ��
		Node* pNum = nullptr;         // ����ڵ��ָ��

		// ָ��ı仯��ɾ��֮���ͷű�ɾ���Ľڵ�
		pNum = this->m_pHead->NextNode;  // ͷ������һ��
		this->m_pHead->NextNode = pNum->NextNode; // ͷ�������¸�

		// ��ӡ��ɾ���Ľڵ���Ϣ
		cout << "ɾ�� : " << pNum->number << endl;
		cout << "λ�� : 1 " << endl;

		// �ͷű�ɾ���Ľڵ�
		delete pNum;  
		pNum = nullptr;

		// ���Ⱥ�ͷָ���������仯
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}
}

/***********************************************************************
* �� �� ����DeleteIndexNum(int index)
* �� �� ��
*			1 ) : index -->( int ) ɾ�������λ��
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ������indexλ�õĽڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void SingleListTable::DeleteEndNum() {
	if (0 != this->m_Len) {  // ���Ȳ�Ϊ�㣬ɾ�����һ��
		Node* pNum = nullptr;      // ����ڵ��ָ��

		Node* pTemp = this->m_pHead;   // ��ʱָ��

		// �ƶ����������ڵ��ǰһ��λ��
		while (pTemp->NextNode->NextNode != nullptr) {
			pTemp = pTemp->NextNode;  // ����
		}

		// ָ��ı仯��ɾ��֮���ͷű�ɾ���Ľڵ�
		pNum = pTemp->NextNode;
		pTemp->NextNode = nullptr;

		// ��ӡ��ɾ���Ľڵ���Ϣ
		cout << "ɾ�� : " << pNum->number << endl;
		cout << "λ�� : " << this->m_Len << " " << endl;

		// �ͷű�ɾ���Ľڵ�
		delete pNum;  
		pNum = nullptr;

		// ���Ⱥ�ͷָ���������仯
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}
}

/***********************************************************************
* �� �� ����DeleteIndexNum(int index)
* �� �� ��
*			1 ) : index -->( int ) ɾ�������λ��
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ������indexλ�õĽڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
*					2 ������������Ϊ����ж�
***********************************************************************/
void SingleListTable::DeleteIndexNum(int index) {
	if (0 != this->m_Len) {  // ���Ȳ�Ϊ��
		if (index<1 || index>this->m_Len) {  // ��������
			cout << "----- �������Ϸ� -----" << endl << endl;
		}
		else {  // ������ȷ
			Node* pTemp = this->m_pHead;  // ��ʱָ��
			Node* pNum = nullptr;         // ����ڵ��ָ��

			// �ҵ���Ҫɾ����ǰһ��λ��
			for (int i = 1; i < index; i++) {
				pTemp = pTemp->NextNode;  // ����
			}

			// ɾ��֮���ͷű�ɾ���Ľڵ�
			pNum = pTemp->NextNode;       // ���汻ɾ���Ľڵ�
			pTemp->NextNode = pNum->NextNode;  // �Ͽ�����������һ���ڵ�

			// ��ӡ��ɾ���Ľڵ���Ϣ
			cout << "ɾ�� : " << pNum->number << endl;
			cout << "λ�� : " << index << " " << endl;

			delete pNum;  // �ͷű�ɾ���Ľڵ�
			pNum = nullptr;

			// ���ȸ���
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
	else {  // ����Ϊ��
		cout << "����Ϊ�գ�" << endl;
	}

}

/***********************************************************************
* �� �� ����DeleteNum(int num, bool flag)
* �� �� ��
*			1 ) : num --->( int ) ��ɾ����ֵ
*			2 ) : flag -->( int ) ȫ��ɾ������numֵ�ı�־
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ɾ������ num ֵ�ĵ�һ���ڵ�
*			-- 2 -- ��flag ( true ) ��Ϣȫ��ɾ������ num ֵ�Ľڵ�
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע�͡�����������ɾ����λ����Ϣ
***********************************************************************/
void SingleListTable::DeleteNum(int num, bool flag) {  // flagΪtrue,ȫ��ɾ��
	Node* pTemp = this->m_pHead;  // ��ʱָ��
	Node* pNum = nullptr;         // ����ڵ��ָ��

	int posindex = 1;  // ��ɾ���ڵ�λ��

	while (pTemp->NextNode != nullptr) {  // ����Ϊ��
		if (pTemp->NextNode->number == num) {
			/*********************
			* ɾ��Ŀ��ڵ㣬���ͷ�
			* ע��ɾ��֮���ǲ����ƶ���
			* ��Ϊ����Ľڵ㱻��������
			*********************/

			// �Ͽ���ɾ���ڵ�
			pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;

			// ��ӡ��ɾ���Ľڵ���Ϣ
			cout << "ɾ�� : " << pNum->number << endl;
			cout << "λ�� : " << posindex << " " << endl;

			// �ͷű��Ͽ��Ľڵ�
			delete pNum;
			pNum = nullptr;

			// ���ȸ���
			--this->m_Len;
			this->m_pHead->number = this->m_Len;

			if (!flag)break;  // flagΪtrue,ȫ��ɾ��
		}
		else {  // ��ɾ���ڵ�ʱ�ƶ�
			pTemp = pTemp->NextNode;

			// ɾ���ڵ�λ����Ϣ����һ
			++posindex;
		}
	}
}

/***********************************************************************
* �� �� ����Sort()
* �� �� ��None
* �� �� ֵ��None
* �������ܣ�
*			-- 1 -- ��ð�����򣬵���
* �����ģ�
*			����ʱ�䣺�� 2023.5.13 ��
*			������Ա��xyt
*			�������ݣ�
*					1 ��д��ע��
***********************************************************************/
void SingleListTable::Sort() {
	for (int i = 1; i < this->m_Len; i++) {  // ����
		Node* pTemp01 = this->m_pHead;
		for (int j = 0; j < this->m_Len - i; j++) {  // ÿ�˱ȽϵĴ���
			Node* pTemp02 = pTemp01->NextNode;
			if (pTemp01->NextNode->number > pTemp02->NextNode->number) {
				// ����
				pTemp01->NextNode = pTemp02->NextNode;
				pTemp02->NextNode = pTemp01->NextNode->NextNode;
				pTemp01->NextNode->NextNode = pTemp02;
				// ����
				pTemp01 = pTemp01->NextNode;
			}
			else {
				// ����
				pTemp01 = pTemp01->NextNode;
			}
		}
	}
}
