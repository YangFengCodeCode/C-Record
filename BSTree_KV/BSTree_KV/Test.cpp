using namespace std;
#include<iostream>
#include"Tree.h"

int main()
{
	BSTree<int, string> BST;
	BST.Insert(1, "apple");
	BST.Insert(2, "banana");
	BST.Insert(4, "watermelon");
	BST.Insert(3, "orange");

	BST.Inorder();

	BST.Erase(3);
	BST.Inorder();



	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜","苹果", "香蕉", "苹果", "西瓜", "香蕉", "草莓" };
	BSTree<string, int> t;
	for (auto& e : arr)
	{
		auto ret = t.Find(e);
		if (ret == nullptr)
		{
			// 第一次出现
			t.Insert(e, 1);
		}
		else
		{
			ret->_value++;
		}
	}

	t.Inorder();


	return 0;
}