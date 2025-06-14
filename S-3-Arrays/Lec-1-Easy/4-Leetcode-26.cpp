#include <bits/stdc++.h>
using namespace std;
//                                                  Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        for (int j=1;j<n;j++){
            if (nums[j]!=nums[i]){
                nums[++i]=nums[j];
                //i++;
            }
        }
        return (i+1);
    }