#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        return bin(nums, target, 0, nums.size() - 1);
    }
    int bin(vector<int> &nums, int target, int l, int r)
    {
        if (l > r)
        {
            return -1;
        }
        int mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            return bin(nums, target, mid + 1, r);
        }
        else
        {
            return bin(nums, target, l, mid - 1);
        }
    }
};