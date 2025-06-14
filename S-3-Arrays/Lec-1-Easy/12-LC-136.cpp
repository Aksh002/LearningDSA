//                                                   Single Number
/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
// https://leetcode.com/problems/single-number/description/

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
        // Fist way:-
        // int i=0;
        // int j=nums.size()-1;
        // while (i<nums.size()){
        //     if (nums[i]==nums[j] && i!=j){
        //         i++;
        //         j=nums.size()-1;
        //     }
        //     else{
        //         if (j==0){
        //             return nums[i];
        //         }
        //         j--;
        //     }
        // }
        // return -1;
        /* 
        A^A=0
        A^B^A=B
        (A^A^B) = (B^A^A) = (A^B^A) = B This shows that position doesn't matter.
        Similarly , if we see , a^a^a......... (even times)=0 and a^a^a........(odd times)=a
        */
        int ans=0;
        for (auto it:nums){
            ans^=it;
        }
        return ans;
        return -1;
    }