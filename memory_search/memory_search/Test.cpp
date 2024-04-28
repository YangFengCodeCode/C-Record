using namespace std;
#include<iostream>
class Solution {
public:
    int dp[31];
    int fib(int n)
    {
        // ¶¯Ì¬¹æ»®
        dp[0] = 0; dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};



class Solution {
    int memo[31];
public:
    int fib(int n)
    {
        memset(memo, -1, sizeof(memo));
        return dfs(n);
    }

    int dfs(int n)
    {
        if (n == 0 || n == 1)
        {
            return n;
        }

        if (memo[n] != -1)
        {
            return memo[n];
        }

        memo[n] = dfs(n - 1) + dfs(n - 2);
        return memo[n];
    }
};

#include<vector>

class Solution {
    vector<vector<int>> memo;
public:
    int uniquePaths(int m, int n) {
        memo.resize(m + 1, vector<int>(n + 1));
        return dfs(m, n);
    }

    int dfs(int m, int n)
    {
        if (memo[m][n] != 0) return memo[m][n];
        if (m == 0 || n == 0) return 0;
        if (m == 1 && n == 1)
        {
            memo[m][n] = 1;
            return 1;
        }
        memo[m][n] = dfs(m - 1, n) + dfs(m, n - 1);
        return memo[m][n];
    }
};


class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == 1 && j == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};



class Solution {
    vector<int> memo;
public:
    int lengthOfLIS(vector<int>& nums) {
        memo.resize(nums.size());
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            ret = max(ret, dfs(i, nums));
        }
        return ret;
    }

    int dfs(int pos, vector<int>& nums)
    {
        if (memo[pos] != 0) return memo[pos];
        int ret = 1;
        for (int i = pos + 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[pos])
            {
                ret = max(ret, dfs(i, nums) + 1);
            }
        }
        memo[pos] = ret;
        return ret;
    }
};



class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ret = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] > nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }

            }
            ret = max(ret, dp[i]);
        }

        return ret;
    }
};



class Solution {
    vector<vector<int>> memo;
public:
    int getMoneyAmount(int n) {
        memo.resize(n + 1, vector<int>(n + 1));
        return dfs(1, n);
    }

    int dfs(int left, int right)
    {
        if (left >= right) return 0;
        if (memo[left][right] != 0) return memo[left][right];

        int ret = INT_MAX;
        for (int head = left; head <= right; head++)
        {
            int x = dfs(left, head - 1);
            int y = dfs(head + 1, right);
            ret = min(ret, max(x, y) + head);
        }
        memo[left][right] = ret;
        return ret;
    }
};




class Solution {
    vector<vector<int>> memo;
    int dx[4] = { 0, 0, -1, 1 };
    int dy[4] = { 1, -1, 0, 0 };
    int m, n;
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo.resize(m, vector<int>(n));
        int ret = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret = max(ret, dfs(i, j, matrix));
            }
        }

        return ret;
    }

    int dfs(int i, int j, vector<vector<int>>& matrix)
    {
        if (memo[i][j] != 0) return memo[i][j];
        int ret = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x >= 0 && x < m && y >= 0 && y < n && matrix[x][y] > matrix[i][j])
            {
                ret = max(ret, dfs(x, y, matrix) + 1);
            }
        }
        memo[i][j] = ret;
        return ret;
    }
};