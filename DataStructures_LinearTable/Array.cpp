#include"Array.h"

Array::Array() {
	this->m_MaxSize = 2;
	this->m_size = 0;
	this->m_p = new int[m_MaxSize];
}

Array::Array(int n, int num) {
	this->m_MaxSize = n;
	this->m_size = n - 2;
	this->m_p = new int[m_MaxSize];
	for (int i = 0; i < this->m_size; ++i) {
		this->m_p[i] = i + 1;
	}
}

Array::Array(int* Begin, int* End) {
	this->m_MaxSize = this->m_size = End - Begin;
	this->m_p = new int[m_MaxSize];
	int i = 0;
	for (int* p = Begin; p < End; ++p) {
		this->m_p[i++] = *p;
	}
}

Array::Array(const Array& other) {
	this->m_MaxSize = other.m_MaxSize;
	this->m_size = other.m_size;
	this->m_p = new int[m_MaxSize];
	memcpy(this->m_p, other.m_p, m_MaxSize * sizeof(int));
}

Array::~Array() {
	this->m_MaxSize = this->m_size = 0;
	delete[]m_p;
	m_p = nullptr;
}

// 清空数组，释放内存，指针置空
void Array::ClearArray() {
	this->m_MaxSize = this->m_size = 0;
	delete[]m_p;
	this->m_p = nullptr;
}

// 打印数组内容
void Array::PintArray() {
	cout << "--------------------" << endl;
	for (int i = 0; i < this->m_size; ++i) {
		cout <<"  " << this->m_p[i] << endl;
	}
	cout << "--------------------" << endl;
}

// 数组是否为空
bool Array::IsEmptyArray() {

	// 指针为空，数组被使用大小为零
	if (this->m_p == nullptr && 0 == this->m_size) {
		return true;
	}
	else {
		return false;
	}
}

// 末尾添加元素
void Array::EndAddArray(int num) {
	// 数组是否已满
	if (this->m_size >= this->m_MaxSize - 1) {  // 这里为什么要大于等于 （ -1 ）
		cout << "----- 增加了内存！ -----" << endl;
		// 申请新的内存
		int* p = new int[m_MaxSize];
		memcpy(p, this->m_p, m_size * sizeof(int));
		delete[]m_p;
		this->m_p = nullptr;

		this->m_p = new int[++this->m_MaxSize];
		memcpy(this->m_p, p, m_size * sizeof(int));
		delete[]p;
		p = nullptr;
	}
	// 末尾添加元素 num 
	this->m_p[this->m_size++] = num;  // 这里下标出现了问题
}

// 末尾删除元素
bool Array::EndDeleteArray() {
	// 数组为空
	if (this->IsEmptyArray()) {
		return false;
	}
	// 删除末尾元素，先置为负一吧
	this->m_p[--this->m_size] = -1;
	return true;
}

// 任意位置添加元素
void Array::AddArrayIndex(int num, int index) {
	// 数组是否已满
	if (this->m_size >= this->m_MaxSize - 1) {  // 这里为什么要大于等于 （ -1 ）
		cout << "----- 增加了内存！ -----" << endl;
		// 申请新的内存
		int* p = new int[m_MaxSize];
		memcpy(p, this->m_p, m_size * sizeof(int));
		delete[]m_p;
		this->m_p = nullptr;

		this->m_p = new int[++this->m_MaxSize];
		memcpy(this->m_p, p, m_size * sizeof(int));
		delete[]p;
		p = nullptr;
	}
	++this->m_size;
	//// index置为数组的下表形式
	//--index;
	//// 插入元素
	//for (int i = this->m_size - 2; i >= 0; --i) {
	//	if (i != index) { // 元素后移
	//		int temp = this->m_p[i];
	//		this->m_p[i] = this->m_p[i + 1];
	//		this->m_p[i + 1] = temp;
	//	}
	//	else {
	//		// 元素后移之后插入
	//		int temp = this->m_p[i];
	//		this->m_p[i] = this->m_p[i + 1];
	//		this->m_p[i + 1] = temp;

	//		this->m_p[index] = num;
	//		break;
	//	}
	//}
	for (int i = this->m_size - 1; i >= 0; --i) {
		if (i == index - 2) { // 需要把当前元素后移，所以减去二
			break;
		}
		else { // 元素后移
			int temp = this->m_p[i];
			this->m_p[i] = this->m_p[i + 1];
			this->m_p[i + 1] = temp;
		}
	}
	this->m_p[index - 1] = num;
}

// 删除满足条件的第一个元素
void Array::DeleteNumArray(int num) {
	// 找到元素删除，删除时候元素前移
	int i = 0;
	for (; i < this->m_size; ++i) {
		if (this->m_p[i] == num) {
			this->m_p[i] = -1;
			break;
		}
	}
	for (; i < this->m_size; ++i) {
		int temp = this->m_p[i];
		this->m_p[i] = this->m_p[i + 1];
		this->m_p[i + 1] = temp;
	}
	--this->m_size;
}

// 删除满足条件的所有元素
void Array::DeletrAllNumArray(int num) {
	int number = 0;
	for (int i = 0; i < this->m_size; ++i) {
		if (this->m_p[i] == num) {
			++number;
		}
	}
	for (int i = 0; i < number; ++i) {
		this->DeleteNumArray(num);
	}
}


/***************************************************
* 排序
* 默认小到大排序，num 为 0 时大到小排序
***************************************************/
void Array::SortArray(int num) {  // 这里的默认值可以不给


}
