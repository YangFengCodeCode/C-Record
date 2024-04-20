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


// ֻ���ڶ���
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
//	// ����˽�л�
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



//// ֻ����Stack
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
//	// ����һ����ר����operator new
//	void* operator new(size_t n) = delete;
//
//private:
//	// ����˽�л�
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


// ֻ���ڶ���
//class HeapOnly
//{
//public:
//	// ����˽�л�
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
//	// �����������
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
//	//HeapOnly ho1; -->������ ��Ϊ�����Ҫ�Զ�������������
//	HeapOnly* ptr = new HeapOnly; // -->����Ϳ���, ��Ϊ����Ҫ������������
//
//	//delete ptr; -->û������������
//	ptr->Destroy();
//
//	shared_ptr<HeapOnly> pptr(new HeapOnly, [](HeapOnly* ptr) {ptr->Destroy(); });
//
//	return 0;
//}



// C++98�й��캯��˽�л����������е���������Ĺ��캯�������޷��̳�
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
//	// ������һ��ʼ(main֮ǰ)�ʹ���������
//	// ���⣺
//	// 1����������������ݽ϶࣬�����ʼ���ɱ��ϸߣ���ô��Ӱ������������ٶȡ��ٳٽ�����main����
//	// 2������������г�ʼ������������ϵ�������޷����ơ����裺A��B��������������Ҫ��A�ȳ�ʼ����B�ٳ�ʼ���������޷���֤
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
//		// ����һЩ���ݣ���ǰ����ֻ��һ�ݣ��ǾͿ��԰���Щ���ݷŵ����������
//		// �ٰ��������Ƴɵ�����������ݾ�ֻ��һ����
//		int _x;
//		int _y;
//		vector<string> _vstr;
//
//		// ��̬��Ա���󣬲����ڶ����У����ھ�̬�����൱��ȫ�ֵģ����������У�����������
//		static Singleton _sint;
//	};
//
//	Singleton Singleton::_sint(1, 1, { "����","�Ĵ�" });
//}
//
//
//int main()
//{
//	hunger::Singleton::GetInstance()->Print();
//	hunger::Singleton::GetInstance()->Print();
//	hunger::Singleton::GetInstance()->Print();
//
//	hunger::Singleton::GetInstance()->AddStr("����");
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
			// ��һ�ε���ʱ��������������
			// �̰߳�ȫ���⣬��Ҫ����
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
			// ������д���ļ�
			cout << "~Singleton()" << endl;
		}

		int _x;
		int _y;
		vector<string> _vstr;

		// ��̬��Ա���󣬲����ڶ����У����ھ�̬�����൱��ȫ�ֵģ����������У�����������
		static Singleton* _psint;

		// �ڲ���
		class GC
		{
		public:
			~GC()
			{
				Singleton::DelInstance();
			}
		};
		static GC gc;
		//����һ����̬��Ա�������������ʱ��ϵͳ���Զ������������������Ӷ��ͷŵ�������
	};

	Singleton* Singleton::_psint = nullptr;
	Singleton::GC Singleton::gc;
}

int main()
{
	lazy::Singleton::GetInstance()->Print();
	lazy::Singleton::GetInstance()->Print();
	lazy::Singleton::GetInstance()->Print();

	lazy::Singleton::GetInstance()->AddStr("����");
	lazy::Singleton::GetInstance()->Print();

	//lazy::Singleton::DelInstance(); -->��gc  ���������ͷ�Ҳû�й�ϵ

	return 0;
}