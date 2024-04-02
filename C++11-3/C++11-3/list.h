#pragma once
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

		ListNode(T&& x)
			:_next(nullptr)
			, _prev(nullptr)
			, _data(forward<T>(x))
		{}

		template<class ...Args>
		ListNode(Args&&... args)
			: _next(nullptr)
			, _prev(nullptr)
			, _data(forward<Args>(args)...)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef ListNode<T> Node;
		typedef __list_iterator<T, Ref, Ptr> self;
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

		self operator--(int)
		{
			self tmp(*this);

			_node = _node->_prev;

			return tmp;
		}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &_node->_data;
		}

		bool operator!=(const self& s)
		{
			return _node != s._node;
		}

		bool operator==(const self& s)
		{
			return _node == s._node;
		}
	};

	template<class T>
	class list
	{
		typedef ListNode<T> Node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		iterator begin()
		{
			return _head->_next;
		}

		iterator end()
		{
			return _head;
		}

		const_iterator begin() const
		{
			return _head->_next;
		}

		const_iterator end() const
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

		list(list<T>& lt)
		{
			empty_init();

			for (const auto& e : lt)
			{
				push_back(e);
			}
		}

		void swap(list<T>& tmp)
		{
			std::swap(_head, tmp._head);
		}

		list<T>& operator=(list<T> lt)
		{
			swap(lt);
			return *this;
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_back(T&& x)
		{
			insert(end(), forward<T>(x));
		}

		template<class ...Args>
		void emplace_back(Args&&... args)
		{
			emplace(end(), forward<Args>(args)...);
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

		iterator insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
			return newnode;
		}

		iterator insert(iterator pos, T&& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(forward<T>(x));

			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;

			return newnode;
		}

		template<class ...Args>
		iterator emplace(iterator pos, Args&&... args)
		{
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(forward<Args>(args)...);

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
}