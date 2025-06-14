#include <bits/stdc++.h>
using namespace std;
//                                                          Maximum Subarray
/*
Given an integer array nums, find the 
subarray
 with the largest sum, and return its sum.

*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        

        //                              Kadane's Algorithm
        long maxi=LONG_MIN;
        long long sum=0;

        for (int i=0;i<nums.size();i++){
            sum+=nums[i];
            if (sum>maxi){
                maxi=sum;
            }
            if (sum<0){
                sum=0;
            }
        }
        
        return maxi; 

        //                              Kadane's Algorithm
        // int maxSoFar=nums[0];
        // int maxEndingHere=nums[0];

        // for (int i=1;i<nums.size();i++){
        //     maxEndingHere=max(nums[i],maxEndingHere+nums[i]);
        //     maxSoFar=max(maxEndingHere,maxSoFar);
        // }

        // return maxSoFar;
        // return maxSubArrayUtil(nums,0,nums.size()-1);       
    }

    // Unoptimal method
    // int maxCrossingSum(vector<int>& nums, int low, int mid, int high) {
    //     // Find maximum sum on the left of mid
    //     int leftSum = INT_MIN, sum = 0;
    //     for (int i = mid; i >= low; i--) {
    //         sum += nums[i];
    //         leftSum = max(leftSum, sum);
    //     }

    //     // Find maximum sum on the right of mid
    //     int rightSum = INT_MIN;
    //     sum = 0;
    //     for (int i = mid + 1; i <= high; i++) {
    //         sum += nums[i];
    //         rightSum = max(rightSum, sum);
    //     }

    //     // Return the sum of the maximum left and right subarrays
    //     return leftSum + rightSum;
    // }

    // int maxSubArrayUtil(vector<int>& nums, int low, int high) {
    //     // Base case: only one element
    //     if (low == high) {
    //         return nums[low];
    //     }

    //     // Find the middle point
    //     int mid = low + (high - low) / 2;

    //     // Recursively find the maximum subarray sum in left, right, and
    //     // crossing parts
    //     int leftSum = maxSubArrayUtil(nums, low, mid);
    //     int rightSum = maxSubArrayUtil(nums, mid + 1, high);
    //     int crossSum = maxCrossingSum(nums, low, mid, high);

    //     // Return the maximum of the three
    //     return max({leftSum, rightSum, crossSum});
    // } 
};