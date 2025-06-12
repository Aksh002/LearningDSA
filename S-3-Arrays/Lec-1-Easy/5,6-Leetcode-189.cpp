//                                                              Rotate Array
// Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
/*
Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]  
*/

#include <bits/stdc++.h>
using namespace std;
// Brute force method:-
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        
            vector <int> ls;
            for (int i=abs(static_cast<int>(nums.size()-k));i<nums.size();i++){
                ls.push_back(nums[i]);
            }
            for (int i=nums.size()-1;i>=k;i--){
                nums[i]=nums[i-k];
            }
            for (int i=0;i<ls.size();i++){
                nums[i]=ls[i];
            }
    }
};

//Optimal method:-
class Solution {
public:
void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int n=nums.size();
        reverse(nums.begin(),nums.begin()+(n-k));
        reverse(nums.begin()+(n-k),nums.end());
        reverse(nums.begin(),nums.end());
    }
    // Below one aint required actually
    // void rotate(vector<int>& nums, int k) {
    //     k=k%nums.size();
    //     int n=nums.size();
    //     rev(nums,0,n-k-1);
    //     rev(nums,n-k,n-1);
    //     rev(nums,0,n-1);
    // }
    // void rev(vector<int>&a,int i,int n){
    //     if (i>n){
    //         return;
    //     }
    //     int temp=a[i];
    //     a[i]=a[n];
    //     a[n]=temp;

    //     rev(a,i+1,n-1);
    // }
};

// https://leetcode.com/problems/rotate-array/solutions/6159341/cpp-rt-0msbeats-100-sco1-tcon-recursive-glqvr