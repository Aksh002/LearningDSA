//                          Missing Number
/*

Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

*/

//https://leetcode.com/problems/missing-number/description/
#include <bits/stdc++.h>
using namespace std;

// My approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        nums.push_back(-1);
        for (int i=0;i<nums.size();i++){
            while(i!=nums[i] && nums[i]!=-1){
                swap(nums[i],nums[nums[i]]);
            }
        }
        for (int i=0;i<nums.size();i++){
            if (nums[i]==-1){
                return i;
            }
        }
        return -1;
    }
};// O(N) | O(1)


// Editorial appoach (XOR-Bit manupulation apprach):-
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;
        
        for(int num:nums){
            result ^= num;
            result ^= i;
            i++;
        }
        
        return result;
    }
};// O(N) | O(1)