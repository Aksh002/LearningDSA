#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int curr_sum = 0;
        int freq = 0;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            curr_sum += nums[i];
            if (mp.count(curr_sum - k))
            {
                freq += mp[curr_sum - k];
            }
            mp[curr_sum]++;
        }
        return freq;
    }
};