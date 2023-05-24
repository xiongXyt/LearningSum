#ifndef _OPERATOROVERLOAD_H_
#define _OPERATOROVERLOAD_H_

#include<iostream>
using namespace std;

template<class T>
class OperatorOverload {
public:
	T m_num;
public:

	typedef OperatorOverload<T> operatorol;

	OperatorOverload() {
		this->m_num = T();  // 这里是不是默认的初始化方法嘞，有点搞不清
	}

	OperatorOverload(T num) {
		this->m_num = num;
	}

	operatorol operator+(
		const operatorol& other) {
		operatorol temp = *this;
		temp = this->m_num + other.m_num;
		return temp;
	}

	operatorol operator-(
		const operatorol& other) {
		operatorol temp = *this;
		temp = this->m_num - other.m_num;
		return temp;
	}

	operatorol& operator++() {
		this->m_num++;
		return *this;
	}

	operatorol operator++(int) {
		operatorol temp = *this;
		this->m_num++;
		return temp;
	}

	operatorol operator=(
		const operatorol& other) {
		this->m_num = other.m_num;
		return *this;
	}

	bool operator!=(
		const operatorol& other) {
		return this->m_num != other.m_num;
	}

	bool operator==(
		const operatorol& other) {
		return this->m_num == other.m_num;
	}

	friend ostream& operator<<(
		ostream& output, operatorol& r) {
		output << "qwe : " << r.m_num << endl;
		return output;
	}

	void Print() {
		cout << this->m_num << endl;
	}
};

#endif // !_OPERATOROVERLOAD_H_
