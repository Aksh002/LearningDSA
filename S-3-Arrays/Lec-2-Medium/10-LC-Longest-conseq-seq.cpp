#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0, freq = 0;
        if (nums.size() == 0)
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return 1;
        }
        for (int i = 0; i < nums.size() - 1; i++)
        {

            if (nums[i + 1] - nums[i] == 1)
            {
                count++;
            }
            else if (nums[i + 1] - nums[i] == 0)
            {
                continue;
            }
            else
            {
                if (count > freq)
                {
                    freq = count;
                }
                count = 0;
            }
        }
        if (count > freq)
        {
            freq = count;
        }
        return freq + 1;
    }
};