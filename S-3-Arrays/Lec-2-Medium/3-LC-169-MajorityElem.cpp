#include <bits/stdc++.h>
using namespace std;
//                                                          MAJORITY ELEEMNT
/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

// https://leetcode.com/problems/majority-element/description/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Better method-
        // int count=1;
        // int n=nums.size();
        // if (n==1){
        //     return nums[0];
        // }
        // sort(nums.begin(),nums.end());
        // for (int i=1;i<nums.size();i++){
        //     if (nums[i]==nums[i-1]){
        //         count++;
        //         if (count>=(n+1)/2){
        //             return nums[i];
        //         }
        //     }
        //     else{
        //         count =1;
        //     }
        // }
        // return -1;

        // Optimal Method
        int ele=nums[0];
        int deficiate=0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]==ele){
                deficiate++;
            }
            else{
                deficiate--;
                if (deficiate==0){
                    ele=nums[i+1];
                }
            }
        }
        int count=0;
        for(int i=0;i<nums.size();i++){
            if (nums[i]==ele){
                count++;
            }
        }
        if (count>=nums.size()/2){
            return ele;
        }
        else {
            return -1;
        }
    }
};