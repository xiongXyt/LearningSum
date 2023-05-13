#include"SingleListTable.h"

/***********************************************************************
* 函 数 名：__InitList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：初始化链表空头节点
*			-- 2 -- ：链表长度为零
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：编写函数
***********************************************************************/
void SingleListTable::__InitList() {
	// 初始化链表空头节点
	this->m_pHead = new Node;
	this->m_pHead->NextNode = nullptr;
	this->m_pHead->number = this->m_Len = 0;  // 链表的长度为 零
}

/***********************************************************************
* 函 数 名：SingleListTable()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：初始化链表空头节点
*			-- 2 -- ：链表长度为零
*			-- 3 -- ：无参数构造
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：初始化链表空头节点，集成到 __InitList() 函数
***********************************************************************/
SingleListTable::SingleListTable() {
	this->__InitList();  // 初始化链表
}

/***********************************************************************
* 函 数 名：SingleListTable(int n)
* 形 参 表：
*			1 ) n -->( int ) : 需要初始化链表的节点个数
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化链表空头节点
*			-- 3 -- ：构造 1~n 的有序链表
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：初始化链表空头节点，集成到 __InitList() 函数
*					2 ：尾插法，集成到 AddEndNum(int num) 函数
***********************************************************************/
SingleListTable::SingleListTable(int n) {
	this->__InitList();  // 初始化链表

	for (int i = 0; i < n; i++) {
		this->AddEndNum(i + 1);  // 尾插法
	}
}

/***********************************************************************
* 函 数 名：SingleListTable(int n, int num)
* 形 参 表：
*			1 ) n ---->( int ) : 需要初始化链表的节点个数
*			2 ) num -->( int ) : 链表每个节点数据域的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化链表空头节点
*			-- 3 -- ：构造值都为 num 的链表
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：初始化链表空头节点，集成到 __InitList() 函数
*					2 ：尾插法，集成到 AddEndNum(int num) 函数
***********************************************************************/
SingleListTable::SingleListTable(int n, int num) {
	this->__InitList();  // 初始化链表

	for (int i = 0; i < n; i++) {
		this->AddEndNum(num);  // 尾插法
	}
}

/***********************************************************************
* 函 数 名：DoubleListTable(int* Begin, int* End)
* 形 参 表：
*			1 ) Begin --->( int* ) : 连续内存的第一个地址
*			2 ) End   --->( int* ) : 连续内存的最后一个地址
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：有参构造
*			-- 2 -- ：初始化链表空头节点
*			-- 3 -- ：构造值为一段连续内存内的值的链表
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：初始化链表空头节点，集成到 __InitList() 函数
*					2 ：尾插法，集成到 AddEndNum(int num) 函数
***********************************************************************/
SingleListTable::SingleListTable(int* Begin, int* End) {
	this->__InitList();  // 初始化链表

	for (int* num = Begin; num < End; ++num) {
		this->AddEndNum(*num);  // 尾插法
	}
}

/***********************************************************************
* 函 数 名：SingleListTable(const SingleListTable& other)
* 形 参 表：
*			1 ) other -->( const SingleListTable& ) : 另外一个常链表类
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：复制构造函数
*			-- 2 -- ：初始化链表空头节点
*			-- 3 -- ：深复制一个只有值相同的链表
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：长度从赋值方式改为计数
*					2 ：初始化链表空头节点，集成到 __InitList() 函数
*					2 ：尾插法，集成到 AddEndNum(int num) 函数
***********************************************************************/
SingleListTable::SingleListTable(const SingleListTable& other) {
	this->__InitList();  // 初始化链表

	Node* pother = other.m_pHead;  // 临时保存传入的链表指针

	// 从头开始复制
	while (pother->NextNode != nullptr) {  // 临时保存传入的链表指针不为空
		this->AddEndNum(pother->NextNode->number);  // 尾插法

		// 节点指针后移
		pother = pother->NextNode;
	}
}

/***********************************************************************
* 函 数 名：~SingleListTable()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：析构函数，手动释放申请的内存
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
SingleListTable::~SingleListTable() {
	Node* pTemp = nullptr;  // 临时保存节点

	// 从前向后遍历释放
	while (this->m_pHead != nullptr) {
		pTemp = this->m_pHead;
		this->m_pHead = this->m_pHead->NextNode;
		delete pTemp;
		pTemp = nullptr;
	}

	// 长度置为零
	this->m_Len = 0;
}

/***********************************************************************
* 函 数 名：operator+(const SingleListTable& other)
* 形 参 表：
*			1 ) other -->( const SingleListTable& ) : 另外一个常链表类
* 返 回 值：
*			1 ) SingleListTable : 返回当面的链表
* 函数功能：
*			-- 1 -- ：加法重载函数
*			-- 2 -- ：尾插法
*			-- 3 -- ：当前链表的最后一节点接一个链表的值
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
SingleListTable SingleListTable::operator+(const SingleListTable& other) {
	Node* pHead = this->m_pHead;  // 保存头指针

	// 移动到最后一个节点
	while (pHead->NextNode != nullptr) {
		pHead = pHead->NextNode;
	}

	// 挂载节点到最后一个
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

/***********************************************************************
* 函 数 名：operator=(const SingleListTable& other)
* 形 参 表：
*			1 ) other -->( const SingleListTable& ) : 另外一个常链表类
* 返 回 值：
*			1 ) SingleListTable : 返回当前的链表
* 函数功能：
*			-- 1 -- ：等于重载函数
*			-- 2 -- ：尾插法
*			-- 3 -- ：当前链表的值为另外一个链表的值，深拷贝
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：尾插法，集成到 AddEndNum(int num) 函数
***********************************************************************/
SingleListTable SingleListTable::operator=(const SingleListTable& other) {
	this->__InitList();  // 初始化链表

	Node* pother = other.m_pHead;  // 临时保存传入的链表指针

	// 从头开始复制
	while (pother->NextNode != nullptr) {  // 临时保存传入的链表指针不为空
		this->AddEndNum(pother->NextNode->number);  // 尾插法

		// 节点指针后移
		pother = pother->NextNode;
	}
	return *this;
}

/***********************************************************************
* 函 数 名：PrintList()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：从头节点下一个节点打印全部链表的值
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：新增加链表长度的打印
***********************************************************************/
void SingleListTable::PrintList() const {
	Node* pPint = this->m_pHead->NextNode;  // 保存链表头节点的下一个节点

	// 打印链表长度
	cout << "m_Len : " << this->m_Len << endl;

	// 遍历打印链表
	cout << "--------------------" << endl << endl;
	for (int i = 0; i < this->m_Len; ++i) {
		cout << pPint->number << endl;
		pPint = pPint->NextNode; // 后移
	}
	cout << endl << "--------------------" << endl << endl;
}

/***********************************************************************
* 函 数 名：AddHeadNum(int num)
* 形 参 表：
*			1 ) num -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值到链表的头部
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void SingleListTable::AddHeadNum(int num) {
	// 新节点
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

/***********************************************************************
* 函 数 名：AddEndNum(int num)
* 形 参 表：
*			1 ) num -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值到链表的尾部
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void SingleListTable::AddEndNum(int num) {
	// 新节点
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

/***********************************************************************
* 函 数 名：AddIndexNum(int index, int num)
* 形 参 表：
*			1 ) index -->( int ) : 插入链表的位置
*			2 ) num -->( int ) : 插入链表的值
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：插入新值 num 到链表的 index 位置
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：就是写了注释
***********************************************************************/
void SingleListTable::AddIndexNum(int index, int num) {
	if (index<1 || index>this->m_Len) {  // 索引有误
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

/***********************************************************************
* 函 数 名：DeleteHeadNum()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表的一个节点
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void SingleListTable::DeleteHeadNum() {
	if (this->m_Len != 0) {  // 长度不为零，删除第一个
		Node* pNum = nullptr;         // 保存节点的指针

		// 指针的变化，删除之后释放被删除的节点
		pNum = this->m_pHead->NextNode;  // 头结点的下一个
		this->m_pHead->NextNode = pNum->NextNode; // 头结点的下下个

		// 打印被删除的节点信息
		cout << "删除 : " << pNum->number << endl;
		cout << "位置 : 1 " << endl;

		// 释放被删除的节点
		delete pNum;  
		pNum = nullptr;

		// 长度和头指针的数据域变化
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 长度为零
		cout << "链表为空！" << endl;
	}
}

/***********************************************************************
* 函 数 名：DeleteIndexNum(int index)
* 形 参 表：
*			1 ) : index -->( int ) 删除链表的位置
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表index位置的节点
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void SingleListTable::DeleteEndNum() {
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

		// 打印被删除的节点信息
		cout << "删除 : " << pNum->number << endl;
		cout << "位置 : " << this->m_Len << " " << endl;

		// 释放被删除的节点
		delete pNum;  
		pNum = nullptr;

		// 长度和头指针的数据域变化
		--this->m_Len;
		this->m_pHead->number = this->m_Len;
	}
	else {  // 长度为零
		cout << "链表为空！" << endl;
	}
}

/***********************************************************************
* 函 数 名：DeleteIndexNum(int index)
* 形 参 表：
*			1 ) : index -->( int ) 删除链表的位置
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表index位置的节点
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
*					2 ：新增链表长度为零的判断
***********************************************************************/
void SingleListTable::DeleteIndexNum(int index) {
	if (0 != this->m_Len) {  // 长度不为零
		if (index<1 || index>this->m_Len) {  // 索引有误
			cout << "----- 索引不合法 -----" << endl << endl;
		}
		else {  // 索引正确
			Node* pTemp = this->m_pHead;  // 临时指针
			Node* pNum = nullptr;         // 保存节点的指针

			// 找到需要删除的前一个位置
			for (int i = 1; i < index; i++) {
				pTemp = pTemp->NextNode;  // 后移
			}

			// 删除之后释放被删除的节点
			pNum = pTemp->NextNode;       // 保存被删除的节点
			pTemp->NextNode = pNum->NextNode;  // 断开并链接下下一个节点

			// 打印被删除的节点信息
			cout << "删除 : " << pNum->number << endl;
			cout << "位置 : " << index << " " << endl;

			delete pNum;  // 释放被删除的节点
			pNum = nullptr;

			// 长度更改
			--this->m_Len;
			this->m_pHead->number = this->m_Len;
		}
	}
	else {  // 长度为零
		cout << "链表为空！" << endl;
	}

}

/***********************************************************************
* 函 数 名：DeleteNum(int num, bool flag)
* 形 参 表：
*			1 ) : num --->( int ) 需删除的值
*			2 ) : flag -->( int ) 全部删除链表num值的标志
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：删除链表 num 值的第一个节点
*			-- 2 -- ：flag ( true ) 信息全部删除链表 num 值的节点
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释、增加了链表被删除的位置信息
***********************************************************************/
void SingleListTable::DeleteNum(int num, bool flag) {  // flag为true,全部删除
	Node* pTemp = this->m_pHead;  // 临时指针
	Node* pNum = nullptr;         // 保存节点的指针

	int posindex = 1;  // 被删除节点位置

	while (pTemp->NextNode != nullptr) {  // 链表不为空
		if (pTemp->NextNode->number == num) {
			/*********************
			* 删除目标节点，并释放
			* 注意删除之后是不用移动的
			* 因为后面的节点被接上来了
			*********************/

			// 断开需删除节点
			pNum = pTemp->NextNode;
			pTemp->NextNode = pNum->NextNode;

			// 打印被删除的节点信息
			cout << "删除 : " << pNum->number << endl;
			cout << "位置 : " << posindex << " " << endl;

			// 释放被断开的节点
			delete pNum;
			pNum = nullptr;

			// 长度更改
			--this->m_Len;
			this->m_pHead->number = this->m_Len;

			if (!flag)break;  // flag为true,全部删除
		}
		else {  // 不删除节点时移动
			pTemp = pTemp->NextNode;

			// 删除节点位置信息增加一
			++posindex;
		}
	}
}

/***********************************************************************
* 函 数 名：Sort()
* 形 参 表：None
* 返 回 值：None
* 函数功能：
*			-- 1 -- ：冒泡排序，递增
* 最后更改：
*			更改时间：【 2023.5.13 】
*			更改人员：xyt
*			更改内容：
*					1 ：写了注释
***********************************************************************/
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
