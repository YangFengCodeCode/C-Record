using namespace std;
#include<iostream>
#include<vector>
#include<string>

//class CopyBan
//{
//    // ...
//
//private:
//    CopyBan(const CopyBan&);
//    CopyBan& operator=(const CopyBan&);
//    //...
//};
//
//
//class CopyBan
//{
//    // ...
//    CopyBan(const CopyBan&) = delete;
//    CopyBan& operator=(const CopyBan&) = delete;
//    //...
//};


// 只能在堆上
//class HeapOnly
//{
//public:
//	template<class... Args>
//	static HeapOnly* CreateObj(Args&&... args)
//	{
//		return new HeapOnly(args...);
//	}
//
//	HeapOnly(const HeapOnly&) = delete;
//	HeapOnly& operator=(const HeapOnly&) = delete;
//private:
//	// 构造私有化
//	HeapOnly()
//	{}
//
//	HeapOnly(int x, int y)
//		:_x(x)
//		,_y(y)
//	{}
//
//	int _x;
//	int _y;
//	vector<int> _a;
//};
//
//int main()
//{
//	//HeapOnly ho1;
//	//HeapOnly* ho2 = new HeapOnly;
//
//	HeapOnly* ho3 = HeapOnly::CreateObj();
//	HeapOnly* ho4 = HeapOnly::CreateObj(1,1);
//
//
//	return 0;
//}



//// 只能在Stack
//class StackOnly
//{
//public:
//	template<class... Args>
//	static StackOnly CreateObj(Args&&... args)
//	{
//		return StackOnly(args...);
//	}
//
//	StackOnly(const StackOnly&) = delete;
//	StackOnly& operator=(const StackOnly&) = delete;
//
//	// 重载一个类专属的operator new
//	void* operator new(size_t n) = delete;
//
//private:
//	// 构造私有化
//	StackOnly()
//	{}
//
//	StackOnly(int x, int y)
//		:_x(x)
//		,_y(y)
//	{}
//
//	int _x;
//	int _y;
//	vector<int> _a;
//};
//
//int main()
//{
//	StackOnly so1 = StackOnly::CreateObj();
//	StackOnly so2 = StackOnly::CreateObj(1,1);
//	//StackOnly* so3 = new StackOnly(so1);
//
//	return 0;
//}


// 只能在堆上
//class HeapOnly
//{
//public:
//	// 构造私有化
//	HeapOnly()
//	{}
//
//	HeapOnly(int x, int y)
//		:_x(x)
//		,_y(y)
//	{}
//
//	void Destroy()
//	{
//		delete this;
//	}
//
//private:
//	// 封掉析构函数
//	~HeapOnly()
//	{
//		cout << "~HeapOnly()" << endl;
//	}
//
//	int _x;
//	int _y;
//	vector<int> _a;
//};
//
//int main()
//{
//	//HeapOnly ho1; -->调不动 因为这个需要自动调用析构函数
//	HeapOnly* ptr = new HeapOnly; // -->这个就可以, 因为不需要调用析构函数
//
//	//delete ptr; -->没有析构调不了
//	ptr->Destroy();
//
//	shared_ptr<HeapOnly> pptr(new HeapOnly, [](HeapOnly* ptr) {ptr->Destroy(); });
//
//	return 0;
//}



// C++98中构造函数私有化，派生类中调不到基类的构造函数。则无法继承
//class NonInherit
//{
//public:
//	static NonInherit GetInstance()
//	{
//		return NonInherit();
//	}
//private:
//	NonInherit()
//	{}
//};
//
//class A  final
//{
//	// ....
//};




//namespace hunger
//{
//	// 饿汉：一开始(main之前)就创建出对象
//	// 问题：
//	// 1、如果单例对象数据较多，构造初始化成本较高，那么会影响程序启动的速度。迟迟进不了main函数
//	// 2、多个单例类有初始化启动依赖关系，饿汉无法控制。假设：A和B两个单例，假设要求A先初始化，B再初始化，饿汉无法保证
//	class Singleton
//	{
//	public:
//		static Singleton* GetInstance()
//		{
//			return &_sint;
//		}
//
//		void Print()
//		{
//			cout << _x << endl;
//			cout << _y << endl;
//
//			for (auto& e : _vstr)
//			{
//				cout << e << " ";
//			}
//			cout << endl;
//		}
//
//		void AddStr(const string& s)
//		{
//			_vstr.push_back(s);
//		}
//
//		Singleton(Singleton const&) = delete;
//		Singleton& operator=(Singleton const&) = delete;
//
//	private:
//		Singleton(int x = 0, int y = 0, const vector<string>& vstr = { "yyyyy","xxxx" })
//			:_x(x)
//			, _y(y)
//			, _vstr(vstr)
//		{}
//
//		// 想让一些数据，当前程序只有一份，那就可以把这些数据放到这个类里面
//		// 再把这个类设计成单例，这个数据就只有一份了
//		int _x;
//		int _y;
//		vector<string> _vstr;
//
//		// 静态成员对象，不存在对象中，存在静态区，相当于全局的，定义在类中，受类域限制
//		static Singleton _sint;
//	};
//
//	Singleton Singleton::_sint(1, 1, { "陕西","四川" });
//}
//
//
//int main()
//{
//	hunger::Singleton::GetInstance()->Print();
//	hunger::Singleton::GetInstance()->Print();
//	hunger::Singleton::GetInstance()->Print();
//
//	hunger::Singleton::GetInstance()->AddStr("甘肃");
//	hunger::Singleton::GetInstance()->Print();
//
//
//	return 0;
//}


namespace lazy
{
	class Singleton
	{
	public:
		static Singleton* GetInstance()
		{
			// 第一次调用时，创建单例对象
			// 线程安全问题，需要加锁
			if (_psint == nullptr)
			{
				_psint = new Singleton;
			}

			return _psint;
		}

		static void DelInstance()
		{
			if (_psint)
			{
				delete _psint;
				_psint = nullptr;
			}
		}

		void Print()
		{
			cout << _x << endl;
			cout << _y << endl;

			for (auto& e : _vstr)
			{
				cout << e << " ";
			}
			cout << endl;
		}

		void AddStr(const string& s)
		{
			_vstr.push_back(s);
		}

		Singleton(Singleton const&) = delete;
		Singleton& operator=(Singleton const&) = delete;

	private:
		Singleton(int x = 0, int y = 0, const vector<string>& vstr = { "yyyyy","xxxx" })
			:_x(x)
			, _y(y)
			, _vstr(vstr)
		{}

		~Singleton()
		{
			// 把数据写到文件
			cout << "~Singleton()" << endl;
		}

		int _x;
		int _y;
		vector<string> _vstr;

		// 静态成员对象，不存在对象中，存在静态区，相当于全局的，定义在类中，受类域限制
		static Singleton* _psint;

		// 内部类
		class GC
		{
		public:
			~GC()
			{
				Singleton::DelInstance();
			}
		};
		static GC gc;
		//定义一个静态成员变量，程序结束时，系统会自动调用它的析构函数从而释放单例对象
	};

	Singleton* Singleton::_psint = nullptr;
	Singleton::GC Singleton::gc;
}

int main()
{
	lazy::Singleton::GetInstance()->Print();
	lazy::Singleton::GetInstance()->Print();
	lazy::Singleton::GetInstance()->Print();

	lazy::Singleton::GetInstance()->AddStr("甘肃");
	lazy::Singleton::GetInstance()->Print();

	//lazy::Singleton::DelInstance(); -->有gc  我们忘记释放也没有关系

	return 0;
}