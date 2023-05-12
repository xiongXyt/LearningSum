#include"DoubleListTable.h"

/*
* 构造函数全部采用头插法
*/
DoubleListTable::DoubleListTable() {
	// 初始化头指针
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// 初始化尾节点指针，指向头结点
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;
}

DoubleListTable::DoubleListTable(int num) {
	// 初始化头指针
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// 初始化尾节点指针，指向头结点
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;
	
	for (int i = num; i >= 1; --i) {
		// 新节点
		Node* pTemp = new Node;
		pTemp->number = i;
		pTemp->FrontNode = pTemp->NextNode = nullptr;
		if (0 == this->m_Len) {  // 链表为空
			// 挂载新的节点
			this->m_pHead->NextNode = pTemp;
			pTemp->FrontNode = this->m_pHead;
			
			// 尾指针指向最后一个节点
			this->m_pEnd->NextNode = pTemp;

			// 节点数增加
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
		else {
			pTemp->NextNode = this->m_pHead->NextNode;
			pTemp->FrontNode = this->m_pHead;
			this->m_pHead->NextNode = pTemp;
			pTemp->NextNode->FrontNode = pTemp;

			// 节点数增加
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
}

DoubleListTable::DoubleListTable(int n, int num) {
	// 初始化头指针
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// 初始化尾节点指针，指向头结点
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;

	for (int i = n; i >= 1; --i) {
		// 新节点
		Node* pTemp = new Node;
		pTemp->number = num;
		pTemp->FrontNode = pTemp->NextNode = nullptr;
		if (0 == this->m_Len) {  // 链表为空
			// 挂载新的节点
			this->m_pHead->NextNode = pTemp;
			pTemp->FrontNode = this->m_pHead;

			// 尾指针指向最后一个节点
			this->m_pEnd->NextNode = pTemp;

			// 节点数增加
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
		else {
			pTemp->NextNode = this->m_pHead->NextNode;
			pTemp->FrontNode = this->m_pHead;
			this->m_pHead->NextNode = pTemp;
			pTemp->NextNode->FrontNode = pTemp;

			// 节点数增加
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
}

DoubleListTable::DoubleListTable(const DoubleListTable& other) {
	// 初始化头指针
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// 初始化尾节点指针，指向头结点
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;

	Node* pNum = other.m_pHead->NextNode;

	// 这里采用尾插法
	while (pNum!=nullptr) {
		// 新增节点初始化，并赋值
		Node* pTemp = new Node;
		pTemp->number = pNum->number;
		pTemp->FrontNode = pTemp->NextNode = nullptr;

		// 挂载节点到链表
		this->m_pEnd->NextNode->NextNode = pTemp;
		pTemp->FrontNode = this->m_pEnd->NextNode;

		// 尾指针指向最后一个节点
		this->m_pEnd->NextNode = pTemp;

		// 节点数增加
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;

		// pNum后移
		pNum = pNum->NextNode;
	}
}

DoubleListTable::~DoubleListTable() {
	// 遍历释放，也就是一个一个的释放申请的内存
	Node* pTemp = nullptr;

	// 释放尾节点
	delete this->m_pEnd;
	this->m_pEnd = nullptr;

	// 从前向后释放
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
	// 这里采用尾插法
	while (pOther != nullptr) {
		// 新增节点初始化，并赋值
		Node* pTemp = new Node;
		pTemp->number = pOther->number;
		pTemp->FrontNode = pTemp->NextNode = nullptr;

		// 挂载节点到链表
		this->m_pEnd->NextNode->NextNode = pTemp;
		pTemp->FrontNode = this->m_pEnd->NextNode;

		// 尾指针指向最后一个节点
		this->m_pEnd->NextNode = pTemp;

		// 节点数增加
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;

		// pOther后移
		pOther = pOther->NextNode;
	}
	return *this;
}

DoubleListTable DoubleListTable::operator=(const DoubleListTable& other) {
	// 初始化头指针
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// 初始化尾节点指针，指向头结点
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;

	Node* pNum = other.m_pHead->NextNode;

	// 这里采用尾插法
	while (pNum != nullptr) {
		// 新增节点初始化，并赋值
		Node* pTemp = new Node;
		pTemp->number = pNum->number;
		pTemp->FrontNode = pTemp->NextNode = nullptr;

		// 挂载节点到链表
		this->m_pEnd->NextNode->NextNode = pTemp;
		pTemp->FrontNode = this->m_pEnd->NextNode;

		// 尾指针指向最后一个节点
		this->m_pEnd->NextNode = pTemp;

		// 节点数增加
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;

		// pNum后移
		pNum = pNum->NextNode;
	}
	return *this;
}

// 打印函数
void DoubleListTable::PrintTable() {
	Node* pPint = this->m_pHead->NextNode;

	cout << "this->m_Len : " << this->m_Len << endl;
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;
		pPint = pPint->NextNode; // 后移
	}
	cout << endl << "--------------------" << endl << endl;
}
