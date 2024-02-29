#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//class Solution {
//public:
//    string tree2str(TreeNode* root) {
//        if (root == nullptr)
//        {
//            return "";
//        }
//
//        string ret = to_string(root->val);
//
//        //1 ×óÓÒ¶¼Îª¿Õ, ÒªÊ¡ÂÔÀ¨ºÅ
//        //2 ÓÒÎª¿Õ, ÒªÊ¡ÂÔÀ¨ºÅ
//        if (root->left || root->right)
//        {
//            ret += '(';
//            ret += tree2str(root->left);
//            ret += ')';
//        }
//
//        if (root->right)
//        {
//            ret += '(';
//            ret += tree2str(root->right);
//            ret += ')';
//        }
//
//        return ret;
//    }
//};

//int main()
//{
//	int ar[] = { 1,2,3,4,0,5,6,7,8,9 };
//	int n = sizeof(ar) / sizeof(int);
//	vector<int> v(ar, ar + n);
//	vector<int>::iterator it = v.begin();
//	while (it != v.end())
//	{
//		if (*it != 0)
//
//			cout << *it;
//		else
//			it = v.erase(it);
//		it++;
//	}
//	return 0;
//}


///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     TreeNode *left;
// *     TreeNode *right;
// *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// * };
// */
//class Solution {
//public:
//    bool isInTree(TreeNode* root, TreeNode* x)
//    {
//        if (root == nullptr)
//        {
//            return false;
//        }
//        return root == x
//            || isInTree(root->left, x)
//            || isInTree(root->right, x);
//    }
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
//    {
//        if (root == NULL)
//        {
//            return NULL;
//        }
//        if (root == p || root == q)
//        {
//            return root;
//        }
//
//        bool pInLeft, pInRight, qInLeft, qInRight;
//        pInLeft = isInTree(root->left, p);
//        pInRight = !pInLeft;
//        qInLeft = isInTree(root->left, q);
//        qInRight = !qInLeft;
//
//        if ((pInLeft && qInRight) || (pInRight && qInLeft))
//        {
//            return root;
//        }
//        else if (pInLeft && qInLeft)
//        {
//            return lowestCommonAncestor(root->left, p, q);
//        }
//        else
//        {
//            return lowestCommonAncestor(root->right, p, q);
//        }
//
//        return NULL;
//    }
//};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool getPath(TreeNode* root, TreeNode* x, stack<TreeNode*>& path)
    {
        if (root == nullptr)
        {
            return false;
        }
        path.push(root);

        if (root == x)
        {
            return true;
        }
        if (getPath(root->left, x, path))
        {
            return true;
        }
        if (getPath(root->right, x, path))
        {
            return true;
        }
        path.pop();
        return false;

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath, qPath;
        getPath(root, p, pPath);
        getPath(root, q, qPath);

        while (pPath.size() != qPath.size())
        {
            if (pPath.size() > qPath.size())
            {
                pPath.pop();
            }
            else
            {
                qPath.pop();
            }
        }

        while (qPath.top() != pPath.top())
        {
            qPath.pop();
            pPath.pop();
        }

        return pPath.top();
    }
};


/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    void inOrderConvert(TreeNode* cur, TreeNode*& prev)
    {
        if (cur == nullptr)
        {
            return;
        }
        inOrderConvert(cur->left, prev);
        cur->left = prev;
        if (prev)
        {
            prev->right = cur;
        }
        prev = cur;
        inOrderConvert(cur->right, prev);

    }
    TreeNode* Convert(TreeNode* pRootOfTree) {
        TreeNode* prev = nullptr;
        inOrderConvert(pRootOfTree, prev);
        TreeNode* head = pRootOfTree;
        while (head && head->left)
        {
            head = head->left;
        }

        return head;

    }
};
