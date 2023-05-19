#ifndef _SINGLETON_H_
#define _SINGLETON_H_
#include<iostream>
using namespace std;

class Singleton {
private:
	static Singleton* m_SL;
private:
	Singleton() {
		cout << "123" << endl;
	}

	~Singleton() {
		delete m_SL;
		m_SL = nullptr;
	}

public:
	static Singleton* SL() {
		if (m_SL==nullptr) {
			m_SL = new Singleton();
		}
		return m_SL;
	}
	void Print() {
		cout << "qwe" << endl;
	}
};

#endif // !_SINGLETON_H_
