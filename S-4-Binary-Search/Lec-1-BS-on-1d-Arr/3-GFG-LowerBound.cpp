#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution
{
public:
    int lowerBound(vector<int> &nums, int target)
    {
        // code here
        int found = 0;
        int l = 0;
        int r = nums.size();
        int num = 0;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
