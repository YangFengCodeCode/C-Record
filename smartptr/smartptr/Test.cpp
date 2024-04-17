using namespace std;
#include<iostream>
#include<vector>

//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void fyy() noexcept
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//	// 重新抛出去。
//	int* array = new int[10];
//	try {
//		fyy();
//	}
//	catch (...)
//	{
//		// 捕获异常不是为了处理异常
//		// 是为了释放内存，然后异常在重新抛出
//		cout << "delete []" << array << endl;
//		delete[] array;
//
//		throw;  // 捕到什么抛什么
//	}
//
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//
//int main()
//{
//	Func();
//}



//// 下面程序及其难看
//// 智能指针解决
//void fxx()
//{
//	int* p1 = new int[10];
//	int* p2, *p3;
//	try
//	{
//		p2 = new int[20];
//		try {
//			p3 = new int[30];
//		}
//		catch (...)
//		{
//			delete[] p1;
//			delete[] p2;
//			throw;
//		}
//	}
//	catch (...)
//	{
//		delete[] p1;
//		throw;
//	}
//
//	//...
//
//	delete[] p1;
//	delete[] p2;
//	delete[] p3;
//}



//void MemoryLeaks()
//{
//	// 1.内存申请了忘记释放
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p2 = new int;
//
//	// 2.异常安全问题
//	int* p3 = new int[10];
//
//	Func(); // 这里Func函数抛异常导致 delete[] p3未执行，p3没被释放.
//
//	delete[] p3;
//}



//class SmartPtr
//{
//public:
//	SmartPtr(int* ptr)
//		:_ptr(ptr)
//	{}
//
//	~SmartPtr()
//	{
//		cout << "delete[] _ptr" << endl;
//
//		delete[] _ptr;
//	}
//
//	// operator*
//	// operator->
//	// operator[]
//
//private:
//	int* _ptr;
//};
//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Division by zero condition!";
//	}
//	return (double)a / (double)b;
//}
//
//void fxx()
//{
//	SmartPtr sp1(new int[10]);
//	SmartPtr sp2(new int[10]);
//	SmartPtr sp3(new int[10]);
//
//	int x, y;
//	cin >> x >> y;
//	Division(x, y);
//}
//
//int main()
//{
//	try
//	{
//		fxx();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//
//	return 0;
//}


///////////////////////////////////////////////////////////////////////////////////////


#include"SmartPtr.h"

//int div()
//{
//	int a, b;
//	cin >> a >> b;
//	if (b == 0)
//		throw invalid_argument("除0错误");
//
//	return a / b;
//}
//
//void Func()
//{
//	SmartPtr<int> sp1(new int(1));
//	SmartPtr<int> sp2(new int(0));
//
//	*sp1 += 10;
//
//	SmartPtr<pair<string, int>> sp3(new pair<string, int>);
//	sp3->first = "apple";
//	sp3->second = 1;
//	//sp3.operator->()->second = 1;
//
//	cout << div() << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}


//int main()
//{
//	yf::auto_ptr<int> sp1(new int(1));
//	yf::auto_ptr<int> sp2(sp1);
//
//	*sp2 += 10;
//
//	// sp1已经悬空 不能被访问 
//	//*sp1 += 10;
//	cout << "Test" << endl;
//	return 0;
//}



// shared_ptr的缺陷
struct ListNode
{
	int _val;
	//struct ListNode* _next;
	//struct ListNode* _prev;

	//yf::shared_ptr<ListNode> _next;
	//yf::shared_ptr<ListNode> _prev;

	yf::weak_ptr<ListNode> _prev;
	yf::weak_ptr<ListNode> _next;

	ListNode(int val = 0)
		:_val(val)
	{}

	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
};

//int main()
//{
//	yf::shared_ptr<ListNode> n1(new ListNode(10));
//	yf::shared_ptr<ListNode> n2(new ListNode(20));
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	n1->_next = n2;
//	n2->_prev = n1;
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	//delete n1;
//	//delete n2;
//
//	return 0;
//}
//
//
//



// 仿函数的删除器
template<class T>
struct FreeFunc {
	void operator()(T* ptr)
	{
		cout << "free:" << ptr << endl;
		free(ptr);
	}
};

template<class T>
struct DeleteArrayFunc {
	void operator()(T* ptr)
	{
		cout << "delete[]" << ptr << endl;
		delete[] ptr;
	}
};
int main()
{
	FreeFunc<int> freeFunc;
	std::shared_ptr<int> sp1((int*)malloc(4), freeFunc);
	DeleteArrayFunc<int> deleteArrayFunc;
	std::shared_ptr<int> sp2((int*)malloc(4), deleteArrayFunc);

	//lambada表达式
	std::shared_ptr<A> sp4(new A[10], [](A* p) {delete[] p; });
	std::shared_ptr<FILE> sp5(fopen("test.txt", "w"), [](FILE* p){fclose(p); });

	return 0;
}


