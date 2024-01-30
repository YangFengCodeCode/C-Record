using namespace std;
#include<vector>
#include<stack>
#include<iostream>
#include<string>

class Solution {
public:
    /**
     * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
     *
     *
     * @param pushV int����vector
     * @param popV int����vector
     * @return bool������
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        // write code here
        int pushi, popi = 0;
        stack<int> st;
        while (pushi < pushV.size())
        {
            st.push(pushV[pushi++]);
            while (!st.empty() && st.top() == popV[popi])
            {
                st.pop();
                popi++;
            }
        }

        return popi == popV.size();
    }
};


int main()
{
    vector<string> v;
    v.push_back("sa");
    v.push_back("12");
    v.push_back("56");
    v.push_back("89"); 
    v.push_back("vesrfes");
    for (auto e : v)
    {
        //cout << e << endl;
        cout << e[0] << endl;
    }

    
    return 0;

}


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto& e : tokens)
        {
            if (e == "+" || e == "-" || e == "/" || e == "*")
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();
                switch (e[0])
                {
                case '+':
                    st.push(left + right);
                    break;
                case '-':
                    st.push(left - right);
                    break;
                case '*':
                    st.push(left * right);
                    break;
                case '/':
                    st.push(left / right);
                    break;
                default:
                    break;
                }
            }

            else
            {
                st.push(stoi(e));
            }
        }

        return st.top();
    }
};