#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFloor(vector<int> &nums, int x)
    {
        // Your code here
        int l = 0;
        int r = nums.size() - 1;
        int mid;
        int ans = -1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (nums[mid] <= x)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
