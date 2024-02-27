using namespace std;
#include<iostream>
#include"BinarySearchTree.h"

int main()
{
	BSTree<int> T;
	T.Insert(1);
	T.Insert(3);
	T.Insert(4); 
	T.Insert(2);
	T.Insert(9);
	T.Insert(100);
	T.InOrder();

	cout << T.Find(100) << endl;

	T.Erase(2);
	T.InOrder();

	T.Erase(100);
	T.InOrder();

	return 0;
}




