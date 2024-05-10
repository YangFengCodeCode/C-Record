#include<iostream>
using namespace std;


#include<windows.h>

//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//
//void Func()
//{
//	int len, time;
//	cout << "cin << len << time: ";
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//
//}
//
//void fxx()
//{
//	int i = 0;
//	cout << "cin >> i: ";
//	cin >> i;
//	if (i % 2 == 0)
//	{
//		throw 1;
//	}
//}
//
//int main()
//{
//	try 
//	{
//		fxx();
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << "捕获异常 division: " << errmsg << endl;
//	}
//	catch (int x)
//	{
//		cout << "捕获异常x:"<< x << endl;
//	}
//
//	return 0;
//}


//#include<windows.h>
//
//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//
//void fxx()
//{
//	int i = 0;
//	cout << "cin >> i: ";
//	cin >> i;
//	if (i % 2 == 0)
//	{
//		throw 1;
//	}
//}
//
//void Func()
//{
//	int len, time;
//	cout << "cin >> len >> time: ";
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//	try
//	{
//		fxx();
//	}
//	catch (int x)
//	{
//		cout <<__LINE__<<"捕获异常:" << x << endl;
//	}
//
//	cout << "=====================" << endl;
//
//}
//
//int main()
//{
//	try 
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (int x)
//	{
//		cout << __LINE__ <<"捕获异常:"<< x << endl;
//	}
//
//	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//
//	return 0;
//}


//double Division(int a, int b)
//{
//	if (b == 0)
//		throw "Division by zero condition!";
//	else
//		return ((double)a / (double)b);
//}
//
//
//void fxx()
//{
//	int i = 0;
//	cin >> i;
//	if (i % 2 == 0)
//	{
//		string s("出现偶数");
//		throw s;
//	}
//}
//
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//	fxx();
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const string& err)//这里不是s的别名 是s的拷贝对象
//	{
//		cout << err << endl;
//	}
//	catch (...) // 任意类型的异常
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}


// 服务器开发中通常使用的异常继承体系
class Exception
{
public:
	Exception(const string& errmsg, int id)
		:_errmsg(errmsg)
		, _id(id)
	{}

	virtual string what() const
	{
		return _errmsg;
	}

protected:
	string _errmsg;  // 错误描述
	int _id;         // 错误编号
};

// 继承和多态
class SqlException : public Exception
{
public:
	SqlException(const string& errmsg, int id, const string& sql)
		:Exception(errmsg, id)
		, _sql(sql)
	{}

	virtual string what() const
	{
		string str = "SqlException:";
		str += _errmsg;
		str += "->";
		str += _sql;
		return str;
	}
private:
	const string _sql;
};

class CacheException : public Exception
{
public:
	CacheException(const string& errmsg, int id)
		:Exception(errmsg, id)
	{}

	virtual string what() const
	{
		string str = "CacheException:";
		str += _errmsg;
		return str;
	}
};

class HttpServerException : public Exception
{
public:
	HttpServerException(const string& errmsg, int id, const string& type)
		:Exception(errmsg, id)
		, _type(type)
	{}

	virtual string what() const
	{
		string str = "HttpServerException:";
		str += _type;
		str += ":";
		str += _errmsg;
		return str;
	}
private:
	const string _type;
};


class A
{
public:
	A()
	{
		cout << "A()" << endl;
		_ptr1 = new int;
		_ptr2 = new int;
	}

	~A()
	{
		cout << "~A()" << endl;

		delete _ptr1;
		delete _ptr2;
	}

private:
	int* _ptr1;
	int* _ptr2;
};


void SQLMgr()
{
	srand(time(0));
	if (rand() % 7 == 0)
	{
		throw SqlException("权限不足", 100, "select * from name = '张三'");
	}

	cout << "!!!!!!!!!!!!!!!!!!!!!!!!运行成功" << endl;
}

void CacheMgr()
{
	srand(time(0));
	if (rand() % 5 == 0)
	{
		throw CacheException("权限不足", 100);
	}
	else if (rand() % 6 == 0)
	{
		throw CacheException("数据不存在", 101);
	}
	SQLMgr();
}

void HttpServer()
{
	A aa;
	srand(time(0));
	if (rand() % 3 == 0)
	{
		throw HttpServerException("请求资源不存在", 100, "get");
	}
	else if (rand() % 4 == 0)
	{
		throw HttpServerException("权限不足", 101, "post");
	}

	CacheMgr();
}

//int main()
//{
//	srand(time(0));
//
//	while (1)
//	{
//		Sleep(1000);
//
//		try {
//			HttpServer(); // io
//		}
//		catch (const Exception& e) // 这里捕获父类对象就可以
//		{
//			// 多态
//			cout << e.what() << endl;
//		}
//		catch (...)
//		{
//			cout << "Unkown Exception" << endl;
//		}
//	}
//
//	return 0;
//}
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
//void Func()
//{
//	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
//	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
//	// 重新抛出去。
//	int* array = new int[10];
//	try {
//		int len, time;
//		cout << "cin >> len >> time: ";
//		cin >> len >> time;
//		cout << Division(len, time) << endl;
//	}
//	catch (...)
//	{
//		cout << "delete []" << array << endl;
//		delete[] array;
//		throw;//捕获到什么就抛出什么
//	}
//	// ...
//	cout << "delete []" << array << endl;
//	delete[] array;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	return 0;
//}

#include<vector>

int main()
{
	try {
		vector<int> v(10, 5);
		// 这里如果系统内存不够也会抛异常
		v.reserve(1000000000);
		// 这里越界会抛异常
		v.at(10) = 100;
	}
	catch (std::exception & e) // 这里捕获父类对象就可以
	{
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unkown Exception" << endl;
	}
	return 0;
}


