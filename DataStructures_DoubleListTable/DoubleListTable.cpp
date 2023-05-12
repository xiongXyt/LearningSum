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
			this->m_pEnd->number = this->m_Len;
		}
		else {
			pTemp->NextNode = this->m_pHead->NextNode;
			pTemp->FrontNode = this->m_pHead;
			this->m_pHead->NextNode = pTemp;
			pTemp->NextNode->FrontNode = pTemp;

			// �ڵ�������
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
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
			this->m_pEnd->number = this->m_Len;
		}
		else {
			pTemp->NextNode = this->m_pHead->NextNode;
			pTemp->FrontNode = this->m_pHead;
			this->m_pHead->NextNode = pTemp;
			pTemp->NextNode->FrontNode = pTemp;

			// �ڵ�������
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
		}
	}
}

DoubleListTable::DoubleListTable(int* Begin, int* End) {
	// ��ʼ��ͷָ��
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// ��ʼ��β�ڵ�ָ�룬ָ��ͷ���
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;

	for (int* pNum = Begin; pNum < End; ++pNum) {
		this->AddEndNum(*pNum);
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

// ͷ����
void DoubleListTable::AddHeadNum(int num) {
	// ��ʼ���½ڵ�
	Node* pNew = new Node;
	pNew->number = num;
	pNew->FrontNode = pNew->NextNode = nullptr;

	if (0 == this->m_Len) {  // ����Ϊ��
		// �����µĽڵ�
		this->m_pHead->NextNode = pNew;
		pNew->FrontNode = this->m_pHead;

		// βָ��ָ�����һ���ڵ�
		this->m_pEnd->NextNode = pNew;

		// �ڵ�������
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {
		pNew->NextNode = this->m_pHead->NextNode;
		pNew->FrontNode = this->m_pHead;
		this->m_pHead->NextNode = pNew;
		pNew->NextNode->FrontNode = pNew;

		// �ڵ�������
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

// β����
void DoubleListTable::AddEndNum(int num) {
	// ��ʼ���½ڵ�
	Node* pNew = new Node;
	pNew->number = num;
	pNew->FrontNode = pNew->NextNode = nullptr;

	// ���ؽڵ㵽����
	this->m_pEnd->NextNode->NextNode = pNew;
	pNew->FrontNode = this->m_pEnd->NextNode;

	// βָ��ָ�����һ���ڵ�
	this->m_pEnd->NextNode = pNew;

	// �ڵ�������
	++this->m_Len;
	this->m_pHead->number = this->m_Len;
	this->m_pEnd->number = this->m_Len;
}

// ����ָ��λ�ò���
void DoubleListTable::AddIndexNum(int index, int num) {
	if (index > 0 && index <= this->m_Len + 1) {
		if (this->m_Len + 1 == index) {  // ���һ��λ��
			this->AddEndNum(num);
		}
		else {
			// ��ʼ���½ڵ�
			Node* pNew = new Node;
			pNew->number = num;
			pNew->FrontNode = pNew->NextNode = nullptr;

			Node* pIndex = this->m_pHead;

			for (int i = 1; i < index; i++) {
				pIndex = pIndex->NextNode;
			}

			pNew->NextNode = pIndex->NextNode;
			pNew->FrontNode = pIndex;
			pIndex->NextNode = pNew;
			pNew->NextNode->FrontNode = pNew;

			// �ڵ�������
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
		}
	}
	else {
		cout << "����λ������" << endl;
	}
}

// ͷɾ��
void DoubleListTable::DeleteHeadNum() {
	if (this->m_Len==0) {
		cout << "����Ϊ�գ�" << endl;
	}
	else if (this->m_Len==1) {
		Node* pTemp = this->m_pHead->NextNode;

		this->m_pEnd->NextNode = this->m_pHead;
		this->m_pHead->NextNode = nullptr;

		cout << "ɾ�� : " << pTemp->number << endl;

		delete pTemp;
		pTemp = nullptr;

		// �ڵ�������
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {
		Node* pTemp = this->m_pHead->NextNode;

		this->m_pHead->NextNode = pTemp->NextNode;
		pTemp->NextNode->FrontNode = this->m_pHead;

		cout << "ɾ�� : " << pTemp->number << endl;

		delete pTemp;
		pTemp = nullptr;

		// �ڵ�������
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

// βɾ��
void DoubleListTable::DeleteEndNum() {
	if (0==this->m_Len) {
		cout << "����Ϊ�գ�" << endl;
	}
	else if (1==this->m_Len) {
		Node* pTemp = this->m_pHead->NextNode;

		this->m_pEnd->NextNode = this->m_pHead;
		this->m_pHead->NextNode = nullptr;

		cout << "ɾ�� : " << pTemp->number << endl;

		delete pTemp;
		pTemp = nullptr;

		// �ڵ�������
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {
		Node* pTemp = this->m_pEnd->NextNode;

		this->m_pEnd->NextNode = pTemp->FrontNode;
		this->m_pEnd->NextNode->NextNode = nullptr;

		cout << "ɾ�� : " << pTemp->number << endl;

		delete pTemp;
		pTemp = nullptr;

		// �ڵ�������
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

// ����ָ��λ��ɾ��
void DoubleListTable::DeleteIndexNum(int index) {
	if (index>0&&index<=this->m_Len) {
		if (1 == index) {
			this->DeleteHeadNum();
		}
		else if (index==this->m_Len) {
			this->DeleteEndNum();
		}
		else {
			Node* pIndex = this->m_pHead->NextNode;

			for (int i = 1; i < index; i++) {
				pIndex = pIndex->NextNode;
			}

			Node* pTemp = pIndex->NextNode;
			pIndex->NextNode = pTemp->NextNode;
			pTemp->NextNode->FrontNode = pIndex;

			cout << "ɾ�� : " << pTemp->number << endl;

			delete pTemp;
			pTemp = nullptr;

			// �ڵ�������
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
		}
	}
	else {
		cout << "����λ������" << endl;
	}
}

// ɾ������ num ���ݵĵ�һ���ڵ�
void DoubleListTable::DeleteNum(int num, bool flag) {  // flagΪtrue,ȫ��ɾ��
	Node* pTemp = this->m_pHead;  // ��ʱָ��
	Node* pNum = nullptr;         // ����ڵ��ָ��

	while (pTemp->NextNode != nullptr) {  // ����Ϊ��
		if (pTemp->NextNode == this->m_pEnd->NextNode &&
			pTemp->NextNode->number == num) {
			this->DeleteEndNum();
		}
		else if (pTemp->NextNode->number == num) {
			/*********************
			* ɾ��Ŀ��ڵ㣬���ͷ�
			* ע��ɾ��֮���ǲ����ƶ���
			* ��Ϊ����Ľڵ㱻��������
			*********************/
			Node* pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;
			pNum->NextNode->FrontNode = pTemp;

			cout << "ɾ�� : " << pNum->number << endl;

			delete pNum;
			pNum = nullptr;

			// �ڵ�������
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;

			if (!flag)break;  // flagΪtrue,ȫ��ɾ��
		}
		else {  // ��ɾ���ڵ�ʱ�ƶ�
			cout << pTemp->NextNode->number << endl;
			pTemp = pTemp->NextNode;
		}
	}
}

// ����
void DoubleListTable::Sort() {
	cout << "���ܻ�û��ʵ��" << endl;
}
