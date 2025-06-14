#include <bits/stdc++.h>
using namespace std;

//                                                                  Sort colors(Sort an array of 0's 1's and 2's)
/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        //  Brute force method

        // int zero=0;
        // int one=0;
        // int two=0;
        // for (int i=0;i<nums.size();i++){
        //     if (nums[i]==0){
        //         zero++;
        //     }
        //     else if (nums[i]==1){
        //         one++;
        //     }
        //     else if (nums[i]==2){
        //         two++;
        //     }
        // }

        // for (int i=0;i<nums.size();i++){
        //     if (zero>0){
        //         nums[i]=0;
        //         zero--;
        //     }
        //     else if (one>0){
        //         nums[i]=1;
        //         one--;
        //     }
        //     else if (two>0){
        //         nums[i]=2;
        //         two--;
        //     }
        // }

        // Optimal method 
        int low=0;
        int mid=0;
        int high=nums.size()-1;
        while (mid<=high){
            if (nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if (nums[mid]==1){
                mid++;
            }
            else if (nums[mid]==2){
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};