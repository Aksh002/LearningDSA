//                                  Max Consecutive Ones
// Given a binary array nums, return the maximum number of consecutive 1's in the array.



//https://leetcode.com/problems/missing-number/description/

#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
        nums.push_back(0);
        for (int i=0;i<nums.size();i++){
            while(i!=nums[i]){
                swap(nums[i],nums[nums[i]]);
            }
        }
        for (int i=0;i<nums.size();i++){
            if (nums[i]!=i){
                return i;
            }
        }
        return -1;
    }