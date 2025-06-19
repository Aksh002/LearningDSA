#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int i, j, k = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int col0 = matrix[0][0];
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    if (j == 0)
                    {
                        col0 = 0;
                    }
                    else
                    {
                        matrix[0][j] = 0;
                    }
                }
            }
        }

        for (i = 1; i < m; i++)
        {
            for (j = 1; j < n; j++)
            {
                if (matrix[i][j] != 0)
                {
                    if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    {
                        matrix[i][j] = 0;
                    }
                }
            }
        }
        if (matrix[0][0] == 0)
        {
            for (j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }
        if (col0 == 0)
        {
            for (i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};