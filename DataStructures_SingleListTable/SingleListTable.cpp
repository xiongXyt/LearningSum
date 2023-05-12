#include"SingleListTable.h"

/*
* �޲ι��죬
*/
SingleListTable::SingleListTable() {
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;         // ��һ��λ��Ϊ ��
	this->m_pHead->number = this->m_Len = 0;   // ����ĳ���Ϊ ��
}

SingleListTable::SingleListTable(int n) {
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;            // ��һ��λ��Ϊ ��
	this->m_pHead->number = this->m_Len = 0;      // ����ĳ���Ϊ ��

	for (int i = 0; i < n; i++) {
		Node* pNew = new Node;
		pNew->number = i + 1;
		pNew->NextNode = nullptr;

		// ͷ�巨
		/*
		* if (0 == this->m_Len) {  // ����Ϊ�㣬ֱ�ӹ��ڵ�һ��λ��
		*
		* 	// ָ��ı仯
		* 	this->m_pHead->NextNode = pNew;  // ͷ������һ��Ϊ pNew
		*
		* 	// ���Ⱥ�ͷָ���������仯
		* 	++this->m_Len;
		* 	this->m_pHead->number = this->m_Len;
		* }
		* else {  // ͷ����ͷָ���������޸�
		*
		* 	// ָ��ı仯
		* 	pNew->NextNode = this->m_pHead->NextNode;  // pNew ��һ���ڵ�Ϊ��һ���ڵ�
		* 	this->m_pHead->NextNode = pNew;            // ͷ������һ��Ϊ pNew
		*
		* 	// ���Ⱥ�ͷָ���������仯
		* 	++this->m_Len;
		* 	this->m_pHead->number = this->m_Len;
		* }
		*/

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

			// �ƶ�����������λ��
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
}

SingleListTable::SingleListTable(int n, int num) {
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;         // ��һ��λ��Ϊ ��
	this->m_pHead->number = this->m_Len = 0;   // ����ĳ���Ϊ ��

	for (int i = 0; i < n; i++) {
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

			// �ƶ�����������λ��
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
}

SingleListTable::SingleListTable(int* Begin, int* End) {
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;         // ��һ��λ��Ϊ ��
	this->m_pHead->number = this->m_Len = 0;   // ����ĳ���Ϊ ��

	for (int* num = Begin; num < End; ++num) {
		Node* pNew = new Node;
		pNew->number = *num;
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

			// �ƶ�����������λ��
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
}

SingleListTable::SingleListTable(const SingleListTable& other) {
	// ��ʼ��
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;
	this->m_pHead->number = this->m_Len = other.m_Len;

	Node* pTemp = this->m_pHead;   // ��ʱ���浱ǰ����ָ��
	Node* pother = other.m_pHead;  // ��ʱ���洫�������ָ��
	Node* pNum = nullptr;          // ����ڵ�ָ��

	// ��ͷ��ʼ����
	while (pother->NextNode != nullptr) {  // ��ʱ���洫�������ָ�벻Ϊ��
		// ��ʼ���ڵ㣬���ֶ���ֵ
		pNum = new Node;
		pNum->number = pother->NextNode->number;
		pNum->NextNode = nullptr;

		pTemp->NextNode = pNum;     // ��������λ��

		// ����ָ��һ�����
		pTemp = pTemp->NextNode;
		pother = pother->NextNode;
	}
}

SingleListTable::~SingleListTable() {
	// �����ͷţ�Ҳ����һ��һ�����ͷ�������ڴ�
	Node* pTemp = nullptr;

	// ��ǰ����ͷ�
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	this->m_Len = 0;

	// �Ӻ���ǰ�ͷ�
	/*
	* �����Ҳ���ǰ��Ľڵ㣬���￼�ǵ���ʹ��˫������
	*/
}
// �ӷ����������
SingleListTable SingleListTable::operator+(const SingleListTable& other) {
	Node* pHead = this->m_pHead;
	// ָ�����
	while (pHead->NextNode != nullptr) {
		pHead = pHead->NextNode;
	}
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

// �������������
SingleListTable SingleListTable::operator=(const SingleListTable& other) {
	// ��ʼ��
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;
	this->m_pHead->number = this->m_Len = other.m_Len;

	Node* pTemp = this->m_pHead;   // ��ʱ���浱ǰ����ָ��
	Node* pother = other.m_pHead;  // ��ʱ���洫�������ָ��
	Node* pNum = nullptr;          // ����ڵ�ָ��

	// ��ͷ��ʼ����
	while (pother->NextNode != nullptr) {  // ��ʱ���洫�������ָ�벻Ϊ��
		// ��ʼ���ڵ㣬���ֶ���ֵ
		pNum = new Node;
		pNum->number = pother->NextNode->number;
		pNum->NextNode = nullptr;

		pTemp->NextNode = pNum;     // ��������λ��

		// ����ָ��һ�����
		pTemp = pTemp->NextNode;
		pother = pother->NextNode;
	}
	return *this;
}


// ��ӡ����
void SingleListTable::PrintList() const {
	Node* pPint = this->m_pHead->NextNode;

	//cout << "this->m_Len : " << this->m_Len << endl;
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;

		pPint = pPint->NextNode; // ����
	}
	cout << endl << "--------------------" << endl << endl;
}

// ͷ����
void SingleListTable::AddHeadNum(int num) {
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

// β����
void SingleListTable::AddEndNum(int num) {
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

// ����ָ��λ�ò���
void SingleListTable::AddIndexNum(int index, int num) {  // index ����1~10
	// 1.index�Ƿ�Ϸ�
	if (index<1 || index>this->m_Len) {
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

// ͷɾ��
void SingleListTable::DeleteHeadNum() {
	// ͷɾ��
	if (this->m_Len != 0) {  // ���Ȳ�Ϊ�㣬ɾ����һ��
		Node* pNum = nullptr;         // ����ڵ��ָ��

		// ָ��ı仯��ɾ��֮���ͷű�ɾ���Ľڵ�
		pNum = this->m_pHead->NextNode;  // ͷ������һ��
		this->m_pHead->NextNode = pNum->NextNode; // ͷ�������¸�

		cout << "ɾ��ͷ���� : " << pNum->number << endl;

		delete pNum;  // �ͷű�ɾ���Ľڵ�
		pNum = nullptr;

		// ���Ⱥ�ͷָ���������仯
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // ����Ϊ��
		// ����Ϊ
	}
}

// βɾ��
void SingleListTable::DeleteEndNum() {
	// βɾ��
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

		cout << "ɾ��β���� : " << pNum->number << endl;

		delete pNum;  // �ͷű�ɾ���Ľڵ�
		pNum = nullptr;

		// ���Ⱥ�ͷָ���������仯
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // ����Ϊ��
		// ����Ϊ
	}
}

// ����ָ��λ��ɾ��
void SingleListTable::DeleteIndexNum(int index) { // index ����1~10
	// 1.index�Ƿ�Ϸ�
	if (index<1 || index>this->m_Len) {
		cout << "----- �������Ϸ� -----" << endl << endl;
	}
	else {
		Node* pTemp = this->m_pHead;  // ��ʱָ��
		Node* pNum = nullptr;         // ����ڵ��ָ��

		// �ҵ���Ҫɾ����ǰһ��λ��
		for (int i = 1; i < index; i++) {
			pTemp = pTemp->NextNode;  // ����
		}

		// ɾ��֮���ͷű�ɾ���Ľڵ�
		pNum = pTemp->NextNode;       // ���汻ɾ���Ľڵ�
		pTemp->NextNode = pNum->NextNode;  // �Ͽ�����������һ���ڵ�

		cout << "ɾ������ : " << pNum->number << endl;

		delete pNum;  // �ͷű�ɾ���Ľڵ�
		pNum = nullptr;

		// ���ȸ���
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

// ɾ������ num ���ݵĵ�һ���ڵ�
void SingleListTable::DeleteNum(int num, bool flag) {
	Node* pTemp = this->m_pHead;  // ��ʱָ��
	Node* pNum = nullptr;         // ����ڵ��ָ��

	while (pTemp->NextNode != nullptr) {  // ����Ϊ��
		if (pTemp->NextNode->number == num) {
			/*********************
			* ɾ��Ŀ��ڵ㣬���ͷ�
			* ע��ɾ��֮���ǲ����ƶ���
			* ��Ϊ����Ľڵ㱻��������
			*********************/
			pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;

			cout << "ɾ������ : " << pNum->number << endl;
			delete pNum;
			pNum = nullptr;

			// ���ȸ���
			--this->m_Len;
			this->m_pHead->number = this->m_Len;

			if (!flag)break;  // flagΪtrue,ȫ��ɾ��
		}
		else {  // ��ɾ���ڵ�ʱ�ƶ�
			pTemp = pTemp->NextNode;
		}
	}
}

// ����
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
