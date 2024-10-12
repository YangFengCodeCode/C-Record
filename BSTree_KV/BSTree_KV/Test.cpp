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



	string arr[] = { "ƻ��", "����", "ƻ��", "����", "ƻ��", "ƻ��", "����","ƻ��", "�㽶", "ƻ��", "����", "�㽶", "��ݮ" };
	BSTree<string, int> t;
	for (auto& e : arr)
	{
		auto ret = t.Find(e);
		if (ret == nullptr)
		{
			// ��һ�γ���
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