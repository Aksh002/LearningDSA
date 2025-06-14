// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

#include <bits/stdc++.h>
using namespace std;


/*
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int j=0;
        int k=1;
        vector<int> ans=nums;
        for (int i=0;i<nums.size();i++){
            if (nums[i]<0){
                ans[k]=nums[i];
                k=k+2;
            }
            else{
                ans[j]=nums[i];
                j=j+2;
            }
        }
        return ans;
    }
};