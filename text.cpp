#include <bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> &nums, int n, int k)
{
    int l = 0;
    int h = n - 1;
    int mid;
    while (l < h)
    {
        mid = l + (h - l) / 2;
        if (nums[mid] < k)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return l;
}
int upperbound(vector<int> &nums, int n, int k)
{
    int l = 0;
    int h = n;
    int mid;
    while (l < h)
    {
        mid = l + (h - l) / 2;
        if (nums[mid] <= k)
        {
            l = mid + 1;
        }
        else
        {
            h = mid;
        }
    }
    return l;
};

int countFreq(vector<int> &nums, int target)
{
    // code here
    int lb = lowerbound(nums, nums.size(), target);
    printf("lb :- %d", lb);
    int ub = upperbound(nums, nums.size(), target);
    printf("ub :- %d", ub);
    if (lb == nums.size() || nums[lb] != target)
        return 0; // not found

    return ub - lb;
}

int main(void)
{
    vector<int> nums = {1};
    int freq = countFreq(nums, 1);
    printf("FREQ:- %d", freq);
    return 0;
}