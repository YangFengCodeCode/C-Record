#pragma once
#include<assert.h>

namespace yf
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _data;

		ListNode(const T& x = T())
			:_next(nullptr)
			, _prev(nullptr)
			, _data(x)
		{}
	};

	template<class T>
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T> self;
		Node* _node;

		__list_iterator(Node* x)
			:_node(x)
		{}

		// ++it
		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		// it++
		self operator++(int)
		{
			//__list_iterator<T> tmp(*this);
			self tmp(*this);

			_node = _node->_next;

			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self operator--(int);

		T& operator*()
		{
			return _node->_data;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s);
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T> iterator;

		iterator begin()
		{
			//return iterator(_head->_next);
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		void empty_init()
		{
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				it = erase(it);
			}
		}

		~list()
		{
			clear();

			delete _head;
			_head = nullptr;
		}

		//list(const list<T>& lt)
		list(list<T>& lt)
		{
			empty_init();

			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		// lt1 = lt2;
		// list<T>& operator=(const list<T>& lt)
		/*list<T>& operator=(list<T>& lt)
		{
			if (this != &lt)
			{
				clear();
				for (const auto& e : lt)
				{
					push_back(e);
				}
			}
			return *this;
		}*/

		void swap(list<T>& tmp)
		{
			std::swap(_head, tmp._head);
		}

		//list& operator=(list lt)
		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
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

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		// vector insert会导致迭代器失效
		// list会不会？不会
		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			// prev newnode cur
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			//return iterator(newnode);
			return newnode;
		}

		iterator erase(iterator pos)
		{
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;

			delete cur;

			return next;
		}

	private:
		Node* _head;
	};

	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it += 10;

			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list2()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);


		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_back(5);
		lt.push_front(0);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.pop_front();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.clear();

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		lt.push_back(10);
		lt.push_back(20);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		for (auto e : lt)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> copy(lt);
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;

		list<int> lt1;
		lt1.push_back(10);
		lt1.push_back(20);
		lt1.push_back(30);
		lt1.push_back(40);

		lt = lt1;
		for (auto e : copy)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}