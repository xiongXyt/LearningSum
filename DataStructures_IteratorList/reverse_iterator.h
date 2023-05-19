#pragma once

namespace beatles
{
	// ���������������ķ��������
	// Iterator���ĸ������ĵ�������reverse_iterator<Iterator>�Ϳ��������ĸ������ķ��������(����)
	template<class Iterator, class Ref, class Ptr>
	class reverse_iterator {
		typedef reverse_iterator<Iterator, Ref, Ptr> self;
	public:
		reverse_iterator(Iterator it)
			:_it(it)
		{}

		Ref operator*() {
			Iterator prev = _it;
			return *--prev;
		}

		Ptr operator->() {
			return &operator*();
		}

		self& operator++() {
			--_it;
			return *this;
		}

		self operator++(int) {
			self tmp(*this);
			--_it;
			return tmp;
		}

		self& operator--() {
			self tmp(*this);
			++_it;
			return tmp;
		}

		self operator--(int) {
			return ++_it;
		}

		bool operator==(const self& rit) const {
			return _it == rit._it;
		}

		bool operator!=(const self& rit) const {
			return _it != rit._it;
		}
	private:
		Iterator _it;
	};
}
