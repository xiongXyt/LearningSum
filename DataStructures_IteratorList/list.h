#pragma once

#include<iostream>
#include<assert.h>
#include"reverse_iterator.h"

using namespace std;

namespace beatles {
	template<class T>
	struct ListNode {
		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _data;

		ListNode(const T& x = T()) {
			_prev = nullptr;
			_next = nullptr;
			_data = x;
		}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator {
		typedef ListNode<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
		Node* _node;

		__list_iterator(Node* x)
			: _node(x)
		{}

		Ref operator*() {
			return _node->_data;
		}

		Ptr operator->() {
			return &_node->_data;
		}

		self& operator++() {
			_node = _node->_next;
			return *this;
		}

		self operator++(int) {
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--() {
			_node = _node->_prev;
			return *this;
		}

		self operator--(int) {
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator==(const self& it) const {
			return _node = it._node;
		}

		bool operator!=(const self& it) const {
			return _node != it._node;
		}
	};

	template<class T>
	class list {
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		//把正向迭代器作为模板参数传给反向迭代器
		typedef reverse_iterator<const_iterator, const T&, const T*> const_reverse_iterator;
		typedef reverse_iterator<iterator, T&, T*> reverse_iterator;
		list() {
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
		}

		// 迭代器区间构造
		template<class InputIterator>
		list(InputIterator first, InputIterator last) {
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			while (first != last) {
				push_back(*first);
				first++;
			}
		}

		// 拷贝构造 - 现代写法
		// lt2(lt1)
		list(const list<T>& lt) {
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			list<T> tmp(lt.begin(), lt.end());
			swap(_head, tmp._head);
		}

		// 赋值重载
		// lt1 = lt3
		list<T>& operator=(list<T> lt) {
			swap(_head, lt._head);
			return *this;
		}

		~list() {
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear() {
			iterator it = begin();
			while (it != end()) {
				iterator del = it++;
				delete del._node;
				//delete (it++)._node;
			}
			//更改链接关系
			_head->_prev = _head;
			_head->_next = _head;
		}

		//拷贝构造 - 传统写法
		//lt2(lt1)
	   /*list(const list<T>& lt)
	   {
		   _head = new Node;
		   _head->_prev = _head;
		   _head->_next = _head;

		   for (auto e : lt)
		   {
			   push_back(e);
		   }
	   }*/

	   //赋值重载 - 传统写法
	   //lt1 = lt3
	  //list<T>& operator=(const list<T>& lt)
	  //{
	  //	if (this != &lt)
	  //	{
	  //		clear(); //lt1
	  //		for (auto e : lt)
	  //		{
	  //			push_back(e);
	  //		}
	  //	}
	  //	return *this;
	  //}

		iterator begin() {
			return iterator(_head->_next);
		}

		iterator end() {
			return iterator(_head);
		}

		const_iterator begin() const {
			return const_iterator(_head->_next);
		}

		const_iterator end() const {
			return const_iterator(_head);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}

		reverse_iterator rend() {
			return reverse_iterator(begin());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}


		iterator insert(iterator pos, const T& x) {
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return iterator(newnode);
		}

		void push_back(const T& x)
		{
			/*Node* newnode = new Node(x);
			Node* tail = _head->_prev;
			tail->_next = newnode;
			newnode->_prev = tail;
			newnode->_next = _head;
			_head->_prev = newnode;*/
			insert(end(), x);
		}

		void push_front(const T& x) {
			insert(begin(), x);
		}

		iterator erase(iterator pos) {
			assert(pos != end());
			Node* prev = pos._node->_prev;
			Node* next = pos._node->_next;
			delete pos._node;
			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}

		void pop_back() {
			erase(--end());
		}

		void pop_front() {
			erase(begin());
		}
	private:
		Node* _head;
	};

	void print_list(const list<int>& lt) {
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end()) {
			// *it /= 2; 不可写
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}

	// 测试迭代器
	void test_list1() {
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end()) {
			*it *= 2; //可写
			cout << *it << " ";
			++it;
		}
		cout << endl;

		//测试const迭代器
		print_list(lt);
	}

	struct Date {
		Date(int year = 0, int month = 0, int day = 0)
			: _year(year)
			, _month(month)
			, _day(day)
		{}

		int _year;
		int _month;
		int _day;
	};

	void test_list2() {
		list<Date> lt;
		lt.push_back(Date(2022, 3, 31));
		lt.push_back(Date(2022, 3, 31));
		lt.push_back(Date(2022, 3, 31));

		// 遍历链表，打印日期
		list<Date>::iterator it = lt.begin();
		while (it != lt.end()) {
			//cout << (*it)._year << "." << (*it)._month << "." << (*it)._day << endl;
			cout << it->_year << "." << it->_month << "." << it->_day << endl;
			it++;
		}
		cout << endl;
	}

	// 测试插入&删除
	void test_list3() {
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);
		lt.push_front(0);
		lt.push_front(-1);
		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.pop_front();
		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;
	}

	// 测试拷贝构造&赋值重载
	void test_list4() {
		list<int> lt1;
		lt1.push_back(1);
		lt1.push_back(2);
		lt1.push_back(3);
		lt1.push_back(4);

		/*lt1.clear();
		for (auto e : lt1)
		{
			cout << e << " ";
		}
		cout << endl;*/

		list<int> lt2(lt1);
		for (auto e : lt2) {
			cout << e << " ";
		}
		cout << endl;

		list<int> lt3;
		lt3.push_back(10);
		lt3.push_back(20);
		lt3.push_back(30);
		lt3.push_back(40);
		lt3.push_back(50);
		lt1 = lt3;
		for (auto e : lt1) {
			cout << e << " ";
		}
		cout << endl;
	}

	// 测试反向迭代器
	void test_list5() {
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::reverse_iterator rit = lt.rbegin();
		while (rit != lt.rend()) {
			cout << *rit << " ";
			rit++;
		}
		cout << endl;
	}
}
