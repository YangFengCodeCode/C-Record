#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<algorithm>

///*
//// Definition for a Node.
//class Node {
//public:
//    int val;
//    Node* next;
//    Node* random;
//
//    Node(int _val) {
//        val = _val;
//        next = NULL;
//        random = NULL;
//    }
//};
//*/
//
//class Solution {
//public:
//    Node* copyRandomList(Node* head) {
//        Node* copyhead = nullptr, * copytail = nullptr;
//        map<Node*, Node*> mapNode;
//        Node* cur = head;
//
//        while (cur)
//        {
//            if (copytail == nullptr)
//            {
//                copyhead = copytail = new Node(cur->val);
//            }
//            else
//            {
//                copytail->next = new Node(cur->val);
//                copytail = copytail->next;
//            }
//            //将原节点和拷贝节点 kv 存储在mapNode中
//            mapNode.insert(make_pair(cur, copytail));
//            cur = cur->next;
//        }
//
//        cur = head;
//        copytail = copyhead;
//
//        //处理ramdom
//        while (cur)
//        {
//            if (cur->random == nullptr)
//            {
//                copytail->random = nullptr;
//            }
//            else
//            {
//                copytail->random = mapNode[cur->random];
//            }
//            cur = cur->next;
//            copytail = copytail->next;
//        }
//
//        return copyhead;
//    }
//};


class Solution1 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> v;
        for (auto e : s1)
        {
            if (s2.count(e) == 1)
            {
                v.push_back(e);
            }
        }
        return v;
    }
};


class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());
        vector<int> v;
        auto it1 = s1.begin();
        auto it2 = s2.begin();

        while (it1 != s1.end() && it2 != s2.end())
        {
            if (*it1 < *it2)
            {
                it1++;
            }
            else if (*it1 > *it2)
            {
                it2++;
            }
            else
            {
                v.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return v;
    }
};


class Solution {
public:
    //仿函数
    struct kvCom
    {
        bool operator()(const pair<string, int>& v1, const pair<string, int>& v2)
        {
            return v1.second > v2.second;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mapWord;
        for (auto& e : words)
        {
            mapWord[e]++;
        }

        vector<pair<string, int>> v(mapWord.begin(), mapWord.end());
        //这里需要归并排序 快排是不稳定的
        stable_sort(v.begin(), v.end(), kvCom());
        auto it = v.begin();
        vector<string> v0;
        while (k--)
        {
            v0.push_back(it->first);
            it++;
        }
        return v0;

    }
};



class Solution {
public:
    struct kvCom
    {
        bool operator()(const pair<string, int>& v1, const pair<string, int>& v2)
        {
            return v1.second > v2.second || (v1.second == v2.second && v1.first < v2.first);
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mapWord;
        for (auto& e : words)
        {
            mapWord[e]++;
        }

        vector<pair<string, int>> v(mapWord.begin(), mapWord.end());
        sort(v.begin(), v.end(), kvCom());
        auto it = v.begin();
        vector<string> v0;
        while (k--)
        {
            v0.push_back(it->first);
            it++;
        }
        return v0;

    }
};