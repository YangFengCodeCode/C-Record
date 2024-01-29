using namespace std;
#include<iostream>
#include<stack>
#include<string>


//int main()
//{
//	stack<int> st1, st2;
//	/*st.emplace("first");
//	st.emplace("second");
//
//	while (!st.empty())
//	{
//		cout << st.top() << endl;
//		st.pop();
//	}*/
//
//
//	st1.push(1);
//	st1.push(2);
//	cout << st1.size() << endl;
//	
//	st2.push(10);
//	st2.push(20);
//	st2.push(30);
//	cout << st2.size() << endl;
//
//	st1.swap(st2);
//	cout << st1.size() << endl;
//	cout << st2.size() << endl;
//
//	return 0;
//}


//int main()
//{
//	stack<int> st;
//	st.push(1);
//	st.push(2);
//	st.push(3);
//
//	while (!st.empty())
//	{
//		cout << st.top() << endl;
//		st.pop();
//	}
//
//	return 0;
//}

class MinStack {
public:
    MinStack() {

    }
    void push(int val) {
        _st.push(val);
        if (_min.empty() || val <= _min.top())
        {
            _min.push(val);
        }
    }

    void pop() {
        if (_st.top() == _min.top())
        {
            _min.pop();
        }

        _st.pop();
    }

    int top() {
        return _st.top();

    }

    int getMin() {
        return _min.top();
    }

    stack<int> _st;
    stack<int> _min;
};