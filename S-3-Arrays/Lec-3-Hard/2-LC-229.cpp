#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int num1 = INT_MIN;
        int num2 = INT_MIN;
        int deficiete1 = 0;
        int deficiete2 = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (deficiete1 == 0 && nums[i] != num2)
            {
                num1 = nums[i];
                deficiete1 = 1;
            }
            else if (deficiete2 == 0 && nums[i] != num1)
            {
                num2 = nums[i];
                deficiete2 = 1;
            }
            else if (nums[i] == num1)
            {
                deficiete1++;
            }
            else if (nums[i] == num2)
            {
                deficiete2++;
            }
            else
            {
                deficiete1--;
                deficiete2--;
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num1)
            {
                count++;
            }
        }
        if (count > n / 3)
        {
            ans.push_back(num1);
        }
        count = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == num2)
            {
                count++;
            }
        }
        if (count > n / 3)
        {
            ans.push_back(num2);
        }
        return ans;
    }
};