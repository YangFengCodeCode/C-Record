using namespace std;
#include<iostream>

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

	//typedef __list_const_iterator<T> const_iterator;


	iterator begin()
	{
		//return iterator(_head->_next);
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


struct AA
{
	int _a1;
	int _a2;

	AA(int a1 = 1, int a2 = 1)
		:_a1(a1)
		,_a2(a2)
	{}
};

int main()
{
	list<AA> lt;
	AA aa1;
	lt.push_back(aa1);

	lt.push_back(AA());

	AA aa2(2,2);
	lt.push_back(aa2);

	lt.push_back(AA(2, 2));

	list<AA>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << (*it)._a1 << ":" << (*it)._a2 << endl;
		cout << it->_a1 << ":" << it->_a2 << endl;

		++it;
	}
	cout << endl;
}
