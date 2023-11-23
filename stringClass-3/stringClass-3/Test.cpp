#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
#include<string>

//int main()
//{
//	string s1("Limitless"), s2("00");
//	s1.insert(2, "123");
//	cout << s1 << endl;
//
//	s1.insert(3, s2);
//	cout << s1 << endl;
//
//	s1.insert(3, 5, 'X');
//	cout << s1 << endl;
//	return 0;
//}

//int main()
//{
//	string s1("hello world\n");
//	s1.erase(9, 1);
//	cout << s1 << endl;
//
//	s1.erase(5);
//	cout << s1 << endl;
//
//	s1.erase(s1.begin());
//	cout << s1 << endl;
//
//
//	s1.erase(s1.begin(), s1.end() - 1);
//	cout << s1 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;
//
//	size_t pos1 = s1.find(' ', 0);
//	cout << pos1 << endl;
//
//	size_t pos2 = s1.find("world", 0);
//	cout << pos2 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello  world hello yf");
//	cout << s1 << endl;
//
//	// 所有的空格替换为20%
//	size_t pos = s1.find(' ', 0);
//	while (pos != string::npos)
//	{
//		s1.replace(pos, 1, "20%");
//		// 效率很低，能不用就不要用了
//		pos = s1.find(' ', pos + 3);
//	}
//	cout << s1 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello world hello yf");
//	cout << s1 << endl;
//	size_t pos = s1.find(' ', 0);
//	s1.replace(pos, 4, "%20");
//	cout << s1 << endl;
//	return 0;
//}


//int main()
//{
//	string s2("hello  world hello yf");
//	cout << s2 << endl;
//	string s3;
//	for (auto ch : s2)
//	{
//		if (ch == ' ')
//		{
//			s3 += "20%";
//		}
//		else
//		{
//			s3 += ch;
//		}
//	}
//	cout << s3 << endl;
//
//	s2.swap(s3);
//	cout << s2 << endl;
//	cout << s3 << endl;
//	
//	return 0;
//}


//int main()
//{
//	string s2("hello  world hello yf");
//	s2.pop_back();
//	cout << s2 << endl;
//	return 0;
//}

//int main()
//{
//	char* c;
//	string s = "1234";
//	c = s.c_str();// --> error
//	//c最后指向的内容是垃圾，因为s对象被析构，其内容被处理，同时编译器将会报错
//	return 0;
//}

//int main()
//{
//	char* cstr;
//	string str("Please split this phrase into tokens");
//	cstr = new char[str.size() + 1];
//	strcpy(cstr, str.c_str());
//	cout << cstr << endl;
//}


//int main()
//{
//	string s("hello world hello yf");
//	size_t pos = s.rfind(' ');
//	s[pos] = 'y';
//	cout << s << endl;
//	return 0;
//}


//int main()
//{
//	string s("hello world hello yf");
//	cout << "lenth == " << s.size() << endl;
//	size_t pos1 = s.find_first_of("ll");
//	cout << pos1 << endl;
//
//	size_t pos2 = s.find_first_of("lo", 5);
//	cout << pos2 << endl;
//
//	size_t pos3 = s.find_last_of("yfff");
//	cout << pos3 << endl;
//
//	size_t pos4 = s.find_last_of("lo", 5);
//	cout << pos4 << endl;
//
//	size_t pos5 = s.find_first_not_of("ll");
//	cout << pos5 << endl;
//
//	size_t pos6 = s.find_last_not_of("ll");
//	cout << pos6 << endl;
//	return 0;
//}


//int main()
//{
//	string s("hello world");
//	size_t pos = s.find("world");
//	cout << pos << endl;
//
//	string sub = s.substr(pos);
//	cout << sub << endl;
//
//	return 0;
//}


//void SplitFilename(const string& str)
//{
//	cout << "Splitting: " << str << '\n';
//	size_t found = str.find_last_of("/\\");
//	cout << found << '\n';
//    cout << " path: " << str.substr(0, found) << '\n';
//	cout << " file: " << str.substr(found + 1) << '\n';
//}
//
//int main()
//{
//	string str1("/usr/bin/man");
//	string str2("c:\\windows\\winhelp.exe");
//
//	SplitFilename(str1);
//	SplitFilename(str2);
//
//	return 0;
//}


//int main()
//{
//	string s1("hello");
//	string s2("world");
//
//	string ret1 = s1 + s2;
//	cout << ret1 << endl;
//
//	string ret2 = s1 + "xx";
//	cout << ret2 << endl;
//
//	string ret3 = "xx" + s1;
//	cout << ret3 << endl;
//
//	return 0;
//}


int main() 
{
	string s;
	getline(cin, s);
	cout << s << endl;
	size_t pos = s.rfind(' ');
	if (pos != string::npos)
	{
		cout << s.size() - pos - 1 << endl;
	}
	else
	{
		cout << s.size() << endl;
	}

	return 0;
}
