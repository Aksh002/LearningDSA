#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int m = matrix.size();
        int n = matrix[0].size();
        int t = 0, b = m - 1, l = 0, r = n - 1;
        while (l <= r && t <= b)
        {
            for (int j = l; j <= r; j++)
            {
                ans.push_back(matrix[t][j]);
            }
            ++t;
            for (int i = t; i <= b; i++)
            {
                ans.push_back(matrix[i][r]);
            }
            --r;
            if (t <= b)
            {
                for (int j = r; j >= l; --j)
                {
                    ans.push_back(matrix[b][j]);
                }
                --b;
            }

            if (l <= r)
            {
                for (int i = b; i >= t; --i)
                {
                    ans.push_back(matrix[i][l]);
                }
                ++l;
            }
        }
        return ans;
    }
};