#ifndef _MYLIST_H_
#define _MYLIST_H_
#include<iostream>
using namespace std;

namespace MyList {
	template<class T>
	struct ListNode {
		T data;
		ListNode<T>* ListNext;
		ListNode<T>* ListFront;

		ListNode(const T& x = T()) {

			ListNext = nullptr;
			ListNext = nullptr;
			data = x;
		}
	};

	template<class T>
	class ListIterator {
		typedef ListNode<T> Node;
		typedef ListIterator<T> Iterator;
	public:
		Node* m_Node;
		ListIterator(Node* x) {
			this->m_Node = x;
		}

		T& operator*() {
			return this->m_Node->data;
		}

		T* operator->() {
			return &this->m_Node->data;
		}

		Iterator& operator++() {
			this->m_Node = this->m_Node->ListNext;
			return *this;
		}

		bool operator==(const Iterator& other) const {
			return this->m_Node = other.m_Node;
		}

		bool operator!=(const Iterator& other) const {
			return this->m_Node != other.m_Node;
		}
	};

	template<class T>
	class MyList {
		typedef ListNode<T> Node;
	public:
		typedef ListIterator<T> iterator;
	private:
		Node* m_Head;
	public:

		MyList() {
			this->m_Head = new Node;
			this->m_Head->ListFront = this->m_Head;
			this->m_Head->ListNext = this->m_Head;
			this->m_Head->data = 0;  // 用来记录长度
		}

		// 迭代器区间构造
		template<class InputIterator>
		MyList(InputIterator first, InputIterator last) {
			this->m_Head = new Node;
			this->m_Head->ListFront = this->m_Head;
			this->m_Head->ListNext = this->m_Head;
			this->m_Head->data = 0;  // 用来记录长度

			while (first != last) {
				push_back(*first);
				++first;
				++this->m_Head->data;
			}
		}

		MyList(const MyList& other) {
			this->m_Head = new Node;
			this->m_Head->ListFront = this->m_Head;
			this->m_Head->ListNext = this->m_Head;
			this->m_Head->data = 0;  // 用来记录长度

			swap(this->m_Head, other.m_Head);
		}

		MyList<T>& operator=(const MyList<T>& other) {
			this->m_Head = new Node;
			this->m_Head->ListFront = this->m_Head;
			this->m_Head->ListNext = this->m_Head;
			this->m_Head->data = 0;  // 用来记录长度

			swap(this->m_Head, other.m_Head);
			return *this;
		}

		~MyList() {
			this->clear();
			delete this->m_Head;
			this->m_Head = nullptr;
		}

		void clear() {
			Node* pTemp = this->m_Head->ListNext;
			while (pTemp != this->m_Head) {
				Node* pNum = pTemp;
				pTemp = pTemp->ListNext;

				delete pNum;
				pNum = nullptr;
			}
		}

		void push_back(const T& num) {
			Node* newnode = new Node(num);
			Node* pTemp = this->m_Head;

			pTemp->ListFront->ListNext = newnode;
			pTemp->ListFront = newnode;

			newnode->ListFront = pTemp->ListFront;
			pTemp->ListFront = newnode;
			newnode->ListNext = pTemp;

			++this->m_Head->data;
		}

		iterator begin() {
			return iterator(this->m_Head->ListNext);
		}

		iterator end() {
			//Node* pTemp = this->m_Head;
			//while (pTemp->ListNext!=nullptr) {
			//	pTemp = pTemp->ListNext;
			//}
			return iterator(this->m_Head);
		}

		void PrintList() {
			Node* pTemp = this->m_Head->ListNext;
			while (pTemp != this->m_Head) {
				cout << pTemp->data << endl;
				pTemp = pTemp->ListNext;
			}
		}
	};
}

#endif // !_MYLIST_H_
