#pragma once

namespace beatles
{
	// 可以是任意容器的反向迭代器
	// Iterator是哪个容器的迭代器，reverse_iterator<Iterator>就可以适配哪个容器的反向迭代器(复用)
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
