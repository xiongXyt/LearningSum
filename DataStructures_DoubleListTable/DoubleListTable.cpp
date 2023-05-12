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
			this->m_pEnd->number = this->m_Len;
		}
		else {
			pTemp->NextNode = this->m_pHead->NextNode;
			pTemp->FrontNode = this->m_pHead;
			this->m_pHead->NextNode = pTemp;
			pTemp->NextNode->FrontNode = pTemp;

			// 节点数增加
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
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
			this->m_pEnd->number = this->m_Len;
		}
		else {
			pTemp->NextNode = this->m_pHead->NextNode;
			pTemp->FrontNode = this->m_pHead;
			this->m_pHead->NextNode = pTemp;
			pTemp->NextNode->FrontNode = pTemp;

			// 节点数增加
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
		}
	}
}

DoubleListTable::DoubleListTable(int* Begin, int* End) {
	// 初始化头指针
	this->m_pHead = new Node;
	this->m_pHead->number = this->m_Len = 0;
	this->m_pHead->FrontNode = this->m_pHead->NextNode = nullptr;

	// 初始化尾节点指针，指向头结点
	this->m_pEnd = new Node;
	this->m_pEnd->FrontNode = nullptr;
	this->m_pEnd->NextNode = this->m_pHead;
	this->m_pEnd->number = this->m_Len;

	for (int* pNum = Begin; pNum < End; ++pNum) {
		this->AddEndNum(*pNum);
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

// 头插入
void DoubleListTable::AddHeadNum(int num) {
	// 初始化新节点
	Node* pNew = new Node;
	pNew->number = num;
	pNew->FrontNode = pNew->NextNode = nullptr;

	if (0 == this->m_Len) {  // 链表为空
		// 挂载新的节点
		this->m_pHead->NextNode = pNew;
		pNew->FrontNode = this->m_pHead;

		// 尾指针指向最后一个节点
		this->m_pEnd->NextNode = pNew;

		// 节点数增加
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {
		pNew->NextNode = this->m_pHead->NextNode;
		pNew->FrontNode = this->m_pHead;
		this->m_pHead->NextNode = pNew;
		pNew->NextNode->FrontNode = pNew;

		// 节点数增加
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

// 尾插入
void DoubleListTable::AddEndNum(int num) {
	// 初始化新节点
	Node* pNew = new Node;
	pNew->number = num;
	pNew->FrontNode = pNew->NextNode = nullptr;

	// 挂载节点到链表
	this->m_pEnd->NextNode->NextNode = pNew;
	pNew->FrontNode = this->m_pEnd->NextNode;

	// 尾指针指向最后一个节点
	this->m_pEnd->NextNode = pNew;

	// 节点数增加
	++this->m_Len;
	this->m_pHead->number = this->m_Len;
	this->m_pEnd->number = this->m_Len;
}

// 按照指定位置插入
void DoubleListTable::AddIndexNum(int index, int num) {
	if (index > 0 && index <= this->m_Len + 1) {
		if (this->m_Len + 1 == index) {  // 最后一个位置
			this->AddEndNum(num);
		}
		else {
			// 初始化新节点
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

			// 节点数增加
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
		}
	}
	else {
		cout << "插入位置有误！" << endl;
	}
}

// 头删除
void DoubleListTable::DeleteHeadNum() {
	if (this->m_Len==0) {
		cout << "链表为空！" << endl;
	}
	else if (this->m_Len==1) {
		Node* pTemp = this->m_pHead->NextNode;

		this->m_pEnd->NextNode = this->m_pHead;
		this->m_pHead->NextNode = nullptr;

		cout << "删除 : " << pTemp->number << endl;

		delete pTemp;
		pTemp = nullptr;

		// 节点数减少
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {
		Node* pTemp = this->m_pHead->NextNode;

		this->m_pHead->NextNode = pTemp->NextNode;
		pTemp->NextNode->FrontNode = this->m_pHead;

		cout << "删除 : " << pTemp->number << endl;

		delete pTemp;
		pTemp = nullptr;

		// 节点数减少
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

// 尾删除
void DoubleListTable::DeleteEndNum() {
	if (0==this->m_Len) {
		cout << "链表为空！" << endl;
	}
	else if (1==this->m_Len) {
		Node* pTemp = this->m_pHead->NextNode;

		this->m_pEnd->NextNode = this->m_pHead;
		this->m_pHead->NextNode = nullptr;

		cout << "删除 : " << pTemp->number << endl;

		delete pTemp;
		pTemp = nullptr;

		// 节点数减少
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
	else {
		Node* pTemp = this->m_pEnd->NextNode;

		this->m_pEnd->NextNode = pTemp->FrontNode;
		this->m_pEnd->NextNode->NextNode = nullptr;

		cout << "删除 : " << pTemp->number << endl;

		delete pTemp;
		pTemp = nullptr;

		// 节点数减少
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
		this->m_pEnd->number = this->m_Len;
	}
}

// 按照指定位置删除
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

			cout << "删除 : " << pTemp->number << endl;

			delete pTemp;
			pTemp = nullptr;

			// 节点数减少
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;
		}
	}
	else {
		cout << "插入位置有误！" << endl;
	}
}

// 删除含有 num 数据的第一个节点
void DoubleListTable::DeleteNum(int num, bool flag) {  // flag为true,全部删除
	Node* pTemp = this->m_pHead;  // 临时指针
	Node* pNum = nullptr;         // 保存节点的指针

	while (pTemp->NextNode != nullptr) {  // 链表不为空
		if (pTemp->NextNode == this->m_pEnd->NextNode &&
			pTemp->NextNode->number == num) {
			this->DeleteEndNum();
		}
		else if (pTemp->NextNode->number == num) {
			/*********************
			* 删除目标节点，并释放
			* 注意删除之后是不用移动的
			* 因为后面的节点被接上来了
			*********************/
			Node* pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;
			pNum->NextNode->FrontNode = pTemp;

			cout << "删除 : " << pNum->number << endl;

			delete pNum;
			pNum = nullptr;

			// 节点数减少
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
			this->m_pEnd->number = this->m_Len;

			if (!flag)break;  // flag为true,全部删除
		}
		else {  // 不删除节点时移动
			cout << pTemp->NextNode->number << endl;
			pTemp = pTemp->NextNode;
		}
	}
}

// 排序
void DoubleListTable::Sort() {
	cout << "功能还没有实现" << endl;
}
