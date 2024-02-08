using namespace std;
#include<iostream>
#include<stack>
#include<queue>
#include"queue.h"
#include"stack.h"
#include"heap.h"


//int main()
//{
//	/*q.push(1);
//	q.push(2);
//	q.push(3);
//	q.push(4);*/
//
//	cout << q.back() << endl;
//	cout << q.size() << endl;
//
//	while (!q.empty())
//	{
//		cout << q.front() << ' ';
//		q.pop();
//	}
//
//	return 0;
//
//}


//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vv;
//        queue<TreeNode*> q;
//        int levelsize = 0;
//        if (root)
//        {
//            q.push(root);
//            levelsize += 1;
//        }
//
//        while (!q.empty())
//        {
//            vector<int> v;
//            while (levelsize--)
//            {
//                TreeNode* node = q.front();
//                q.pop();
//                v.push_back(node->val);
//                if (node->left)
//                {
//                    q.push(node->left);
//                }
//                if (node->right)
//                {
//                    q.push(node->right);
//                }
//            }
//            levelsize = q.size();
//            vv.push_back(v);
//        }
//
//        return vv;
//
//    }
//};

//#include <vector>
//#include <queue>
//#include <functional> // greater算法的头文件
//void TestPriorityQueue()
//{
//	// 默认情况下，创建的是大堆，其底层按照小于号比较
//	vector<int> v{ 3,2,7,6,0,4,1,9,8,5 };
//	priority_queue<int> q1;
//	for (auto& e : v)
//	{
//		q1.push(e);
//	}
//
//	while (!q1.empty())
//	{
//		cout << q1.top() << ' ';
//		q1.pop();
//	}
//	cout << endl;
//
//	// 如果要创建小堆，将第三个模板参数换成greater比较方式
//	priority_queue<int, vector<int>, greater<int>> q2(v.begin(), v.end());
//	while (!q2.empty())
//	{
//		cout << q2.top() << ' ';
//		q2.pop();
//	}
//}
//
//int main()
//{
//	TestPriorityQueue();
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	bool operator<(const Date& d)const
//	{
//		return (_year < d._year) ||
//			(_year == d._year && _month < d._month) ||
//			(_year == d._year && _month == d._month && _day < d._day);
//	}
//	bool operator>(const Date& d)const
//	{
//		return (_year > d._year) ||
//			(_year == d._year && _month > d._month) ||
//			(_year == d._year && _month == d._month && _day > d._day);
//	}
//	friend ostream& operator<<(ostream& _cout, const Date& d)
//	{
//		_cout << d._year << "-" << d._month << "-" << d._day;
//		return _cout;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//void TestPriorityQueue()
//{
//	// 大堆，需要用户在自定义类型中提供<的重载
//	priority_queue<Date> q1;
//	q1.push(Date(2018, 10, 29));
//	q1.push(Date(2018, 10, 28));
//	q1.push(Date(2018, 10, 30));
//	cout << q1.top() << endl;
//	// 如果要创建小堆，需要用户提供>的重载
//	priority_queue<Date, vector<Date>, greater<Date>> q2;
//	q2.push(Date(2018, 10, 29));
//	q2.push(Date(2018, 10, 28));
//	q2.push(Date(2018, 10, 30));
//	cout << q2.top() << endl;
//}


//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        sort(nums.begin(), nums.end(), greater<int>());
//        return nums[k - 1];
//    }
//};


//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        priority_queue<int> q(nums.begin(), nums.end());
//        while (--k)
//        {
//            q.pop();
//        }
//
//        return q.top();
//    }
//};


//class Solution {
//public:
//    int findKthLargest(vector<int>& nums, int k) {
//        priority_queue<int, vector<int>, greater<int>> q(nums.begin(), nums.begin() + k);
//        for (int i = k; i < nums.size(); i++)
//        {
//            if (nums[i] > q.top())
//            {
//                q.pop();
//                q.push(nums[i]);
//            }
//        }
//
//        return q.top();
//    }
//};


//仿函数/函数对象
namespace yf
{
	template<class T>
	class less
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	class greater
	{
	public:
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};
}

template<class Comapre>
class A
{
public:
	void func(int xx, int yy)
	{
		Comapre com;
		cout << "void func(int xx, int yy)" << com(xx, yy) << endl;;
	}
};

int main()
{
	A<yf::less<int>> aa1;
	aa1.func(1, 2);

	A<yf::greater<int>> aa2;
	aa2.func(1, 2);
}
