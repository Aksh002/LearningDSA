#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution
{
public:
    int upperBound(vector<int> &nums, int target)
    {
        // code here
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        while (l < r)
        {
            mid = (l + r) / 2;
            if (nums[mid] <= target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        if (l == nums.size() - 1 && target > nums[l])
        {
            return nums.size();
        }
        return l;
    }
};
