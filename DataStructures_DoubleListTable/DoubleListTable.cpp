#include"DoubleListTable.h"

/*
* ���캯��ȫ������ͷ�巨
*/
DoubleListTable::DoubleListTable() {
	// ��ʼ��ͷָ��
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// ��ʼ��β�ڵ�ָ�룬ָ��ͷ���
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;
}

DoubleListTable::DoubleListTable(int num) {
	// ��ʼ��ͷָ��
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// ��ʼ��β�ڵ�ָ�룬ָ��ͷ���
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;
	
	for (int i = num; i >= 1; --i) {
		// �½ڵ�
		Node* pTemp = new Node;
		pTemp->number = i;
		pTemp->FrontNode = pTemp->NextNode = nullptr;
		if (0 == this->m_Len) {  // ����Ϊ��
			// �����µĽڵ�
			this->m_pHead->NextNode = pTemp;
			pTemp->FrontNode = this->m_pHead;
			
			// βָ��ָ�����һ���ڵ�
			this->m_pEnd->NextNode = pTemp;

			// �ڵ�������
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
		else {
			pTemp->NextNode = this->m_pHead->NextNode;
			pTemp->FrontNode = this->m_pHead;
			this->m_pHead->NextNode = pTemp;
			pTemp->NextNode->FrontNode = pTemp;

			// �ڵ�������
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
}

DoubleListTable::DoubleListTable(int n, int num) {
	// ��ʼ��ͷָ��
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// ��ʼ��β�ڵ�ָ�룬ָ��ͷ���
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;

	for (int i = n; i >= 1; --i) {
		// �½ڵ�
		Node* pTemp = new Node;
		pTemp->number = num;
		pTemp->FrontNode = pTemp->NextNode = nullptr;
		if (0 == this->m_Len) {  // ����Ϊ��
			// �����µĽڵ�
			this->m_pHead->NextNode = pTemp;
			pTemp->FrontNode = this->m_pHead;

			// βָ��ָ�����һ���ڵ�
			this->m_pEnd->NextNode = pTemp;

			// �ڵ�������
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
		else {
			pTemp->NextNode = this->m_pHead->NextNode;
			pTemp->FrontNode = this->m_pHead;
			this->m_pHead->NextNode = pTemp;
			pTemp->NextNode->FrontNode = pTemp;

			// �ڵ�������
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
}

DoubleListTable::DoubleListTable(const DoubleListTable& other) {
	// ��ʼ��ͷָ��
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// ��ʼ��β�ڵ�ָ�룬ָ��ͷ���
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;

	Node* pNum = other.m_pHead->NextNode;

	// �������β�巨
	while (pNum!=nullptr) {
		// �����ڵ��ʼ��������ֵ
		Node* pTemp = new Node;
		pTemp->number = pNum->number;
		pTemp->FrontNode = pTemp->NextNode = nullptr;

		// ���ؽڵ㵽����
		this->m_pEnd->NextNode->NextNode = pTemp;
		pTemp->FrontNode = this->m_pEnd->NextNode;

		// βָ��ָ�����һ���ڵ�
		this->m_pEnd->NextNode = pTemp;

		// �ڵ�������
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;

		// pNum����
		pNum = pNum->NextNode;
	}
}

DoubleListTable::~DoubleListTable() {
	// �����ͷţ�Ҳ����һ��һ�����ͷ�������ڴ�
	Node* pTemp = nullptr;

	// �ͷ�β�ڵ�
	delete this->m_pEnd;
	this->m_pEnd = nullptr;

	// ��ǰ����ͷ�
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	this->m_Len = 0;
}

DoubleListTable DoubleListTable::operator+(const DoubleListTable& other) {
	Node* pOther = other.m_pHead->NextNode;
	// �������β�巨
	while (pOther != nullptr) {
		// �����ڵ��ʼ��������ֵ
		Node* pTemp = new Node;
		pTemp->number = pOther->number;
		pTemp->FrontNode = pTemp->NextNode = nullptr;

		// ���ؽڵ㵽����
		this->m_pEnd->NextNode->NextNode = pTemp;
		pTemp->FrontNode = this->m_pEnd->NextNode;

		// βָ��ָ�����һ���ڵ�
		this->m_pEnd->NextNode = pTemp;

		// �ڵ�������
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;

		// pOther����
		pOther = pOther->NextNode;
	}
	return *this;
}

DoubleListTable DoubleListTable::operator=(const DoubleListTable& other) {
	// ��ʼ��ͷָ��
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// ��ʼ��β�ڵ�ָ�룬ָ��ͷ���
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;

	Node* pNum = other.m_pHead->NextNode;

	// �������β�巨
	while (pNum != nullptr) {
		// �����ڵ��ʼ��������ֵ
		Node* pTemp = new Node;
		pTemp->number = pNum->number;
		pTemp->FrontNode = pTemp->NextNode = nullptr;

		// ���ؽڵ㵽����
		this->m_pEnd->NextNode->NextNode = pTemp;
		pTemp->FrontNode = this->m_pEnd->NextNode;

		// βָ��ָ�����һ���ڵ�
		this->m_pEnd->NextNode = pTemp;

		// �ڵ�������
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;

		// pNum����
		pNum = pNum->NextNode;
	}
	return *this;
}

// ��ӡ����
void DoubleListTable::PrintTable() {
	Node* pPint = this->m_pHead->NextNode;

	cout << "this->m_Len : " << this->m_Len << endl;
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;
		pPint = pPint->NextNode; // ����
	}
	cout << endl << "--------------------" << endl << endl;
}
