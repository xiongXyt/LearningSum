#include"SingleListTable.h"

/*
* 无参构造，
*/
SingleListTable::SingleListTable() {
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;         // 下一个位置为 空
	this->m_pHead->number = this->m_Len = 0;   // 链表的长度为 零
}

SingleListTable::SingleListTable(int n) {
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;            // 下一个位置为 空
	this->m_pHead->number = this->m_Len = 0;      // 链表的长度为 零

	for (int i = 0; i < n; i++) {
		Node* pNew = new Node;
		pNew->number = i + 1;
		pNew->NextNode = nullptr;

		// 头插法
		/*
		* if (0 == this->m_Len) {  // 长度为零，直接挂在第一个位置
		*
		* 	// 指针的变化
		* 	this->m_pHead->NextNode = pNew;  // 头结点的下一个为 pNew
		*
		* 	// 长度和头指针的数据域变化
		* 	++this->m_Len;
		* 	this->m_pHead->number = this->m_Len;
		* }
		* else {  // 头插在头指针上面做修改
		*
		* 	// 指针的变化
		* 	pNew->NextNode = this->m_pHead->NextNode;  // pNew 下一个节点为第一个节点
		* 	this->m_pHead->NextNode = pNew;            // 头结点的下一个为 pNew
		*
		* 	// 长度和头指针的数据域变化
		* 	++this->m_Len;
		* 	this->m_pHead->number = this->m_Len;
		* }
		*/

		// 尾插法
		if (0 == this->m_Len) {  // 长度为零，直接挂在第一个位置

			// 指针的变化
			this->m_pHead->NextNode = pNew;  // 头结点的下一个为 pNew

			// 长度和头指针的数据域变化
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
		else {  // 尾插法在尾指针做修改
			Node* pTemp = this->m_pHead;

			// 移动到链表最后的位置
			while (pTemp->NextNode != nullptr) {
				pTemp = pTemp->NextNode;  // 后移
			}

			// 插入
			pTemp->NextNode = pNew;

			// 长度和头指针的数据域变化
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
}

SingleListTable::SingleListTable(int n, int num) {
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;         // 下一个位置为 空
	this->m_pHead->number = this->m_Len = 0;   // 链表的长度为 零

	for (int i = 0; i < n; i++) {
		Node* pNew = new Node;
		pNew->number = num;
		pNew->NextNode = nullptr;

		// 尾插法
		if (0 == this->m_Len) {  // 长度为零，直接挂在第一个位置

			// 指针的变化
			this->m_pHead->NextNode = pNew;  // 头结点的下一个为 pNew

			// 长度和头指针的数据域变化
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
		else {  // 尾插法在尾指针做修改
			Node* pTemp = this->m_pHead;

			// 移动到链表最后的位置
			while (pTemp->NextNode != nullptr) {
				pTemp = pTemp->NextNode;  // 后移
			}

			// 插入
			pTemp->NextNode = pNew;

			// 长度和头指针的数据域变化
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
}

SingleListTable::SingleListTable(int* Begin, int* End) {
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;         // 下一个位置为 空
	this->m_pHead->number = this->m_Len = 0;   // 链表的长度为 零

	for (int* num = Begin; num < End; ++num) {
		Node* pNew = new Node;
		pNew->number = *num;
		pNew->NextNode = nullptr;

		// 尾插法
		if (0 == this->m_Len) {  // 长度为零，直接挂在第一个位置

			// 指针的变化
			this->m_pHead->NextNode = pNew;  // 头结点的下一个为 pNew

			// 长度和头指针的数据域变化
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
		else {  // 尾插法在尾指针做修改
			Node* pTemp = this->m_pHead;

			// 移动到链表最后的位置
			while (pTemp->NextNode != nullptr) {
				pTemp = pTemp->NextNode;  // 后移
			}

			// 插入
			pTemp->NextNode = pNew;

			// 长度和头指针的数据域变化
			++this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
}

SingleListTable::SingleListTable(const SingleListTable& other) {
	// 初始化
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;
	this->m_pHead->number = this->m_Len = other.m_Len;

	Node* pTemp = this->m_pHead;   // 临时保存当前链表指针
	Node* pother = other.m_pHead;  // 临时保存传入的链表指针
	Node* pNum = nullptr;          // 保存节点指针

	// 从头开始复制
	while (pother->NextNode != nullptr) {  // 临时保存传入的链表指针不为空
		// 初始化节点，并手动赋值
		pNum = new Node;
		pNum->number = pother->NextNode->number;
		pNum->NextNode = nullptr;

		pTemp->NextNode = pNum;     // 挂在最后的位置

		// 两个指针一起后移
		pTemp = pTemp->NextNode;
		pother = pother->NextNode;
	}
}

SingleListTable::~SingleListTable() {
	// 遍历释放，也就是一个一个的释放申请的内存
	Node* pTemp = nullptr;

	// 从前向后释放
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	this->m_Len = 0;

	// 从后向前释放
	/*
	* 好像找不到前面的节点，这里考虑的是使用双向链表。
	*/
}
// 加法运算符重载
SingleListTable SingleListTable::operator+(const SingleListTable& other) {
	Node* pHead = this->m_pHead;
	// 指针后移
	while (pHead->NextNode != nullptr) {
		pHead = pHead->NextNode;
	}
	for (Node* pOther = other.m_pHead->NextNode; pOther != nullptr; pOther=pOther->NextNode) {
		// 获取新链表的数据
		Node* pNum = new Node;
		pNum->number = pOther->number;
		pNum->NextNode = nullptr;

		//挂载新节点到最后节点
		pHead->NextNode = pNum;
		pHead = pHead->NextNode;
	}
	return *this;
}

// 等于运算符重载
SingleListTable SingleListTable::operator=(const SingleListTable& other) {
	// 初始化
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;
	this->m_pHead->number = this->m_Len = other.m_Len;

	Node* pTemp = this->m_pHead;   // 临时保存当前链表指针
	Node* pother = other.m_pHead;  // 临时保存传入的链表指针
	Node* pNum = nullptr;          // 保存节点指针

	// 从头开始复制
	while (pother->NextNode != nullptr) {  // 临时保存传入的链表指针不为空
		// 初始化节点，并手动赋值
		pNum = new Node;
		pNum->number = pother->NextNode->number;
		pNum->NextNode = nullptr;

		pTemp->NextNode = pNum;     // 挂在最后的位置

		// 两个指针一起后移
		pTemp = pTemp->NextNode;
		pother = pother->NextNode;
	}
	return *this;
}


// 打印链表
void SingleListTable::PrintList() const {
	Node* pPint = this->m_pHead->NextNode;

	//cout << "this->m_Len : " << this->m_Len << endl;
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;

		pPint = pPint->NextNode; // 后移
	}
	cout << endl << "--------------------" << endl << endl;
}

// 头插入
void SingleListTable::AddHeadNum(int num) {
	Node* pNew = new Node;
	pNew->number = num;
	pNew->NextNode = nullptr;

	// 头插法
	if (0 == this->m_Len) {  // 长度为零，直接挂在第一个位置

		// 指针的变化
		this->m_pHead->NextNode = pNew;  // 头结点的下一个为 pNew

		// 长度和头指针的数据域变化
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 头插在头指针上面做修改

		// 指针的变化
		pNew->NextNode = this->m_pHead->NextNode;  // pNew 下一个节点为第一个节点
		this->m_pHead->NextNode = pNew;            // 头结点的下一个为 pNew

		// 长度和头指针的数据域变化
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

// 尾插入
void SingleListTable::AddEndNum(int num) {
	Node* pNew = new Node;
	pNew->number = num;
	pNew->NextNode = nullptr;

	// 尾插法
	if (0 == this->m_Len) {  // 长度为零，直接挂在第一个位置

		// 指针的变化
		this->m_pHead->NextNode = pNew;  // 头结点的下一个为 pNew

		// 长度和头指针的数据域变化
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 尾插法在尾指针做修改
		Node* pTemp = this->m_pHead;

		// 移动到链表最后的节点
		while (pTemp->NextNode != nullptr) {
			pTemp = pTemp->NextNode;  // 后移
		}

		// 插入
		pTemp->NextNode = pNew;

		// 长度和头指针的数据域变化
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

// 按照指定位置插入
void SingleListTable::AddIndexNum(int index, int num) {  // index 符合1~10
	// 1.index是否合法
	if (index<1 || index>this->m_Len) {
		cout << "----- 索引不合法 -----" << endl << endl;
	}
	else {
		Node* pTemp = this->m_pHead;  // 临时指针

		// 需要插入的节点初始化
		Node* pNum = new Node;
		pNum->number = num;
		pNum->NextNode = nullptr;

		// 找到需要插入的前一个位置
		for (int i = 1; i < index; i++) {
			pTemp = pTemp->NextNode;  // 后移
		}

		// 插入
		pNum->NextNode = pTemp->NextNode; // 先挂上去
		pTemp->NextNode = pNum;           // 在链接

		// 长度更改
		++this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

// 头删除
void SingleListTable::DeleteHeadNum() {
	// 头删除
	if (this->m_Len != 0) {  // 长度不为零，删除第一个
		Node* pNum = nullptr;         // 保存节点的指针

		// 指针的变化，删除之后释放被删除的节点
		pNum = this->m_pHead->NextNode;  // 头结点的下一个
		this->m_pHead->NextNode = pNum->NextNode; // 头结点的下下个

		cout << "删除头数据 : " << pNum->number << endl;

		delete pNum;  // 释放被删除的节点
		pNum = nullptr;

		// 长度和头指针的数据域变化
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 长度为零
		// 不作为
	}
}

// 尾删除
void SingleListTable::DeleteEndNum() {
	// 尾删除
	if (0 != this->m_Len) {  // 长度不为零，删除最后一个
		Node* pNum = nullptr;      // 保存节点的指针

		Node* pTemp = this->m_pHead;   // 临时指针

		// 移动到链表最后节点的前一个位置
		while (pTemp->NextNode->NextNode != nullptr) {
			pTemp = pTemp->NextNode;  // 后移
		}

		// 指针的变化，删除之后释放被删除的节点
		pNum = pTemp->NextNode;
		pTemp->NextNode = nullptr;

		cout << "删除尾数据 : " << pNum->number << endl;

		delete pNum;  // 释放被删除的节点
		pNum = nullptr;

		// 长度和头指针的数据域变化
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 长度为零
		// 不作为
	}
}

// 按照指定位置删除
void SingleListTable::DeleteIndexNum(int index) { // index 符合1~10
	// 1.index是否合法
	if (index<1 || index>this->m_Len) {
		cout << "----- 索引不合法 -----" << endl << endl;
	}
	else {
		Node* pTemp = this->m_pHead;  // 临时指针
		Node* pNum = nullptr;         // 保存节点的指针

		// 找到需要删除的前一个位置
		for (int i = 1; i < index; i++) {
			pTemp = pTemp->NextNode;  // 后移
		}

		// 删除之后释放被删除的节点
		pNum = pTemp->NextNode;       // 保存被删除的节点
		pTemp->NextNode = pNum->NextNode;  // 断开并链接下下一个节点

		cout << "删除数据 : " << pNum->number << endl;

		delete pNum;  // 释放被删除的节点
		pNum = nullptr;

		// 长度更改
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
}

// 删除含有 num 数据的第一个节点
void SingleListTable::DeleteNum(int num, bool flag) {
	Node* pTemp = this->m_pHead;  // 临时指针
	Node* pNum = nullptr;         // 保存节点的指针

	while (pTemp->NextNode != nullptr) {  // 链表不为空
		if (pTemp->NextNode->number == num) {
			/*********************
			* 删除目标节点，并释放
			* 注意删除之后是不用移动的
			* 因为后面的节点被接上来了
			*********************/
			pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;

			cout << "删除数据 : " << pNum->number << endl;
			delete pNum;
			pNum = nullptr;

			// 长度更改
			--this->m_Len;
			this->m_pHead->number = this->m_Len;

			if (!flag)break;  // flag为true,全部删除
		}
		else {  // 不删除节点时移动
			pTemp = pTemp->NextNode;
		}
	}
}

// 排序
void SingleListTable::Sort() {
	for (int i = 1; i < this->m_Len; i++) {  // 趟数
		Node* pTemp01 = this->m_pHead;
		for (int j = 0; j < this->m_Len - i; j++) {  // 每趟比较的次数
			Node* pTemp02 = pTemp01->NextNode;
			if (pTemp01->NextNode->number > pTemp02->NextNode->number) {
				// 交换
				pTemp01->NextNode = pTemp02->NextNode;
				pTemp02->NextNode = pTemp01->NextNode->NextNode;
				pTemp01->NextNode->NextNode = pTemp02;
				// 后移
				pTemp01 = pTemp01->NextNode;
			}
			else {
				// 后移
				pTemp01 = pTemp01->NextNode;
			}
		}
	}
}
