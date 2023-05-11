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

// ������飬�ͷ��ڴ棬ָ���ÿ�
void Array::ClearArray() {
	this->m_MaxSize = this->m_size = 0;
	delete[]m_p;
	this->m_p = nullptr;
}

// ��ӡ��������
void Array::PintArray() {
	cout << "--------------------" << endl;
	for (int i = 0; i < this->m_size; ++i) {
		cout <<"  " << this->m_p[i] << endl;
	}
	cout << "--------------------" << endl;
}

// �����Ƿ�Ϊ��
bool Array::IsEmptyArray() {

	// ָ��Ϊ�գ����鱻ʹ�ô�СΪ��
	if (this->m_p == nullptr && 0 == this->m_size) {
		return true;
	}
	else {
		return false;
	}
}

// ĩβ���Ԫ��
void Array::EndAddArray(int num) {
	// �����Ƿ�����
	if (this->m_size >= this->m_MaxSize - 1) {  // ����ΪʲôҪ���ڵ��� �� -1 ��
		cout << "----- �������ڴ棡 -----" << endl;
		// �����µ��ڴ�
		int* p = new int[m_MaxSize];
		memcpy(p, this->m_p, m_size * sizeof(int));
		delete[]m_p;
		this->m_p = nullptr;

		this->m_p = new int[++this->m_MaxSize];
		memcpy(this->m_p, p, m_size * sizeof(int));
		delete[]p;
		p = nullptr;
	}
	// ĩβ���Ԫ�� num 
	this->m_p[this->m_size++] = num;  // �����±����������
}

// ĩβɾ��Ԫ��
bool Array::EndDeleteArray() {
	// ����Ϊ��
	if (this->IsEmptyArray()) {
		return false;
	}
	// ɾ��ĩβԪ�أ�����Ϊ��һ��
	this->m_p[--this->m_size] = -1;
	return true;
}

// ����λ�����Ԫ��
void Array::AddArrayIndex(int num, int index) {
	// �����Ƿ�����
	if (this->m_size >= this->m_MaxSize - 1) {  // ����ΪʲôҪ���ڵ��� �� -1 ��
		cout << "----- �������ڴ棡 -----" << endl;
		// �����µ��ڴ�
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
	//// index��Ϊ������±���ʽ
	//--index;
	//// ����Ԫ��
	//for (int i = this->m_size - 2; i >= 0; --i) {
	//	if (i != index) { // Ԫ�غ���
	//		int temp = this->m_p[i];
	//		this->m_p[i] = this->m_p[i + 1];
	//		this->m_p[i + 1] = temp;
	//	}
	//	else {
	//		// Ԫ�غ���֮�����
	//		int temp = this->m_p[i];
	//		this->m_p[i] = this->m_p[i + 1];
	//		this->m_p[i + 1] = temp;

	//		this->m_p[index] = num;
	//		break;
	//	}
	//}
	for (int i = this->m_size - 1; i >= 0; --i) {
		if (i == index - 2) { // ��Ҫ�ѵ�ǰԪ�غ��ƣ����Լ�ȥ��
			break;
		}
		else { // Ԫ�غ���
			int temp = this->m_p[i];
			this->m_p[i] = this->m_p[i + 1];
			this->m_p[i + 1] = temp;
		}
	}
	this->m_p[index - 1] = num;
}

// ɾ�����������ĵ�һ��Ԫ��
void Array::DeleteNumArray(int num) {
	// �ҵ�Ԫ��ɾ����ɾ��ʱ��Ԫ��ǰ��
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

// ɾ����������������Ԫ��
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
* ����
* Ĭ��С��������num Ϊ 0 ʱ��С����
***************************************************/
void Array::SortArray(int num) {  // �����Ĭ��ֵ���Բ���


}
