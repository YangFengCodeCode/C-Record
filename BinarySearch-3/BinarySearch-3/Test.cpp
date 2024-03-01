#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<vector>
#include<map>
#include<set>


  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// 
//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int inbegin, int inend)
//    {
//        if (inbegin > inend)
//        {
//            return nullptr;
//        }
//        TreeNode* root = new TreeNode(preorder[previ++]);
//        int rooti = inbegin;
//        while (true)
//        {
//            if (root->val == inorder[rooti])
//            {
//                break;
//            }
//            else
//            {
//                rooti++;
//            }
//        }
//        root->left = _buildTree(preorder, inorder, previ, inbegin, rooti - 1);
//        root->right = _buildTree(preorder, inorder, previ, rooti + 1, inend);
//        return root;
//
//    }
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        int previ = 0;
//        int inbegin = 0, inend = preorder.size() - 1;
//        return _buildTree(preorder, inorder, previ, inbegin, inend);
//
//    }
//};


//
//TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int inbegin, int inend)
//{
//    if (inbegin > inend)
//    {
//        return nullptr;
//    }
//    TreeNode* root = new TreeNode(preorder[previ++]);
//    int rooti = inbegin;
//    while (true)
//    {
//        if (root->val == inorder[rooti])
//        {
//            break;
//        }
//        else
//        {
//            rooti++;
//        }
//    }
//    root->left = _buildTree(preorder, inorder, previ, inbegin, rooti - 1);
//    root->right = _buildTree(preorder, inorder, previ, rooti + 1, inend);
//    return root;
//
//}
//
//int main()
//{
//    vector<int> v1{ 3,9,20,15,7 };
//    vector<int> v2{ 9,3,15,20,7 };
//    int previ = 0;
//    TreeNode* n = _buildTree(v1, v2, previ, 0, 4);
//    return 0;
//}



//class Solution {
//public:
//    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& previ, int inbegin, int inend)
//    {
//        if (inbegin > inend)
//        {
//            return nullptr;
//        }
//        TreeNode* root = new TreeNode(preorder[previ++]);
//        int rooti = inbegin;
//        while (true)
//        {
//            if (root->val == inorder[rooti])
//            {
//                break;
//            }
//            else
//            {
//                rooti++;
//            }
//        }
//        root->left = _buildTree(preorder, inorder, previ, inbegin, rooti - 1);
//        root->right = _buildTree(preorder, inorder, previ, rooti + 1, inend);
//        return root;
//
//    }
//    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//        int previ = 0;
//        int inbegin = 0, inend = preorder.size() - 1;
//        return _buildTree(preorder, inorder, previ, inbegin, inend);
//
//    }
//};


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
class Solution {
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& posti, int inbegin, int inend)
    {
        if (inbegin > inend)
        {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[posti--]);
        int rooti = inbegin;
        while (true)
        {
            if (root->val == inorder[rooti])
            {
                break;
            }
            else
            {
                rooti++;
            }
        }
        root->right = _buildTree(inorder, postorder, posti, rooti + 1, inend);
        root->left = _buildTree(inorder, postorder, posti, inbegin, rooti - 1);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        int posti = postorder.size() - 1;
        int inbegin = 0, inend = postorder.size() - 1;
        return _buildTree(inorder, postorder, posti, inbegin, inend);

    }
};